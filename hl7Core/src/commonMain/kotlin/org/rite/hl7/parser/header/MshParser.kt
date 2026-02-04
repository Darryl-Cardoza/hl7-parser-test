package org.rite.hl7.parser.header

import org.rite.hl7.domain.model.MessageHeaderData
import org.rite.hl7.parser.Hl7ParseException

/**
 * Parses the MSH segment and extracts message-level metadata.
 * MSH must be parsed first because it defines separators and message identity.
 */
fun mshParser(msh: String): MessageHeaderData {

    if (msh.length < 8)
        throw Hl7ParseException(
            "MSH segment too short",
            segment = msh
        )

    val fieldSep = msh[3].toString()

    /** Parsed encoding characters defining HL7 delimiters (MSH-2) **/
    val encodingChars =
        if (msh.length > 4 && msh[4] != fieldSep[0])
            msh.substring(4, minOf(8, msh.length))
        else "^~\\&"

    /** Split MSH segment into individual fields using field separator **/
    val fields = msh.split(fieldSep)
    val compSep = encodingChars.getOrNull(0)?.toString() ?: "^"
    val msgTypeParts = fields.getOrElse(8) { "" }.split(compSep)

    /** Build and return parsed MSH header data **/
    return MessageHeaderData(
        fieldSeparator = fieldSep,
        encodingCharacters = encodingChars,
        sendingApplication = fields.getOrElse(2) { "" },
        sendingFacility = fields.getOrElse(3) { "" },
        receivingApplication = fields.getOrElse(4) { "" },
        receivingFacility = fields.getOrElse(5) { "" },
        messageDateTime = fields.getOrElse(6) { "" },
        messageType = msgTypeParts.getOrNull(0) ?: "",
        triggerEvent = msgTypeParts.getOrNull(1) ?: "",
        messageControlId = fields.getOrElse(9) { "" },
        processingId = fields.getOrElse(10) { "" },
        versionId = fields.getOrElse(11) { "" },
        countryCode = fields.getOrNull(17)?.takeIf { it.isNotBlank() }
    )
}
