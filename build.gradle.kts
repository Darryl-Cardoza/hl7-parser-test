plugins {
    // this is necessary to avoid the plugins to be loaded multiple times
    // in each subproject's classloader
    alias(libs.plugins.androidApplication) apply false
    alias(libs.plugins.androidLibrary) apply false
    alias(libs.plugins.composeMultiplatform) apply false
    alias(libs.plugins.composeCompiler) apply false
    alias(libs.plugins.kotlinMultiplatform) apply false
}

// AGP's Unified Test Platform pulls older Netty and Protobuf dependencies.
// Apply the security floors to the actual tooling graph, not just CI lockfiles.
allprojects {
    configurations.configureEach {
        resolutionStrategy.eachDependency {
            val dependencyVersion = requested.version.orEmpty()
            if (requested.group == "io.netty" && dependencyVersion.startsWith("4.1.")) {
                val patch = dependencyVersion.removePrefix("4.1.").substringBefore('.').toIntOrNull()
                if (patch != null && patch < 137) {
                    useVersion("4.1.137.Final")
                    because("Fix Netty vulnerabilities reported by the dependency security scan")
                }
            }
            if (requested.group == "com.google.protobuf" && dependencyVersion.startsWith("3.")) {
                val parts = dependencyVersion.split('.')
                val minor = parts.getOrNull(1)?.toIntOrNull()
                val patch = parts.getOrNull(2)?.toIntOrNull()
                if (minor != null && (minor < 25 || (minor == 25 && patch != null && patch < 8))) {
                    useVersion("3.25.8")
                    because("Fix vulnerable Protobuf parsing while retaining the 3.x runtime")
                }
            }
        }
    }
}
