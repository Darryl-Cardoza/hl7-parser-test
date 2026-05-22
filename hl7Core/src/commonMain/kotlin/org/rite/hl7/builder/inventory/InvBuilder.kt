package com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.inventory

import org.rite.hl7.domain.model.InventoryBinData
import org.rite.hl7.domain.model.InventoryResponseItem
import org.rite.hl7.domain.model.ZinData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent
import org.rite.hl7.hl7.domain.utils.HL7Constants

// ==================== INV SEGMENT BUILDER ====================
// Builds an INV segment for inventory count response (INR^U05).
//
// Field layout (matches expected wire format):
//   INV-1  : set ID (sequence index)
//   INV-2  : ndc^drugName
//   INV-3  : (empty)
//   INV-4  : (empty)
//   INV-5  : (empty)
//   INV-6  : (empty)
//   INV-7  : (empty)
//   INV-8  : (empty)
//   INV-9  : (empty)
//   INV-10 : (empty)
//   INV-11 : total quantity
//   INV-12 : (empty)
//   INV-13 : (empty)
//   INV-14 : (empty)
//   INV-15 : (empty)  ← last field for v2.1/2.2
//   INV-16 : lot number (v2.3+)
//   INV-17 : manufacturer (v2.3+)
//   INV-18 : supplier (v2.3+)
//   INV-19 : on-order qty (v2.5+)

fun buildINVResponseSegment(
    item: InventoryResponseItem,
    hl7Version: String = "2.5"
): String {
    val substanceId = buildComponent(item.ndc, item.drugName ?: "")

    val allFields = listOf(
        item.setId.toString(),    // INV-1
        substanceId,              // INV-2
        "",                       // INV-3
        "",                       // INV-4
        "",                       // INV-5
        "",                       // INV-6
        "",                       // INV-7
        "",                       // INV-8
        "",                       // INV-9
        "",                       // INV-10
        item.totalQuantity.toString(), // INV-11
        "",                       // INV-12
        "",                       // INV-13
        "",                       // INV-14
        ""                        // INV-15
        // INV-16..19 intentionally omitted — not used in count response
    )

    val maxField = InvVersionCapabilities.maxResponseField(hl7Version)
    val trimmed = allFields.take(maxField).dropLastWhile { it.isEmpty() }

    return buildString {
        append("INV")
        append(HL7Constants.FIELD_SEPARATOR)
        append(trimmed.joinToString(HL7Constants.FIELD_SEPARATOR))
        // Re-append trailing separators up to maxField so receivers can parse positionally
        val trailingEmpty = maxField - trimmed.size
        if (trailingEmpty > 0) {
            repeat(trailingEmpty) { append(HL7Constants.FIELD_SEPARATOR) }
        }
    }
}

// ==================== ZIN SEGMENT BUILDER ====================
// Builds a ZIN (custom Z-segment) for one dispense-type row under an INV.
//
// Format: ZIN|setId|dispenseType|quantity|lotNumber|expiry

fun buildZINSegment(setId: Int, row: ZinData): String {
    val fields = listOf(
        setId.toString(),
        row.dispenseType,
        row.quantity.toString(),
        row.lotNumber ?: "",
        row.expiry ?: ""
    ).dropLastWhile { it.isEmpty() }

    return buildString {
        append("ZIN")
        append(HL7Constants.FIELD_SEPARATOR)
        append(fields.joinToString(HL7Constants.FIELD_SEPARATOR))
        // keep trailing separators for lot/expiry positional parsing
        val trailingEmpty = 4 - fields.size  // 4 fields after setId
        if (trailingEmpty > 0) {
            repeat(trailingEmpty) { append(HL7Constants.FIELD_SEPARATOR) }
        }
    }
}


// ==================== LEGACY INV BUILDER ====================
// Kept intact — used by dispense/equipment paths. Do not remove.

fun buildINV(
    bin: InventoryBinData,
    hl7Version: String = "2.5"
): String {

    val substanceId = buildComponent(
        bin.substanceId,
        bin.substanceName ?: "",
        bin.substanceCodeSystem ?: ""
    )

    val quantityUnits = buildComponent(
        bin.quantityUnitCode ?: "",
        bin.quantityUnitText ?: ""
    )

    val allFields = listOf(
        substanceId,                 // INV-1
        bin.substanceStatus ?: "",   // INV-2
        "",                          // INV-3
        "",                          // INV-4
        bin.cellId ?: "",            // INV-5
        "",                          // INV-6
        "",                          // INV-7
        bin.quantityOnHand ?: "",    // INV-8
        bin.availableQuantity ?: "", // INV-9
        bin.cellLocation ?: "",      // INV-10
        quantityUnits,               // INV-11
        bin.expirationDate ?: "",    // INV-12
        "",                          // INV-13
        "",                          // INV-14
        "",                          // INV-15
        bin.lotNumber ?: "",         // INV-16
        bin.manufacturerName ?: "",  // INV-17
        bin.supplierName ?: "",      // INV-18
        bin.onOrderQuantity ?: ""    // INV-19
    )

    val maxField = InvVersionCapabilities.maxField(hl7Version)

    return HL7Utils.buildSegment(
        "INV",
        *allFields.take(maxField).toTypedArray()
    )
}


object InvVersionCapabilities {

    // Max field for legacy INV (equipment/dispense path)
    fun maxField(version: String): Int =
        when {
            version.startsWith("2.1") -> 11
            version.startsWith("2.2") -> 11
            version.startsWith("2.3") -> 12
            version.startsWith("2.4") -> 16
            else -> 19 // 2.5+
        }

    // Max field for inventory count response INV (INR^U05)
    // Only fields up to INV-15 are relevant; lot/manufacturer not sent in count response
    fun maxResponseField(version: String): Int =
        when {
            version.startsWith("2.1") -> 11
            version.startsWith("2.2") -> 11
            else -> 15 // 2.3+ — INV-11 is quantity, up to INV-15 covers standard count fields
        }
}
