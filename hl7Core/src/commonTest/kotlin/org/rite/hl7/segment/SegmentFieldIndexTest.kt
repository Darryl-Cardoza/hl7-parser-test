package org.rite.hl7.segment

import org.rite.hl7.model.codedfield.AckCode
import org.rite.hl7.model.codedfield.EquipmentState
import org.rite.hl7.model.codedfield.ObsResultStatus
import org.rite.hl7.model.codedfield.OrderControl
import org.rite.hl7.model.codedfield.OrderStatus
import org.rite.hl7.model.codedfield.Priority
import org.rite.hl7.model.codedfield.SubstanceStatus
import org.rite.hl7.model.codedfield.SubstitutionStatus
import org.rite.hl7.model.segment.*
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.parser.HL7Parser
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs

class SegmentFieldIndexTest {

    private fun parse(hl7: String) =
        (HL7Parser.Builder().build().parse(hl7.trimIndent()) as HL7ParseResult.Success).message

    // --- ORC ---
    @Test fun orc_orderControl_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001||CM|||||20240101120000|||DOC001
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertIs<OrderControl.NW>(orc.orderControl)
        assertEquals("NW", orc.orderControl.code)
        assertEquals("NW", orc.orderControlRaw)
    }

    @Test fun orc_orderStatus_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001|||CM
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertIs<OrderStatus.CM>(orc.orderStatus)
    }

    @Test fun orc_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            ORC|NW|RX001|||||||20240101||||DOC001||20240101130000||ORG001
        """)
        val orc = msg.segment<ORCSegment>(ORCSegment.NAME)!!
        assertEquals("20240101130000", orc.orderEffectiveDateTime)
        assertEquals("ORG001", orc.enteringOrganization)
    }

    // --- MSA ---
    @Test fun msa_acknowledgmentCode_sealed() {
        val msg = parse("""
            MSH|^~\&|LIB|FAC|PMS|FAC|20240101120000||ACK^R01|CTL001|P|2.5
            MSA|AA|CTL001|OK
        """)
        val msa = msg.segment<MSASegment>(MSASegment.NAME)!!
        assertIs<AckCode.AA>(msa.acknowledgmentCode)
        assertEquals("AA", msa.acknowledgmentCodeRaw)
    }

    // --- TQ1 ---
    @Test fun tq1_priority_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            TQ1|1|||||||20240101|S
        """)
        val tq1 = msg.segment<TQ1Segment>(TQ1Segment.NAME)!!
        assertIs<Priority.S>(tq1.priority)
        assertEquals("S", tq1.priorityRaw)
    }

    // --- MSH new fields ---
    @Test fun msh_new_fields() {
        // MSH-9.3 messageStructure, MSH-14 continuationPointer, MSH-15/16 ack types
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11^RDE_O11|CTL001|P|2.5|||AL|NE
        """)
        val msh = msg.segment<MSHSegment>(MSHSegment.NAME)!!
        assertEquals("RDE_O11", msh.messageStructure)
        assertEquals("AL", msh.acceptAcknowledgmentType)
        assertEquals("NE", msh.applicationAcknowledgmentType)
    }

    // --- PID new fields ---
    @Test fun pid_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            PID|1||MRN001^^^HOS^PI||DOE^JOHN^M|||M||W|123 MAIN ST^^BOSTON^MA^02101^USA||(617)555-0100||EN|S||1001^^^ACC
        """)
        val pid = msg.segment<PIDSegment>(PIDSegment.NAME)!!
        assertEquals("W", pid.race)
        assertEquals("S", pid.maritalStatus)
        assertEquals("1001", pid.patientAccountNumber)
    }

    // --- PV1 new fields ---
    @Test fun pv1_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            PV1|1|I|W^101^A^GH|||||7101^SMITH^JOHN||MED|||||||||||1234^^^VN|||||||||||||||||20240101|||||20240201
        """)
        val pv1 = msg.segment<PV1Segment>(PV1Segment.NAME)!!
        assertEquals("7101", pv1.referringDoctorId)
        assertEquals("MED", pv1.hospitalService)
    }

    // --- RXD ---
    @Test fun rxd_substitutionStatus_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            RXD|1|00069015505^Drug^NDC|20240101|30|EA||RX001|||10|G
        """)
        val rxd = msg.segment<RXDSegment>(RXDSegment.NAME)!!
        assertIs<SubstitutionStatus.G>(rxd.substitutionStatus)
        assertEquals("G", rxd.substitutionStatusRaw)
    }

    @Test fun rxd_new_field() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            RXD|1|00069015505^Drug^NDC|20240101|30|EA||RX001|||10|G|||||||||||||||||||||BP
        """)
        val rxd = msg.segment<RXDSegment>(RXDSegment.NAME)!!
        assertEquals("BP", rxd.pharmacyOrderType)
    }

    // --- OBX ---
    @Test fun obx_resultStatus_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            OBX|1|NM|HEIGHT^Height^L||180|cm|||||F
        """)
        val obx = msg.segment<OBXSegment>(OBXSegment.NAME)!!
        assertIs<ObsResultStatus.F>(obx.resultStatus)
        assertEquals("F", obx.resultStatusRaw)
    }

    @Test fun obx_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            OBX|1|NM|HT^Height^L|SUB1|180|cm|100-200||||F|20240101|ACCESS||PROD001|RESP001|RESP001|EQ001|OBS001|METHOD|20240101130000
        """)
        val obx = msg.segment<OBXSegment>(OBXSegment.NAME)!!
        assertEquals("20240101", obx.effectiveDateOfReferenceRange)
        assertEquals("PROD001", obx.producersId)
    }

    // --- RXR ---
    @Test fun rxr_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            RXR|PO^Oral^HL70162|M^Mouth^HL70163|SPR|SLOW|ROUTING_NOTE
        """)
        val rxr = msg.segment<RXRSegment>(RXRSegment.NAME)!!
        assertEquals("SLOW", rxr.administrationMethod)
        assertEquals("ROUTING_NOTE", rxr.routingInstruction)
    }

    // --- RXC ---
    @Test fun rxc_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            RXC|A|00069015505^Drug^NDC|1|TAB|||SUPP|5.0
        """)
        val rxc = msg.segment<RXCSegment>(RXCSegment.NAME)!!
        assertEquals("SUPP", rxc.supplementaryCode)
        assertEquals("5.0", rxc.componentDrugStrengthVolume)
    }

    // --- EQU ---
    @Test fun equ_equipmentState_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            EQU|EQ001^Robot1^L|20240101120000|OP|L|W
        """)
        val equ = msg.segment<EQUSegment>(EQUSegment.NAME)!!
        assertIs<EquipmentState.OP>(equ.equipmentState)
        assertEquals("OP", equ.equipmentStateRaw)
        assertEquals("L", equ.localRemoteControlState)
        assertEquals("W", equ.alertLevel)
    }

    // --- INV ---
    @Test fun inv_substanceIdentifier_renamed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|NDC001^LISINOPRIL^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001
        """)
        val inv = msg.segment<INVSegment>(INVSegment.NAME)!!
        assertEquals("NDC001", inv.substanceIdentifier)
    }

    @Test fun inv_substanceStatus_sealed() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||INR^U06|CTL001|P|2.5
            INV|NDC001^LISINOPRIL^L|EW^Expired Warning^HL70383|DRUG^Drug^HL70384
        """)
        val inv = msg.segment<INVSegment>(INVSegment.NAME)!!
        assertIs<SubstanceStatus.EW>(inv.substanceStatus)
        assertEquals("EW", inv.substanceStatus.code)
    }

    // --- RXE ---
    @Test fun rxe_new_fields() {
        val msg = parse("""
            MSH|^~\&|PMS|FAC|LIB|FAC|20240101120000||RDE^O11|CTL001|P|2.5
            RXE||00069015505^Drug^NDC|30|60|TAB||||G||||DR001||RX001||||||||||||||||||||DEA_CLASS
        """)
        val rxe = msg.segment<RXESegment>(RXESegment.NAME)!!
        assertEquals("DEA_CLASS", rxe.deaClass)
        assertEquals("DR001", rxe.orderingProviderDeaNumber)
    }
}
