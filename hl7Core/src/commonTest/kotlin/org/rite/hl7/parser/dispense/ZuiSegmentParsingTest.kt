package org.rite.hl7.parser.dispense

import org.rite.hl7.model.segment.ZUISegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

/**
 * ZUI segment parsing — both field map layouts (Order Data Packet for RDE^O11,
 * Pharmacy Dispense Message for RDS). Covers field-by-field reading,
 * component splits, blank fields, and invalid scenarios.
 */
class ZuiSegmentParsingTest {

    private fun parser() = HL7Parser.Builder().build()

    private fun msh(msgType: String, version: String) =
        "MSH|^~\\&|A|B|C|D|20260101||$msgType|1|P|$version"

    // --- Order Data Packet layout (RDE^O11) ---

    @Test
    fun parsesZuiOrderNdc() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|Doe^Jane|1001|10|4853|1"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zui = result.message.segment<ZUISegment>(ZUISegment.NAME)
        assertNotNull(zui)
        assertEquals("12345678901", zui.ndc)
    }

    @Test
    fun parsesZuiOrderDrugName() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|LISINOPRIL 10MG|Doe^Jane|1001|10|4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("LISINOPRIL 10MG", zui.orderDrugName)
    }

    @Test
    fun parsesZuiOrderPatientNameComponents() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|SMITH^JOHN|1001|10|4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("SMITH", zui.orderPatientFamilyName)
        assertEquals("JOHN", zui.orderPatientGivenName)
    }

    @Test
    fun parsesZuiOrderTransactionOrderId() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|Doe^Jane|RX-99999|10|4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("RX-99999", zui.orderTransactionOrderId)
    }

    @Test
    fun parsesZuiOrderDispenseQuantity() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|Doe^Jane|1001|45|4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("45", zui.orderDispenseQuantity)
    }

    @Test
    fun parsesZuiOrderRxNumber() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|Doe^Jane|1001|10|RX-4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("RX-4853", zui.orderRxNumber)
    }

    @Test
    fun parsesZuiOrderFillNumber() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI|12345678901|Drug|Doe^Jane|1001|10|4853|5"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("5", zui.orderFillNumber)
    }

    // --- Pharmacy Dispense Message layout (RDS) ---

    @Test
    fun parsesZuiDispenseVividUserName() {
        val raw = "${msh("RDS^O13", "2.5")}\r" +
            "ZUI|12345678901|JSMITH|TXN-1001|RX-4853|2|30|Done"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("JSMITH", zui.dispenseVividUserName)
    }

    @Test
    fun parsesZuiDispensedQuantity() {
        val raw = "${msh("RDS^O13", "2.5")}\r" +
            "ZUI|12345678901|JSMITH|TXN-1001|RX-4853|2|30|Done"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("30", zui.dispensedQuantity)
    }

    @Test
    fun parsesZuiTransactionStatus() {
        val raw = "${msh("RDS^O13", "2.5")}\r" +
            "ZUI|12345678901|JSMITH|TXN-1001|RX-4853|2|30|Done"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("Done", zui.transactionStatus)
    }

    @Test
    fun parsesZuiDispenseDrugLotNumber() {
        val raw = "${msh("RDS^O13", "2.5")}\r" +
            "ZUI|12345678901|JSMITH|TXN-1001|RX-4853|2|30|Done||LOT78321"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("LOT78321", zui.drugLotNumber)
    }

    @Test
    fun parsesZuiDispenseDrugExpiration() {
        val raw = "${msh("RDS^O13", "2.5")}\r" +
            "ZUI|12345678901|JSMITH|TXN-1001|RX-4853|2|30|Done|||SN123|271031"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("271031", zui.drugExpirationDate)
    }

    // --- Absent ZUI ---

    @Test
    fun messageWithoutZuiHasNullZui() {
        val raw = "${msh("RDE^O11", "2.5")}\rORC|NW|RX-1\rRXE|^0|12345678901^Drug^NDC|10||EA"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertNull(result.message.segment<ZUISegment>(ZUISegment.NAME))
    }

    // --- Blank/missing fields ---

    @Test
    fun blankNdcParsedAsEmpty() {
        val raw = "${msh("RDE^O11", "2.5")}\rZUI||Drug|Doe^Jane|1001|10|4853|1"
        val zui = (parser().parse(raw) as HL7ParseResult.Success).message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("", zui.ndc)
    }

    // --- Version variants ---

    @Test
    fun zuiParsedFor231() {
        val raw = "${msh("RDE^O01", "2.3.1")}\rZUI|00904201360|ASPIRIN|ALAM^DIAN|6085400|6.000|60854-00|00"
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        val zui = result.message.segment<ZUISegment>(ZUISegment.NAME)!!
        assertEquals("00904201360", zui.ndc)
        assertEquals("ASPIRIN", zui.orderDrugName)
    }
}
