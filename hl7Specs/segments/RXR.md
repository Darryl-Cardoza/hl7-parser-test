# RXR — Pharmacy/Treatment Route

> Chapters: v2.3.1 §4 | v2.5.1 §4.14.2 | v2.8.2 §4A

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Route | CE/CWE | R | | 0162 | ✓(CE) | ✓(CE) | ✓(CWE) | PO/IV/IM/SC/... |
| 2 | Administration Site | CE/CWE | O | | 0163/0550 | ✓(CE,0163) | ✓(CWE,0163) | ✓(CWE,0550) | Table 0163→0550 in v2.8.2 |
| 3 | Administration Device | CE/CWE | O | | 0164 | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 4 | Administration Method | CE/CWE | O | | 0165 | ✓(CE) | ✓(CWE) | ✓(CWE) | |
| 5 | Routing Instruction | CE/CWE | O | | | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 6 | Administration Site Modifier | CWE | O | | 0495 | — | ✓ | ✓ | v2.5.1+ |

## Coded Fields
- RXR-1: Table 0162 — PO/IV/IM/SC/SL/OP/OT/PR/ID/IH/NG/TP/...
- RXR-4: Table 0165 — CH/DI/DU/IF/IS/IR/IVPB/IVP/NB/PT/PF/SH/SO/WA/WI
