package org.rite.hl7.model.datatype

import org.rite.hl7.model.ast.HL7Field

/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4), used inline in
 * fields like ORC-7. Every component is a plain String (raw, "" if absent);
 * [explicitTimes] is the one structured extra, and it degrades to an empty
 * list rather than throwing when TQ.2 doesn't have the expected shape.
 */
data class TQ(
    val quantity: String, // TQ.1
    val interval: String, // TQ.2 (full, e.g. "Q6H^0600,1200,1800,0000")
    val intervalCode: String, // TQ.2.1 subcomponent (e.g. "Q6H")
    val explicitTimes: List<String>, // TQ.2.2 subcomponent, comma-split, [] if absent
    val duration: String, // TQ.3
    val startDateTime: String, // TQ.4
    val endDateTime: String, // TQ.5
    val priority: String, // TQ.6
    val condition: String, // TQ.7
    val text: String, // TQ.8
    val conjunction: String, // TQ.9 (S/A/C, HL70472)
    val orderSequencing: String, // TQ.10 (raw composite string)
    val occurrenceDuration: String, // TQ.11
    val totalOccurrences: String, // TQ.12
) {
    /** TQ.9 = "S" (sequential) — TQ.10 should carry the predecessor link. */
    val isSequential: Boolean get() = conjunction.equals("S", ignoreCase = true)

    /** No end date and no total-occurrences cap -> schedule runs until cancelled. */
    val isOpenEnded: Boolean get() = endDateTime.isBlank() && totalOccurrences.isBlank()

    companion object {
        fun parse(field: HL7Field): TQ {
            val intervalComponent = field.component(2)
            return TQ(
                quantity = field.component(1).value,
                interval = intervalComponent.value,
                intervalCode = intervalComponent.subcomponent(1),
                explicitTimes =
                    intervalComponent
                        .subcomponent(2)
                        .split(',')
                        .map { it.trim() }
                        .filter { it.isNotBlank() },
                duration = field.component(3).value,
                startDateTime = field.component(4).value,
                endDateTime = field.component(5).value,
                priority = field.component(6).value,
                condition = field.component(7).value,
                text = field.component(8).value,
                conjunction = field.component(9).value,
                orderSequencing = field.component(10).subcomponents.joinToString("&"),
                occurrenceDuration = field.component(11).value,
                totalOccurrences = field.component(12).value,
            )
        }
    }
}
