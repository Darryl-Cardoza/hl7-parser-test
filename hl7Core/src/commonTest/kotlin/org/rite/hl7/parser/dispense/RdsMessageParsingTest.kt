package org.rite.hl7.parser.dispense

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXDSegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.model.segment.ZSVSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * Full RDS^O13 / RDS^O01 message parsing across HL7 versions 2.3.1, 2.5, 2.5.1.
 * Covers trigger selection, segment presence, messageKind classification,
 * multi-segment parsing, and valid/invalid scenarios.
 */
class RdsMessageParsingTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZSNSegment.Definition)
        .registerCustomSegment(ZSVSegment.Definition)
        .build()

    // --- Version-specific trigger events ---

    @Test
    fun rds231UsesO01Trigger() {
        val raw = "MSH|^~\\&|PHARM|FAC|PMS|HOSP|20060101||RDS^O01|CTL-1|P|2.3.1\r" +
            "ORC|RE||RX-1||CM\r" +
            "RXD|1|00093-0058-01||90"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("O01", result.message.segment<MSHSegment>("MSH")!!.triggerEvent)
    }

    @Test
    fun rds25UsesO13Trigger() {
        val raw = "MSH|^~\\&|PHARM|FAC|PMS|HOSP|20260101||RDS^O13|CTL-2|P|2.5\r" +
            "ORC|RE||RX-2||CM\r" +
            "RXD|1|00093-0058-01||30"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("O13", result.message.segment<MSHSegment>("MSH")!!.triggerEvent)
    }

    @Test
    fun rds251UsesO13Trigger() {
        val raw = "MSH|^~\\&|PHARM|FAC|PMS|HOSP|20260101||RDS^O13|CTL-3|P|2.5.1\r" +
            "ORC|RE||RX-3||CM\r" +
            "RXD|1|00093-0058-02||60"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("O13", result.message.segment<MSHSegment>("MSH")!!.triggerEvent)
    }

    // --- messageKind classification ---

    @Test
    fun rdsMessageKindIsDispense() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "ORC|RE||RX-1||CM\r" +
            "RXD|1|00093-0058-01||90"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.DISPENSE, result.message.kind)
    }

    @Test
    fun rdsCancelOrderKindIsCancel() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "ORC|CA|RX-999"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.CANCEL_ORDER, result.message.kind)
    }

    // --- Core segment presence ---

    @Test
    fun rdsHasAllCoreSegments() {
        val raw = "MSH|^~\\&|PHARM-SYS|MAIN|PMS|HOSP|20260623||RDS^O13|CTL-9|P|2.5\r" +
            "ORC|RE|ORD-1|RX-8765||CM\r" +
            "RXD|1|00093-0058-01^AMOX 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100842"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msg = result.message
        assertNotNull(msg.segment<MSHSegment>("MSH"))
        assertNotNull(msg.segment<ORCSegment>("ORC"))
        assertNotNull(msg.segment<RXDSegment>("RXD"))
    }

    @Test
    fun rdsWithoutOrcIsStillParsed() {
        // ORC is optional in practice; parser should still succeed
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "RXD|1|00093-0058-01||90"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNotNull(result.message.segment<RXDSegment>("RXD"))
    }

    // --- ZSN / ZSV presence ---

    @Test
    fun rdsWithZsnParsesSerialNumber() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "RXD|1|00093-0058-01||90\r" +
            "ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zsn = result.message.segment<ZSNSegment>(ZSNSegment.NAME)
        assertNotNull(zsn)
        assertEquals("21N4F9XK0042", zsn.packageSerialNumber)
        assertEquals("D", zsn.transactionType)
        assertEquals("LOT78321", zsn.lotNumber)
    }

    @Test
    fun rdsWithMultipleZsnRowsParsesAll() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "RXD|1|00093-0058-01||90\r" +
            "ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D\r" +
            "ZSN|2|21N4F9XK0099|00093-0058-01|LOT78321|20271031|D"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zsns = result.message.segments<ZSNSegment>("ZSN")
        assertEquals(2, zsns.size)
        assertEquals("21N4F9XK0042", zsns[0].packageSerialNumber)
        assertEquals("21N4F9XK0099", zsns[1].packageSerialNumber)
    }

    @Test
    fun rdsWithZsvParsesValidationResult() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "RXD|1|00093-0058-01||90\r" +
            "ZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1||20260101120000|EXACT"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zsv = result.message.segment<ZSVSegment>(ZSVSegment.NAME)
        assertNotNull(zsv)
        assertEquals("MATCH", zsv.validationResult)
        assertEquals("EXACT", zsv.matchStrength)
    }

    @Test
    fun rdsWithoutZsnHasNullZsn() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5\r" +
            "RXD|1|00093-0058-01||90"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZSNSegment>(ZSNSegment.NAME))
        assertNull(result.message.segment<ZSVSegment>(ZSVSegment.NAME))
    }

    // --- Invalid scenarios ---

    @Test
    fun rdsWithBlankMshFails() {
        val result = parser().parse("")
        assertTrue(result is HL7ParseResult.Failure)
    }

    @Test
    fun rdsWithUnknownVersionStillParses() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|9.9\r" +
            "RXD|1|00093-0058-01||90"
        val result = parser().parse(raw)
        // Parser degrades gracefully to default version
        assertTrue(result is HL7ParseResult.Success)
    }

    // --- Cross-version field consistency ---

    @Test
    fun rdsFieldsConsistentAcross231And251() {
        val raw231 = "MSH|^~\\&|A|B|C|D|20060101||RDS^O01|CTL|P|2.3.1\r" +
            "RXD|1|00093-0058-01^AMOX^NDC||90|TAB^Tablets|^|RX100"
        val raw251 = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|CTL|P|2.5.1\r" +
            "RXD|1|00093-0058-01^AMOX^NDC||90|TAB^Tablets|^|RX100"

        listOf(raw231, raw251).forEach { raw ->
            val result = parser().parse(raw)
            assertTrue(result is HL7ParseResult.Success)
            val rxd = result.message.segment<RXDSegment>("RXD")!!
            assertEquals("00093-0058-01", rxd.dispenseGiveCode)
            assertEquals("90", rxd.actualDispenseAmount)
            assertEquals("RX100", rxd.prescriptionNumber)
        }
    }
}
