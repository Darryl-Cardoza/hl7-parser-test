# RXD — Pharmacy/Treatment Dispense

> Chapters: v2.3.1 §4 | v2.5.1 §4.14.5 | v2.8.2 §4A

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Dispense Sub-ID Counter | NM | R | | | ✓ | ✓ | ✓ | Numeric |
| 2 | Dispense/Give Code | CE | R | | 0292 | ✓ | ✓ | ✓ | NDC^name^codeSystem |
| 3 | Date/Time Dispensed | TS/DTM | R | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 4 | Actual Dispense Amount | NM | R | | | ✓ | ✓ | ✓ | Numeric |
| 5 | Actual Dispense Units | CE | C | | | ✓ | ✓ | ✓ | code^text |
| 6 | Actual Dosage Form | CE | O | | | ✓ | ✓ | ✓ | |
| 7 | Prescription Number | ST | R | | | ✓ | ✓ | ✓ | Required |
| 8 | Number of Refills Remaining | NM | C | | | ✓ | ✓ | ✓ | |
| 9 | Dispense Notes | ST | O | Y | | ✓ | ✓ | ✓ | |
| 10 | Dispensing Provider | XCN | O | Y | | ✓ | ✓ | ✓ | id^family^given |
| 11 | Substitution Status | ID | O | | 0167 | ✓ | ✓ | ✓ | |
| 12 | Total Daily Dose | CQ | O | | | ✓ | ✓ | ✓ | |
| 13 | Dispense-to Location | CM/LA2 | C | | | ✓(CM) | ✓(LA2) | ✓(LA2) | CM→LA2 v2.5.1 |
| 14 | Needs Human Review | ID | O | | 0136 | ✓ | ✓ | ✓ | Y/N |
| 15 | Pharmacy Special Dispensing Instructions | CE | O | Y | | ✓ | ✓ | ✓ | |
| 16 | Actual Strength | NM | O | | | ✓ | ✓ | ✓ | |
| 17 | Actual Strength Unit | CE | O | | | ✓ | ✓ | ✓ | |
| 18 | Substance Lot Number | ST | O | Y | | ✓ | ✓ | ✓ | Repeatable |
| 19 | Substance Expiration Date | TS/DTM | O | Y | | ✓(TS) | ✓(TS) | ✓(DTM) | Repeatable |
| 20 | Substance Manufacturer Name | CE | O | Y | 0227 | ✓ | ✓ | ✓ | Repeatable; component(20,2)=name |
| 21 | Indication | CE | O | Y | | ✓ | ✓ | ✓ | |
| 22 | Dispense Package Size | NM | O | | | ✓ | ✓ | ✓ | |
| 23 | Dispense Package Size Unit | CE | O | | | ✓ | ✓ | ✓ | |
| 24 | Dispense Package Method | ID | O | | 0321 | ✓ | ✓ | ✓ | CH/EA/IV |
| 25 | Supplementary Code | CE | O | Y | | — | ✓ | ✓ | v2.5.1+ |
| 26 | Initiating Location | CE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 27 | Packaging/Assembly Location | CE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 28 | Actual Drug Strength Volume | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 29 | Actual Drug Strength Volume Units | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 30 | Dispense to Pharmacy | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 31 | Dispense to Pharmacy Address | XAD | O | | | — | ✓ | ✓ | v2.5.1+ |
| 32 | Pharmacy Order Type | ID | O | | 0480 | — | ✓ | ✓ | v2.5.1+; M/O/S |
| 33 | Dispense Type | CWE | O | | 0484 | — | ✓ | ✓ | v2.5.1+; N/P/Q/R/B/C/S/T/Z |
| 34 | Pharmacy Phone Number | XTN | O | Y | | — | — | ✓ | v2.8.2 only |

## Required Fields for RDS^O13
RXD-1, RXD-2, RXD-3, RXD-4, RXD-7 are always Required.

## Coded Fields
- RXD-11: Table 0167 — Substitution Status
- RXD-14: Table 0136 — Y/N
- RXD-24: Table 0321 — CH/EA/IV
- RXD-32: Table 0480 — M/O/S
- RXD-33: Table 0484 — Dispense Type
