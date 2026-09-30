package org.rite.hl7

import org.rite.hl7.builder.HL7Builder
import org.rite.hl7.encoding.Mllp
import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

class MllpBatchTest {

    private fun parser() = HL7Parser.Builder()
        .defaultVersion("2.5")
        .strictMode(false)
        .build()

    private val msg1 = "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|1|P|2.5"
    private val msg2 = "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091206||RDS^O13|2|P|2.5"
    private val msg3 = "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091207||RDS^O13|3|P|2.5"

    @Test
    fun stripAllSplitsTwoConcatenatedMllpFrames() {
        val stream = Mllp.wrap(msg1) + Mllp.wrap(msg2)
        val frames = Mllp.stripAll(stream)
        assertEquals(2, frames.size)
        assertEquals(msg1, frames[0])
        assertEquals(msg2, frames[1])
    }

    @Test
    fun stripAllSplitsThreeConcatenatedMllpFrames() {
        val stream = Mllp.wrap(msg1) + Mllp.wrap(msg2) + Mllp.wrap(msg3)
        val frames = Mllp.stripAll(stream)
        assertEquals(3, frames.size)
        assertEquals(msg1, frames[0])
        assertEquals(msg2, frames[1])
        assertEquals(msg3, frames[2])
    }

    @Test
    fun stripAllReturnsSingleFrameForSingleMessage() {
        val stream = Mllp.wrap(msg1)
        val frames = Mllp.stripAll(stream)
        assertEquals(1, frames.size)
        assertEquals(msg1, frames[0])
    }

    @Test
    fun parseMllpBatchParsesEachMessageIndependently() {
        val stream = Mllp.wrap(msg1) + Mllp.wrap(msg2)
        val results = parser().parseMllpBatch(stream)

        assertEquals(2, results.size)
        assertTrue(results[0] is HL7ParseResult.Success)
        assertTrue(results[1] is HL7ParseResult.Success)

        val first = (results[0] as HL7ParseResult.Success).message.segment<MSHSegment>("MSH")
        val second = (results[1] as HL7ParseResult.Success).message.segment<MSHSegment>("MSH")
        assertNotNull(first)
        assertNotNull(second)
        assertEquals("1", first.messageControlId)
        assertEquals("2", second.messageControlId)
    }

    @Test
    fun parseMllpBatchIsolatesOneMalformedMessageFromOthers() {
        val badFrame = Mllp.wrap("PID|1||12345")
        val stream = Mllp.wrap(msg1) + badFrame + Mllp.wrap(msg2)
        val results = parser().parseMllpBatch(stream)

        assertEquals(3, results.size)
        assertTrue(results[0] is HL7ParseResult.Success)
        assertTrue(results[1] is HL7ParseResult.Failure)
        assertTrue(results[2] is HL7ParseResult.Success)
    }

    @Test
    fun singleParseRejectsUnexpectedMidStreamMsh() {
        val raw = "$msg1\r$msg2"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Failure)
        assertTrue(result.errors.isNotEmpty())
    }

    @Test
    fun rdeO25MultiOrcRoundTrip() {
        val builder = HL7Builder.builder().defaultVersion("2.5").build()
        val msg = builder.rdeO25 {
            msh { it.messageControlId = "O25MULTI001"; it.sendingApplication = "PMS" }
            order {
                orc { it.orderControl = "RF"; it.placerOrderNumber = "RX101" }
                rxe { it.giveCode = "00069015505"; it.giveAmountMinimum = "30" }
            }
            order {
                orc { it.orderControl = "RF"; it.placerOrderNumber = "RX102" }
                rxe { it.giveCode = "00093005801"; it.giveAmountMinimum = "60" }
            }
        }
        val encoded = msg.encode()
        val decoded = (parser().parse(encoded) as HL7ParseResult.Success).message

        assertEquals("O25", decoded.triggerEvent)
        assertEquals(2, decoded.orderGroups.size)
        assertEquals("RX101", decoded.orderGroups[0].orc.placerOrderNumber)
        assertEquals("RX102", decoded.orderGroups[1].orc.placerOrderNumber)
    }
}
