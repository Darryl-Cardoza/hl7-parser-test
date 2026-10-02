# MSH — Message Header

> Chapters: v2.3.1 §2.24.1 | v2.5.1 §2.15.9 | v2.8.2 §2

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Field Separator | ST | R | | | ✓ | ✓ | ✓ | |
| 2 | Encoding Characters | ST | R | | | ✓ | ✓ | ✓ | v2.8.2: 5 chars (adds truncation char) |
| 3 | Sending Application | HD | O | | 0361 | ✓ | ✓ | ✓ | |
| 4 | Sending Facility | HD | O | | 0362 | ✓ | ✓ | ✓ | |
| 5 | Receiving Application | HD | O | | 0361 | ✓ | ✓ | ✓ | |
| 6 | Receiving Facility | HD | O | | 0362 | ✓ | ✓ | ✓ | |
| 7 | Date/Time of Message | TS/DTM | O→R | | | ✓ | ✓(R) | ✓(DTM) | v2.5.1 made R; v2.8.2 changed TS→DTM |
| 8 | Security | ST | O | | | ✓ | ✓ | ✓ | |
| 9 | Message Type | CM/MSG | R | | 0076 | ✓(CM) | ✓(MSG) | ✓(MSG) | v2.5.1 changed CM→MSG composite |
| 10 | Message Control ID | ST | R | | | ✓ | ✓ | ✓ | |
| 11 | Processing ID | PT | R | | 0003 | ✓ | ✓ | ✓ | |
| 12 | Version ID | VID | R | | | ✓ | ✓ | ✓ | |
| 13 | Sequence Number | NM | O | | | ✓ | ✓ | ✓ | |
| 14 | Continuation Pointer | ST | O | | | ✓ | ✓ | ✓ | |
| 15 | Accept Acknowledgment Type | ID | O | | 0155 | ✓ | ✓ | ✓ | |
| 16 | Application Acknowledgment Type | ID | O | | 0155 | ✓ | ✓ | ✓ | |
| 17 | Country Code | ID | O | | 0104/0399 | ✓ | ✓ | ✓ | Table changed to 0399 in v2.5.1 |
| 18 | Character Set | ID | O | Y | 0211 | ✓ | ✓ | ✓ | |
| 19 | Principal Language of Message | CE/CWE | O | | | ✓ | ✓(CE) | ✓(CWE) | CE→CWE in v2.8.2 |
| 20 | Alternate Character Set Handling Scheme | ID | O | | 0356 | ✓ | ✓ | ✓ | |
| 21 | Message Profile Identifier | EI | O | Y | | — | ✓ | ✓ | v2.5.1+ only |
| 22 | Sending Responsible Organization | XON | O | | | — | — | ✓ | v2.8.2 only |
| 23 | Receiving Responsible Organization | XON | O | | | — | — | ✓ | v2.8.2 only |
| 24 | Sending Network Address | HD | O | | | — | — | ✓ | v2.8.2 only |
| 25 | Receiving Network Address | HD | O | | | — | — | ✓ | v2.8.2 only |

## MSH-9 Message Type Components (MSG)
- MSH-9.1: Message Code (e.g., RDE, RDS, ACK) — Table 0076
- MSH-9.2: Trigger Event (e.g., O11, O13, O25) — Table 0003
- MSH-9.3: Message Structure (e.g., RDE_O11) — Table 0354

## Coded Fields (Tables)
- MSH-15, MSH-16: Table 0155 — AL/ER/NE/SU
- MSH-11 Processing ID: P=Production, D=Debugging, T=Training
