package org.rite.hl7.parser

import org.rite.hl7.model.SegmentDefinition
import org.rite.hl7.model.TypedSegment
import org.rite.hl7.model.ast.HL7Segment
import org.rite.hl7.model.segment.GenericSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/** A user-defined typed segment registered without any core changes. */
class ZQQSegment(raw: HL7Segment) : TypedSegment(raw) {
    val widgetId: String get() = fieldValue(1)
    val widgetName: String get() = fieldValue(2)

    companion object {
        val Definition = SegmentDefinition("ZQQ") { ZQQSegment(it) }
    }
}

class PartialAndCustomTest {

    @Test
    fun customSegmentRegistersWithoutCoreChanges() {
        val parser = HL7Parser.Builder()
            .registerCustomSegment(ZQQSegment.Definition)
            .build()
        val raw = "MSH|^~\\&|A|B|C|D|20260101||ADT^A01|1|P|2.5\rZQQ|W-1|Widget"
        val result = parser.parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zqq = result.message.segment<ZQQSegment>("ZQQ")
        assertNotNull(zqq)
        assertEquals("W-1", zqq.widgetId)
        assertEquals("Widget", zqq.widgetName)
    }

    @Test
    fun unregisteredSegmentFallsBackToGeneric() {
        val parser = HL7Parser.Builder().build()
        val raw = "MSH|^~\\&|A|B|C|D|20260101||ADT^A01|1|P|2.5\rZZZ|x|y|z"
        val result = parser.parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val generic = result.message.segmentNamed("ZZZ") as? GenericSegment
        assertNotNull(generic)
        assertEquals("x", generic.value(1))
        assertEquals("z", generic.value(3))
    }

    @Test
    fun nonStrictModeReturnsPartialMessage() {
        // strictMode=false is the default; an all-good message still succeeds.
        val parser = HL7Parser.Builder().strictMode(false).build()
        val raw = "MSH|^~\\&|A|B|C|D|20260101||ADT^A01|1|P|2.5\rPID|1||123"
        val result = parser.parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(2, result.message.typedSegments.size)
    }

    @Test
    fun emptyMessageFails() {
        val result = HL7Parser.Builder().build().parse("")
        assertTrue(result is HL7ParseResult.Failure)
    }
}
