package org.rite.hl7.parser.inventory

import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * ZAD (Inventory Adjustment) segment field parsing.
 * Covers all named fields, adjustment type signs (+/-/O),
 * multi-row ZAD, optional comment field, and version variants 2.3.1 / 2.5.1.
 */
class ZadSegmentParsingTest {
    private fun parser() =
        HL7Parser
            .Builder()
            .registerCustomSegment(ZADSegment.Definition)
            .build()

    private fun parseZad(
        zadLine: String,
        version: String = "2.5",
    ): ZADSegment {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|$version\r" +
                "INV|1|123^Drug^NDC|||10|EA\r$zadLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed")
        val zad = result.message.segment<ZADSegment>(ZADSegment.NAME)
        assertNotNull(zad)
        return zad
    }

    @Test
    fun parsesSetId() {
        val zad = parseZad("ZAD|2|+|5|PO_RECEIPT|20260101|JDOE")
        assertEquals("2", zad.setId)
    }

    @Test
    fun parsesAdjustmentTypeAdd() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260101|JDOE")
        assertEquals("+", zad.adjustmentType)
    }

    @Test
    fun parsesAdjustmentTypeSubtract() {
        val zad = parseZad("ZAD|1|-|3|DAMAGED_IN_TRANSIT|20260101|JDOE")
        assertEquals("-", zad.adjustmentType)
    }

    @Test
    fun parsesAdjustmentTypeOverwrite() {
        val zad = parseZad("ZAD|1|O|150|PHYSICAL_INVENTORY|20260101|JDOE")
        assertEquals("O", zad.adjustmentType)
    }

    @Test
    fun parsesAdjustmentTypeAsLoss() {
        val zad = parseZad("ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JDOE")
        assertEquals("LOSS", zad.adjustmentType)
    }

    @Test
    fun parsesAdjustmentQuantityInteger() {
        val zad = parseZad("ZAD|1|+|100|PO_RECEIPT|20260101|JDOE")
        assertEquals("100", zad.adjustmentQuantity)
    }

    @Test
    fun parsesAdjustmentQuantityDecimal() {
        val zad = parseZad("ZAD|1|-|5.5|DAMAGED_IN_TRANSIT|20260101|JDOE")
        assertEquals("5.5", zad.adjustmentQuantity)
    }

    @Test
    fun parsesAdjustmentReasonPoReceipt() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260101|JDOE")
        assertEquals("PO_RECEIPT", zad.adjustmentReason)
    }

    @Test
    fun parsesAdjustmentReasonDamaged() {
        val zad = parseZad("ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JDOE")
        assertEquals("DAMAGED_IN_TRANSIT", zad.adjustmentReason)
    }

    @Test
    fun parsesAdjustmentReasonBroken() {
        val zad = parseZad("ZAD|1|-|3|BROKEN|20260101|JDOE")
        assertEquals("BROKEN", zad.adjustmentReason)
    }

    @Test
    fun parsesAdjustmentReasonTransferIn() {
        val zad = parseZad("ZAD|1|+|10|TRANSFER_IN|20260101|JDOE")
        assertEquals("TRANSFER_IN", zad.adjustmentReason)
    }

    @Test
    fun parsesAdjustmentReasonPhysicalInventory() {
        val zad = parseZad("ZAD|2|O|150|PHYSICAL_INVENTORY|20260101|JDOE")
        assertEquals("PHYSICAL_INVENTORY", zad.adjustmentReason)
    }

    @Test
    fun parsesAdjustmentDateTime() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260615141500|JDOE")
        assertEquals("20260615141500", zad.adjustmentDateTime)
    }

    @Test
    fun parsesApprovedBy() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260101|JOHN.DOE")
        assertEquals("JOHN.DOE", zad.approvedBy)
    }

    @Test
    fun parsesOptionalComment() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260101|JDOE|Received from supplier X")
        assertEquals("Received from supplier X", zad.comment)
    }

    @Test
    fun blankCommentIsEmpty() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20260101|JDOE")
        assertEquals("", zad.comment)
    }

    // --- Multi-row ZAD ---

    @Test
    fun multipleZadRowsAllParsed() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
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

    // --- Absent ZAD ---

    @Test
    fun messageWithoutZadReturnsNull() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^Drug^NDC|||10|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZADSegment>(ZADSegment.NAME))
    }

    // --- Version variants ---

    @Test
    fun zadParsedFor231() {
        val zad = parseZad("ZAD|1|+|5|PO_RECEIPT|20060101|JDOE", version = "2.3.1")
        assertEquals("PO_RECEIPT", zad.adjustmentReason)
    }

    @Test
    fun zadParsedFor251() {
        val zad = parseZad("ZAD|1|-|3|BROKEN|20260101|JANE.DOE", version = "2.5.1")
        assertEquals("BROKEN", zad.adjustmentReason)
        assertEquals("JANE.DOE", zad.approvedBy)
    }
}
