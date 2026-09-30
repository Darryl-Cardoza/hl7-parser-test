package org.rite.hl7

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Button
import androidx.compose.material3.Divider
import androidx.compose.material3.DropdownMenu
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.ExposedDropdownMenuBox
import androidx.compose.material3.ExposedDropdownMenuDefaults
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import org.rite.hl7.parser.HL7ParseResult

/**
 * Pure-library test harness: pick an HL7 version, pick or paste a raw
 * message, and parse it directly through [org.rite.hl7.parser.HL7Parser] —
 * bypassing [HL7Workflows]'s build helpers so parsing behavior itself is
 * exercised, independent of any one message's construction path.
 */
@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun HL7TestScreen() {
    var selectedVersion by remember { mutableStateOf(HL7SampleMessages.versions.first { it == "2.5" }) }
    var versionMenuExpanded by remember { mutableStateOf(false) }

    var selectedSample by remember { mutableStateOf(HL7SampleMessages.samples.first()) }
    var sampleMenuExpanded by remember { mutableStateOf(false) }

    var rawText by remember { mutableStateOf(selectedSample.raw) }
    var results by remember { mutableStateOf(listOf<String>()) }

    fun appendResult(lines: List<String>) {
        results = results + lines + "────────"
    }

    fun parserFor(version: String) =
        org.rite.hl7.parser.HL7Parser
            .Builder()
            .defaultVersion(version)
            .registerCustomSegment(org.rite.hl7.model.segment.ZSNSegment.Definition)
            .registerCustomSegment(org.rite.hl7.model.segment.ZADSegment.Definition)
            .strictMode(false)
            .build()

    Column(
        modifier = Modifier.fillMaxWidth().padding(16.dp),
        verticalArrangement = Arrangement.spacedBy(12.dp),
    ) {
        Text("HL7 Library Test Harness", style = MaterialTheme.typography.titleLarge)

        // HL7 version dropdown — drives the default-version fallback used
        // when a message omits MSH-12, and can be used to build messages
        // at a specific version via HL7Workflows(version = selectedVersion).
        ExposedDropdownMenuBox(
            expanded = versionMenuExpanded,
            onExpandedChange = { versionMenuExpanded = it },
        ) {
            OutlinedTextField(
                readOnly = true,
                value = selectedVersion,
                onValueChange = {},
                label = { Text("HL7 Version") },
                trailingIcon = { ExposedDropdownMenuDefaults.TrailingIcon(expanded = versionMenuExpanded) },
                modifier = Modifier.fillMaxWidth(),
            )
            DropdownMenu(
                expanded = versionMenuExpanded,
                onDismissRequest = { versionMenuExpanded = false },
            ) {
                HL7SampleMessages.versions.forEach { version ->
                    DropdownMenuItem(
                        text = { Text(version) },
                        onClick = {
                            selectedVersion = version
                            versionMenuExpanded = false
                        },
                    )
                }
            }
        }

        // Sample message dropdown — loads a canned raw message into the
        // editable text field below.
        ExposedDropdownMenuBox(
            expanded = sampleMenuExpanded,
            onExpandedChange = { sampleMenuExpanded = it },
        ) {
            OutlinedTextField(
                readOnly = true,
                value = selectedSample.label,
                onValueChange = {},
                label = { Text("Sample Message") },
                trailingIcon = { ExposedDropdownMenuDefaults.TrailingIcon(expanded = sampleMenuExpanded) },
                modifier = Modifier.fillMaxWidth(),
            )
            DropdownMenu(
                expanded = sampleMenuExpanded,
                onDismissRequest = { sampleMenuExpanded = false },
            ) {
                HL7SampleMessages.samples.forEach { sample ->
                    DropdownMenuItem(
                        text = { Text(sample.label) },
                        onClick = {
                            selectedSample = sample
                            rawText = sample.raw
                            sampleMenuExpanded = false
                        },
                    )
                }
            }
        }

        OutlinedTextField(
            value = rawText,
            onValueChange = { rawText = it },
            label = { Text("Raw HL7 (editable)") },
            modifier = Modifier.fillMaxWidth(),
            minLines = 4,
            maxLines = 10,
        )

        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
            Button(onClick = {
                when (val result = parserFor(selectedVersion).parse(rawText)) {
                    is HL7ParseResult.Success -> {
                        val msg = result.message
                        appendResult(
                            listOf(
                                "Parse OK [defaultVersion=$selectedVersion]",
                                "  resolvedVersion=${msg.version.wire}",
                                "  type=${msg.messageCode}^${msg.triggerEvent}",
                                "  kind=${msg.kind}",
                                "  segments=${msg.typedSegments.map { it.segmentName }}",
                            ),
                        )
                    }
                    is HL7ParseResult.Failure -> {
                        appendResult(
                            listOf("Parse FAILED [defaultVersion=$selectedVersion]") +
                                result.errors.map { "  ${it.segmentName ?: "?"}: ${it.message}" } +
                                (
                                    result.partialMessage?.let {
                                        val segments = it.typedSegments.map { s -> s.segmentName }
                                        listOf("  partial: type=${it.messageCode}^${it.triggerEvent} segments=$segments")
                                    } ?: emptyList()
                                ),
                        )
                    }
                }
            }) {
                Text("Parse")
            }

            Button(onClick = {
                val workflows = HL7Workflows(version = selectedVersion)
                val raw =
                    workflows.buildDispenseMessage(
                        controlId = "MSG-${(1..9999).random()}",
                        placerOrderNumber = "ORD-12345",
                        ndc = "00093-0058-01",
                        drugName = "AMOXICILLIN 500MG",
                        amount = "90",
                        lotNumber = "LOT78321",
                        expirationDate = "20271031",
                        packageSerialNumbers = listOf("21N4F9XK0042", "21N4F9XK0099"),
                    )
                rawText = raw
                appendResult(listOf("Built RDS dispense at version=$selectedVersion:", raw))
                workflows
                    .parseDispenseMessage(raw)
                    .onSuccess { pkg -> appendResult(listOf("Round-trip parsed OK: $pkg")) }
                    .onFailure { appendResult(listOf("Round-trip parse FAILED: ${it.message}")) }
            }) {
                Text("Build @ Version")
            }

            Button(onClick = { results = emptyList() }) {
                Text("Clear")
            }
        }

        Divider()

        LazyColumn(verticalArrangement = Arrangement.spacedBy(2.dp)) {
            items(results) { line ->
                Text(line, style = MaterialTheme.typography.bodySmall)
            }
        }
    }
}
