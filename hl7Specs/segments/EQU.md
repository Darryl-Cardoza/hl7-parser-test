# EQU — Equipment Detail

> Chapters: v2.5.1 §13.4.1 | v2.8.2 §13  
> **NOT present in v2.3.1** — introduced in v2.4

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Equipment Instance Identifier | EI | R | N→Y | | — | ✓(N) | ✓(Y) | v2.8.2: repeatable (hierarchical IDs) |
| 2 | Event Date/Time | TS/DTM | R | | | — | ✓(TS) | ✓(DTM) | TS→DTM in v2.8.2 |
| 3 | Equipment State | CE/CWE | C | | 0365 | — | ✓(CE) | ✓(CWE) | CE→CWE v2.8.2 |
| 4 | Local/Remote Control State | CE/CWE | O | | 0366 | — | ✓(CE) | ✓(CWE) | L/R/U |
| 5 | Alert Level | CE/CWE | O | | 0367 | — | ✓(CE) | ✓(CWE) | C/N/S/W |

## Coded Fields
### EQU-3 Equipment State (Table 0365)
IN/CO/PU/RS/ID/OP/CL/PA/PD/ES/DC/DI/UNK

### EQU-4 Local/Remote Control State (Table 0366)
L (Local), R (Remote), U (Unknown)

### EQU-5 Alert Level (Table 0367)
C (Critical), N (Normal), S (Serious), W (Warning)

## Wire Shape Note
Some devices prefix a bare sequence number before the ID composite (field 1 has no second component but field 2 does). Current parser handles this via `idField` detection. This is a vendor deviation, not in spec.
