package org.rite.hl7

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull

/**
 * Unit tests for [MllpServerViewModel] state transitions.
 *
 * Uses a [FakeMllpServerDelegate] that fires events synchronously,
 * bypassing the coroutine dispatcher so tests run without a test coroutine scope.
 * This is possible because viewModelScope.launch { handleEvent(e) } is called
 * from onEvent — but the fake fires events on the same thread synchronously
 * via a stored callback, and we call it after the ViewModel is set up.
 */
class MllpServerViewModelTest {
    @Test
    fun initialStateIsStoppedWithDefaultPort() {
        val vm = MllpServerViewModel(FakeMllpServerDelegate())
        val state = vm.uiState.value

        assertEquals(MllpServerStatus.STOPPED, state.status)
        assertEquals(2575, state.port)
        assertEquals(0, state.totalReceived)
        assertNull(state.lastMessage)
    }

    @Test
    fun startSetsStatusToListening() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)

        assertEquals(MllpServerStatus.LISTENING, vm.uiState.value.status)
        assertEquals(2575, vm.uiState.value.port)
    }

    @Test
    fun stopSetsStatusToStopped() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)
        vm.stop()

        assertEquals(MllpServerStatus.STOPPED, vm.uiState.value.status)
    }

    @Test
    fun serverStoppedEventSetsStatusToStopped() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)
        // Simulate the server loop emitting a stop event (e.g. socket error)
        fake.emit(MllpSessionEvent.ServerStopped)

        assertEquals(MllpServerStatus.STOPPED, vm.uiState.value.status)
    }

    @Test
    fun serverErrorEventSetsStatusToStoppedAndPopulatesLastError() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)
        fake.emit(MllpSessionEvent.ServerError("bind failed"))

        assertEquals(MllpServerStatus.STOPPED, vm.uiState.value.status)
        assertEquals("bind failed", vm.uiState.value.lastError)
    }

    @Test
    fun connectionErrorStaysListeningAndSetsLastError() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)
        fake.emit(MllpSessionEvent.ConnectionError("client timed out"))

        // Non-fatal: server is still LISTENING; only lastError is updated.
        assertEquals(MllpServerStatus.LISTENING, vm.uiState.value.status)
        assertEquals("client timed out", vm.uiState.value.lastError)
    }

    @Test
    fun lateServerStoppedFromOldSessionIgnoredWhenNewSessionRunning() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)

        vm.stop()
        vm.start(9999) // session 2 starts

        // Session 1's late ServerStopped must NOT flip the new session to STOPPED
        vm.handleEvent(MllpSessionEvent.ServerStopped, session = 1)

        assertEquals(MllpServerStatus.LISTENING, vm.uiState.value.status)
    }
}

/**
 * Synchronous fake delegate for testing.
 * Stores the [onEvent] callback from [start] and exposes [emit] so tests can
 * fire events directly on the calling thread — no coroutines needed.
 */
private class FakeMllpServerDelegate : MllpServerDelegate {
    private var callback: ((MllpSessionEvent) -> Unit)? = null
    var stopped = false

    override fun start(
        port: Int,
        onEvent: (MllpSessionEvent) -> Unit,
    ) {
        callback = onEvent
    }

    override fun stop() {
        stopped = true
    }

    fun emit(event: MllpSessionEvent) {
        callback?.invoke(event)
    }
}
