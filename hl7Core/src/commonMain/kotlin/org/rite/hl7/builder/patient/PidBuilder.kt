package org.rite.hl7.builder.patient

import org.rite.hl7.domain.model.PatientData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

fun buildPID(patient: PatientData): String {

    // PID-3: Patient Identifier List (ID ^ ^ ^ assigning authority ^ ID type)
    val patientId = buildComponent(
        patient.patientId,
        "", // Check digit
        "", // Check digit scheme
        patient.patientIdAssigningAuthority ?: "",
        patient.patientIdType ?: ""
    )

    // PID-5: Patient Name (family ^ given ^ middle)
    val patientName = buildComponent(
        patient.familyName ?: "",
        patient.givenName ?: "",
        patient.middleName ?: ""
    )

    // PID-11: Patient Address (street ^ ^ city ^ state ^ zip ^ country)
    val address = buildComponent(
        patient.streetAddress ?: "",
        "", // Other designation
        patient.city ?: "",
        patient.state ?: "",
        patient.zipCode ?: "",
        patient.country ?: ""
    )

    /** Assemble PID segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "PID",  /** Segment ID **/

        /** PID-1: Set ID **/
        "1",

        /** PID-2: Patient ID (external, not used) **/
        "",

        /** PID-3: Patient identifier list **/
        patientId,

        /** PID-4: Alternate patient ID (not used) **/
        "",

        /** PID-5: Patient name **/
        patientName,

        /** PID-6: Mother’s maiden name (not used) **/
        "",

        /** PID-7: Date of birth (YYYYMMDD) **/
        patient.dateOfBirth ?: "",

        /** PID-8: Administrative sex **/
        patient.sex ?: "",

        /** PID-9: Patient alias (not used) **/
        "",

        /** PID-10: Race (not used) **/
        "",

        /** PID-11: Patient address **/
        address
    )
}
