# INR^U06 — Automated Equipment Inventory Request

> Spec: v2.5.1 §13 | v2.8.2 §13  
> Direction: PMS → Robot (request)

## Message Structure

```
MSH                    — Required
EQU                    — Required; equipment identifier
[QPD]                  — Optional; query parameters (NDC filter, etc.)
[RCP]                  — Optional; response control
```

## Required Fields
- MSH-9: INR^U06
- MSH-10: Message Control ID
- EQU-1: Equipment Instance Identifier
- EQU-2: Event Date/Time

## Notes
Robot responds with INU^U06 containing the inventory data.
