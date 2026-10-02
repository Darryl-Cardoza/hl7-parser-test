package org.rite.hl7

/** Lifecycle state of the MLLP TCP server. */
enum class MllpServerStatus { STOPPED, LISTENING, PROCESSING }

/**
 * All display-relevant fields extracted from one received HL7 message.
 * Carrying these out of the socket thread lets the UI observe pure data —
 * no HL7 types leak into the Compose layer.
 */
data class MllpMessageInfo(
    val messageType: String,            // e.g. "RDE^O11"  — from MSH-9
    val controlId: String,              // MSH-10: unique message identifier
    val senderFacility: String,         // MSH-4: sending facility name
    val senderApp: String,              // MSH-3: sending application name
    val ackCode: String,                // "AA" (accept) | "AE" (error) | "AR" (reject)
    val validationErrors: List<String>, // human-readable texts from ValidationResult.issues
    val rawSegments: List<String>,      // segment names in order, e.g. ["MSH","ORC","RXE"]
    val receivedAt: String,             // local time formatted "HH:mm:ss"
)

/**
 * Full UI state for [MllpServerScreen].
 * Immutable snapshot — [MllpServerViewModel] replaces the whole object on every update
 * so Compose's structural equality check triggers recomposition only when needed.
 */
data class MllpServerState(
    val status: MllpServerStatus = MllpServerStatus.STOPPED,
    val port: Int = 2575,                           // HL7 standard MLLP port
    val boundAddresses: List<String> = emptyList(), // IPv4 addresses of this device
    val totalReceived: Int = 0,
    val lastMessage: MllpMessageInfo? = null,
    /** Non-null when the last event was a ServerError or ConnectionError. */
    val lastError: String? = null,
)

/** Events emitted by the server loop to [MllpServerViewModel]. */
sealed class MllpSessionEvent {
    /** A complete HL7 message was received, validated, and ACK sent. */
    data class MessageReceived(val info: MllpMessageInfo) : MllpSessionEvent()
    /**
     * The server socket threw an unexpected fatal error (bind failure, OOM, etc).
     * The accept loop has exited — status transitions to STOPPED.
     */
    data class ServerError(val message: String) : MllpSessionEvent()
    /**
     * A single client connection failed (read error, write error, soTimeout).
     * The accept loop continues — status stays LISTENING.
     */
    data class ConnectionError(val message: String) : MllpSessionEvent()
    /** The server stopped (either user-requested or due to a fatal error). */
    object ServerStopped : MllpSessionEvent()
}
