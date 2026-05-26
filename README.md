# MobRite HL7 Parser Builder

> A Kotlin Multiplatform (KMP) library for HL7 message parsing and building across Android, iOS, and JVM.

---

## 📌 About

This library provides a **cross-platform HL7 engine** for healthcare systems like PMS, EMR, LIS, and CMP.

It enables:
- Unified HL7 parsing logic
- Message building with fluent APIs
- Platform-independent implementation using KMP

---

# 📚 Table of Contents

- [✨ What's Included](#-whats-included)
- [🛠️ Tech Stack](#️-tech-stack)
- [📋 Prerequisites](#-prerequisites)
- [🚀 Project Setup (Step by Step)](#-project-setup-step-by-step)
- [🏃 Running the Project](#-running-the-project)
- [🧪 Testing](#-testing)
- [📁 Folder Structure Overview](#-folder-structure-overview)
- [📁 Detailed File Structure](#-detailed-file-structure)
- [⚙️ Configuration Details](#️-configuration-details)
- [📦 Adding a New Module](#-adding-a-new-module)
- [🍎 iOS Integration](#-ios-integration)
- [🤖 Android Integration](#-android-integration)
- [🔧 Building the Swift Package (xcframework)](#-building-the-swift-package-xcframework)

---

# ✨ What's Included

- HL7 Parser
- HL7 Builder
- Segment validation
- Cross-platform support (KMP)
- Structured HL7 model output

---

# 🛠️ Tech Stack

- Kotlin Multiplatform (KMP)
- Gradle Kotlin DSL
- Swift Package Manager (SPM)
- Compose Multiplatform
- JVM / Android / iOS

---

# 📋 Prerequisites

- Kotlin 1.9+
- Android Studio / IntelliJ IDEA
- Xcode 14+ (for iOS)
- Gradle 8+
- macOS with Xcode Command Line Tools (for xcframework builds)

---

# 🚀 Project Setup (Step by Step)

## 1. Clone Repository

```bash
git clone https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder.git
cd mobrite_hl7_parser_builder
```

---

## 2. Generate the Swift Package (iOS developers — required after clone)

> ⚠️ The `ComposeApp.xcframework` is **not committed to git** (too large). You must generate it locally before building the iOS app.

```bash
# Step 1 — Build the iosSimulatorArm64 framework first
./gradlew :hl7Core:linkReleaseFrameworkIosSimulatorArm64

# Step 2 — Package everything into the xcframework + merge simulator slices
./gradlew :hl7Core:createSwiftPackage
```

This produces `hl7Core/swiftpackage/ComposeApp.xcframework` with three slices:
- `ios-arm64` — physical device
- `ios-arm64_x86_64-simulator` — Apple Silicon + Intel Mac simulator (fat binary)

Verify the build succeeded:

```bash
ls hl7Core/swiftpackage/ComposeApp.xcframework/
# Expected: Info.plist  ios-arm64  ios-arm64_x86_64-simulator

lipo -info hl7Core/swiftpackage/ComposeApp.xcframework/ios-arm64_x86_64-simulator/ComposeApp.framework/ComposeApp
# Expected: Architectures in the fat file: ComposeApp are: x86_64 arm64
```

---

# 🔧 Building the Swift Package (xcframework)

## How It Works

The `multiplatform-swiftpackage` Gradle plugin (v2.0.3) does not automatically merge the `iosX64` and `iosSimulatorArm64` slices into a fat binary. The `build.gradle.kts` in `hl7Core` includes a custom `afterEvaluate` task that:

1. Compiles the `iosSimulatorArm64` framework via `linkReleaseFrameworkIosSimulatorArm64`
2. Merges it with the plugin's `iosX64` output using `lipo`
3. Rewrites `Info.plist` to reference the merged `ios-arm64_x86_64-simulator` slice

## Rebuilding After Code Changes

```bash
./gradlew clean
./gradlew :hl7Core:linkReleaseFrameworkIosSimulatorArm64
./gradlew :hl7Core:createSwiftPackage
```

Then in Xcode:
1. **File → Packages → Reset Package Caches**
2. `⇧⌘K` — Clean Build Folder
3. `⌘B` — Build

## Xcode Build Settings Required

| Setting | Value |
|---|---|
| Frameworks, Libraries, and Embedded Content | `ComposeApp` → **Do Not Embed** (static framework) |
| Other Linker Flags | `-ObjC` |
| Excluded Architectures → Any iOS Simulator SDK | `x86_64` |
| iOS Deployment Target | `16.0` minimum |

---

# 🤖 Android Integration

> ⚠️ Library is **not published to Maven yet** — use as a local Gradle module.

## Step 1 — Include Module

In your root `settings.gradle.kts`:

```kotlin
include(":libraries:hl7-parser")
project(":libraries:hl7-parser").projectDir = File("path/to/hl7Core")
```

## Step 2 — Add Dependency

```kotlin
dependencies {
    implementation(project(":libraries:hl7-parser"))
}
```

## Step 3 — Usage

```kotlin
val parser = HL7Parser()

val message = """
    MSH|^~\&|APP|FACILITY
    PID|1||12345
""".trimIndent()

val result = parser.parse(message)
println(result.segments)
```

---

# 🍎 iOS Integration

## Option 1 — Local Swift Package (Recommended)

### Step 1 — Generate the xcframework

```bash
./gradlew :hl7Core:linkReleaseFrameworkIosSimulatorArm64
./gradlew :hl7Core:createSwiftPackage
```

### Step 2 — Add to Xcode

- Open Xcode → **File → Add Package Dependencies**
- Click **Add Local...**
- Navigate to `hl7Core/swiftpackage/`
- Select the folder containing `Package.swift`
- Add `ComposeApp` library to your target

### Step 3 — Configure Build Settings

In your Xcode target → **Build Settings**:

```
Other Linker Flags:                     -ObjC
Excluded Architectures (Simulator):     x86_64
iOS Deployment Target:                  16.0
```

In **Frameworks, Libraries, and Embedded Content**:
- Set `ComposeApp` → **Do Not Embed**

## Option 2 — Remote Swift Package

```
https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder
```

> ⚠️ Requires Git LFS to be enabled on the remote if xcframework binaries are committed.

## Swift Usage

```swift
import ComposeApp

let parser = ComposeAppHL7Parser()

let message = """
MSH|^~\\&|APP|FACILITY
PID|1||12345
"""

let parsed = parser.parse(message: message)
print(parsed)
```

---

# 🏃 Running the Project

### Android

```bash
./gradlew :composeApp:assembleDebug
```

### iOS

1. Generate the xcframework (see [Building the Swift Package](#-building-the-swift-package-xcframework))
2. Open `iosApp/iosApp.xcodeproj` in Xcode
3. Select your simulator or device
4. `⌘R` to run

---

# 🧪 Testing

```bash
# All platforms
./gradlew test

# Specific module
./gradlew :hl7Core:test
```

---

# 📁 Folder Structure Overview

```
mobrite_hl7_parser_builder/
│
├── composeApp/          # Compose Multiplatform shared UI
├── hl7Core/             # KMP library (parser, builder, models)
├── iosApp/              # Native iOS host app
├── gradle/
├── build.gradle.kts
└── settings.gradle.kts
```

---

# 📁 Detailed File Structure

```
hl7Core/
│
├── src/
│   ├── commonMain/
│   │   └── kotlin/org/rite/hl7/
│   │
│   │   ├── builder/
│   │   │   ├── header/
│   │   │   ├── inventory/
│   │   │   ├── order/
│   │   │   ├── patient/
│   │   │   ├── pharmacy/
│   │   │   └── HL7Builder.kt
│   │
│   │   ├── domain/
│   │   │   ├── model/
│   │   │   └── utils/
│   │
│   │   ├── parser/
│   │   │   ├── header/
│   │   │   ├── inventory/
│   │   │   ├── order/
│   │   │   ├── patient/
│   │   │   ├── pharmacy/
│   │   │   ├── HL7Parser.kt
│   │   │   └── HL7ParserException.kt
│   │
│   │   └── util/
│   │       └── AckGenerator.kt
│
│   ├── androidMain/
│   └── iosMain/
│
├── swiftpackage/        # Generated — do not commit (see .gitignore)
│   ├── Package.swift
│   └── ComposeApp.xcframework/
│
└── build.gradle.kts
```

---

## 📌 Directory Explanation

| Folder       | Description                                  |
|--------------|----------------------------------------------|
| builder      | HL7 message construction                     |
| parser       | HL7 message parsing                          |
| domain       | Data models & utilities                      |
| util         | Helper utilities                             |
| androidMain  | Android-specific code                        |
| iosMain      | iOS-specific code                            |
| swiftpackage | Generated xcframework output (not in git)    |

---

# ⚙️ Configuration Details

## Gradle (Android)

```kotlin
implementation(project(":libraries:hl7-parser"))
```

## Swift Package (iOS remote)

```swift
.package(
    url: "https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder",
    from: "1.0.0"
)
```

## Swift Package (iOS local)

```swift
.package(
    path: "../mobrite_hl7_parser_builder/hl7Core/swiftpackage"
)
```

---

# 📦 Adding a New Module

## Step 1 — Create Module Directory

```
libraries/new-module/
├── src/commonMain/
└── build.gradle.kts
```

## Step 2 — Register in settings.gradle.kts

```kotlin
include(":libraries:new-module")
```

## Step 3 — Add as Dependency

```kotlin
implementation(project(":libraries:new-module"))
```

---

# ✅ Best Practices

- **Never commit** `ComposeApp.xcframework` or `.zip` binaries to git — regenerate with Gradle
- Run `./gradlew :hl7Core:createSwiftPackage` after every KMP code change before opening Xcode
- Keep modules independent with clear boundaries
- Maintain unit tests for parser and builder
- Follow KMP folder conventions (`commonMain`, `androidMain`, `iosMain`)

---

# 📞 Support

Maintained by **Rite Technologies**
