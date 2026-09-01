package org.rite.hl7

import org.rite.hl7.model.HL7Message
import org.rite.hl7.model.HL7MessageKind
import org.rite.hl7.model.segment.EQUSegment
import org.rite.hl7.model.segment.INVSegment
import org.rite.hl7.model.segment.NTESegment
import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXDSegment
import org.rite.hl7.model.segment.ZADSegment
import org.rite.hl7.model.segment.ZSNSegment
import org.rite.hl7.parser.HL7ParseResult

/**
 * Example app-side usage of hl7Core for dispense (RDS^O13) and inventory
 * (INR^U06) workflows. One [HL7] facade instance is enough for a whole app —
 * it pre-registers the ZSN/ZSV/ZAD extension segments.
 */
class HL7Workflows(version: String = "2.5", private val hl7: HL7 = HL7(version = version)) {

    // ---------------------------------------------------------------
    // Dispense
    // ---------------------------------------------------------------

    data class DispensedPackage(
        val drugName: String,
        val ndc: String,
        val amountDispensed: String,
        val lotNumber: String,
        val expirationDate: String,
        val serialNumbers: List<String>,
    )

    /** Builds an RDS^O13 dispense message and returns the wire-format string. */
    fun buildDispenseMessage(
        controlId: String,
        placerOrderNumber: String,
        ndc: String,
        drugName: String,
        amount: String,
        lotNumber: String,
        expirationDate: String,
        packageSerialNumbers: List<String>,
    ): String {
        val message = hl7.build().rdsO13 {
            msh {
                it.sendingApplication = "PillCounter"
                it.sendingFacility = "PHARMACY"
                it.messageControlId = controlId
            }
            orc {
                it.orderControl = "RE"
                it.placerOrderNumber = placerOrderNumber
            }
            rxd {
                it.dispenseGiveCode = ndc
                it.dispenseGiveName = drugName
                it.actualDispenseAmount = amount
                it.lotNumber = lotNumber
                it.expirationDate = expirationDate
            }
            packageSerialNumbers.forEachIndexed { index, serial ->
                zsn {
                    it.setId = (index + 1).toString()
                    it.packageSerialNumber = serial
                    it.nationalDrugCode = ndc
                    it.lotNumber = lotNumber
                    it.expirationDate = expirationDate
                    it.transactionType = "D" // dispense
                }
            }
        }
        return message.encode()
    }

    /** Parses a raw RDS^O13 message and extracts everything the UI needs. */
    fun parseDispenseMessage(raw: String): Result<DispensedPackage> {
        return when (val result = hl7.parse(raw)) {
            is HL7ParseResult.Success -> {
                val msg = result.message
                if (msg.kind != HL7MessageKind.DISPENSE) {
                    return Result.failure(IllegalArgumentException("Not a dispense message: ${msg.kind}"))
                }
                val rxd = msg.segment<RXDSegment>("RXD")
                    ?: return Result.failure(IllegalStateException("Missing RXD segment"))
                val serials = msg.segments<ZSNSegment>("ZSN").map { it.packageSerialNumber }

                Result.success(
                    DispensedPackage(
                        drugName = rxd.dispenseGiveName,
                        ndc = rxd.dispenseGiveCode,
                        amountDispensed = rxd.actualDispenseAmount,
                        lotNumber = rxd.lotNumber,
                        expirationDate = rxd.expirationDate,
                        serialNumbers = serials,
                    )
                )
            }
            is HL7ParseResult.Failure -> Result.failure(
                IllegalArgumentException("Parse failed: ${result.errors.joinToString { it.message }}")
            )
        }
    }

    // ---------------------------------------------------------------
    // Inventory
    // ---------------------------------------------------------------

    data class InventoryAdjustment(
        val ndc: String,
        val substanceName: String,
        val onHandQuantity: String,
        val units: String,
        val adjustmentType: String,
        val adjustmentQuantity: String,
        val adjustmentReason: String,
    )

    /** Builds an INR^U06 inventory adjustment message. */
    fun buildInventoryAdjustmentMessage(
        controlId: String,
        ndc: String,
        substanceName: String,
        onHandQuantity: String,
        units: String,
        adjustmentType: String,
        adjustmentQuantity: String,
        adjustmentReason: String,
        approvedBy: String,
    ): String {
        val message = hl7.build().inrU06 {
            msh {
                it.sendingApplication = "PillCounter"
                it.sendingFacility = "PHARMACY"
                it.messageControlId = controlId
            }
            inv {
//                it.setId = "1"
                it.substanceCode = ndc
                it.substanceName = substanceName
                it.substanceCodeSystem = "NDC"
                it.inventoryOnHandQuantity = onHandQuantity
                it.units = units
            }
            zad {
                it.setId = "1"
                it.adjustmentType = adjustmentType
                it.adjustmentQuantity = adjustmentQuantity
                it.adjustmentReason = adjustmentReason
                it.approvedBy = approvedBy
            }
        }
        return message.encode()
    }

