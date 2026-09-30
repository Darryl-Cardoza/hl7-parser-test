package org.rite.hl7

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.launch
import org.rite.hl7.encoding.Mllp
import org.rite.hl7.parser.HL7ParseResult
import java.io.BufferedInputStream
import java.io.ByteArrayOutputStream
import java.net.NetworkInterface
import java.net.ServerSocket
import java.net.SocketException
import java.net.SocketTimeoutException

/**
 * Android MLLP server reference implementation.
 *
 * This class is the Android concrete implementation of [MllpServerDelegate].
 * It binds a [ServerSocket] on the given port, accepts one client at a time,
 * reads a complete MLLP frame, validates it through the hl7Core library, and
 * sends an ACK^R01 response before closing the client connection.
 *
 * Lifecycle:
 *  - [start] binds the socket and launches an accept loop on [Dispatchers.IO].
 *  - [stop] closes the server socket and the active client socket;
 *    [ServerSocket.accept] throws [SocketException] as a clean stop signal.
 *
 * MLLP framing (HL7 v2.x Appendix C):
 *  - Frame start:  0x0B (VT / Start Block)
 *  - Frame end:    0x1C 0x0D (FS + CR / End Block + Carriage Return)
 *
 * Safety limits:
 *  - Max frame size: [MAX_FRAME_BYTES] (1 MB) — connection dropped if exceeded.
 *  - Client read timeout: [CLIENT_TIMEOUT_MS] (30 s) — unresponsive clients are dropped.
 *
 * One [HL7] facade instance is created per server — immutable and thread-safe.
 */
class MllpServer : MllpServerDelegate {

    // Pre-wired HL7 facade: parser + builder + validator + extension segments.
    private val hl7 = HL7()

    private val scope = CoroutineScope(Dispatchers.IO + SupervisorJob())

    // @Volatile: stop() may run on any thread before the IO coroutine has bound.
    @Volatile private var serverSocket: ServerSocket? = null
    @Volatile private var activeClient: java.net.Socket? = null

    // Flag prevents a late ServerStopped (emitted from the old loop's finally{})
    // from flipping a newly-started server back to STOPPED.
    @Volatile private var stopped = false

    override fun start(port: Int, onEvent: (MllpSessionEvent) -> Unit) {
        stopped = false
        scope.launch {
            try {
                // Bind to 0.0.0.0 so any connected network (Wi-Fi, USB tethering)
                // can reach this server, not just one specific interface.
                val ss = ServerSocket(port).also { serverSocket = it }

                // If stop() was called before the bind completed, close immediately.
                if (stopped) {
                    ss.close()
                    return@launch
                }

                android.util.Log.i("MllpServer", "Listening on port $port")

                while (!ss.isClosed) {
                    val client = try {
                        ss.accept()
                    } catch (e: SocketException) {
                        // ServerSocket.close() from stop() causes SocketException here —
                        // this is the normal, expected exit path for a clean stop.
                        break
                    }

                    // 30-second idle timeout per client — prevents infinite blocking on
                    // clients that connect but never send, or send unframed bytes.
                    client.soTimeout = CLIENT_TIMEOUT_MS
                    activeClient = client
                    handleConnection(client, onEvent)
                    activeClient = null
                }
            } catch (e: Exception) {
                if (!stopped) {
                    onEvent(MllpSessionEvent.ServerError(e.message ?: "Unknown error starting server"))
                }
            } finally {
                // Only emit ServerStopped if this loop was not superseded by a new start.
                if (!stopped) {
                    onEvent(MllpSessionEvent.ServerStopped)
                }
            }
        }
    }

    override fun stop() {
        stopped = true
        // Close the active client first so its read() unblocks immediately.
        activeClient?.close()
        activeClient = null
        serverSocket?.close()
        serverSocket = null
    }

    // ── Private helpers ────────────────────────────────────────────────────────

