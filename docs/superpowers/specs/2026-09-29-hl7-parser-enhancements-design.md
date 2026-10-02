# HL7 Parser Enhancements Design

> Branch: `feature/hl7-parser-enhancements`
> Author: bhushan.patil@ritetechnologies.co.in
> Date: 2026-09-29
> Reference: `hl7Specs/` folder (segments/, tables/, messages/)

---

## 1. Goals

1. **Spec accuracy** — correct field indices, names, and data types for 15 standard segments against the project-authoritative specs in `hl7Specs/` (covering v2.3.1, v2.5.1, v2.8.2).
2. **Typed coded fields** — important HL7 coded table fields (ORC-1, MSA-1, ORC-5, EQU state fields, INV status fields, TQ1-9, OBX-11, RXD-11) become sealed classes so callers can branch on known values without string matching.
3. **Numeric fields** — fields whose spec type is NM (numeric) or SI (integer) return `Int` or `Double` where it would help callers; others stay `String`.
4. **Registry cleanup** — ZIN and ZPR unregistered from `SegmentRegistry` auto-init; ZNI and ZUI are completely untouched; ZSN/ZCC/ZSV/ZAD remain opt-in only.
5. **Validator enhancements** — existing `HL7Validator` extended with structural and field-level checks covering all three target message types: `RDE^O11`, `RDE^O25`, `INR^U06`, `INU^U06`, and `ACK`.
6. **AckBuilder enhancements** — existing `AckBuilder` extended to emit `ERR` segments for each `ValidationIssue`.
7. **Comprehensive tests** — per message type (happy path + validation failure + multi-ORC), per typed accessor, per validation rule.

Success criteria:
- All 15 segment classes align with spec reference files — field number, name, and type correct.
- Sealed-class fields compile to exhaustive `when` in client code.
- `HL7Validator.validate(msg)` catches every spec-required error; no false positives on valid messages.
- `AckBuilder.build(msg, result)` produces parseable ACK with correct MSA-1 + ERR segments.
- Test coverage ≥ 90% on all new/modified paths.

---

## 2. Scope

### In scope — message types parsed / validated
| Message | Direction | Notes |
|---------|-----------|-------|
| RDE^O11 | PMS → Library | Pharmacy dispense order; multi-ORC supported |
| RDE^O25 | PMS → Library | Pharmacy refill order; same shape as O11 |
| INR^U06 | PMS → Library | Automated equipment inventory request |
| ACK | Outbound | Built by AckBuilder; never accepted inbound |

### In scope — segments corrected
MSH, PID, PV1, ORC, MSA, NTE, TQ1, RXE, RXD, RXR, RXC, OBX, EQU, INV, BTS

### Not in scope (no changes)
ZNI, ZUI, and existing RDS^O13 / QBP^Q11 / RSP^K11 flows.

---

## 3. Architecture

### 3.1 Sealed class layer — `model/codedfield/`

New package `org.rite.hl7.model.codedfield` containing one sealed class per HL7 table used for conditional logic.

```
OrderControl   — Table 0119 (ORC-1)
AckCode        — Table 0008 (MSA-1)
OrderStatus    — Table 0038 (ORC-5)
ObsResultStatus — Table 0085 (OBX-11)
SubstitutionStatus — Table 0167 (RXD-11)
Priority       — Table 0485 (TQ1-9)
EquipmentState — Table 0365 (EQU-3/4/5)
SubstanceStatus — Table 0383 (INV-2/3)
```

Each sealed class has:
- `Known(val code: String)` subclasses for each value defined in `hl7Specs/tables/`
- `Unknown(val raw: String)` catch-all so parse never throws on unrecognized codes

Pattern (example):
```kotlin
sealed class OrderControl(val code: String) {
    object NW : OrderControl("NW")
    object CA : OrderControl("CA")
    object DC : OrderControl("DC")
    object RF : OrderControl("RF")
    // ... all from Table 0119
    class Unknown(raw: String) : OrderControl(raw)

    companion object {
        fun from(raw: String): OrderControl = when (raw.uppercase()) {
            "NW" -> NW
            "CA" -> CA
            // ...
            else -> Unknown(raw)
        }
    }
}
```

### 3.2 Segment field corrections

Each corrected segment class adds/renames/removes fields to match spec. Only fields directly needed by existing callers or the validator are exposed as named properties; the rest remain accessible via `fieldValue(n)` / `component(n, c)` on the base class.

Key changes per segment (compared to current code):

