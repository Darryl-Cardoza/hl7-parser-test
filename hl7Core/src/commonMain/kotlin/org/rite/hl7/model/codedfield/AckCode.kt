package org.rite.hl7.model.codedfield

sealed class AckCode(val code: String) {
    object AA : AckCode("AA")
    object AE : AckCode("AE")
    object AR : AckCode("AR")
    object CA : AckCode("CA")
    object CE : AckCode("CE")
    object CR : AckCode("CR")
    data class Unknown(val raw: String) : AckCode(raw)

    companion object {
        fun from(raw: String): AckCode = when (raw.uppercase()) {
            "AA" -> AA; "AE" -> AE; "AR" -> AR
            "CA" -> CA; "CE" -> CE; "CR" -> CR
            else -> Unknown(raw)
        }
    }
}
