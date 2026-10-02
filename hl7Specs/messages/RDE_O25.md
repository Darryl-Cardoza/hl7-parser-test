# RDE^O25 — Pharmacy/Treatment Refill Authorization Request

> Spec: v2.5.1 §4 | v2.8.2 §4  
> Structure identical to RDE^O11 with different ORC-1 context (RF = refill)

## Message Structure

```
MSH                    — Required
PID                    — Required
[PV1]                  — Optional
{                      — Order group, repeating (1..*)
  ORC                  — Required per group; ORC-1 typically RF
  [TQ1]                — Optional
  RXE                  — Required per group
  {RXR}                — Required, repeating
  [{RXC}]              — Optional
  [ZUI]                — Project extension
}
[NTE]                  — Optional
```

## Differences from RDE^O11
- MSH-9: RDE^O25
- ORC-1 context: RF (refill request), AF (approval), DF (denied)
- Otherwise identical structure and required fields

## Required Fields
Same as RDE^O11; MSH-9 trigger event = O25.
