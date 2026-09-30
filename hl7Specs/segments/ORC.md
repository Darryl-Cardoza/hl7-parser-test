# ORC — Common Order

> Chapters: v2.3.1 §4 | v2.5.1 §4.3.1 | v2.8.2 §4

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Order Control | ID | R | | 0119 | ✓ | ✓ | ✓ | NW/CA/DC/RF/OH/OK/UA/... |
| 2 | Placer Order Number | EI | C | | | ✓ | ✓ | ✓ | placerOrderNum^namespace |
| 3 | Filler Order Number | EI | C | | | ✓ | ✓ | ✓ | fillerOrderNum^namespace |
| 4 | Placer Group Number | EI | O | | | ✓ | ✓ | ✓ | |
| 5 | Order Status | ID | O | | 0038 | ✓ | ✓ | ✓ | IP/CM/CA/DC/HD/SC/A/RP/ER |
| 6 | Response Flag | ID | O | | 0121 | ✓ | ✓ | ✓ | D/E/F/N/R |
| 7 | Quantity/Timing | TQ | O→B | Y | | ✓(O) | ✓(B) | W | Deprecated v2.5.1; withdrawn v2.7+; use TQ1 |
| 8 | Parent | CM/EIP | O | | | ✓(CM) | ✓(EIP) | ✓(EIP) | Changed CM→EIP in v2.5.1 |
| 9 | Date/Time of Transaction | TS | O | | | ✓ | ✓ | ✓ | |
| 10 | Entered By | XCN | O | Y | | ✓ | ✓ | ✓ | |
| 11 | Verified By | XCN | O | Y | | ✓ | ✓ | ✓ | |
| 12 | Ordering Provider | XCN | O | Y | | ✓ | ✓ | ✓ | id^family^given |
| 13 | Enterer's Location | PL | O | | | ✓ | ✓ | ✓ | |
| 14 | Call Back Phone Number | XTN | O | Y/2 | | ✓ | ✓ | ✓ | Max 2 reps |
| 15 | Order Effective Date/Time | TS | O | | | ✓ | ✓ | ✓ | |
| 16 | Order Control Code Reason | CE | O | | | ✓ | ✓ | ✓ | |
| 17 | Entering Organization | CE | O | | | ✓ | ✓ | ✓ | |
| 18 | Entering Device | CE | O | | | ✓ | ✓ | ✓ | |
| 19 | Action By | XCN | O | Y | | ✓ | ✓ | ✓ | |
| 20 | Advanced Beneficiary Notice Code | CE/CWE | O | | 0339 | ✓ | ✓ | ✓(CWE) | |
| 21 | Ordering Facility Name | XON | O | Y | | ✓ | ✓ | ✓ | |
| 22 | Ordering Facility Address | XAD | O | Y | | ✓ | ✓ | ✓ | |
| 23 | Ordering Facility Phone Number | XTN | O | Y | | ✓ | ✓ | ✓ | |
| 24 | Ordering Provider Address | XAD | O | Y | | ✓ | ✓ | ✓ | |
| 25 | Order Status Modifier | CWE | O | | | — | ✓ | ✓ | v2.5.1+ |
| 26 | Advanced Beneficiary Notice Override Reason | CWE | C | | | — | ✓ | ✓ | v2.5.1+ |
| 27 | Filler's Expected Availability Date/Time | TS | O | | | — | ✓ | ✓ | v2.5.1+ |
| 28 | Confidentiality Code | CWE | O | | 0177 | — | ✓ | ✓ | v2.5.1+ |
| 29 | Order Type | CWE | O | | 0482 | — | ✓ | ✓ | v2.5.1+; I/O |
| 30 | Enterer Authorization Mode | CNE | O | | 0483 | — | ✓ | ✓ | v2.5.1+ |
| 31 | Parent Universal Service Identifier | CWE | O | | | — | — | ✓ | v2.8.2 only |
| 32 | Advanced Beneficiary Notice Date | DT | O | | | — | — | ✓ | v2.8.2 only |
| 33 | Alternate Placer Order Number | CX | O | Y | | — | — | ✓ | v2.8.2 only |
| 34 | Order Workflow Profile | CWE | O | Y | 0934 | — | — | ✓ | v2.8.2 only |

## Critical Coded Fields
### ORC-1 Order Control (Table 0119) — used for conditional logic
| Value | Description |
|-------|-------------|
| NW | New order |
| CA | Cancel order request |
| DC | Discontinue order request |
| RF | Refill order request |
| OH | Order held |
| OK | Order accepted & OK |
| UA | Unable to accept order |
| SC | Status changed |
| HD | Hold order request |
| OC | Order canceled |
| OD | Order discontinued |
| RP | Order replace request |
| RO | Replacement order |
| CR | Canceled as requested |
| DR | Discontinued as requested |
| AF | Order refill request approval |
| DF | Order refill request denied |
| FU | Order refilled, unsolicited |
| RE | Observations to follow |
| XO | Change order request |

### ORC-5 Order Status (Table 0038)
| Value | Description |
|-------|-------------|
| A | Some results available |
| CA | Canceled |
| CM | Completed |
| DC | Discontinued |
| ER | Error |
| HD | On hold |
| IP | In process |
| RP | Replaced |
| SC | Scheduled |

### ORC-29 Order Type (Table 0482)
| Value | Description |
|-------|-------------|
| I | Inpatient |
| O | Outpatient |
