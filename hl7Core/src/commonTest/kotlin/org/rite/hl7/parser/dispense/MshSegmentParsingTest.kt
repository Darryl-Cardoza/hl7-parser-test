package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * MSH segment field parsing for dispense-type messages across HL7 versions 2.3.1, 2.5, 2.5.1, 2.8.
 * Covers valid values, missing fields, field ordering, and version detection.
 */
class MshSegmentParsingTest {

    private fun parser() = HL7Parser.Builder().strictMode(false).build()

    // --- Sending/receiving application and facility ---

    @Test
    fun parsesSendingApplicationAndFacility() {
        val raw = "MSH|^~\\&|PHARMACY-SYS|MAIN-PHARM|EHR|HOSPITAL|20260623091205||RDS^O13|CTL-1|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")
        assertNotNull(msh)
        assertEquals("PHARMACY-SYS", msh.sendingApplication)
        assertEquals("MAIN-PHARM", msh.sendingFacility)
        assertEquals("EHR", msh.receivingApplication)
        assertEquals("HOSPITAL", msh.receivingFacility)
    }

    @Test
    fun parsesMessageCodeAndTriggerForRdsO13() {
        val raw = "MSH|^~\\&|A|B|C|D|20260623||RDS^O13|CTL-2|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDS", msh.messageCode)
        assertEquals("O13", msh.triggerEvent)
    }

    @Test
    fun parsesMessageCodeAndTriggerForRdsO01Pre25() {
        val raw = "MSH|^~\\&|A|B|C|D|20060101||RDS^O01|CTL-3|P|2.3.1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDS", msh.messageCode)
        assertEquals("O01", msh.triggerEvent)
    }

    @Test
    fun parsesMessageControlId() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|MSG-XYZ-99|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("MSG-XYZ-99", result.message.segment<MSHSegment>("MSH")!!.messageControlId)
    }

    @Test
    fun parsesVersionId231() {
        val raw = "MSH|^~\\&|A|B|C|D|20060101||RDS^O01|CTL|P|2.3.1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.3.1", result.message.version.wire)
    }

    @Test
    fun parsesVersionId25() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5", result.message.version.wire)
    }

    @Test
    fun parsesVersionId251() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5.1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5.1", result.message.version.wire)
    }

    @Test
    fun parsesVersionId28() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.8"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.8", result.message.version.wire)
    }

    @Test
    fun defaultsVersionWhenMissingFromMsh() {
        // No MSH-12 field — parser default kicks in
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P"
        val result = HL7Parser.Builder().defaultVersion("2.5").build().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5", result.message.version.wire)
    }

    @Test
    fun parsesProcessingIdProduction() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("P", result.message.segment<MSHSegment>("MSH")!!.processingId)
    }

    @Test
    fun parsesProcessingIdDebug() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|D|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("D", result.message.segment<MSHSegment>("MSH")!!.processingId)
    }

    @Test
    fun failsWhenFirstSegmentIsNotMsh() {
        val result = parser().parse("RXD|1|12345678901||30")
        assertTrue(result is HL7ParseResult.Failure)
        assertTrue(result.errors.isNotEmpty())
    }

    @Test
    fun failsOnEmptyInput() {
        val result = parser().parse("")
        assertTrue(result is HL7ParseResult.Failure)
        assertTrue(result.errors.isNotEmpty())
    }

    @Test
    fun parsesRdeO11MessageCode() {
        val raw = "MSH|^~\\&|PMS|PHARM|VIVID|KIOSK|20260101||RDE^O11|CTL-5|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDE", msh.messageCode)
        assertEquals("O11", msh.triggerEvent)
    }

    @Test
    fun parsesRdeO25MessageCode() {
        val raw = "MSH|^~\\&|PMS|PHARM|VIVID|KIOSK|20260101||RDE^O25|CTL-6|P|2.5.1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDE", msh.messageCode)
        assertEquals("O25", msh.triggerEvent)
    }

    @Test
    fun spaceSeparatedMessageTypeIsParsedCorrectly() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS O13|CTL|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDS", msh.messageCode)
        assertEquals("O13", msh.triggerEvent)
    }

    @Test
    fun rde001TriggerParsedAsValidTrigger() {
        val raw = "MSH|^~\\&|A|B|C|D|20060101||RDE^001|CTL|P|2.3.1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")!!
        assertEquals("RDE", msh.messageCode)
        assertEquals("001", msh.triggerEvent)
    }
}
