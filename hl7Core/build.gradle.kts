import org.jetbrains.kotlin.gradle.dsl.JvmTarget
import java.util.Locale

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.androidLibrary)
    alias(libs.plugins.kotlinxSerialization)
    id("com.chromaticnoise.multiplatform-swiftpackage") version "2.0.3"
    `maven-publish`
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
            baseName = "Hl7Core"
            isStatic = true
        }
    }

    sourceSets {
        commonMain.dependencies {
            implementation(libs.kotlinx.serialization.json)
        }
        commonTest.dependencies {
            implementation(libs.kotlin.test)
        }
    }
}

// Version read at config time so the swift package plugin picks it up for the zip filename
val hl7CoreVersionEager = project.findProperty("hl7core.version")?.toString() ?: "unspecified"
version = hl7CoreVersionEager

multiplatformSwiftPackage {
    swiftToolsVersion("5.3")
    outputDirectory(File(projectDir, "swiftpackage"))
    packageName("Hl7Core")
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
            val xcframeworkDir = File(projectDir, "swiftpackage/Hl7Core.xcframework")

            // The plugin outputs iosX64 as "ios-x86_64-simulator"
            val x86SimBin = File(xcframeworkDir, "ios-x86_64-simulator/Hl7Core.framework/Hl7Core")

            // iosSimulatorArm64 is compiled by Gradle but NOT packaged by the plugin — we grab it directly
            val arm64SimBin = File(projectDir, "build/bin/iosSimulatorArm64/releaseFramework/Hl7Core.framework/Hl7Core")

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
            val fatSliceDir = File(xcframeworkDir, "ios-arm64_x86_64-simulator/Hl7Core.framework")
            fatSliceDir.mkdirs()

            // Copy full framework structure from x86_64 slice (headers, modules, plist)
            File(xcframeworkDir, "ios-x86_64-simulator/Hl7Core.framework")
                .copyRecursively(fatSliceDir, overwrite = true)

            // Merge both binaries into fat binary
            exec {
                commandLine(
                    "lipo", "-create",
                    arm64SimBin.absolutePath,
                    x86SimBin.absolutePath,
                    "-output", File(fatSliceDir, "Hl7Core").absolutePath
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
                            <string>Hl7Core.framework/Hl7Core</string>
                            <key>LibraryIdentifier</key>
                            <string>ios-arm64_x86_64-simulator</string>
                            <key>LibraryPath</key>
                            <string>Hl7Core.framework</string>
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
                            <string>Hl7Core.framework/Hl7Core</string>
                            <key>LibraryIdentifier</key>
                            <string>ios-arm64</string>
                            <key>LibraryPath</key>
                            <string>Hl7Core.framework</string>
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
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
}

// Embeds hl7Core/specSource/**/*.json as Kotlin string constants at build time.
// Real resource bundles don't survive this module's static xcframework + lipo
// merge (no working mechanism without the Compose resources plugin), so spec
// JSON is compiled directly into the binary instead.
val specSourceDir = layout.projectDirectory.dir("specSource")
val generatedSpecsDir = layout.buildDirectory.dir("generated/specs/commonMain/kotlin")

val generateSpecConstants = tasks.register("generateSpecConstants") {
    inputs.dir(specSourceDir)
    val outputDir = generatedSpecsDir
    outputs.dir(outputDir)

    doLast {
        val outDir = outputDir.get().asFile
        outDir.deleteRecursively()
        val pkgDir = File(outDir, "org/rite/hl7/spec")
        pkgDir.mkdirs()

        val entries = specSourceDir.asFile.walkTopDown()
            .filter { it.isFile && it.extension == "json" }
            .sortedBy { it.path }
            .map { file ->
                val relative = file.relativeTo(specSourceDir.asFile).invariantSeparatorsPath
                val key = relative.removeSuffix(".json")
                val escaped = file.readText()
                    .replace("\\", "\\\\")
                    .replace("$", "\${'$'}")
                    .replace("\"\"\"", "\\\"\\\"\\\"")
                key to escaped
            }
            .toList()

        val body = buildString {
            appendLine("package org.rite.hl7.spec")
            appendLine()
            appendLine("// GENERATED FILE. Do not edit by hand — edit hl7Core/specSource/**/*.json instead.")
            appendLine("internal object GeneratedSpecs {")
            appendLine("    val jsonByKey: Map<String, String> = mapOf(")
            for ((key, json) in entries) {
                appendLine("        \"$key\" to \"\"\"$json\"\"\",")
            }
            appendLine("    )")
            appendLine("}")
        }

        File(pkgDir, "GeneratedSpecs.kt").writeText(body)
    }
}

kotlin {
    sourceSets {
        commonMain {
            kotlin.srcDir(generateSpecConstants.map { generatedSpecsDir.get() })
        }
    }
}

tasks.matching { it.name.startsWith("compileKotlin") || it.name.startsWith("compile") }.configureEach {
    dependsOn(generateSpecConstants)
}

// ---------------------------------------------------------------------------
// Publishing — GitHub Packages (Android) and local Maven (dev/testing)
// ---------------------------------------------------------------------------
publishing {
    repositories {
        maven {
            name = "GitHubPackages"
            url = uri("https://maven.pkg.github.com/bhushanrite/PillCount-Hl7")
            credentials {
                username = System.getenv("GITHUB_ACTOR")
                    ?: providers.gradleProperty("gpr.user").orNull
                password = System.getenv("GITHUB_TOKEN")
                    ?: providers.gradleProperty("gpr.token").orNull
            }
        }
    }
}

// KMP plugin auto-creates publications; set groupId/artifactId/version on all
afterEvaluate {
    val hl7CoreVersion = project.findProperty("hl7core.version")?.toString() ?: "unspecified"
    publishing.publications.withType<MavenPublication>().configureEach {
        groupId = "org.rite.hl7"
        artifactId = when (name) {
            "kotlinMultiplatform" -> "hl7core"
            else -> "hl7core-$name"
        }
        version = hl7CoreVersion
    }
}
