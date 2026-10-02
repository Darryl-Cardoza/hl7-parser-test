# hl7Core Library Integration Guide

Developer reference for integrating the `hl7Core` Kotlin Multiplatform library into
Android and iOS projects. All code samples map 1-to-1 to the library's public API —
no modifications to `hl7Core` are required or allowed.

The live reference implementation lives in `composeApp/` — specifically:
- `MllpServer.kt` — Android TCP server
- `MllpServerViewModel.kt` — state management
- `MllpServerScreen.kt` — Compose UI showing every field the library surfaces

---

## 1. Adding the Dependency

### Android / Kotlin Multiplatform (Gradle)

```kotlin
// settings.gradle.kts
include(":hl7Core")

// composeApp/build.gradle.kts
kotlin {
    sourceSets {
        commonMain.dependencies {
            implementation(project(":hl7Core"))
            // If published to Maven Central:
            // implementation("org.rite:hl7core:<version>")
        }
    }
}
```

### iOS — Swift Package Manager

The `hl7Core` module ships as an XCFramework via Swift Package Manager.
Run `./gradlew :hl7Core:createSwiftPackage` to build it, then add:

```swift
// Package.swift
dependencies: [
    .package(path: "../hl7Core/swiftpackage"),
],
targets: [
    .target(name: "MyApp", dependencies: ["Hl7Core"]),
]
```

Or add via Xcode → File → Add Package Dependencies, pointing at the `swiftpackage/` directory.

### iOS — CocoaPods

```ruby
# Podfile
pod 'Hl7Core', :path => '../hl7Core'
```

---

## 2. The HL7 Facade (Recommended Entry Point)

`HL7` is the batteries-included entry point. It wires `HL7Parser`, `HL7Builder`,
`HL7Validator`, and `AckBuilder` together with Z-segment extensions pre-registered.
One instance per app is sufficient — it is immutable and thread-safe.

### Android / Kotlin

```kotlin
import org.rite.hl7.HL7

// Default: version 2.5.1, strict mode off, standard ValidationConfig
val hl7 = HL7()

// Custom:
val hl7 = HL7(
    version = "2.5",
    strictMode = true,                          // parse failures return Failure, no partial message
    validationConfig = ValidationConfig.DEFAULT, // override rules if needed
)
```

### iOS / Swift

```swift
import Hl7Core

let hl7 = HL7()                    // version 2.5.1, strictMode false
let hl7strict = HL7(version: "2.5", strictMode: true,
                    validationConfig: ValidationConfig.companion.DEFAULT,
                    extraSegments: [])
```

---

## 3. Parsing HL7 Text

### Android / Kotlin

```kotlin
import org.rite.hl7.HL7
import org.rite.hl7.parser.HL7ParseResult

val raw = "MSH|^~\\&|SenderApp|SenderFac|RecvApp|RecvFac|20240101120000||RDE^O11|CTRL001|P|2.5.1"

when (val result = hl7.parse(raw)) {
    is HL7ParseResult.Success -> {
        val msg = result.message

        // Connection / routing fields (from MSH)
        println("Message type:   ${msg.messageCode}^${msg.triggerEvent}") // "RDE^O11"
        println("Control ID:     ${msg.messageControlId}")                 // MSH-10
        println("Sender app:     ${msg.header?.sendingApplication}")       // MSH-3
        println("Sender facility:${msg.sendingFacility}")                  // MSH-4
        println("HL7 version:    ${msg.version}")                          // from MSH-12

        // All segments found by the parser
        println("Segments: ${msg.typedSegments.map { it.segmentName }}")   // ["MSH","ORC","RXE",...]

        // Business classification (DISPENSE, INVENTORY_REQUEST, QUERY, UNKNOWN, …)
        println("Kind: ${msg.kind}")
    }
    is HL7ParseResult.Failure -> {
        // errors: List<HL7ParseError> — each has message, segmentName?, lineIndex?
        println("Parse failed: ${result.errors.map { it.message }}")
        // In non-strict mode, result.partialMessage holds successfully-parsed segments
        result.partialMessage?.let { println("Partial segments: ${it.typedSegments.size}") }
    }
}
```

### iOS / Swift

```swift
import Hl7Core

let raw = "MSH|^~\\&|SenderApp|SenderFac|RecvApp|RecvFac|20240101120000||RDE^O11|CTRL001|P|2.5.1"

let result = hl7.parse(raw: raw)
if let success = result as? HL7ParseResultSuccess {
    let msg = success.message
    print("Type: \(msg.messageCode)^\(msg.triggerEvent)")
    print("Control ID: \(msg.messageControlId)")
    print("Sender: \(msg.sendingFacility)")
} else if let failure = result as? HL7ParseResultFailure {
    print("Parse failed: \(failure.errors.map { $0.message })")
}
```

