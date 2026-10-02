package org.rite.hl7

import androidx.compose.runtime.Composable

/**
 * Platform-specific entry point for the MLLP Server tab.
 *
 * Android: renders [MllpServerScreen] backed by [MllpServerViewModel] + [MllpServer].
 * iOS: not supported — iOS sandbox does not allow binding a TCP server socket
 *      in a foreground app. See docs/LIBRARY_INTEGRATION.md for iOS client-mode usage.
 */
@Composable
expect fun MllpServerTab()
