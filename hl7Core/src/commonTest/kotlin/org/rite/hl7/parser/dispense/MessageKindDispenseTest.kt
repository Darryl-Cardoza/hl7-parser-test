package org.rite.hl7.parser.dispense

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

/**
 * HL7MessageKind classification for all dispense message types across versions.
 * Covers DISPENSE, DISPENSE_ORDER, CANCEL_ORDER, and UNKNOWN/invalid classifications.
 */
class MessageKindDispenseTest {
    private fun parser() = HL7Parser.Builder().build()

    private fun kindOf(
        msgType: String,
        version: String = "2.5",
        orcLine: String? = null,
    ): HL7MessageKind {
        val orc = if (orcLine != null) "\r$orcLine" else ""
        val raw = "MSH|^~\\&|A|B|C|D|20260101||$msgType|1|P|$version$orc"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        return result.message.kind
    }

    // --- DISPENSE ---

    @Test
    fun rdsO13IsDispense() {
        assertEquals(HL7MessageKind.DISPENSE, kindOf("RDS^O13"))
    }

    @Test
    fun rdsO01Pre25IsDispense() {
        assertEquals(HL7MessageKind.DISPENSE, kindOf("RDS^O01", version = "2.3.1"))
    }

    @Test
    fun rdsO01At25IsAlsoDispense() {
        // O01 accepted even for 2.5 (legacy sending systems)
        assertEquals(HL7MessageKind.DISPENSE, kindOf("RDS^O01", version = "2.5"))
    }

    // --- DISPENSE_ORDER ---

    @Test
    fun rdeO11IsDispenseOrder() {
        assertEquals(HL7MessageKind.DISPENSE_ORDER, kindOf("RDE^O11"))
    }

    @Test
    fun rdeO01IsDispenseOrder() {
        assertEquals(HL7MessageKind.DISPENSE_ORDER, kindOf("RDE^O01", version = "2.3.1"))
    }

    @Test
    fun rdeO25IsDispenseOrder() {
        assertEquals(HL7MessageKind.DISPENSE_ORDER, kindOf("RDE^O25", version = "2.5.1"))
    }

    @Test
    fun rde001IsDispenseOrder() {
        // Eyecon device quirk: sends RDE^001 instead of RDE^O01
        assertEquals(HL7MessageKind.DISPENSE_ORDER, kindOf("RDE^001", version = "2.3.1"))
    }

    // --- CANCEL_ORDER ---

    @Test
    fun orcCaOnRdeIsCancel() {
        assertEquals(HL7MessageKind.CANCEL_ORDER, kindOf("RDE^O11", orcLine = "ORC|CA|RX-999"))
    }

    @Test
    fun orcCaOnRdsIsCancel() {
        assertEquals(HL7MessageKind.CANCEL_ORDER, kindOf("RDS^O13", orcLine = "ORC|CA|RX-999"))
    }

    @Test
    fun orcCaFor231IsCancel() {
        assertEquals(HL7MessageKind.CANCEL_ORDER, kindOf("RDE^O01", version = "2.3.1", orcLine = "ORC|CA|RX-CA"))
    }

    // --- ORC order control does not override unless CA ---

    @Test
    fun orcNwOnRdeDoesNotChangeKindToCancel() {
        assertEquals(HL7MessageKind.DISPENSE_ORDER, kindOf("RDE^O11", orcLine = "ORC|NW|RX-1"))
    }

    @Test
    fun orcReOnRdsDoesNotChangeKindToCancel() {
        assertEquals(HL7MessageKind.DISPENSE, kindOf("RDS^O13", orcLine = "ORC|RE||RX-1"))
    }

    // --- UNKNOWN ---

    @Test
    fun adtA01IsUnknown() {
        assertEquals(HL7MessageKind.UNKNOWN, kindOf("ADT^A01"))
    }

    @Test
    fun missingTriggerIsUnknown() {
        // RDS with no trigger part — unknown classification
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS|1|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.UNKNOWN, result.message.kind)
    }
}
