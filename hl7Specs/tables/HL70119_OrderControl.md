# HL7 Table 0119 — Order Control Codes

Used in: ORC-1

## Primary Codes (used in this project)

| Value | Description | Initiator | Notes |
|-------|-------------|-----------|-------|
| NW | New order | Placer | New prescription |
| RF | Refill order request | Placer | Refill request |
| CA | Cancel order request | Placer | Cancel order |
| DC | Discontinue order request | Placer | Discontinue |
| HD | Hold order request | Placer | Put on hold |
| OH | Order held | Filler | Confirmation of hold |
| OK | Order accepted & OK | Filler | Order accepted |
| UA | Unable to accept order | Filler | Rejection |
| SC | Status changed | Filler | Status update |
| OC | Order canceled | Filler | Canceled confirmation |
| OD | Order discontinued | Filler | Discontinued confirmation |
| AF | Order refill request approval | Filler | Refill approved |
| DF | Order refill request denied | Filler | Refill denied |
| FU | Order refilled, unsolicited | Filler | Proactive refill notification |
| RP | Order replace request | Placer | Replace order |
| RO | Replacement order | Filler | Replacement |
| XO | Change order request | Placer | Modify order |
| RE | Observations to follow | Filler | Results attached |

## Initiator Patterns
- Placer → Filler: NW, RF, CA, DC, HD, RP, XO
- Filler → Placer: OK, UA, OH, SC, OC, OD, AF, DF, FU, RO, RE
