package org.rite.hl7.model

import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.RXRSegment
import org.rite.hl7.model.segment.ZPRSegment

/**
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR segment trailing it, up to (not including) the next ORC.
 */
data class OrderGroup(
    val orc: ORCSegment,
    val rxe: RXESegment?,
    val rxr: List<RXRSegment>,
    val zpr: List<ZPRSegment>,
)
