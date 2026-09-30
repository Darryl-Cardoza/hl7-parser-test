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

- Kotlin Multiplatform (KMP) — `hl7Core` is a pure, dependency-light library (no Compose)
- Gradle Kotlin DSL
- Swift Package Manager (SPM)
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

> ⚠️ The `Hl7Core.xcframework` is **not committed to git** (too large). You must generate it locally before building the iOS app.

```bash
# Step 1 — Build the iosSimulatorArm64 framework first
./gradlew :hl7Core:linkReleaseFrameworkIosSimulatorArm64

# Step 2 — Package everything into the xcframework + merge simulator slices
./gradlew :hl7Core:createSwiftPackage
```

This produces `hl7Core/swiftpackage/Hl7Core.xcframework` with three slices:
- `ios-arm64` — physical device
- `ios-arm64_x86_64-simulator` — Apple Silicon + Intel Mac simulator (fat binary)

Verify the build succeeded:

```bash
ls hl7Core/swiftpackage/Hl7Core.xcframework/
# Expected: Info.plist  ios-arm64  ios-arm64_x86_64-simulator

lipo -info hl7Core/swiftpackage/Hl7Core.xcframework/ios-arm64_x86_64-simulator/Hl7Core.framework/Hl7Core
# Expected: Architectures in the fat file: Hl7Core are: x86_64 arm64
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
| Frameworks, Libraries, and Embedded Content | `Hl7Core` → **Do Not Embed** (static framework) |
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

## Step 3 — Usage (Kotlin)

```kotlin
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.parser.HL7ParseResult
import org.rite.hl7.builder.HL7Builder
import org.rite.hl7.model.segment.*

// Parser — fluent builder, register custom Z-segments, partial parse in non-strict mode.
val parser = HL7Parser.Builder()
    .defaultVersion("2.5")
    .registerCustomSegment(ZSNSegment.Definition)
    .registerCustomSegment(ZSVSegment.Definition)
    .registerCustomSegment(ZADSegment.Definition)
    .strictMode(false)
    .build()

val raw = """
    MSH|^~\&|WMS|WAREHOUSE|EHR|HOSPITAL|20240615||INR^U06|MSG-002|P|2.5
    INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA
    ZAD|1|LOSS|5|DAMAGED_IN_TRANSIT|20240615141500|JOHN.DOE
""".trimIndent()

when (val result = parser.parse(raw)) {
    is HL7ParseResult.Success -> {
        val inv = result.message.segment<INVSegment>("INV")
        val zad = result.message.segment<ZADSegment>("ZAD")
        println(inv?.inventoryOnHandQuantity)   // 150
        println(zad?.adjustmentReason)          // DAMAGED_IN_TRANSIT
    }
    is HL7ParseResult.Failure -> println(result.errors)  // result.partialMessage holds parsed segments
}

// Builder — one method per message type; nested segment blocks; encode() escapes + validates.
val builder = HL7Builder.builder()
    .defaultVersion("2.5")
    .registerCustomSegment(ZSNSegment.Definition)
    .build()

val out = builder.rdsO13 {
    msh { it.sendingApplication = "PHARMACY-SYS"; it.messageControlId = "MSG-1" }
    orc { it.orderControl = "RE"; it.fillerOrderNumber = "RX-98765" }
    rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
    zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0042" }
}.encode()
```

### Supported message builders
`rdeO11`, `rdsO13`, `inrU05`, `inrU06`, `inuU05`, `qbpQ11`, `ack`. Any HL7 v2.x
message parses generically; unknown segments are preserved losslessly via
`GenericSegment`. Add a new typed Z-segment by registering a `SegmentDefinition`
— no core changes.

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
- Add `Hl7Core` library to your target

### Step 3 — Configure Build Settings

In your Xcode target → **Build Settings**:

```
Other Linker Flags:                     -ObjC
Excluded Architectures (Simulator):     x86_64
iOS Deployment Target:                  16.0
```

In **Frameworks, Libraries, and Embedded Content**:
- Set `Hl7Core` → **Do Not Embed**

## Option 2 — Remote Swift Package

```
https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder
```

> ⚠️ Requires Git LFS to be enabled on the remote if xcframework binaries are committed.

## Swift Usage

The library ships an optional Swift shim (`hl7Core/swiftshim/HL7Interop.swift`)
— add it to your app target for idiomatic `if case .success` matching and
`segment(T.self, named:)` typed access.

```swift
import Hl7Core   // framework renamed from ComposeApp

