package org.rite.hl7.parser.dispense

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.RXRSegment
import org.rite.hl7.model.segment.ZPRSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * Full RDE^O11 / RDE^O25 message parsing across HL7 versions 2.3.1, 2.5, 2.5.1.
 * Covers trigger selection, order groups, multi-order messages, ZPR,
 * cancel orders, and invalid scenarios.
 */
class RdeMessageParsingTest {
    private fun parser() = HL7Parser.Builder().build()

    // --- Trigger-event variants ---

    @Test
    fun rdeO11IsDispenseOrderKind() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.DISPENSE_ORDER, result.message.kind)
    }

    @Test
    fun rdeO01IsDispenseOrderKind() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20060101||RDE^O01|1|P|2.3.1\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.DISPENSE_ORDER, result.message.kind)
    }

    @Test
    fun rdeO25IsDispenseOrderKind() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O25|1|P|2.5.1\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.DISPENSE_ORDER, result.message.kind)
    }

    @Test
    fun rde001TriggerIsDispenseOrderKind() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20060101||RDE^001|1|P|2.3.1\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.DISPENSE_ORDER, result.message.kind)
    }

    // --- Core segments parsed correctly ---

    @Test
    fun rdeHasOrcAndRxe() {
        val raw =
            "MSH|^~\\&|PMS|PHARM|VIVID|KIOSK|20260101||RDE^O11|CTL-X|P|2.5\r" +
                "ORC|NW|RX-500\r" +
                "RXE|^0|00069015505^LISI 10MG^NDC|30||TAB^Tablets"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msg = result.message
        assertNotNull(msg.segment<ORCSegment>("ORC"))
        assertNotNull(msg.segment<RXESegment>("RXE"))
    }

    @Test
    fun rdeRxeFieldsParsedCorrectly() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-77\r" +
                "RXE|^0|12345678901^Drug Name^NDC|45||CAP^Capsules"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val rxe = result.message.segment<RXESegment>("RXE")!!
        assertEquals("12345678901", rxe.giveCode)
        assertEquals("Drug Name", rxe.giveName)
        assertEquals("45", rxe.giveAmountMinimum)
    }

    // --- RXR route segment ---

    @Test
    fun rdeWithRxrParsesRouteCode() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "RXR|PO^Oral^HL70162"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val rxr = result.message.segment<RXRSegment>("RXR")
        assertNotNull(rxr)
        assertEquals("PO", rxr.routeCode)
        assertEquals("Oral", rxr.routeText)
    }

    @Test
    fun rdeWithoutRxrHasNullRxr() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<RXRSegment>("RXR"))
    }

    // --- ZPR priority segment ---

    @Test
    fun rdeWithZprParsedPriority() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|HIGH"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zpr = result.message.segment<ZPRSegment>("ZPR")
        assertNotNull(zpr)
        assertEquals("PRIORITY", zpr.qualifier)
        assertEquals("HIGH", zpr.priority)
    }

    // --- Cancel order ---

    @Test
    fun rdeCancelOrderKindIsCancel() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|CA|RX-999"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.CANCEL_ORDER, result.message.kind)
    }

    // --- Multiple ORC groups ---

    @Test
    fun rdeTwoOrderGroupsBothParsed() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA\r" +
                "ORC|NW|RX-2\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val rxes = result.message.segments<RXESegment>("RXE")
        assertEquals(2, rxes.size)
        assertEquals("11111111111", rxes[0].giveCode)
        assertEquals("22222222222", rxes[1].giveCode)
    }

    @Test
    fun rdeThreeOrderGroupsAllParsed() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|RX-1\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA\r" +
                "ORC|NW|RX-2\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA\r" +
                "ORC|NW|RX-3\r" +
                "RXE|^0|33333333333^Drug3^NDC|30||EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val rxes = result.message.segments<RXESegment>("RXE")
        assertEquals(3, rxes.size)
    }

    // --- Cross-version consistency ---

    @Test
    fun rdeFor231ParsesCorrectly() {
        val raw =
            "MSH|^~\\&|PMS|PHARM|VIVID|KIOSK|20060101||RDE^O01|1|P|2.3.1\r" +
                "ORC|NW|RX-231\r" +
                "RXE|^0|00093-0058-01^AMOX^NDC|90||TAB^Tablets"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.3.1", result.message.version.wire)
        assertEquals("00093-0058-01", result.message.segment<RXESegment>("RXE")!!.giveCode)
    }

    @Test
    fun rdeFor251ParsesCorrectly() {
        val raw =
            "MSH|^~\\&|PMS|PHARM|VIVID|KIOSK|20260101||RDE^O11|1|P|2.5.1\r" +
                "ORC|NW|RX-251\r" +
                "RXE|^0|00069015505^LISI^NDC|30||TAB^Tablets"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5.1", result.message.version.wire)
        assertEquals("00069015505", result.message.segment<RXESegment>("RXE")!!.giveCode)
    }

    // --- Invalid / malformed scenarios ---

    @Test
    fun emptyMessageFails() {
        val result = parser().parse("")
        assertTrue(result is HL7ParseResult.Failure)
    }

    @Test
    fun nonMshFirstSegmentFails() {
        val result = parser().parse("ORC|NW|RX-1\rRXE|^0|12345678901^Drug^NDC|10||EA")
        assertTrue(result is HL7ParseResult.Failure)
    }
}
