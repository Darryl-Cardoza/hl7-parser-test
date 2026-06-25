package org.rite.hl7.model.segment

import org.rite.hl7.model.SegmentDefinition
import org.rite.hl7.model.TypedSegment
import org.rite.hl7.model.ast.HL7Segment

/**
 * ZSN — Serial Number Capture (DSCSA). New §10 extension.
 *
 * Field map (project-authoritative):
 * `ZSN|setId|packageSerialNumber|nationalDrugCode|lotNumber|expirationDate|transactionType`
 * transactionType: D = dispense, R = return.
 */
class ZSNSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val packageSerialNumber: String get() = fieldValue(2)
    val nationalDrugCode: String get() = fieldValue(3)
    val lotNumber: String get() = fieldValue(4)
    val expirationDate: String get() = fieldValue(5)
    val transactionType: String get() = fieldValue(6)

    companion object {
        const val NAME = "ZSN"
        /** Register on parser/builder via `registerCustomSegment(ZSNSegment.Definition)`. */
        val Definition = SegmentDefinition(NAME) { ZSNSegment(it) }
    }
}

/**
 * ZSV — Stock Bottle Validation Assertion. New §13 extension.
 *
 * Field map (project-authoritative):
 * `ZSV|setId|validationStatus|validationTimestamp|validatorId|rejectionReason`
 * validationStatus: VA = valid, VR = rejected.
 */
class ZSVSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val validationStatus: String get() = fieldValue(2)
    val validationTimestamp: String get() = fieldValue(3)
    val validatorId: String get() = fieldValue(4)
    val rejectionReason: String get() = fieldValue(5)

    companion object {
        const val NAME = "ZSV"
        val Definition = SegmentDefinition(NAME) { ZSVSegment(it) }
    }
}

/**
 * ZAD — Inventory Adjustment. New §11 extension.
 *
 * Field map (project-authoritative):
 * `ZAD|setId|adjustmentType|adjustmentQuantity|adjustmentReason|adjustmentDateTime|approvedBy`
 */
class ZADSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val adjustmentType: String get() = fieldValue(2)
    val adjustmentQuantity: String get() = fieldValue(3)
    val adjustmentReason: String get() = fieldValue(4)
    val adjustmentDateTime: String get() = fieldValue(5)
    val approvedBy: String get() = fieldValue(6)

    companion object {
        const val NAME = "ZAD"
        val Definition = SegmentDefinition(NAME) { ZADSegment(it) }
    }
}