    /** Parses a raw INR^U05/INR^U06 message and extracts inventory + adjustment rows. */
    fun parseInventoryMessage(raw: String): Result<List<InventoryAdjustment>> {
        return when (val result = hl7.parse(raw)) {
            is HL7ParseResult.Success -> {
                val msg = result.message
                if (msg.kind != HL7MessageKind.INVENTORY_ADJUSTMENT &&
                    msg.kind != HL7MessageKind.INVENTORY_RESPONSE
                ) {
                    return Result.failure(IllegalArgumentException("Not an inventory message: ${msg.kind}"))
                }

                val invRows = msg.segments<INVSegment>("INV")
                val zadRows = msg.segments<ZADSegment>("ZAD")

                // INV and ZAD share position/setId ordering in this project's convention.
                val adjustments = invRows.mapIndexed { index, inv ->
                    val zad = zadRows.getOrNull(index)
                    InventoryAdjustment(
                        ndc = inv.substanceCode,
                        substanceName = inv.substanceName,
                        onHandQuantity = inv.inventoryOnHandQuantity,
                        units = inv.units,
                        adjustmentType = zad?.adjustmentType ?: "",
                        adjustmentQuantity = zad?.adjustmentQuantity ?: "",
                        adjustmentReason = zad?.adjustmentReason ?: "",
                    )
                }
                Result.success(adjustments)
            }
            is HL7ParseResult.Failure -> Result.failure(
                IllegalArgumentException("Parse failed: ${result.errors.joinToString { it.message }}")
            )
        }
    }

    data class InventoryRequestItem(
        val ndc: String,
        val name: String,
        val statusCode: String,
        val statusDesc: String,
        val typeCode: String,
        val typeDesc: String,
        val locationCode: String,
        val locationName: String,
    )

    data class InventoryRequest(
        val messageId: String,
        val timestamp: String,
        val robotId: String,
        val equipmentState: String,
        val items: List<InventoryRequestItem>,
        val notes: List<String>,
    )

    /**
     * Parses a raw INR^U06 inventory count request (no ZAD) — the strict
     * spec format in `plan/inventory/HL7_v2_5_1_INR_U06_Official_Specification.md`
     * (MSH+EQU+INV, INV fields 1-4 only) — into everything the app needs.
     */
    fun parseInventoryRequest(raw: String): Result<InventoryRequest> {
        return when (val result = hl7.parse(raw)) {
            is HL7ParseResult.Success -> {
                val msg = result.message
                if (msg.kind != HL7MessageKind.INVENTORY_REQUEST) {
                    return Result.failure(IllegalArgumentException("Not an inventory request message: ${msg.kind}"))
                }

                val equ = msg.segment<EQUSegment>(EQUSegment.NAME)
                    ?: return Result.failure(IllegalStateException("Missing EQU segment"))

                val items = msg.segments<INVSegment>(INVSegment.NAME).map { inv ->
                    InventoryRequestItem(
                        ndc = inv.deviceItemCode,
                        name = inv.deviceItemName,
                        statusCode = inv.deviceStatusCode,
                        statusDesc = inv.raw.componentValue(2, 2),
                        typeCode = inv.deviceTypeCode,
                        typeDesc = inv.raw.componentValue(3, 2),
                        locationCode = inv.deviceLocationCode,
                        locationName = inv.deviceLocationText,
                    )
                }

                val notes = msg.segments<NTESegment>(NTESegment.NAME).map { it.comment }

                Result.success(
                    InventoryRequest(
                        messageId = msg.messageControlId,
                        timestamp = msg.header?.dateTimeOfMessage ?: "",
                        robotId = equ.equipmentId,
                        equipmentState = equ.equipmentState,
                        items = items,
                        notes = notes,
                    )
                )
            }
            is HL7ParseResult.Failure -> Result.failure(
                IllegalArgumentException("Parse failed: ${result.errors.joinToString { it.message }}")
            )
        }
    }

    /** Validates a parsed message and returns the encoded ACK^R01 to send back. */
    fun acknowledge(message: HL7Message): String = hl7.ack(message)

    /** Order control / provider info shared by both flows, if the caller needs it. */
    fun orderInfo(message: HL7Message): ORCSegment? = message.segment("ORC")
}
