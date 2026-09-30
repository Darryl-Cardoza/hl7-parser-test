package org.rite.hl7.parser.inventory

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * Full INR^U06 message parsing across versions 2.3.1, 2.5, 2.5.1.
 * Covers both INR^U06 flavours:
 *   - INVENTORY_REQUEST (no ZAD): inventory count request
 *   - INVENTORY_ADJUSTMENT (with ZAD): carries adjustment detail
 *
 * Covers messageKind classification, INV/ZAD field parsing, multi-ZAD rows,
 * EQU variants, and valid/invalid scenarios.
 */
class InrU06MessageParsingTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZADSegment.Definition)
        .build()

    // --- messageKind: request vs adjustment ---

    @Test
    fun inrU06WithoutZadIsInventoryRequest() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_REQUEST, result.message.kind)
    }

    @Test
    fun inrU06WithZadIsInventoryAdjustment() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|123^Drug^NDC|||10|EA\r" +
            "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
    }

    // --- INVENTORY_REQUEST: INV parsing (NDC-only request format) ---

    @Test
    fun inrU06RequestParsesInvNdc() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val inv = result.message.segment<INVSegment>("INV")!!
        // Device-sync layout (no leading setId): substance at field 1
        assertEquals("00069-3820-20", inv.substanceIdentifier)
    }

    @Test
    fun inrU06RequestParsesMultipleInvRows() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
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

    @Test
    fun inrU06RequestWithLeadingSetIdInv() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val inv = result.message.segment<INVSegment>("INV")!!
        assertEquals("00069015505", inv.substanceCode)
        assertEquals("150", inv.inventoryOnHandQuantity)
    }

    // --- INVENTORY_ADJUSTMENT: ZAD parsing ---

    @Test
    fun inrU06AdjustmentParsesZadFields() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|123^Drug^NDC|||10|EA\r" +
            "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zad = result.message.segment<ZADSegment>(ZADSegment.NAME)!!
        assertEquals("LOSS", zad.adjustmentType)
        assertEquals("5", zad.adjustmentQuantity)
        assertEquals("DAMAGED_IN_TRANSIT", zad.adjustmentReason)
        assertEquals("JOHN.DOE", zad.approvedBy)
    }

    @Test
    fun inrU06AdjustmentWithMultipleZadRows() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|123^Drug^NDC|||10|EA\r" +
            "ZAD|1|+|10|TRANSFER_IN|20260101|JDOE\r" +
            "ZAD|2|O|150|PHYSICAL_INVENTORY|20260101|JDOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zads = result.message.segments<ZADSegment>("ZAD")
        assertEquals(2, zads.size)
        assertEquals("TRANSFER_IN", zads[0].adjustmentReason)
        assertEquals("PHYSICAL_INVENTORY", zads[1].adjustmentReason)
    }

    @Test
    fun inrU06AdjustmentAddParsed() {
        val raw = "MSH|^~\\&|WMS|WAREHOUSE|EHR|HOSPITAL|20240615||INR^U06|MSG-001|P|2.5\r" +
            "INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA\r" +
            "ZAD|1|+|5|PO_RECEIPT|20240615141500|JOHN.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zad = result.message.segment<ZADSegment>(ZADSegment.NAME)!!
        assertEquals("+", zad.adjustmentType)
        assertEquals("5", zad.adjustmentQuantity)
        assertEquals("PO_RECEIPT", zad.adjustmentReason)
    }

    @Test
    fun inrU06AdjustmentSubtractParsed() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5.1\r" +
            "INV|1|00069015505^Drug^NDC|||200|EA\r" +
            "ZAD|1|-|3|BROKEN|20260101|JANE.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zad = result.message.segment<ZADSegment>(ZADSegment.NAME)!!
        assertEquals("-", zad.adjustmentType)
        assertEquals("BROKEN", zad.adjustmentReason)
    }

    // --- Version variants ---

    @Test
    fun inrU06For231ParsesCorrectly() {
        val raw = "MSH|^~\\&|WMS|WAREHOUSE|EHR|HOSPITAL|20060101||INR^U06|MSG-231|P|2.3.1\r" +
            "INV|1|00069015505^Drug Name^NDC|||150|EA\r" +
            "ZAD|1|+|5|PO_RECEIPT|20060101|JOHN.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.3.1", result.message.version.wire)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
        val zad = result.message.segment<ZADSegment>(ZADSegment.NAME)!!
        assertEquals("PO_RECEIPT", zad.adjustmentReason)
    }

    @Test
    fun inrU06For251ParsesCorrectly() {
        val raw = "MSH|^~\\&|WMS|WAREHOUSE|EHR|HOSPITAL|20260101||INR^U06|MSG-251|P|2.5.1\r" +
            "INV|1|00069015505^Drug Name^NDC|||200|EA\r" +
            "ZAD|1|-|3|BROKEN|20260101|JANE.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5.1", result.message.version.wire)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
    }

    // --- Without ZAD: no adjustment segment ---

    @Test
    fun inrU06WithoutZadHasNullZad() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|00069015505^Drug^NDC|||100|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZADSegment>(ZADSegment.NAME))
    }

    // --- Invalid scenarios ---

    @Test
    fun emptyMessageFails() {
        val result = parser().parse("")
        assertTrue(result is HL7ParseResult.Failure)
    }
}
