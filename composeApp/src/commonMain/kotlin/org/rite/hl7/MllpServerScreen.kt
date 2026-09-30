package org.rite.hl7

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.unit.dp

/**
 * Reference screen demonstrating end-to-end MLLP server usage with hl7Core.
 *
 * How to read this screen as a developer:
 *  1. User picks a port (default 2575) and presses Start.
 *  2. [MllpServerViewModel.start] binds a TCP [java.net.ServerSocket] via [MllpServer].
 *  3. Device IP addresses appear so the user knows where to point the HL7 sender.
 *  4. When a message arrives, [MllpServerViewModel] emits a [MllpServerState] update.
 *  5. The screen shows every field that hl7Core extracted: message type, control ID,
 *     sender facility/app (from MSH), ACK code (from ValidationResult.worst), errors
 *     (from ValidationResult.issues), and segment names (from HL7Message.typedSegments).
 *
 * Every displayed field maps to a specific hl7Core type — making this screen a
 * living reference for what the library surfaces after parse + validate.
 */
@Composable
fun MllpServerScreen(viewModel: MllpServerViewModel) {
    val state by viewModel.uiState.collectAsState()

    // rememberSaveable survives screen rotation; remember would reset the port on config change.
    var portText by rememberSaveable { mutableStateOf("2575") }
    val portValid = portText.toIntOrNull()?.let { it in 1..65535 } == true
    val isRunning = state.status != MllpServerStatus.STOPPED

    Scaffold { padding ->
        LazyColumn(
            modifier = Modifier
                .fillMaxSize()
                .padding(padding)
                .padding(horizontal = 16.dp, vertical = 12.dp),
            verticalArrangement = Arrangement.spacedBy(12.dp),
        ) {

            // ── Title + subtitle ───────────────────────────────────────────────
            item {
                Text("MLLP Server", style = MaterialTheme.typography.titleLarge)
                Text(
                    "Reference: TCP server → parse HL7 → validate → ACK/NACK",
                    style = MaterialTheme.typography.bodySmall,
                    color = MaterialTheme.colorScheme.onSurfaceVariant,
                )
            }

            // ── Port field + Start/Stop button + status badge ─────────────────
            item {
                Row(
                    verticalAlignment = Alignment.Top,
                    horizontalArrangement = Arrangement.spacedBy(8.dp),
                ) {
                    // Numeric port field; disabled while server is running
                    OutlinedTextField(
                        value = portText,
                        onValueChange = { if (!isRunning) portText = it },
                        label = { Text("Port") },
                        singleLine = true,
                        isError = !portValid,
                        keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                        modifier = Modifier.width(120.dp),
                        enabled = !isRunning,
                        supportingText = {
                            if (!portValid) Text("1–65535", color = MaterialTheme.colorScheme.error)
                        },
                    )

                    Column(verticalArrangement = Arrangement.spacedBy(6.dp)) {
                        Button(
                            onClick = {
                                if (isRunning) {
                                    viewModel.stop()
                                } else {
                                    val port = portText.toIntOrNull() ?: return@Button
                                    viewModel.start(port)
                                }
                            },
                            enabled = if (isRunning) true else portValid,
                            colors = if (isRunning)
                                ButtonDefaults.buttonColors(containerColor = MaterialTheme.colorScheme.error)
                            else
                                ButtonDefaults.buttonColors(),
                        ) {
                            Text(if (isRunning) "Stop" else "Start")
                        }

                        // Status badge: color-coded for instant scanning
                        StatusBadge(state.status)
                    }
                }
            }

            // ── Connection info card (visible when server is running) ──────────
            // Shows the device IP addresses the sender should target.
            // Library usage: MllpServer.localAddresses() returns NetworkInterface IPv4 addrs.
            if (isRunning && state.boundAddresses.isNotEmpty()) {
                item {
                    InfoCard(title = "Connect From Sender") {
                        Text(
                            "Send MLLP-framed HL7 to any of:",
                            style = MaterialTheme.typography.labelMedium,
                        )
                        Spacer(Modifier.height(4.dp))
                        state.boundAddresses.forEach { ip ->
                            Text(
                                "$ip:${state.port}",
                                style = MaterialTheme.typography.bodyMedium,
                                fontFamily = FontFamily.Monospace,
                            )
                        }
                        Spacer(Modifier.height(4.dp))
                        Text(
                            "MLLP frame: 0x0B + HL7 text + 0x1C + 0x0D",
                            style = MaterialTheme.typography.bodySmall,
                            color = MaterialTheme.colorScheme.onSurfaceVariant,
                        )
                    }
                }
            }

            // ── Message counter ────────────────────────────────────────────────
            item {
                Text(
                    "Messages received: ${state.totalReceived}",
                    style = MaterialTheme.typography.bodyMedium,
                )
            }

            // ── Last error banner (ConnectionError or ServerError) ─────────────
            // ConnectionError: one client failed, server still LISTENING.
            // ServerError: fatal bind/accept failure, server is now STOPPED.
            val lastError = state.lastError
            if (lastError != null) {
                item {
                    Card(
                        modifier = Modifier.fillMaxWidth(),
                        colors = CardDefaults.cardColors(
                            containerColor = MaterialTheme.colorScheme.errorContainer,
                        ),
                    ) {
                        Column(modifier = Modifier.padding(12.dp)) {
                            Text(
                                "Connection Error",
                                style = MaterialTheme.typography.labelLarge,
                                color = MaterialTheme.colorScheme.onErrorContainer,
                            )
                            Spacer(Modifier.height(4.dp))
                            Text(
                                lastError,
                                style = MaterialTheme.typography.bodySmall,
                                color = MaterialTheme.colorScheme.onErrorContainer,
                            )
                        }
                    }
                }
            }

            // ── Last message detail (null until first message arrives) ─────────
            val msg = state.lastMessage
            if (msg != null) {
                item { HorizontalDivider() }

                item {
                    Text("Last Message", style = MaterialTheme.typography.titleMedium)
                }

                // MSH fields — connection and routing metadata
                // Library: msg.messageCode, msg.triggerEvent, msg.messageControlId,
                //          msg.sendingFacility, msg.header?.sendingApplication
                item {
                    InfoCard(title = "Message Header (MSH)") {
                        LabelValue("Type", msg.messageType)           // MSH-9: messageCode^triggerEvent
                        LabelValue("Control ID", msg.controlId)       // MSH-10: unique per message
                        LabelValue("Sender App", msg.senderApp)       // MSH-3
                        LabelValue("Sender Facility", msg.senderFacility) // MSH-4
                        LabelValue("Received At", msg.receivedAt)
                    }
                }

                // Validation result — ACK code + any rule violations
                // Library: HL7Validator.validate(message) → ValidationResult
                //          ValidationResult.worst.code → "AA" | "AE" | "AR"
                //          ValidationResult.issues → List<ValidationIssue>
                item {
                    InfoCard(title = "Validation Result") {
                        Row(
                            verticalAlignment = Alignment.CenterVertically,
                            horizontalArrangement = Arrangement.spacedBy(8.dp),
                        ) {
                            Text("ACK code:", style = MaterialTheme.typography.bodyMedium)
                            AckBadge(msg.ackCode)
                        }
                        if (msg.validationErrors.isNotEmpty()) {
                            Spacer(Modifier.height(6.dp))
                            Text(
                                "Validation errors (${msg.validationErrors.size}):",
                                style = MaterialTheme.typography.labelMedium,
                            )
                            msg.validationErrors.forEach { err ->
                                Text(
                                    "• $err",
                                    style = MaterialTheme.typography.bodySmall,
                                    color = MaterialTheme.colorScheme.error,
                                )
                            }
                        } else {
                            Spacer(Modifier.height(4.dp))
                            Text(
                                "No validation errors",
                                style = MaterialTheme.typography.bodySmall,
                                color = Color(0xFF4CAF50),
                            )
                        }
                    }
                }

                // Segment list — shows which segments the parser found
                // Library: HL7Message.typedSegments.map { it.segmentName }
                if (msg.rawSegments.isNotEmpty()) {
                    item {
                        InfoCard(title = "Parsed Segments (${msg.rawSegments.size})") {
                            Text(
                                msg.rawSegments.joinToString(" → "),
                                style = MaterialTheme.typography.bodySmall,
                                fontFamily = FontFamily.Monospace,
                            )
                        }
                    }
                }
            }
        }
    }
}

