package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * ORC segment field parsing — order control, placer/filler order numbers,
 * order status, and order control typed enum across versions.
 */
class OrcSegmentParsingTest {
    private fun parser() = HL7Parser.Builder().build()

    private fun parseOrc(
        orcLine: String,
        version: String = "2.5",
    ): ORCSegment {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|$version\r$orcLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed")
        val orc = result.message.segment<ORCSegment>(ORCSegment.NAME)
        assertNotNull(orc)
        return orc
    }

    @Test
    fun parsesOrderControlNw() {
        val orc = parseOrc("ORC|NW|1001")
        assertEquals("NW", orc.orderControlRaw)
    }

    @Test
    fun parsesOrderControlCa() {
        val orc = parseOrc("ORC|CA|2002")
        assertEquals("CA", orc.orderControlRaw)
    }

    @Test
    fun parsesOrderControlRe() {
        val orc = parseOrc("ORC|RE||RX-888")
        assertEquals("RE", orc.orderControlRaw)
    }

    @Test
    fun parsesPlacerOrderNumber() {
        val orc = parseOrc("ORC|NW|RX-100842")
        assertEquals("RX-100842", orc.placerOrderNumber)
    }

    @Test
    fun parsesFillerOrderNumber() {
        val orc = parseOrc("ORC|RE|ORD-1|RX-5000")
        assertEquals("RX-5000", orc.fillerOrderNumber)
    }

    @Test
    fun parsesOrderStatus() {
        val orc = parseOrc("ORC|RE|ORD-1|RX-5000||CM")
        assertEquals("CM", orc.orderStatusRaw)
    }

    @Test
    fun parsesOrderStatusIp() {
        val orc = parseOrc("ORC|NW|1001|||IP")
        assertEquals("IP", orc.orderStatusRaw)
    }

    @Test
    fun parsesBlankOrderStatus() {
        val orc = parseOrc("ORC|NW|1001")
        assertEquals("", orc.orderStatusRaw)
    }

    @Test
    fun parsesOrcFor231() {
        val orc = parseOrc("ORC|RE|ORD-231|RX-231||CM", version = "2.3.1")
        assertEquals("RE", orc.orderControlRaw)
        assertEquals("ORD-231", orc.placerOrderNumber)
        assertEquals("RX-231", orc.fillerOrderNumber)
        assertEquals("CM", orc.orderStatusRaw)
    }

    @Test
    fun parsesOrcFor251() {
        val orc = parseOrc("ORC|NW|ORD-251|||SC", version = "2.5.1")
        assertEquals("NW", orc.orderControlRaw)
        assertEquals("SC", orc.orderStatusRaw)
    }

    @Test
    fun blankOrderControlParsedAsEmpty() {
        val orc = parseOrc("ORC||1001")
        assertEquals("", orc.orderControlRaw)
    }

    @Test
    fun parsesOrcInRdsMessage() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|1|P|2.5\r" +
                "ORC|RE|ORD-A|RX-B||CM"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val orc = result.message.segment<ORCSegment>(ORCSegment.NAME)!!
        assertEquals("RE", orc.orderControlRaw)
        assertEquals("ORD-A", orc.placerOrderNumber)
    }
}
