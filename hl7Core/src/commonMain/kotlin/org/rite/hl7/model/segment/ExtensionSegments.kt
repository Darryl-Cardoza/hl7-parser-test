package org.rite.hl7.model.segment

import org.rite.hl7.model.SegmentDefinition
import org.rite.hl7.model.TypedSegment
import org.rite.hl7.model.ast.HL7Segment

/**
 * ZSN — Serial Number Capture (DSCSA). New §10 extension.
 *
 * Field map (project-authoritative):
 * `ZSN|setId|packageSerialNumber|nationalDrugCode|lotNumber|expirationDate|transactionType|quantityFromThisStockItem|captureSource|captureTimestamp`
 * transactionType: D = dispense, R = return.
 * captureSource: GS1 / NDC_LINEAR / MANUAL / UNKNOWN.
 */
class ZSNSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val packageSerialNumber: String get() = fieldValue(2)
    val nationalDrugCode: String get() = fieldValue(3)
    val lotNumber: String get() = fieldValue(4)
    val expirationDate: String get() = fieldValue(5)
    val transactionType: String get() = fieldValue(6)
    val quantityFromThisStockItem: String get() = fieldValue(7)
    val captureSource: String get() = fieldValue(8)
    val captureTimestamp: String get() = fieldValue(9)

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
 * `ZSV|setId|validationStatus|validationTimestamp|validatorId|rejectionReason|dispensedNdc|scannedNdc|scanSource|matchStrength`
 * validationStatus: VA = valid, VR = rejected.
 * scanSource: GS1 / NDC_LINEAR / MANUAL.
 * matchStrength: EXACT / GENERIC / NDC10 — required when validationStatus indicates a match/substitution.
 */
class ZSVSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val validationStatus: String get() = fieldValue(2)
    val validationTimestamp: String get() = fieldValue(3)
    val validatorId: String get() = fieldValue(4)
    val rejectionReason: String get() = fieldValue(5)
    val dispensedNdc: String get() = fieldValue(6)
    val scannedNdc: String get() = fieldValue(7)
    val scanSource: String get() = fieldValue(8)
    val matchStrength: String get() = fieldValue(9)

    companion object {
        const val NAME = "ZSV"
        val Definition = SegmentDefinition(NAME) { ZSVSegment(it) }
    }
}

/**
 * ZAD — Inventory Adjustment. New §11 extension.
 *
 * Field map (project-authoritative):
 * `ZAD|setId|adjustmentType|adjustmentQuantity|adjustmentReason|adjustmentDateTime|approvedBy|comment`
 * adjustmentType (sign): + add, - subtract, O overwrite QOH.
 * adjustmentReason: see [org.rite.hl7.builder.ZadReasonCode] for default site reason codes.
 */
class ZADSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val adjustmentType: String get() = fieldValue(2)
    val adjustmentQuantity: String get() = fieldValue(3)
    val adjustmentReason: String get() = fieldValue(4)
    val adjustmentDateTime: String get() = fieldValue(5)
    val approvedBy: String get() = fieldValue(6)
    val comment: String get() = fieldValue(7)

    companion object {
        const val NAME = "ZAD"
        val Definition = SegmentDefinition(NAME) { ZADSegment(it) }
    }
}
