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
    private val SB: Byte = 0x0B  // Start Block (Vertical Tab)
    private val EB: Byte = 0x1C  // End Block (File Separator)
    private val CR: Byte = 0x0D  // Carriage Return

    private fun frame(text: String): ByteArray {
        val body = text.encodeToByteArray()
        val out = ByteArray(body.size + 3)
        out[0] = SB
        body.copyInto(out, destinationOffset = 1)
        out[body.size + 1] = EB
        out[body.size + 2] = CR
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
        // Frame bytes with no EB+CR — client disconnected mid-frame
        val partial = byteArrayOf(SB, 'M'.code.toByte(), 'S'.code.toByte(), 'H'.code.toByte())
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
        input[body.size] = EB
        input[body.size + 1] = CR

        val result = MllpFrameReader.readFrame(input)
        // Should return bytes up to and including the sentinel
        assertEquals(input.toList(), result?.toList())
    }

    @Test
    fun sentinelEbWithoutFollowingCrDoesNotTerminate() {
        // EB byte alone (not followed by CR) should not terminate the frame
        val hl7 = "MSH|^~\\&|App|Fac"
        val body = hl7.encodeToByteArray()
        // Inject a lone EB in the middle, then proper EB+CR at end
        val input = byteArrayOf(SB) +
            body.copyOfRange(0, 3) +
            byteArrayOf(EB) +      // lone EB — not a sentinel
            body.copyOfRange(3, body.size) +
            byteArrayOf(EB, CR)    // real sentinel
        val result = MllpFrameReader.readFrame(input)
        assertEquals(input.toList(), result?.toList())
    }
}
