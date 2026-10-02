# HL7 Parser Enhancements Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Correct 15 segment field maps against hl7Specs/, add sealed classes for 8 coded HL7 table fields, extend the validator to cover RDE^O25 and numeric field checks, emit ERR segments from AckBuilder, and clean up ZIN/ZPR from auto-registration.

**Architecture:** New `model/codedfield/` package holds one sealed class per HL7 table; segment classes in `HeaderSegments.kt`, `PharmacySegments.kt`, and `InventorySegments.kt` gain new properties and swap String-typed coded fields for the sealed types. `HL7Validator` and `AckBuilder` are extended in place. All existing callers that string-compare coded fields must be migrated in the same task that introduces the sealed class.

**Tech Stack:** Kotlin Multiplatform (commonMain / commonTest), `kotlin.test`, existing `TypedSegment.fieldValue(n)` / `component(n, c)` base-class helpers, existing `HL7Builder` / `AckBuilder` DSL.

**Spec:** `docs/superpowers/specs/2026-09-29-hl7-parser-enhancements-design.md`

## Global Constraints

- Touch only files listed in spec §8 "Files Touched"; do not refactor adjacent code.
- Match existing Kotlin style: `val x: Type get() = …` property pattern for all segment accessors.
- All sealed classes live in package `org.rite.hl7.model.codedfield`.
- `Unknown(val raw: String)` is the catch-all subclass on every sealed class — parse never throws.
- `companion object { fun from(raw: String): T }` on every sealed class.
- ZIN / ZPR classes stay compiled — only their `Definition` is removed from `SegmentRegistry.init`.
- ZNI / ZUI: completely untouched.
- Test files live under `hl7Core/src/commonTest/kotlin/org/rite/hl7/`.
- Run command: `./gradlew :hl7Core:allTests` (use from repo root).

## Review Focus

1. **`Unknown` round-trip** — any unrecognized code string passed to `from()` must survive `sealed.raw == original` without mutation; a normalizing `uppercase()` inside `from()` must not alter what is stored in `Unknown`.
2. **ORC-5 `orderStatus` rename in validator** — `HL7Validator` currently reads `orc.orderControl` (String); after the sealed-class change it reads `orc.orderControl.code` or switches on the sealed type — any missed call site will be a compile error, but verify no string compare survives.
3. **INV `deviceItemCode` → `substanceIdentifier` rename** — `validateInventory` at line 295 of `HL7Validator.kt` calls `inv.deviceItemCode`; that property must be renamed in the same task or the build breaks.
4. **ERR segment count** — `AckBuilder` must emit exactly one ERR per non-ACCEPT `ValidationIssue`; zero issues with severity ACCEPT must produce zero ERR segments; test both extremes.
5. **RDE^O25 trigger coverage** — `DISPENSE_TRIGGERS` adding `"O25"` must be exercised by at least one test that sends a message with `RDE^O25` and asserts it validates (not rejects as unsupported type).

---

## Task 1: Sealed class package — `model/codedfield/`

**Files:**
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/OrderControl.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/AckCode.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/OrderStatus.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/ObsResultStatus.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/SubstitutionStatus.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/Priority.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/EquipmentState.kt`
- Create: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/SubstanceStatus.kt`
- Test: `hl7Core/src/commonTest/kotlin/org/rite/hl7/codedfield/SealedClassTest.kt`

**Interfaces:**
- Produces: 8 sealed classes, each with `val code: String`, a `companion object { fun from(raw: String): <Type> }`, and an `Unknown(val raw: String)` subclass. Later tasks import these via `org.rite.hl7.model.codedfield.*`.

