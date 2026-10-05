package org.rite.hl7.validation

import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertTrue

class InrU06ValidatorTest {
    private val validator = HL7Validator()
    private val parser = HL7Parser.Builder().build()

    private fun parse(hl7: String) = (parser.parse(hl7.trimIndent()) as HL7ParseResult.Success).message

    @Test fun happyPathInrU06() {
        val msg =
            parse(
                """
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            EQU|EQ001^Robot1^L|20240101120000|OP
            INV|00069015505^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """,
            )
        val result = validator.validate(msg)
        assertTrue(result.isValid, "INR^U06 with valid INV must pass; issues=${result.issues}")
    }

    @Test fun missingInvRejected() {
        val msg =
            parse(
                """
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            EQU|EQ001^Robot1^L|20240101120000|OP
        """,
            )
        val result = validator.validate(msg)
        assertTrue(
            result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" },
            "Missing INV must produce REJECT on INV segment; issues=${result.issues}",
        )
    }

    @Test fun invalidNdcInInvRejected() {
        val msg =
            parse(
                """
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|BADNDC^Bad Drug^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """,
            )
        val result = validator.validate(msg)
        assertTrue(
            result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" },
            "Invalid NDC must produce REJECT on INV segment; issues=${result.issues}",
        )
    }

    @Test fun missingStatusInInvRejected() {
        val msg =
            parse(
                """
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|00069015505^LISINOPRIL 10MG^L||DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """,
            )
        val result = validator.validate(msg)
        assertTrue(
            result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" },
            "Missing substance status must produce REJECT on INV segment; issues=${result.issues}",
        )
    }
}
