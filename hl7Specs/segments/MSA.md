# MSA — Message Acknowledgment

> Chapters: v2.3.1 §2.24.2 | v2.5.1 §2.15.8 | v2.8.2 §2

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Acknowledgment Code | ID | R | | 0008 | ✓ | ✓ | ✓ | AA/AE/AR/CA/CE/CR |
| 2 | Message Control ID | ST | R | | | ✓ | ✓ | ✓ | Echoes MSH-10 of original |
| 3 | Text Message | ST | O→B→W | | | ✓(O) | ✓(B) | W | Deprecated v2.4, withdrawn v2.8 |
| 4 | Expected Sequence Number | NM | O | | | ✓ | ✓ | ✓ | |
| 5 | Delayed Acknowledgment Type | ID | B→W | | 0102 | ✓(B) | W | W | Withdrawn |
| 6 | Error Condition | CE | O→B→W | | 0357 | ✓(O) | ✓(B) | W | Withdrawn v2.8; use ERR segment |
| 7 | Message Waiting Number | NM | O | | | — | ✓ | ✓ | v2.5.1+ |
| 8 | Message Waiting Priority | ID | O | | 0520 | — | ✓ | ✓ | v2.5.1+; H/M/L |

## Coded Fields (Tables)
- MSA-1: Table 0008 — AA (Accept), AE (Error), AR (Reject), CA/CE/CR (enhanced mode)
- MSA-8: Table 0520 — H (High), M (Medium), L (Low)

## ACK Construction Rules
- MSA-1 = AA if message accepted, AE if application error, AR if reject
- MSA-2 = original MSH-10 (message control ID)
- MSA-3 deprecated — do not populate in v2.5.1+
- Use ERR segment for error detail instead of MSA-6
