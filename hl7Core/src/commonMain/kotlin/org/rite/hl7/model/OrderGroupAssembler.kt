package org.rite.hl7.model

import org.rite.hl7.model.segment.ORCSegment
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.RXRSegment
import org.rite.hl7.model.segment.TQ1Segment
import org.rite.hl7.model.segment.ZPRSegment

/**
 * Buckets a flat, already-parsed segment list into [OrderGroup]s: each
 * segment belongs to the most recently seen ORC. Segments before the first
 * ORC (MSH, PID, PV1) are message-level and never grouped; segments that
 * aren't RXE/RXR/ZPR/TQ1 (e.g. ZUI/ZNI, or any unmatched trailing segment)
 * are simply absent from the result — this is a read convenience derived
 * from the flat segment list, not the source of truth, so nothing is lost
 * from the message itself.
 */
internal object OrderGroupAssembler {
    fun assemble(segments: List<TypedSegment>): List<OrderGroup> {
        val groups = mutableListOf<OrderGroup>()
        var currentOrc: ORCSegment? = null
        var currentRxe: RXESegment? = null
        val currentRxr = mutableListOf<RXRSegment>()
        val currentZpr = mutableListOf<ZPRSegment>()
        var currentTq1: TQ1Segment? = null

        fun flush() {
            val orc = currentOrc ?: return
            groups += OrderGroup(orc, currentRxe, currentRxr.toList(), currentZpr.toList(), currentTq1)
            currentRxe = null
            currentRxr.clear()
            currentZpr.clear()
            currentTq1 = null
        }

        for (seg in segments) {
            when {
                seg is ORCSegment -> {
                    flush()
                    currentOrc = seg
                }
                currentOrc == null -> Unit
                seg is RXESegment -> currentRxe = seg
                seg is RXRSegment -> currentRxr += seg
                seg is ZPRSegment -> currentZpr += seg
                seg is TQ1Segment -> currentTq1 = seg
                else -> Unit
            }
        }
        flush()
        return groups
    }
}
