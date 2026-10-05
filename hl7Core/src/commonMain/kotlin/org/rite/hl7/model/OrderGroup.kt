package org.rite.hl7.model

import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.RXRSegment
import org.rite.hl7.model.segment.TQ1Segment
import org.rite.hl7.model.segment.ZPRSegment

/**
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR/TQ1 segment trailing it, up to (not including) the next ORC.
 */
data class OrderGroup(
    val orc: ORCSegment,
    val rxe: RXESegment?,
    val rxr: List<RXRSegment>,
    val zpr: List<ZPRSegment>,
    val tq1: TQ1Segment?,
) {
    /** TQ1-9 -> ORC-7.6 (TQ.6) -> ZPR.priority fallback, first non-blank wins. */
    val resolvedPriority: String
        get() =
            tq1?.priorityRaw?.takeIf { it.isNotBlank() }
                ?: orc.quantityTiming.priority.takeIf { it.isNotBlank() }
                ?: zpr.firstOrNull()?.priority.orEmpty()
}
