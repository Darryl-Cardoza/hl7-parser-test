package org.rite.hl7

import org.rite.hl7.encoding.HL7Delimiters
import org.rite.hl7.model.datatype.TQ
import org.rite.hl7.model.ast.HL7Field
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class TQTest {

    private fun tqOf(raw: String): TQ = TQ.parse(HL7Field.parse(raw, HL7Delimiters.DEFAULT))

    @Test
    fun standardV23OrderWithExplicitPriorityParsesAllComponents() {
        val tq = tqOf("1^BID^^202609250900^^STAT")

        assertEquals("1", tq.quantity)
        assertEquals("BID", tq.intervalCode)
        assertEquals("202609250900", tq.startDateTime)
        assertEquals("STAT", tq.priority)
    }

    @Test
    fun explicitClockTimesAreSplitFromIntervalSubcomponent() {
        val tq = tqOf("1^Q6H&0600,1200,1800,0000")

        assertEquals("Q6H", tq.intervalCode)
        assertEquals(listOf("0600", "1200", "1800", "0000"), tq.explicitTimes)
    }

    @Test
    fun sequencedOrderExtractsConjunctionAndOrderSequencing() {
        val tq = tqOf("1^BID^^^^ROUTINE^^^S^RX1001&2&PLACER")

        assertTrue(tq.isSequential)
        assertEquals("S", tq.conjunction)
        assertEquals("RX1001&2&PLACER", tq.orderSequencing)
    }

    @Test
    fun nonSequentialConjunctionIsNotSequential() {
        val tq = tqOf("1^BID^^^^ROUTINE^^^C")

        assertFalse(tq.isSequential)
    }

    @Test
    fun scheduleWithNoEndDateAndNoTotalOccurrencesIsOpenEnded() {
        val tq = tqOf("1^BID^^202609250900")

        assertTrue(tq.isOpenEnded)
    }

    @Test
    fun scheduleBoundedByEndDateIsNotOpenEnded() {
        val tq = tqOf("1^BID^^202609250900^202610010900")

        assertFalse(tq.isOpenEnded)
        assertEquals("202610010900", tq.endDateTime)
    }

    @Test
    fun scheduleBoundedByTotalOccurrencesIsNotOpenEnded() {
        val tq = tqOf("1^BID^^202609250900^^^^^^^^10")

        assertFalse(tq.isOpenEnded)
        assertEquals("10", tq.totalOccurrences)
    }

    @Test
    fun nonStandardIntervalTextFallsBackToRawWithoutThrowing() {
        val tq = tqOf("1^every other Tuesday afternoon")

        assertEquals("every other Tuesday afternoon", tq.interval)
        assertEquals("every other Tuesday afternoon", tq.intervalCode)
        assertTrue(tq.explicitTimes.isEmpty())
    }

    @Test
    fun missingFieldParsesToAllBlankComponents() {
        val tq = TQ.parse(HL7Field.EMPTY)

        assertEquals("", tq.quantity)
        assertEquals("", tq.interval)
        assertEquals("", tq.priority)
        assertTrue(tq.explicitTimes.isEmpty())
        assertTrue(tq.isOpenEnded)
    }
}
