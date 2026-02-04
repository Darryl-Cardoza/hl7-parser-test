package org.rite.hl7.builder.inventory

import org.rite.hl7.domain.model.InventoryBinData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

fun buildINV(bin: InventoryBinData): String {

    // INV-1: Substance Identifier (code ^ name ^ coding system)
    val substanceId = buildComponent(
        bin.substanceId,
        bin.substanceName ?: "",
        bin.substanceCodeSystem ?: ""
    )

    // INV-11: Quantity Units (code ^ text)
    val quantityUnits = buildComponent(
        bin.quantityUnitCode ?: "",
        bin.quantityUnitText ?: ""
    )

    /** Assemble INV segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "INV",  /** Segment ID **/

        /** INV-1: Substance identifier **/
        substanceId,

        /** INV-2: Substance status **/
        bin.substanceStatus ?: "",

        /** INV-3: Container status (not used) **/
        "",

        /** INV-4: Available status amount (not used) **/
        "",

        /** INV-5: Inventory cell ID **/
        bin.cellId,

        /** INV-6: Container dose amount (not used) **/
        "",

        /** INV-7: Available date (not used) **/
        "",

        /** INV-8: Quantity on hand **/
        bin.quantityOnHand ?: "",

        /** INV-9: Available quantity **/
        bin.availableQuantity ?: "",

        /** INV-10: Cell location **/
        bin.cellLocation ?: "",

        /** INV-11: Quantity units **/
        quantityUnits,

        /** INV-12: Expiration date **/
        bin.expirationDate ?: "",

        /** INV-13: Reorder level (not used) **/
        "",

        /** INV-14: Reorder amount (not used) **/
        "",

        /** INV-15: Distribute to (not used) **/
        "",

        /** INV-16: Lot number **/
        bin.lotNumber ?: "",

        /** INV-17: Manufacturer name **/
        bin.manufacturerName ?: "",

        /** INV-18: Supplier name **/
        bin.supplierName ?: "",

        /** INV-19: On-order quantity **/
        bin.onOrderQuantity ?: ""
    )
}
