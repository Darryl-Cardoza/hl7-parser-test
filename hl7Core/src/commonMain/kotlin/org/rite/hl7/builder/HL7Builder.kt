package org.rite.hl7.builder

import org.rite.hl7.domain.model.ObservationData
import org.rite.hl7.builder.header.buildMSH
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.order.buildORC
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.patient.buildPID
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.patient.buildPV1
import org.rite.hl7.builder.pharmacy.rxc.buildRXC
import org.rite.hl7.builder.pharmacy.rxd.buildRXD
import org.rite.hl7.builder.pharmacy.rxe.buildRXE
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.pharmacy.rxr.buildRXR
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.inventory.buildINVResponseSegment
import com.rite.pillcounting.core.hl7.hl7MessageHandler.builder.inventory.buildZINSegment
import org.rite.hl7.builder.observation.ObxVersionCapabilities
import org.rite.hl7.domain.model.AcknowledgmentData
import org.rite.hl7.domain.model.CompleteHL7Message
import org.rite.hl7.domain.model.CustomSegmentData
import org.rite.hl7.domain.model.ErrorData
import org.rite.hl7.hl7.domain.utils.HL7Constants
import org.rite.hl7.domain.utils.HL7Utils
import org.rite.hl7.domain.model.NoteData

/**
 * Comprehensive HL7 Message Builder
 * Converts CompleteHL7Message data class back to HL7 format
 * Supports all standard segments: MSH, PID, PV1, ORC, RXE, RXR, RXC, RXD, EQU, INV, MSA, ERR, NTE
 */
class HL7MessageBuilder {

    companion object {
        private const val FIELD_SEP = "|"
        private const val COMPONENT_SEP = "^"
        private const val REPETITION_SEP = "~"
        private const val ESCAPE_CHAR = "\\"
        private const val SUBCOMPONENT_SEP = "&"
    }

    // Tracks the HL7 version of the message being built, used for version-aware segment builders
    private var currentVersion: String = "2.5"

    /**
     * Build complete HL7 message from CompleteHL7Message data class
     */
    fun build(message: CompleteHL7Message): String {
        currentVersion = message.header.versionId
        val segments = mutableListOf<String>()
        // Required segments
        segments.add(buildMSH(message.header))

        // Patient segment (if present)
        message.patient?.let { segments.add(buildPID(it, currentVersion)) }

        // Visit segment (if present)
        message.visit?.let { segments.add(buildPV1(it, currentVersion)) }

        // Order segment (if present)
        message.order?.let { segments.add(buildORC(it, currentVersion)) }

        // Medication segments (if present)
        message.medications.forEach { segments.add(buildRXE(it, currentVersion)) }

        // Route segments (if present)
        message.routes.forEach { segments.add(buildRXR(it, currentVersion)) }

        // Component segments (if present)
        message.components.forEach { segments.add(buildRXC(it, currentVersion)) }

        // Dispense segments (if present)
        message.dispenses.forEach { segments.add(buildRXD(it, currentVersion)) }

        // Inventory count response: INV+ZIN interleaved per drug (INR^U05)
        message.inventoryResponseItems.forEach { item ->
            segments.add(buildINVResponseSegment(item, message.header.versionId))
            item.zinRows.forEach { row -> segments.add(buildZINSegment(item.setId, row)) }
        }

        // Acknowledgment segment (if present)
        message.acknowledgment?.let { segments.add(buildMSA(it)) }

        // Error segments (if present)
        message.errors.forEach { segments.add(buildERR(it)) }

        // Note segments (if present)
        message.notes.forEach { segments.add(buildNTE(it)) }

        // OBX Segment (if present)
        message.obxSegments.forEach { segments.add(buildObxSegment(it)) }
        // Custom Z-segments (if present)

        message.customSegments.forEach { segments.add(buildCustomSegment(it)) }

        return segments.joinToString(HL7Constants.SEGMENT_TERMINATOR) +
                HL7Constants.SEGMENT_TERMINATOR
    }

    /**
     * Build with MLLP framing for network transmission
     */
    fun buildWithMllp(message: CompleteHL7Message): ByteArray {
        val hl7String = build(message)
        val sb = byteArrayOf(0x0B)
        val eb = byteArrayOf(0x1C, 0x0D)
        return sb + hl7String.encodeToByteArray() + eb
    }

    // ==================== SEGMENT BUILDERS ====================


    private fun buildMSA(ack: AcknowledgmentData): String {
        return HL7Utils.buildSegment(
            "MSA",
            ack.acknowledgmentCode,
            ack.messageControlId,
            ack.textMessage ?: "",
            "", // Expected Sequence Number
            "", // Delayed Acknowledgment Type
            ack.errorCondition ?: ""
        )
    }

    private fun buildERR(error: ErrorData): String {
        // ERR-2: Error Location
        val errorLocation = buildComponent(
            error.segmentId ?: "",
            error.sequence ?: "",
            error.fieldPosition ?: ""
        )

        // ERR-3: HL7 Error Code
        val hl7ErrorCode = buildComponent(
            error.errorCode ?: "",
            error.errorDescription ?: ""
        )

        // ERR-5: Application Error Code
        val appErrorCode = buildComponent(
            error.applicationErrorCode ?: "",
            error.applicationErrorText ?: ""
        )

        return HL7Utils.buildSegment(
            "ERR",
            "", // Error Code and Location (deprecated)
            errorLocation,
            hl7ErrorCode,
            error.severity ?: "",
            appErrorCode,
            "", // Application Error Parameter
            error.diagnosticInfo ?: "",
            error.userMessage ?: ""
        )
    }

