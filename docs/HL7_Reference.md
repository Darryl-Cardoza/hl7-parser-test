# HL7 v2.x Reference — PillCount / hl7Core Library

**Scope:** Every HL7 segment implemented in `hl7Core`, all typed fields exposed by this library, per-version differences (2.1 → 2.8, including 2.7.1), and example wire-format messages for each supported message type.

**Source of truth:** This document reflects what the `hl7Core` Kotlin Multiplatform library actually implements (`model/segment/*.kt`, `builder/*.kt`, `version/SegmentCapabilities.kt`), cross-checked against the public HL7 v2.x standard (via hl7.eu / Caristix / v2plus.hl7.org mirrors — Caristix's own site is a JS-rendered SPA and does not return content via automated fetch, so citations below rely on hl7.eu and v2plus.hl7.org mirrors of the same ANSI/HL7 standard text).

---

## Table of Contents

1. [Supported HL7 Versions](#1-supported-hl7-versions)
2. [Supported Message Types](#2-supported-message-types)
3. [Segment Reference](#3-segment-reference)
   - MSH, PID, PV1, ORC, MSA, ERR, NTE
   - RXE, RXD, RXC, RXR, OBX
   - EQU, INV
   - QPD, RCP, QAK
   - ZIN, ZPR, ZSN, ZSV, ZAD (project extensions)
4. [Version-wise Structural Changes](#4-version-wise-structural-changes)
5. [Example Messages](#5-example-messages)
6. [How to Use This Library](#6-how-to-use-this-library)
7. [Testing in the App](#7-testing-in-the-app)

---

## 1. Supported HL7 Versions

| Enum | Wire value | Notes |
|---|---|---|
| `V21` | 2.1 | |
| `V22` | 2.2 | |
| `V23` | 2.3 | Flat structure — trigger names O01/U05/U06 pre-date formal grouping |
| `V231` | 2.3.1 | |
| `V24` | 2.4 | INR^U06 / INU^U05 (Clinical Laboratory Automation, Ch.13) become valid from this version |
| `V25` | 2.5 | Formal message groups introduced; trigger events renamed (O01→O13, O01→O11) |
| `V251` | 2.5.1 | |
| `V26` | 2.6 | Old trigger names (O01) still accepted for backward compatibility |
| `V27` | 2.7 | Old trigger names (O01) withdrawn per the standard |
| `V271` | 2.7.1 | Distinct enum entry (added so it doesn't silently fall back to 2.7's field caps) |
| `V28` | 2.8 | |

Default version when `MSH-12` is absent/unrecognized: **2.5** (`HL7Version.DEFAULT`).

Version resolution (`HL7Version.from`) tries an exact match on `MSH-12` first, then a `startsWith` fallback (e.g. an unrecognized `"2.7.2"` would fall back to `V27`).

---

## 2. Supported Message Types

| Builder method | Message type (2.5+) | Message type (pre-2.5) | Purpose |
|---|---|---|---|
| `rdsO13 { }` | `RDS^O13` | `RDS^O01` | Pharmacy dispense (give-out) message |
| `rdeO11 { }` | `RDE^O11` | `RDE^O01` | Pharmacy encoded dispense **order** |
| `inrU05 { }` | `INR^U05` | `INR^U05` (no version split modeled) | Inventory count **response** |
| `inrU06 { }` | `INR^U06` | `INR^U06` (no version split modeled) | Inventory adjustment / inventory count **request** (distinguished by presence of `ZAD`) |
| `inuU05 { }` | `INU^U05` | `INU^U05` | Unsolicited inventory update |
| `qbpQ11 { }` | `QBP^Q11` | — | Pre-count / stock-on-hand query |
| `ack { }` | `ACK^R01` | — | Generic acknowledgement |

`HL7MessageKind.from(message)` classifies a parsed message into a business kind (`DISPENSE`, `DISPENSE_ORDER`, `CANCEL_ORDER`, `INVENTORY_RESPONSE`, `INVENTORY_ADJUSTMENT`, `INVENTORY_REQUEST`, `INVENTORY_UPDATE`, `QUERY`, `QUERY_RESPONSE`, `ACKNOWLEDGMENT`, `UNKNOWN`) by looking at `MSH-9` (message code + trigger event) and `ORC-1` (order control). Both the old (`O01`) and new (`O13`/`O11`) trigger names are recognized for `RDS`/`RDE`.

> **Standard-conformance note:** `INR^U06` / `INU^U05` / `INV` are real HL7 Chapter 13 (Clinical Laboratory Automation) constructs, confirmed valid from v2.4 onward. This library layers an `ORC` segment and project-specific `ZAD`/`ZIN` Z-segments on top of them for pharmacy-inventory semantics — this is a **customized profile**, not literal standard-conformant wire format. Fine for a closed-loop protocol between your own devices; would need alignment work for third-party lab-automation interop.

---

## 3. Segment Reference

Each table lists **only the fields this library exposes a typed getter for** — HL7 segments can have more fields than shown; unexposed fields are still preserved losslessly on the underlying `HL7Segment` AST and reachable via `GenericSegment.value(n)` / `component(n, c)`.

### MSH — Message Header

*File: `HeaderSegments.kt`. Required, once, always first segment in every message.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| MSH-1 | Field Separator | `\|` | Always position 1, fixed in all versions |
| MSH-2 | Encoding Characters | `^~\&` | Fixed in all versions |
| MSH-3 | Sending Application | `PillCounter` | |
| MSH-4 | Sending Facility | `PHARMACY` | |
| MSH-5 | Receiving Application | `ROBOT` | |
| MSH-6 | Receiving Facility | `PMS` | |
| MSH-7 | Date/Time of Message | `20260623091205` | |
| MSH-8 | Security | *(blank)* | |
| MSH-9 | Message Type | `RDS^O13` | MSH-9.1=message code, MSH-9.2=trigger event. Trigger name differs by version (O01 pre-2.5 vs O13/O11 2.5+) |
| MSH-10 | Message Control ID | `1782200001` | |
| MSH-11 | Processing ID | `P` | P=production, T=test, D=debug |
| MSH-12 | Version ID | `2.5` | Drives this library's version resolution (`HL7Version.from`) |
| MSH-17 | Country Code | `USA` | |

**Max field count per version** (`SegmentCapabilities`): 12 fields (≤2.1), 16 fields (2.2–2.4), 21 fields (2.5+). Trailing unset fields beyond this cap are trimmed on build.

---

### PID — Patient Identification

*File: `HeaderSegments.kt`. Optional in dispense/inventory flows; required in RDE per the standard's PATIENT group.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| PID-1 | Set ID | `1` | |
| PID-3 | Patient ID (component 1) | `PT-9001` | PID-3.4 = assigning authority, PID-3.5 = identifier type code |
| PID-3.4 | Assigning Authority | `HOSP` | |
| PID-3.5 | Identifier Type Code | `MR` | |
| PID-5 | Patient Name (component 1/2/3) | `DOE^JANE^A` | Family^Given^Middle |
| PID-7 | Date of Birth | `19800101` | |
| PID-8 | Sex | `F` | |
| PID-11 | Patient Address (components 1/3/4/5/6) | `123 MAIN ST^^SPRINGFIELD^IL^62701^USA` | Street/City/State/Zip/Country |

**Max field count per version:** 30 fields (≤2.3), 39 fields (2.5+).

---

### PV1 — Patient Visit

*File: `HeaderSegments.kt`. Optional; only relevant in RDE's PATIENT_VISIT sub-group.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| PV1-1 | Set ID | `1` | |
| PV1-2 | Patient Class | `O` | O=outpatient, I=inpatient |
| PV1-3 | Assigned Patient Location (1/2/3/4) | `ER^101^A^MAINHOSP` | PointOfCare/Room/Bed/Facility |
| PV1-7 | Attending Doctor (1/2/3) | `1234^SMITH^JOHN` | ID/Family/Given |
| PV1-19 | Visit Number (comp. 1) | `V-5001` | |
| PV1-44 | Admit Date/Time | `20260101080000` | |

**Max field count per version:** 40 fields (≤2.1), 44 fields (2.2–2.4), 52 fields (2.5+).

---

### ORC — Common Order

*File: `HeaderSegments.kt`. Required once per order in RDS/RDE/inventory scopes in this library (note: ORC is not part of the literal HL7 Chapter 13 INR/INU structure — see conformance note above).*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ORC-1 | Order Control | `RE` | RE=dispense (drives `HL7MessageKind.DISPENSE`), NW=new order, CA=cancel (drives `HL7MessageKind.CANCEL_ORDER`) |
| ORC-2 | Placer Order Number (1/2) | `ORD-12345^PHARM` | Number / Namespace ID |
| ORC-3 | Filler Order Number (1/2) | `RX-98765^PHARM` | Number / Namespace ID |
| ORC-5 | Order Status | `CM` | CM=completed |
| ORC-9 | Date/Time of Transaction | `20260623091205` | |
| ORC-12 | Ordering Provider (1/2/3) | `1234^SMITH^JOHN` | ID/Family/Given |
| ORC-21 | Ordering Facility Name | `PHARMACY` | |

**Max field count per version:** 19 fields (≤2.1), 25 fields (2.3–2.4), 31 fields (2.5+).

---

### MSA — Message Acknowledgement

*File: `HeaderSegments.kt`. Used in `ACK^R01` responses.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| MSA-1 | Acknowledgment Code | `AA` | AA=accept, AE=error, AR=reject |
| MSA-2 | Message Control ID | `1782200001` | Echoes the original MSH-10 |
| MSA-3 | Text Message | `Message accepted` | Deprecated field, still populated by many senders |

**Max field count per version:** 6 fields (≤2.1), 3 fields (2.5+) — field count actually **shrinks** at 2.5 as trailing fields were deprecated/moved.

---

### ERR — Error

*File: `HeaderSegments.kt`. Optional, repeating, carried in ACK when validation fails.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ERR-2 | Error Location (1/2/3) | `RXD^1^4` | Segment ID / Sequence / Field position |
| ERR-3 | HL7 Error Code (1/2) | `101^Required field missing` | Code / Text |
| ERR-4 | Severity | `E` | E=error, W=warning, I=information |
| ERR-5 | Application Error Code (1/2) | `VAL-01^Missing dispense amount` | |
| ERR-7 | Diagnostic Information | `RXD-4 is blank` | |
| ERR-8 | User Message | `Please provide a dispense amount` | |

**Max field count per version:** 1 field (≤2.1), 12 fields (2.5+) — a large expansion at 2.5.

---

### NTE — Notes and Comments

*File: `HeaderSegments.kt`. Optional, repeating; attaches to the message or to a preceding OBX depending on position.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| NTE-1 | Set ID | `1` | |
| NTE-2 | Source of Comment | `L` | L=ancillary (lab), P=orderer |
| NTE-3 | Comment | `Verified by pharmacist` | |
| NTE-4 | Comment Type | `GEN` | |

**Max field count per version:** 3 fields (≤2.1), 4 fields (2.5+).

---

### RXE — Pharmacy/Treatment Encoded Order

*File: `PharmacySegments.kt`. Used in `RDE` (dispense order) messages — required in RDE's `ENCODING`/`ORDER_DETAIL` structure from 2.5 onward, flat/optional pre-2.5.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| RXE-2 | Give Code (1/2/3) | `00093-0058-01^AMOXICILLIN 500MG^NDC` | Code / Name / Coding system |
| RXE-3 | Give Amount – Minimum | `90` | |
| RXE-4 | Give Amount – Maximum | `90` | |
| RXE-5 | Give Units (1/2) | `TAB^Tablets` | |
| RXE-6 | Give Dosage Form (1/2) | `TAB^Tablet` | |
| RXE-7 | Provider's Administration Instructions | `Take one tablet daily` | |
| RXE-8 | Deliver-to Location | `PHARMACY-1` | |
| RXE-10 | Dispense Amount | `90` | |
| RXE-11 | Dispense Units (1/2) | `TAB^Tablets` | |
| RXE-12 | Number of Refills | `2` | |
| RXE-15 | Prescription Number | `RX100845` | |

**Max field count per version:** 14 fields (≤2.1), 16 (2.2), 18 (2.3), 20 (2.4), 25 fields (2.5+).

---

### RXD — Pharmacy/Treatment Dispense

*File: `PharmacySegments.kt`. Required, once, per order — this is the actual dispense record in RDS messages.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| RXD-1 | Dispense Sub-ID Counter | `1` | |
| RXD-2 | Dispense/Give Code (1/2/3) | `00093-0058-01^AMOXICILLIN 500MG^NDC` | Code / Name / Coding system |
| RXD-3 | Date/Time Dispensed | `20260623091205` | |
| RXD-4 | Actual Dispense Amount | `90` | |
| RXD-5 | Actual Dispense Units (1/2) | `TAB^Tablets` | |
| RXD-6 | Actual Dosage Form (1) | `TAB` | |
| RXD-7 | Prescription Number | `RX100842` | |
| RXD-10 | Dispensing Provider (1/2/3) | `1234^SMITH^JOHN` | ID / Family / Given |
| RXD-11 | Substitution Status | `G` | G=generic substituted, N=none |
| RXD-15 | Lot Number | `LOT78321` | |
| RXD-16 | Expiration Date | `20271031` | |
| RXD-17 | Substance Manufacturer Name (2) | `PFIZER` | |

**Max field count per version:** 20 fields (≤2.1), 25 fields (2.5+).

---

### RXC — Pharmacy/Treatment Component Order

*File: `PharmacySegments.kt`. Optional, repeating; used for compound/mixture drug component drugs.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| RXC-1 | Component Type | `B` | B=base, A=additive |
| RXC-2 | Component Code (1/2/3) | `00093-0059-01^IBUPROFEN 200MG^NDC` | Code / Name / Coding system |
| RXC-3 | Component Amount | `200` | |
| RXC-4 | Component Units (1/2) | `MG^Milligrams` | |
| RXC-5 | Component Strength | `200` | |
| RXC-6 | Component Strength Units | `MG` | |

**Max field count per version:** 4 fields (≤2.1), 5 (2.3), 9 fields (2.4+).

---

### RXR — Pharmacy/Treatment Route

*File: `PharmacySegments.kt`. Required, repeating, at 2.5+ (per standard); optional/loosely-defined pre-2.5. This library treats it as optional/unenforced at build time for both eras.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| RXR-1 | Route (1/2/3) | `PO^Oral^HL70162` | Code / Text / Coding system |
| RXR-2 | Administration Site (1/2) | `LA^Left Arm` | |
| RXR-3 | Administration Device (1/2) | `SYRINGE^Syringe` | |

**Max field count per version:** 3 fields (≤2.1), 6 fields (2.5+).

---

### OBX — Observation/Result

*File: `PharmacySegments.kt`. Optional, repeating; attaches result/observation values, e.g. dispense-verification flags.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| OBX-1 | Set ID | `1` | |
| OBX-2 | Value Type | `ST` | ST=string, NM=numeric, CE=coded entry |
| OBX-3 | Observation Identifier (1/2/3) | `DISPENSE-VERIFIED^Dispense Verified^L` | Code / Text / Coding system |
| OBX-4 | Observation Sub-ID | `1` | |
| OBX-5 | Observation Value | `true` | |
| OBX-6 | Units (1) | `EA` | |
| OBX-7 | Reference Range | `N/A` | |
| OBX-8 | Abnormal Flags | *(blank)* | |
| OBX-11 | Result Status | `F` | F=final |
| OBX-14 | Date/Time of Observation | `20260623091205` | |
| OBX-16 | Responsible Observer (1) | `1234` | |
| OBX-17 | Observation Method | `MANUAL` | |

**Max field count per version:** 11 fields (≤2.1), 17 (2.2–2.3), 19 (2.4), 25 fields (2.5+).

> Per Caristix/hl7.eu structural verification, the `OBSERVATION` group (`OBX` + `NTE`) wrapping this segment is **optional overall** (0..*) in the 2.5+ formal RDS structure — if present it repeats, but it can be entirely absent. It is not "always required" as sometimes assumed.

---

### EQU — Equipment Detail

*File: `InventorySegments.kt`. Required, once, in `INR`/`INU` (Chapter 13, Clinical Laboratory Automation) messages — identifies the automation equipment/device.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| EQU-1 | Equipment ID (comp. 1) | `DEVICE-1` | |
| EQU-2 | Event Date/Time | `20260623091205` | |
| EQU-3 | Equipment State | `OK` | |
| EQU-4 | Local/Remote Control State | `R` | R=remote, L=local |
| EQU-5 | Alert Level | `NONE` | |

**Max field count per version:** 4 fields (2.4+; no cap defined below 2.4, matching EQU's actual v2.4 introduction).

---

### INV — Inventory Detail

*File: `InventorySegments.kt`. Confirmed **real, standard** HL7 Chapter 13 segment (not a Z-segment). This library uses a simplified project-specific field mapping rather than the full standard field table (Substance Identifier, Substance Status per Table 0383, First-Used Date/Time, On-Board Stability Duration, etc.).*

| Field | Name | Example | Version notes |
|---|---|---|---|
| INV-1 | Set ID | `1` | |
| INV-2 | Substance (1/2/3) | `00069015505^Drug Name^NDC` | NDC / Name / Coding system — project-specific reuse of INV-2 |
| INV-3 | Lot Number | `LOT-A` | |
| INV-4 | Expiration Date | `20251201` | |
| INV-5 | On-Hand Quantity | `150` | |
| INV-6 | Units | `EA` | |

**Max field count per version:** 20 fields (2.4+).

> **Note:** this project's `INV` field layout is a simplified, pill-count-oriented mapping — it does not match the literal standard INV field table used in lab-reagent inventory tracking. Treat this segment's semantics as project-specific even though the segment *name* is standard.

---

### QPD — Query Parameter Definition

*File: `InventorySegments.kt`. Used by `QBP^Q11` / `RSP^K11` query/response pair.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| QPD-1 | Message Query Name (1) | `STOCK_ON_HAND` | |
| QPD-2 | Query Tag | `Q-001` | |
| QPD-3 | NDC / Drug Name (1/2) | `00093-0058-01^AMOXICILLIN 500MG` | |
| QPD-4 | Equipment ID | `DEVICE-1` | |

**Max field count per version:** 60 fields (2.5+; QBP/QPD is a v2.5+ construct, no pre-2.5 cap defined).

---

### RCP — Response Control Parameter

*File: `InventorySegments.kt`. Query response-shaping segment for `QBP^Q11`.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| RCP-1 | Query Priority | `I` | I=immediate, D=deferred |
| RCP-2 | Quantity Limited Request | `50^RD` | |

**Max field count per version:** 7 fields (2.5+).

---

### QAK — Query Acknowledgement

*File: `InventorySegments.kt`. Used in `RSP^K11` responses to a `QBP^Q11` query.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| QAK-1 | Query Tag | `Q-001` | |
| QAK-2 | Query Response Status | `OK` | OK / NF (not found) / AE (application error) |
| QAK-3 | Message Query Name | `STOCK_ON_HAND` | |

**Max field count per version:** 8 fields (2.5+).

---

### ZIN — Inventory Count Row *(project Z-segment)*

*File: `InventorySegments.kt`. Custom extension used in `INR^U05` inventory-count-response scope.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ZIN-1 | Set ID | `1` | |
| ZIN-2 | Dispense Type | `OPENED` | OPENED / SEALED / NA / EXPECTED_ON_HAND |
| ZIN-3 | Quantity | `45` | |
| ZIN-4 | Lot Number | `LOT-A` | |
| ZIN-5 | Expiry | `20251201` | |

No standard version cap (Z-segment) — same field layout across all versions.

---

### ZPR — Transaction Priority *(project Z-segment)*

*File: `InventorySegments.kt`. Custom extension.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ZPR-1 | Set ID | `1` | |
| ZPR-2 | Qualifier | `PRIORITY` | Fixed literal |
| ZPR-3 | Priority | `STAT` | STAT / URGENT / ROUTINE / TIMED |

No standard version cap (Z-segment).

---

### ZSN — Serial Number Capture (DSCSA) *(project Z-segment)*

*File: `ExtensionSegments.kt`. Custom extension for package-level serialization (US DSCSA compliance), repeating per package serial in a dispense message.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ZSN-1 | Set ID | `1` | |
| ZSN-2 | Package Serial Number | `21N4F9XK0042` | |
| ZSN-3 | National Drug Code | `00093-0058-01` | |
| ZSN-4 | Lot Number | `LOT78321` | |
| ZSN-5 | Expiration Date | `20271031` | |
| ZSN-6 | Transaction Type | `D` | D=dispense, R=return |

No standard version cap (Z-segment).

---

### ZSV — Stock Bottle Validation Assertion *(project Z-segment)*

*File: `ExtensionSegments.kt`. Custom extension asserting a stock-bottle validation outcome.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ZSV-1 | Set ID | `1` | |
| ZSV-2 | Validation Status | `VA` | VA=valid, VR=rejected |
| ZSV-3 | Validation Timestamp | `20260623091205` | |
| ZSV-4 | Validator ID | `SCANNER-1` | |
| ZSV-5 | Rejection Reason | *(blank)* | Populated only when status=VR |

No standard version cap (Z-segment).

---

### ZAD — Inventory Adjustment *(project Z-segment)*

*File: `ExtensionSegments.kt`. Custom extension carrying inventory-adjustment detail alongside `INV` in `INR^U06`.*

| Field | Name | Example | Version notes |
|---|---|---|---|
| ZAD-1 | Set ID | `1` | |
| ZAD-2 | Adjustment Type | `LOSS` | LOSS / GAIN / DAMAGE / EXPIRED |
| ZAD-3 | Adjustment Quantity | `5` | |
| ZAD-4 | Adjustment Reason | `DAMAGED_IN_TRANSIT` | |
| ZAD-5 | Adjustment Date/Time | `20240615141500` | |
| ZAD-6 | Approved By | `JOHN.DOE` | |

No standard version cap (Z-segment).

---

## 4. Version-wise Structural Changes

| Version | Structural change |
|---|---|
| **2.3 / 2.3.1** | Flat segment layout — no formal groups. RDS/RDE use `O01` trigger. Chapter 13 (INR/INU, Clinical Laboratory Automation) **not defined** at 2.3.1 (confirmed absent from the 2.3.1 standard chapter list). |
| **2.4** | Chapter 13 introduced — `INR^U06` / `INU^U05` / `EQU` / `INV` become valid from this version onward. RDS/RDE still flat, still `O01`. |
| **2.5** | Formal message groups introduced (PATIENT, ORDER, ORDER_DETAIL, ENCODING, OBSERVATION for RDS/RDE). Trigger events renamed: `RDS^O01`→`RDS^O13`, `RDE^O01`→`RDE^O11`. `SFT` (Software Segment) added to Ch.13 messages, right after MSH. QBP/QPD/RCP/QAK query framework introduced. |
| **2.5.1** | No material structural changes found vs 2.5 for the message types this library implements. |
| **2.6** | Old trigger names (`O01`) retained **for backward compatibility only**. Structure otherwise identical to 2.5.1. |
| **2.7** | Old trigger names (`O01`) **withdrawn** per the standard — `O13`/`O11` become the sole valid trigger. |
| **2.7.1** | No functional difference identified from 2.7 for the message types implemented here; kept as a distinct `HL7Version` entry for forward-compatibility with future field-cap divergence. |
| **2.8** | No structural difference confirmed vs 2.7.1 for these message types (not independently fetchable from public mirrors during verification; assumed unchanged per HL7's typical minimal-change pattern). |

### Field-count caps by segment (from `SegmentCapabilities`)

| Segment | ≤2.1 | 2.2 | 2.3 | 2.4 | 2.5+ |
|---|---|---|---|---|---|
| MSH | 12 | 12 | 12 | 16 | 21 |
| PID | 30 | 30 | 30 | 30 | 39 |
| PV1 | 40 | 44 | 44 | 44 | 52 |
| ORC | 19 | 19 | 25 | 25 | 31 |
| RXE | 14 | 16 | 18 | 20 | 25 |
| RXD | 20 | 20 | 20 | 20 | 25 |
| RXC | 4 | 4 | 5 | 9 | 9 |
| RXR | 3 | 3 | 3 | 3 | 6 |
| OBX | 11 | 17 | 17 | 19 | 25 |
| NTE | 3 | 3 | 3 | 3 | 4 |
| MSA | 6 | 6 | 6 | 6 | 3 *(shrinks)* |
| ERR | 1 | 1 | 1 | 1 | 12 |
| EQU | — | — | — | 4 | 4 |
| INV | — | — | — | 20 | 20 |
| QPD | — | — | — | — | 60 |
| RCP | — | — | — | — | 7 |
| QAK | — | — | — | — | 8 |

*(`—` = uncapped / not applicable below the segment's introduction version.)*

---

## 5. Example Messages

All examples use `\r` (carriage return) as the segment separator per the HL7 wire format; shown here on separate lines for readability. These mirror the samples in `HL7SampleMessages.kt` used by the in-app test harness.

### RDS^O01 — Dispense (v2.3, flat, pre-group structure)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O01|MSG-231-1|P|2.3
ORC|RE|ORD-1001
RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100842
```

### RDS^O13 — Dispense (v2.5, grouped structure, with observation)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|MSG-25-1|P|2.5
ORC|RE|ORD-1004
RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100845
RXR|PO^Oral
OBX|1|ST|DISPENSE-VERIFIED||true||||||F
```

### RDS^O13 — Dispense with DSCSA package serials (v2.5.1)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDS^O13|MSG-251-1|P|2.5.1
ORC|RE|ORD-1005
RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100846
RXR|PO^Oral
ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D
ZSN|2|21N4F9XK0099|00093-0058-01|LOT78321|20271031|D
```

### RDE^O01 — Dispense Order (v2.4, flat, pre-group structure)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDE^O01|MSG-24-1|P|2.4
PID|1||PT-9002^^^HOSP^MR||SMITH^JOHN
ORC|NW|ORD-2002
RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets
RXR|PO^Oral
RXC|B|00093-0059-01^IBUPROFEN 200MG^NDC|200|MG
```

### RDE^O11 — Dispense Order (v2.5, grouped structure)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||RDE^O11|MSG-25-2|P|2.5
PID|1||PT-9003^^^HOSP^MR||PATEL^RAJ
ORC|NW|ORD-2003
RXO|00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets
RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets
RXR|PO^Oral
```

### INR^U05 — Inventory Count Response (v2.5)

```
MSH|^~\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||INR^U05|MSG-3001|P|2.5
EQU|DEVICE-1|20260623091205
ORC|RE|ORD-3001
INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA
```

### INR^U06 — Inventory Adjustment (v2.5)

```
MSH|^~\&|WMS|WAREHOUSE|EHR|HOSPITAL|20240615||INR^U06|MSG-002|P|2.5
INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA
ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE
```

### ACK^R01 — Acknowledgement

```
MSH|^~\&|A|B|C|D|20260101||ACK^R01|1|P
MSA|AA|1|Message accepted
```

---

## 6. How to Use This Library

### Parsing

```kotlin
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.model.segment.RXDSegment

val parser = HL7Parser.Builder()
    .defaultVersion("2.5")
    .registerCustomSegment(ZSNSegment.Definition)   // required for project Z-segments
    .strictMode(false)                              // false = partial parse on error
    .build()

when (val result = parser.parse(rawMessage)) {
    is HL7ParseResult.Success -> {
        val rxd = result.message.segment<RXDSegment>("RXD")
        println(rxd?.actualDispenseAmount)
    }
    is HL7ParseResult.Failure -> {
        println(result.errors)              // list of HL7ParseError
        result.partialMessage                // segments parsed before the error, if any
    }
}
```

### Building

```kotlin
import org.rite.hl7.builder.HL7Builder

val builder = HL7Builder.builder()
    .defaultVersion("2.5")
    .registerCustomSegment(ZSNSegment.Definition)
    .build()

val message = builder.rdsO13 {
    msh { it.sendingApplication = "PillCounter"; it.messageControlId = "MSG-1" }
    orc { it.orderControl = "RE"; it.placerOrderNumber = "ORD-12345" }
    rxd {
        it.dispenseGiveCode = "00093-0058-01"
        it.dispenseGiveName = "AMOXICILLIN 500MG"
        it.actualDispenseAmount = "90"
        it.lotNumber = "LOT78321"
        it.expirationDate = "20271031"
    }
}
val raw = message.encode()   // wire-format string, CR-separated
```

### One-call facade

```kotlin
import org.rite.hl7.HL7

val hl7 = HL7(version = "2.5")   // pre-registers ZSN/ZSV/ZAD
val result = hl7.parse(rawMessage)
val ackText = hl7.ack(result.messageOrNull!!)   // validate + build ACK^R01
```

---

## 7. Testing in the App

The Compose app ships a **Library Test** tab (`HL7TestScreen.kt`) alongside the original demo screen, purpose-built to exercise `hl7Core`'s pure parsing/building logic directly:

- **HL7 Version dropdown** — selects the version used both as the parser's default-version fallback and as the target version for the "Build @ Version" action.
- **Sample Message dropdown** — loads one of the canned messages from `HL7SampleMessages.kt` (18 samples spanning RDS^O01/O13, RDE^O01/O11, INR^U05/U06, and two intentionally malformed messages) into an editable text field.
- **Parse** — runs the raw text straight through `HL7Parser`, showing resolved version, message type, business `kind` classification, and the full segment list — or detailed error/partial-parse output on failure.
- **Build @ Version** — builds a fresh RDS dispense message via `HL7Workflows(version = selectedVersion)` and round-trips it through parsing, to validate the builder path at a chosen version.

To add a new test case, add a `Sample(label, raw)` entry to `HL7SampleMessages.samples`.
