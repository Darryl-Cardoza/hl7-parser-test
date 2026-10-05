package org.rite.hl7

import androidx.lifecycle.ViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update

/**
 * Bridges [MllpServerDelegate] (platform socket code) with the Compose UI.
 *
 * [delegate] is injected so tests can supply a [FakeMllpServerDelegate] without
 * needing a real socket — the ViewModel only knows the interface, not the impl.
 *
 * [localAddresses] is injected so the common class does not import the
 * Android-only [java.net.NetworkInterface]. The Android factory passes
 * `{ MllpServer.localAddresses() }`; test code passes `{ listOf("127.0.0.1") }`.
 *
 * State updates always happen via [MutableStateFlow.update], which is thread-safe,
 * so the IO socket thread may call [handleEvent] directly without a dispatcher hop.
 */
class MllpServerViewModel(
    private val delegate: MllpServerDelegate,
    private val localAddresses: () -> List<String> = { emptyList() },
) : ViewModel() {
    private val _uiState = MutableStateFlow(MllpServerState())
    val uiState: StateFlow<MllpServerState> = _uiState.asStateFlow()

    // Monotonically increasing session counter. Incremented on every start().
    // A late ServerStopped from a previous session carries the old ID and is
    // ignored when a new server is already running with a higher ID.
    private var currentSession = 0

    /**
     * Starts the MLLP server on [port].
     * Transitions status to LISTENING immediately, then processes events
     * as they arrive from the server loop.
     */
    fun start(port: Int) {
        currentSession++
        val session = currentSession
        val addresses =
            try {
                localAddresses()
            } catch (_: Exception) {
                emptyList()
            }
        _uiState.update {
            it.copy(
                status = MllpServerStatus.LISTENING,
                port = port,
                boundAddresses = addresses,
                lastError = null,
            )
        }

        delegate.start(port) { event ->
            // MutableStateFlow.update is thread-safe; called directly from the
            // IO socket thread. Compose observes via collectAsState and recomposes
            // on the next frame automatically.
            handleEvent(event, session)
        }
    }

    /**
     * Stops the server and resets status to STOPPED.
     * [MllpSessionEvent.ServerStopped] will also arrive via [handleEvent]
     * when the socket closes, but we set STOPPED here eagerly so the UI
     * responds without waiting for the socket close to propagate.
     */
    fun stop() {
        delegate.stop()
        _uiState.update { it.copy(status = MllpServerStatus.STOPPED, boundAddresses = emptyList()) }
    }

    override fun onCleared() {
        super.onCleared()
        // Ensure the socket is closed when the ViewModel is destroyed
        // (e.g. Activity finishes while the server is running).
        delegate.stop()
    }

    internal fun handleEvent(
        event: MllpSessionEvent,
        session: Int = currentSession,
    ) {
        when (event) {
            is MllpSessionEvent.MessageReceived -> {
                _uiState.update { state ->
                    state.copy(
                        // Return to LISTENING after processing so the status reflects
                        // "waiting for next connection", not "currently reading".
                        status = MllpServerStatus.LISTENING,
                        totalReceived = state.totalReceived + 1,
                        lastMessage = event.info,
                        lastError = null,
                    )
                }
            }
            is MllpSessionEvent.ConnectionError -> {
                // Non-fatal: one client connection failed. Accept loop continues.
                // Stay LISTENING; surface the error so the user can diagnose.
                _uiState.update { state ->
                    state.copy(lastError = event.message)
                }
            }
            is MllpSessionEvent.ServerError -> {
                // Fatal: the server socket itself failed. Accept loop has exited.
                _uiState.update {
                    it.copy(
                        status = MllpServerStatus.STOPPED,
                        boundAddresses = emptyList(),
                        lastError = event.message,
                    )
                }
            }
            is MllpSessionEvent.ServerStopped -> {
                // Guard against a late ServerStopped from a previous loop firing
                // after a new server has already started (race: stop → quick restart).
                if (session == currentSession) {
                    _uiState.update { it.copy(status = MllpServerStatus.STOPPED, boundAddresses = emptyList()) }
                }
            }
        }
    }
}
