package org.rite.hl7.parser

import org.rite.hl7.model.segment.ZNISegment
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

class ZNITest {
    @Test
    fun parsesEyeconMinimumValidOrderPacket() {
        val parser = HL7Parser.Builder().build()
        val raw =
            "MSH|^~\\&|eniClient||Eyecon||20060123090341||RDE^O01|012309034104|P|2.3.1||||||ASCII|EN^English\r" +
                "ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|"

        val result = parser.parse(raw)
        assertTrue(result is HL7ParseResult.Success)

        val zni = result.message.segment<ZNISegment>(ZNISegment.NAME)
        assertNotNull(zni)
        assertEquals("B", zni.mode)
        assertEquals("12345678901", zni.ndc)
        assertEquals("123456789012", zni.stockBottleBarcode)
        assertEquals("ACETAMINOPHEN", zni.drugName)
        assertEquals("N", zni.stockBottleVerification)
        assertEquals("JSMITH", zni.userName)
        assertEquals("E", zni.countType)
        assertEquals("A0.1", zni.packetVersion)
        assertEquals("JANE", zni.patientFamilyName)
        assertEquals("DOE", zni.patientGivenName)
        assertEquals("RX4853", zni.fillerOrderNumber)
        assertEquals("Y", zni.substitutionStatus)
        assertEquals("1024", zni.dispenseAmount)
        assertEquals("4853", zni.prescriptionNumber)
        assertEquals("10", zni.fillNumber)
    }

    @Test
    fun ordinaryMessagesAreUnaffectedByDefaultZNIRegistration() {
        val parser = HL7Parser.Builder().build()
        val raw = "MSH|^~\\&|A|B|C|D|20260101||ADT^A01|1|P|2.5\rPID|1||123"
        val result = parser.parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(null, result.message.segment<ZNISegment>(ZNISegment.NAME))
    }
}
