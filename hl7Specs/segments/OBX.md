# OBX — Observation/Result

> Chapters: v2.3.1 §7 | v2.5.1 §7.4.2 | v2.8.2 §7

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Set ID - OBX | SI | O | | | ✓ | ✓ | ✓ | |
| 2 | Value Type | ID | C | | 0125 | ✓ | ✓ | ✓ | NM/ST/TX/FT/CWE/TS/... |
| 3 | Observation Identifier | CE | R | | | ✓ | ✓ | ✓ | code^text^codeSystem |
| 4 | Observation Sub-ID | ST | C | | | ✓ | ✓ | ✓ | Links OBX to INV Set ID |
| 5 | Observation Value | varies | C | Y | | ✓ | ✓ | ✓ | Type per OBX-2 |
| 6 | Units | CE | O | | | ✓ | ✓ | ✓ | code^text |
| 7 | References Range | ST | O | | | ✓ | ✓ | ✓ | |
| 8 | Abnormal Flags / Interpretation Codes | ID/IS | O | Y/4 | 0078 | ✓(ID) | ✓(IS) | ✓ | Renamed v2.5.1 |
| 9 | Probability | NM | O | | | ✓ | ✓ | ✓ | |
| 10 | Nature of Abnormal Test | ID | O | Y | 0080 | ✓ | ✓ | ✓ | A/R/S/N/B/SP |
| 11 | Observation Result Status | ID | R | | 0085 | ✓ | ✓ | ✓ | F/P/C/R/S/I/D/U/W/X |
| 12 | Date Last Obs Normal Values | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 13 | User Defined Access Checks | ST | O | | | ✓ | ✓ | ✓ | |
| 14 | Date/Time of the Observation | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 15 | Producer's ID | CE | O | | | ✓ | ✓ | ✓ | |
| 16 | Responsible Observer | XCN | O | Y | | ✓ | ✓ | ✓ | |
| 17 | Observation Method | CE | O | Y | | ✓ | ✓ | ✓ | |
| 18 | Equipment Instance Identifier | EI | O | Y | | — | ✓ | ✓ | v2.5.1+ |
| 19 | Date/Time of the Analysis | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | v2.5.1+ |
| 23 | Performing Organization Name | XON | O | N→Y | | — | ✓(N) | ✓(Y) | v2.5.1+; became repeatable v2.8.2 |
| 24 | Performing Organization Address | XAD | O | N→Y | | — | ✓(N) | ✓(Y) | v2.5.1+ |
| 25 | Performing Organization Medical Director | XCN | O | N→Y | | — | ✓(N) | ✓(Y) | v2.5.1+ |
| 28 | Observation Site | CWE | O | Y | 0163 | — | — | ✓ | v2.8.2 only |
| 29 | Observation Instance Identifier | EI | O | | | — | — | ✓ | v2.8.2 only |
| 30 | Mood Code | CNE | C | | 0725 | — | — | ✓ | v2.8.2 only |
| 31–33 | (same as 23–25 in v2.8.2 numbering) | | | | | — | — | ✓ | v2.8.2 renumbered |
| 34 | Patient Results Release Category | ID | O | | 0909 | — | — | ✓ | v2.8.2 only |
| 35 | Root Cause | CWE | O | | 0914 | — | — | ✓ | v2.8.2 only |
| 36 | Local Process Control | CWE | O | Y | 0915 | — | — | ✓ | v2.8.2 only |

## Coded Fields
### OBX-11 Observation Result Status (Table 0085)
| Value | Description |
|-------|-------------|
| C | Correction |
| D | Delete |
| F | Final |
| I | Pending |
| N | Not asked |
| O | Order detail only |
| P | Preliminary |
| R | Results entered not verified |
| S | Partial |
| U | Final without retransmit |
| W | Wrong |
| X | Cannot obtain |

- OBX-8: Table 0078 — H/L/HH/LL/N/A/AA/U/D/W/B/...
- OBX-10: Table 0080 — A/R/S/N/B/SP
- OBX-2: Table 0125 — NM/ST/TX/FT/CWE/TS/DTM/...
