# iOS Integration Guide — Hl7Core

## No token required

iOS distribution uses GitHub Releases (public asset download). No authentication needed.

## Add via Xcode (recommended)

1. Open your project in Xcode
2. **File → Add Package Dependencies**
3. Paste URL: `https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder`
4. Select version rule: **Up to Next Major** from `1.0.0`
5. Add `Hl7Core` to your app target → **Add Package**

## Add via `Package.swift`

```swift
dependencies: [
    .package(
        url: "https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder",
        from: "1.0.0"
    )
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: ["Hl7Core"]
    )
]
```

## Swift facade (recommended)

Copy `hl7Core/swiftshim/HL7Interop.swift` into your app target. This gives you:
- Swift enum pattern matching on parse results (`if case .success(let msg) = ...`)
- Typed segment access (`message.segment(INVSegment.self, named: "INV")`)

It is a thin source file — not baked into the binary — so you can customise it freely.

## Usage example

```swift
import Hl7Core

let parser = HL7Parser.Builder()
    .defaultVersion("2.5")
    .build()

if case .success(let message) = parser.parseResult(rawHl7String) {
    let msh = message.segment(MSHSegment.self, named: "MSH")
    print(msh?.sendingApplication ?? "")
}
```

## Upgrading

In Xcode: **File → Packages → Update to Latest Package Versions**

Or change the version in your `Package.swift` and run `swift package resolve`.

## Troubleshooting

| Error | Cause | Fix |
|---|---|---|
| Checksum mismatch | Cached old version | File → Packages → Reset Package Caches |
| `binaryTarget` not found | Wrong repo URL | Verify URL is `https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder` |
| Build error after update | API change in new version | Check release notes on the GitHub Release page |
