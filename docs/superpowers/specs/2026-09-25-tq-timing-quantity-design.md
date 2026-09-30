# TQ (Timing/Quantity) data type — design spec

Date: 2026-09-25

## Purpose

Parse the legacy HL7 TQ composite data type out of ORC-7 (Quantity/Timing),
and add support for the standalone v2.5+ TQ1 segment, so downstream code can
read execution quantity, schedule, and priority for RDE^O11 orders without
manually indexing components. Also establish a single place ("resolved
priority") that walks the fallback chain TQ1 -> ORC-7.6 -> ZPR, since no such
unified extractor exists today (only unrelated ZPR/RCP priority fields).

## Scope

In scope:
- New `TQ` composite data type, parsed from an `HL7Field` (used at ORC-7).
- New `TQ1Segment` typed segment (registered in `SegmentRegistry`).
- `ORCSegment.quantityTiming: TQ` accessor.
- `OrderGroup.tq1: TQ1Segment?` field, wired into `OrderGroupAssembler`.
- `OrderGroup.resolvedPriority: String` computed property (TQ1-9 -> ORC-7.6 ->
  ZPR.priority fallback chain).
- `SegmentCapabilities` entry for TQ1 (v2.5+ field-count breakpoint).
- Unit tests: TQ parsing (direct), OrderGroup/round-trip coverage for TQ1 +
  resolvedPriority.

Out of scope (deliberately, confirmed with user):
- OBR and RXO segments — do not exist in this codebase yet (repo is scoped to
  RDE^O11 pharmacy dispense only). The `TQ` type is built generic enough to
  reuse for OBR-27/RXO-21 later, when those segments are added.
- Outbound builder DSL sugar for TQ1 (`tq1 { }` in `RdeO11Scope`/
  `OrderBlockScope`). This pass is parse-only (inbound).
- Any enum/validation of priority *values* beyond exposing the raw string
  (existing `ValidationConfig.knownPriorities` / `HL7Validator` ZPR check is
  unaffected; extending it to `resolvedPriority` is a future follow-up, not
  this pass).

## Background: why this is a new architectural layer

The codebase has no reusable composite-data-type layer today — every
"composite type" (CWE-like, XCN-like, etc.) is inlined as named getters
directly on the segment class that uses it (e.g. `ORCSegment.orderingProviderId`
/ `orderingProviderFamilyName` / `orderingProviderGivenName` spell out an XCN
by hand — see `HeaderSegments.kt:92-94`). TQ appears (or will appear) across
multiple fields (ORC-7 now; OBR-27/RXO-21 later) plus has its own standalone
segment (TQ1), so a shared `TQ` data class is worth the precedent — confirmed
with user rather than silently deviating from the inline-getter convention.

## Data model

### `TQ` (new file: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/datatype/TQ.kt`)

```kotlin
package org.rite.hl7.model.datatype

import org.rite.hl7.model.ast.HL7Field

/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4). Every component is a
 * plain String (raw, "" if absent) per this codebase's convention; the
 * explicit-times list is the one structured extra, and it degrades to an
 * empty list rather than throwing when TQ.2 doesn't have the expected shape.
 */
data class TQ(
    val quantity: String,            // TQ.1
    val interval: String,            // TQ.2 (full, e.g. "Q6H^0600,1200,1800,0000")
    val intervalCode: String,        // TQ.2.1 subcomponent (e.g. "Q6H")
    val explicitTimes: List<String>, // TQ.2.2 subcomponent, comma-split, [] if absent
    val duration: String,            // TQ.3
    val startDateTime: String,       // TQ.4
    val endDateTime: String,         // TQ.5
    val priority: String,            // TQ.6
    val condition: String,           // TQ.7
    val text: String,                // TQ.8
    val conjunction: String,         // TQ.9 (S/A/C, HL70472)
    val orderSequencing: String,     // TQ.10 (raw composite string)
    val occurrenceDuration: String,  // TQ.11
    val totalOccurrences: String,    // TQ.12
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
                explicitTimes = intervalComponent.subcomponent(2)
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
                orderSequencing = field.component(10).value,
                occurrenceDuration = field.component(11).value,
                totalOccurrences = field.component(12).value,
            )
        }
    }
}
```

Notes:
- Uses the existing `HL7Field`/`HL7Component` primitives directly (no new
  tokenizer work needed — component/subcomponent splitting is already
  delimiter-driven and version-agnostic).
- `field.component(n)` on a short/absent field already resolves to
  `HL7Component.EMPTY` per existing `HL7Field` behavior, so components beyond
  what a v2.3 sender populates safely come back as `""` — this is what
  satisfies "gracefully fall back to raw string" for TQ.2 non-standard text:
  `intervalCode`/`explicitTimes` come back blank/empty, but `interval` still
  holds the full raw string untouched.
- Exact accessor names for `HL7Component`/`HL7Field` (`.value`, `.subcomponent(n)`,
  `.component(n)`) to be confirmed against current signatures in
  `HL7Component.kt`/`HL7Field.kt` while implementing — investigation notes
  above may not be verbatim.

### `TQ1Segment` (added to `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/HeaderSegments.kt`, alongside `ORCSegment`)

```kotlin
/** TQ1 — Timing/Quantity (standalone, HL7 v2.5+). */
class TQ1Segment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val quantity: String get() = fieldValue(2)
    val repeatPattern: String get() = fieldValue(3)
    val explicitTime: String get() = fieldValue(4)
    val relativeTimeAndUnits: String get() = fieldValue(5)
    val serviceDuration: String get() = fieldValue(6)
    val startDateTime: String get() = fieldValue(7)
    val endDateTime: String get() = fieldValue(8)
    val priority: String get() = fieldValue(9)
    val condition: String get() = fieldValue(10)
    val text: String get() = fieldValue(11)
    val conjunction: String get() = fieldValue(12)
    val occurrenceDuration: String get() = fieldValue(13)
    val totalOccurrences: String get() = fieldValue(14)

    companion object {
        const val NAME = "TQ1"
        val Definition = SegmentDefinition(NAME) { TQ1Segment(it) }
    }
}
```

TQ1 gets its own field-by-field getters (not built from the `TQ` data class)
because its field layout genuinely differs from the inline composite (e.g.
repeat pattern and explicit time are split into separate fields, TQ1-3/TQ1-4,
rather than combined as TQ.2 subcomponents) — mirrors how the codebase already
treats "same concept, different wire shape" (see `INVSegment`'s three
layouts, `InventorySegments.kt:32-80`).

### `ORCSegment` change

Add one accessor to the existing class (`HeaderSegments.kt:84-101`):
```kotlin
val quantityTiming: TQ get() = TQ.parse(raw.field(7))
```

### `SegmentRegistry` change

Add `TQ1Segment.Definition` to the registration list in
`SegmentRegistry.kt:38-47`.

### `OrderGroup` change

```kotlin
data class OrderGroup(
    val orc: ORCSegment,
    val rxe: RXESegment?,
    val rxr: List<RXRSegment>,
    val zpr: List<ZPRSegment>,
    val tq1: TQ1Segment?,   // new — 0..1 per order group (segment is single, not repeating)
) {
    /** TQ1-9 -> ORC-7.6 (TQ.6) -> ZPR.priority fallback, first non-blank wins. */
    val resolvedPriority: String get() =
        tq1?.priority?.takeIf { it.isNotBlank() }
            ?: orc.quantityTiming.priority.takeIf { it.isNotBlank() }
            ?: zpr.firstOrNull()?.priority.orEmpty()
}
```

`OrderGroupAssembler`'s `when` branch (`OrderGroupAssembler.kt:34-40`) gets a
new case bucketing a trailing `TQ1Segment` into the current group, same
pattern as the existing `ZPRSegment` case.

### `SegmentCapabilities` change

Add `"TQ1" to listOf(V25 to 14)` to the per-segment max-fields table
(`SegmentCapabilities.kt`), since TQ1 doesn't exist before v2.5.

## Handling rules (mapped to prompt requirements)

- **Field routing**: TQ parsed from ORC-7 via `ORCSegment.quantityTiming`
  regardless of version (works identically v2.3+, since the composite shape
  doesn't change). TQ1 only meaningfully appears v2.5+; `OrderGroupAssembler`
  will pick it up whenever present in the segment stream (no version gate
  needed at parse time — if a v2.3 message somehow carries a stray TQ1, it
  still parses; that's consistent with the "never throw, just expose what's
  there" convention).
- **Priority resolution**: `OrderGroup.resolvedPriority`, fallback chain
  TQ1.priority -> ORC.quantityTiming.priority -> ZPR.priority (first order's
  ZPR, matching how `zpr` is already a per-group list).
- **Interval fallback**: `TQ.interval` always holds the full raw TQ.2 string;
  `intervalCode`/`explicitTimes` are best-effort structured reads that come
  back blank/empty (never throw) when the text doesn't split the expected way
  — satisfies "if TQ.2 contains non-standard text, gracefully fall back to
  storing it as a raw string."
- **Open-ended vs bounded schedules**: `TQ.isOpenEnded` flags the
  no-TQ.5-and-no-TQ.12 case; when either is present, both `endDateTime` and
  `totalOccurrences` are still parsed as plain strings so downstream code can
  evaluate consistency itself (no cross-field validation added here — out of
  scope, this pass exposes data only).
- **Sequenced chains**: `TQ.isSequential` (TQ.9 == "S") plus `orderSequencing`
  (raw TQ.10 composite) — downstream code establishes the predecessor link;
  this pass does not decode TQ.10's own sub-structure (not specified by the
  prompt beyond "extract it").

## Testing plan

- `TQTest.kt` (new, mirrors `EscapingTest.kt`'s direct-construction style):
  - Standard v2.3/v2.4 ORC-7 with explicit priority, e.g.
    `1^BID^^202609250900^^STAT` -> assert `quantity`, `intervalCode`,
    `startDateTime`, `priority`.
  - Sequenced order: TQ.9=`S`, TQ.10 populated -> `isSequential == true`,
    `orderSequencing` non-blank.
  - Open-ended (`TQ.5`/`TQ.12` both blank) vs bounded by `TQ.5` only vs bounded
    by `TQ.12` only -> `isOpenEnded` true/false/false.
  - TQ.2 non-standard free text (doesn't match `CODE^times` shape) ->
    `interval` holds the raw string, `intervalCode`/`explicitTimes` degrade
    gracefully (blank/empty), no exception.
- Extend `OrderGroupTest.kt` / round-trip tests:
  - A parsed message with ORC + TQ1 -> `group.tq1` populated,
    `resolvedPriority` reads from TQ1 when present.
  - A message with ORC-7 priority but no TQ1 -> `resolvedPriority` falls back
    to `orc.quantityTiming.priority`.
  - A message with neither TQ1 nor ORC-7 priority but a ZPR present ->
    `resolvedPriority` falls back to `zpr.priority`.

## Explicitly deferred (not this pass)

- OBR/RXO segments and their own TQ usage (OBR-27, RXO-21) — added when those
  message flows are built.
- Outbound `tq1 { }` builder DSL sugar.
- Validating `resolvedPriority` against `ValidationConfig.knownPriorities` (or
  a similar allow-list) in `HL7Validator` — flagged as a natural follow-up,
  not requested by the current prompt.
