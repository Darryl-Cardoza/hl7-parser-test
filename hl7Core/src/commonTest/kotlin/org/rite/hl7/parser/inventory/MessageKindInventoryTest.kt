package org.rite.hl7.parser.inventory

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

/**
 * HL7MessageKind classification for all inventory message types across versions.
 * Covers INVENTORY_RESPONSE, INVENTORY_REQUEST, INVENTORY_ADJUSTMENT,
 * INVENTORY_UPDATE, and boundary conditions.
 */
class MessageKindInventoryTest {
    private fun parser() =
        HL7Parser
            .Builder()
            .registerCustomSegment(ZADSegment.Definition)
            .build()

    private fun kindOf(
        msgType: String,
        version: String = "2.5",
        extra: String = "",
    ): HL7MessageKind {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||$msgType|1|P|$version$extra"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        return result.message.kind
    }

    // --- INVENTORY_RESPONSE ---

    @Test
    fun inrU05IsInventoryResponse() {
        assertEquals(HL7MessageKind.INVENTORY_RESPONSE, kindOf("INR^U05"))
    }

    @Test
    fun inrU05For231IsInventoryResponse() {
        assertEquals(HL7MessageKind.INVENTORY_RESPONSE, kindOf("INR^U05", version = "2.3.1"))
    }

    @Test
    fun inrU05For251IsInventoryResponse() {
        assertEquals(HL7MessageKind.INVENTORY_RESPONSE, kindOf("INR^U05", version = "2.5.1"))
    }

    // --- INVENTORY_REQUEST ---

    @Test
    fun inrU06WithoutZadIsInventoryRequest() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|00069-3820-20^LISI^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_REQUEST, result.message.kind)
    }

    @Test
    fun inrU06For231WithoutZadIsInventoryRequest() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20060101||INR^U06|1|P|2.3.1\r" +
                "INV|1|00069015505^Drug^NDC|||100|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_REQUEST, result.message.kind)
    }

    // --- INVENTORY_ADJUSTMENT ---

    @Test
    fun inrU06WithZadIsInventoryAdjustment() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^Drug^NDC|||10|EA\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
    }

    @Test
    fun inrU06WithZadFor231IsInventoryAdjustment() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20060101||INR^U06|1|P|2.3.1\r" +
                "INV|1|123^Drug^NDC|||10|EA\r" +
                "ZAD|1|+|5|PO_RECEIPT|20060101|JDOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
    }

    @Test
    fun inrU06WithZadFor251IsInventoryAdjustment() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5.1\r" +
                "INV|1|123^Drug^NDC|||10|EA\r" +
                "ZAD|1|-|3|BROKEN|20260101|JANE.DOE"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, result.message.kind)
    }

    // --- INVENTORY_UPDATE ---

    @Test
    fun inuU05IsInventoryUpdate() {
        assertEquals(HL7MessageKind.INVENTORY_UPDATE, kindOf("INU^U05"))
    }

    @Test
    fun inuU05For231IsInventoryUpdate() {
        assertEquals(HL7MessageKind.INVENTORY_UPDATE, kindOf("INU^U05", version = "2.3.1"))
    }

    @Test
    fun inuU05For251IsInventoryUpdate() {
        assertEquals(HL7MessageKind.INVENTORY_UPDATE, kindOf("INU^U05", version = "2.5.1"))
    }

    // --- ZAD presence switches INR^U06 kind —  key boundary ---

    @Test
    fun inrU06KindSwitchesWhenZadAdded() {
        val rawWithout =
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^Drug^NDC|||10|EA"
        val rawWith = rawWithout + "\rZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"

        val withoutZad = (parser().parse(rawWithout) as HL7ParseResult.Success).message.kind
        val withZad = (parser().parse(rawWith) as HL7ParseResult.Success).message.kind

        assertEquals(HL7MessageKind.INVENTORY_REQUEST, withoutZad)
        assertEquals(HL7MessageKind.INVENTORY_ADJUSTMENT, withZad)
    }

    // --- UNKNOWN ---

    @Test
    fun adtA01IsUnknown() {
        assertEquals(HL7MessageKind.UNKNOWN, kindOf("ADT^A01"))
    }

    @Test
    fun inrWithUnrecognizedTriggerIsUnknown() {
        assertEquals(HL7MessageKind.UNKNOWN, kindOf("INR^U99"))
    }
}
