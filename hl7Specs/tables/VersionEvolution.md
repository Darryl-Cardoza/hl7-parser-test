# HL7 Version Evolution Summary

## Data Type Changes

| Feature | v2.3.1 | v2.5.1 | v2.8.2 |
|---------|--------|--------|--------|
| Date/Time type | TS | TS | DTM |
| Coded Element | CE | CE | CWE |
| ORC-8 Parent type | CM | EIP | EIP |
| RXE-8 Deliver-to | CM | LA1 | LA1 |
| RXD-13 Dispense-to | CM | LA2 | LA2 |

## Segment Availability

| Segment | v2.3.1 | v2.5.1 | v2.8.2 |
|---------|--------|--------|--------|
| MSH | ✓ (20 fields) | ✓ (21 fields) | ✓ (25 fields) |
| MSA | ✓ (6 fields) | ✓ (8 fields) | ✓ (8 fields, MSA-3/5/6 withdrawn) |
| NTE | ✓ (4 fields) | ✓ (4 fields) | ✓ (8 fields) |
| BTS | ✓ (3 fields) | ✓ (3 fields) | ✓ (3 fields) |
| PID | ✓ (30 fields) | ✓ (39 fields) | ✓ (39+ fields) |
| PV1 | ✓ (50 fields) | ✓ (52 fields) | ✓ (54 fields) |
| ORC | ✓ (24 fields) | ✓ (30 fields) | ✓ (34 fields) |
| TQ1 | — | ✓ (14 fields) | ✓ (14 fields) |
| RXE | ✓ (24 fields) | ✓ (44 fields) | ✓ (45 fields) |
| RXD | ✓ (24 fields) | ✓ (33 fields) | ✓ (34 fields) |
| RXR | ✓ (5 fields) | ✓ (6 fields) | ✓ (6 fields) |
| RXC | ✓ (6 fields) | ✓ (9 fields) | ✓ (11 fields) |
| OBX | ✓ (17 fields) | ✓ (25 fields) | ✓ (38 fields) |
| EQU | — | ✓ (5 fields) | ✓ (5 fields) |
| INV | — | ✓ (20 fields) | ✓ (20 fields) |

## Deprecation / Withdrawal Timeline

| Field | Status |
|-------|--------|
| ORC-7 Quantity/Timing (TQ) | Deprecated v2.5.1 → withdrawn v2.7+ |
| RXE-1 Quantity/Timing (TQ) | Deprecated v2.5.1 → withdrawn v2.7+ |
| MSA-3 Text Message | Deprecated v2.4 → withdrawn v2.8 |
| MSA-5 Delayed Ack Type | Deprecated v2.3 → withdrawn v2.8 |
| MSA-6 Error Condition | Deprecated v2.4 → withdrawn v2.8 |
| PID-2 Patient ID | Deprecated (use PID-3) |
| PID-4 Alternate Patient ID | Deprecated (use PID-3 repeats) |
| PID-9 Patient Alias | Deprecated v2.5.1 |
| PID-12 County Code | Deprecated (use PID-11.6) |
| PID-19 SSN | Deprecated (use PID-3 with SS type) |
| INV-14 On Board Stability Duration | Deprecated v2.5.1 |