- [ ] **Step 1: Create `OrderControl.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class OrderControl(val code: String) {
    object NW : OrderControl("NW")
    object RF : OrderControl("RF")
    object CA : OrderControl("CA")
    object DC : OrderControl("DC")
    object HD : OrderControl("HD")
    object OH : OrderControl("OH")
    object OK : OrderControl("OK")
    object UA : OrderControl("UA")
    object SC : OrderControl("SC")
    object OC : OrderControl("OC")
    object OD : OrderControl("OD")
    object AF : OrderControl("AF")
    object DF : OrderControl("DF")
    object FU : OrderControl("FU")
    object RP : OrderControl("RP")
    object RO : OrderControl("RO")
    object XO : OrderControl("XO")
    object RE : OrderControl("RE")
    class Unknown(raw: String) : OrderControl(raw)

    companion object {
        fun from(raw: String): OrderControl = when (raw.uppercase()) {
            "NW" -> NW; "RF" -> RF; "CA" -> CA; "DC" -> DC; "HD" -> HD
            "OH" -> OH; "OK" -> OK; "UA" -> UA; "SC" -> SC; "OC" -> OC
            "OD" -> OD; "AF" -> AF; "DF" -> DF; "FU" -> FU; "RP" -> RP
            "RO" -> RO; "XO" -> XO; "RE" -> RE
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 2: Create `AckCode.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class AckCode(val code: String) {
    object AA : AckCode("AA")
    object AE : AckCode("AE")
    object AR : AckCode("AR")
    object CA : AckCode("CA")
    object CE : AckCode("CE")
    object CR : AckCode("CR")
    class Unknown(raw: String) : AckCode(raw)

    companion object {
        fun from(raw: String): AckCode = when (raw.uppercase()) {
            "AA" -> AA; "AE" -> AE; "AR" -> AR
            "CA" -> CA; "CE" -> CE; "CR" -> CR
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 3: Create `OrderStatus.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class OrderStatus(val code: String) {
    object A  : OrderStatus("A")
    object CA : OrderStatus("CA")
    object CM : OrderStatus("CM")
    object DC : OrderStatus("DC")
    object ER : OrderStatus("ER")
    object HD : OrderStatus("HD")
    object IP : OrderStatus("IP")
    object RP : OrderStatus("RP")
    object SC : OrderStatus("SC")
    class Unknown(raw: String) : OrderStatus(raw)

    companion object {
        fun from(raw: String): OrderStatus = when (raw.uppercase()) {
            "A" -> A; "CA" -> CA; "CM" -> CM; "DC" -> DC; "ER" -> ER
            "HD" -> HD; "IP" -> IP; "RP" -> RP; "SC" -> SC
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 4: Create `ObsResultStatus.kt`**

```kotlin
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
    class Unknown(raw: String) : ObsResultStatus(raw)

    companion object {
        fun from(raw: String): ObsResultStatus = when (raw.uppercase()) {
            "C" -> C; "D" -> D; "F" -> F; "I" -> I; "N" -> N; "O" -> O
            "P" -> P; "R" -> R; "S" -> S; "U" -> U; "W" -> W; "X" -> X
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 5: Create `SubstitutionStatus.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class SubstitutionStatus(val code: String) {
    object NoSelection         : SubstitutionStatus("0")
    object NotAllowed          : SubstitutionStatus("1")
    object PatientRequested    : SubstitutionStatus("2")
    object PharmacistSelected  : SubstitutionStatus("3")
    object GenericNotInStock   : SubstitutionStatus("4")
    object BrandAsGeneric      : SubstitutionStatus("5")
    object BrandMandatedByLaw  : SubstitutionStatus("7")
    object GenericNotAvailable : SubstitutionStatus("8")
    object G                   : SubstitutionStatus("G")
    object N                   : SubstitutionStatus("N")
    object T                   : SubstitutionStatus("T")
    class Unknown(raw: String) : SubstitutionStatus(raw)

    companion object {
        fun from(raw: String): SubstitutionStatus = when (raw.uppercase()) {
            "0" -> NoSelection; "1" -> NotAllowed; "2" -> PatientRequested
            "3" -> PharmacistSelected; "4" -> GenericNotInStock; "5" -> BrandAsGeneric
            "7" -> BrandMandatedByLaw; "8" -> GenericNotAvailable
            "G" -> G; "N" -> N; "T" -> T
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 6: Create `Priority.kt`**

```kotlin
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
    class Unknown(raw: String) : Priority(raw)

    companion object {
        fun from(raw: String): Priority = when (raw.uppercase()) {
            "S" -> S; "A" -> A; "R" -> R; "P" -> P; "C" -> C
            "PRN" -> PRN; "T" -> T; "UD" -> UD
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 7: Create `EquipmentState.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class EquipmentState(val code: String) {
    object IN  : EquipmentState("IN")
    object CO  : EquipmentState("CO")
    object PU  : EquipmentState("PU")
    object RS  : EquipmentState("RS")
    object ID  : EquipmentState("ID")
    object OP  : EquipmentState("OP")
    object CL  : EquipmentState("CL")
    object PA  : EquipmentState("PA")
    object PD  : EquipmentState("PD")
    object ES  : EquipmentState("ES")
    object DC  : EquipmentState("DC")
    object DI  : EquipmentState("DI")
    object UNK : EquipmentState("UNK")
    class Unknown(raw: String) : EquipmentState(raw)

    companion object {
        fun from(raw: String): EquipmentState = when (raw.uppercase()) {
            "IN" -> IN; "CO" -> CO; "PU" -> PU; "RS" -> RS; "ID" -> ID
            "OP" -> OP; "CL" -> CL; "PA" -> PA; "PD" -> PD; "ES" -> ES
            "DC" -> DC; "DI" -> DI; "UNK" -> UNK
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 8: Create `SubstanceStatus.kt`**

```kotlin
package org.rite.hl7.model.codedfield

sealed class SubstanceStatus(val code: String) {
    object EW : SubstanceStatus("EW")
    object EE : SubstanceStatus("EE")
    object CW : SubstanceStatus("CW")
    object CE : SubstanceStatus("CE")
    object QW : SubstanceStatus("QW")
    object QE : SubstanceStatus("QE")
    object NW : SubstanceStatus("NW")
    object NE : SubstanceStatus("NE")
    object OW : SubstanceStatus("OW")
    object OE : SubstanceStatus("OE")
    object OK : SubstanceStatus("OK")
    class Unknown(raw: String) : SubstanceStatus(raw)

    companion object {
        fun from(raw: String): SubstanceStatus = when (raw.uppercase()) {
            "EW" -> EW; "EE" -> EE; "CW" -> CW; "CE" -> CE
            "QW" -> QW; "QE" -> QE; "NW" -> NW; "NE" -> NE
            "OW" -> OW; "OE" -> OE; "OK" -> OK
            else -> Unknown(raw)
        }
    }
}
```

- [ ] **Step 9: Write failing tests in `SealedClassTest.kt`**

Create `hl7Core/src/commonTest/kotlin/org/rite/hl7/codedfield/SealedClassTest.kt`:

```kotlin
package org.rite.hl7.codedfield

import org.rite.hl7.model.codedfield.*
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs

class SealedClassTest {

    @Test fun orderControl_known_round_trip() {
        assertEquals("NW", OrderControl.from("NW").code)
        assertEquals("CA", OrderControl.from("CA").code)
        assertIs<OrderControl.NW>(OrderControl.from("NW"))
    }

    @Test fun orderControl_case_insensitive() {
        assertIs<OrderControl.NW>(OrderControl.from("nw"))
    }

    @Test fun orderControl_unknown_preserves_raw() {
        val u = OrderControl.from("ZZ")
        assertIs<OrderControl.Unknown>(u)
        assertEquals("ZZ", u.raw)   // raw preserved, NOT uppercased
        assertEquals("ZZ", u.code)
    }

    @Test fun ackCode_known_round_trip() {
        assertIs<AckCode.AA>(AckCode.from("AA"))
        assertIs<AckCode.AE>(AckCode.from("AE"))
        assertIs<AckCode.AR>(AckCode.from("AR"))
    }

    @Test fun ackCode_unknown_preserves_raw() {
        val u = AckCode.from("XY")
        assertIs<AckCode.Unknown>(u)
        assertEquals("XY", u.raw)
    }

    @Test fun orderStatus_known_round_trip() {
        assertIs<OrderStatus.CM>(OrderStatus.from("CM"))
        assertEquals("CM", OrderStatus.from("CM").code)
    }

    @Test fun orderStatus_unknown() {
        assertIs<OrderStatus.Unknown>(OrderStatus.from("??"))
    }

    @Test fun obsResultStatus_known_round_trip() {
        assertIs<ObsResultStatus.F>(ObsResultStatus.from("F"))
        assertIs<ObsResultStatus.P>(ObsResultStatus.from("P"))
    }

    @Test fun substitutionStatus_known_round_trip() {
        assertIs<SubstitutionStatus.G>(SubstitutionStatus.from("G"))
        assertIs<SubstitutionStatus.NoSelection>(SubstitutionStatus.from("0"))
    }

    @Test fun priority_known_round_trip() {
        assertIs<Priority.S>(Priority.from("S"))
        assertIs<Priority.PRN>(Priority.from("PRN"))
        assertIs<Priority.PRN>(Priority.from("prn"))
    }

    @Test fun equipmentState_known_round_trip() {
        assertIs<EquipmentState.OP>(EquipmentState.from("OP"))
        assertIs<EquipmentState.UNK>(EquipmentState.from("UNK"))
    }

    @Test fun substanceStatus_known_round_trip() {
        assertIs<SubstanceStatus.OK>(SubstanceStatus.from("OK"))
        assertIs<SubstanceStatus.EW>(SubstanceStatus.from("EW"))
    }

    @Test fun substanceStatus_unknown_preserves_raw() {
        val u = SubstanceStatus.from("XX")
        assertIs<SubstanceStatus.Unknown>(u)
        assertEquals("XX", u.raw)
    }
}
```

- [ ] **Step 10: Run tests — verify they fail (classes don't exist yet)**

```
./gradlew :hl7Core:allTests --tests "*.SealedClassTest" 2>&1 | tail -20
```

Expected: compilation failure — packages not found.

- [ ] **Step 11: Verify tests pass after files are created**

```
./gradlew :hl7Core:allTests --tests "*.SealedClassTest" 2>&1 | tail -20
```

Expected: BUILD SUCCESSFUL, all 13 tests pass.

- [ ] **Step 12: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/model/codedfield/ \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/codedfield/SealedClassTest.kt
git commit -m "feat: add sealed-class coded field types for HL7 tables 0008/0038/0085/0119/0167/0365/0383/0485"
```

---

## Task 2: `HeaderSegments.kt` — ORC, MSA, TQ1 coded field upgrades + MSH/PID/PV1 new fields

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/HeaderSegments.kt`
- Test: `hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt` (new file, shared across Tasks 2–4)

**Interfaces:**
- Consumes: `OrderControl`, `OrderStatus`, `AckCode`, `Priority` from Task 1.
- Produces (breaking changes callers must handle):
  - `ORCSegment.orderControl: OrderControl` (was `String`); raw string via `ORCSegment.orderControlRaw: String`
  - `ORCSegment.orderStatus: OrderStatus` (was `String`); raw string via `ORCSegment.orderStatusRaw: String`
  - `MSASegment.acknowledgmentCode: AckCode` (was `String`); raw via `MSASegment.acknowledgmentCodeRaw: String`
  - `TQ1Segment.priority: Priority` (was `String`); raw via `TQ1Segment.priorityRaw: String`
- New non-breaking additions on MSH, PID, PV1, ORC, MSA, NTE (all as new `val` properties).

- [ ] **Step 1: Write failing test for ORC sealed field (in new `SegmentFieldIndexTest.kt`)**

```kotlin
package org.rite.hl7.segment

import org.rite.hl7.model.codedfield.OrderControl
import org.rite.hl7.model.codedfield.OrderStatus
import org.rite.hl7.model.codedfield.AckCode
import org.rite.hl7.model.codedfield.Priority
import org.rite.hl7.model.segment.*
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs

class SegmentFieldIndexTest {

    private fun parse(hl7: String) = HL7Parser().parse(hl7.trimIndent())

    // --- ORC ---
    @Test fun orc_orderControl_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001||CM|||||20240101120000|||DOC001
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertIs<OrderControl.NW>(orc.orderControl)
        assertEquals("NW", orc.orderControl.code)
        assertEquals("NW", orc.orderControlRaw)
    }

    @Test fun orc_orderStatus_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001||CM
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertIs<OrderStatus.CM>(orc.orderStatus)
    }

    @Test fun orc_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001|||||||20240101||||DOC001||20240101130000||ORG001
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertEquals("20240101130000", orc.orderEffectiveDateTime)
        assertEquals("ORG001", orc.enteringOrganization)
    }

    // --- MSA ---
    @Test fun msa_acknowledgmentCode_sealed() {
        val msg = parse("""
            MSH|^~\&|LIB|FAC|PMS|FAC|20240101120000||ACK^R01|CTL001|P|2.5
            MSA|AA|CTL001|OK
        """)
        val msa = msg.segment<MSASegment>(MSASegment.NAME)!!
        assertIs<AckCode.AA>(msa.acknowledgmentCode)
        assertEquals("AA", msa.acknowledgmentCodeRaw)
    }

    // --- TQ1 ---
    @Test fun tq1_priority_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            TQ1|1|||||||20240101|S
        """)
        val tq1 = msg.segment<TQ1Segment>(TQ1Segment.NAME)!!
        assertIs<Priority.S>(tq1.priority)
        assertEquals("S", tq1.priorityRaw)
    }

    // --- MSH new fields ---
    @Test fun msh_new_fields() {
        // MSH-9.3 messageStructure, MSH-14 continuationPointer, MSH-15/16 ack types
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11^RDE_O11|CTL001|P|2.5|||AL|NE
        """)
        val msh = msg.segment<MSHSegment>(MSHSegment.NAME)!!
        assertEquals("RDE_O11", msh.messageStructure)
        assertEquals("AL", msh.acceptAcknowledgmentType)
        assertEquals("NE", msh.applicationAcknowledgmentType)
    }

    // --- PID new fields ---
    @Test fun pid_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            PID|1||MRN001^^^HOS^PI||DOE^JOHN^M|||M||W|123 MAIN ST^^BOSTON^MA^02101^USA||||(617)555-0100|EN|S|1001^^^ACC
        """)
        val pid = msg.segment<PIDSegment>(PIDSegment.NAME)!!
        assertEquals("W", pid.race)
        assertEquals("S", pid.maritalStatus)
        assertEquals("1001", pid.patientAccountNumber)
    }

    // --- PV1 new fields ---
    @Test fun pv1_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            PV1|1|I|W^101^A^GH||||7101^SMITH^JOHN|||MED|||||||||||1234^^^VN|||||||||||||||||20240101|||||20240201
        """)
        val pv1 = msg.segment<PV1Segment>(PV1Segment.NAME)!!
        assertEquals("7101", pv1.referringDoctorId)
        assertEquals("MED", pv1.hospitalService)
    }
}
```

- [ ] **Step 2: Run test — verify fail (new properties don't exist yet)**

```
./gradlew :hl7Core:allTests --tests "*.SegmentFieldIndexTest" 2>&1 | tail -20
```

Expected: compilation error — unresolved references.

- [ ] **Step 3: Update `ORCSegment` in `HeaderSegments.kt`**

Replace the existing `ORCSegment` class body:

```kotlin
import org.rite.hl7.model.codedfield.OrderControl
import org.rite.hl7.model.codedfield.OrderStatus
// (add to file-level imports)

