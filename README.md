# MobRite HL7 Parser Builder

A **Kotlin Multiplatform (KMP)** library designed for **HL7 message parsing and building** used in **Clinical Message Processing (CMP)** systems.

The project provides a unified HL7 toolkit capable of running across **Android, iOS, Desktop JVM**, and other Kotlin-supported platforms while maintaining a single shared codebase.

---

# 📖 Overview

Healthcare systems rely heavily on **HL7 (Health Level 7)** messages for exchanging clinical and operational data between systems such as:

- Pharmacy Management Systems (PMS)
- Electronic Medical Records (EMR)
- Laboratory Information Systems (LIS)
- Clinical Message Processing (CMP) engines
- Hospital Information Systems (HIS)

Implementing HL7 support across multiple platforms can be complex due to:

- Message formatting rules
- Segment validation
- Encoding rules
- Platform-specific parsing logic

This library solves those problems by providing a **single Kotlin Multiplatform HL7 engine**.

---

# 🎯 Use Cases

| System | Usage |
|------|------|
Pharmacy Systems | Prescription processing |
Hospital Systems | Patient admission updates |
Laboratory Systems | Lab result transmission |
Clinical Middleware | HL7 message routing |
Healthcare Mobile Apps | HL7 message parsing |

---

# ✨ Features

## Core HL7 Capabilities

- HL7 message parsing
- HL7 message building
- Segment validation
- Field extraction
- Message serialization
- Error handling

---

## Parser Features

- Token-based parsing engine
- Segment validation
- Field indexing support
- HL7 delimiter handling
- Structured message model output

---

## Builder Features

- Fluent message builder API
- Segment creation helpers
- Field insertion utilities
- HL7 message serialization

---

## Platform Support

| Platform | Supported |
|--------|--------|
Android | ✅ |
iOS | ✅ |
Desktop JVM | ✅ |
Kotlin Multiplatform | ✅ |

---

# 🚀 Usage Process

### 1. Add Library

### Android

Add dependency in `build.gradle.kts` if uploaded to maven else use as local package for android or swiftpackage for iOS

```kotlin
dependencies {
    implementation("com.rite.hl7:parser:1.0.0")
}
```

---

### iOS

Add Swift Package via GitHub:

```
https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder
```

---

# 📱 Android Integration (CMP Local Package)

### Step 1 — Add Module

Clone repository:

```bash
git clone https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder.git
```

Move module into project:

```
your-project/
  libraries/
     hl7-parser/
```

---

### Step 2 — Update `settings.gradle.kts`

```kotlin
include(":libraries:hl7-parser")
include(":app")
```

---

### Step 3 — Add Dependency

```kotlin
dependencies {
    implementation(project(":libraries:hl7-parser"))
}
```

---

### Step 4 — Android Usage Example

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

# 🍎 iOS Integration (Swift Package)

### Option A — Xcode UI

1. Open Xcode
2. File → Add Packages
3. Enter GitHub URL

```
https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder
```

---

### Option B — Package.swift

```swift
.package(
    url: "https://github.com/Rite-Technologies-23/mobile_rite_hl7_parser_builder",
    from: "1.0.0"
)
```

---

### Swift Usage Example

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

# 📦 HL7 Parsing Example

```kotlin
val parser = HL7Parser()

val message = """
MSH|^~\&|APP|FACILITY
PID|1||12345||DOE^JOHN
""".trimIndent()

val result = parser.parse(message)

println(result.getSegment("PID"))
```

---

# 🏗️ HL7 Message Builder Example

```kotlin
val message = HL7MessageBuilder()
    .addSegment("MSH")
    .addField("APP")
    .addField("FACILITY")
    .addSegment("PID")
    .addField("12345")
    .build()

println(message)
```

---

# 📁 Project Structure

```
mobile_rite_hl7_parser_builder
│
├── composeApp
│   ├── src
│   │   ├── commonMain
│   │   ├── androidMain
│   │   ├── iosMain
│   │   └── jvmMain
│
├── iosApp
│   ├── iosApp
│   └── iosAppTests
│
├── gradle
├── build.gradle.kts
├── settings.gradle.kts
└── README.md
```

---

# 📁 Detailed Directory Breakdown

| Directory | Purpose |
|---------|--------|
composeApp/commonMain | Shared business logic |
composeApp/androidMain | Android specific code |
composeApp/iosMain | iOS specific code |
composeApp/jvmMain | Desktop support |
iosApp | iOS application wrapper |

---

# 🏗️ Architecture Overview

```
Application Layer
      │
      ▼
Presentation Layer
      │
      ▼
Business Logic Layer
      │
      ▼
HL7 Parser / Builder Engine
      │
      ▼
Platform Layer
(Android / iOS / JVM)
```

---

# 🔄 Message Parsing Flow

```
HL7 Message
      │
      ▼
Tokenizer
      │
      ▼
Segment Parser
      │
      ▼
Field Mapping
      │
      ▼
Model Objects
```

---

# 🔄 Message Building Flow

```
Builder API
     │
     ▼
Add Segments
     │
     ▼
Add Fields
     │
     ▼
Validation
     │
     ▼
Serialize HL7 Message
```

---

# 📊 Architecture Patterns

| Pattern | Usage |
|------|------|
Builder | HL7 message creation |
Factory | Parser creation |
Strategy | Validation logic |
Adapter | Platform integration |
Singleton | Parser configuration |

---

# 🔗 Module Dependency Graph

```
Application
   │
   ▼
HL7 Parser Library
   │
   ▼
Common HL7 Engine
   │
   ▼
Platform Implementations
(Android / iOS / JVM)
```

---

# 🔄 Data Flow

```
Incoming HL7 Message
      │
      ▼
Parser Engine
      │
      ▼
Structured HL7 Model
      │
      ▼
Application Logic
```

---

# 🧪 Testing Architecture

| Test Type | Description |
|---------|-----------|
Unit Tests | Parser functionality |
Integration Tests | End-to-end HL7 parsing |
Platform Tests | Android / iOS integration |

Run tests:

```
./gradlew test
```

---

# 🛠 Development Workflow

### Build Android

```
./gradlew :composeApp:assembleDebug
```

### Run Tests

```
./gradlew test
```



---

# 🧯 Troubleshooting

### Android Build Issues

Run clean:

```
./gradlew clean
```




---

# 📞 Support

Maintained by **Rite Technologies**

