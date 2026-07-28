package org.rite.hl7

import org.rite.hl7.encoding.HL7Delimiters
import org.rite.hl7.encoding.HL7Escaping
import kotlin.test.Test
import kotlin.test.assertEquals

class EscapingTest {
    private val d = HL7Delimiters.DEFAULT

    @Test
    fun escapesEachDelimiter() {
        assertEquals("\\F\\", HL7Escaping.escape("|", d))
        assertEquals("\\S\\", HL7Escaping.escape("^", d))
        assertEquals("\\T\\", HL7Escaping.escape("&", d))
        assertEquals("\\R\\", HL7Escaping.escape("~", d))
        assertEquals("\\E\\", HL7Escaping.escape("\\", d))
    }

    @Test
    fun unescapeIsInverseOfEscape() {
        val raw = "a|b^c&d~e\\f"
        val escaped = HL7Escaping.escape(raw, d)
        assertEquals(raw, HL7Escaping.unescape(escaped, d))
    }

    @Test
    fun unknownEscapePassesThrough() {
        // \Z...\ is not a known escape; keep it verbatim.
        assertEquals("\\Zfoo\\", HL7Escaping.unescape("\\Zfoo\\", d))
    }

    @Test
    fun hexEscapeDecodes() {
        // \X0D\ → carriage return
        assertEquals("\r", HL7Escaping.unescape("\\X0D\\", d))
    }

    @Test
    fun repetitionAndSubcomponentTablePinned() {
        // Guard against the historical swapped ~/& table.
        assertEquals("~", HL7Escaping.unescape("\\R\\", d))
        assertEquals("&", HL7Escaping.unescape("\\T\\", d))
    }
}