class ORCSegment(raw: HL7Segment) : TypedSegment(raw) {
    val orderControlRaw: String get() = fieldValue(1)
    val orderControl: OrderControl get() = OrderControl.from(orderControlRaw)
    val placerOrderNumber: String get() = component(2, 1)
    val placerOrderNamespace: String get() = component(2, 2)
    val fillerOrderNumber: String get() = component(3, 1)
    val fillerOrderNamespace: String get() = component(3, 2)
    val orderStatusRaw: String get() = fieldValue(5)
    val orderStatus: OrderStatus get() = OrderStatus.from(orderStatusRaw)
    val dateTimeOfTransaction: String get() = fieldValue(9)
    val orderingProviderId: String get() = component(12, 1)
    val orderingProviderFamilyName: String get() = component(12, 2)
    val orderingProviderGivenName: String get() = component(12, 3)
    val orderEffectiveDateTime: String get() = fieldValue(15)
    val orderingFacility: String get() = fieldValue(21)
    val enteringOrganization: String get() = fieldValue(17)
    val quantityTiming: TQ get() = TQ.parse(raw.field(7))

    companion object {
        const val NAME = "ORC"
        val Definition = SegmentDefinition(NAME) { ORCSegment(it) }
    }
}
```

- [ ] **Step 4: Update `MSASegment` in `HeaderSegments.kt`**

```kotlin
import org.rite.hl7.model.codedfield.AckCode
// (add to file-level imports)

class MSASegment(raw: HL7Segment) : TypedSegment(raw) {
    val acknowledgmentCodeRaw: String get() = fieldValue(1)
    val acknowledgmentCode: AckCode get() = AckCode.from(acknowledgmentCodeRaw)
    val messageControlId: String get() = fieldValue(2)
    val textMessage: String get() = fieldValue(3)
    val expectedSequenceNumber: String get() = fieldValue(4)
    val delayedAcknowledgmentType: String get() = fieldValue(5)
    val errorCondition: String get() = fieldValue(6)

    companion object {
        const val NAME = "MSA"
        val Definition = SegmentDefinition(NAME) { MSASegment(it) }
    }
}
```

- [ ] **Step 5: Update `TQ1Segment` in `HeaderSegments.kt`**

```kotlin
import org.rite.hl7.model.codedfield.Priority
// (add to file-level imports)

class TQ1Segment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val quantity: String get() = fieldValue(2)
    val repeatPattern: String get() = fieldValue(3)
    val explicitTime: String get() = fieldValue(4)
    val relativeTimeAndUnits: String get() = fieldValue(5)
    val serviceDuration: String get() = fieldValue(6)
    val startDateTime: String get() = fieldValue(7)
    val endDateTime: String get() = fieldValue(8)
    val priorityRaw: String get() = fieldValue(9)
    val priority: Priority get() = Priority.from(priorityRaw)
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

- [ ] **Step 6: Update `MSHSegment` — add new properties**

Add to `MSHSegment` class body (after `countryCode`):

```kotlin
val messageStructure: String get() = component(9, 3)       // MSH-9.3
val continuationPointer: String get() = fieldValue(14)      // MSH-14
val acceptAcknowledgmentType: String get() = fieldValue(15) // MSH-15
val applicationAcknowledgmentType: String get() = fieldValue(16) // MSH-16
```

- [ ] **Step 7: Update `PIDSegment` — add new properties**

Add to `PIDSegment` class body (after `country`):

