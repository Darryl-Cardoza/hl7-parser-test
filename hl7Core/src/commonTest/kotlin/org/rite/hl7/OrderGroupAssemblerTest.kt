package org.rite.hl7

import org.rite.hl7.model.OrderGroupAssembler
import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.PIDSegment
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.RXRSegment
import org.rite.hl7.model.segment.ZPRSegment
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.parser.HL7ParseResult
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull
import kotlin.test.assertTrue

class OrderGroupAssemblerTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZPRSegment.Definition)
        .build()

    private fun typedSegmentsOf(raw: String) =
        (parser().parse(raw.replace("\n", "\r")) as HL7ParseResult.Success).message.typedSegments

    @Test
    fun twoOrderGroupsAreAssembledInOrderWithCorrectFields() {
        val raw = """
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

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(2, groups.size)

        assertEquals("ORD789", groups[0].orc.placerOrderNumber)
        assertEquals("00071015523", groups[0].rxe?.giveCode)
        assertEquals(1, groups[0].rxr.size)
        assertEquals("PO", groups[0].rxr[0].routeCode)
        assertEquals(1, groups[0].zpr.size)
        assertEquals("High", groups[0].zpr[0].priority)

        assertEquals("ORD790", groups[1].orc.placerOrderNumber)
        assertEquals("00093014701", groups[1].rxe?.giveCode)
        assertEquals(1, groups[1].rxr.size)
        assertEquals("Normal", groups[1].zpr[0].priority)
    }

    @Test
    fun threeOrGroupsAreAssembledWithNoHardcodedCountAssumption() {
        val raw = """
            MSH|^~\&|A|B|C|D|20260101||RDE^O11|1|P|2.5
            ORC|NW|1001
            RXE|^0|11111111111^Drug1^NDC|10||EA^each
            ORC|NW|1002
            RXE|^0|22222222222^Drug2^NDC|20||EA^each
            ORC|NW|1003
            RXE|^0|33333333333^Drug3^NDC|30||EA^each
        """.trimIndent()

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(3, groups.size)
        assertEquals("1001", groups[0].orc.placerOrderNumber)
        assertEquals("1002", groups[1].orc.placerOrderNumber)
        assertEquals("1003", groups[2].orc.placerOrderNumber)
        assertEquals("11111111111", groups[0].rxe?.giveCode)
        assertEquals("22222222222", groups[1].rxe?.giveCode)
        assertEquals("33333333333", groups[2].rxe?.giveCode)
    }

    @Test
    fun singleOrderGroupMatchesPreviousSingleOrcBehavior() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|NW|1001\r" +
            "RXE|^0|12345678901^Drug^NDC|10||EA^each"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(1, groups.size)
        assertEquals("1001", groups[0].orc.placerOrderNumber)
        assertEquals("12345678901", groups[0].rxe?.giveCode)
    }

    @Test
    fun cancelOrderWithNoRxeYieldsGroupWithNullRxe() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|CA|1001"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(1, groups.size)
        assertNull(groups[0].rxe)
        assertTrue(groups[0].rxr.isEmpty())
    }

    @Test
    fun segmentsBeforeFirstOrcAreNotGrouped() {
        // Malformed/unusual input: an RXE appears before any ORC. It must not
        // be silently attached to a later ORC's group.
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "RXE|^0|99999999999^Orphan^NDC|1||EA^each\r" +
            "ORC|NW|1001\r" +
            "RXE|^0|12345678901^Drug^NDC|10||EA^each"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(1, groups.size)
        assertEquals("12345678901", groups[0].rxe?.giveCode)
    }

    @Test
    fun noOrcYieldsEmptyOrderGroups() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ZUI|12345678901|Drug|Doe^Jane|1001|10|4853|1"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertTrue(groups.isEmpty())
    }

    @Test
    fun multipleZprUnderOneOrderAreAllCaptured() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|NW|1001\r" +
            "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
            "ZPR|1|PRIORITY|High\r" +
            "ZPR|2|PRIORITY|Routine"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(1, groups.size)
        assertEquals(2, groups[0].zpr.size)
        assertEquals("High", groups[0].zpr[0].priority)
        assertEquals("Routine", groups[0].zpr[1].priority)
    }

    @Test
    fun tq1SegmentIsAttachedToItsOwnOrderGroupAcrossMultipleOrcs() {
        val raw = """
            MSH|^~\&|A|B|C|D|20260101||RDE^O11|1|P|2.5
            ORC|NW|1001
            TQ1|1|1^BID|||||202609250900||STAT
            RXE|^0|11111111111^Drug1^NDC|10||EA^each
            ORC|NW|1002
            RXE|^0|22222222222^Drug2^NDC|20||EA^each
            TQ1|1|1^QD|||||202609260900||ROUTINE
        """.trimIndent()

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals(2, groups.size)
        assertEquals("STAT", groups[0].tq1?.priorityRaw)
        assertEquals("ROUTINE", groups[1].tq1?.priorityRaw)
    }

    @Test
    fun orderGroupWithNoTq1SegmentHasNullTq1() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|NW|1001\r" +
            "RXE|^0|12345678901^Drug^NDC|10||EA^each"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertNull(groups[0].tq1)
    }

    @Test
    fun resolvedPriorityPrefersTq1OverOrcAndZpr() {
        val raw = """
            MSH|^~\&|A|B|C|D|20260101||RDE^O11|1|P|2.5
            ORC|NW|1001|||||1^BID^^^^ROUTINE
            TQ1|1|1^BID|||||||STAT
            ZPR|1|PRIORITY|Low
        """.trimIndent()

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals("STAT", groups[0].resolvedPriority)
    }

    @Test
    fun resolvedPriorityFallsBackToOrc7WhenNoTq1Present() {
        val raw = """
            MSH|^~\&|A|B|C|D|20260101||RDE^O11|1|P|2.5
            ORC|NW|1001|||||1^BID^^^^ROUTINE
            ZPR|1|PRIORITY|Low
        """.trimIndent()

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals("ROUTINE", groups[0].resolvedPriority)
    }

    @Test
    fun resolvedPriorityFallsBackToZprWhenNoTq1OrOrc7PriorityPresent() {
        val raw = """
            MSH|^~\&|A|B|C|D|20260101||RDE^O11|1|P|2.5
            ORC|NW|1001
            ZPR|1|PRIORITY|Low
        """.trimIndent()

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals("Low", groups[0].resolvedPriority)
    }

    @Test
    fun resolvedPriorityIsBlankWhenNoSourceHasAPriority() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|NW|1001"

        val groups = OrderGroupAssembler.assemble(typedSegmentsOf(raw))

        assertEquals("", groups[0].resolvedPriority)
    }
}
