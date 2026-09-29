package org.rite.hl7.model.codedfield

sealed class OrderStatus(val code: String) {
    object A  : OrderStatus("A")
    object CA : OrderStatus("CA")
    object CM : OrderStatus("CM")
    object DC : OrderStatus("DC")
    object ER : OrderStatus("ER")
    object HD : OrderStatus("HD")
    object IP : OrderStatus("IP")
    object RP : OrderStatus("RP")
    object SC : OrderStatus("SC")
    class Unknown(val raw: String) : OrderStatus(raw)

    companion object {
        fun from(raw: String): OrderStatus = when (raw.uppercase()) {
            "A" -> A; "CA" -> CA; "CM" -> CM; "DC" -> DC; "ER" -> ER
            "HD" -> HD; "IP" -> IP; "RP" -> RP; "SC" -> SC
            else -> Unknown(raw)
        }
    }
}
