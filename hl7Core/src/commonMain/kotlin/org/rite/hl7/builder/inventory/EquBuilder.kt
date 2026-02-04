package org.rite.hl7.builder.inventory

import org.rite.hl7.domain.model.InventoryData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

fun buildEQU(inventory: InventoryData): String {

    // EQU-1: Equipment Instance Identifier (ID ^ namespace ^ type)
    val equipmentId = buildComponent(
        inventory.equipmentId,
        inventory.equipmentIdNamespace ?: "",
        inventory.equipmentType ?: ""
    )

    /** Assemble EQU segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "EQU",  /** Segment ID **/

        /** EQU-1: Equipment instance identifier **/
        equipmentId,

        /** EQU-2: Event date/time **/
        inventory.eventDateTime ?: "",

        /** EQU-3: Equipment state **/
        inventory.equipmentState ?: "",

        /** EQU-4: Local/remote control state (not used) **/
        "",

        /** EQU-5: Alert level (not used) **/
        "",

        /** EQU-6: Equipment name **/
        inventory.equipmentName ?: ""
    )
}