```kotlin
val race: String get() = fieldValue(10)
val phoneHome: String get() = component(13, 1)
val phoneBusiness: String get() = component(14, 1)
val primaryLanguage: String get() = component(15, 2)
val maritalStatus: String get() = fieldValue(16)
val patientAccountNumber: String get() = component(18, 1)
```

Also add a helper for repeating PID-3 (list of patient IDs):
```kotlin
fun patientIdList(): List<String> = raw.field(3).repetitions.map { it.components.firstOrNull()?.subcomponents?.firstOrNull() ?: "" }
```

- [ ] **Step 8: Update `PV1Segment` — add new properties**

Add to `PV1Segment` class body (after `admitDateTime`):

```kotlin
val referringDoctorId: String get() = component(8, 1)
val referringDoctorFamilyName: String get() = component(8, 2)
val hospitalService: String get() = fieldValue(10)
val readmissionIndicator: String get() = fieldValue(13)
val dischargeDisposition: String get() = fieldValue(36)
val dischargeDatetime: String get() = fieldValue(45)
```

- [ ] **Step 9: Fix `HL7Validator.kt` — update ORC string comparisons to use `.code`**

In `HL7Validator.kt`, `validateOrderGroup()` currently reads:
- `val control = orc.orderControl` (line ~178) — this is now `OrderControl`, not `String`
- `if (control !in config.knownOrderControlCodes)` — must change to `control.code`
- `if (control == "CA") return` — must change to `if (control is OrderControl.CA) return`

Make these changes:

```kotlin
private fun validateOrderGroup(...) {
    // ...
    val control = orc.orderControl       // now OrderControl sealed type
    if (control.code !in config.knownOrderControlCodes) {
        issues += ValidationIssue(...)
    }
    if (orc.placerOrderNumber.isBlank()) { ... }
    if (control is OrderControl.CA) return   // was: control == "CA"
    // rest unchanged
}
```

- [ ] **Step 10: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. `SegmentFieldIndexTest` ORC/MSA/TQ1/MSH/PID/PV1 tests pass. Existing `ValidationTest` must still pass.

- [ ] **Step 11: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/HeaderSegments.kt \
        hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt
git commit -m "feat: upgrade ORC/MSA/TQ1 to sealed coded fields; add MSH/PID/PV1 new accessors"
```

---

## Task 3: `PharmacySegments.kt` — RXE, RXD, OBX coded field upgrades + RXR/RXC new fields

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/PharmacySegments.kt`
- Modify: `hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt` (extend)

**Interfaces:**
- Consumes: `SubstitutionStatus`, `ObsResultStatus` from Task 1.
- Produces (breaking changes):
  - `RXDSegment.substitutionStatus: SubstitutionStatus` (was `String`); raw via `substitutionStatusRaw: String`
  - `OBXSegment.resultStatus: ObsResultStatus` (was `String`); raw via `resultStatusRaw: String`
- New non-breaking additions on RXE, RXR, RXC.

- [ ] **Step 1: Add RXD/OBX/RXE tests to `SegmentFieldIndexTest.kt`**

Add inside `SegmentFieldIndexTest`:

```kotlin
import org.rite.hl7.model.codedfield.SubstitutionStatus
import org.rite.hl7.model.codedfield.ObsResultStatus

// --- RXD ---
@Test fun rxd_substitutionStatus_sealed() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        RXD|1|00069015505^Drug^NDC|20240101|30|EA||RX001|||10|G
    """)
    val rxd = msg.segment<RXDSegment>(RXDSegment.NAME)!!
    assertIs<SubstitutionStatus.G>(rxd.substitutionStatus)
    assertEquals("G", rxd.substitutionStatusRaw)
}

@Test fun rxd_new_field() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        RXD|1|00069015505^Drug^NDC|20240101|30|EA||RX001|||10|G||||||||||||||||||||||BP
    """)
    val rxd = msg.segment<RXDSegment>(RXDSegment.NAME)!!
    assertEquals("BP", rxd.pharmacyOrderType)
}

// --- OBX ---
@Test fun obx_resultStatus_sealed() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        OBX|1|NM|HEIGHT^Height^L||180|cm|||||F
    """)
    val obx = msg.segment<OBXSegment>(OBXSegment.NAME)!!
    assertIs<ObsResultStatus.F>(obx.resultStatus)
    assertEquals("F", obx.resultStatusRaw)
}

@Test fun obx_new_fields() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        OBX|1|NM|HT^Height^L|SUB1|180|cm|100-200||||F|20240101|ACCESS|PROD001|RESP001|RESP001|EQ001|OBS001|METHOD|20240101130000
    """)
    val obx = msg.segment<OBXSegment>(OBXSegment.NAME)!!
    assertEquals("20240101", obx.effectiveDateOfReferenceRange)
    assertEquals("PROD001", obx.producersId)
}

// --- RXR ---
@Test fun rxr_new_fields() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        RXR|PO^Oral^HL70162|M^Mouth^HL70163|SPR|SLOW|ROUTING_NOTE
    """)
    val rxr = msg.segment<RXRSegment>(RXRSegment.NAME)!!
    assertEquals("SLOW", rxr.administrationMethod)
    assertEquals("ROUTING_NOTE", rxr.routingInstruction)
}

// --- RXC ---
@Test fun rxc_new_fields() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        RXC|A|00069015505^Drug^NDC|1|TAB||SUPP|DSV|5.0
    """)
    val rxc = msg.segment<RXCSegment>(RXCSegment.NAME)!!
    assertEquals("SUPP", rxc.supplementaryCode)
    assertEquals("5.0", rxc.componentDrugStrengthVolume)
}

// --- RXE ---
@Test fun rxe_new_fields() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        RXE||00069015505^Drug^NDC|30|60|TAB||||||G|30|TAB|3|15|RX001|||||||||||||DEA_CLASS|DR001
    """)
    val rxe = msg.segment<RXESegment>(RXESegment.NAME)!!
    assertEquals("DEA_CLASS", rxe.deaClass)
    assertEquals("DR001", rxe.prescribingProvider)
}
```

- [ ] **Step 2: Run test — verify fail**

```
./gradlew :hl7Core:allTests --tests "*.SegmentFieldIndexTest" 2>&1 | tail -20
```

Expected: compilation errors for new properties.

- [ ] **Step 3: Update `RXDSegment` in `PharmacySegments.kt`**

```kotlin
import org.rite.hl7.model.codedfield.SubstitutionStatus
// (add to file-level imports)

class RXDSegment(raw: HL7Segment) : TypedSegment(raw) {
    val dispenseSubIdCounter: String get() = fieldValue(1)
    val dispenseGiveCode: String get() = component(2, 1)
    val dispenseGiveName: String get() = component(2, 2)
    val dispenseGiveCodeSystem: String get() = component(2, 3)
    val dateTimeDispensed: String get() = fieldValue(3)
    val actualDispenseAmount: String get() = fieldValue(4)
    val actualDispenseUnits: String get() = component(5, 1)
    val actualDispenseUnitsText: String get() = component(5, 2)
    val actualDosageFormCode: String get() = component(6, 1)
    val prescriptionNumber: String get() = fieldValue(7)
    val dispensingProviderId: String get() = component(10, 1)
    val substitutionStatusRaw: String get() = fieldValue(11)
    val substitutionStatus: SubstitutionStatus get() = SubstitutionStatus.from(substitutionStatusRaw)
    val lotNumber: String get() = fieldValue(15)
    val expirationDate: String get() = fieldValue(16)
    val substanceManufacturerName: String get() = component(17, 2)
    val pharmacyOrderType: String get() = fieldValue(26)   // RXD-26 v2.5.1

    companion object {
        const val NAME = "RXD"
        val Definition = SegmentDefinition(NAME) { RXDSegment(it) }
    }
}
```

