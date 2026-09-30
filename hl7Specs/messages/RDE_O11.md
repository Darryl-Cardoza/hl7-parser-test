# RDE^O11 — Pharmacy/Treatment Encoded Order

> Spec: v2.3.1 §4 | v2.5.1 §4.14.1 | v2.8.2 §4

## Message Structure

```
MSH                    — Required, always first
PID                    — Required
[PV1]                  — Optional
{                      — Order group, repeating (1..*)
  ORC                  — Required per group
  [TQ1]                — Optional (v2.5.1+); v2.3.1 uses ORC-7
  RXE                  — Required per group
  {RXR}                — Required, repeating (1..*)
  [{RXC}]              — Optional, repeating
  [ZUI]                — Project extension: order data packet
}
[NTE]                  — Optional notes
```

## Required Fields
- MSH-9: RDE^O11
- MSH-10: Message Control ID (non-empty)
- MSH-12: Version ID
- PID-3: Patient Identifier List
- PID-5: Patient Name
- ORC-1: Order Control (NW for new order, RF for refill)
- ORC-2 or ORC-3: Placer OR Filler Order Number (at least one)
- RXE-2: Give Code (drug identifier)
- RXE-3: Give Amount Minimum (numeric)
- RXE-5: Give Units

## Validation Rules
- ORC-1 must be a known Table 0119 value
- RXE-3 must be numeric and positive
- RXE-2.1 (NDC) must not be empty
- Each order group must have at least one RXR
- TQ1 present → v2.5.1+; if present in v2.3.1 message, it is a vendor extension
