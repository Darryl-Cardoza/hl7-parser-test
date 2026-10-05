package org.rite.hl7.model.segment

import org.rite.hl7.model.SegmentDefinition
import org.rite.hl7.model.TypedSegment
import org.rite.hl7.model.ast.HL7Segment
import org.rite.hl7.model.codedfield.SubstitutionStatus
import org.rite.hl7.model.codedfield.ObsResultStatus
import org.rite.hl7.model.codedfield.Priority

/** RXE — Pharmacy/Treatment Encoded Order. */
class RXESegment(
    raw: HL7Segment,
) : TypedSegment(raw) {
    val substitutionStatusRaw: String get() = fieldValue(9)
    val substitutionStatus: SubstitutionStatus get() = SubstitutionStatus.from(substitutionStatusRaw)
    val orderingProviderDeaNumber: String get() = component(13, 1)
    val controlledSubstanceSchedule: String get() = component(35, 1)
    val giveCode: String get() = component(2, 1)
    val giveName: String get() = component(2, 2)
    val giveCodeSystem: String get() = component(2, 3)
    val giveAmountMinimum: String get() = fieldValue(3)
    val giveAmountMaximum: String get() = fieldValue(4)
    val giveUnitsCode: String get() = component(5, 1)
    val giveUnitsText: String get() = component(5, 2)
    val dosageFormCode: String get() = component(6, 1)
    val dosageFormText: String get() = component(6, 2)
    val providerAdministrationInstructions: String get() = fieldValue(7)
    val deliverToLocation: String get() = fieldValue(8)
    val dispenseAmount: String get() = fieldValue(10)
    val dispenseUnitsCode: String get() = component(11, 1)
    val dispenseUnitsText: String get() = component(11, 2)
    val numberOfRefills: String get() = fieldValue(12)
    val prescriptionNumber: String get() = fieldValue(15)

    companion object {
        const val NAME = "RXE"
        val Definition = SegmentDefinition(NAME) { RXESegment(it) }
    }
}

/** RXD — Pharmacy/Treatment Dispense. */
class RXDSegment(
    raw: HL7Segment,
) : TypedSegment(raw) {
    val pharmacyOrderType: String get() = fieldValue(32)
    val dispenseSubIdCounter: String get() = fieldValue(1)
    val dispenseGiveCode: String get() = component(2, 1)
    val dispenseGiveName: String get() = component(2, 2)
    val dispenseGiveCodeSystem: String get() = component(2, 3)
    val dateTimeDispensed: String get() = fieldValue(3)
    val actualDispenseAmount: String get() = fieldValue(4)
    val actualDispenseUnits: String get() = component(5, 1)
    val actualDispenseUnitsText: String get() = component(5, 2)
    val actualDosageFormCode: String get() = component(6, 1)
    val prescriptionNumber: String get() = fieldValue(7)
    val dispensingProviderId: String get() = component(10, 1)

    val substitutionStatusRaw: String get() = fieldValue(11)
    val substitutionStatus: SubstitutionStatus get() = SubstitutionStatus.from(substitutionStatusRaw)
    val lotNumber: String get() = fieldValue(15)
    val expirationDate: String get() = fieldValue(16)
    val substanceManufacturerName: String get() = component(17, 2)

    companion object {
        const val NAME = "RXD"
        val Definition = SegmentDefinition(NAME) { RXDSegment(it) }
    }
}

/** RXC — Pharmacy/Treatment Component Order. */
class RXCSegment(
    raw: HL7Segment,
) : TypedSegment(raw) {
    val componentType: String get() = fieldValue(1)
    val componentCode: String get() = component(2, 1)
    val componentName: String get() = component(2, 2)
    val componentCodeSystem: String get() = component(2, 3)
    val componentAmount: String get() = fieldValue(3)
    val componentUnitsCode: String get() = component(4, 1)
    val componentUnitsText: String get() = component(4, 2)
    val componentStrength: String get() = fieldValue(5)
    val supplementaryCode: String get() = fieldValue(7)
    val componentDrugStrengthVolume: String get() = fieldValue(8)
    val componentStrengthUnits: String get() = fieldValue(6)

    companion object {
        const val NAME = "RXC"
        val Definition = SegmentDefinition(NAME) { RXCSegment(it) }
    }
}

/** RXR — Pharmacy/Treatment Route. */
class RXRSegment(
    raw: HL7Segment,
) : TypedSegment(raw) {
    val administrationMethod: String get() = fieldValue(4)
    val routingInstruction: String get() = fieldValue(5)
    val routeCode: String get() = component(1, 1)
    val routeText: String get() = component(1, 2)
    val routeCodeSystem: String get() = component(1, 3)
    val administrationSiteCode: String get() = component(2, 1)
    val administrationSiteText: String get() = component(2, 2)
    val administrationDeviceCode: String get() = component(3, 1)
    val administrationDeviceText: String get() = component(3, 2)

    companion object {
        const val NAME = "RXR"
        val Definition = SegmentDefinition(NAME) { RXRSegment(it) }
    }
}

/** TQ1 — Timing/Quantity. */
class TQ1Segment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val quantity: String get() = fieldValue(2)
    val repeatPattern: String get() = fieldValue(3)
    val explicitTime: String get() = fieldValue(4)
    val relativeTimeUnits: String get() = fieldValue(5)
    val serviceDuration: String get() = fieldValue(6)
    val startDateTime: String get() = fieldValue(7)
    val endDateTime: String get() = fieldValue(8)
    /** TQ1-9: priority (e.g. "R" routine, "S" stat). */
    val priority: Priority get() = Priority.from(priorityRaw)
    val priorityRaw: String get() = component(9, 1)

    companion object {
        const val NAME = "TQ1"
        val Definition = SegmentDefinition(NAME) { TQ1Segment(it) }
    }
}

/** OBX — Observation/Result. */
class OBXSegment(
    raw: HL7Segment,
) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val valueType: String get() = fieldValue(2)
    val observationId: String get() = component(3, 1)
    val observationText: String get() = component(3, 2)
    val observationCodeSystem: String get() = component(3, 3)
    val observationSubId: String get() = fieldValue(4)
    val observationValue: String get() = fieldValue(5)
    val units: String get() = component(6, 1)
    val referenceRange: String get() = fieldValue(7)
    val abnormalFlags: String get() = fieldValue(8)
    val resultStatusRaw: String get() = fieldValue(11)
    val resultStatus: ObsResultStatus get() = ObsResultStatus.from(resultStatusRaw)
    val dateTimeOfObservation: String get() = fieldValue(14)
    val responsibleObserver: String get() = component(16, 1)
    val effectiveDateOfReferenceRange: String get() = fieldValue(12)
    val producersId: String get() = component(15, 1)
    val observationMethod: String get() = fieldValue(17)

    companion object {
        const val NAME = "OBX"
        val Definition = SegmentDefinition(NAME) { OBXSegment(it) }
    }
}