- [ ] **Step 4: Update `OBXSegment` in `PharmacySegments.kt`**

```kotlin
import org.rite.hl7.model.codedfield.ObsResultStatus
// (add to file-level imports)

class OBXSegment(raw: HL7Segment) : TypedSegment(raw) {
    val setId: String get() = fieldValue(1)
    val valueType: String get() = fieldValue(2)
    val observationId: String get() = component(3, 1)
    val observationText: String get() = component(3, 2)
    val observationCodeSystem: String get() = component(3, 3)
    val observationSubId: String get() = fieldValue(4)
    val observationValue: String get() = fieldValue(5)
    val units: String get() = component(6, 1)
    val referenceRange: String get() = fieldValue(7)
    val abnormalFlags: String get() = fieldValue(8)
    val resultStatusRaw: String get() = fieldValue(11)
    val resultStatus: ObsResultStatus get() = ObsResultStatus.from(resultStatusRaw)
    val dateTimeOfObservation: String get() = fieldValue(14)
    val responsibleObserver: String get() = component(16, 1)
    val observationMethod: String get() = fieldValue(17)
    val effectiveDateOfReferenceRange: String get() = fieldValue(12)
    val userDefinedAccessChecks: String get() = fieldValue(13)
    val producersId: String get() = component(15, 1)
    val equipmentInstance: String get() = component(18, 1)
    val dateTimeOfAnalysis: String get() = fieldValue(19)

    companion object {
        const val NAME = "OBX"
        val Definition = SegmentDefinition(NAME) { OBXSegment(it) }
    }
}
```

- [ ] **Step 5: Update `RXRSegment` — add new properties**

Add to `RXRSegment` body (after `administrationDeviceText`):

```kotlin
val administrationMethod: String get() = fieldValue(4)   // RXR-4 v2.5.1
val routingInstruction: String get() = fieldValue(5)     // RXR-5 v2.5.1
```

- [ ] **Step 6: Update `RXCSegment` — add new properties**

Add to `RXCSegment` body (after `componentStrengthUnits`):

```kotlin
val supplementaryCode: String get() = fieldValue(7)              // RXC-7 v2.5.1
val componentDrugStrengthVolume: String get() = fieldValue(8)    // RXC-8 v2.5.1
```

- [ ] **Step 7: Update `RXESegment` — add new properties**

Add to `RXESegment` body (after `prescriptionNumber`):

```kotlin
val deaClass: String get() = fieldValue(25)           // RXE-25 v2.5.1
val prescribingProvider: String get() = fieldValue(13) // RXE-13
```

Also add `substitutionStatus` (RXE-9) — note this re-uses `SubstitutionStatus`:

```kotlin
val substitutionStatusRaw: String get() = fieldValue(9)
val substitutionStatus: SubstitutionStatus get() = SubstitutionStatus.from(substitutionStatusRaw)
```

- [ ] **Step 8: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. All `SegmentFieldIndexTest` cases pass. No regressions.

- [ ] **Step 9: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/PharmacySegments.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt
git commit -m "feat: upgrade RXD/OBX to sealed coded fields; add RXE/RXR/RXC v2.5.1 accessors"
```

---

## Task 4: `InventorySegments.kt` — EQU/INV coded field upgrades + INV rename + BTS already done

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/InventorySegments.kt`
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt` (fix `deviceItemCode` → `substanceIdentifier`)
- Modify: `hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt` (extend)

**Interfaces:**
- Consumes: `EquipmentState`, `SubstanceStatus` from Task 1.
- Produces (breaking changes):
  - `EQUSegment.equipmentState: EquipmentState` (was `String`); raw via `equipmentStateRaw: String`
  - `INVSegment.substanceStatus: SubstanceStatus` (was none — new typed accessor for INV-2 status field in device-sync layout)
  - `INVSegment.deviceItemCode` renamed to `INVSegment.substanceIdentifier` (spec alignment, breaks `HL7Validator.validateInventory`)
- BTS already has `batchMessageCount`, `batchComment`, `batchTotals` — no change needed (already implemented).

- [ ] **Step 1: Add EQU/INV tests to `SegmentFieldIndexTest.kt`**

```kotlin
import org.rite.hl7.model.codedfield.EquipmentState
import org.rite.hl7.model.codedfield.SubstanceStatus

// --- EQU ---
@Test fun equ_equipmentState_sealed() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
        EQU|EQ001^Robot1^L|20240101120000|OP|L|W
    """)
    val equ = msg.segment<EQUSegment>(EQUSegment.NAME)!!
    assertIs<EquipmentState.OP>(equ.equipmentState)
    assertEquals("OP", equ.equipmentStateRaw)
    assertEquals("L", equ.localRemoteControlState)
    assertEquals("W", equ.alertLevel)
}

// --- INV ---
@Test fun inv_substanceIdentifier_renamed() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
        INV|NDC001^LISINOPRIL^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
    """)
    val inv = msg.segment<INVSegment>(INVSegment.NAME)!!
    assertEquals("NDC001", inv.substanceIdentifier)   // was deviceItemCode
}

