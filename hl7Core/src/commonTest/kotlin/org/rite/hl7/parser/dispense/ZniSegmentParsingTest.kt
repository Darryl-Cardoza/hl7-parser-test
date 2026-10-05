package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.ZNISegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * ZNI segment parsing — Eyecon Native Interface order packet fields, component
 * access for patient name, all modes (B/I/C/Q), and version variants 2.3.1 / 2.5.1.
 */
class ZniSegmentParsingTest {
    private fun parser() = HL7Parser.Builder().build()

    private fun parseZni(
        zniLine: String,
        msgType: String = "RDE^O01",
        version: String = "2.3.1",
    ): ZNISegment {
        val raw = "MSH|^~\\&|eniClient||Eyecon||20060123090341||$msgType|1|P|$version\r$zniLine"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed")
        val zni = result.message.segment<ZNISegment>(ZNISegment.NAME)
        assertNotNull(zni)
        return zni
    }

    @Test
    fun parsesModeBuffered() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("B", zni.mode)
    }

    @Test
    fun parsesModeImmediate() {
        val zni = parseZni("ZNI|I|12345678901|123456789012|IBUPROFEN 200MG|A|MJONES|C|N|A0.1|SMITH^JOHN|RX5000|N|60|5000|1|")
        assertEquals("I", zni.mode)
    }

    @Test
    fun parsesModeQuery() {
        val zni = parseZni("ZNI|Q|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|DOE^JANE|RX1|Y|0|1|0|")
        assertEquals("Q", zni.mode)
    }

    @Test
    fun parsesNdc() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("12345678901", zni.ndc)
    }

    @Test
    fun parsesStockBottleBarcode() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("123456789012", zni.stockBottleBarcode)
    }

    @Test
    fun parsesDrugName() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|ACETAMINOPHEN 500MG|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("ACETAMINOPHEN 500MG", zni.drugName)
    }

    @Test
    fun parsesStockBottleVerification() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|A|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("A", zni.stockBottleVerification)
    }

    @Test
    fun parsesUserName() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|PHARM-USER|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("PHARM-USER", zni.userName)
    }

    @Test
    fun parsesCountType() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|C|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("C", zni.countType)
    }

    @Test
    fun parsesPacketVersion() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.2|JANE^DOE|RX4853|Y|1024|4853|10|")
        assertEquals("A0.2", zni.packetVersion)
    }

    @Test
    fun parsesPatientNameComponents() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|SMITH^JOHN|RX4853|Y|1024|4853|10|")
        assertEquals("SMITH", zni.patientFamilyName)
        assertEquals("JOHN", zni.patientGivenName)
    }

    @Test
    fun parsesFillerOrderNumber() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|JANE^DOE|RX99999|Y|1024|4853|10|")
        assertEquals("RX99999", zni.fillerOrderNumber)
    }

    @Test
    fun parsesSubstitutionStatus() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|N|1024|4853|10|")
        assertEquals("N", zni.substitutionStatus)
    }

    @Test
    fun parsesDispenseAmount() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|500|4853|10|")
        assertEquals("500", zni.dispenseAmount)
    }

    @Test
    fun parsesPrescriptionNumber() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|RX-99|10|")
        assertEquals("RX-99", zni.prescriptionNumber)
    }

    @Test
    fun parsesFillNumber() {
        val zni = parseZni("ZNI|B|12345678901|123456789012|DRUG|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|7|")
        assertEquals("7", zni.fillNumber)
    }

    @Test
    fun zniFor251MessageParses() {
        val zni =
            parseZni(
                "ZNI|I|22233344455|223334445566|IBUPROFEN 200MG|A|MJONES|C|N|A0.1|SMITH^JOHN|RX5000|N|60|5000|1|",
                msgType = "RDS^O13",
                version = "2.5.1",
            )
        assertEquals("22233344455", zni.ndc)
        assertEquals("IBUPROFEN 200MG", zni.drugName)
    }

    @Test
    fun messageWithoutZniReturnsNull() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||RDE^O11|1|P|2.5\rORC|NW|RX-1\rRXE|^0|12345678901^Drug^NDC|10||EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZNISegment>(ZNISegment.NAME))
    }
}
