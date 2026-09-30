package org.rite.hl7.validation

import org.rite.hl7.model.segment.ERRSegment
import org.rite.hl7.model.segment.MSASegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class AckBuilderErrTest {

    private val builder = AckBuilder()
    private val parser = HL7Parser.Builder().build()

    private fun parse(hl7: String) =
        (parser.parse(hl7.trimIndent()) as HL7ParseResult.Success).message

    private val minimalInbound = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL999|P|2.5
        PID|||P001||Smith^John
        ORC|NW|RX001
        RXE||00069015505^Drug^NDC|1||TAB
    """)

    @Test fun zero_issues_produces_zero_err_segments() {
        val result = ValidationResult(emptyList())
        val ack = builder.build(minimalInbound, result)
        val errSegments = ack.segments<ERRSegment>(ERRSegment.NAME)
        assertEquals(0, errSegments.size, "No ERR segments expected when result is clean")
    }

    @Test fun accept_severity_issues_produce_zero_err_segments() {
        val result = ValidationResult(listOf(
            ValidationIssue(AckSeverity.ACCEPT, "informational note")
        ))
        val ack = builder.build(minimalInbound, result)
        assertEquals(0, ack.segments<ERRSegment>(ERRSegment.NAME).size)
    }

    @Test fun one_reject_issue_produces_one_err_with_correct_fields() {
        val issue = ValidationIssue(
            severity = AckSeverity.REJECT,
            errorText = "Missing NDC in RXE",
            segmentId = "RXE",
            fieldPosition = "2",
            errorCode = "301"
        )
        val ack = builder.build(minimalInbound, ValidationResult(listOf(issue)))

        val errs = ack.segments<ERRSegment>(ERRSegment.NAME)
        assertEquals(1, errs.size)
        val err = errs[0]
        assertEquals("RXE", err.segmentId)
        assertEquals("2", err.fieldPosition)
        assertEquals("301", err.errorCode)
        assertEquals("Missing NDC in RXE", err.errorText)
        assertEquals("E", err.severity)
    }

    @Test fun two_issues_produce_two_err_segments_in_order() {
        val issues = listOf(
            ValidationIssue(AckSeverity.REJECT, "First error", "ORC", "1", "300"),
            ValidationIssue(AckSeverity.ERROR, "Second error", "RXE", "3", "301")
        )
        val ack = builder.build(minimalInbound, ValidationResult(issues))

        val errs = ack.segments<ERRSegment>(ERRSegment.NAME)
        assertEquals(2, errs.size)
        assertEquals("First error", errs[0].errorText)
        assertEquals("Second error", errs[1].errorText)
    }

    @Test fun msa_acknowledgment_code_reflects_worst_severity() {
        val issues = listOf(
            ValidationIssue(AckSeverity.ERROR, "non-fatal error", "RXE", "2", "301"),
            ValidationIssue(AckSeverity.REJECT, "fatal error", "MSH", "9", "103")
        )
        val ack = builder.build(minimalInbound, ValidationResult(issues))

        val msa = ack.segments<MSASegment>(MSASegment.NAME).firstOrNull()
        assertEquals("AR", msa?.acknowledgmentCodeRaw, "Worst severity REJECT should map to AR")
    }

    @Test fun msa_first_failure_error_text_appears_in_msa_3() {
        val issues = listOf(
            ValidationIssue(AckSeverity.REJECT, "first failure message", "ORC", "0", "300"),
            ValidationIssue(AckSeverity.REJECT, "second failure message", "RXE", "0", "300")
        )
        val ack = builder.build(minimalInbound, ValidationResult(issues))

        val msa = ack.segments<MSASegment>(MSASegment.NAME).firstOrNull()
        assertEquals("first failure message", msa?.textMessage)
    }

    @Test fun accept_only_produces_aa_and_no_err() {
        val result = ValidationResult.VALID
        val ack = builder.build(minimalInbound, result)

        val msa = ack.segments<MSASegment>(MSASegment.NAME).firstOrNull()
        assertEquals("AA", msa?.acknowledgmentCodeRaw)
        assertEquals(0, ack.segments<ERRSegment>(ERRSegment.NAME).size)
    }
}
