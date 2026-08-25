package org.rite.hl7

import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.validation.AckSeverity
import org.rite.hl7.validation.HL7Validator
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class ValidationTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZADSegment.Definition)
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
    fun ackEchoesControlIdAndCode() {
        val msg = parse("MSH|^~\\&|App|Fac|R|H|20260101||RDS^O13|CTL-9|P|2.5")
        val ack = org.rite.hl7.validation.AckBuilder().build(msg, HL7Validator().validate(msg)).encode()
        assertTrue(ack.contains("MSA|AA|CTL-9"))
        // Sender/receiver swapped.
        assertTrue(ack.startsWith("MSH|^~\\&|R|H|App|Fac"))
    }

    @Test
    fun dispenseOrderWithValidOrcAndRxeIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun dispenseOrderMissingOrcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "RXE|^0|12345678901^Drug^NDC|||EA^each||||^1|10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing ORC segment" })
    }

    @Test
    fun dispenseOrderMissingRxeIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\rORC|NW")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing RXE segment" })
    }

    @Test
    fun dispenseOrderRxeMissingNdcAndQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW\r" +
                "RXE|^0||||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in RXE 1" })
        assertTrue(result.issues.any { it.errorText == "Missing quantity in RXE 1" })
    }

    @Test
    fun dispenseOrderWithZuiBypassesOrcRxeChecks() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ZUI|12345678901|Drug|Doe^Jane|1001|10|4853|1"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun dispenseOrderWithZniBypassesOrcRxeChecks() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O01|1|P|2.5\r" +
                "ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryCountRequestWithObxValuesIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "OBX|1|NM|12345678901^Drug^NDC||10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryCountRequestWithBlankObxValueIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "OBX|1|NM|12345678901^Drug^NDC||"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing value in OBX 1" })
    }

    @Test
    fun inventoryCountRequestFallsBackToRxeWhenNoObx() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "RXE|^0|12345678901^Drug^NDC|||EA^each||||^1|10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryCountRequestWithNoObxOrRxeIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing OBX/RXE segment for INR^U06" })
    }

    @Test
    fun inventoryAdjustmentWithZadIsUnaffectedByObxRxeRule() {
        // Already covered by knownAdjustmentReasonIsAccepted — ZAD-carrying
        // INR^U06 must not require OBX/RXE.
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun unsupportedMessageTypeIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||ADT^A01|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Unsupported message type ADT^A01" })
    }

    @Test
    fun blankControlIdIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDS^O13||P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing control ID (MSH-10)" })
    }

    @Test
    fun ackAlwaysEchoesControlIdEvenWhenBlank() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDS^O13||P|2.5")
        val ack = org.rite.hl7.validation.AckBuilder().build(msg, HL7Validator().validate(msg)).encode()
        assertTrue(ack.contains("MSA|AR|"))
    }

    @Test
    fun ackCarriesFirstFailureReasonInMsa3AndNoErrSegments() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\rORC|NW")
        val ack = org.rite.hl7.validation.AckBuilder().build(msg, HL7Validator().validate(msg)).encode()
        assertTrue(ack.contains("MSA|AR|1|Missing Rx number in ORC"))
        assertTrue(!ack.contains("ERR"))
    }

    @Test
    fun missingMessageTypeIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101|||1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing message type" })
    }

    @Test
    fun messageTypeWithoutTriggerIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid message type format" })
    }

    // --- MSH-9 accepted with either "^" (component separator) or a plain space ---

    @Test
    fun spaceSeparatedMessageTypeIsParsedSameAsCaretSeparated() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE O01|1|P|2.5")
        assertEquals("RDE", msg.messageCode)
        assertEquals("O01", msg.triggerEvent)
    }

    @Test
    fun spaceSeparatedDispenseOrderValidatesLikeCaretSeparated() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE O01|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun spaceSeparatedRdsIsParsedSameAsCaretSeparated() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDS O13|1|P|2.5")
        assertEquals("RDS", msg.messageCode)
        assertEquals("O13", msg.triggerEvent)
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun zuiWithMissingFieldsIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ZUI||Drug|Doe^Jane|1001||4853|1"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in ZUI" })
        assertTrue(result.issues.any { it.errorText == "Missing quantity in ZUI" })
    }

    @Test
    fun zuiFullyBlankIsMalformed() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\rZUI")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Malformed ZUI segment" })
    }

    @Test
    fun zniWithMissingFieldsIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O01|1|P|2.5\r" +
                "ZNI|B||123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE||Y|1024|4853|10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in ZNI" })
        assertTrue(result.issues.any { it.errorText == "Missing Rx number in ZNI" })
    }

    @Test
    fun orcUnsupportedControlCodeIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|ZZ|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Unsupported order control code: ZZ" })
    }

    @Test
    fun orcMissingPlacerOrderNumberIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing Rx number in ORC" })
    }

    @Test
    fun cancelOrderSkipsRxeRequirement() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|CA|1001"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun rxeInvalidNdcFormatIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|c^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in RXE 1" })
    }

    @Test
    fun rxeNonPositiveQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|0||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun rxeNonNumericQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|ABC||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun inventoryObxInvalidNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "OBX|1|NM|c^Drug^NDC||10"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in OBX 1" })
    }

    @Test
    fun inventoryObxNegativeValueIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "OBX|1|NM|12345678901^Drug^NDC||-5"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in OBX 1" })
    }

    // --- §3: quantity must be a bounded plain integer ---

    private fun rxeMsgWithQuantity(qty: String) = parse(
        "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
            "ORC|NW|1001\r" +
            "RXE|^0|12345678901^Drug^NDC|$qty||EA^each"
    )

    @Test
    fun rxeQuantityAboveMaxIsRejected() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("999999999999"))
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun rxeDecimalQuantityIsRoundedAndAccepted() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("5.5"))
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun rxeDecimalQuantityRoundingDownToZeroIsRejected() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("0.4"))
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun rxeDecimalQuantityRoundingUpToOneIsAccepted() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("0.5"))
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun rxeScientificNotationQuantityIsRejected() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("1e10"))
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun rxePlusPrefixedQuantityIsRejected() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("+10"))
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE 1" })
    }

    @Test
    fun rxeValidQuantityIsAccepted() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("30"))
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §2: VIVID ZUI NDC rejects malformed values ---

    @Test
    fun zuiInvalidNdcFormatIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ZUI|123-45|Drug|Doe^Jane|1001|10|4853|1"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in ZUI" })
    }

    @Test
    fun vividZuiNdcFuzzCasesAreRejected() {
        val fuzzValues = listOf(
            " 12345-6789-01 ",  // leading/trailing space
            "-----",            // only hyphens
            "12345-6789-01!@#", // special chars
            "１２３４５-６７８９-０１", // unicode digits
            "c",                // single char
            "ABCDE-1234-56",    // letters embedded
            "123456789012345",  // too long
            "123-45",           // too short
        )
        fuzzValues.forEach { ndc ->
            val msg = parse(
                "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                    "ZUI|$ndc|Drug|Doe^Jane|1001|10|4853|1"
            )
            val result = HL7Validator().validate(msg)
            assertEquals(AckSeverity.REJECT, result.worst, "expected AR for NDC '$ndc'")
            assertTrue(
                result.issues.any { it.errorText == "Invalid NDC in ZUI" },
                "expected 'Invalid NDC in ZUI' for '$ndc', got: ${result.issues.map { it.errorText }}",
            )
        }
    }

    @Test
    fun vividZuiEmptyNdcIsRejectedAsMissing() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ZUI||Drug|Doe^Jane|1001|10|4853|1"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in ZUI" })
    }

    @Test
    fun inventoryResponseEmptyNdcIsRejectedAsMissing() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
                "INV|1||||10|EA"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in INV 1" })
    }

    // --- §0: server's own ACK type must not be accepted inbound ---

    @Test
    fun ackMessageTypeIsRejectedAsUnsupported() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||ACK^R01|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Unsupported message type ACK^R01" })
    }

    // --- §1: Rx number is never format-checked, only required to be non-empty ---

    @Test
    fun orcRxNumberWithoutPrefixIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|12345\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §2: route (RXR) is never required, even when it's missing entirely ---

    @Test
    fun missingRxrIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun rxrWithUnrecognizedValueIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "RXR|GARBAGE_ROUTE"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §2: patient name is never required, even when it's missing entirely ---

    @Test
    fun missingPatientNameIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §6: order status is never validated ---

    @Test
    fun orcWithAnyOrderStatusIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001|||IP\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §5: ZPR priority allow-list is HIGH/ROUTINE, case-insensitive; absent is fine ---

    @Test
    fun zprInvalidPriorityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|SUPERFAST"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid priority: SUPERFAST" })
    }

    @Test
    fun zprEmptyValueIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid priority: " })
    }

    @Test
    fun zprLowercaseHighIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|high"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun zprRoutineIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|Routine"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun absentZprIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- §9: ZIN expected-on-hand must not be negative ---

    @Test
    fun zinNegativeQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "OBX|1|NM|12345678901^Drug^NDC||10\r" +
                "ZIN|1|EXPECTED_ON_HAND|-5"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in ZIN 1" })
    }

    // --- ZAD adjustment quantity must be a bounded plain integer ---

    @Test
    fun zadMissingQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS||DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing quantity in ZAD" })
    }

    @Test
    fun zadDecimalQuantityIsRoundedAndAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS|5.5|DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun zadInvalidQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
                "INV|1|123^x^NDC|||10|EA\r" +
                "ZAD|1|LOSS|ABC|DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in ZAD" })
    }

    // --- ORC-1 order control code is required, not just format-checked ---

    @Test
    fun orcBlankControlCodeIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC||1001\r" +
                "RXE|^0|12345678901^Drug^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Unsupported order control code: " })
    }

    // --- INR^U05 inventory count response (INV rows) ---

    @Test
    fun inventoryResponseMissingInvIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing INV segment" })
    }

    @Test
    fun inventoryResponseInvalidNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
                "INV|1|c^x^NDC|||10|EA"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in INV 1" })
    }

    @Test
    fun inventoryResponseNegativeQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
                "INV|1|12345678901^x^NDC|||-10|EA"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in INV 1" })
    }

    @Test
    fun inventoryResponseValidIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
                "INV|1|12345678901^x^NDC|||10|EA"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- INU^U05 inventory update (same INV/ZIN shape) ---

    @Test
    fun inventoryUpdateMissingInvIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing INV segment" })
    }

    @Test
    fun inventoryUpdateNegativeZinIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5\r" +
                "INV|1|12345678901^x^NDC|||10|EA\r" +
                "ZIN|1|OPENED|-3"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in ZIN 1" })
    }

    // --- RSP^K11 query response ---

    @Test
    fun queryResponseMissingQakIsRejected() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RSP^K11|1|P|2.5")
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing QAK segment" })
    }

    @Test
    fun queryResponseInvalidStatusIsRejected() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RSP^K11|1|P|2.5\r" +
                "QAK|TAG|MAYBE"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid query response status: MAYBE" })
    }

    @Test
    fun queryResponseValidStatusIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RSP^K11|1|P|2.5\r" +
                "QAK|TAG|OK"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

}
