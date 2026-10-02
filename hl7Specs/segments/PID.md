# PID — Patient Identification

> Chapters: v2.3.1 §3 | v2.5.1 §3.4.2 | v2.8.2 §3

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Set ID - PID | SI | O | | | ✓ | ✓ | ✓ | |
| 2 | Patient ID | CX | B | | | ✓(B) | ✓(B) | ✓(B) | Deprecated |
| 3 | Patient Identifier List | CX | R | Y | | ✓ | ✓ | ✓ | Primary patient ID; CX components: id^check^checkscheme^authority^type |
| 4 | Alternate Patient ID | CX | B | Y | | ✓(B) | ✓(B) | ✓(B) | Deprecated |
| 5 | Patient Name | XPN | R | Y | 0200 | ✓ | ✓ | ✓ | family^given^middle^suffix^prefix |
| 6 | Mother's Maiden Name | XPN | O | Y | | ✓ | ✓ | ✓ | |
| 7 | Date/Time of Birth | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 8 | Administrative Sex | IS/CWE | O | | 0001 | ✓(IS) | ✓(IS) | ✓(CWE) | F/M/O/U/A/N |
| 9 | Patient Alias | XPN | O→B | Y | | ✓ | ✓(B) | ✓(B) | Deprecated v2.5.1 |
| 10 | Race | CE/CWE | O | Y | 0005 | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 11 | Patient Address | XAD | O | Y | | ✓ | ✓ | ✓ | street^other^city^state^zip^country |
| 12 | County Code | IS | B | | 0289 | ✓(B) | ✓(B) | ✓(B) | Deprecated |
| 13 | Phone Number - Home | XTN | O | Y | | ✓ | ✓ | ✓ | |
| 14 | Phone Number - Business | XTN | O | Y | | ✓ | ✓ | ✓ | |
| 15 | Primary Language | CE/CWE | O | | 0296 | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 16 | Marital Status | CE/CWE | O | | 0002 | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 17 | Religion | CE/CWE | O | | 0006 | ✓(CE) | ✓(CE) | ✓(CWE) | |
| 18 | Patient Account Number | CX | O | | 0061 | ✓ | ✓ | ✓ | |
| 19 | SSN Number | ST | B | | | ✓(B) | ✓(B) | ✓(B) | Deprecated |
| 20 | Driver's License Number | DLN | O | | | ✓ | ✓ | ✓ | |
| 21 | Mother's Identifier | CX | O | Y | | ✓ | ✓ | ✓ | |
| 22 | Ethnic Group | CE/CWE | O | Y | 0189 | ✓(CE) | ✓(CE) | ✓(CWE) | H/N/U |
| 23 | Birth Place | ST | O | | | ✓ | ✓ | ✓ | |
| 24 | Multiple Birth Indicator | ID | O | | 0136 | ✓ | ✓ | ✓ | Y/N |
| 25 | Birth Order | NM | O | | | ✓ | ✓ | ✓ | |
| 26 | Citizenship | CE/CWE | O | Y | 0171 | ✓(CE) | ✓(CE) | ✓(CWE) | ISO 3166 |
| 27 | Veterans Military Status | CE | O | | 0172 | ✓ | ✓ | ✓ | |
| 28 | Nationality | CE | O | | 0212 | ✓ | ✓ | ✓ | |
| 29 | Patient Death Date and Time | TS/DTM | O | | | ✓(TS) | ✓(TS) | ✓(DTM) | |
| 30 | Patient Death Indicator | ID | O | | 0136 | ✓ | ✓ | ✓ | Y/N |
| 31 | Identity Unknown Indicator | ID | O | | 0136 | — | ✓ | ✓ | v2.5.1+ |
| 32 | Identity Reliability Code | IS | O | Y | 0445 | — | ✓ | ✓ | v2.5.1+ |
| 33 | Last Update Date/Time | TS/DTM | O | | | — | ✓(TS) | ✓(DTM) | v2.5.1+ |
| 34 | Last Update Facility | HD | O | | | — | ✓ | ✓ | v2.5.1+ |
| 35 | Species Code | CE/CWE | C | | 0446 | — | ✓(CE) | ✓(CWE) | v2.5.1+ |
| 36 | Breed Code | CE/CWE | C | | 0447 | — | ✓(CE) | ✓(CWE) | v2.5.1+ |
| 37 | Strain | ST | O | | | — | ✓ | ✓ | v2.5.1+ |
| 38 | Production Class Code | CE/CWE | O | 2 | 0429 | — | ✓(CE) | ✓(CWE) | v2.5.1+; max 2 reps |
| 39 | Tribal Citizenship | CWE | O | Y | 0171 | — | ✓ | ✓ | v2.5.1+ |

## Key Components
- PID-3 (Patient Identifier List) CX: id ^ checkDigit ^ checkScheme ^ assigningAuthority ^ idType
- PID-5 (Patient Name) XPN: familyName ^ given ^ middle ^ suffix ^ prefix ^ degree
- PID-11 (Patient Address) XAD: street ^ other ^ city ^ state ^ zip ^ country

## Coded Fields
- PID-8: Table 0001 — F/M/O/U/A/N
- PID-16: Table 0002 — M/S/D/W/...
- PID-22: Table 0189 — H/N/U
- PID-24, PID-30, PID-31: Table 0136 — Y/N