// ── Reusable composables ───────────────────────────────────────────────────────

/**
 * Color-coded status chip.
 * STOPPED=grey, LISTENING=green, PROCESSING=amber.
 */
@Composable
private fun StatusBadge(status: MllpServerStatus) {
    val (label, color) = when (status) {
        MllpServerStatus.STOPPED    -> "STOPPED"    to Color(0xFF9E9E9E)
        MllpServerStatus.LISTENING  -> "LISTENING"  to Color(0xFF4CAF50)
        MllpServerStatus.PROCESSING -> "PROCESSING" to Color(0xFFFFC107)
    }
    Box(
        modifier = Modifier
            .background(color, RoundedCornerShape(50))
            .padding(horizontal = 10.dp, vertical = 4.dp),
    ) {
        Text(label, color = Color.White, style = MaterialTheme.typography.labelSmall)
    }
}

/**
 * Color-coded ACK code chip.
 * AA=green (accepted), AE=amber (error), AR=red (rejected).
 */
@Composable
private fun AckBadge(code: String) {
    val color = when (code) {
        "AA" -> Color(0xFF4CAF50)
        "AE" -> Color(0xFFFFC107)
        else -> Color(0xFFF44336)
    }
    Box(
        modifier = Modifier
            .background(color, RoundedCornerShape(4.dp))
            .padding(horizontal = 8.dp, vertical = 2.dp),
    ) {
        Text(code, color = Color.White, style = MaterialTheme.typography.labelMedium)
    }
}

/** Elevated card with a title label and arbitrary content. */
@Composable
private fun InfoCard(title: String, content: @Composable () -> Unit) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        elevation = CardDefaults.cardElevation(defaultElevation = 2.dp),
    ) {
        Column(modifier = Modifier.padding(12.dp)) {
            Text(title, style = MaterialTheme.typography.labelLarge)
            Spacer(Modifier.height(6.dp))
            content()
        }
    }
}

/** Single label+value row; skipped when value is blank. */
@Composable
private fun LabelValue(label: String, value: String) {
    if (value.isBlank()) return
    Row(modifier = Modifier.padding(vertical = 1.dp)) {
        Text(
            "$label: ",
            style = MaterialTheme.typography.labelSmall,
            color = MaterialTheme.colorScheme.onSurfaceVariant,
        )
        Text(
            value,
            style = MaterialTheme.typography.bodySmall,
            fontFamily = FontFamily.Monospace,
        )
    }
}