    /**
     * Handles one accepted client connection end-to-end:
     * read MLLP frame → parse → validate → send ACK → close.
     * The client socket is closed by the [use] block regardless of outcome.
     *
     * Connection-level errors emit [MllpSessionEvent.ConnectionError] so the accept
     * loop can continue. Only fatal server-level errors emit [MllpSessionEvent.ServerError].
     */
    private fun handleConnection(
        client: java.net.Socket,
        onEvent: (MllpSessionEvent) -> Unit,
    ) {
        client.use { socket ->
            try {
                val inputStream = BufferedInputStream(socket.getInputStream())
                val outputStream = socket.getOutputStream()

                // Read a complete MLLP frame. TCP may deliver bytes in multiple segments,
                // so we accumulate byte-by-byte until the end-block sentinel (0x1C 0x0D).
                // Returns null if the client disconnects before completing the frame.
                val frameBytes = readMllpFrameFromStream(inputStream)
                    ?: return // client disconnected mid-frame — nothing to ACK

                // Parse: Mllp.strip() removes VT/FS+CR framing; HL7Parser tokenizes segments.
                val parseResult = hl7.parseMllp(frameBytes)

                val info: MllpMessageInfo
                val ackBytes: ByteArray

                when (parseResult) {
                    is HL7ParseResult.Success -> {
                        val message = parseResult.message

                        // Validate: required fields, NDC format, supported message types.
                        val validation = hl7.validate(message)

                        // Build and encode ACK^R01; AckBuilder mirrors MSH sender/receiver.
                        val ackText = hl7.ack(message)
                        ackBytes = Mllp.wrap(ackText)

                        info = MllpMessageInfo(
                            messageType = "${message.messageCode}^${message.triggerEvent}",
                            controlId = message.messageControlId,               // MSH-10
                            senderFacility = message.sendingFacility,           // MSH-4
                            senderApp = message.header?.sendingApplication ?: "", // MSH-3
                            ackCode = validation.worst.code,                    // "AA" | "AE" | "AR"
                            validationErrors = validation.issues
                                .filter { it.severity.code != "AA" }
                                .map { "[${it.segmentId ?: "?"}] ${it.errorText}" },
                            rawSegments = message.typedSegments.map { it.segmentName },
                            receivedAt = currentTimeString(),
                        )
                    }

                    is HL7ParseResult.Failure -> {
                        // Parse failure: cannot mirror MSH (no valid header), so build
                        // a minimal AR response that the sender can identify as a NAK.
                        val errorText = parseResult.errors.firstOrNull()?.message ?: "Parse failure"
                        ackBytes = Mllp.wrap(buildMinimalArAck(escapeHl7Delimiters(errorText)))

                        info = MllpMessageInfo(
                            messageType = "UNKNOWN",
                            controlId = "",
                            senderFacility = "",
                            senderApp = "",
                            ackCode = "AR",
                            validationErrors = listOf("Parse error: $errorText"),
                            rawSegments = emptyList(),
                            receivedAt = currentTimeString(),
                        )
                    }
                }

                // Write MLLP-framed ACK before closing — client blocks until this arrives.
                outputStream.write(ackBytes)
                outputStream.flush()

                onEvent(MllpSessionEvent.MessageReceived(info))

            } catch (e: SocketTimeoutException) {
                // Client connected but sent no data within CLIENT_TIMEOUT_MS.
                // Emit ConnectionError (not ServerError) so the accept loop continues.
                onEvent(MllpSessionEvent.ConnectionError("Client timed out: ${socket.remoteSocketAddress}"))
            } catch (e: Exception) {
                // Any other per-connection error (write failure, client reset, etc).
                // Do not emit ServerError — the server itself is still running.
                onEvent(MllpSessionEvent.ConnectionError("Connection error: ${e.message}"))
            }
        }
    }

    /**
     * Reads bytes from [stream] byte-by-byte until the MLLP end-block sentinel
     * (0x1C followed by 0x0D) is found. Uses [MllpFrameReader.readFrame] semantics
     * but operates on a live [java.io.InputStream] to handle streaming TCP delivery.
     *
     * Returns null if the stream ends (EOF) before the sentinel —
     * meaning the client disconnected mid-frame.
     *
     * Throws [SocketTimeoutException] if the client stops sending within [CLIENT_TIMEOUT_MS].
     *
     * @throws IllegalStateException if [MAX_FRAME_BYTES] is exceeded (protects against OOM).
     */
    private fun readMllpFrameFromStream(stream: java.io.InputStream): ByteArray? {
        val buffer = ByteArrayOutputStream(8192) // efficient resizable buffer
        var prevByte = -1
        var bytesRead = 0

        while (true) {
            val b = stream.read()
            if (b == -1) return null // EOF — client disconnected

            buffer.write(b)
            bytesRead++

            // Guard against unbounded growth (e.g. malformed frames, adversarial clients).
            if (bytesRead > MAX_FRAME_BYTES) {
                throw IllegalStateException("MLLP frame exceeded ${MAX_FRAME_BYTES / 1024} KB limit")
            }

            // End-block sentinel: File Separator (0x1C) + Carriage Return (0x0D).
            // MllpFrameReader.readFrame uses the same sentinel logic for ByteArray inputs.
            if (prevByte == 0x1C && b == 0x0D) {
                return buffer.toByteArray()
            }
            prevByte = b
        }
    }

    /**
     * Strips HL7 delimiter characters from [text] before embedding it in MSA-3
     * of the minimal NAK. This prevents a parse error message from accidentally
     * adding extra fields or segments to the outbound HL7 frame.
     */
    private fun escapeHl7Delimiters(text: String): String =
        text.replace("|", "&#124;")
            .replace("^", "&#94;")
            .replace("~", "&#126;")
            .replace("\\", "&#92;")
            .replace("&", "&#38;")
            .replace("\r", " ")
            .replace("\n", " ")

    /**
     * Builds a minimal ACK^R01 AR string for when parsing failed and there is
     * no valid MSH to mirror.
     */
    private fun buildMinimalArAck(safeErrorText: String): String {
        val ts = java.time.LocalDateTime.now()
            .format(java.time.format.DateTimeFormatter.ofPattern("yyyyMMddHHmmss"))
        return buildString {
            append("MSH|^~\\&|MllpServer||Unknown||$ts||ACK^R01|NACK-$ts|P|2.5.1\r")
            append("MSA|AR|UNKNOWN|$safeErrorText\r")
        }
    }

    private fun currentTimeString(): String =
        java.time.LocalTime.now()
            .format(java.time.format.DateTimeFormatter.ofPattern("HH:mm:ss"))

    companion object {
        /** Maximum allowed MLLP frame size. Connections exceeding this are dropped. */
        private const val MAX_FRAME_BYTES = 1_048_576 // 1 MB

        /** Per-client read timeout in milliseconds. */
        const val CLIENT_TIMEOUT_MS = 30_000

        /**
         * Returns the device's non-loopback IPv4 addresses.
         * Used by [MllpServerViewModel] to display connection targets to the user.
         */
        fun localAddresses(): List<String> =
            try {
                NetworkInterface.getNetworkInterfaces()
                    ?.toList()
                    ?.flatMap { it.inetAddresses.toList() }
                    ?.filter { !it.isLoopbackAddress && it is java.net.Inet4Address }
                    ?.map { it.hostAddress ?: "" }
                    ?.filter { it.isNotEmpty() }
                    ?: emptyList()
            } catch (_: Exception) {
                emptyList()
            }
    }
}
