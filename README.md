# Mobile Rite HL7 Parser Builder

A comprehensive Kotlin Multiplatform (KMP) solution for parsing and building HL7 messages in clinical and healthcare applications. This repository is dedicated to CMP (Clinical Message Processing) HL7 message handling, supporting both Android and iOS platforms with a shared codebase.

## Overview

The **Mobile Rite HL7 Parser Builder** is designed to streamline HL7 message processing in mobile healthcare applications. It provides robust parsing, validation, and building capabilities for HL7 messages across multiple platforms, ensuring consistency and reliability in clinical data exchange.

### Key Features

- **Cross-Platform Support**: Native Android and iOS applications using Kotlin Multiplatform
- **HL7 Message Parsing**: Parse and extract data from standard HL7 v2 messages
- **Message Building**: Construct valid HL7 messages programmatically
- **CMP Integration**: Optimized for Clinical Message Processing workflows
- **Shared Business Logic**: Common code base for both Android and iOS reduces maintenance overhead
- **Type-Safe Operations**: Leverage Kotlin's type system for safer message handling

## Technology Stack

### Languages
- **Kotlin** (46.9%) - Primary language for multiplatform logic
- **Objective-C** (52.7%) - iOS native integration
- **Swift** (0.4%) - iOS interoperability layer

### Framework
- **Kotlin Multiplatform Mobile (KMM)** - Shared codebase for Android and iOS
- **Compose Multiplatform** - Modern UI toolkit

## Project Structure

```
mob_rite_hl7_parser_builder/
├── composeApp/                           # Shared Compose Multiplatform code
│   └── src/
│       ├── commonMain/kotlin/           # Common code for all targets
│       ├── androidMain/kotlin/          # Android-specific implementations
│       ├── iosMain/kotlin/              # iOS-specific implementations (Kotlin)
│       └── jvmMain/kotlin/              # JVM-specific code (if applicable)
├── iosApp/                               # iOS application entry point
│   ├── iosApp/                          # iOS app with SwiftUI
│   └── [other iOS configurations]
└── gradle/                               # Gradle build system files
```

### Directory Breakdown

- **[/composeApp](./composeApp/src)** - Shared code across Compose Multiplatform applications
  - **[commonMain](./composeApp/src/commonMain/kotlin)** - Code shared across all targets (Android, iOS, JVM)
  - **[androidMain](./composeApp/src/androidMain/kotlin)** - Android-specific implementations
  - **[iosMain](./composeApp/src/iosMain/kotlin)** - iOS-specific implementations (Kotlin/Native)
    - Use for Apple framework integrations (e.g., CoreCrypto, Security framework)
  - **[jvmMain](./composeApp/src/jvmMain/kotlin)** - Desktop/JVM-specific code

- **[/iosApp](./iosApp)** - iOS application
  - Contains the iOS app entry point required for the iOS platform
  - SwiftUI code and iOS-specific configurations reside here
  - Even with shared UI logic, this folder is necessary for app deployment

## Getting Started

### Prerequisites

- Kotlin 1.9.0 or higher
- Gradle 8.0+
- For Android: Android Studio and Android SDK
- For iOS: Xcode 14+ and macOS
- Java Development Kit (JDK) 11+

### Installation

1. Clone the repository:
```bash
git clone https://github.com/Rite-Technologies-23/mob_rite_hl7_parser_builder.git
cd mob_rite_hl7_parser_builder
```

2. Build the project:
```bash
# On macOS/Linux
./gradlew build

# On Windows
.\gradlew.bat build
```

## Build and Run

### Android Application

To build and run the development version of the Android app:

**macOS/Linux:**
```shell
./gradlew :composeApp:assembleDebug
```

**Windows:**
```shell
.\gradlew.bat :composeApp:assembleDebug
```

Alternatively, use the run configuration from your IDE's toolbar for a one-click build and deploy experience.

### iOS Application

To build and run the development version of the iOS app:

1. **Using IDE:**
   - Use the run configuration from your IDE's toolbar

2. **Using Xcode:**
   - Open the [/iosApp](./iosApp) directory in Xcode
   - Select your target device or simulator
   - Click the Run button

**Note:** Even though UI logic is shared via Compose Multiplatform, the iOS app requires a native entry point in this directory for proper deployment and SwiftUI integration.

