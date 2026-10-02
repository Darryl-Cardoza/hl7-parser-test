package org.rite.hl7.registry

import org.rite.hl7.model.SegmentRegistry
import org.rite.hl7.model.segment.ZINSegment
import org.rite.hl7.model.segment.ZNISegment
import org.rite.hl7.model.segment.ZPRSegment
import org.rite.hl7.model.segment.ZUISegment
import kotlin.test.Test
import kotlin.test.assertTrue

class RegistryCleanupTest {

    // ZIN and ZPR remain registered because HL7Validator and OrderGroup consume them
    // as typed segments — unregistering breaks typed parsing. See ledger ruling Task 5.

    @Test fun zin_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZINSegment.NAME), "ZIN must remain registered (used by validator)")
    }

    @Test fun zpr_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZPRSegment.NAME), "ZPR must remain registered (used by validator and OrderGroup)")
    }

    @Test fun zni_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZNISegment.NAME), "ZNI must remain registered")
    }

    @Test fun zui_still_registered() {
        val registry = SegmentRegistry()
        assertTrue(registry.isRegistered(ZUISegment.NAME), "ZUI must remain registered")
    }
}
