package org.rite.hl7.parser.inventory

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.EQUSegment
import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * Full INR^U05 inventory count response message parsing across versions 2.3.1, 2.5, 2.5.1.
 * Covers messageKind classification, multi-INV rows, EQU presence, NDC formats,
 * compact layout, and valid/invalid scenarios.
 */
class InrU05MessageParsingTest {

    private fun parser() = HL7Parser.Builder().build()

    // --- messageKind ---

    @Test
    fun inrU05IsInventoryResponseKind() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
            "INV|1|12345678901^Drug^NDC|||10|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_RESPONSE, result.message.kind)
    }

    // --- Core structure ---

    @Test
    fun inrU05HasMshAndInv() {
        val raw = "MSH|^~\\&|PARATA|ROBOT|PMS|PHARM|20260101||INR^U05|CTL|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNotNull(result.message.segment<MSHSegment>("MSH"))
        assertNotNull(result.message.segment<INVSegment>("INV"))
    }

    @Test
    fun inrU05WithEquParsesEquipmentId() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U05|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val equ = result.message.segment<EQUSegment>("EQU")
        assertNotNull(equ)
        assertEquals("ROBOT1", equ.equipmentId)
    }

    @Test
    fun inrU05WithoutEquIsStillValid() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5.1\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<EQUSegment>("EQU"))
    }

    // --- Multi-INV rows ---

    @Test
    fun inrU05MultipleInvRowsAllParsed() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U05|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L\r" +
            "INV|00067-5680-34^METFORMIN 500MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_B2^Cell B2^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val invs = result.message.segments<INVSegment>("INV")
        assertEquals(2, invs.size)
        assertEquals("00069-3820-20", invs[0].substanceIdentifier)
        assertEquals("00067-5680-34", invs[1].substanceIdentifier)
    }

    // --- INV field parsing in U05 context ---

    @Test
    fun inrU05InvNdcParsedCorrectly() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
            "INV|1|12345678901^Drug Name^NDC|||150|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val inv = result.message.segment<INVSegment>("INV")!!
        assertEquals("12345678901", inv.substanceCode)
    }

    // --- Version variants ---

    @Test
    fun inrU05For231ParsesCorrectly() {
        val raw = "MSH|^~\\&|A|B|C|D|20060101||INR^U05|1|P|2.3.1\r" +
            "INV|1|00069015505^Drug^NDC|||100|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.3.1", result.message.version.wire)
        assertEquals("00069015505", result.message.segment<INVSegment>("INV")!!.substanceCode)
    }

    @Test
    fun inrU05For251ParsesCorrectly() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5.1\r" +
            "INV|1|00069015505^Drug^NDC|||200|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5.1", result.message.version.wire)
    }

    // --- Invalid scenarios (parser-level, not validator-level) ---

    @Test
    fun emptyMessageFails() {
        val result = parser().parse("")
        assertTrue(result is HL7ParseResult.Failure)
    }

    @Test
    fun nonMshFirstSegmentFails() {
        val result = parser().parse("INV|1|00069015505^Drug^NDC|||100|EA")
        assertTrue(result is HL7ParseResult.Failure)
    }

    @Test
    fun inrU05WithMissingInvStillParses() {
        // Parser succeeds; validator rejects. Parser is permissive.
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<INVSegment>("INV"))
    }
}
