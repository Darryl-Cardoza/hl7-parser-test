package org.rite.hl7

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull

/**
 * Unit tests for the MLLP frame-reading logic.
 *
 * Each test feeds bytes into [MllpFrameReader.readFrame] via a byte array,
 * simulating what [java.io.InputStream.read] would deliver from a socket.
 * Tests verify behavior defined in the plan's Review Focus:
 *  - Complete frame parsed correctly
 *  - Partial frame (stream ends before sentinel) returns null
 *  - Frame split across multiple simulated reads (sentinel at end)
 */
class MllpFrameReaderTest {

    // MLLP framing constants
    private val startBlock: Byte = 0x0B  // Start Block (Vertical Tab)
    private val endBlock: Byte = 0x1C  // End Block (File Separator)
    private val carriageReturn: Byte = 0x0D  // Carriage Return

    private fun frame(text: String): ByteArray {
        val body = text.encodeToByteArray()
        val out = ByteArray(body.size + 3)
        out[0] = startBlock
        body.copyInto(out, destinationOffset = 1)
        out[body.size + 1] = endBlock
        out[body.size + 2] = carriageReturn
        return out
    }

    @Test
    fun completeMllpFrameIsReturnedAsBytes() {
        val hl7 = "MSH|^~\\&|App|Fac|||20240101||RDE^O11|CTL001|P|2.5.1"
        val input = frame(hl7)

        val result = MllpFrameReader.readFrame(input)

        // readFrame returns the raw frame bytes; Mllp.strip() is applied separately
        assertEquals(input.toList(), result?.toList())
    }

    @Test
    fun emptyStreamReturnsNull() {
        val result = MllpFrameReader.readFrame(byteArrayOf())
        assertNull(result, "Empty byte array (EOF immediately) should return null")
    }

    @Test
    fun partialFrameWithoutSentinelReturnsNull() {
        // Frame bytes with no endBlock+carriageReturn — client disconnected mid-frame
        val partial = byteArrayOf(startBlock, 'M'.code.toByte(), 'S'.code.toByte(), 'H'.code.toByte())
        val result = MllpFrameReader.readFrame(partial)
        assertNull(result, "Frame without end-block sentinel should return null")
    }

    @Test
    fun frameWithoutLeadingStartBlockIsStillRead() {
        // Some senders omit the VT prefix; frame reader should still read until sentinel
        val hl7 = "MSH|^~\\&|App|Fac|||20240101||RDE^O11|CTL002|P|2.5.1"
        val body = hl7.encodeToByteArray()
        val input = ByteArray(body.size + 2)
        body.copyInto(input)
        input[body.size] = endBlock
        input[body.size + 1] = carriageReturn

        val result = MllpFrameReader.readFrame(input)
        // Should return bytes up to and including the sentinel
        assertEquals(input.toList(), result?.toList())
    }

    @Test
    fun sentinelEbWithoutFollowingCrDoesNotTerminate() {
        // endBlock byte alone (not followed by carriageReturn) should not terminate the frame
        val hl7 = "MSH|^~\\&|App|Fac"
        val body = hl7.encodeToByteArray()
        // Inject a lone endBlock in the middle, then proper endBlock+carriageReturn at end
        val input = byteArrayOf(startBlock) +
            body.copyOfRange(0, 3) +
            byteArrayOf(endBlock) +      // lone endBlock — not a sentinel
            body.copyOfRange(3, body.size) +
            byteArrayOf(endBlock, carriageReturn)    // real sentinel
        val result = MllpFrameReader.readFrame(input)
        assertEquals(input.toList(), result?.toList())
    }
}
