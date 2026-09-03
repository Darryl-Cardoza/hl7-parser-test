package org.rite.hl7

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class HL7WorkflowsInventoryRequestTest {

    private val workflows = HL7Workflows()

    @Test
    fun parsesAllDataFromValidInventoryRequest() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L\r" +
            "INV|00067-5680-34^METFORMIN 500MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_B2^Cell B2^L"

        val result = workflows.parseInventoryRequest(raw)

        assertTrue(result.isSuccess)
        val request = result.getOrThrow()
        assertEquals("MSG00001", request.messageId)
        assertEquals("20251113190000", request.timestamp)
        assertEquals("ROBOT1", request.robotId)
        assertEquals("A", request.equipmentState)
        assertEquals(2, request.items.size)

        val first = request.items[0]
        assertEquals("00069-3820-20", first.ndc)
        assertEquals("LISINOPRIL 10MG TAB", first.name)
        assertEquals("A", first.statusCode)
        assertEquals("Active", first.statusDesc)
        assertEquals("DRUG", first.typeCode)
        assertEquals("Drug", first.typeDesc)
        assertEquals("CELL_A1", first.locationCode)
        assertEquals("Cell A1", first.locationName)
    }

    @Test
    fun parsesNoteCommentsWhenPresent() {
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
            "EQU|ROBOT1^Parata Max 2^MFG|20251113190000|A\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L\r" +
            "NTE|1||Verify inventory at Cell A1 location"

        val request = workflows.parseInventoryRequest(raw).getOrThrow()

        assertEquals(listOf("Verify inventory at Cell A1 location"), request.notes)
    }

    @Test
    fun parsesSuccessfullyWhenEquIsMissing() {
        // EQU is not consumed by the app — its absence must not block parsing.
        val raw = "MSH|^~\\&|PRIMERX|MAINPHARM|PARATA|ROBOT1|20251113190000||INR^U06|MSG00001|P|2.5.1\r" +
            "INV|00069-3820-20^LISINOPRIL 10MG TAB^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L"

        val result = workflows.parseInventoryRequest(raw)

        assertTrue(result.isSuccess)
        val request = result.getOrThrow()
        assertEquals("", request.robotId)
        assertEquals("", request.equipmentState)
        assertEquals(1, request.items.size)
    }

    @Test
    fun rejectsMessageThatIsNotAnInventoryRequest() {
        val raw = "MSH|^~\\&|A|B|C|D|20260101||INR^U05|1|P|2.5\r" +
            "INV|1|12345678901^x^NDC|||10|EA"

        val result = workflows.parseInventoryRequest(raw)

        assertTrue(result.isFailure)
    }
}
