import org.jetbrains.kotlin.gradle.dsl.JvmTarget

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.androidLibrary)
    alias(libs.plugins.composeMultiplatform)
    alias(libs.plugins.composeCompiler)
    id("com.chromaticnoise.multiplatform-swiftpackage") version "2.0.3"
}

kotlin {
    androidTarget {
        compilerOptions {
            jvmTarget.set(JvmTarget.JVM_11)
        }
    }

    listOf(
        iosX64(),
        iosArm64(),
        iosSimulatorArm64()
    ).forEach { iosTarget ->
        iosTarget.binaries.framework {
            baseName = "ComposeApp"
            isStatic = true
        }
    }

    sourceSets {
        androidMain.dependencies {
            implementation(libs.compose.uiToolingPreview)
            implementation(libs.androidx.activity.compose)
        }
        commonMain.dependencies {
            implementation(libs.compose.runtime)
            implementation(libs.compose.foundation)
            implementation(libs.compose.material3)
            implementation(libs.compose.ui)
            implementation(libs.compose.components.resources)
            implementation(libs.compose.uiToolingPreview)
            implementation(libs.androidx.lifecycle.viewmodelCompose)
            implementation(libs.androidx.lifecycle.runtimeCompose)
        }
        commonTest.dependencies {
            implementation(libs.kotlin.test)
        }
    }
}

multiplatformSwiftPackage {
    swiftToolsVersion("5.3")
    outputDirectory(File(projectDir, "swiftpackage"))
    packageName("ComposeApp")
    targetPlatforms {
        iOS { v("13") }
    }
}

// Fix: merge separate simulator slices into a single fat binary
afterEvaluate {
    tasks.named("createSwiftPackage").configure {
        // Ensure iosSimulatorArm64 framework is built before we run
        dependsOn("linkReleaseFrameworkIosSimulatorArm64")

        doLast {
            val xcframeworkDir = File(projectDir, "swiftpackage/ComposeApp.xcframework")

            // The plugin outputs iosX64 as "ios-x86_64-simulator"
            val x86SimBin = File(xcframeworkDir, "ios-x86_64-simulator/ComposeApp.framework/ComposeApp")

            // iosSimulatorArm64 is compiled by Gradle but NOT packaged by the plugin — we grab it directly
            val arm64SimBin = File(projectDir, "build/bin/iosSimulatorArm64/releaseFramework/ComposeApp.framework/ComposeApp")

            if (!x86SimBin.exists()) {
                println("⚠️  ios-x86_64-simulator slice not found at: ${x86SimBin.absolutePath}")
                return@doLast
            }
            if (!arm64SimBin.exists()) {
                println("⚠️  iosSimulatorArm64 slice not found at: ${arm64SimBin.absolutePath}")
                return@doLast
            }

            println("✅ Found x86_64 simulator: ${x86SimBin.absolutePath}")
            println("✅ Found arm64 simulator:  ${arm64SimBin.absolutePath}")

            // Create fat simulator slice directory
            val fatSliceDir = File(xcframeworkDir, "ios-arm64_x86_64-simulator/ComposeApp.framework")
            fatSliceDir.mkdirs()

            // Copy full framework structure from x86_64 slice (headers, modules, plist)
            File(xcframeworkDir, "ios-x86_64-simulator/ComposeApp.framework")
                .copyRecursively(fatSliceDir, overwrite = true)

            // Merge both binaries into fat binary
            exec {
                commandLine(
                    "lipo", "-create",
                    arm64SimBin.absolutePath,
                    x86SimBin.absolutePath,
                    "-output", File(fatSliceDir, "ComposeApp").absolutePath
                )
            }

            // Remove the now-redundant x86-only simulator slice
            File(xcframeworkDir, "ios-x86_64-simulator").deleteRecursively()

            // Rewrite Info.plist with the correct merged slice
            val infoPlist = File(xcframeworkDir, "Info.plist")
            infoPlist.writeText("""
                <?xml version="1.0" encoding="UTF-8"?>
                <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
                <plist version="1.0">
                <dict>
                    <key>AvailableLibraries</key>
                    <array>
                        <dict>
                            <key>BinaryPath</key>
                            <string>ComposeApp.framework/ComposeApp</string>
                            <key>LibraryIdentifier</key>
                            <string>ios-arm64_x86_64-simulator</string>
                            <key>LibraryPath</key>
                            <string>ComposeApp.framework</string>
                            <key>SupportedArchitectures</key>
                            <array>
                                <string>arm64</string>
                                <string>x86_64</string>
                            </array>
                            <key>SupportedPlatform</key>
                            <string>ios</string>
                            <key>SupportedPlatformVariant</key>
                            <string>simulator</string>
                        </dict>
                        <dict>
                            <key>BinaryPath</key>
                            <string>ComposeApp.framework/ComposeApp</string>
                            <key>LibraryIdentifier</key>
                            <string>ios-arm64</string>
                            <key>LibraryPath</key>
                            <string>ComposeApp.framework</string>
                            <key>SupportedArchitectures</key>
                            <array>
                                <string>arm64</string>
                            </array>
                            <key>SupportedPlatform</key>
                            <string>ios</string>
                        </dict>
                    </array>
                    <key>CFBundlePackageType</key>
                    <string>XFWK</string>
                    <key>XCFrameworkFormatVersion</key>
                    <string>1.0</string>
                </dict>
                </plist>
            """.trimIndent())

            println("✅ Fat simulator slice created: ios-arm64_x86_64-simulator")
            println("✅ Info.plist updated")
        }
    }
}

android {
    namespace = "org.rite.hl7"
    compileSdk = libs.versions.android.compileSdk.get().toInt()

    defaultConfig {
        minSdk = libs.versions.android.minSdk.get().toInt()
    }
    packaging {
        resources {
            excludes += "/META-INF/{AL2.0,LGPL2.1}"
        }
    }
    buildTypes {
        getByName("release") {
            isMinifyEnabled = false
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
}

dependencies {
    debugImplementation(libs.compose.uiTooling)
}
