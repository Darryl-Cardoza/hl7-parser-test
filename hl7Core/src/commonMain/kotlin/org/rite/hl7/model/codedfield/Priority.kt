package org.rite.hl7.model.codedfield

sealed class Priority(val code: String) {
    object S   : Priority("S")
    object A   : Priority("A")
    object R   : Priority("R")
    object P   : Priority("P")
    object C   : Priority("C")
    object PRN : Priority("PRN")
    object T   : Priority("T")
    object UD  : Priority("UD")
    data class Unknown(val raw: String) : Priority(raw)

    companion object {
        fun from(raw: String): Priority = when (raw.uppercase()) {
            "S" -> S; "A" -> A; "R" -> R; "P" -> P; "C" -> C
            "PRN" -> PRN; "T" -> T; "UD" -> UD
            else -> Unknown(raw)
        }
    }
}
