package org.rite.hl7.model.codedfield

sealed class SubstitutionStatus(
    val code: String,
) {
    object NoSelection : SubstitutionStatus("0")

    object NotAllowed : SubstitutionStatus("1")

    object PatientRequested : SubstitutionStatus("2")

    object PharmacistSelected : SubstitutionStatus("3")

    object GenericNotInStock : SubstitutionStatus("4")

    object BrandAsGeneric : SubstitutionStatus("5")

    object BrandMandatedByLaw : SubstitutionStatus("7")

    object GenericNotAvailable : SubstitutionStatus("8")

    object G : SubstitutionStatus("G")

    object N : SubstitutionStatus("N")

    object T : SubstitutionStatus("T")

    data class Unknown(
        val raw: String,
    ) : SubstitutionStatus(raw)

    companion object {
        fun from(raw: String): SubstitutionStatus =
            when (raw.uppercase()) {
                "0" -> NoSelection
                "1" -> NotAllowed
                "2" -> PatientRequested
                "3" -> PharmacistSelected
                "4" -> GenericNotInStock
                "5" -> BrandAsGeneric
                "7" -> BrandMandatedByLaw
                "8" -> GenericNotAvailable
                "G" -> G
                "N" -> N
                "T" -> T
                else -> Unknown(raw)
            }
    }
}
