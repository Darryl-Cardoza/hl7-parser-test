// swift-tools-version:5.3
import PackageDescription

// RELEASE: the Release workflow attaches the updated manifest to the release.
// Manual branch releases also include it in the newly created version tag.
// See docs/RELEASING.md for the release procedure.
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
            url: "https://github.com/Rite-Technologies-23/mobrite_hl7_parser_builder/releases/download/v1.0.0/Hl7Core-1.0.0.zip",
            checksum: "16e19a5697053c8f961d21dfd5bc8bbb533bc2c8075bc66025c1e282f57154fa"
        ),
    ]
)