    private fun buildNTE(note: NoteData): String {
        return HL7Utils.buildSegment(
            "NTE",
            note.setId ?: "",
            note.sourceOfComment ?: "",
            note.comment,
            note.commentType ?: ""
        )
    }

    private fun buildCustomSegment(custom: CustomSegmentData): String {
        val fields = mutableListOf(custom.segmentType)

        // Add fields in order
        custom.allFields.forEach { (_, value) ->
            fields.add(value)
        }

        // Fallback if allFields is empty
        if (custom.allFields.isEmpty()) {
            listOfNotNull(
                custom.field1,
                custom.field2,
                custom.field3,
                custom.field4,
                custom.field5,
                custom.field6
            ).forEach { fields.add(it) }
        }

        return fields.joinToString(FIELD_SEP)
    }

    private fun buildObxSegment(obx: ObservationData): String {
        // OBX-3: Observation Identifier (code^text^codingSystem)
        val obsId = buildComponent(
            obx.observationId,
            obx.observationText ?: "",
            obx.codingSystem ?: ""
        )

        // Full OBX field list — positional, version-trimmed below
        val allFields = listOf(
            obx.setId,                              // OBX-1
            obx.valueType,                          // OBX-2
            obsId,                                  // OBX-3
            obx.subId ?: "",                        // OBX-4
            obx.observationValue,                   // OBX-5
            obx.units ?: "",                        // OBX-6
            obx.referenceRange ?: "",               // OBX-7
            obx.abnormalFlags ?: "",                // OBX-8
            obx.probability ?: "",                  // OBX-9
            obx.natureOfAbnormalTest ?: "",         // OBX-10
            obx.resultStatus,                       // OBX-11
            obx.effectiveDateOfReferenceRange ?: "", // OBX-12 (v2.2+)
            obx.userDefinedAccessChecks ?: "",      // OBX-13 (v2.2+)
            obx.dateTimeOfObservation ?: "",        // OBX-14 (v2.2+)
            obx.producerId ?: "",                   // OBX-15 (v2.2+)
            obx.responsibleObserver ?: "",          // OBX-16 (v2.2+)
            obx.observationMethod ?: "",            // OBX-17 (v2.2+)
            obx.equipmentInstanceIdentifier ?: "",  // OBX-18 (v2.4+)
            obx.dateTimeOfAnalysis ?: ""            // OBX-19 (v2.4+)
        )

        val maxField = ObxVersionCapabilities.maxField(currentVersion)
        val trimmed = allFields.take(maxField).dropLastWhile { it.isEmpty() }

        return buildString {
            append("OBX")
            append(FIELD_SEP)
            append(trimmed.joinToString(FIELD_SEP))
        }
    }


    // ==================== HELPER FUNCTIONS ====================

    private fun buildComponent(vararg parts: String): String {
        return parts.joinToString(COMPONENT_SEP) { it.ifEmpty { "" } }
            .trimEnd(COMPONENT_SEP[0])
    }

    /**
     * Escape special characters in HL7 text
     */
    private fun escapeHL7Text(text: String): String {
        return text
            .replace("\\", "\\E\\")
            .replace("|", "\\F\\")
            .replace("^", "\\S\\")
            .replace("~", "\\T\\")
            .replace("&", "\\R\\")
    }

    /**
     * Build message for specific message types with validation
     */
    fun buildTypedMessage(message: CompleteHL7Message): String {
        return when ("${message.messageType}^${message.triggerEvent}") {
            "RDE^O11" -> buildPharmacyOrder(message)
            "RDS^O13" -> buildDispenseMessage(message)
            "INU^U05" -> buildInventoryUpdate(message)
            "ACK^*" -> buildAcknowledgment(message)
            else -> build(message)
        }
    }

    private fun buildPharmacyOrder(message: CompleteHL7Message): String {
        require(message.patient != null) { "Patient segment required for RDE^O11" }
        require(message.order != null) { "Order segment required for RDE^O11" }
        require(message.medications.isNotEmpty()) { "At least one medication required for RDE^O11" }
        return build(message)
    }

    private fun buildDispenseMessage(message: CompleteHL7Message): String {
        require(message.patient != null) { "Patient segment required for RDS^O13" }
        require(message.order != null) { "Order segment required for RDS^O13" }
        require(message.dispenses.isNotEmpty()) { "At least one dispense required for RDS^O13" }

        // 🔥 Strip order-only segments
        val clean = message.copy(
            medications = emptyList(),
            routes = emptyList(),
            components = emptyList()
        )

        return build(clean)
    }

    private fun buildInventoryUpdate(message: CompleteHL7Message): String {
        require(message.inventory != null || message.inventoryResponseItems.isNotEmpty()) {
            "Inventory segment or inventoryResponseItems required for INU^U05"
        }
        return build(message)
    }

    private fun buildAcknowledgment(message: CompleteHL7Message): String {
        require(message.acknowledgment != null) { "Acknowledgment segment required for ACK" }
        return build(message)
    }
}

// ==================== CONVENIENCE EXTENSION FUNCTIONS ====================

/**
 * Extension function to build HL7 message from CompleteHL7Message
 */
fun CompleteHL7Message.toHL7String(): String {
    return HL7MessageBuilder().build(this)
}

/**
 * Extension function to build HL7 message with MLLP framing
 */
fun CompleteHL7Message.toHL7BytesWithMllp(): ByteArray {
    return HL7MessageBuilder().buildWithMllp(this)
}

/**
 * Extension function to build typed message with validation
 */
fun CompleteHL7Message.toTypedHL7String(): String {
    return HL7MessageBuilder().buildTypedMessage(this)
}