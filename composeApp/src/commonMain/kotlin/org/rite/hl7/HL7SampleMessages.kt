package org.rite.hl7

/**
 * Canned raw HL7 wire messages for exercising [org.rite.hl7.parser.HL7Parser]
 * directly from the demo UI, independent of [HL7Workflows]'s own builders.
 * Covers RDS (dispense) and RDE (dispense order) across the pre-2.5 flat
 * trigger names (O01) and the 2.5+ grouped trigger names (O13/O11), plus a
 * couple of malformed samples to exercise failure/partial-parse paths.
 */
object HL7SampleMessages {

    data class Sample(val label: String, val raw: String)

    private fun msh(version: String, type: String, controlId: String = "MSG-${version.replace(".", "")}-1"): String =
        "MSH|^~\\&|PillCounter|ROBOT|PMS|PHARMACY|20260623091205||$type|$controlId|P|$version"

    val samples: List<Sample> = listOf(
        Sample(
            "RDS^O01 dispense (v2.3)",
            listOf(
                msh("2.3", "RDS^O01"),
                "ORC|RE|ORD-1001",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100842",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O01 dispense (v2.3.1)",
            listOf(
                msh("2.3.1", "RDS^O01"),
                "ORC|RE|ORD-1002",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100843",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O01 dispense (v2.4)",
            listOf(
                msh("2.4", "RDS^O01"),
                "ORC|RE|ORD-1003",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100844",
                "RXR|PO^Oral",
                "RXC|B|00093-0059-01^IBUPROFEN 200MG^NDC|200|MG",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense (v2.5)",
            listOf(
                msh("2.5", "RDS^O13"),
                "ORC|RE|ORD-1004",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100845",
                "RXR|PO^Oral",
                "OBX|1|ST|DISPENSE-VERIFIED||true||||||F",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense with serials (v2.5.1)",
            listOf(
                msh("2.5.1", "RDS^O13"),
                "ORC|RE|ORD-1005",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100846",
                "RXR|PO^Oral",
                "ZSN|1|21N4F9XK0042|00093-0058-01|LOT78321|20271031|D",
                "ZSN|2|21N4F9XK0099|00093-0058-01|LOT78321|20271031|D",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense (v2.6)",
            listOf(
                msh("2.6", "RDS^O13"),
                "ORC|RE|ORD-1006",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100847",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense (v2.7)",
            listOf(
                msh("2.7", "RDS^O13"),
                "ORC|RE|ORD-1007",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100848",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense (v2.7.1)",
            listOf(
                msh("2.7.1", "RDS^O13"),
                "ORC|RE|ORD-1008",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100849",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDS^O13 dispense (v2.8)",
            listOf(
                msh("2.8", "RDS^O13"),
                "ORC|RE|ORD-1009",
                "RXD|1|00093-0058-01^AMOXICILLIN 500MG^NDC|20260623091205|90|TAB^Tablets|^|RX100850",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDE^O01 dispense order (v2.3)",
            listOf(
                msh("2.3", "RDE^O01"),
                "PID|1||PT-9001^^^HOSP^MR||DOE^JANE",
                "ORC|NW|ORD-2001",
                "RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDE^O01 dispense order (v2.4)",
            listOf(
                msh("2.4", "RDE^O01"),
                "PID|1||PT-9002^^^HOSP^MR||SMITH^JOHN",
                "ORC|NW|ORD-2002",
                "RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXR|PO^Oral",
                "RXC|B|00093-0059-01^IBUPROFEN 200MG^NDC|200|MG",
            ).joinToString("\r"),
        ),
        Sample(
            "RDE^O11 dispense order (v2.5)",
            listOf(
                msh("2.5", "RDE^O11"),
                "PID|1||PT-9003^^^HOSP^MR||PATEL^RAJ",
                "ORC|NW|ORD-2003",
                "RXO|00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDE^O11 dispense order (v2.6)",
            listOf(
                msh("2.6", "RDE^O11"),
                "PID|1||PT-9004^^^HOSP^MR||GARCIA^MARIA",
                "ORC|NW|ORD-2004",
                "RXO|00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "RDE^O11 dispense order (v2.7.1)",
            listOf(
                msh("2.7.1", "RDE^O11"),
                "PID|1||PT-9005^^^HOSP^MR||NGUYEN^LINH",
                "ORC|NW|ORD-2005",
                "RXO|00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXE||00093-0058-01^AMOXICILLIN 500MG^NDC|90|||TAB^Tablets",
                "RXR|PO^Oral",
            ).joinToString("\r"),
        ),
        Sample(
            "INR^U05 inventory response (v2.5)",
            listOf(
                msh("2.5", "INR^U05"),
                "EQU|DEVICE-1|20260623091205",
                "ORC|RE|ORD-3001",
                "INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA",
            ).joinToString("\r"),
        ),
        Sample(
            "INR^U06 inventory adjustment (v2.5)",
            listOf(
                msh("2.5", "INR^U06"),
                "EQU|DEVICE-1|20260623091205",
                "ORC|RE|ORD-3002",
                "INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA",
                "ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE",
            ).joinToString("\r"),
        ),
        Sample(
            "Malformed: missing MSH",
            "PID|1||12345",
        ),
        Sample(
            "Malformed: RDS missing RXD",
            listOf(
                msh("2.5", "RDS^O13"),
                "ORC|RE|ORD-9999",
            ).joinToString("\r"),
        ),
    )

    /** All distinct HL7 versions referenced by [samples], for the version picker. */
    val versions: List<String> = listOf(
        "2.3", "2.3.1", "2.4", "2.5", "2.5.1", "2.6", "2.7", "2.7.1", "2.8",
    )
}