---

## 4. Parsing MLLP-Framed Bytes

MLLP (Minimal Lower Layer Protocol, HL7 Appendix C) wraps HL7 for TCP transport.

**Frame format:**  `0x0B` + HL7 text + `0x1C` + `0x0D`
- `0x0B` = VT (Vertical Tab / Start Block)
- `0x1C` = FS (File Separator / End Block)
- `0x0D` = CR (Carriage Return)

### Android / Kotlin

```kotlin
import org.rite.hl7.HL7
import org.rite.hl7.encoding.Mllp

// Parse MLLP-framed bytes received from a socket:
val frameBytes: ByteArray = receivedFromSocket()
val result = hl7.parseMllp(frameBytes)          // strips framing then parses

// Parse multiple concatenated frames on one connection:
val results: List<HL7ParseResult> = hl7.parseMllpBatch(batchBytes)

// Wrap HL7 text in MLLP framing before sending:
val hl7Text = "MSH|^~\\&|..."
val framedBytes: ByteArray = Mllp.wrap(hl7Text)
socket.getOutputStream().write(framedBytes)

// Strip framing manually (if you need the raw text):
val rawText: String = Mllp.strip(frameBytes)
```

### iOS / Swift (client mode — see §8 for the full pattern)

```swift
import Hl7Core

// Strip framing and parse:
let frameData: Data = receivedFromStream()
let frameBytes: KotlinByteArray = frameData.toKotlinByteArray()
let result = hl7.parseMllp(bytes: frameBytes)

// Wrap for sending:
let framedBytes: KotlinByteArray = Mllp.companion.wrap(hl7: hl7Text)
outputStream.write(framedBytes.toData(), maxLength: framedBytes.size)
```

---

## 5. Validating a Message

`HL7Validator` checks required fields, NDC format, supported message types,
and Z-segment business rules. The result drives the ACK code.

### Android / Kotlin

```kotlin
import org.rite.hl7.validation.AckSeverity

val message = (hl7.parse(raw) as HL7ParseResult.Success).message
val validation = hl7.validate(message)

println("Valid:    ${validation.isValid}")         // true if no issues
println("ACK code: ${validation.worst.code}")      // "AA" | "AE" | "AR"

// Iterate issues:
validation.issues.forEach { issue ->
    when (issue.severity) {
        AckSeverity.ACCEPT -> { /* no problem */ }
        AckSeverity.ERROR  -> println("AE [${issue.segmentId}-${issue.fieldPosition}]: ${issue.errorText}")
        AckSeverity.REJECT -> println("AR [${issue.segmentId}-${issue.fieldPosition}]: ${issue.errorText}")
    }
}

// Severity levels (worst → ACK code):
// ACCEPT → "AA"  (application accept)
// ERROR  → "AE"  (application error — received but with issues)
// REJECT → "AR"  (application reject — not processed)
```

### iOS / Swift

```swift
import Hl7Core

let message = (hl7.parse(raw: raw) as! HL7ParseResultSuccess).message
let validation = hl7.validate(message: message)

print("Valid: \(validation.isValid)")
print("ACK code: \(validation.worst.code)")

for issue in validation.issues {
    print("\(issue.severity.name) [\(issue.segmentId ?? "")-\(issue.fieldPosition ?? "")]: \(issue.errorText)")
}
```

---

## 6. Sending ACK / NACK

`HL7.ack()` validates the message and returns a fully-encoded ACK^R01 string.
`AckBuilder` mirrors the inbound MSH sender/receiver so the ACK routes back.

### Android / Kotlin

```kotlin
import org.rite.hl7.encoding.Mllp

// Validate + build ACK text in one call:
val ackText: String = hl7.ack(message)

// Send over MLLP:
socket.getOutputStream().write(Mllp.wrap(ackText))
socket.getOutputStream().flush()

// The ACK code embedded in MSA-1 matches validation.worst.code:
// AA if isValid, AE if worst==ERROR, AR if worst==REJECT
```

### iOS / Swift

```swift
import Hl7Core

let ackText: String = hl7.ack(message: message)
let framedBytes: KotlinByteArray = Mllp.companion.wrap(hl7: ackText)
// write framedBytes via your stream
```

---

## 7. Android: MLLP TCP Server Pattern

The full annotated reference is in
`composeApp/src/androidMain/kotlin/org/rite/hl7/MllpServer.kt`.

**Minimum viable server:**

