package org.rite.hl7.domain.model

/**
 * Typed representation of a parsed ZIN custom segment.
 *
 * ZIN segment formats used in this system:
 *
 *   Inventory count response (INR^U05):
 *     ZIN|<setId>|OPENED|<qty>|<lot>|<expiry>
 *     ZIN|<setId>|SEALED|<qty>|<lot>|<expiry>
 *     ZIN|<setId>|NA|0||
 *
 *   Inventory count with expected on-hand (extended):
 *     ZIN|<setId>|OPENED|<qty>|<lot>|<expiry>
 *     ZIN|<setId>|EXPECTED_ON_HAND|<qty>||
 *
 * ZIN-1 : set ID — links this ZIN to its parent INV row (same index)
 * ZIN-2 : dispense type / qualifier — OPENED | SEALED | NA | EXPECTED_ON_HAND
 * ZIN-3 : quantity
 * ZIN-4 : lot number (optional)
 * ZIN-5 : expiry date (optional)
 */
data class ZinData(

    /** ZIN-1: Set ID matching the parent INV segment index **/
    val setId: Int,

    /** ZIN-2: Qualifier — OPENED, SEALED, NA, EXPECTED_ON_HAND, or any custom value **/
    val dispenseType: String,

    /** ZIN-3: Quantity for this qualifier **/
    val quantity: Int,

    /** ZIN-4: Lot number (present for OPENED/SEALED rows, absent for NA/EXPECTED_ON_HAND) **/
    val lotNumber: String? = null,

    /** ZIN-5: Expiry date (present for OPENED/SEALED rows) **/
    val expiry: String? = null
) {
    /**
     * True when this ZIN row carries the expected on-hand count
     * (ZIN-2 = EXPECTED_ON_HAND). Used by inventory reconciliation logic.
     */
    val isExpectedOnHand: Boolean get() = dispenseType.uppercase() == "EXPECTED_ON_HAND"

    /**
     * True when there is no stock to report (ZIN-2 = NA).
     */
    val isNotAvailable: Boolean get() = dispenseType.uppercase() == "NA"
}
