package org.rite.hl7

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull
import kotlin.test.assertTrue

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

    private fun makeInfo(ackCode: String = "AA", errorCount: Int = 0) = MllpMessageInfo(
        messageType = "RDE^O11",
        controlId = "CTL001",
        senderFacility = "PHARMACY",
        senderApp = "PMS",
        ackCode = ackCode,
        validationErrors = List(errorCount) { "Error $it" },
        rawSegments = listOf("MSH", "ORC", "RXE"),
        receivedAt = "12:00:00",
    )

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
    fun serverErrorEventSetsStatusToStopped() {
        val fake = FakeMllpServerDelegate()
        val vm = MllpServerViewModel(fake)

        vm.start(2575)
        fake.emit(MllpSessionEvent.ServerError("bind failed"))

        assertEquals(MllpServerStatus.STOPPED, vm.uiState.value.status)
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

    override fun start(port: Int, onEvent: (MllpSessionEvent) -> Unit) {
        callback = onEvent
    }

    override fun stop() {
        stopped = true
    }

    fun emit(event: MllpSessionEvent) {
        callback?.invoke(event)
    }
}
