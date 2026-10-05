package org.rite.hl7.parser.inventory

import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.EQUSegment
import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.model.segment.OBXSegment
import org.rite.hl7.model.segment.ZADSegment
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
 * Full INU^U05 inventory update / cycle-count message parsing across versions.
 * Covers messageKind, device Parata payloads (INV+OBX), ZIN count rows,
 * ZCC extension, optional ZAD trailer, and invalid scenarios.
 */
class InuU05MessageParsingTest {
    private fun parser() =
        HL7Parser
            .Builder()
            .registerCustomSegment(ZADSegment.Definition)
            .registerCustomSegment(ZCCSegment.Definition)
            .build()

    // --- messageKind ---

    @Test
    fun inuU05IsInventoryUpdateKind() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5\r" +
                "INV|1|00069015505^Drug^NDC|||10|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(HL7MessageKind.INVENTORY_UPDATE, result.message.kind)
    }

    // --- Parata device cycle-count payload: INV + OBX rows ---

    @Test
    fun parataMessageParsesInvIdentifier() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "EQU|1|ROBOT1^Parata Max 2^MFG|PHARM^Main Pharmacy^L|DISP^Dispensing Robot^L|A|20251113191400\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val inv = result.message.segment<INVSegment>("INV")!!
        assertEquals("00904201361", inv.substanceIdentifier)
    }

    @Test
    fun parataMessageParsesInvQuantityOnHand() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("55", result.message.segment<INVSegment>("INV")!!.deviceQuantityOnHand)
    }

    @Test
    fun parataMessageParsesInvLotNumber() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("LOTLIS001", result.message.segment<INVSegment>("INV")!!.deviceLotNumber)
    }

    @Test
    fun parataMessageParsesObxValue() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val obx = result.message.segment<OBXSegment>("OBX")!!
        assertEquals("5", obx.observationValue)
        assertEquals("NDC001_SEALED", obx.observationId)
    }

    @Test
    fun parataMessageMultipleInvGroupsParsed() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||5\r" +
                "OBX|2|NM|NDC001_OPEN^Open||50\r" +
                "INV|00904201362^METFORMIN 500MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_B2^Cell B2^L|||7000|7000|7000|1|BOT^Bottles^UCUM|20260228|||LOTMET001\r" +
                "OBX|3|NM|NDC002_SEALED^Sealed||7000"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val invs = result.message.segments<INVSegment>("INV")
        assertEquals(2, invs.size)
        assertEquals("00904201361", invs[0].substanceIdentifier)
        assertEquals("00904201362", invs[1].substanceIdentifier)
        val obxs = result.message.segments<OBXSegment>("OBX")
        assertEquals(3, obxs.size)
    }

    // --- ZIN count rows ---

    @Test
    fun inuU05WithZinParsesDispenseType() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5\r" +
                "INV|1|12345678901^Drug^NDC|||10|EA\r" +
                "ZIN|1|OPENED|50|LOT-A|20271031"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zin = result.message.segment<ZINSegment>("ZIN")!!
        assertEquals("OPENED", zin.dispenseType)
        assertEquals("50", zin.quantity)
    }

    // --- ZCC extension ---

    @Test
    fun inuU05WithZccParsesNdcCode() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "ZCC|00069-3820-20|LISINOPRIL 10MG TABLET|TABLET|MERCK SHARP DOHME|MSD001|00069382020005|" +
                "CELL_A1|55|5|1|50|1|LOTLIS001|SN-2025-001-ABC|20260131|20231101|TAB^Tablets^UCUM|100|100|OK|" +
                "/images/sealed.jpg~/images/open.jpg|COMPLETE|Maria Garcia|All verified"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zcc = result.message.segment<ZCCSegment>(ZCCSegment.NAME)!!
        assertEquals("00069-3820-20", zcc.ndcCode)
        assertEquals(listOf("/images/sealed.jpg", "/images/open.jpg"), zcc.imagePaths)
    }

    // --- Optional ZAD trailer ---

    @Test
    fun inuU05CanCarryTrailingZad() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001\r" +
                "OBX|1|NM|NDC001_SEALED^Sealed||55\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20260101|JD"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNotNull(result.message.segment<ZADSegment>(ZADSegment.NAME))
    }

    @Test
    fun inuU05WithoutZadHasNullZad() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5\r" +
                "INV|1|12345678901^Drug^NDC|||10|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZADSegment>(ZADSegment.NAME))
    }

    // --- EQU ---

    @Test
    fun inuU05WithEquParsesId() {
        val raw =
            "MSH|^~\\&|PARATA|ROBOT1|PRIMERX|MAINPHARM|20251113191500||INU^U05|MSG00003|P|2.5.1\r" +
                "EQU|1|ROBOT1^Parata Max 2^MFG|PHARM^Main Pharmacy^L|DISP^Dispensing Robot^L|A|20251113191400\r" +
                "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val equ = result.message.segment<EQUSegment>("EQU")
        assertNotNull(equ)
    }

    // --- Version variants ---

    @Test
    fun inuU05For231ParsesCorrectly() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20060101||INU^U05|1|P|2.3.1\r" +
                "INV|1|00069015505^Drug^NDC|||100|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.3.1", result.message.version.wire)
        assertEquals(HL7MessageKind.INVENTORY_UPDATE, result.message.kind)
    }

    @Test
    fun inuU05For251ParsesCorrectly() {
        val raw =
            "MSH|^~\\&|A|B|C|D|20260101||INU^U05|1|P|2.5.1\r" +
                "INV|1|00069015505^Drug^NDC|||200|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5.1", result.message.version.wire)
    }

    // --- Invalid ---

    @Test
    fun emptyMessageFails() {
        assertTrue(parser().parse("") is HL7ParseResult.Failure)
    }
}
