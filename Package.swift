// swift-tools-version:5.3
import PackageDescription

// RELEASE: url and checksum are updated automatically by scripts/publish-release.sh
// Do not edit these values manually — run the release script instead.
let package = Package(
    name: "Hl7Core",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "Hl7Core",
            targets: ["Hl7Core"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "Hl7Core",
            url: "https://github.com/bhushanrite/PillCount-Hl7/releases/download/v1.0.0/Hl7Core.xcframework.zip",
            checksum: "PLACEHOLDER_CHECKSUM_UPDATED_BY_RELEASE_SCRIPT"
        ),
    ]
)
