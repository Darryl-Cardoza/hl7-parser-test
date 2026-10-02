# PV1 — Patient Visit

> Chapters: v2.3.1 §3 | v2.5.1 §3.4.3 | v2.8.2 §3

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Set ID - PV1 | SI | O | | | ✓ | ✓ | ✓ | |
| 2 | Patient Class | IS/CWE | R | | 0004 | ✓(IS) | ✓(IS) | ✓(CWE) | E/I/O/P/R/B/C/N/U |
| 3 | Assigned Patient Location | PL | O | | | ✓ | ✓ | ✓ | pointOfCare^room^bed^facility |
| 4 | Admission Type | IS/CWE | O | | 0007 | ✓ | ✓ | ✓(CWE) | A/C/E/L/N/R/U |
| 7 | Attending Doctor | XCN | O | Y | 0010 | ✓ | ✓ | ✓ | id^family^given |
| 8 | Referring Doctor | XCN | O | Y | 0010 | ✓ | ✓ | ✓ | |
| 9 | Consulting Doctor | XCN | O | Y | 0010 | ✓ | ✓ | ✓ | |
| 10 | Hospital Service | IS/CWE | O | | 0069 | ✓ | ✓ | ✓(CWE) | |
| 17 | Admitting Doctor | XCN | O | | 0010 | ✓ | ✓ | ✓ | |
| 18 | Patient Type | IS/CWE | O | | 0018 | ✓ | ✓ | ✓(CWE) | Site-defined |
| 19 | Visit Number | CX | O | | | ✓ | ✓ | ✓ | |
| 20 | Financial Class | FC | O | Y | 0064 | ✓ | ✓ | ✓ | |
| 36 | Discharge Disposition | IS/CWE | O | | 0112 | ✓ | ✓ | ✓(CWE) | |
| 44 | Admit Date/Time | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 45 | Discharge Date/Time | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 50 | Alternate Visit ID | CX | O | | 0203 | ✓ | ✓ | ✓ | |
| 51 | Visit Indicator | IS/CWE | O | | 0326 | — | ✓ | ✓(CWE) | v2.5.1+ |
| 52 | Other Healthcare Provider | XCN | B | Y | 0010 | — | ✓(B) | ✓(B) | v2.5.1+; deprecated |
| 53 | Service Episode Description | ST | O | | | — | — | ✓ | v2.8.2 only |
| 54 | Service Episode Identifier | CX | O | | | — | — | ✓ | v2.8.2 only |

## Key Components
- PV1-3 (Assigned Patient Location) PL: pointOfCare ^ room ^ bed ^ facility ^ locationStatus ^ personLocationType ^ building ^ floor

## Coded Fields
- PV1-2: Table 0004 — E/I/O/P/R/B/C/N/U
- PV1-4: Table 0007 — A/C/E/L/N/R/U
