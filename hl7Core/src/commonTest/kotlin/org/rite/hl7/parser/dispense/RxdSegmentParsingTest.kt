package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.RXDSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * RXD segment field parsing — NDC, quantity, lot, expiry, prescription number,
 * component fields, and optional fields across versions 2.3.1, 2.5, 2.5.1.
 */
class RxdSegmentParsingTest {
    private fun parser() = HL7Parser.Builder().build()

    private fun parseRxd(
        rxdLine: String,
        version: String = "2.5",
    ): RXDSegment {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDS^O13|1|P|$version\r$rxdLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed: ${(result as? HL7ParseResult.Failure)?.errors}")
        val rxd = result.message.segment<RXDSegment>(RXDSegment.NAME)
        assertNotNull(rxd)
        return rxd
    }

    @Test
    fun parsesDispenseSubIdCounter() {
        val rxd = parseRxd("RXD|3|00093-0058-01||90")
        assertEquals("3", rxd.dispenseSubIdCounter)
    }

    @Test
    fun parsesDispenseGiveCodeNdcComponent() {
        val rxd = parseRxd("RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC||90")
        assertEquals("00093-0058-01", rxd.dispenseGiveCode)
        assertEquals("AMOXICILLIN 500MG", rxd.dispenseGiveName)
        assertEquals("NDC", rxd.dispenseGiveCodeSystem)
    }

    @Test
    fun parsesActualDispenseAmount() {
        val rxd = parseRxd("RXD|1|00093-0058-01||60")
        assertEquals("60", rxd.actualDispenseAmount)
    }

    @Test
    fun parsesActualDispenseUnits() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90|TAB^Tablets")
        assertEquals("TAB", rxd.actualDispenseUnits)
        assertEquals("Tablets", rxd.actualDispenseUnitsText)
    }

    @Test
    fun parsesPrescriptionNumber() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90|TAB^Tablets|^|RX100842")
        assertEquals("RX100842", rxd.prescriptionNumber)
    }

    @Test
    fun parsesLotNumber() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90|TAB^Tablets|^|RX100842||||||||LOT78321")
        assertEquals("LOT78321", rxd.lotNumber)
    }

    @Test
    fun parsesExpirationDate() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90|TAB^Tablets|^|RX100842|||||||||20271031")
        assertEquals("20271031", rxd.expirationDate)
    }

    @Test
    fun parsesDateTimeDispensed() {
        val rxd = parseRxd("RXD|1|00093-0058-01|20260623091205|90")
        assertEquals("20260623091205", rxd.dateTimeDispensed)
    }

    @Test
    fun parsesSubstitutionStatusN() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90|TAB^Tablets|^|RX1||||N")
        assertEquals("N", rxd.substitutionStatusRaw)
    }

    @Test
    fun parsesDispensingProviderIdFromComponent() {
        // RXD-10 is the 10th pipe-delimited field (9 pipes after "RXD")
        val rxd = parseRxd("RXD|1|00093-0058-01||90||||||PHARM-USER")
        assertEquals("PHARM-USER", rxd.dispensingProviderId)
    }

    @Test
    fun blankActualAmountIsParsedAsEmpty() {
        val rxd = parseRxd("RXD|1|00093-0058-01|||TAB^Tablets")
        assertEquals("", rxd.actualDispenseAmount)
    }

    @Test
    fun parsesRxdFor231Version() {
        val rxd = parseRxd("RXD|1|00093-0058-01||90", version = "2.3.1")
        assertEquals("00093-0058-01", rxd.dispenseGiveCode)
        assertEquals("90", rxd.actualDispenseAmount)
    }

    @Test
    fun parsesRxdFor251Version() {
        val rxd = parseRxd("RXD|1|00069015505^LISINOPRIL 10MG^NDC||30", version = "2.5.1")
        assertEquals("00069015505", rxd.dispenseGiveCode)
        assertEquals("30", rxd.actualDispenseAmount)
    }

    @Test
    fun parsesRxdWithMinimalFields() {
        // Only NDC and amount — everything else blank
        val rxd = parseRxd("RXD||00093-0058-01||45")
        assertEquals("00093-0058-01", rxd.dispenseGiveCode)
        assertEquals("45", rxd.actualDispenseAmount)
    }

    @Test
    fun parsesPharmacyOrderType() {
        // pharmacyOrderType is at RXD-32; build a wire with 31 blank fields then the value
        val fields = Array(31) { "" }.toMutableList()
        fields[0] = "1"
        fields[1] = "00093-0058-01"
        fields[3] = "90"
        fields[31 - 1] = "" // pad
        val wire =
            "RXD|" +
                (0 until 31)
                    .map {
                        if (it == 0) {
                            "1"
                        } else if (it == 1) {
                            "00093-0058-01"
                        } else if (it == 3) {
                            "90"
                        } else {
                            ""
                        }
                    }.joinToString("|") +
                "|FILL"
        val rxd = parseRxd(wire)
        assertEquals("FILL", rxd.pharmacyOrderType)
    }
}
