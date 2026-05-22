package org.rite.hl7.domain.model

// ==================== INVENTORY RESPONSE ITEM ====================
// Groups one INV segment with its associated ZIN rows for a single drug.
// Used in INR^U05 inventory count response messages.
// The library emits them interleaved: INV then its ZINs, then the next INV, etc.
//
// ZIN rows use ZinData — the same model used by the parser.
// setId on each ZinData must match this item's setId.

data class InventoryResponseItem(

    /** INV-1: Sequence index (1-based) **/
    val setId: Int,

    /** INV-2: Substance identifier NDC code (INV-2.1) **/
    val ndc: String,

    /** INV-2: Drug name / description (INV-2.2) **/
    val drugName: String? = null,

    /** INV-11: Total quantity count (opened + sealed) **/
    val totalQuantity: Int,

    /** ZIN rows for this drug — OPENED, SEALED, NA, or EXPECTED_ON_HAND **/
    val zinRows: List<ZinData> = emptyList()
)
