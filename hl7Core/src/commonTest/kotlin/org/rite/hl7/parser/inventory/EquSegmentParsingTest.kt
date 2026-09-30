package org.rite.hl7.parser.inventory

import org.rite.hl7.model.segment.EQUSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * EQU segment parsing — both wire shapes:
 *   - With leading Set-ID (real device variant: field 1 = setId, field 2 = composite ID)
 *   - Without leading Set-ID (standard HL7 v2.5.1: field 1 = composite ID)
 *   - Bare plain ID (neither composite field is populated)
 *
 * Covers equipmentId, eventDateTime, equipmentState, and version variants.
 */
class EquSegmentParsingTest {

    private fun parser() = HL7Parser.Builder().build()

    private fun parseEqu(equLine: String, version: String = "2.5.1"): EQUSegment {
        val raw = "MSH|^~\\&|PMS|PHARM|PARATA|ROBOT|20260101||INR^U06|1|P|$version\r$equLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed: ${(result as? HL7ParseResult.Failure)?.errors}")
        val equ = result.message.segment<EQUSegment>(EQUSegment.NAME)
        assertNotNull(equ)
        return equ
    }

    // --- With leading Set-ID ---

    @Test
    fun withLeadingSetIdParsesEquipmentId() {
        val equ = parseEqu("EQU|1|TERMINAL_13^Terminal 13^RITE|20260901134041|A")
        assertEquals("TERMINAL_13", equ.equipmentId)
    }

    @Test
    fun withLeadingSetIdParsesEventDateTime() {
        val equ = parseEqu("EQU|1|TERMINAL_13^Terminal 13^RITE|20260901134041|A")
        assertEquals("20260901134041", equ.eventDateTime)
    }

    @Test
    fun withLeadingSetIdParsesEquipmentStateActive() {
        val equ = parseEqu("EQU|1|TERMINAL_13^Terminal 13^RITE|20260901134041|A")
        assertEquals("A", equ.equipmentStateRaw)
    }

    @Test
    fun withLeadingSetIdParsesEquipmentStateIdle() {
        val equ = parseEqu("EQU|1|TERMINAL_13^Terminal 13^RITE|20260901134041|I")
        assertEquals("I", equ.equipmentStateRaw)
    }

    // --- Without leading Set-ID (composite at field 1) ---

    @Test
    fun withoutLeadingSetIdParsesEquipmentId() {
        val equ = parseEqu("EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A")
        assertEquals("ROBOT1", equ.equipmentId)
    }

    @Test
    fun withoutLeadingSetIdParsesEventDateTime() {
        val equ = parseEqu("EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A")
        assertEquals("20251113190000", equ.eventDateTime)
    }

    @Test
    fun withoutLeadingSetIdParsesEquipmentState() {
        val equ = parseEqu("EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A")
        assertEquals("A", equ.equipmentStateRaw)
    }

    // --- Bare plain ID (no composite) ---

    @Test
    fun barePlainIdParsesEquipmentId() {
        val equ = parseEqu("EQU|DEVICE-1|20260623091205|A")
        assertEquals("DEVICE-1", equ.equipmentId)
    }

    @Test
    fun barePlainIdParsesEventDateTime() {
        val equ = parseEqu("EQU|DEVICE-1|20260623091205|A")
        assertEquals("20260623091205", equ.eventDateTime)
    }

    // --- Missing equipment state ---

    @Test
    fun missingEquipmentStateIsBlank() {
        val equ = parseEqu("EQU|ROBOT1^Parata Max 2^MFG|20251113190000|")
        assertEquals("", equ.equipmentStateRaw)
    }

    // --- Absent EQU ---

    @Test
    fun messageWithoutEquReturnsNull() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5.1\r" +
            "INV|1|00069015505^Drug^NDC|LOT-A|20251201|150|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<EQUSegment>(EQUSegment.NAME))
    }

    // --- Version variants ---

    @Test
    fun equParsedFor231() {
        val equ = parseEqu("EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A", version = "2.3.1")
        assertEquals("ROBOT1", equ.equipmentId)
    }

    @Test
    fun equParsedFor25() {
        val equ = parseEqu("EQU|1|TERMINAL_13^Terminal 13^RITE|20260901134041|A", version = "2.5")
        assertEquals("TERMINAL_13", equ.equipmentId)
    }
}
