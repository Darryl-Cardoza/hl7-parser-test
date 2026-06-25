// swift-tools-version:5.3
import PackageDescription

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
            path: "./Hl7Core.xcframework"
        ),
    ]
)
