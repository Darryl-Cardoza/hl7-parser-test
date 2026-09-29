package org.rite.hl7.model.codedfield

sealed class EquipmentState(val code: String) {
    object IN  : EquipmentState("IN")
    object CO  : EquipmentState("CO")
    object PU  : EquipmentState("PU")
    object RS  : EquipmentState("RS")
    object ID  : EquipmentState("ID")
    object OP  : EquipmentState("OP")
    object CL  : EquipmentState("CL")
    object PA  : EquipmentState("PA")
    object PD  : EquipmentState("PD")
    object ES  : EquipmentState("ES")
    object DC  : EquipmentState("DC")
    object DI  : EquipmentState("DI")
    object UNK : EquipmentState("UNK")
    class Unknown(val raw: String) : EquipmentState(raw)

    companion object {
        fun from(raw: String): EquipmentState = when (raw.uppercase()) {
            "IN" -> IN; "CO" -> CO; "PU" -> PU; "RS" -> RS; "ID" -> ID
            "OP" -> OP; "CL" -> CL; "PA" -> PA; "PD" -> PD; "ES" -> ES
            "DC" -> DC; "DI" -> DI; "UNK" -> UNK
            else -> Unknown(raw)
        }
    }
}