```kotlin
import java.net.ServerSocket
import java.net.SocketException
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.launch
import org.rite.hl7.HL7
import org.rite.hl7.encoding.Mllp
import org.rite.hl7.parser.HL7ParseResult

// One HL7 instance per server — immutable, thread-safe
val hl7 = HL7()
val scope = CoroutineScope(Dispatchers.IO + SupervisorJob())
var serverSocket: ServerSocket? = null

fun startServer(port: Int = 2575) {
    scope.launch {
        val server = ServerSocket(port).also { serverSocket = it }

        while (!server.isClosed) {
            // accept() blocks until a client connects or the socket is closed.
            val client = try { server.accept() }
                         catch (e: SocketException) { break } // stop() was called

            client.use { socket ->
                // 1. Read until MLLP end-block sentinel (0x1C followed by 0x0D).
                //    TCP may split the frame; accumulate bytes byte-by-byte.
                val frameBytes = readMllpFrame(socket.getInputStream()) ?: return@use

                // 2. Parse + validate via hl7Core
                val ackText = when (val result = hl7.parseMllp(frameBytes)) {
                    is HL7ParseResult.Success -> hl7.ack(result.message) // validate + build ACK
                    is HL7ParseResult.Failure -> buildMinimalArAck()      // parse failed → AR
                }

                // 3. Send MLLP-wrapped ACK back before closing
                socket.getOutputStream().write(Mllp.wrap(ackText))
                socket.getOutputStream().flush()
            }
        }
    }
}

fun stopServer() { serverSocket?.close() }

// Accumulate bytes until 0x1C+0x0D sentinel; return null on EOF (client disconnect)
fun readMllpFrame(stream: java.io.InputStream): ByteArray? {
    val buf = mutableListOf<Byte>()
    var prev = -1
    while (true) {
        val b = stream.read().also { if (it == -1) return null }
        buf.add(b.toByte())
        if (prev == 0x1C && b == 0x0D) return buf.toByteArray()
        prev = b
    }
}
```

**Required — AndroidManifest.xml:**
```xml
<uses-permission android:name="android.permission.INTERNET" />
```

---

## 8. iOS: Client-Mode Socket Pattern

iOS sandbox prevents binding server sockets in foreground apps.
Use `Network.framework` (iOS 12+) as a client to send HL7 and receive ACK:

```swift
import Network
import Hl7Core

let hl7 = HL7()
var connection: NWConnection?

func sendHl7Message(host: String, port: Int, message: HL7Message) {
    connection = NWConnection(
        host: NWEndpoint.Host(host),
        port: NWEndpoint.Port(integerLiteral: UInt16(port)),
        using: .tcp
    )

    connection?.stateUpdateHandler = { state in
        guard case .ready = state else { return }

        // Encode + MLLP-wrap the message
        let hl7Text = message.encode()
        let framedBytes = Mllp.companion.wrap(hl7: hl7Text)
        let data = Data(bytes: framedBytes.toArray(), count: Int(framedBytes.size))

        connection?.send(content: data, completion: .contentProcessed { _ in
            // Receive the ACK frame (read until 0x1C+0x0D sentinel)
            receiveAck()
        })
    }
    connection?.start(queue: .global())
}

func receiveAck() {
    // Read enough bytes to cover a typical ACK frame
    connection?.receive(minimumIncompleteLength: 3, maximumLength: 65536) { data, _, isComplete, _ in
        guard let data = data, !data.isEmpty else { return }
        let frameBytes = KotlinByteArray(size: Int32(data.count))
        data.withUnsafeBytes { ptr in
            for (i, b) in ptr.enumerated() { frameBytes.set(index: Int32(i), value: Int8(bitPattern: b)) }
        }
        let ackResult = hl7.parseMllp(bytes: frameBytes)
        if let success = ackResult as? HL7ParseResultSuccess {
            let ack = success.message
            let msaCode = ack.header?.acknowledgmentCode ?? "?"
            print("ACK received: \(msaCode)")  // "AA" | "AE" | "AR"
        }
    }
}
```

---

## 9. Accessing Typed Segments

After parsing, access specific segment data via typed wrappers:

### Android / Kotlin

```kotlin
import org.rite.hl7.model.segment.RXESegment
import org.rite.hl7.model.segment.ORCSegment

val message = (hl7.parse(raw) as HL7ParseResult.Success).message

// First segment of a type:
val rxe = message.segment<RXESegment>(RXESegment.NAME)
rxe?.let {
    println("NDC:      ${it.giveCode}")           // RXE-2
    println("Quantity: ${it.giveAmountMinimum}")  // RXE-3
    println("Drug:     ${it.giveDrugName}")        // RXE-2.2
}

// All segments of a type:
val orcs = message.segments<ORCSegment>(ORCSegment.NAME)
orcs.forEach { orc ->
    println("Order control: ${orc.orderControl.code}") // ORC-1 (typed enum)
    println("Rx number:     ${orc.placerOrderNumber}")  // ORC-2
}

// Order groups: ORC + RXE pairs in RDE^O11/O25 messages
message.orderGroups.forEach { group ->
    println("${group.orc.placerOrderNumber} → NDC ${group.rxe?.giveCode}")
}
```

