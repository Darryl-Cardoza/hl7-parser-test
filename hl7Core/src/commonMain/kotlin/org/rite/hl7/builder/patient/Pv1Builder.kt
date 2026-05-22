package com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.patient

import org.rite.hl7.domain.model.VisitData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

fun buildPV1(
    visit: VisitData,
    hl7Version: String = "2.5"
): String {

    // PV1-3: Assigned Patient Location (POC ^ Room ^ Bed ^ Facility)
    val location = buildComponent(
        visit.locPointOfCare ?: "",
        visit.locRoom ?: "",
        visit.locBed ?: "",
        visit.locFacility ?: ""
    )

    // PV1-7: Attending Doctor (ID ^ family ^ given)
    val attendingDoctor = buildComponent(
        visit.attendingDoctorId ?: "",
        visit.attendingDoctorFamilyName ?: "",
        visit.attendingDoctorGivenName ?: ""
    )

    // PV1-19: Visit Number (ID ^ ^ ^ assigning authority)
    val visitNumber = buildComponent(
        visit.visitNumber ?: "",
        "",
        "",
        visit.visitNumberAssigningAuthority ?: ""
    )

    /**
     * Canonical PV1 field list (PV1-1 → PV1-44).
     * Version cap applied below — v2.1 stops at PV1-44 (same), but
     * trailing empty fields are trimmed so the wire message is minimal.
     */
    val allFields = listOf(
        "1",                        // PV1-1
        visit.patientClass ?: "",   // PV1-2
        location,                   // PV1-3
        "",                         // PV1-4
        "",                         // PV1-5
        "",                         // PV1-6
        attendingDoctor,            // PV1-7
        "",                         // PV1-8
        "",                         // PV1-9
        "",                         // PV1-10
        "",                         // PV1-11
        "",                         // PV1-12
        "",                         // PV1-13
        "",                         // PV1-14
        "",                         // PV1-15
        "",                         // PV1-16
        "",                         // PV1-17
        "",                         // PV1-18
        visitNumber,                // PV1-19
        "",                         // PV1-20
        "",                         // PV1-21
        "",                         // PV1-22
        "",                         // PV1-23
        "",                         // PV1-24
        "",                         // PV1-25
        "",                         // PV1-26
        "",                         // PV1-27
        "",                         // PV1-28
        "",                         // PV1-29
        "",                         // PV1-30
        "",                         // PV1-31
        "",                         // PV1-32
        "",                         // PV1-33
        "",                         // PV1-34
        "",                         // PV1-35
        "",                         // PV1-36
        "",                         // PV1-37
        "",                         // PV1-38
        "",                         // PV1-39
        "",                         // PV1-40
        "",                         // PV1-41
        "",                         // PV1-42
        "",                         // PV1-43
        visit.admitDateTime ?: ""   // PV1-44
    )

    val maxField = Pv1VersionCapabilities.maxField(hl7Version)

    return HL7Utils.buildSegmentTrimmed(
        "PV1",
        *allFields.take(maxField).toTypedArray()
    )
}

object Pv1VersionCapabilities {

    /**
     * Maximum PV1 field number by HL7 version.
     * v2.1 : PV1-1..40
     * v2.2+: PV1-1..44
     */
    private val maxFieldByVersion = mapOf(
        "2.1"   to 40,
        "2.2"   to 44,
        "2.3"   to 44,
        "2.3.1" to 44,
        "2.4"   to 44,
        "2.5"   to 44,
        "2.5.1" to 44,
        "2.6"   to 44,
        "2.7"   to 44,
        "2.8"   to 44
    )

    fun maxField(version: String): Int =
        maxFieldByVersion[version] ?: 44
}
