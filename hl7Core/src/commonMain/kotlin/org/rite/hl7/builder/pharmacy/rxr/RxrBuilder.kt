package org.rite.hl7.builder.pharmacy.rxr

import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent
import org.rite.hl7.domain.model.RouteData

fun buildRXR(route: RouteData): String {

    // RXR-1: Route of administration (code ^ text ^ coding system)
    val routeCode = buildComponent(
        route.routeCode ?: "",
        route.routeText ?: "",
        route.routeCodeSystem ?: ""
    )

    // RXR-2: Administration site (code ^ text)
    val adminSite = buildComponent(
        route.adminSiteCode ?: "",
        route.adminSiteText ?: ""
    )

    // RXR-3: Administration device (code ^ text)
    val adminDevice = buildComponent(
        route.adminDeviceCode ?: "",
        route.adminDeviceText ?: ""
    )

    /** Assemble RXR segment with HL7-defined field positions **/
    return HL7Utils.buildSegment(
        "RXR",  /** Segment ID **/

        /** RXR-1: Route **/
        routeCode,

        /** RXR-2: Administration site **/
        adminSite,

        /** RXR-3: Administration device **/
        adminDevice
    )
}