---

## 10. Custom / Z-Segment Registration

### Android / Kotlin — via HL7 facade

```kotlin
import org.rite.hl7.HL7
import org.rite.hl7.model.segment.ZADSegment

// ZSN, ZSV, ZAD are pre-registered in HL7() by default.
// Pass additional custom segments via extraSegments:
val hl7 = HL7(extraSegments = listOf(ZADSegment.Definition))
```

### Android / Kotlin — via HL7Parser.Builder (fine-grained control)

```kotlin
import org.rite.hl7.parser.HL7Parser
import org.rite.hl7.model.segment.ZADSegment

val parser = HL7Parser.Builder()
    .defaultVersion("2.5.1")
    .registerCustomSegment(ZADSegment.Definition) // register each custom segment
    .strictMode(false)
    .build()

val result = parser.parse(raw)
```

### iOS / Swift

The XCFramework pre-registers ZSN/ZSV/ZAD. Use `HL7()` directly. Custom segments
require exposing their `SegmentDefinition` across the Kotlin/Swift boundary — add
them to `HL7.extraSegments` in the Kotlin layer and rebuild the framework.

---

## 11. Common Gotchas

| Problem | Cause | Fix |
|---|---|---|
| `Parse failed: Empty HL7 message` | Blank string passed to `parse()` | Guard against blank/null before calling |
| `Invalid NDC` validation error | NDC must be 10–11 digits or hyphenated `4-5/3-4/1-2` | Normalize NDC format before building |
| ACK code `AR` for valid-looking message | Unsupported type (e.g. `INU^U06`, `ACK`) sent inbound | Library rejects types that are outbound-only |
| MLLP frame never completes | Sender omits `0x1C 0x0D` end-block | Ensure sender uses `Mllp.wrap()` or equivalent |
| `SocketException` on `accept()` | Expected when `ServerSocket.close()` is called | Catch and treat as normal stop, not an error |
| Partial TCP frame | TCP splits the MLLP frame across segments | Accumulate bytes byte-by-byte until sentinel found |
| `strictMode = true`, partial parse returned | Even one segment error → `Failure` with no partial | Use `strictMode = false` (default) for resilience |
| ViewModel event not updating UI on Android | `viewModelScope.launch` requires Main dispatcher | Call `handleEvent()` directly; `MutableStateFlow.update` is thread-safe |

---

## 12. API Quick Reference

| Class / Function | Location | Purpose |
|---|---|---|
| `HL7` | `commonMain` | Facade: parser + builder + validator + ackBuilder |
| `HL7Parser.Builder` | `commonMain` | Fine-grained parser construction |
| `HL7Parser.parse(raw)` | `commonMain` | Parse raw HL7 text → `HL7ParseResult` |
| `HL7Parser.parseMllp(bytes)` | `commonMain` | Strip MLLP framing + parse → `HL7ParseResult` |
| `HL7Parser.parseMllpBatch(bytes)` | `commonMain` | Parse multiple concatenated MLLP frames |
| `HL7Message.typedSegments` | `commonMain` | All parsed segments in order |
| `HL7Message.segment<T>(name)` | `commonMain` | First segment of type `T` |
| `HL7Message.orderGroups` | `commonMain` | ORC+RXE pairs for RDE^O11/O25 |
| `HL7Message.kind` | `commonMain` | Business classification enum |
| `HL7Validator.validate(msg)` | `commonMain` | → `ValidationResult` (isValid, worst, issues) |
| `AckBuilder.build(msg, result)` | `commonMain` | Build ACK^R01 `HL7Message` |
| `HL7.ack(message)` | `commonMain` | Validate + build + encode ACK in one call |
| `Mllp.wrap(text)` | `commonMain` | Encode HL7 string to MLLP `ByteArray` |
| `Mllp.strip(bytes)` | `commonMain` | Remove MLLP framing from `ByteArray` |
| `Mllp.stripAll(bytes)` | `commonMain` | Split batch frame into individual HL7 strings |
| `MllpServer` | `androidMain` | Reference TCP server implementation |

---

*This guide was generated from the PillCount-Hl7 reference implementation.*
*See `composeApp/src/androidMain/kotlin/org/rite/hl7/MllpServer.kt` for the annotated server.*
