package org.rite.hl7.model.codedfield

sealed class ObsResultStatus(val code: String) {
    object C : ObsResultStatus("C")
    object D : ObsResultStatus("D")
    object F : ObsResultStatus("F")
    object I : ObsResultStatus("I")
    object N : ObsResultStatus("N")
    object O : ObsResultStatus("O")
    object P : ObsResultStatus("P")
    object R : ObsResultStatus("R")
    object S : ObsResultStatus("S")
    object U : ObsResultStatus("U")
    object W : ObsResultStatus("W")
    object X : ObsResultStatus("X")
    class Unknown(val raw: String) : ObsResultStatus(raw)

    companion object {
        fun from(raw: String): ObsResultStatus = when (raw.uppercase()) {
            "C" -> C; "D" -> D; "F" -> F; "I" -> I; "N" -> N; "O" -> O
            "P" -> P; "R" -> R; "S" -> S; "U" -> U; "W" -> W; "X" -> X
            else -> Unknown(raw)
        }
    }
}