**MSH** — add `messageStructure` (MSH-9.3), `continuationPointer` (MSH-14), `acceptAcknowledgmentType` (MSH-15), `applicationAcknowledgmentType` (MSH-16); fix `sequenceNumber` type (currently String, stays String per NM→String convention for optional seq).

**PID** — add `patientIdList` repetition accessor (PID-3 repeats), `race` (PID-10), `phoneHome` (PID-13.1), `phoneBusiness` (PID-14.1), `primaryLanguage` (PID-15.2), `maritalStatus` (PID-16), `patientAccountNumber` (PID-18.1).

**PV1** — add `referringDoctorId`/`Name` (PV1-8), `hospitalService` (PV1-10), `readmissionIndicator` (PV1-13), `dischargeDisposition` (PV1-36), `dischargeDatetime` (PV1-45).

**ORC** — `orderControl` property returns `OrderControl` (sealed class) instead of `String`. `orderStatus` returns `OrderStatus` (sealed class). Existing `String` backing remains on `raw` for encode round-trips. Add `orderEffectiveDateTime` (ORC-15), `enteringOrganization` (ORC-17).

**MSA** — `acknowledgmentCode` returns `AckCode` (sealed class). Add `expectedSequenceNumber` (MSA-4), `delayedAcknowledgmentType` (MSA-5), `errorCondition` (MSA-6).

**NTE** — no field index changes; spec-accurate (already correct in v2.3.1+).

**TQ1** — `priority` returns `Priority` (sealed class, Table 0485). Field indices already correct.

**RXE** — fix `giveCode` field index (currently 2→stays correct); add `deaClass` (RXE-25 v2.5.1), `substitutionStatus` (RXE-9) returning `SubstitutionStatus` sealed class. Fix `dispenseAmount` (RXE-10 correct); add `prescribingProvider` (RXE-13).

**RXD** — `substitutionStatus` returns `SubstitutionStatus` (sealed class, Table 0167). Add `pharmacyOrderType` (RXD-26 v2.5.1). Fix field counts per version.

**RXR** — add `administrationMethod` (RXR-4 v2.5.1), `routingInstruction` (RXR-5 v2.5.1). Current indices are correct.

**RXC** — no index changes; add `supplementaryCode` (RXC-7 v2.5.1), `componentDrugStrengthVolume` (RXC-8 v2.5.1).

**OBX** — `resultStatus` returns `ObsResultStatus` (sealed class, Table 0085). Add `effectiveDateOfReferenceRange` (OBX-12), `userDefinedAccessChecks` (OBX-13), `producersId` (OBX-15.1), `equipmentInstance` (OBX-18.1), `dateTimeOfAnalysis` (OBX-19).

**EQU** — `equipmentState` (EQU-3) returns `EquipmentState` (sealed class, Table 0365). Add `localRemoteControlState` (EQU-4), `alertLevel` (EQU-5).

**INV** — `substanceStatus` (INV-2) and `substanceType` (INV-3) return `SubstanceStatus` (sealed class, Table 0383). Correct field numbering — current `deviceItemCode` maps to INV-1 but spec calls it `SubstanceIdentifier`; rename to `substanceIdentifier`. Add `inventoryContainerIdentifier` (INV-3.1), `containerCarrierIdentifier` (INV-4.1), `positionOnCarrier` (INV-5.1), `initialQuantity` (INV-6, NM), `currentQuantity` (INV-7, NM), `availableQuantity` (INV-8, NM), `consumptionQuantity` (INV-9, NM), `onBoardStabilityDuration` (INV-13), `targetValue` (INV-20 v2.5.1).

**BTS** — add `batchMessageCount` (BTS-1), `batchComment` (BTS-2), `batchTotals` (BTS-3). (Currently BTS is a stub or GenericSegment.)

### 3.3 Registry cleanup

In `SegmentRegistry.init {}`, remove `ZINSegment.Definition` and `ZPRSegment.Definition` from the list. The classes remain but are no longer auto-registered.

`ZSN`, `ZCC`, `ZSV`, `ZAD` — already opt-in; no change needed.

`ZNI`, `ZUI` — completely untouched.

### 3.4 Validator enhancements

Extend existing `HL7Validator`:

- **RDE^O25** — add to `DISPENSE_TRIGGERS` set (trigger `O25`); same validation rules as O11.
- **Numeric field-level checks** — for INV quantity fields returned as `Double?`, check non-negative; for RXE quantity, verify parseable number (not arbitrary string).
- **Required field checks for RDE^O25** — same as O11 (ORC-1 coded, ORC-2 present, RXE NDC + qty).
- **INU^U06** — not accepted inbound; `validateSupportedType` rejects it with AR if received.