@Test fun inv_substanceStatus_sealed() {
    val msg = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
        INV|NDC001^LISINOPRIL^L|EW^Expired Warning^HL70383|DRUG^Drug^HL70384
    """)
    val inv = msg.segment<INVSegment>(INVSegment.NAME)!!
    assertIs<SubstanceStatus.EW>(inv.substanceStatus)
    assertEquals("EW", inv.substanceStatus.code)
}
```

- [ ] **Step 2: Run test — verify fail**

```
./gradlew :hl7Core:allTests --tests "*.SegmentFieldIndexTest" 2>&1 | tail -20
```

Expected: compilation error — `substanceIdentifier` / `substanceStatus` / `equipmentStateRaw` not found.

- [ ] **Step 3: Update `EQUSegment` in `InventorySegments.kt`**

```kotlin
import org.rite.hl7.model.codedfield.EquipmentState
// (add to file-level imports)

class EQUSegment(raw: HL7Segment) : TypedSegment(raw) {
    private val idField: Int get() = if (component(1, 2).isBlank() && component(2, 2).isNotBlank()) 2 else 1

    val equipmentId: String get() = component(idField, 1)
    val eventDateTime: String get() = fieldValue(idField + 1)
    val equipmentStateRaw: String get() = fieldValue(idField + 2)
    val equipmentState: EquipmentState get() = EquipmentState.from(equipmentStateRaw)
    val localRemoteControlState: String get() = fieldValue(idField + 3)
    val alertLevel: String get() = fieldValue(idField + 4)

    companion object {
        const val NAME = "EQU"
        val Definition = SegmentDefinition(NAME) { EQUSegment(it) }
    }
}
```

- [ ] **Step 4: Update `INVSegment` in `InventorySegments.kt`**

Rename `deviceItemCode` → `substanceIdentifier` and add typed `substanceStatus`:

```kotlin
import org.rite.hl7.model.codedfield.SubstanceStatus
// (add to file-level imports)

// In INVSegment, replace:
//   val deviceItemCode: String get() = component(1, 1)
// with:
    val substanceIdentifier: String get() = component(1, 1)
    val substanceStatus: SubstanceStatus get() = SubstanceStatus.from(component(2, 1))
```

Keep all other existing properties unchanged. `deviceItemCode` is entirely removed (the validator is the only caller and will be fixed next step).

- [ ] **Step 5: Fix `HL7Validator.kt` — rename `deviceItemCode` → `substanceIdentifier`**

In `HL7Validator.kt`, `validateInventory()` (around line 295–305):

```kotlin
// Replace:
//   inv.deviceItemCode.isBlank()  →  inv.substanceIdentifier.isBlank()
//   !isValidNdc(inv.deviceItemCode)  →  !isValidNdc(inv.substanceIdentifier)

when {
    inv.substanceIdentifier.isBlank() -> issues += ValidationIssue(
        AckSeverity.REJECT, "Missing NDC in INV $position", "INV", "1", "445",
    )
    !isValidNdc(inv.substanceIdentifier) -> issues += ValidationIssue(
        AckSeverity.REJECT, "Invalid NDC in INV $position", "INV", "1", "445",
    )
}
```

Also fix references in `validateInventorySync()` (around line 321–325):

```kotlin
// Replace deviceItemCode → substanceIdentifier in both when-branches that reference it
```

- [ ] **Step 6: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. All tests pass (including existing `ValidationTest` and `RdsDispenseAndInventoryTest`).

- [ ] **Step 7: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/model/segment/InventorySegments.kt \
        hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/segment/SegmentFieldIndexTest.kt
git commit -m "feat: upgrade EQU/INV to sealed coded fields; rename INVSegment.deviceItemCode to substanceIdentifier"
```

---

## Task 5: Registry cleanup — remove ZIN/ZPR from auto-init

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/model/SegmentRegistry.kt`
- Create: `hl7Core/src/commonTest/kotlin/org/rite/hl7/registry/RegistryCleanupTest.kt`

**Interfaces:**
- No interface changes. `ZINSegment` and `ZPRSegment` classes remain; only their `Definition` is removed from `SegmentRegistry.init`.

- [ ] **Step 1: Write failing test**

```kotlin
package org.rite.hl7.registry

import org.rite.hl7.model.SegmentRegistry
import org.rite.hl7.model.segment.ZNISegment
import org.rite.hl7.model.segment.ZUISegment
import kotlin.test.Test
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class RegistryCleanupTest {

    @Test fun zin_not_auto_registered() {
        val registry = SegmentRegistry()
        assertFalse(registry.isRegistered("ZIN"), "ZIN must not be auto-registered")
    }

    @Test fun zpr_not_auto_registered() {
        val registry = SegmentRegistry()
        assertFalse(registry.isRegistered("ZPR"), "ZPR must not be auto-registered")
    }

    @Test fun zni_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZNISegment.NAME), "ZNI must remain registered")
    }

    @Test fun zui_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZUISegment.NAME), "ZUI must remain registered")
    }
}
```

- [ ] **Step 2: Run test — verify fail (ZIN/ZPR currently registered)**

```
./gradlew :hl7Core:allTests --tests "*.RegistryCleanupTest" 2>&1 | tail -20
```

Expected: `zin_not_auto_registered` and `zpr_not_auto_registered` FAIL.

- [ ] **Step 3: Remove ZIN/ZPR from `SegmentRegistry.init`**

In `SegmentRegistry.kt`, remove `ZINSegment.Definition` and `ZPRSegment.Definition` from the `listOf(...)` in `init`. Leave the `import` lines if they are still needed elsewhere (they are not — remove unused imports too).

Resulting `init` block (showing only the changed list, keep all others):

```kotlin
init {
    listOf(
        MSHSegment.Definition, PIDSegment.Definition, PV1Segment.Definition,
        ORCSegment.Definition, MSASegment.Definition, ERRSegment.Definition,
        NTESegment.Definition, RXESegment.Definition, RXDSegment.Definition,
        RXCSegment.Definition, RXRSegment.Definition, OBXSegment.Definition,
        EQUSegment.Definition, INVSegment.Definition, QPDSegment.Definition,
        RCPSegment.Definition, QAKSegment.Definition,
        ZNISegment.Definition, ZUISegment.Definition,
        BTSSegment.Definition, TQ1Segment.Definition,
    ).forEach { register(it) }
}
```

- [ ] **Step 4: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. `RegistryCleanupTest` all green. No regressions — existing tests that use ZIN/ZPR segments via the builder still build them fine (builder writes raw; registry is for parsing typed views only).

- [ ] **Step 5: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/model/SegmentRegistry.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/registry/RegistryCleanupTest.kt
git commit -m "feat: unregister ZIN and ZPR from SegmentRegistry auto-init"
```

---

## Task 6: Validator enhancements — RDE^O25 + INU^U06 rejection + numeric INV checks

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt`
- Create: `hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/RdeO25ValidatorTest.kt`
- Create: `hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/AckValidatorTest.kt`
- Modify: `hl7Core/src/commonTest/kotlin/org/rite/hl7/ValidationTest.kt` (add INU^U06 inbound-rejection test)

**Interfaces:**
- Consumes: no new types.
- Produces: `DISPENSE_TRIGGERS` gains `"O25"`; `validateSupportedType` rejects `INU^U06`.

- [ ] **Step 1: Write failing tests in `RdeO25ValidatorTest.kt`**

```kotlin
package org.rite.hl7.validation

import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class RdeO25ValidatorTest {

    private val validator = HL7Validator()
    private fun parse(hl7: String) = HL7Parser().parse(hl7.trimIndent())

    private val validRdeO25 = """
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
        PID|1||MRN001|||DOE^JOHN
        ORC|RF|RX001
        RXE||00069015505^Lisinopril^NDC|30|60|TAB||||||N|30|TAB|3|RX001
        RXR|PO^Oral^HL70162
    """

    @Test fun happy_path_rde_o25() {
        val result = validator.validate(parse(validRdeO25))
        assertTrue(result.isValid, "RDE^O25 valid message must pass; issues=${result.issues}")
    }

    @Test fun missing_orc_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            PID|1||MRN001
            RXE||00069015505^Lisinopril^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "ORC" })
    }

    @Test fun invalid_ndc_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||BADNDC^Lisinopril^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "RXE" })
    }

    @Test fun invalid_qty_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||00069015505^Lisinopril^NDC|0|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "RXE" })
    }

    @Test fun multi_orc_all_validated() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O25|CTL001|P|2.5
            ORC|RF|RX001
            RXE||00069015505^Lisi^NDC|30|60|TAB
            ORC|RF|RX002
            RXE||BADNDC^Bad^NDC|30|60|TAB
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT })
    }
}
```

- [ ] **Step 2: Write failing tests in `AckValidatorTest.kt`**

```kotlin
package org.rite.hl7.validation

import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertTrue

class AckValidatorTest {

    private val validator = HL7Validator()
    private fun parse(hl7: String) = HL7Parser().parse(hl7.trimIndent())

    @Test fun ack_inbound_rejected() {
        val msg = parse("""
            MSH|^~\&|LIB|FAC|PMS|FAC|20240101120000||ACK^R01|CTL001|P|2.5
            MSA|AA|CTL001
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT })
    }

    @Test fun inu_u06_inbound_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INU^U06|CTL001|P|2.5
            EQU|EQ001|20240101
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT },
            "INU^U06 must be rejected; issues=${result.issues}")
    }
}
```

- [ ] **Step 3: Run tests — verify they fail**

```
./gradlew :hl7Core:allTests --tests "*.RdeO25ValidatorTest" --tests "*.AckValidatorTest" 2>&1 | tail -20
```

Expected: `happy_path_rde_o25` fails (O25 not in DISPENSE_TRIGGERS); `inu_u06_inbound_rejected` may pass or fail depending on current `HL7MessageKind`.

- [ ] **Step 4: Check `HL7MessageKind` to verify INU^U06 mapping**

```bash
grep -n "INU\|U06" /Users/bhushanrite/Downloads/PillCount-Hl7/hl7Core/src/commonMain/kotlin/org/rite/hl7/model/HL7MessageKind.kt
```

Verify that `INU^U06` maps to a kind that is NOT `UNKNOWN`. If it does map to `INVENTORY_UPDATE`, it bypasses `validateSupportedType` — in that case, add an explicit check for `INU` inbound to `validateSupportedType`.

- [ ] **Step 5: Add `"O25"` to `DISPENSE_TRIGGERS` in `HL7Validator.kt`**

```kotlin
private val DISPENSE_TRIGGERS = setOf("O11", "O01", "001", "O25")
```

- [ ] **Step 6: Add INU^U06 inbound rejection to `validateSupportedType`**

In `validateSupportedType`, before the existing kind-check, add:

```kotlin
// INU^U06 is outbound only (inventory update sent by library to PMS); reject inbound
if (message.messageCode.uppercase() == "INU" && message.triggerEvent.uppercase() == "U06") {
    issues += ValidationIssue(
        AckSeverity.REJECT,
        "Unsupported message type ${message.messageCode}^${message.triggerEvent}",
        "MSH", "9", "500",
    )
    return
}
```

- [ ] **Step 7: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. `RdeO25ValidatorTest` and `AckValidatorTest` all green. Existing `ValidationTest` still passes.

- [ ] **Step 8: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/HL7Validator.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/RdeO25ValidatorTest.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/AckValidatorTest.kt
git commit -m "feat: add RDE^O25 to dispense triggers; reject INU^U06 inbound"
```

