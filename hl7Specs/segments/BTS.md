# BTS — Batch Trailer Segment

> Chapters: v2.3.1 §2 | v2.5.1 §2 | v2.8.2 §2  
> Identical across all three versions.

## Field Definitions

| SEQ | Field Name | DT | OPT | RP | TBL | v2.3.1 | v2.5.1 | v2.8.2 | Notes |
|-----|-----------|-----|-----|----|-----|--------|--------|--------|-------|
| 1 | Batch Message Count | ST | O | | | ✓ | ✓ | ✓ | Repurposed: chunk index in this project |
| 2 | Batch Comment | ST | O | | | ✓ | ✓ | ✓ | Repurposed: total chunk count |
| 3 | Batch Totals | NM | O | Y | | ✓ | ✓ | ✓ | Repeatable; this chunk's item total |

## Project Usage
BTS is used as a per-message trailer (not inside BHS/BTS batch envelope) to track inventory sync chunks:
- BTS-1: chunk index (1-based)
- BTS-2: total chunk count
- BTS-3: item count in this chunk
