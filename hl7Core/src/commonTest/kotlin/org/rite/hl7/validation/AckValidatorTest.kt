package org.rite.hl7.validation

import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertTrue

class AckValidatorTest {

    private val validator = HL7Validator()
    private fun parse(hl7: String) =
        (HL7Parser.Builder().build().parse(hl7.trimIndent()) as HL7ParseResult.Success).message

    @Test fun ackInboundRejected() {
        val msg = parse("""
            MSH|^~\&|LIB|FAC|PMS|FAC|20240101120000||ACK^R01|CTL001|P|2.5
            MSA|AA|CTL001
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT })
    }

    @Test fun inuU06InboundRejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INU^U06|CTL001|P|2.5
            EQU|EQ001|20240101
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT },
            "INU^U06 must be rejected; issues=${result.issues}")
    }
}
