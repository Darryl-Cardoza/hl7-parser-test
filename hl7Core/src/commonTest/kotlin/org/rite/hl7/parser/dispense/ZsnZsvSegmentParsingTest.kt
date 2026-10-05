package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.model.segment.ZSVSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * ZSN (Serial Number Capture) and ZSV (Stock-bottle Validation) segment parsing.
 * Covers all named fields, multi-row ZSN, component access, missing segments,
 * and both HL7 versions 2.3.1 and 2.5.1.
 */
class ZsnZsvSegmentParsingTest {
    private fun parser() =
        HL7Parser
            .Builder()
            .registerCustomSegment(ZSNSegment.Definition)
            .registerCustomSegment(ZSVSegment.Definition)
            .build()

    private fun mshRds(version: String) = "MSH|^~\\&|A|B|C|D|20260101||${if (version < "2.5") "RDS^O01" else "RDS^O13"}|1|P|$version"

    // --- ZSN field-by-field ---

    @Test
    fun parsesZsnSetId() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|3|SN-001|00093-0058-01|LOT1|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("3", zsn.setId)
    }

    @Test
    fun parsesZsnPackageSerialNumber() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("21N4F9XK0042", zsn.packageSerialNumber)
    }

    @Test
    fun parsesZsnNationalDrugCode() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT1|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("00093-0058-01", zsn.nationalDrugCode)
    }

    @Test
    fun parsesZsnLotNumber() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT78321|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("LOT78321", zsn.lotNumber)
    }

    @Test
    fun parsesZsnExpirationDate() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT1|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("20271031", zsn.expirationDate)
    }

    @Test
    fun parsesZsnTransactionTypeDispense() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT1|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("D", zsn.transactionType)
    }

    @Test
    fun parsesZsnTransactionTypeReturn() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT1|20271031|R"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("R", zsn.transactionType)
    }

    @Test
    fun parsesZsnQuantityAndCaptureSource() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-001|00093-0058-01|LOT1|20271031|D|1|GS1|20260623120000"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("1", zsn.quantityFromThisStockItem)
        assertEquals("GS1", zsn.captureSource)
        assertEquals("20260623120000", zsn.captureTimestamp)
    }

    // --- Multi-row ZSN ---

    @Test
    fun multipleZsnRowsAllParsed() {
        val raw =
            "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\r" +
                "ZSN|1|21N4F9XK0042|00093-0058-01|LOT1|20271031|D\r" +
                "ZSN|2|21N4F9XK0099|00093-0058-01|LOT1|20271031|D\r" +
                "ZSN|3|21N4F9XK0100|00093-0058-01|LOT1|20271031|D"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zsns = result.message.segments<ZSNSegment>("ZSN")
        assertEquals(3, zsns.size)
        assertEquals("21N4F9XK0042", zsns[0].packageSerialNumber)
        assertEquals("21N4F9XK0099", zsns[1].packageSerialNumber)
        assertEquals("21N4F9XK0100", zsns[2].packageSerialNumber)
    }

    @Test
    fun zsnFor231Parses() {
        val raw = "${mshRds("2.3.1")}\rRXD|1|00093-0058-01||90\rZSN|1|SN-XYZ|00093-0058-01|LOT1|20271031|D"
        val zsn = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME)!!
        assertEquals("SN-XYZ", zsn.packageSerialNumber)
    }

    @Test
    fun messageWithoutZsnReturnsNull() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90"
        assertTrue(parser().parse(raw) is HL7ParseResult.Success)
        assertNull((parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSNSegment>(ZSNSegment.NAME))
    }

    // --- ZSV field-by-field ---

    @Test
    fun parsesZsvSetId() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|2|00093-0058-01|00093-0058-01|MATCH|GS1||20260101|EXACT"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("2", zsv.setId)
    }

    @Test
    fun parsesZsvDispensedNdc() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-99|MISMATCH|NDC_LINEAR"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("00093-0058-01", zsv.dispensedNdc)
    }

    @Test
    fun parsesZsvScannedNdc() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-99|MISMATCH|NDC_LINEAR"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("00093-0058-99", zsv.scannedNdc)
    }

    @Test
    fun parsesZsvValidationResultMatch() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1||20260101|EXACT"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("MATCH", zsv.validationResult)
    }

    @Test
    fun parsesZsvValidationResultMismatch() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-99|MISMATCH|NDC_LINEAR"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("MISMATCH", zsv.validationResult)
    }

    @Test
    fun parsesZsvScanSource() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("GS1", zsv.scanSource)
    }

    @Test
    fun parsesZsvMatchStrength() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1||20260101|NDC10"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("NDC10", zsv.matchStrength)
    }

    @Test
    fun parsesZsvValidationTimestamp() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\rZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1|JPHARM|20260623120000|EXACT"
        val zsv = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME)!!
        assertEquals("20260623120000", zsv.validationTimestamp)
        assertEquals("JPHARM", zsv.validator)
    }

    @Test
    fun messageWithoutZsvReturnsNull() {
        val raw = "${mshRds("2.5")}\rRXD|1|00093-0058-01||90"
        assertNull((parser().parse(raw) as HL7ParseResult.Success).message.segment<ZSVSegment>(ZSVSegment.NAME))
    }

    @Test
    fun zsnAndZsvBothPresentAreIndependentlyParsed() {
        val raw =
            "${mshRds("2.5")}\rRXD|1|00093-0058-01||90\r" +
                "ZSN|1|SN-001|00093-0058-01|LOT1|20271031|D\r" +
                "ZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1||20260101|EXACT"
        val msg = (parser().parse(raw) as HL7ParseResult.Success).message
        assertNotNull(msg.segment<ZSNSegment>(ZSNSegment.NAME))
        assertNotNull(msg.segment<ZSVSegment>(ZSVSegment.NAME))
    }
}
