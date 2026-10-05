package org.rite.hl7

import androidx.compose.runtime.Composable
import androidx.lifecycle.viewmodel.compose.viewModel

/**
 * Android actual: creates [MllpServerViewModel] with a real [MllpServer] delegate
 * and renders [MllpServerScreen].
 *
 * [viewModel] scopes the ViewModel to the nearest [androidx.lifecycle.ViewModelStoreOwner]
 * (the Activity), so it survives recomposition and tab switches — the server keeps
 * running while the user browses other tabs.
 *
 * [MllpServer.localAddresses] is passed as a lambda so the common ViewModel class
 * does not import Android-only [java.net.NetworkInterface].
 */
@Composable
actual fun MllpServerTab() {
    val vm: MllpServerViewModel =
        viewModel {
            MllpServerViewModel(
                delegate = MllpServer(),
                localAddresses = { MllpServer.localAddresses() },
            )
        }
    MllpServerScreen(viewModel = vm)
}
