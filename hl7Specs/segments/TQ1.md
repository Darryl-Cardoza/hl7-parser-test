# TQ1 — Timing/Quantity

> Chapters: v2.5.1 §4.5.4 | v2.8.2 §4  
> **NOT present in v2.3.1** — use ORC-7 TQ composite instead

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Set ID - TQ1 | SI | O | | | — | ✓ | ✓ | |
| 2 | Quantity | CQ | O | | | — | ✓ | ✓ | value^units |
| 3 | Repeat Pattern | RPT | O | Y | 0335 | — | ✓ | ✓ | BID/TID/QID/PRN/... |
| 4 | Explicit Time | TM | O | Y | | — | ✓ | ✓ | |
| 5 | Relative Time and Units | CQ | O | Y | | — | ✓ | ✓ | |
| 6 | Service Duration | CQ | O | | | — | ✓ | ✓ | |
| 7 | Start date/time | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | TS→DTM in v2.8.2 |
| 8 | End date/time | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | TS→DTM in v2.8.2 |
| 9 | Priority | CWE | O | Y | 0485 | — | ✓ | ✓ | S/A/R/P/C/PRN/T/UD |
| 10 | Condition text | TX | O | | | — | ✓ | ✓ | |
| 11 | Text instruction | TX | O | | | — | ✓ | ✓ | |
| 12 | Conjunction | ID | C | | 0427→0472 | — | ✓(0427) | ✓(0472) | Table changed v2.8.2 |
| 13 | Occurrence duration | CQ | O | | | — | ✓ | ✓ | |
| 14 | Total occurrences | NM | O | | | — | ✓ | ✓ | |

## Coded Fields
### TQ1-9 Priority (Table 0485)
| Value | Description |
|-------|-------------|
| S | Stat — fill immediately |
| A | ASAP — fill after Stat |
| R | Routine |
| P | Preop |
| C | Callback |
| PRN | As needed |
| T | Timing critical |
| UD | Use as directed |

### TQ1-3 Repeat Pattern (Table 0335, selected values)
BID, TID, QID, QAM, QPM, QHS, Q4H, Q6H, Q8H, Q12H, Q1D, QWK, PRN, C (continuous)

## v2.3.1 Compatibility
In v2.3.1 messages, timing is in ORC-7 (TQ composite): quantity^interval^duration^startDateTime^endDateTime^priority^condition^text^conjunction^orderSequencing^occurrenceDuration^totalOccurrences
