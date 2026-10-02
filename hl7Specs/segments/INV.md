# INV — Inventory Detail

> Chapters: v2.5.1 §13.4.4 | v2.8.2 §13  
> **NOT present in v2.3.1** — introduced in v2.4

## Field Definitions (Standard HL7)

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Substance Identifier | CE/CWE | R | | 0451 | — | ✓(CE) | ✓(CWE) | NDC^name^codeSystem |
| 2 | Substance Status | CE/CWE | R | Y | 0383 | — | ✓(CE) | ✓(CWE) | EW/EE/CW/CE/QW/QE/NW/NE/OW/OE/OK |
| 3 | Substance Type | CE/CWE | O | | 0384 | — | ✓(CE) | ✓(CWE) | SR/MR/DI/PT/RC/CO/PW/LW/SW/SC/LI/OT |
| 4 | Inventory Container Identifier | CE/CWE | O | | | — | ✓(CE) | ✓(CWE) | |
| 5 | Container Carrier Identifier | CE/CWE | O | | | — | ✓(CE) | ✓(CWE) | |
| 6 | Position on Carrier | CE/CWE | O | | | — | ✓(CE) | ✓(CWE) | |
| 7 | Initial Quantity | NM | O | | | — | ✓ | ✓ | |
| 8 | Current Quantity | NM | O | | | — | ✓ | ✓ | |
| 9 | Available Quantity | NM | O | | | — | ✓ | ✓ | |
| 10 | Consumption Quantity | NM | O | | | — | ✓ | ✓ | |
| 11 | Quantity Units | CE/CWE | O | | | — | ✓(CE) | ✓(CWE) | code^text |
| 12 | Expiration Date/Time | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | |
| 13 | First Used Date/Time | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | |
| 14 | On Board Stability Duration | TQ | B | | | — | ✓(B) | deprecated | Deprecated |
| 15 | Test/Fluid Identifier(s) | CE/CWE | O | Y | | — | ✓(CE) | ✓(CWE) | Repeatable |
| 16 | Manufacturer Lot Number | ST | O | | | — | ✓ | ✓ | |
| 17 | Manufacturer Identifier | CE/CWE | O | | 0385 | — | ✓(CE) | ✓(CWE) | |
| 18 | Supplier Identifier | CE/CWE | O | | 0386 | — | ✓(CE) | ✓(CWE) | |
| 19 | On Board Stability Time | CQ | O | | | — | ✓ | ✓ | |
| 20 | Target Value | CQ | O | | | — | ✓ | ✓ | |

## Coded Fields
### INV-2 Substance Status (Table 0383)
EW (Expired Warning), EE (Expired Error), CW (Calibration Warning), CE (Calibration Error), QW (QC Warning), QE (QC Error), NW (Not Available Warning), NE (Not Available Error), OW (Other Warning), OE (Other Error), OK (OK)

### INV-3 Substance Type (Table 0384)
SR/MR/DI/PT/RC/CO/PW/LW/SW/SC/LI/OT

## Project-Specific Field Maps
This library uses INV in three different layouts — see `INVSegment.kt` comments for the compact, device-sync (Parata), and count-result accessor groups.
