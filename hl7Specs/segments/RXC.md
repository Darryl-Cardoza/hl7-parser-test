# RXC — Pharmacy/Treatment Component Order

> Chapters: v2.3.1 §4 | v2.5.1 §4.14.3 | v2.8.2 §4A

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | RX Component Type | ID | R | | 0166 | ✓ | ✓ | ✓ | A=Additive, B=Base |
| 2 | Component Code | CE/CWE | R | | | ✓(CE) | ✓(CE) | ✓(CWE) | code^name^codeSystem |
| 3 | Component Amount | NM | R | | | ✓ | ✓ | ✓ | Numeric |
| 4 | Component Units | CE/CWE | R | | | ✓(CE) | ✓(CE) | ✓(CWE) | code^text |
| 5 | Component Strength | NM | O | | | ✓ | ✓ | ✓ | |
| 6 | Component Strength Units | CE/CWE | O | | | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 7 | Supplementary Code | CE/CWE | O | Y | | — | ✓(CE) | ✓(CWE) | v2.5.1+ |
| 8 | Component Drug Strength Volume | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 9 | Component Drug Strength Volume Units | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 10 | Dispense Amount | NM | O | | | — | — | ✓ | v2.8.2 only |
| 11 | Dispense Units | CWE | O | | | — | — | ✓ | v2.8.2 only |

## Coded Fields
- RXC-1: Table 0166 — A (Additive), B (Base)
