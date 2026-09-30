package org.rite.hl7

import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.model.segment.ZSVSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class RoundTripTest {
    private fun parser() =
        HL7Parser
            .Builder()
            .registerCustomSegment(ZSNSegment.Definition)
            .registerCustomSegment(ZSVSegment.Definition)
            .registerCustomSegment(ZADSegment.Definition)
            .build()

    private fun roundTrips(raw: String) {
        val normalized = raw.replace("\r\n", "\r").replace("\n", "\r")
        val result = parser().parse(normalized)
        assertTrue(result is HL7ParseResult.Success, "parse failed for: $raw")
        assertEquals(normalized, result.message.encode())
    }

    @Test
    fun dispenseWithZsnRoundTrips() {
        roundTrips(
            "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|1782200001|P|2.5\r" +
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100842\r" +
                "ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D",
        )
    }

    @Test
    fun inventoryAdjustmentRoundTrips() {
        roundTrips(
            "MSH|^~\\&|WMS|WAREHOUSE|EHR|HOSPITAL|20240615||INR^U06|MSG-002|P|2.5\r" +
                "INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA\r" +
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE",
        )
    }

    @Test
    fun escapedDataRoundTrips() {
        // A field containing an escaped component separator must survive a round trip.
        roundTrips(
            "MSH|^~\\&|App|Fac|R|H|20260101||ACK^R01|1|P|2.5\r" +
                "NTE|1|L|value with \\S\\ caret and \\F\\ pipe",
        )
    }

    @Test
    fun unknownZSegmentRoundTripsLosslessly() {
        roundTrips(
            "MSH|^~\\&|App|Fac|R|H|20260101||ADT^A01|1|P|2.5\r" +
                "ZXY|1|a^b&c|d~e",
        )
    }

    @Test
    fun nonStandardDelimitersRoundTrip() {
        // field='|', component='#', repetition='@', escape='\', subcomponent='%'
        roundTrips(
            "MSH|#@\\%|App|Fac|R|H|20260101||ACK^R01|1|P|2.5\r" +
                "NTE|1|L|note#withcomponent",
        )
    }
}
