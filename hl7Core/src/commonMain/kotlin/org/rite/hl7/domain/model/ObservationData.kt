package org.rite.hl7.domain.model

/**
 * OBX - Observation/Result Segment
 * Supports HL7 v2.1–v2.8 field set.
 * Used for dispense images, lab results, and any structured observation.
 */
data class ObservationData(

    /** OBX-1: Set ID (sequence number) **/
    val setId: String,

    /** OBX-2: Value type (ST, NM, RP, CWE, etc.) **/
    val valueType: String,

    /** OBX-3.1: Observation identifier code **/
    val observationId: String,

    /** OBX-3.2: Observation identifier text **/
    val observationText: String? = null,

    /** OBX-3.3: Coding system **/
    val codingSystem: String? = null,

    /** OBX-4: Observation sub-ID (used to group related OBX rows) **/
    val subId: String? = null,

    /** OBX-5: Observation value (count, URL, text, etc.) **/
    val observationValue: String,

    /** OBX-6: Units (e.g. type=VIAL, mg/dL) **/
    val units: String? = null,

    /** OBX-7: Reference range (e.g. image filename) **/
    val referenceRange: String? = null,

    /** OBX-8: Abnormal flags **/
    val abnormalFlags: String? = null,

    /** OBX-9: Probability **/
    val probability: String? = null,

    /** OBX-10: Nature of abnormal test **/
    val natureOfAbnormalTest: String? = null,

    /** OBX-11: Result status (F=Final, P=Preliminary, C=Correction, etc.) **/
    val resultStatus: String,

    /** OBX-12: Effective date of reference range (v2.2+) **/
    val effectiveDateOfReferenceRange: String? = null,

    /** OBX-13: User-defined access checks (v2.2+) **/
    val userDefinedAccessChecks: String? = null,

    /** OBX-14: Date/time of observation (v2.2+) **/
    val dateTimeOfObservation: String? = null,

    /** OBX-15: Producer ID (v2.2+) **/
    val producerId: String? = null,

    /** OBX-16: Responsible observer (v2.2+) **/
    val responsibleObserver: String? = null,

    /** OBX-17: Observation method (v2.2+) **/
    val observationMethod: String? = null,

    /** OBX-18: Equipment instance identifier (v2.4+) **/
    val equipmentInstanceIdentifier: String? = null,

    /** OBX-19: Date/time of analysis (v2.4+) **/
    val dateTimeOfAnalysis: String? = null
)
