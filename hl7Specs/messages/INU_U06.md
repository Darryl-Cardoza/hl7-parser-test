# INU^U06 — Automated Equipment Inventory Update

> Spec: v2.5.1 §13 | v2.8.2 §13  
> Direction: Robot → PMS (response/unsolicited)

## Message Structure

```
MSH                    — Required
EQU                    — Required; equipment identifier
{                      — Inventory group, repeating (1..*)
  INV                  — Required per group; one drug row
  [{OBX}]              — Optional; count detail observations
  [{NTE}]              — Optional; notes
}
```

## Required Fields
- MSH-9: INU^U06
- MSH-10: Message Control ID
- EQU-1: Equipment Instance Identifier
- EQU-2: Event Date/Time
- INV-1: Substance Identifier (drug)
- INV-2: Substance Status

## Notes
Sent by robot as cycle-count result or in response to INR^U06.
