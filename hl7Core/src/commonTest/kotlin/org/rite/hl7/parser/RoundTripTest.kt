package org.rite.hl7.parser

import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.model.segment.ZSVSegment
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

    @Test
    fun multiOrderDispenseWithZprRoundTrips() {
        roundTrips(
            "MSH|^~\\&|PMS|PHARMACY|PILLCOUNTER|ROBOT|20260925102510||RDE^O11|MSG10002|P|2.5\r" +
                "PID|1||PAT100232^^^PMS^MR||DOE^JOHN^A||19850101|M\r" +
                "ORC|NW|ORD789^EHR|RX456789^PHARM||IP\r" +
                "RXE|1^BID^^202609250900|00071015523^LISINOPRIL 10MG TAB^NDC|10||MG|TAB|||||30|TAB|5||RX456789|5|0\r" +
                "RXR|PO^ORAL\r" +
                "ZPR|1|PRIORITY|High\r" +
                "ORC|RF|ORD790^EHR|RX456790^PHARM||IP\r" +
                "RXE|1^QD^^202609250900|00093014701^AMLODIPINE 5MG TAB^NDC|5||MG|TAB|||||30|TAB|5||RX456790|3|2\r" +
                "RXR|PO^ORAL\r" +
                "ZPR|1|PRIORITY|Normal",
        )
    }

    @Test
    fun multiOrderDispenseParsesIntoCorrectOrderGroupsAfterRoundTrip() {
        val raw =
            "MSH|^~\\&|PMS|PHARMACY|PILLCOUNTER|ROBOT|20260925102510||RDE^O11|MSG10002|P|2.5\r" +
                "PID|1||PAT100232^^^PMS^MR||DOE^JOHN^A||19850101|M\r" +
                "ORC|NW|ORD789^EHR|RX456789^PHARM||IP\r" +
                "RXE|1^BID^^202609250900|00071015523^LISINOPRIL 10MG TAB^NDC|10||MG|TAB|||||30|TAB|5||RX456789|5|0\r" +
                "RXR|PO^ORAL\r" +
                "ZPR|1|PRIORITY|High\r" +
                "ORC|RF|ORD790^EHR|RX456790^PHARM||IP\r" +
                "RXE|1^QD^^202609250900|00093014701^AMLODIPINE 5MG TAB^NDC|5||MG|TAB|||||30|TAB|5||RX456790|3|2\r" +
                "RXR|PO^ORAL\r" +
                "ZPR|1|PRIORITY|Normal"

        val parsed = parser().parse(raw)
        assertTrue(parsed is HL7ParseResult.Success)
        val reparsed = parser().parse(parsed.message.encode())
        assertTrue(reparsed is HL7ParseResult.Success)

        assertEquals(2, reparsed.message.orderGroups.size)
        assertEquals(
            "ORD789",
            reparsed.message.orderGroups[0]
                .orc.placerOrderNumber,
        )
        assertEquals(
            "00071015523",
            reparsed.message.orderGroups[0]
                .rxe
                ?.giveCode,
        )
        assertEquals(
            "High",
            reparsed.message.orderGroups[0]
                .zpr[0]
                .priority,
        )
        assertEquals(
            "ORD790",
            reparsed.message.orderGroups[1]
                .orc.placerOrderNumber,
        )
        assertEquals(
            "00093014701",
            reparsed.message.orderGroups[1]
                .rxe
                ?.giveCode,
        )
        assertEquals(
            "Normal",
            reparsed.message.orderGroups[1]
                .zpr[0]
                .priority,
        )
    }
}