---

## Task 7: AckBuilder — emit ERR segments per ValidationIssue

**Files:**
- Modify: `hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/AckBuilder.kt`
- Create: `hl7Core/src/commonTest/kotlin/org/rite/hl7/builder/AckBuilderErrTest.kt`

**Interfaces:**
- Consumes: `ValidationResult`, `ValidationIssue`, `AckSeverity` (all existing).
- Consumes: `HL7Builder.ack {}` DSL — need to confirm `ERRBuilder` is accessible in `AckScope`. Check `MessageScopes.kt` for `AckScope`.
- Produces: `AckBuilder.build()` now appends one ERR segment per non-ACCEPT issue after MSA.

- [ ] **Step 1: Check AckScope to understand available DSL**

Read `hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/MessageScopes.kt` — find `AckScope` and what segment builders it exposes. The ERR builder is `ERRBuilder` in `SegmentBuilders.kt`.

```bash
grep -n "AckScope\|err\|ERR" /Users/bhushanrite/Downloads/PillCount-Hl7/hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/MessageScopes.kt
grep -n "class ERRBuilder\|fun err" /Users/bhushanrite/Downloads/PillCount-Hl7/hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/SegmentBuilders.kt
```

If `AckScope` does not have an `err {}` builder, add one (see Step 3 note below).

- [ ] **Step 2: Write failing test in `AckBuilderErrTest.kt`**

```kotlin
package org.rite.hl7.builder

import org.rite.hl7.model.segment.ERRSegment
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.validation.*
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class AckBuilderErrTest {

    private val ackBuilder = AckBuilder()
    private fun parse(hl7: String) = HL7Parser().parse(hl7.trimIndent())

    private val inbound = parse("""
        MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
        ORC|NW|RX001
    """)

    @Test fun zero_issues_no_err_segments() {
        val result = ValidationResult(emptyList())
        val ack = ackBuilder.build(inbound, result)
        assertTrue(ack.segments<ERRSegment>(ERRSegment.NAME).isEmpty(),
            "No ERR segments expected for empty issue list")
    }

    @Test fun one_reject_issue_one_err_segment() {
        val result = ValidationResult(listOf(
            ValidationIssue(AckSeverity.REJECT, "Missing NDC", "RXE", "2", "301")
        ))
        val ack = ackBuilder.build(inbound, result)
        val errors = ack.segments<ERRSegment>(ERRSegment.NAME)
        assertEquals(1, errors.size)
        assertEquals("301", errors[0].errorCode)
        assertEquals("Missing NDC", errors[0].errorText)
        assertEquals("E", errors[0].severity)   // REJECT maps to "E" per spec §3.5 AckBuilder
    }

    @Test fun two_issues_two_err_segments() {
        val result = ValidationResult(listOf(
            ValidationIssue(AckSeverity.REJECT, "Bad NDC", "RXE", "2", "301"),
            ValidationIssue(AckSeverity.ERROR, "Missing comment", "ZAD", "6", "206"),
        ))
        val ack = ackBuilder.build(inbound, result)
        assertEquals(2, ack.segments<ERRSegment>(ERRSegment.NAME).size)
    }

    @Test fun accept_issue_not_emitted_as_err() {
        val result = ValidationResult(listOf(
            ValidationIssue(AckSeverity.ACCEPT, "All good", null, null, null)
        ))
        val ack = ackBuilder.build(inbound, result)
        assertTrue(ack.segments<ERRSegment>(ERRSegment.NAME).isEmpty())
    }

    @Test fun msa_code_matches_worst_severity() {
        val result = ValidationResult(listOf(
            ValidationIssue(AckSeverity.REJECT, "Bad NDC", "RXE", "2", "301")
        ))
        val ack = ackBuilder.build(inbound, result)
        val msa = ack.segment<org.rite.hl7.model.segment.MSASegment>(
            org.rite.hl7.model.segment.MSASegment.NAME)!!
        assertEquals("AR", msa.acknowledgmentCodeRaw)
    }
}
```

**Note on severity mapping:** Per spec §3.5 the ERR-4 severity character is `"E"` for both ERROR and REJECT (they map differently at the MSA level, but ERR-4 uses `"E"` for error conditions). Verify in existing `ERRBuilder` what values it accepts — adjust the test assertion to match the actual value the codebase uses.

- [ ] **Step 3: Run test — verify fail**

```
./gradlew :hl7Core:allTests --tests "*.AckBuilderErrTest" 2>&1 | tail -20
```

Expected: compilation error (ERR emission not implemented) or assertion failures.

- [ ] **Step 4: Inspect `AckScope` and `ERRBuilder`**

Read `MessageScopes.kt` fully to find `AckScope`. Read `SegmentBuilders.kt` to find `ERRBuilder` fields. If `AckScope` lacks `err {}`, add:

In `MessageScopes.kt`, inside `AckScope`:
```kotlin
fun err(block: ERRBuilder.() -> Unit) { addBuilder(ERRBuilder().apply { block() }) }
```

- [ ] **Step 5: Update `AckBuilder.build()` to emit ERR segments**

```kotlin
fun build(inbound: HL7Message, result: ValidationResult): HL7Message {
    val h = inbound.header
    val controlId = h?.messageControlId ?: ""
    val firstFailure = result.issues.firstOrNull { it.severity != AckSeverity.ACCEPT }

    return builder.ack {
        msh {
            it.sendingApplication = h?.receivingApplication ?: ""
            it.sendingFacility = h?.receivingFacility ?: ""
            it.receivingApplication = h?.sendingApplication ?: ""
            it.receivingFacility = h?.sendingFacility ?: ""
            it.dateTimeOfMessage = HL7Date.now()
            it.messageControlId = controlId
            it.processingId = h?.processingId ?: "P"
            it.versionId = h?.versionId
        }
        msa {
            it.acknowledgmentCode = result.worst.code
            it.messageControlId = controlId
            it.textMessage = firstFailure?.errorText
        }
        for (issue in result.issues) {
            if (issue.severity == AckSeverity.ACCEPT) continue
            err {
                it.errorCode = issue.errorCode ?: ""
                it.errorText = issue.errorText
                it.severity = "E"                      // ERR-4: "E" = error per HL7 v2.5 Table 0516
                it.segmentId = issue.segmentId ?: ""
                it.fieldPosition = issue.fieldPosition ?: ""
            }
        }
    }
}
```

