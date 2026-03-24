Here’s your **final polished README.md** with:


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
- JVM / Android / iOS

---

# 📋 Prerequisites

- Kotlin 1.9+
- Android Studio / IntelliJ
- Xcode (for iOS)
- Gradle

---

# 🚀 Project Setup (Step by Step)

## 1. Clone Repository

```bash
git clone https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder.git
````

---

## 2. Use as Local Library

### Project Structure

```
your-project/
│
├── libraries/
│   └── hl7-parser/
```

---

# 🤖 Android Integration

> ⚠️ Note: Library is **NOT published to Maven yet**, use as **local Gradle module**

---

## Step 1 — Include Module

```kotlin
include(":libraries:hl7-parser")
```

---

## Step 2 — Add Dependency

```kotlin
dependencies {
    implementation(project(":libraries:hl7-parser"))
}
```

---

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

## Option 1 — Swift Package (Remote)

Add package via Xcode:

```
https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder
```

---

## Option 2 — Local Swift Package 

### Step 1 — Add Local Package

* Open Xcode
* File → Add Packages
* Select **Add Local**
* Choose cloned repo folder

---

### Step 2 — Package.swift (Manual)

```swift
.package(
    path: "../mobile_rite_hl7_parser_builder"
)
```

---

## Swift Usage

```swift
let parser = HL7Parser()

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

---

### iOS

* Run via Xcode (iosApp target)

---

# 🧪 Testing

```bash
./gradlew test
```

> ✅ Add unit tests if not present (parser + builder recommended)

---

# 📁 Folder Structure Overview

```
MOBRITE_HL7_PARSER_BUILDER
│
├── composeApp
├── hl7Core
├── iosApp
├── gradle
├── build.gradle.kts
├── settings.gradle.kts
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
│   │   ├── util/
│   │   │   └── AckGenerator.kt
│
│   ├── androidMain/
│   └── iosMain/
│
├── swiftpackage/
├── build.gradle.kts
```

---

## 📌 Directory Explanation

| Folder      | Description              |
| ----------- | ------------------------ |
| builder     | HL7 message construction |
| parser      | HL7 message parsing      |
| domain      | Data models & utilities  |
| util        | Helper utilities         |
| androidMain | Android-specific code    |
| iosMain     | iOS-specific code        |

---

# ⚙️ Configuration Details

## Gradle

```kotlin
implementation(project(":libraries:hl7-parser"))
```

---

## Swift Package

```swift
.package(
    url: "https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder",
    from: "1.0.0"
)
```

---

# 📦 Adding a New Module

## Step 1 — Create Module

```
libraries/new-module/
```

---

## Step 2 — Register

```kotlin
include(":libraries:new-module")
```

---

## Step 3 — Use

```kotlin
implementation(project(":libraries:new-module"))
```

---

# ✅ Best Practices

* Add **About section** in all repositories
* Keep modules independent
* Maintain **unit tests**
* Follow KMP folder conventions

---

# 📞 Support

Maintained by **Rite Technologies**

