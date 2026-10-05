package org.rite.hl7.model.codedfield

sealed class SubstanceStatus(
    val code: String,
) {
    object EW : SubstanceStatus("EW")

    object EE : SubstanceStatus("EE")

    object CW : SubstanceStatus("CW")

    object CE : SubstanceStatus("CE")

    object QW : SubstanceStatus("QW")

    object QE : SubstanceStatus("QE")

    object NW : SubstanceStatus("NW")

    object NE : SubstanceStatus("NE")

    object OW : SubstanceStatus("OW")

    object OE : SubstanceStatus("OE")

    object OK : SubstanceStatus("OK")

    data class Unknown(
        val raw: String,
    ) : SubstanceStatus(raw)

    companion object {
        fun from(raw: String): SubstanceStatus =
            when (raw.uppercase()) {
                "EW" -> EW
                "EE" -> EE
                "CW" -> CW
                "CE" -> CE
                "QW" -> QW
                "QE" -> QE
                "NW" -> NW
                "NE" -> NE
                "OW" -> OW
                "OE" -> OE
                "OK" -> OK
                else -> Unknown(raw)
            }
    }
}
