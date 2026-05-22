package org.rite.hl7.builder.observation

object ObxVersionCapabilities {

    /**
     * Maximum OBX field number by HL7 version.
     *
     * v2.1 : OBX-1..11  (no date/producer/method fields)
     * v2.2 : OBX-1..17  (adds effective-date, access-checks, obs-datetime, producer, observer, method)
     * v2.4 : OBX-1..19  (adds equipment instance ID and datetime-of-analysis)
     * v2.5+: OBX-1..19  (same as v2.4)
     */
    private val maxFieldByVersion = mapOf(
        "2.1"   to 11,
        "2.2"   to 17,
        "2.3"   to 17,
        "2.3.1" to 17,
        "2.4"   to 19,
        "2.5"   to 19,
        "2.5.1" to 19,
        "2.6"   to 19,
        "2.7"   to 19,
        "2.8"   to 19
    )

    fun maxField(version: String): Int =
        maxFieldByVersion[version] ?: 19
}
