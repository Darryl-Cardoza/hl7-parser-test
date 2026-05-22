package org.rite.hl7.domain.model

/**
 * Transaction priority parsed from the ZPR custom segment.
 *
 * ZPR segment format:
 *   ZPR|<setId>|PRIORITY|<value>|...
 *
 * Example:
 *   ZPR|1|PRIORITY|STAT    →  TxnPriority.STAT
 *   ZPR|1|PRIORITY|ROUTINE →  TxnPriority.ROUTINE
 *   ZPR|1|PRIORITY|URGENT  →  TxnPriority.URGENT
 */
enum class TxnPriority {

    /** Immediate — highest priority, process before all others **/
    STAT,

    /** Urgent — high priority, process soon **/
    URGENT,

    /** Standard routine priority **/
    ROUTINE,

    /** Timing not critical **/
    TIMED,

    /** Priority not specified or segment absent **/
    UNKNOWN;

    companion object {

        /**
         * Parses a ZPR field3 value into a [TxnPriority].
         * Case-insensitive. Returns [UNKNOWN] for null or unrecognised values.
         */
        fun fromString(value: String?): TxnPriority =
            when (value?.uppercase()?.trim()) {
                "STAT"    -> STAT
                "URGENT"  -> URGENT
                "ROUTINE" -> ROUTINE
                "TIMED"   -> TIMED
                else      -> UNKNOWN
            }
    }
}
