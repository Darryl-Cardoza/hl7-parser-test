package org.rite.hl7.builder.pharmacy.rxc

import org.rite.hl7.domain.model.ComponentData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

/**
 * Builds the HL7 RXC (Pharmacy/Treatment Component) segment.
 */
fun buildRXC(component: ComponentData): String {

    /** RXC-2: Component code (identifier ^ text ^ coding system) **/
    val componentCode = buildComponent(
        component.ndcOrComponentCode ?: "",
        component.componentName ?: "",
        component.componentCodeSystem ?: ""
    )

    // RXC-4: Component units (code ^ display text)
    val componentUnits = buildComponent(
        component.componentUnitsCode ?: "",
        component.componentUnitsText ?: ""
    )

    /** Assemble RXC segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "RXC",  /** Segment ID **/

        /** RXC-1: Component type **/
        component.componentType ?: "",

        /** RXC-2: Component code (identifier ^ text ^ coding system) **/
        componentCode,

        /** RXC-3: Component amount **/
        component.componentAmount ?: "",

        /** RXC-4: Component units (code ^ text) **/
        componentUnits,

        /** RXC-5: Component strength **/
        component.componentStrength ?: "",

        /** RXC-6: Component strength units **/
        component.componentStrengthUnits ?: ""
    )
}
