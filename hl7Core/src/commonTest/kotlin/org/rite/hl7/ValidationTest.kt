package org.rite.hl7

import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZSVSegment
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.validation.AckSeverity
import org.rite.hl7.validation.HL7Validator
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class ValidationTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZADSegment.Definition)
        .registerCustomSegment(ZSVSegment.Definition)
        .build()

    private fun parse(raw: String) =
        (parser().parse(raw) as org.rite.hl7.parser.HL7ParseResult.Success).message

    @Test
    fun unknownAdjustmentReasonIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS|5|TOTALLY_MADE_UP|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText.contains("Unknown adjustment reason") })
    }

    @Test
    fun knownAdjustmentReasonIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun unsupportedQueryIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||QBP^Q11|1|P|2.5\r" +
                "QPD|WrongQueryName|TAG|123^x^NDC"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Unsupported query" })
    }

    @Test
    fun rejectedValidationWithoutReasonIsError() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|1|P|2.5\r" +
                "ZSV|1|VR|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ERROR, result.worst)
    }

    @Test
    fun ackEchoesControlIdAndCode() {
        val msg = parse("MSH|^~\\&|App|Fac|R|H|20260101||RDS^O13|CTL-9|P|2.5")
        val ack = org.rite.hl7.validation.AckBuilder().build(msg, HL7Validator().validate(msg)).encode()
        assertTrue(ack.contains("MSA|AA|CTL-9"))
        // Sender/receiver swapped.
        assertTrue(ack.startsWith("MSH|^~\\&|R|H|App|Fac"))
    }
}
