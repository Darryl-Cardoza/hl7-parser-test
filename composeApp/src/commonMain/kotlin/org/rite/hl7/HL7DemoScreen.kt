package org.rite.hl7

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Button
import androidx.compose.material3.Divider
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp

/**
 * Demo screen exercising [HL7Workflows] end to end: build a message, encode
 * it to wire text, parse it back, and show the extracted fields. Wire this
 * into [App] (or navigate to it) to see dispense and inventory round-trips
 * working against real device/simulator UI.
 */
@Composable
fun HL7DemoScreen(workflows: HL7Workflows = remember { HL7Workflows() }) {
    var log by remember { mutableStateOf(listOf<String>()) }

    fun appendLog(lines: List<String>) {
        log = log + lines + "────────"
    }

    Scaffold { padding ->
        Column(
            modifier = Modifier.fillMaxSize().padding(padding).padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(12.dp),
        ) {
            Text("HL7 Dispense / Inventory Demo", style = MaterialTheme.typography.titleLarge)

            Button(onClick = {
                val raw = workflows.buildDispenseMessage(
                    controlId = "MSG-${(1..9999).random()}",
                    placerOrderNumber = "ORD-12345",
                    ndc = "00093-0058-01",
                    drugName = "AMOXICILLIN 500MG",
                    amount = "90",
                    lotNumber = "LOT78321",
                    expirationDate = "20271031",
                    packageSerialNumbers = listOf("21N4F9XK0042", "21N4F9XK0099"),
                )
                appendLog(listOf("Built dispense message:", raw))

                workflows.parseDispenseMessage(raw)
                    .onSuccess { pkg ->
                        appendLog(
                            listOf(
                                "Parsed dispense:",
                                "  drug=${pkg.drugName} ndc=${pkg.ndc}",
                                "  amount=${pkg.amountDispensed} lot=${pkg.lotNumber} exp=${pkg.expirationDate}",
                                "  serials=${pkg.serialNumbers}",
                            )
                        )
                    }
                    .onFailure { appendLog(listOf("Dispense parse error: ${it.message}")) }
            }) {
                Text("Run Dispense Round-Trip")
            }

            Button(onClick = {
                val raw = workflows.buildInventoryAdjustmentMessage(
                    controlId = "MSG-${(1..9999).random()}",
                    ndc = "00069015505",
                    substanceName = "Drug Name",
                    onHandQuantity = "150",
                    units = "EA",
                    adjustmentType = "LOSS",
                    adjustmentQuantity = "5",
                    adjustmentReason = "DAMAGED_IN_TRANSIT",
                    approvedBy = "JOHN.DOE",
                )
                appendLog(listOf("Built inventory message:", raw))

                workflows.parseInventoryMessage(raw)
                    .onSuccess { adjustments ->
                        adjustments.forEach { adj ->
                            appendLog(
                                listOf(
                                    "Parsed inventory row:",
                                    "  ${adj.substanceName} (${adj.ndc}) onHand=${adj.onHandQuantity} ${adj.units}",
                                    "  adjustment=${adj.adjustmentType} qty=${adj.adjustmentQuantity} reason=${adj.adjustmentReason}",
                                )
                            )
                        }
                    }
                    .onFailure { appendLog(listOf("Inventory parse error: ${it.message}")) }
            }) {
                Text("Run Inventory Round-Trip")
            }

            Divider()

            LazyColumn(verticalArrangement = Arrangement.spacedBy(2.dp)) {
                items(log) { line ->
                    Text(line, style = MaterialTheme.typography.bodySmall)
                }
            }
        }
    }
}
