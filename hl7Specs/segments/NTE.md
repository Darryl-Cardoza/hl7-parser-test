# NTE — Notes and Comments

> Chapters: v2.3.1 §2.24.15 | v2.5.1 §2.15.10 | v2.8.2 §2

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Set ID - NTE | SI | O | | | ✓ | ✓ | ✓ | |
| 2 | Source of Comment | ID | O | | 0105 | ✓ | ✓ | ✓ | L/O/P |
| 3 | Comment | FT | O | Y | | ✓ | ✓ | ✓ | Repeatable |
| 4 | Comment Type | CE/CWE | O | | 0364 | ✓(CE) | ✓(CE) | ✓(CWE) | CE→CWE v2.8.2 |
| 5 | Entered By | XCN | O | | | — | — | ✓ | v2.8.2 only |
| 6 | Entered Date/Time | DTM | O | | | — | — | ✓ | v2.8.2 only |
| 7 | Effective Start Date | DTM | O | | | — | — | ✓ | v2.8.2 only |
| 8 | Expiration Date | DTM | O | | | — | — | ✓ | v2.8.2 only |

## Coded Fields
- NTE-2: Table 0105 — L (Ancillary/filler), O (Other), P (Orderer/placer)
- NTE-4: Table 0364 — 1R/2R/AI/DR/GI/GR/PI/RE
