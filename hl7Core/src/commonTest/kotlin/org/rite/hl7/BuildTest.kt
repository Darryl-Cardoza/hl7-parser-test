package org.rite.hl7

import org.rite.hl7.builder.HL7Builder
import org.rite.hl7.model.segment.ZSNSegment
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class BuildTest {
    private fun builder() =
        HL7Builder
            .builder()
            .defaultVersion("2.5")
            .fillTimestamps(false)
            .registerCustomSegment(ZSNSegment.Definition)
            .build()

    @Test
    fun buildsRdsO13WithZsn() {
        val message =
            builder().rdsO13 {
                msh {
                    it.sendingApplication = "PHARMACY-SYS"
                    it.sendingFacility = "MAIN-PHARM"
                    it.receivingApplication = "EHR"
                    it.receivingFacility = "HOSPITAL"
                    it.messageControlId = "MSG-1"
                    it.processingId = "P"
                }
                orc {
                    it.orderControl = "RE"
                    it.placerOrderNumber = "ORD-12345"
                    it.fillerOrderNumber = "RX-98765"
                    it.orderStatus = "CM"
                }
                rxd {
                    it.dispenseSubIdCounter = "1"
                    it.dispenseGiveCode = "00093-0058-01"
                    it.actualDispenseAmount = "90"
                }
                zsn {
                    it.setId = "1"
                    it.packageSerialNumber = "21N4F9XK0042"
                }
                zsn {
                    it.setId = "2"
                    it.packageSerialNumber = "21N4F9XK0099"
                }
            }

        val encoded = message.encode()
        assertTrue(encoded.startsWith("MSH|^~\\&|PHARMACY-SYS|MAIN-PHARM|EHR|HOSPITAL"))
        assertTrue(encoded.contains("|RDS^O13|MSG-1|P|2.5"))
        assertTrue(encoded.contains("\rORC|RE|ORD-12345|RX-98765||CM"))
        assertTrue(encoded.contains("\rRXD|1|00093-0058-01||90"), "RXD present: $encoded")
        assertTrue(encoded.contains("\rZSN|1|21N4F9XK0042"))
        assertTrue(encoded.contains("\rZSN|2|21N4F9XK0099"))
    }

    @Test
    fun buildThenParseRoundTrips() {
        val message =
            builder().inrU06 {
                msh {
                    it.sendingApplication = "WMS"
                    it.messageControlId = "MSG-002"
                }
                inv {
                    it.setId = "1"
                    it.substanceCode = "00069015505"
                    it.substanceName = "Drug Name"
                    it.substanceCodeSystem = "NDC"
                    it.inventoryOnHandQuantity = "150"
                    it.units = "EA"
                }
                zad {
                    it.setId = "1"
                    it.adjustmentType = "LOSS"
                    it.adjustmentQuantity = "5"
                    it.adjustmentReason = "DAMAGED_IN_TRANSIT"
                    it.approvedBy = "JOHN.DOE"
                }
            }
        val encoded = message.encode()

        val parser =
            org.rite.hl7.parser.HL7Parser
                .Builder()
                .registerCustomSegment(org.rite.hl7.model.segment.ZADSegment.Definition)
                .build()
        val result = parser.parse(encoded)
        assertTrue(result is org.rite.hl7.parser.HL7ParseResult.Success)
        val zad = result.message.segment<org.rite.hl7.model.segment.ZADSegment>("ZAD")
        assertEquals("LOSS", zad?.adjustmentType)
        assertEquals("DAMAGED_IN_TRANSIT", zad?.adjustmentReason)
    }
}
