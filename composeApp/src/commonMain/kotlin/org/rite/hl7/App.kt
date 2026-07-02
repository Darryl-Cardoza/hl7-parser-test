package org.rite.hl7

import androidx.compose.foundation.layout.Column
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Tab
import androidx.compose.material3.TabRow
import androidx.compose.runtime.*
import androidx.compose.ui.tooling.preview.Preview


@Composable
@Preview
fun App() {
    MaterialTheme {
        var tab by remember { mutableStateOf(0) }
        Column {
            TabRow(selectedTabIndex = tab) {
                Tab(selected = tab == 0, onClick = { tab = 0 }, text = { androidx.compose.material3.Text("Demo") })
                Tab(selected = tab == 1, onClick = { tab = 1 }, text = { androidx.compose.material3.Text("Library Test") })
            }
            if (tab == 0) HL7DemoScreen() else HL7TestScreen()
        }
    }
}