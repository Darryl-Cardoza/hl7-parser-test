package org.rite.hl7.validation

import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertTrue

class RdeO25ValidatorTest {

    private val validator = HL7Validator()
    private fun parse(hl7: String) =
        (HL7Parser.Builder().build().parse(hl7.trimIndent()) as HL7ParseResult.Success).message

    private val validRdeO25 = """
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
        PID|1||MRN001|||DOE^JOHN
        ORC|RF|RX001
        RXE||00069015505^Lisinopril^NDC|30|60|TAB||||||N|30|TAB|3|RX001
        RXR|PO^Oral^HL70162
    """

    @Test fun happy_path_rde_o25() {
        val result = validator.validate(parse(validRdeO25))
        assertTrue(result.isValid, "RDE^O25 valid message must pass; issues=${result.issues}")
    }

    @Test fun missing_orc_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            PID|1||MRN001
            RXE||00069015505^Lisinopril^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "ORC" })
    }

    @Test fun invalid_ndc_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||BADNDC^Lisinopril^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "RXE" })
    }

    @Test fun invalid_qty_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||00069015505^Lisinopril^NDC|0|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "RXE" })
    }

    @Test fun multi_orc_all_validated() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||00069015505^Lisi^NDC|30|60|TAB
            ORC|RF|RX002
            RXE||BADNDC^Bad^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT })
    }
}
