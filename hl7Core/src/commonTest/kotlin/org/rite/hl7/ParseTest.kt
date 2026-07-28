package org.rite.hl7

import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.model.segment.MSHSegment
import org.rite.hl7.model.segment.RXDSegment
import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

class ParseTest {

    private fun parser() = HL7Parser.Builder()
        .defaultVersion("2.5")
        .registerCustomSegment(ZSNSegment.Definition)
        .registerCustomSegment(ZADSegment.Definition)
        .strictMode(false)
        .build()

    @Test
    fun parsesMshAndTypedFields() {
        val raw = "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|1782200001|P|2.5"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val msh = result.message.segment<MSHSegment>("MSH")
        assertNotNull(msh)
        assertEquals("PillCounter", msh.sendingApplication)
        assertEquals("RDS", msh.messageCode)
        assertEquals("O13", msh.triggerEvent)
        assertEquals("1782200001", msh.messageControlId)
        assertEquals("2.5", msh.versionId)
    }

    @Test
    fun parsesInvAndZadFromUserExample() {
        val raw = """
            MSH|^~\&|WMS|WAREHOUSE|EHR|HOSPITAL|20240615||INR^U06|MSG-002|P|2.5
            INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA
            ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE
        """.trimIndent()

        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val message = result.message

        val inv = message.segment<INVSegment>("INV")
        assertNotNull(inv)
        assertEquals("00069015505", inv.substanceCode)
        assertEquals("150", inv.inventoryOnHandQuantity)

        val zad = message.segment<ZADSegment>("ZAD")
        assertNotNull(zad)
        assertEquals("LOSS", zad.adjustmentType)
        assertEquals("5", zad.adjustmentQuantity)
        assertEquals("DAMAGED_IN_TRANSIT", zad.adjustmentReason)
        assertEquals("JOHN.DOE", zad.approvedBy)
    }

    @Test
    fun parsesRepeatingZsnRows() {
        val raw = """
            MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|1|P|2.5
            RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100842
            ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D
            ZSN|2|21N4F9XK0099|00093-0058-01|LOT78321|20271031|D
        """.trimIndent()

        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zsns = result.message.segments<ZSNSegment>("ZSN")
        assertEquals(2, zsns.size)
        assertEquals("21N4F9XK0042", zsns[0].packageSerialNumber)
        assertEquals("21N4F9XK0099", zsns[1].packageSerialNumber)

        val rxd = result.message.segment<RXDSegment>("RXD")
        assertNotNull(rxd)
        assertEquals("90", rxd.actualDispenseAmount)
        assertEquals("RX100842", rxd.prescriptionNumber)
    }

    @Test
    fun defaultsVersionTo25WhenMshMissingVersion() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||ACK^R01|1|P"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals("2.5", result.message.version.wire)
    }

    @Test
    fun nonMshFirstSegmentFails() {
        val result = parser().parse("PID|1||12345")
        assertTrue(result is HL7ParseResult.Failure)
        assertTrue(result.errors.isNotEmpty())
    }
}
