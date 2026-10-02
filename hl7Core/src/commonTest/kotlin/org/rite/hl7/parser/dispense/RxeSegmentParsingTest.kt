package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * RXE segment field parsing — NDC, quantity, units, prescription number,
 * substitution status, and component fields across HL7 versions.
 */
class RxeSegmentParsingTest {

    private fun parser() = HL7Parser.Builder().build()

    private fun parseRxe(rxeLine: String, version: String = "2.5"): RXESegment {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|$version\r" +
            "ORC|NW|RX-001\r$rxeLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed: ${(result as? HL7ParseResult.Failure)?.errors}")
        val rxe = result.message.segment<RXESegment>(RXESegment.NAME)
        assertNotNull(rxe)
        return rxe
    }

    @Test
    fun parsesGiveCodeNdcComponent() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug Name^NDC|10||EA^each")
        assertEquals("12345678901", rxe.giveCode)
        assertEquals("Drug Name", rxe.giveName)
        assertEquals("NDC", rxe.giveCodeSystem)
    }

    @Test
    fun parsesGiveAmountMinimum() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|30||TAB^Tablets")
        assertEquals("30", rxe.giveAmountMinimum)
    }

    @Test
    fun parsesGiveUnits() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each")
        assertEquals("EA", rxe.giveUnitsCode)
        assertEquals("each", rxe.giveUnitsText)
    }

    @Test
    fun parsesPrescriptionNumber() {
        // prescriptionNumber is RXE-15 (field 15), 14 pipes after "RXE"
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each||||||||||RX98765")
        assertEquals("RX98765", rxe.prescriptionNumber)
    }

    @Test
    fun parsesDispenseAmountField10() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each|||||60")
        assertEquals("60", rxe.dispenseAmount)
    }

    @Test
    fun parsesDispenseUnitsField11() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each|||||60|TAB^Tablets")
        assertEquals("TAB", rxe.dispenseUnitsCode)
        assertEquals("Tablets", rxe.dispenseUnitsText)
    }

    @Test
    fun parsesNumberOfRefills() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each|||||||3")
        assertEquals("3", rxe.numberOfRefills)
    }

    @Test
    fun parsesSubstitutionStatusRaw() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each||||N")
        assertEquals("N", rxe.substitutionStatusRaw)
    }

    @Test
    fun parsesOrderingProviderDeaNumber() {
        // orderingProviderDeaNumber is RXE-13.1 (field 13), 12 pipes after "RXE"
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each||||||||DEA-ABC123")
        assertEquals("DEA-ABC123", rxe.orderingProviderDeaNumber)
    }

    @Test
    fun parsesRxeFor231() {
        val rxe = parseRxe("RXE|^0|00093-0058-01^AMOX^NDC|90||TAB^Tablets", version = "2.3.1")
        assertEquals("00093-0058-01", rxe.giveCode)
        assertEquals("90", rxe.giveAmountMinimum)
    }

    @Test
    fun parsesRxeFor251() {
        val rxe = parseRxe("RXE|^0|00069015505^LISI^NDC|30||TAB^Tablets", version = "2.5.1")
        assertEquals("00069015505", rxe.giveCode)
    }

    @Test
    fun blankGiveCodeParsedAsEmpty() {
        val rxe = parseRxe("RXE|^0||10||EA^each")
        assertEquals("", rxe.giveCode)
    }

    @Test
    fun dosageFormFieldParsed() {
        val rxe = parseRxe("RXE|^0|12345678901^Drug^NDC|10||EA^each|TAB^Tablet")
        assertEquals("TAB", rxe.dosageFormCode)
        assertEquals("Tablet", rxe.dosageFormText)
    }
}