## HL7 Parsing Usage

### Basic Example: Parsing an HL7 Message

```kotlin
// Example HL7 message
val hl7Message = "MSH|^~\\&|SENDAPP|SENDHOSP|RECAPP|RECHOSP|20230315153045||ADT^A01|MSG00001|P|2.5..."

// Parse the message (implementation details in commonMain)
val parsedMessage = HL7Parser.parse(hl7Message)

// Access segments
val mshSegment = parsedMessage.getSegment("MSH")
val pidSegment = parsedMessage.getSegment("PID")

// Extract specific fields
val messageType = mshSegment.getField(9)
val sendingApplication = mshSegment.getField(3)
```

### Building an HL7 Message

```kotlin
// Create a new HL7 message builder
val builder = HL7MessageBuilder()
    .addMSHSegment(
        sendingApplication = "SENDAPP",
        sendingFacility = "SENDHOSP",
        receivingApplication = "RECAPP",
        receivingFacility = "RECHOSP",
        timestamp = getCurrentTimestamp()
    )
    .addPIDSegment(
        patientID = "12345",
        patientName = "Doe, John",
        dateOfBirth = "19800101",
        gender = "M"
    )

val hl7Message = builder.build()
```

## Development Workflow

### Adding Platform-Specific Code

#### For Android:
Place your Android-specific code in `composeApp/src/androidMain/kotlin/`

#### For iOS:
Place your iOS-specific Kotlin code in `composeApp/src/iosMain/kotlin/`
For native Swift code, place it in `iosApp/iosApp/`

### Testing

```bash
# Run all tests
./gradlew test

# Run Android tests
./gradlew :composeApp:testDebug

# Run iOS tests
./gradlew :composeApp:iosSimulatorArm64Test
```

## Contributing

We welcome contributions to improve the HL7 parser and builder functionality. Please follow these guidelines:

1. Create a feature branch from `main`
2. Make your changes with clear, descriptive commits
3. Ensure all tests pass
4. Submit a pull request with a detailed description of your changes

## Project Guidelines

- Use Kotlin idioms and best practices
- Write unit tests for all new functionality
- Maintain backward compatibility when possible
- Document complex algorithms and unusual implementations
- Follow the existing code structure and naming conventions

## Common Tasks

### Updating Dependencies

```bash
./gradlew dependencies --refresh-dependencies
```

### Cleaning Build Artifacts

```bash
# macOS/Linux
./gradlew clean

# Windows
.\\gradlew.bat clean
```

### Building Release Versions

```bash
# Android Release
./gradlew :composeApp:assembleRelease

# iOS Release
# Use Xcode's build scheme or configure in build.gradle.kts
```

## Architecture

The project follows a modular architecture pattern:

- **Common Module** (`commonMain`) - Shared HL7 parsing/building logic, data models
- **Platform Modules** (`androidMain`, `iosMain`) - Platform-specific implementations and optimizations
- **UI Layer** - Compose Multiplatform for cross-platform user interfaces
- **Integration Layer** - Native platform integrations via expect/actual declarations

## Troubleshooting

### iOS Build Issues

If you encounter iOS build issues:
1. Ensure Xcode is up to date
2. Clean build folder: `Cmd + Shift + K`
3. Delete derived data: `~/Library/Developer/Xcode/DerivedData`
4. Rebuild the project

### Android Build Issues

If Gradle fails to sync:
1. Run `./gradlew clean`
2. Invalidate caches and restart IDE
3. Check Java version: `java -version` (should be 11+)

## Resources

- [Kotlin Multiplatform Documentation](https://www.jetbrains.com/help/kotlin-multiplatform-dev/get-started.html)
- [HL7 v2 Standard](https://www.hl7.org/implement/standards/product_brief.cfm?product_id=185)
- [Compose Multiplatform](https://www.jetbrains.com/help/compose-multiplatform/)
- [Kotlin Documentation](https://kotlinlang.org/docs/)

## License

Please refer to the LICENSE file in the repository for licensing information.

## Support

For issues, questions, or feature requests, please open an issue on the [GitHub repository](https://github.com/Rite-Technologies-23/mob_rite_hl7_parser_builder).

## Contact

For more information about Rite Technologies, visit [Rite Technologies](https://www.rite-technologies.com)

---

**Last Updated:** March 2026