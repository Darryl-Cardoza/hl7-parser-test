# ACK — General Acknowledgment

> Spec: v2.3.1 §2 | v2.5.1 §2 | v2.8.2 §2

## Message Structure

```
MSH                    — Required; mirrors original MSH with sender/receiver swapped
MSA                    — Required
[ERR]                  — Optional, repeating; one per error
```

## MSH Construction Rules
- MSH-3 (Sending Application) ← original MSH-5 (Receiving Application)
- MSH-4 (Sending Facility) ← original MSH-6 (Receiving Facility)
- MSH-5 (Receiving Application) ← original MSH-3 (Sending Application)
- MSH-6 (Receiving Facility) ← original MSH-4 (Sending Facility)
- MSH-7: current timestamp
- MSH-9: ACK (no trigger event, or ACK^XX^ACK)
- MSH-10: new unique message control ID

## MSA Construction Rules
- MSA-1: AA (accept), AE (application error), AR (reject)
- MSA-2: original MSH-10 (echoed)
- MSA-3: deprecated — leave empty

## ERR Segment (v2.5.1+)
When MSA-1 = AE:
- ERR-2: segment location (segment^seq^field)
- ERR-3: HL7 error code (Table 0357)
- ERR-4: Severity (E=Error, W=Warning, I=Info)
- ERR-5: Application error code
- ERR-8: User message (human-readable reason)

## Required Fields
- MSH-9 = ACK
- MSA-1 ∈ {AA, AE, AR}
- MSA-2 = original message control ID
