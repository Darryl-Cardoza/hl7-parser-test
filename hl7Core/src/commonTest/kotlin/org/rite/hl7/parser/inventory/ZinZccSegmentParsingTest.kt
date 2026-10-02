package org.rite.hl7.parser.inventory

import org.rite.hl7.model.segment.ZCCSegment
import org.rite.hl7.model.segment.ZINSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * ZIN (Inventory Count Row) and ZCC (Device Inventory Row with GS1) segment parsing.
 * ZIN: dispenseType, quantity, lot, expiry.
 * ZCC: all 24 fields including imagePaths repetition (~separator), operator, notes.
 */
class ZinZccSegmentParsingTest {

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZCCSegment.Definition)
        .build()

    private fun mshInu(version: String = "2.5") =
        "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|$version"

    // --- ZIN field-by-field ---

    @Test
    fun zinParsesSetId() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|2|OPENED|50|LOT-A|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("2", zin.setId)
    }

    @Test
    fun zinParsesDispenseTypeOpened() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|OPENED|50|LOT-A|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("OPENED", zin.dispenseType)
    }

    @Test
    fun zinParsesDispenseTypeSealed() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|SEALED|10|LOT-A|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("SEALED", zin.dispenseType)
    }

    @Test
    fun zinParsesQuantity() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|OPENED|77|LOT-A|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("77", zin.quantity)
    }

    @Test
    fun zinParsesLotNumber() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|OPENED|50|LOTXYZ|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("LOTXYZ", zin.lotNumber)
    }

    @Test
    fun zinParsesExpiry() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|OPENED|50|LOT-A|20280630"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("20280630", zin.expiry)
    }

    @Test
    fun messageWithoutZinReturnsNull() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA"
        assertNull((parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME))
    }

    @Test
    fun negativeZinQuantityStillParses() {
        // Parser reads it as-is; validation is separate layer
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA\rZIN|1|OPENED|-3|LOT-A|20271031"
        val zin = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZINSegment>(ZINSegment.NAME)!!
        assertEquals("-3", zin.quantity)
    }

    // --- ZCC field-by-field ---

    private fun zccLine(ndcCode: String = "00069-3820-20", qty: String = "55") =
        "ZCC|$ndcCode|LISINOPRIL 10MG TABLET|TABLET|MERCK SHARP DOHME|MSD001|00069382020005|" +
            "CELL_A1|$qty|5|1|50|1|LOTLIS001|SN-2025-001-ABC|20260131|20231101|TAB^Tablets^UCUM|100|100|OK|" +
            "/images/sealed.jpg~/images/open.jpg|COMPLETE|Maria Garcia|All verified"

    @Test
    fun zccParsesNdcCode() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("00069-3820-20", zcc.ndcCode)
    }

    @Test
    fun zccParsesDrugName() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("LISINOPRIL 10MG TABLET", zcc.drugName)
    }

    @Test
    fun zccParsesDrugType() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("TABLET", zcc.drugType)
    }

    @Test
    fun zccParsesManufacturer() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("MERCK SHARP DOHME", zcc.manufacturer)
        assertEquals("MSD001", zcc.manufacturerCode)
    }

    @Test
    fun zccParsesGtin() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("00069382020005", zcc.gtin)
    }

    @Test
    fun zccParsesCellLocation() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("CELL_A1", zcc.cellLocation)
    }

    @Test
    fun zccParsesTotalQuantity() {
        val raw = "${mshInu()}\r${zccLine(qty = "77")}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("77", zcc.totalQuantity)
    }

    @Test
    fun zccParsesSealedAndOpenCounts() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("5", zcc.sealedCount)
        assertEquals("1", zcc.sealedContainers)
        assertEquals("50", zcc.openCount)
        assertEquals("1", zcc.openContainers)
    }

    @Test
    fun zccParsesLotAndSerial() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("LOTLIS001", zcc.lotNumber)
        assertEquals("SN-2025-001-ABC", zcc.serialNumber)
    }

    @Test
    fun zccParsesDates() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("20260131", zcc.expirationDate)
        assertEquals("20231101", zcc.manufacturingDate)
    }

    @Test
    fun zccParsesUnitOfMeasureComponents() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("TAB", zcc.unitOfMeasureCode)
        assertEquals("Tablets", zcc.unitOfMeasureText)
        assertEquals("UCUM", zcc.unitOfMeasureCodeSystem)
    }

    @Test
    fun zccParsesPackageSizeAndReorderLevel() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("100", zcc.packageSize)
        assertEquals("100", zcc.reorderLevel)
    }

    @Test
    fun zccParsesStockStatus() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("OK", zcc.stockStatus)
    }

    @Test
    fun zccParsesImagePathsAsRepetitions() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals(listOf("/images/sealed.jpg", "/images/open.jpg"), zcc.imagePaths)
    }

    @Test
    fun zccParsesCountStatus() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("COMPLETE", zcc.countStatus)
    }

    @Test
    fun zccParsesOperatorName() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("Maria Garcia", zcc.operatorName)
    }

    @Test
    fun zccParsesNotes() {
        val raw = "${mshInu()}\r${zccLine()}"
        val zcc = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("All verified", zcc.notes)
    }

    @Test
    fun messageWithoutZccReturnsNull() {
        val raw = "${mshInu()}\rINV|1|00069015505^Drug^NDC|||10|EA"
        assertNull((parser().parse(raw) as HL7ParseResult.Success).message.segment<ZCCSegment>(ZCCSegment.NAME))
    }
}
