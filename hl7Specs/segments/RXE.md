# RXE — Pharmacy/Treatment Encoded Order

> Chapters: v2.3.1 §4 | v2.5.1 §4.14.4 | v2.8.2 §4A

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Quantity/Timing | TQ | R→B→W | | | ✓(R) | ✓(B) | W | Deprecated→withdrawn; use TQ1 |
| 2 | Give Code | CE | R | | 0292 | ✓ | ✓ | ✓ | NDC^name^codingSystem |
| 3 | Give Amount - Minimum | NM | R | | | ✓ | ✓ | ✓ | Numeric |
| 4 | Give Amount - Maximum | NM | O | | | ✓ | ✓ | ✓ | Numeric |
| 5 | Give Units | CE | R | | | ✓ | ✓ | ✓ | code^text^codeSystem |
| 6 | Give Dosage Form | CE | O | | | ✓ | ✓ | ✓ | code^text |
| 7 | Provider's Administration Instructions | CE | O | Y | | ✓ | ✓ | ✓ | Repeatable |
| 8 | Deliver-to Location | CM/LA1 | C | | | ✓(CM) | ✓(LA1) | ✓(LA1) | CM→LA1 in v2.5.1 |
| 9 | Substitution Status | ID | O | | 0167 | ✓ | ✓ | ✓ | 0/1/2/3/4/5/7/8/G/N/T |
| 10 | Dispense Amount | NM | C | | | ✓ | ✓ | ✓ | Numeric |
| 11 | Dispense Units | CE | C | | | ✓ | ✓ | ✓ | code^text |
| 12 | Number of Refills | NM | O | | | ✓ | ✓ | ✓ | Numeric |
| 13 | Ordering Provider's DEA Number | XCN | C | Y | | ✓ | ✓ | ✓ | |
| 14 | Pharmacist/Treatment Supplier Verifier ID | XCN | O | Y | | ✓ | ✓ | ✓ | |
| 15 | Prescription Number | ST | C | | | ✓ | ✓ | ✓ | |
| 16 | Number of Refills Remaining | NM | C | | | ✓ | ✓ | ✓ | |
| 17 | Number of Refills/Doses Dispensed | NM | C | | | ✓ | ✓ | ✓ | |
| 18 | D/T of Most Recent Refill or Dose Dispensed | TS | C | | | ✓ | ✓ | ✓ | |
| 19 | Total Daily Dose | CQ | C | | | ✓ | ✓ | ✓ | value^units |
| 20 | Needs Human Review | ID | O | | 0136 | ✓ | ✓ | ✓ | Y/N |
| 21 | Pharmacy Special Dispensing Instructions | CE | O | Y | | ✓ | ✓ | ✓ | |
| 22 | Give Per (Time Unit) | ST | C | | | ✓ | ✓ | ✓ | |
| 23 | Give Rate Amount | ST | O | | | ✓ | ✓ | ✓ | |
| 24 | Give Rate Units | CE | O | | | ✓ | ✓ | ✓ | |
| 25 | Give Strength | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 26 | Give Strength Units | CE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 27 | Give Indication | CE | O | Y | | — | ✓ | ✓ | v2.5.1+ |
| 28 | Dispense Package Size | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 29 | Dispense Package Size Unit | CE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 30 | Dispense Package Method | ID | O | | 0321 | — | ✓ | ✓ | v2.5.1+; CH/EA/IV |
| 31 | Supplementary Code | CE | O | Y | | — | ✓ | ✓ | v2.5.1+ |
| 32 | Original Order Date/Time | TS | O | | | — | ✓ | ✓ | v2.5.1+ |
| 33 | Give Drug Strength Volume | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 34 | Give Drug Strength Volume Units | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 35 | Controlled Substance Schedule | CWE | O | | 0477 | — | ✓ | ✓ | v2.5.1+; I/II/IIN/IIS/III/IV/V |
| 36 | Formulary Status | ID | O | | 0478 | — | ✓ | ✓ | v2.5.1+; Y/N/R/G/T |
| 37 | Pharmaceutical Substance Alternative | CWE | O | Y | | — | ✓ | ✓ | v2.5.1+ |
| 38 | Pharmacy of Most Recent Fill | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 39 | Initial Dispense Amount | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 40 | Dispensing Pharmacy | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 41 | Dispensing Pharmacy Address | XAD | O | | | — | ✓ | ✓ | v2.5.1+ |
| 42 | Deliver-to Patient Location | PL | O | | | — | ✓ | ✓ | v2.5.1+ |
| 43 | Deliver-to Address | XAD | O | | | — | ✓ | ✓ | v2.5.1+ |
| 44 | Pharmacy Order Type | ID | O | | 0480 | — | ✓ | ✓ | v2.5.1+; M/O/S |
| 45 | Pharmacy Phone Number | XTN | O | Y | | — | — | ✓ | v2.8.2 only |

## Required Fields for RDE^O11 / RDE^O25
RXE-2 (Give Code), RXE-3 (Give Amount Min), RXE-5 (Give Units) are always Required.

## Coded Fields
- RXE-9: Table 0167 — Substitution Status
- RXE-20: Table 0136 — Y/N
- RXE-30: Table 0321 — CH/EA/IV
- RXE-35: Table 0477 — Controlled Substance Schedule
- RXE-36: Table 0478 — Formulary Status Y/N/R/G/T
- RXE-44: Table 0480 — M/O/S
