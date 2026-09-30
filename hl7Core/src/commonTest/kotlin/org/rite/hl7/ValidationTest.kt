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
        .registerCustomSegment(org.rite.hl7.model.segment.ZCCSegment.Definition)
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
        assertTrue(result.issues.any { it.errorText == "Missing NDC in RXE" })
        assertTrue(result.issues.any { it.errorText == "Missing quantity in RXE" })
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

    // --- INR^U06 inventory count REQUEST (no ZAD): strict spec format,
    // MSH+EQU+INV(fields 1-4), see plan/inventory/HL7_v2_5_1_INR_U06_Official_Specification.md

    @Test
    fun inventoryRequestValidMessageIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
                "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L\r" +
                "INV|00067-5680-34^METFORMIN 500MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_B2^Cell B2^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryRequestMissingEquIsAccepted() {
        // EQU is not required — the app doesn't consume it.
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryRequestEquMissingStateIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|\r" +
                "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun inventoryRequestMissingInvIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing INV segment for INR^U06" })
    }

    @Test
    fun inventoryRequestInvMissingNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
                "INV||A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in INV 1" })
    }

    @Test
    fun inventoryRequestInvInvalidNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
                "INV|c^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in INV 1" })
    }

    @Test
    fun inventoryRequestInvMissingStatusIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
                "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
                "INV|00069-3820-20^LISINOPRIL 10MG TAB^L||DRUG^Drug^HL70384|CELL_A1^Cell A1^L"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing status in INV 1" })
    }

    @Test
    fun inventoryAdjustmentWithZadIsUnaffectedByInventoryRequestRule() {
        // Already covered by knownAdjustmentReasonIsAccepted — ZAD-carrying
        // INR^U06 must not go through the plain-request EQU/INV checks.
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
    fun ackCarriesFirstFailureReasonInMsa3AndEmitsErrSegments() {
        val msg = parse("MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\rORC|NW")
        val ack = org.rite.hl7.validation.AckBuilder().build(msg, HL7Validator().validate(msg)).encode()
        assertTrue(ack.contains("MSA|AR|1|Missing Rx number in ORC"))
        assertTrue(ack.contains("ERR"), "ERR segment expected for each validation failure")
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

    // --- RDE^001 is a device-quirk alias for the standard RDE^O01 trigger ---

    @Test
    fun rde001TriggerIsAcceptedSameAsO01() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^001|1|P|2.5\r" +
                "ZUI|00904201360|ASPIRIN|ALAM^DIAN|6085400|6.000|60854-00|00"
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
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in RXE" })
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
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
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
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
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
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
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
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
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
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
    }

    @Test
    fun rxePlusPrefixedQuantityIsRejected() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("+10"))
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in RXE" })
    }

    @Test
    fun rxeValidQuantityIsAccepted() {
        val result = HL7Validator().validate(rxeMsgWithQuantity("30"))
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    // --- Multi-ORC order groups (RDE^O11 repeating { ORC + RXE + RXR + [ZPR] }) ---

    @Test
    fun secondRxeUnderSameOrcIsRejectedNotSilentlyDropped() {
        // Two RXE under one ORC: the first (bad NDC) would be silently
        // overwritten by orderGroups' single `rxe` slot, and validating only
        // the grouped view would miss it entirely. The message must still be
        // rejected instead of accepted on the strength of the second RXE.
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|c^Bad^NDC|10||EA^each\r" +
                "RXE|^0|11111111111^Good^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
    }

    @Test
    fun orphanRxeBeforeFirstOrcIsRejectedNotSilentlyDropped() {
        // An RXE before any ORC is intentionally excluded from orderGroups
        // (it can't belong to a group), but it must still be validated —
        // not silently accepted just because it isn't part of any group.
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "RXE|^0|c^Orphan^NDC|0||EA^each\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Good^NDC|10||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
    }

    @Test
    fun twoValidOrderGroupsAreBothAccepted() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun secondOrderMissingRxeIsRejectedWithCorrectPosition() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ORC|NW|1002"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing RXE segment (order 2)" })
        // Order 1 must not be flagged.
        assertTrue(result.issues.none { it.errorText.contains("order 1") })
    }

    @Test
    fun secondOrderBadNdcIsRejectedWhileFirstOrderIsClean() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|c^Drug2^NDC|20||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in RXE (order 2)" })
        assertTrue(result.issues.none { it.errorText.contains("order 1") })
    }

    @Test
    fun mixedCancelAndNewOrderValidatesEachIndependently() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|CA|1001\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun threeOrderGroupsAllValidatedNoHardcodedCountAssumption() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA^each\r" +
                "ORC|NW|1003\r" +
                "RXE|^0||30||EA^each"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Missing NDC in RXE (order 3)" })
    }

    @Test
    fun perOrderZprPriorityIsValidatedIndependently() {
        val msg = parse(
            "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\r" +
                "ORC|NW|1001\r" +
                "RXE|^0|11111111111^Drug1^NDC|10||EA^each\r" +
                "ZPR|1|PRIORITY|High\r" +
                "ORC|NW|1002\r" +
                "RXE|^0|22222222222^Drug2^NDC|20||EA^each\r" +
                "ZPR|1|PRIORITY|SUPERFAST"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid priority: SUPERFAST (order 2)" })
        assertTrue(result.issues.none { it.errorText.contains("order 1") })
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

    // --- INU^U05 device cycle-count payload (e.g. Parata robot) ---

    @Test
    fun parataDeviceInuU05MessageIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "EQU|1|ROBOT1^Parata Max 2^MFG|PHARM^Main Pharmacy^L|DISP^Dispensing Robot^L|A|20251113191400\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5\r" +
                "OBX|2|NM|NDC001_OPEN^Open||50\r" +
                "OBX|3|ST|NDC001_IMAGE^Image||/images/cycle_count_NDC001.jpg\r" +
                "INV|00904201362^METFORMIN 500MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_B2^Cell B2^L|||7000|7000|7000|1|BOT^Bottles^UCUM|20260228|||LOTMET001\r" +
                "OBX|4|NM|NDC002_SEALED^Sealed||7000\r" +
                "OBX|5|NM|NDC002_OPEN^Open||0\r" +
                "OBX|6|ST|NDC002_IMAGE^Image||/images/cycle_count_NDC002.jpg\r" +
                "INV|00904201363^ATORVASTATIN 20MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_C3^Cell C3^L|||30|30|30|1|TAB^Tablets^UCUM|20260315|||LOTATO001\r" +
                "OBX|7|NM|NDC003_SEALED^Sealed||0\r" +
                "OBX|8|NM|NDC003_OPEN^Open||30\r" +
                "OBX|9|ST|NDC003_IMAGE^Image||/images/cycle_count_NDC003.jpg\r" +
                "INV|00904201364^AMLODIPINE 5MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_D4^Cell D4^L|||0|0|0|1|TAB^Tablets^UCUM|20260430|||LOTAML001\r" +
                "OBX|10|NM|NDC004_SEALED^Sealed||0\r" +
                "OBX|11|NM|NDC004_OPEN^Open||0\r" +
                "INV|00904201365^OMEPRAZOLE 20MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_E5^Cell E5^L|||0|0|0|1|CAP^Capsules^UCUM|20260530|||LOTOME001\r" +
                "OBX|12|NM|NDC005_SEALED^Sealed||0\r" +
                "OBX|13|NM|NDC005_OPEN^Open||0"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun parataDeviceInvInvalidNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|c^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in INV 1" })
    }

    @Test
    fun parataDeviceObxNegativeValueIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||-5"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in OBX 1" })
    }

    @Test
    fun parataDeviceInuU05CanCarryTrailingZad() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||55\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
    }

    @Test
    fun deviceInvBuilderRoundTripsThroughParser() {
        val builder = org.rite.hl7.builder.HL7Builder.builder().build()
        val msg = builder.inuU05 {
            msh { it.messageControlId = "MSG00003" }
            equ { it.equipmentId = "ROBOT1" }
            invDevice {
                it.itemCode = "00904201361"; it.itemName = "LISINOPRIL 10MG"
                it.statusCode = "A"; it.statusText = "Active"
                it.typeCode = "DRUG"; it.typeText = "Drug"
                it.locationCode = "CELL_A1"; it.locationText = "Cell A1"
                it.quantityOnHand = "55"; it.quantityAvailable = "55"; it.quantityExpected = "55"
                it.packageSize = "1"
                it.unitsCode = "TAB"; it.unitsText = "Tablets"
                it.expirationDate = "20260131"
                it.lotNumber = "LOTLIS001"
            }
            obx { it.setId = "1"; it.valueType = "NM"; it.observationId = "NDC001_SEALED"; it.observationValue = "5" }
        }
        val reparsed = (parser().parse(msg.encode()) as org.rite.hl7.parser.HL7ParseResult.Success).message
        val result = HL7Validator().validate(reparsed)
        assertEquals(AckSeverity.ACCEPT, result.worst)
        val inv = reparsed.segment<org.rite.hl7.model.segment.INVSegment>(org.rite.hl7.model.segment.INVSegment.NAME)!!
        assertEquals("00904201361", inv.substanceIdentifier)
        assertEquals("55", inv.deviceQuantityOnHand)
        assertEquals("LOTLIS001", inv.deviceLotNumber)
    }

    // --- ZCC — 24-field device inventory row with GS1 (custom extension) ---

    @Test
    fun zinvMessageIsAccepted() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "ZCC|00069-3820-20|LISINOPRIL 10MG TABLET|TABLET|MERCK SHARP DOHME|MSD001|00069382020005|" +
                "CELL_A1|55|5|1|50|1|LOTLIS001|SN-2025-001-ABC|20260131|20231101|TAB^Tablets^UCUM|100|100|OK|" +
                "/images/sealed.jpg~/images/open.jpg|COMPLETE|Maria Garcia|All verified"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.ACCEPT, result.worst)
        val zcc = msg.segment<org.rite.hl7.model.segment.ZCCSegment>(org.rite.hl7.model.segment.ZCCSegment.NAME)!!
        assertEquals("00069-3820-20", zcc.ndcCode)
        assertEquals("TABLET", zcc.drugType)
        assertEquals("TAB", zcc.unitOfMeasureCode)
        assertEquals("Tablets", zcc.unitOfMeasureText)
        assertEquals(listOf("/images/sealed.jpg", "/images/open.jpg"), zcc.imagePaths)
        assertEquals("Maria Garcia", zcc.operatorName)
        assertEquals("All verified", zcc.notes)
    }

    @Test
    fun zinvInvalidNdcIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "ZCC|c|LISINOPRIL 10MG TABLET|TABLET|MERCK SHARP DOHME|MSD001|00069382020005|" +
                "CELL_A1|55|5|1|50|1|LOTLIS001|SN-2025-001-ABC|20260131|20231101|TAB^Tablets^UCUM|100|100|OK"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid NDC in ZCC 1" })
    }

    @Test
    fun zinvNegativeQuantityIsRejected() {
        val msg = parse(
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "ZCC|00069-3820-20|LISINOPRIL 10MG TABLET|TABLET|MERCK SHARP DOHME|MSD001|00069382020005|" +
                "CELL_A1|-55|5|1|50|1|LOTLIS001|SN-2025-001-ABC|20260131|20231101|TAB^Tablets^UCUM|100|100|OK"
        )
        val result = HL7Validator().validate(msg)
        assertEquals(AckSeverity.REJECT, result.worst)
        assertTrue(result.issues.any { it.errorText == "Invalid quantity in ZCC 1" })
    }

    @Test
    fun zinvBuilderRoundTripsThroughParser() {
        val builder = org.rite.hl7.builder.HL7Builder.builder()
            .registerCustomSegment(org.rite.hl7.model.segment.ZCCSegment.Definition)
            .build()
        val msg = builder.inuU05 {
            msh { it.messageControlId = "MSG00003" }
            zcc {
                it.ndcCode = "00069-3820-20"; it.drugName = "LISINOPRIL 10MG TABLET"
                it.drugType = "TABLET"
                it.manufacturer = "MERCK SHARP DOHME"; it.manufacturerCode = "MSD001"
                it.gtin = "00069382020005"; it.cellLocation = "CELL_A1"
                it.totalQuantity = "55"; it.sealedCount = "5"; it.sealedContainers = "1"
                it.openCount = "50"; it.openContainers = "1"
                it.lotNumber = "LOTLIS001"; it.serialNumber = "SN-2025-001-ABC"
                it.expirationDate = "20260131"; it.manufacturingDate = "20231101"
                it.unitOfMeasureCode = "TAB"; it.unitOfMeasureText = "Tablets"; it.unitOfMeasureCodeSystem = "UCUM"
                it.packageSize = "100"; it.reorderLevel = "100"; it.stockStatus = "OK"
                it.imagePaths = listOf("/images/sealed.jpg", "/images/open.jpg")
                it.countStatus = "COMPLETE"; it.operatorName = "Maria Garcia"; it.notes = "All verified"
            }
        }
        val reparsed = (parser().parse(msg.encode()) as org.rite.hl7.parser.HL7ParseResult.Success).message
        val result = HL7Validator().validate(reparsed)
        assertEquals(AckSeverity.ACCEPT, result.worst)
        val zcc = reparsed.segment<org.rite.hl7.model.segment.ZCCSegment>(org.rite.hl7.model.segment.ZCCSegment.NAME)!!
        assertEquals("00069-3820-20", zcc.ndcCode)
        assertEquals(listOf("/images/sealed.jpg", "/images/open.jpg"), zcc.imagePaths)
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
