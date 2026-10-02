package org.rite.hl7

/**
 * Platform-neutral contract for starting/stopping the MLLP server.
 *
 * The Android implementation ([MllpServer] in androidMain) uses
 * [java.net.ServerSocket]. The common source set and iOS source set
 * depend only on this interface, so the common ViewModel compiles on
 * all targets without pulling in Android-only JVM classes.
 */
interface MllpServerDelegate {
    /**
     * Starts the TCP server on [port]. Must not block — implementations
     * launch their own coroutine. [onEvent] is called for every
     * [MllpSessionEvent] emitted by the server loop (message received,
     * error, stopped). May be called from any thread.
     */
    fun start(port: Int, onEvent: (MllpSessionEvent) -> Unit)

    /**
     * Closes the server socket. The accept loop exits on the next
     * iteration (or immediately if blocked in [java.net.ServerSocket.accept]).
     */
    fun stop()
}
