package org.rite.hl7.parser.inventory

import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * INV segment field parsing — all three layout flavours:
 *   - Compact (WMS/PMS warehouse sync: leading setId at field 1)
 *   - Device Inventory Sync (Parata: no leading setId, NDC at field 1)
 *   - Count-Result (standard-first INU^U05 response: leading setId + rich INV-2 composite)
 *
 * Covers substance code/name/system, lot/expiry, quantity, and multi-row parsing
 * across HL7 versions 2.3.1, 2.5, 2.5.1.
 */
class InvSegmentParsingTest {

    private fun parser() = HL7Parser.Builder().build()

    private fun parseInv(invLine: String, msgType: String = "INR^U06", version: String = "2.5"): INVSegment {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||$msgType|1|P|$version\r$invLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed: ${(result as? HL7ParseResult.Failure)?.errors}")
        val inv = result.message.segment<INVSegment>(INVSegment.NAME)
        assertNotNull(inv)
        return inv
    }

    // --- Compact layout (warehouse/PMS sync) ---

    @Test
    fun compactLayoutParsesSetId() {
        val inv = parseInv("INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA")
        assertEquals("1", inv.setId)
    }

    @Test
    fun compactLayoutParsesSubstanceCode() {
        val inv = parseInv("INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA")
        assertEquals("00069015505", inv.substanceCode)
    }

    @Test
    fun compactLayoutParsesSubstanceName() {
        val inv = parseInv("INV|1|00069015505^LISINOPRIL 10MG^NDC|LOT-A|20251201|150|EA")
        assertEquals("LISINOPRIL 10MG", inv.substanceName)
    }

    @Test
    fun compactLayoutParsesSubstanceCodeSystem() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20251201|150|EA")
        assertEquals("NDC", inv.substanceCodeSystem)
    }

    @Test
    fun compactLayoutParsesLotNumber() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-XYZ|20251201|150|EA")
        assertEquals("LOT-XYZ", inv.lotNumber)
    }

    @Test
    fun compactLayoutParsesExpirationDate() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20271031|150|EA")
        assertEquals("20271031", inv.expirationDate)
    }

    @Test
    fun compactLayoutParsesOnHandQuantity() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20251201|200|EA")
        assertEquals("200", inv.inventoryOnHandQuantity)
    }

    @Test
    fun compactLayoutParsesUnits() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20251201|150|BOT")
        assertEquals("BOT", inv.units)
    }

    // --- Device Inventory Sync layout (Parata, no leading setId) ---

    @Test
    fun deviceLayoutParsesSubstanceIdentifier() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("00904201361", inv.substanceIdentifier)
    }

    @Test
    fun deviceLayoutParsesItemName() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("LISINOPRIL 10MG", inv.deviceItemName)
    }

    @Test
    fun deviceLayoutParsesQuantityOnHand() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("55", inv.deviceQuantityOnHand)
    }

    @Test
    fun deviceLayoutParsesExpirationDate() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("20260131", inv.deviceExpirationDate)
    }

    @Test
    fun deviceLayoutParsesLotNumber() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("LOTLIS001", inv.deviceLotNumber)
    }

    @Test
    fun deviceLayoutParsesLocationCode() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("CELL_A1", inv.deviceLocationCode)
        assertEquals("Cell A1", inv.deviceLocationText)
    }

    @Test
    fun deviceLayoutParsesUnitsCode() {
        val inv = parseInv(
            "INV|00904201361^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001",
            msgType = "INU^U05"
        )
        assertEquals("TAB", inv.deviceUnitsCode)
        assertEquals("Tablets", inv.deviceUnitsText)
    }

    // --- Count-Result layout (standard-first INU^U05, INR^U05) ---

    @Test
    fun countResultLayoutParsesSetId() {
        val inv = parseInv(
            "INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123",
            msgType = "INR^U05"
        )
        assertEquals("1", inv.countSetId)
    }

    @Test
    fun countResultLayoutParsesItemCode() {
        val inv = parseInv(
            "INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123",
            msgType = "INR^U05"
        )
        assertEquals("00009-5134-03", inv.countItemCode)
    }

    @Test
    fun countResultLayoutParsesSerialNumber() {
        val inv = parseInv(
            "INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123",
            msgType = "INR^U05"
        )
        assertEquals("SERIAL001", inv.countSerialNumber)
    }

    @Test
    fun countResultLayoutParsesGtin() {
        val inv = parseInv(
            "INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123",
            msgType = "INR^U05"
        )
        assertEquals("00300095134032", inv.countGtin)
    }

    @Test
    fun countResultLayoutParsesLotNumber() {
        // countLotNumber = fieldValue(15). Wire: f1=1, f2=item, f3=status, f4=type,
        // f5=empty, f6=empty, f7=qty-on-hand, f8=qty-avail, f9=qty-exp, f10=units,
        // f11=expiry (skipping f10=packageSize in spec), f12-f13=empty, f14=empty, f15=lot
        // Use 3 separators between f4 and f7 so qty is at the right field index.
        val inv = parseInv(
            "INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384|||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123",
            msgType = "INR^U05"
        )
        assertEquals("ABC123", inv.countLotNumber)
    }

    // --- Multi-row INV ---

    @Test
    fun multipleInvRowsAllParsed() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U06|1|P|2.5\r" +
            "INV|1|00069015505^Drug1^NDC|LOT-1|20271031|100|EA\r" +
            "INV|2|00093-0058-01^Drug2^NDC|LOT-2|20271031|50|EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val invs = result.message.segments<INVSegment>("INV")
        assertEquals(2, invs.size)
        assertEquals("00069015505", invs[0].substanceCode)
        assertEquals("00093-0058-01", invs[1].substanceCode)
    }

    // --- Version variants ---

    @Test
    fun invParsedFor231() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20251201|150|EA", version = "2.3.1")
        assertEquals("00069015505", inv.substanceCode)
    }

    @Test
    fun invParsedFor251() {
        val inv = parseInv("INV|1|00069015505^Drug^NDC|LOT-A|20251201|150|EA", version = "2.5.1")
        assertEquals("150", inv.inventoryOnHandQuantity)
    }
}
