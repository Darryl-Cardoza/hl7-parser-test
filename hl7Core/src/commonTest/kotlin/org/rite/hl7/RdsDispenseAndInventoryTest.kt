package org.rite.hl7

import org.rite.hl7.builder.HL7Builder
import org.rite.hl7.builder.ZadReasonCode
import org.rite.hl7.builder.ZsvValidationResult
import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZNISegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.model.segment.ZSVSegment
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

/**
 * End-to-end coverage for building the RDS dispense response across HL7 versions,
 * with/without the custom ZSN/ZSV segments, the Eyecon ZNI variant, and the ZAD
 * inventory adjustment across versions.
 */
class RdsDispenseAndInventoryTest {

    private fun builder(version: String) = HL7Builder.builder()
        .defaultVersion(version)
        .fillTimestamps(false)
        .registerCustomSegment(ZSNSegment.Definition)
        .registerCustomSegment(ZSVSegment.Definition)
        .registerCustomSegment(ZADSegment.Definition)
        .build()

    private fun parser() = HL7Parser.Builder()
        .registerCustomSegment(ZSNSegment.Definition)
        .registerCustomSegment(ZSVSegment.Definition)
        .registerCustomSegment(ZADSegment.Definition)
        .build()

    private fun parseSuccess(raw: String): HL7ParseResult.Success {
        val result = parser().parse(raw)
        assertTrue(result is HL7ParseResult.Success, "parse failed for: $raw")
        return result
    }

    // ---------------------------------------------------------------
    // 1. Version-agnostic trigger event selection (2.3.1 vs 2.5.1)
    // ---------------------------------------------------------------