### 3.5 AckBuilder enhancements

Current `AckBuilder.build()` produces MSA only (no ERR). Add ERR segment generation:

```kotlin
// For each ValidationIssue with severity != ACCEPT, emit one ERR segment:
// ERR-3.1 = errorCode, ERR-3.2 = errorText, ERR-4 = severity char
```

ERR segments appear after MSA in the ACK message. Use existing ERR builder DSL.

---

## 4. Data Flow

```
Raw HL7 text
    └── HL7Parser.parse()
        └── HL7Lexer → HL7Segment[] → SegmentRegistry.wrap()
            └── TypedSegment subclasses
                ├── Segment properties (String / sealed / Double)
                └── HL7Message (segments + version)
                    └── HL7Validator.validate(message)
                        └── ValidationResult (issues + worst severity)
                            └── AckBuilder.build(inbound, result)
                                └── ACK HL7Message (MSH + MSA + ERR[])
```

Sealed-class fields are pure view transforms — they call `from(fieldValue(n))` inside the property getter. No parsing state changes; no extra allocation on fields not accessed.

---

## 5. Error Handling

- Parse never throws or fails on unrecognized coded values — `Unknown(raw)` absorbs them.
- Validation produces a list; callers inspect `result.worst` for ACK code.
- `AckBuilder` tolerates a null inbound header (produces blank sender/receiver fields).
- Version mismatch (e.g. TQ1 in a v2.3.1 message) is caller's concern; the library parses it regardless.

---

## 6. Testing Plan

### Unit tests — new files in `commonTest/kotlin/org/rite/hl7/`

| Test File | Covers |
|-----------|--------|
| `segment/SegmentFieldIndexTest.kt` | Every renamed/added property for all 15 segments using hand-crafted HL7 strings |
| `codedfield/SealedClassTest.kt` | `from()` round-trip for all values including Unknown |
| `validation/RdeO11ValidatorTest.kt` | Happy path, missing ORC, bad NDC, invalid qty, multi-ORC, cancel order |
| `validation/RdeO25ValidatorTest.kt` | Same as O11 with O25 trigger |
| `validation/InrU06ValidatorTest.kt` | Happy path, missing INV, bad NDC, negative qty |
| `validation/AckValidatorTest.kt` | ACK and INU^U06 inbound rejected (unsupported types) |
| `builder/AckBuilderErrTest.kt` | ERR segments emitted per issue; zero issues = no ERR |
| `registry/RegistryCleanupTest.kt` | ZIN/ZPR not registered; ZNI/ZUI still registered |

### Integration tests — existing files
- Extend `MllpBatchTest.kt` to cover multi-ORC RDE^O25 round-trip.

---

## 7. Breaking Changes

- `ORCSegment.orderControl` type changes `String` → `OrderControl`. Callers comparing strings must switch to sealed class.
- `ORCSegment.orderStatus` type changes `String` → `OrderStatus`.
- `MSASegment.acknowledgmentCode` type changes `String` → `AckCode`.
- `OBXSegment.resultStatus` type changes `String` → `ObsResultStatus`.
- `RXDSegment.substitutionStatus` type changes `String` → `SubstitutionStatus`.
- `TQ1Segment.priority` type changes `String` → `Priority`.
- `EQUSegment.equipmentState` type changes `String` → `EquipmentState`.
- `INVSegment.substanceStatus` type changes `String` → `SubstanceStatus`.
- `INVSegment.deviceItemCode` renamed to `substanceIdentifier` (spec alignment).
- ZIN and ZPR no longer auto-registered — callers relying on typed access to these must register manually.

All changes are intentional and acceptable (library not yet published).

---

## 8. Files Touched

**New:**
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/OrderControl.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/AckCode.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/OrderStatus.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/ObsResultStatus.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/SubstitutionStatus.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/Priority.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/EquipmentState.kt`
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/SubstanceStatus.kt`
- Test files (listed in §6)

**Modified:**
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/HeaderSegments.kt` — MSH, PID, PV1, ORC, MSA, NTE
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/PharmacySegments.kt` — RXE, RXD, RXR, RXC, OBX
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/InventorySegments.kt` — EQU, INV, BTS
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/SegmentRegistry.kt` — remove ZIN/ZPR from auto-init
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt` — RDE^O25 + INU^U06 + numeric checks
- `hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/AckBuilder.kt` — ERR segment emission
