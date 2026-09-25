package org.rite.hl7

import org.rite.hl7.model.segment.ZPRSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertSame
import kotlin.test.assertTrue

class OrderGroupTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZPRSegment.Definition)
        .build()

    private fun parse(raw: String) =
        (parser().parse(raw.replace("\n", "\r")) as HL7ParseResult.Success).message

    @Test
    fun messageExposesTwoOrderGroupsFromSampleMessage() {
        val msg = parse(
            """
            MSH|^~\&|PMS|PHARMACY|PILLCOUNTER|ROBOT|20260925102510||RDE^O11|MSG10002|P|2.5
            PID|1||PAT100232^^^PMS^MR||DOE^JOHN^A||19850101|M
            ORC|NW|ORD789^EHR|RX456789^PHARM||IP
            RXE|1^BID^^202609250900|00071015523^LISINOPRIL 10MG TAB^NDC|10||MG|TAB|||||30|TAB|5||RX456789|5|0
            RXR|PO^ORAL
            ZPR|1|PRIORITY|High
            ORC|RF|ORD790^EHR|RX456790^PHARM||IP
            RXE|1^QD^^202609250900|00093014701^AMLODIPINE 5MG TAB^NDC|5||MG|TAB|||||30|TAB|5||RX456790|3|2
            RXR|PO^ORAL
            ZPR|1|PRIORITY|Normal
            """.trimIndent()
        )

        assertEquals(2, msg.orderGroups.size)
        assertEquals("ORD789", msg.orderGroups[0].orc.placerOrderNumber)
        assertEquals("ORD790", msg.orderGroups[1].orc.placerOrderNumber)
    }

    @Test
    fun orderGroupsIsStableAcrossRepeatedAccess() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        assertSame(msg.orderGroups, msg.orderGroups)
    }

    @Test
    fun flatAccessorsStillWorkUnchangedAlongsideOrderGroups() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA^each"
        )

        // Flat accessor: first ORC only (pre-existing behavior, untouched).
        val firstOrc = msg.segment<org.rite.hl7.model.segment.ORCSegment>("ORC")
        assertEquals("1001", firstOrc?.placerOrderNumber)

        // Flat accessor: all RXE flattened (pre-existing behavior, untouched).
        assertEquals(2, msg.segments<org.rite.hl7.model.segment.RXESegment>("RXE").size)

        // New grouped accessor: correctly paired.
        assertEquals(2, msg.orderGroups.size)
        assertTrue(msg.orderGroups[1].rxe?.giveCode == "22222222222")
    }
}