    @Test
    fun rdsUsesO01TriggerFor231() {
        val message = builder("2.3.1").rdsO13 {
            msh { it.sendingApplication = "PHARMACY-SYS"; it.messageControlId = "MSG-1"; it.processingId = "P" }
            orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-1" }
            rxd { it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O01|MSG-1|P|2.3.1"), encoded)
    }

    @Test
    fun rdsUsesO13TriggerFor251() {
        val message = builder("2.5.1").rdsO13 {
            msh { it.sendingApplication = "PHARMACY-SYS"; it.messageControlId = "MSG-2"; it.processingId = "P" }
            orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-2" }
            rxd { it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "60" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O13|MSG-2|P|2.5.1"), encoded)
    }

    @Test
    fun rdsUsesO13TriggerFor25Boundary() {
        // Exactly 2.5 must fall on the "from25" side (ordinal >= V25.ordinal).
        val message = builder("2.5").rdsO13 {
            msh { it.messageControlId = "MSG-3"; it.processingId = "P" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "30" }
        }
        assertTrue(message.encode().contains("|RDS^O13|MSG-3|P|2.5"))
    }

    @Test
    fun rdsMessageTypeOverridesPerCallVersionNotJustDefault() {
        // defaultVersion is 2.5.1, but the caller sets MSH-12 to 2.3.1 explicitly.
        val message = builder("2.5.1").rdsO13 {
            msh { it.versionId = "2.3.1"; it.messageControlId = "MSG-4"; it.processingId = "P" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "15" }
        }
        assertTrue(message.encode().contains("|RDS^O01|MSG-4|P|2.3.1"))
    }

    // ---------------------------------------------------------------
    // 2. Normal RDS response (no custom segments) per version
    // ---------------------------------------------------------------

    @Test
    fun normalRdsResponseBuildsFor231() {
        val message = builder("2.3.1").rdsO13 {
            msh {
                it.sendingApplication = "PHARMACY-SYS"; it.sendingFacility = "MAIN-PHARM"
                it.receivingApplication = "EHR"; it.receivingFacility = "HOSPITAL"
                it.messageControlId = "MSG-N231"; it.processingId = "P"
            }
            orc { it.orderControl = "RE"; it.placerOrderNumber = "ORD-1"; it.fillerOrderNumber = "RX-1"; it.orderStatus = "CM" }
            rxd {
                it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-01"
                it.actualDispenseAmount = "90"
            }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O01|MSG-N231|P|2.3.1"))
        assertTrue(encoded.contains("\rORC|RE|ORD-1|RX-1||CM"))
        assertTrue(encoded.contains("\rRXD|1|00093-0058-01||90"))
        assertTrue(!encoded.contains("\rZSN"))
        assertTrue(!encoded.contains("\rZSV"))
    }

    @Test
    fun normalRdsResponseBuildsFor251() {
        val message = builder("2.5.1").rdsO13 {
            msh { it.messageControlId = "MSG-N251"; it.processingId = "P" }
            orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-2"; it.orderStatus = "CM" }
            rxd { it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-02"; it.actualDispenseAmount = "45" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O13|MSG-N251|P|2.5.1"))
        assertTrue(encoded.contains("\rRXD|1|00093-0058-02||45"))
        assertTrue(!encoded.contains("\rZSN"))
        assertTrue(!encoded.contains("\rZSV"))
    }

    // ---------------------------------------------------------------
    // 2b. RDS with ZSN only, per version
    // ---------------------------------------------------------------

    @Test
    fun rdsWithZsnOnlyFor231() {
        val message = builder("2.3.1").rdsO13 {
            msh { it.messageControlId = "MSG-ZSN231"; it.processingId = "P" }
            rxd { it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0042"; it.transactionType = "D" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O01|MSG-ZSN231|P|2.3.1"))
        assertTrue(encoded.contains("\rZSN|1|21N4F9XK0042"))
        assertTrue(!encoded.contains("\rZSV"))

        val parsed = parseSuccess(encoded)
        val zsn = parsed.message.segment<ZSNSegment>(ZSNSegment.NAME)
        assertNotNull(zsn)
        assertEquals("D", zsn.transactionType)
    }

    @Test
    fun rdsWithZsnOnlyFor251() {
        val message = builder("2.5.1").rdsO13 {
            msh { it.messageControlId = "MSG-ZSN251"; it.processingId = "P" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0099"; it.transactionType = "D" }
            zsn { it.setId = "2"; it.packageSerialNumber = "21N4F9XK0100"; it.transactionType = "D" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O13|MSG-ZSN251|P|2.5.1"))
        assertTrue(encoded.contains("\rZSN|1|21N4F9XK0099"))
        assertTrue(encoded.contains("\rZSN|2|21N4F9XK0100"))
    }

    // ---------------------------------------------------------------
    // 2c. RDS with ZSV only, per version
    // ---------------------------------------------------------------

    @Test
    fun rdsWithZsvOnlyFor231() {
        val message = builder("2.3.1").rdsO13 {
            msh { it.messageControlId = "MSG-ZSV231"; it.processingId = "P" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsv {
                it.setId = "1"; it.dispensedNdc = "00093-0058-01"; it.scannedNdc = "00093-0058-01"
                it.validationResult = ZsvValidationResult.MATCH; it.scanSource = "GS1"; it.matchStrength = "EXACT"
            }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O01|MSG-ZSV231|P|2.3.1"))
        assertTrue(encoded.contains("\rZSV|1|00093-0058-01|00093-0058-01|MATCH|GS1"))
        assertTrue(!encoded.contains("\rZSN"))

        val parsed = parseSuccess(encoded)
        val zsv = parsed.message.segment<ZSVSegment>(ZSVSegment.NAME)
        assertNotNull(zsv)
        assertEquals(ZsvValidationResult.MATCH, zsv.validationResult)
        assertEquals("EXACT", zsv.matchStrength)
    }

    @Test
    fun rdsWithZsvOnlyFor251() {
        val message = builder("2.5.1").rdsO13 {
            msh { it.messageControlId = "MSG-ZSV251"; it.processingId = "P" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsv {
                it.setId = "1"; it.dispensedNdc = "00093-0058-01"; it.scannedNdc = "00093-0058-99"
                it.validationResult = ZsvValidationResult.MISMATCH; it.scanSource = "NDC_LINEAR"
            }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O13|MSG-ZSV251|P|2.5.1"))
        assertTrue(encoded.contains("\rZSV|1|00093-0058-01|00093-0058-99|MISMATCH|NDC_LINEAR"), encoded)

        val parsed = parseSuccess(encoded)
        val zsv = parsed.message.segment<ZSVSegment>(ZSVSegment.NAME)
        assertNotNull(zsv)
        assertEquals(ZsvValidationResult.MISMATCH, zsv.validationResult)
    }

    // ---------------------------------------------------------------
    // 2d. RDS with ZSN + ZSV together, per version
    // ---------------------------------------------------------------

    @Test
    fun rdsWithZsnAndZsvTogetherFor231() {
        val message = builder("2.3.1").rdsO13 {
            msh { it.messageControlId = "MSG-BOTH231"; it.processingId = "P" }
            orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-98765"; it.orderStatus = "CM" }
            rxd { it.dispenseSubIdCounter = "1"; it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0042"; it.transactionType = "D" }
            zsv { it.setId = "1"; it.dispensedNdc = "00093-0058-01"; it.scannedNdc = "00093-0058-01"; it.validationResult = ZsvValidationResult.MATCH; it.matchStrength = "EXACT" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O01|MSG-BOTH231|P|2.3.1"))
        assertTrue(encoded.contains("\rZSN|1|21N4F9XK0042"))
        assertTrue(encoded.contains("\rZSV|1|00093-0058-01|00093-0058-01|MATCH"))

        val parsed = parseSuccess(encoded)
        assertNotNull(parsed.message.segment<ZSNSegment>(ZSNSegment.NAME))
        assertNotNull(parsed.message.segment<ZSVSegment>(ZSVSegment.NAME))
    }

    @Test
    fun rdsWithZsnAndZsvTogetherFor251() {
        val message = builder("2.5.1").rdsO13 {
            msh { it.messageControlId = "MSG-BOTH251"; it.processingId = "P" }
            orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-98766"; it.orderStatus = "CM" }
            rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
            zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0043"; it.transactionType = "D" }
            zsv { it.setId = "1"; it.dispensedNdc = "00093-0058-01"; it.scannedNdc = "00093-0058-01"; it.validationResult = ZsvValidationResult.MATCH; it.matchStrength = "EXACT" }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|RDS^O13|MSG-BOTH251|P|2.5.1"))
        assertTrue(encoded.contains("\rZSN|1|21N4F9XK0043"))
        assertTrue(encoded.contains("\rZSV|1|00093-0058-01|00093-0058-01|MATCH"))
    }

    // ---------------------------------------------------------------
    // 3. Eyecon RDS response (ZNI segment) — parse-side, kept separate
    //    since ZNI currently has no HL7SegmentBuilder/scope method.
    // ---------------------------------------------------------------

    @Test
    fun eyeconRdsResponseParsesWithZniFor231() {
        val raw = "MSH|^~\\&|Eyecon||PHARMACY-SYS||20060123090341||RDS^O01|EYE-1|P|2.3.1\r" +
            "ORC|RE|ORD-1|RX-4853||CM\r" +
            "RXD|1|00093-0058-01||1024\r" +
            "ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|1024|4853|10|"

        val result = HL7Parser.Builder().build().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertTrue(result.message.encode().contains("|RDS^O01|EYE-1|P|2.3.1"))

        val zni = result.message.segment<ZNISegment>(ZNISegment.NAME)
        assertNotNull(zni)
        assertEquals("ACETAMINOPHEN", zni.drugName)
        assertEquals("1024", zni.dispenseAmount)
        assertEquals("4853", zni.prescriptionNumber)
    }

    @Test
    fun eyeconRdsResponseParsesWithZniFor251() {
        val raw = "MSH|^~\\&|Eyecon||PHARMACY-SYS||20060123090341||RDS^O13|EYE-2|P|2.5.1\r" +
            "ORC|RE|ORD-2|RX-5000||CM\r" +
            "RXD|1|00093-0058-02||60\r" +
            "ZNI|I|22233344455|223334445566|IBUPROFEN 200MG|A|MJONES|C|N|A0.1|SMITH^JOHN|RX5000|N|60|5000|1|"

        val result = HL7Parser.Builder().build().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertTrue(result.message.encode().contains("|RDS^O13|EYE-2|P|2.5.1"))

        val zni = result.message.segment<ZNISegment>(ZNISegment.NAME)
        assertNotNull(zni)
        assertEquals("IBUPROFEN 200MG", zni.drugName)
        assertEquals("SMITH", zni.patientFamilyName)
        assertEquals("JOHN", zni.patientGivenName)
        assertEquals("N", zni.substitutionStatus)
    }

    @Test
    fun eyeconRdsResponseIsIndependentOfZsnZsv() {
        // Eyecon (ZNI) messages must parse and encode correctly on their own,
        // without any ZSN/ZSV segments present, and vice versa.
        val raw = "MSH|^~\\&|Eyecon||PHARMACY-SYS||20060123090341||RDS^O01|EYE-3|P|2.3.1\r" +
            "RXD|1|00093-0058-01||30\r" +
            "ZNI|B|12345678901|123456789012|ACETAMINOPHEN|N|JSMITH|E|N|A0.1|JANE^DOE|RX4853|Y|30|4853|10|"
        val result = HL7Parser.Builder().build().parse(raw)
        assertTrue(result is HL7ParseResult.Success)
        assertEquals(null, result.message.segment<ZSNSegment>(ZSNSegment.NAME))
        assertEquals(null, result.message.segment<ZSVSegment>(ZSVSegment.NAME))
        assertNotNull(result.message.segment<ZNISegment>(ZNISegment.NAME))
    }

    // ---------------------------------------------------------------
    // 4. Inventory adjustment (ZAD) — normal + custom, per version
    // ---------------------------------------------------------------

    @Test
    fun inventoryAdjustmentBuildsWithZadFor231() {
        val message = builder("2.3.1").inrU06 {
            msh { it.sendingApplication = "WMS"; it.messageControlId = "MSG-INV231"; it.processingId = "P" }
            inv {
                it.setId = "1"; it.substanceCode = "00069015505"; it.substanceName = "Drug Name"
                it.substanceCodeSystem = "NDC"; it.inventoryOnHandQuantity = "150"; it.units = "EA"
            }
            zad {
                it.setId = "1"; it.adjustmentType = "+"; it.adjustmentQuantity = "5"
                it.adjustmentReason = ZadReasonCode.PO_RECEIPT; it.approvedBy = "JOHN.DOE"
            }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|INR^U06|MSG-INV231|P|2.3.1"))
        assertTrue(encoded.contains("\rZAD|1|+|5|PO_RECEIPT"))

        val parsed = parseSuccess(encoded)
        val zad = parsed.message.segment<ZADSegment>(ZADSegment.NAME)
        assertNotNull(zad)
        assertEquals(ZadReasonCode.PO_RECEIPT, zad.adjustmentReason)
    }

    @Test
    fun inventoryAdjustmentBuildsWithZadFor251() {
        val message = builder("2.5.1").inrU06 {
            msh { it.sendingApplication = "WMS"; it.messageControlId = "MSG-INV251"; it.processingId = "P" }
            inv {
                it.setId = "1"; it.substanceCode = "00069015505"; it.substanceName = "Drug Name"
                it.substanceCodeSystem = "NDC"; it.inventoryOnHandQuantity = "200"; it.units = "EA"
            }
            zad {
                it.setId = "1"; it.adjustmentType = "-"; it.adjustmentQuantity = "3"
                it.adjustmentReason = ZadReasonCode.BROKEN; it.approvedBy = "JANE.DOE"
            }
        }
        val encoded = message.encode()
        assertTrue(encoded.contains("|INR^U06|MSG-INV251|P|2.5.1"))
        assertTrue(encoded.contains("\rZAD|1|-|3|BROKEN"))
    }

    @Test
    fun inventoryAdjustmentWithMultipleZadRowsRoundTrips() {
        val message = builder("2.5").inrU06 {
            msh { it.sendingApplication = "WMS"; it.messageControlId = "MSG-INV-MULTI"; it.processingId = "P" }
            inv {
                it.setId = "1"; it.substanceCode = "00069015505"; it.substanceName = "Drug Name"
                it.substanceCodeSystem = "NDC"; it.inventoryOnHandQuantity = "150"; it.units = "EA"
            }
            zad { it.setId = "1"; it.adjustmentType = "+"; it.adjustmentQuantity = "10"; it.adjustmentReason = ZadReasonCode.TRANSFER_IN }
            zad { it.setId = "2"; it.adjustmentType = "O"; it.adjustmentQuantity = "150"; it.adjustmentReason = ZadReasonCode.PHYSICAL_INVENTORY }
        }
        val encoded = message.encode()
        val parsed = parseSuccess(encoded)
        assertEquals(encoded, parsed.message.encode())
        assertTrue(encoded.contains("\rZAD|1|+|10|TRANSFER_IN"))
        assertTrue(encoded.contains("\rZAD|2|O|150|PHYSICAL_INVENTORY"))
    }

    @Test
    fun inventoryWithoutZadBuildsNormallyPerVersion() {
        val message231 = builder("2.3.1").inrU06 {
            msh { it.sendingApplication = "WMS"; it.messageControlId = "MSG-NOZAD231"; it.processingId = "P" }
            inv {
                it.setId = "1"; it.substanceCode = "00069015505"; it.substanceName = "Drug Name"
                it.substanceCodeSystem = "NDC"; it.inventoryOnHandQuantity = "150"; it.units = "EA"
            }
        }
        val encoded231 = message231.encode()
        assertTrue(encoded231.contains("|INR^U06|MSG-NOZAD231|P|2.3.1"))
        assertTrue(!encoded231.contains("\rZAD"))

        val message251 = builder("2.5.1").inrU06 {
            msh { it.sendingApplication = "WMS"; it.messageControlId = "MSG-NOZAD251"; it.processingId = "P" }
            inv {
                it.setId = "1"; it.substanceCode = "00069015505"; it.substanceName = "Drug Name"
                it.substanceCodeSystem = "NDC"; it.inventoryOnHandQuantity = "150"; it.units = "EA"
            }
        }
        val encoded251 = message251.encode()
        assertTrue(encoded251.contains("|INR^U06|MSG-NOZAD251|P|2.5.1"))
        assertTrue(!encoded251.contains("\rZAD"))
    }
}
