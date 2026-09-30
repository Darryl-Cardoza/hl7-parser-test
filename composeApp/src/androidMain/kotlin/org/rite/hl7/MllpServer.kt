package org.rite.hl7

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.launch
import org.rite.hl7.encoding.Mllp
import org.rite.hl7.parser.HL7ParseResult
import java.io.InputStream
import java.net.NetworkInterface
import java.net.ServerSocket
import java.net.SocketException

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
 *  - [stop] closes the socket; [ServerSocket.accept] throws [SocketException]
 *    which is caught as a clean stop signal (not an error).
 *
 * MLLP framing (HL7 v2.x Appendix C):
 *  - Frame start:  0x0B (VT / Start Block)
 *  - Frame end:    0x1C 0x0D (FS + CR / End Block + Carriage Return)
 *
 * One [HL7] facade instance is created per server — immutable and thread-safe.
 */
class MllpServer : MllpServerDelegate {

    // Pre-wired HL7 facade: parser + builder + validator + extension segments.
    // Constructing once avoids per-message parser allocation.
    private val hl7 = HL7()

    private val scope = CoroutineScope(Dispatchers.IO + SupervisorJob())
    private var serverSocket: ServerSocket? = null

    override fun start(port: Int, onEvent: (MllpSessionEvent) -> Unit) {
        scope.launch {
            try {
                // Bind to 0.0.0.0 so any connected network (Wi-Fi, USB tethering)
                // can reach this server, not just one specific interface.
                val ss = ServerSocket(port).also { serverSocket = it }
                android.util.Log.i("MllpServer", "Listening on port $port")

                while (!ss.isClosed) {
                    // accept() blocks until a client connects or the socket is closed.
                    val client = try {
                        ss.accept()
                    } catch (e: SocketException) {
                        // ServerSocket.close() from stop() causes SocketException here —
                        // this is the normal, expected exit path for a clean stop.
                        break
                    }

                    handleConnection(client, onEvent)
                }
            } catch (e: Exception) {
                onEvent(MllpSessionEvent.ServerError(e.message ?: "Unknown error starting server"))
            } finally {
                // Always emit ServerStopped so the UI transitions to STOPPED state.
                onEvent(MllpSessionEvent.ServerStopped)
            }
        }
    }

    override fun stop() {
        serverSocket?.close()
        serverSocket = null
    }

    // ── Private helpers ────────────────────────────────────────────────────────

    /**
     * Handles one accepted client connection end-to-end:
     * read MLLP frame → parse → validate → send ACK → close.
     * The client socket is closed by the [use] block regardless of outcome.
     */
    private fun handleConnection(
        client: java.net.Socket,
        onEvent: (MllpSessionEvent) -> Unit,
    ) {
        client.use { socket ->
            try {
                val inputStream = socket.getInputStream()
                val outputStream = socket.getOutputStream()

                // Accumulate bytes from the stream until the MLLP end-block sentinel.
                // TCP may deliver bytes in multiple segments, so we cannot read once
                // and assume we have a full frame.
                val frameBytes = readMllpFrameFromStream(inputStream) ?: return

                // Parse: Mllp.strip() removes VT/FS+CR framing; HL7Parser tokenizes segments.
                val parseResult = hl7.parseMllp(frameBytes)

                val info: MllpMessageInfo
                val ackBytes: ByteArray

                when (parseResult) {
                    is HL7ParseResult.Success -> {
                        val message = parseResult.message

                        // Validate: check required fields, NDC format, supported message types.
                        val validation = hl7.validate(message)

                        // Build and encode ACK^R01; AckBuilder mirrors MSH sender/receiver.
                        val ackText = hl7.ack(message)
                        ackBytes = Mllp.wrap(ackText)

                        info = MllpMessageInfo(
                            messageType = "${message.messageCode}^${message.triggerEvent}",
                            controlId = message.messageControlId,        // MSH-10
                            senderFacility = message.sendingFacility,    // MSH-4
                            senderApp = message.header?.sendingApplication ?: "", // MSH-3
                            ackCode = validation.worst.code,             // "AA" | "AE" | "AR"
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
                        ackBytes = Mllp.wrap(buildMinimalArAck(errorText))

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

            } catch (e: Exception) {
                onEvent(MllpSessionEvent.ServerError("Connection error: ${e.message}"))
            }
        }
    }

    /**
     * Reads bytes from [stream] one at a time until the MLLP end-block sentinel
     * (0x1C followed by 0x0D) is found, then passes the accumulated bytes to
     * [MllpFrameReader.readFrame] and returns the result.
     *
     * Returns null if the stream ends (read() returns -1) before the sentinel
     * is found — this means the client disconnected mid-frame.
     */
    private fun readMllpFrameFromStream(stream: InputStream): ByteArray? {
        val buffer = mutableListOf<Byte>()
        var prevByte = -1

        while (true) {
            val b = stream.read()
            if (b == -1) {
                // Client closed the connection before completing the MLLP frame.
                return null
            }
            buffer.add(b.toByte())

            // End-block sentinel: File Separator (0x1C) + Carriage Return (0x0D)
            if (prevByte == 0x1C && b == 0x0D) {
                return buffer.toByteArray()
            }
            prevByte = b
        }
    }

    /**
     * Builds a minimal ACK^R01 AR string for when parsing failed and there is
     * no valid MSH to mirror. Includes a timestamp-based control ID so the
     * client can correlate it with the connection attempt.
     */
    private fun buildMinimalArAck(errorText: String): String {
        val ts = java.time.LocalDateTime.now()
            .format(java.time.format.DateTimeFormatter.ofPattern("yyyyMMddHHmmss"))
        return buildString {
            append("MSH|^~\\&|MllpServer||Unknown||$ts||ACK^R01|NACK-$ts|P|2.5.1\r")
            append("MSA|AR|UNKNOWN|$errorText")
        }
    }

    private fun currentTimeString(): String =
        java.time.LocalTime.now()
            .format(java.time.format.DateTimeFormatter.ofPattern("HH:mm:ss"))

    companion object {
        /**
         * Returns the device's non-loopback IPv4 addresses.
         * Used by [MllpServerViewModel] to display connection targets to the user
         * (e.g. "Send HL7 to 192.168.1.42:2575").
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
