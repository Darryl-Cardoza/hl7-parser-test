package org.rite.hl7.parser.observation

import org.rite.hl7.domain.model.ObservationData

/**
 * Parses OBX segments into ObservationData objects.
 * Handles both standard OBX and FOBX (vendor continuation) segments —
 * callers must normalize FOBX → OBX before passing the segment map.
 */
fun parseObservations(
    segments: Map<String, List<List<String>>>,
    compSep: String
): List<ObservationData> {

    return (segments["OBX"] ?: emptyList()).map { obx ->

        // OBX-3: Observation identifier (code^text^codingSystem)
        val idParts = obx.getOrElse(3) { "" }.split(compSep)

        ObservationData(
            setId              = obx.getOrElse(1) { "" },
            valueType          = obx.getOrElse(2) { "" },
            observationId      = idParts.getOrNull(0) ?: "",
            observationText    = idParts.getOrNull(1)?.takeIf { it.isNotBlank() },
            codingSystem       = idParts.getOrNull(2)?.takeIf { it.isNotBlank() },
            subId              = obx.getOrNull(4)?.takeIf { it.isNotBlank() },
            observationValue   = obx.getOrElse(5) { "" },
            units              = obx.getOrNull(6)?.takeIf { it.isNotBlank() },
            referenceRange     = obx.getOrNull(7)?.takeIf { it.isNotBlank() },
            abnormalFlags      = obx.getOrNull(8)?.takeIf { it.isNotBlank() },
            probability        = obx.getOrNull(9)?.takeIf { it.isNotBlank() },
            natureOfAbnormalTest          = obx.getOrNull(10)?.takeIf { it.isNotBlank() },
            resultStatus       = obx.getOrElse(11) { "" },
            effectiveDateOfReferenceRange = obx.getOrNull(12)?.takeIf { it.isNotBlank() },
            userDefinedAccessChecks       = obx.getOrNull(13)?.takeIf { it.isNotBlank() },
            dateTimeOfObservation         = obx.getOrNull(14)?.takeIf { it.isNotBlank() },
            producerId                    = obx.getOrNull(15)?.takeIf { it.isNotBlank() },
            responsibleObserver           = obx.getOrNull(16)?.takeIf { it.isNotBlank() },
            observationMethod             = obx.getOrNull(17)?.takeIf { it.isNotBlank() },
            equipmentInstanceIdentifier   = obx.getOrNull(18)?.takeIf { it.isNotBlank() },
            dateTimeOfAnalysis            = obx.getOrNull(19)?.takeIf { it.isNotBlank() }
        )
    }
}
