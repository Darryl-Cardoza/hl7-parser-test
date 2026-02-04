package org.rite.hl7.builder.pharmacy.rxe

import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent
import org.rite.hl7.domain.model.MedicationData

/**
 * Builds the HL7 RXE (Pharmacy/Treatment Encoded Order) segment.
 */
fun buildRXE(medication: MedicationData): String {

    /** RXE-2: Drug ordered (code ^ name ^ coding system) **/
    val giveCode = buildComponent(
        medication.drugCode,
        medication.drugName,
        medication.drugCodeSystem ?: ""
    )

    /** RXE-5: Units of quantity ordered (code ^ text) **/
    val giveUnits = buildComponent(
        medication.qtyUnitCode ?: "",
        medication.qtyUnitText ?: ""
    )

    /** RXE-6: Dosage form (code ^ text) **/
    val dosageForm = buildComponent(
        medication.dosageFormCode ?: "",
        medication.dosageFormText ?: ""
    )

    /** RXE-11: Units used for dispensing (code ^ text) **/
    val dispenseUnits = buildComponent(
        medication.dispenseUnitsCode ?: "",
        medication.dispenseUnitsText ?: ""
    )

    /** RXE-14: Pharmacist verifier (ID only) **/
    val pharmacist = buildComponent(
        medication.pharmacistVerifierId ?: ""
    )

    /** Assemble RXE segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "RXE",  /** Segment ID **/

        /** RXE-1: Quantity/Timing (not used) **/
        "",

        /** RXE-2: Give code (drug code ^ name ^ coding system) **/
        giveCode,

        /** RXE-3: Requested give amount **/
        medication.requestedQty ?: "",

        /** RXE-4: Requested give amount maximum **/
        medication.requestedQtyMax ?: "",

        /** RXE-5: Give units (code ^ text) **/
        giveUnits,

        /** RXE-6: Dosage form (code ^ text) **/
        dosageForm,

        /** RXE-7: Administration instructions **/
        medication.adminInstructions ?: "",

        /** RXE-8: Deliver-to location **/
        medication.deliverToLocation ?: "",

        /** RXE-9: Substitution status (not used) **/
        "",

        /** RXE-10: Dispense amount **/
        medication.dispenseAmount ?: "",

        /** RXE-11: Dispense units (code ^ text) **/
        dispenseUnits,

        /** RXE-12: Number of refills **/
        medication.numberOfRefills ?: "",

        /** RXE-13: Ordering provider DEA number (not used) **/
        "",

        /** RXE-14: Pharmacist verifier **/
        pharmacist,

        /** RXE-15: Prescription number (not used) **/
        "",

        /** RXE-16: Number of refills remaining (not used) **/
        "",

        /** RXE-17: Number of refills/doses dispensed (not used) **/
        "",

        /** RXE-18: Date/time of last refill or dose dispensed (not used) **/
        "",

        /** RXE-19: Total daily dose (not used) **/
        "",

        /** RXE-20: Needs human review indicator (not used) **/
        "",

        /** RXE-21: Pharmacy instructions **/
        medication.pharmacyInstructions ?: ""
    )
}
