package com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.order

import org.rite.hl7.domain.model.OrderData
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.utils.HL7Utils.buildComponent

fun buildORC(
    order: OrderData,
    hl7Version: String = "2.5"
): String {

    // ORC-2: Placer Order Number (ID ^ namespace)
    val placerOrder = buildComponent(
        order.placerOrderId,
        order.placerOrderNamespace ?: ""
    )

    // ORC-3: Filler Order Number (ID ^ namespace)
    val fillerOrder = buildComponent(
        order.fillerOrderId ?: "",
        order.fillerOrderNamespace ?: ""
    )

    // ORC-12: Ordering Provider (ID ^ family ^ given)
    val orderingProvider = buildComponent(
        order.orderingProviderId ?: "",
        order.orderingProviderFamilyName ?: "",
        order.orderingProviderGivenName ?: ""
    )

    /**
     * Canonical ORC field list.
     * ORC-21 (ordering facility) is v2.3+ only — trimmed by version cap below.
     */
    val allFields = listOf(
        order.orderControl,           // ORC-1
        placerOrder,                  // ORC-2
        fillerOrder,                  // ORC-3
        "",                           // ORC-4
        order.orderStatus ?: "",      // ORC-5
        "",                           // ORC-6
        "",                           // ORC-7
        "",                           // ORC-8
        order.orderDateTime ?: "",    // ORC-9
        "",                           // ORC-10
        "",                           // ORC-11
        orderingProvider,             // ORC-12
        "",                           // ORC-13
        "",                           // ORC-14
        "",                           // ORC-15
        "",                           // ORC-16
        "",                           // ORC-17
        "",                           // ORC-18
        "",                           // ORC-19
        "",                           // ORC-20
        order.orderingFacility ?: ""  // ORC-21 (v2.3+)
    )

    val maxField = OrcVersionCapabilities.maxField(hl7Version)

    return HL7Utils.buildSegmentTrimmed(
        "ORC",
        *allFields.take(maxField).toTypedArray()
    )
}

object OrcVersionCapabilities {

    /**
     * Maximum ORC field number by HL7 version.
     * v2.1/2.2 : ORC-1..16
     * v2.3+    : ORC-1..21
     */
    private val maxFieldByVersion = mapOf(
        "2.1"   to 16,
        "2.2"   to 16,
        "2.3"   to 21,
        "2.3.1" to 21,
        "2.4"   to 21,
        "2.5"   to 21,
        "2.5.1" to 21,
        "2.6"   to 21,
        "2.7"   to 21,
        "2.8"   to 21
    )

    fun maxField(version: String): Int =
        maxFieldByVersion[version] ?: 21
}
