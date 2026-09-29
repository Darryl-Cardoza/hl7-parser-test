package org.rite.hl7.codedfield

import org.rite.hl7.model.codedfield.*
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs

class SealedClassTest {

    @Test fun orderControl_known_round_trip() {
        assertEquals("NW", OrderControl.from("NW").code)
        assertEquals("CA", OrderControl.from("CA").code)
        assertIs<OrderControl.NW>(OrderControl.from("NW"))
    }

    @Test fun orderControl_case_insensitive() {
        assertIs<OrderControl.NW>(OrderControl.from("nw"))
    }

    @Test fun orderControl_unknown_preserves_raw() {
        val u = OrderControl.from("ZZ")
        assertIs<OrderControl.Unknown>(u)
        assertEquals("ZZ", u.raw)   // raw preserved, NOT uppercased
        assertEquals("ZZ", u.code)
    }

    @Test fun ackCode_known_round_trip() {
        assertIs<AckCode.AA>(AckCode.from("AA"))
        assertIs<AckCode.AE>(AckCode.from("AE"))
        assertIs<AckCode.AR>(AckCode.from("AR"))
    }

    @Test fun ackCode_unknown_preserves_raw() {
        val u = AckCode.from("XY")
        assertIs<AckCode.Unknown>(u)
        assertEquals("XY", u.raw)
    }

    @Test fun orderStatus_known_round_trip() {
        assertIs<OrderStatus.CM>(OrderStatus.from("CM"))
        assertEquals("CM", OrderStatus.from("CM").code)
    }

    @Test fun orderStatus_unknown() {
        assertIs<OrderStatus.Unknown>(OrderStatus.from("??"))
    }

    @Test fun obsResultStatus_known_round_trip() {
        assertIs<ObsResultStatus.F>(ObsResultStatus.from("F"))
        assertIs<ObsResultStatus.P>(ObsResultStatus.from("P"))
    }

    @Test fun substitutionStatus_known_round_trip() {
        assertIs<SubstitutionStatus.G>(SubstitutionStatus.from("G"))
        assertIs<SubstitutionStatus.NoSelection>(SubstitutionStatus.from("0"))
    }

    @Test fun priority_known_round_trip() {
        assertIs<Priority.S>(Priority.from("S"))
        assertIs<Priority.PRN>(Priority.from("PRN"))
        assertIs<Priority.PRN>(Priority.from("prn"))
    }

    @Test fun equipmentState_known_round_trip() {
        assertIs<EquipmentState.OP>(EquipmentState.from("OP"))
        assertIs<EquipmentState.UNK>(EquipmentState.from("UNK"))
    }

    @Test fun substanceStatus_known_round_trip() {
        assertIs<SubstanceStatus.OK>(SubstanceStatus.from("OK"))
        assertIs<SubstanceStatus.EW>(SubstanceStatus.from("EW"))
    }

    @Test fun substanceStatus_unknown_preserves_raw() {
        val u = SubstanceStatus.from("XX")
        assertIs<SubstanceStatus.Unknown>(u)
        assertEquals("XX", u.raw)
    }
}
