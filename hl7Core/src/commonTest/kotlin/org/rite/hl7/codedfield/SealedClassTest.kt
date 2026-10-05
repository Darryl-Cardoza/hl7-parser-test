package org.rite.hl7.codedfield

import org.rite.hl7.model.codedfield.*
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs

class SealedClassTest {

    @Test fun orderControlKnownRoundTrip() {
        assertEquals("NW", OrderControl.from("NW").code)
        assertEquals("CA", OrderControl.from("CA").code)
        assertIs<OrderControl.NW>(OrderControl.from("NW"))
    }

    @Test fun orderControlCaseInsensitive() {
        assertIs<OrderControl.NW>(OrderControl.from("nw"))
    }

    @Test fun orderControlUnknownPreservesRaw() {
        val u = OrderControl.from("ZZ")
        assertIs<OrderControl.Unknown>(u)
        assertEquals("ZZ", u.raw)   // raw preserved, NOT uppercased
        assertEquals("ZZ", u.code)
    }

    @Test fun ackCodeKnownRoundTrip() {
        assertIs<AckCode.AA>(AckCode.from("AA"))
        assertIs<AckCode.AE>(AckCode.from("AE"))
        assertIs<AckCode.AR>(AckCode.from("AR"))
    }

    @Test fun ackCodeUnknownPreservesRaw() {
        val u = AckCode.from("XY")
        assertIs<AckCode.Unknown>(u)
        assertEquals("XY", u.raw)
    }

    @Test fun orderStatusKnownRoundTrip() {
        assertIs<OrderStatus.CM>(OrderStatus.from("CM"))
        assertEquals("CM", OrderStatus.from("CM").code)
    }

    @Test fun orderStatusUnknown() {
        assertIs<OrderStatus.Unknown>(OrderStatus.from("??"))
    }

    @Test fun obsResultStatusKnownRoundTrip() {
        assertIs<ObsResultStatus.F>(ObsResultStatus.from("F"))
        assertIs<ObsResultStatus.P>(ObsResultStatus.from("P"))
    }

    @Test fun substitutionStatusKnownRoundTrip() {
        assertIs<SubstitutionStatus.G>(SubstitutionStatus.from("G"))
        assertIs<SubstitutionStatus.NoSelection>(SubstitutionStatus.from("0"))
    }

    @Test fun priorityKnownRoundTrip() {
        assertIs<Priority.S>(Priority.from("S"))
        assertIs<Priority.PRN>(Priority.from("PRN"))
        assertIs<Priority.PRN>(Priority.from("prn"))
    }

    @Test fun equipmentStateKnownRoundTrip() {
        assertIs<EquipmentState.OP>(EquipmentState.from("OP"))
        assertIs<EquipmentState.UNK>(EquipmentState.from("UNK"))
        assertIs<EquipmentState.A>(EquipmentState.from("A"))
        assertIs<EquipmentState.I>(EquipmentState.from("I"))
    }

    @Test fun equipmentStateActiveIdleCodePreserved() {
        assertEquals("A", EquipmentState.from("A").code)
        assertEquals("I", EquipmentState.from("I").code)
    }

    @Test fun substanceStatusKnownRoundTrip() {
        assertIs<SubstanceStatus.OK>(SubstanceStatus.from("OK"))
        assertIs<SubstanceStatus.EW>(SubstanceStatus.from("EW"))
    }

    @Test fun substanceStatusUnknownPreservesRaw() {
        val u = SubstanceStatus.from("XX")
        assertIs<SubstanceStatus.Unknown>(u)
        assertEquals("XX", u.raw)
    }
}
