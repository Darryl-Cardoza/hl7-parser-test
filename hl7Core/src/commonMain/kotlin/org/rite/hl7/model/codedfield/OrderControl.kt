package org.rite.hl7.model.codedfield

sealed class OrderControl(val code: String) {
    object NW : OrderControl("NW")
    object RF : OrderControl("RF")
    object CA : OrderControl("CA")
    object DC : OrderControl("DC")
    object HD : OrderControl("HD")
    object OH : OrderControl("OH")
    object OK : OrderControl("OK")
    object UA : OrderControl("UA")
    object SC : OrderControl("SC")
    object OC : OrderControl("OC")
    object OD : OrderControl("OD")
    object AF : OrderControl("AF")
    object DF : OrderControl("DF")
    object FU : OrderControl("FU")
    object RP : OrderControl("RP")
    object RO : OrderControl("RO")
    object XO : OrderControl("XO")
    object RE : OrderControl("RE")
    data class Unknown(val raw: String) : OrderControl(raw)

    companion object {
        fun from(raw: String): OrderControl = when (raw.uppercase()) {
            "NW" -> NW; "RF" -> RF; "CA" -> CA; "DC" -> DC; "HD" -> HD
            "OH" -> OH; "OK" -> OK; "UA" -> UA; "SC" -> SC; "OC" -> OC
            "OD" -> OD; "AF" -> AF; "DF" -> DF; "FU" -> FU; "RP" -> RP
            "RO" -> RO; "XO" -> XO; "RE" -> RE
            else -> Unknown(raw)
        }
    }
}
