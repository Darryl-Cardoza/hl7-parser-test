package org.rite.hl7

import androidx.compose.material3.Text
import androidx.compose.runtime.Composable

/**
 * iOS does not support binding a TCP server socket in a foreground app
 * due to sandbox restrictions. Use hl7Core in client mode on iOS:
 * parse incoming bytes with [org.rite.hl7.HL7.parseMllp] and send via
 * Network.framework — see docs/LIBRARY_INTEGRATION.md for a full example.
 */
@Composable
actual fun MllpServerTab() {
    Text("MLLP Server not supported on iOS.\nSee docs/LIBRARY_INTEGRATION.md for client-mode usage.")
}