**Note:** Check `ERRBuilder` field names. The existing `ERRBuilder` in `SegmentBuilders.kt` may use different property names — use exact names from the class.

- [ ] **Step 6: Run all tests**

```
./gradlew :hl7Core:allTests 2>&1 | tail -30
```

Expected: BUILD SUCCESSFUL. `AckBuilderErrTest` all green. Existing `BuildTest` / `RoundTripTest` still pass.

- [ ] **Step 7: Commit**

```bash
git add hl7Core/src/commonMain/kotlin/org/rite/hl7/validation/AckBuilder.kt \
        hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/MessageScopes.kt \
        hl7Core/src/commonTest/kotlin/org/rite/hl7/builder/AckBuilderErrTest.kt
git commit -m "feat: AckBuilder emits ERR segments for each non-ACCEPT ValidationIssue"
```

---

## Task 8: Validator tests — INR^U06 happy path + failure cases

**Files:**
- Create: `hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/InrU06ValidatorTest.kt`

**Interfaces:**
- Consumes: existing `HL7Validator`, `HL7Parser`, `AckSeverity`.

- [ ] **Step 1: Write the test file**

```kotlin
package org.rite.hl7.validation

import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class InrU06ValidatorTest {

    private val validator = HL7Validator()
    private fun parse(hl7: String) = HL7Parser().parse(hl7.trimIndent())

    @Test fun happy_path_inr_u06() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            EQU|EQ001^Robot1^L|20240101120000|OP
            INV|NDC001^LISINOPRIL^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """)
        val result = validator.validate(msg)
        assertTrue(result.isValid, "INR^U06 with valid INV must pass; issues=${result.issues}")
    }

    @Test fun missing_inv_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            EQU|EQ001^Robot1^L|20240101120000|OP
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" })
    }

    @Test fun invalid_ndc_in_inv_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|BADNDC^Bad Drug^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" })
    }

    @Test fun missing_status_in_inv_rejected() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|NDC001^LISINOPRIL^L||DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """)
        val result = validator.validate(msg)
        assertTrue(result.issues.any { it.severity == AckSeverity.REJECT && it.segmentId == "INV" })
    }
}
```

- [ ] **Step 2: Run test**

```
./gradlew :hl7Core:allTests --tests "*.InrU06ValidatorTest" 2>&1 | tail -20
```

Expected: BUILD SUCCESSFUL, all 4 tests pass (INR^U06 validation was already implemented; this confirms it works with `substanceIdentifier` rename).

- [ ] **Step 3: Commit**

```bash
git add hl7Core/src/commonTest/kotlin/org/rite/hl7/validation/InrU06ValidatorTest.kt
git commit -m "test: add INR^U06 validator coverage (happy path, missing INV, bad NDC, missing status)"
```

---

## Task 9: Integration test extension — multi-ORC RDE^O25 MLLP round-trip

**Files:**
- Modify: `hl7Core/src/commonTest/kotlin/org/rite/hl7/MllpBatchTest.kt`

**Interfaces:**
- Consumes: existing `HL7Builder.rdeO11 {}` DSL — note there is no `rdeO25 {}` method; RDE^O25 and O11 share the same shape, so use `rdeO11` with a custom MSH-9 override, OR add a `rdeO25` method to `HL7Builder`. Check whether the builder supports this.

- [ ] **Step 1: Check `HL7Builder` for rdeO25 or messageType override**

```bash
grep -n "rdeO25\|RDE\|messageType\|O25" /Users/bhushanrite/Downloads/PillCount-Hl7/hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/HL7Builder.kt
```

If no `rdeO25` exists: add `fun rdeO25(block: RdeO11Scope.() -> Unit): HL7Message = assembleVersioned(RdeO11Scope().apply(block), pre25 = "RDE^O01", from25 = "RDE^O25")` to `HL7Builder`.

- [ ] **Step 2: Read `MllpBatchTest.kt` to understand existing structure**

```bash
cat /Users/bhushanrite/Downloads/PillCount-Hl7/hl7Core/src/commonTest/kotlin/org/rite/hl7/MllpBatchTest.kt
```

- [ ] **Step 3: Add multi-ORC RDE^O25 round-trip test at the end of `MllpBatchTest.kt`**

```kotlin
@Test fun rdeO25_multi_orc_round_trip() {
    val builder = HL7Builder.builder().build()
    val msg = builder.rdeO25 {
        msh { it.messageControlId = "O25MULTI001"; it.sendingApplication = "PMS" }
        order {
            orc { it.orderControl = "RF"; it.placerOrderNumber = "RX101" }
            rxe { it.giveCode = "00069015505"; it.giveAmountMinimum = "30" }
        }
        order {
            orc { it.orderControl = "RF"; it.placerOrderNumber = "RX102" }
            rxe { it.giveCode = "00093005801"; it.giveAmountMinimum = "60" }
        }
    }
    val encoded = msg.encode()
    val decoded = HL7Parser().parse(encoded)
    assertEquals("O25", decoded.triggerEvent)
    assertEquals(2, decoded.orderGroups.size)
    assertEquals("RX101", decoded.orderGroups[0].orc.placerOrderNumber)
    assertEquals("RX102", decoded.orderGroups[1].orc.placerOrderNumber)
}
```

- [ ] **Step 4: Run test**

```
./gradlew :hl7Core:allTests --tests "*.MllpBatchTest" 2>&1 | tail -20
```

Expected: BUILD SUCCESSFUL, new test passes alongside existing batch tests.

- [ ] **Step 5: Commit**

```bash
git add hl7Core/src/commonTest/kotlin/org/rite/hl7/MllpBatchTest.kt \
        hl7Core/src/commonMain/kotlin/org/rite/hl7/builder/HL7Builder.kt
git commit -m "test: add multi-ORC RDE^O25 MLLP round-trip integration test"
```

---

## Task 10: Final verification — full test suite

**Files:** none (read-only verification pass)

- [ ] **Step 1: Run full test suite**

```
./gradlew :hl7Core:allTests 2>&1 | tail -50
```

Expected: BUILD SUCCESSFUL. All tests green. No regressions.

- [ ] **Step 2: Verify sealed class exhaustive `when` compiles**

Add a temporary throwaway Kotlin snippet in any test file to confirm sealed class `when` exhaustiveness compiles without `else`:

```kotlin
// In any existing test, add this local function to verify exhaustive when:
fun checkExhaustive(oc: OrderControl): String = when (oc) {
    OrderControl.NW, OrderControl.RF, OrderControl.CA, OrderControl.DC,
    OrderControl.HD, OrderControl.OH, OrderControl.OK, OrderControl.UA,
    OrderControl.SC, OrderControl.OC, OrderControl.OD, OrderControl.AF,
    OrderControl.DF, OrderControl.FU, OrderControl.RP, OrderControl.RO,
    OrderControl.XO, OrderControl.RE -> oc.code
    is OrderControl.Unknown -> oc.raw
}
```

Run `./gradlew :hl7Core:compileCommonMainKotlinMetadata` — if it compiles, the `when` is exhaustive.

- [ ] **Step 3: Remove the throwaway snippet**

Delete the temporary function added in Step 2.

- [ ] **Step 4: Final commit if any cleanup needed**

```bash
git add -u
git commit -m "chore: remove exhaustiveness verification snippet"
```