let parser = HL7Parser.Builder()
    .defaultVersion("2.5")
    .registerCustomSegment(ZSNSegment.companion.Definition)
    .registerCustomSegment(ZADSegment.companion.Definition)
    .strictMode(false)
    .build()

if case .success(let message) = parser.parseResult(raw) {        // shim helper
    let inv = message.segment(INVSegment.self, named: "INV")     // shim helper
    let zad = message.segment(ZADSegment.self, named: "ZAD")
    print(inv?.inventoryOnHandQuantity ?? "")   // 150
    print(zad?.adjustmentReason ?? "")          // DAMAGED_IN_TRANSIT
}

// Builder
let builder = HL7Builder.companion.builder()
    .defaultVersion("2.5")
    .build()

let out = builder.rdsO13 { scope in
    scope.msh { $0.sendingApplication = "PHARMACY-SYS"; $0.messageControlId = "MSG-1" }
    scope.rxd { $0.dispenseGiveCode = "00093-0058-01"; $0.actualDispenseAmount = "90" }
    scope.zsn { $0.setId = "1"; $0.packageSerialNumber = "21N4F9XK0042" }
}.encode()
```

> Without the shim, parse results are matched with `onEnum(of:)` /
> `as? HL7ParseResultSuccess` and typed access via
> `message.segmentNamed(name:) as? INVSegment`.

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
│   ├── commonMain/kotlin/org/rite/hl7/
│   │   ├── HL7.kt                     # batteries-included facade (parse/build/validate/ack)
│   │   ├── encoding/                  # delimiters, escape/unescape, MLLP framing
│   │   ├── model/
│   │   │   ├── ast/                   # HL7Component / HL7Field / HL7Segment (generic, lossless)
│   │   │   ├── segment/               # typed segments (MSH…ZSN/ZSV/ZAD) + GenericSegment
│   │   │   ├── HL7Message.kt          # segment<T>() / segments<T>() accessors
│   │   │   ├── HL7MessageKind.kt      # business classification
│   │   │   ├── TypedSegment.kt        # thin-getter base
│   │   │   ├── SegmentDefinition.kt   # custom-segment registration
│   │   │   └── SegmentRegistry.kt
│   │   ├── parser/                    # HL7Lexer, HL7Parser (+ Builder), HL7ParseResult
│   │   ├── builder/                   # HL7Builder (+ Builder), segment + message-scope builders
│   │   ├── validation/               # HL7Validator, AckBuilder, ValidationConfig/Result
│   │   ├── version/                   # HL7Version, SegmentCapabilities
│   │   └── util/                      # HL7Date, CurrentLocalDateTime (expect)
│   │
│   ├── commonTest/kotlin/org/rite/hl7/  # roundtrip, escaping, parse, build, validation tests
│   ├── androidMain/  └── iosMain/       # currentLocalDateTime actuals only
│
├── swiftshim/HL7Interop.swift          # optional Swift facade (.success / segment(T.self,named:))
├── swiftpackage/                       # Generated — do not commit (see .gitignore)
│   ├── Package.swift
│   └── Hl7Core.xcframework/
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

- **Never commit** `Hl7Core.xcframework` or `.zip` binaries to git — regenerate with Gradle
- Run `./gradlew :hl7Core:createSwiftPackage` after every KMP code change before opening Xcode
- Keep modules independent with clear boundaries
- Maintain unit tests for parser and builder
- Follow KMP folder conventions (`commonMain`, `androidMain`, `iosMain`)

---

# 📞 Support

Maintained by **Rite Technologies**
