package org.rite.hl7

/**
 * Extracts a complete MLLP frame from a raw byte array.
 *
 * MLLP frame format (HL7 v2.x Appendix C):
 *   [0x0B] ... message bytes ... [0x1C][0x0D]
 *    VT (Start Block)            FS+CR (End Block + Carriage Return)
 *
 * Extracted as a platform-neutral object so tests can run on all targets
 * without needing a real TCP socket.
 */
internal object MllpFrameReader {
    private const val EB: Int = 0x1C // End Block (File Separator)
    private const val CR: Int = 0x0D // Carriage Return

    /**
     * Scans [bytes] for the MLLP end-block sentinel (0x1C followed by 0x0D)
     * and returns all bytes from index 0 up to and including the sentinel.
     * Returns null if [bytes] is empty or the sentinel is never found
     * (simulates EOF / client disconnect before frame completion).
     *
     * The leading Start Block byte (0x0B) is included in the returned slice
     * when present — callers use [org.rite.hl7.encoding.Mllp.strip] to remove framing.
     */
    fun readFrame(bytes: ByteArray): ByteArray? {
        if (bytes.isEmpty()) return null

        var prevByte = -1
        for (i in bytes.indices) {
            val b = bytes[i].toInt() and 0xFF
            // Sentinel: File Separator (0x1C) followed immediately by Carriage Return (0x0D)
            if (prevByte == EB && b == CR) {
                return bytes.copyOfRange(0, i + 1)
            }
            prevByte = b
        }
        // Reached end of bytes without finding the sentinel — partial frame.
        return null
    }
}
