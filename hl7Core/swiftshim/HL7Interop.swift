// HL7Interop.swift
//
// Idiomatic Swift facade over the Hl7Core KMP framework. Add this file to your
// iOS app target (it is NOT part of the xcframework binary — it is thin source
// that adapts the generated Kotlin API to Swift conventions).
//
// With this shim you can write:
//
//     let parser = HL7Parser.Builder()
//         .defaultVersion("2.5")
//         .registerCustomSegment(ZSNSegment.companion.Definition)
//         .strictMode(false)
//         .build()
//
//     if case .success(let message) = parser.parseResult(raw) {
//         let inv = message.segment(INVSegment.self, named: "INV")
//         print(inv?.inventoryOnHandQuantity ?? "")
//     }

import Foundation
import Hl7Core

/// Swift-native mirror of the Kotlin `HL7ParseResult` sealed class.
public enum HL7Result {
    case success(HL7Message)
    case failure(errors: [HL7ParseError], partialMessage: HL7Message?)
}

public extension HL7Parser {
    /// Parses and returns a Swift enum you can pattern-match with `if case .success`.
    func parseResult(_ raw: String) -> HL7Result {
        let result = parse(raw: raw)
        if let s = result as? HL7ParseResultSuccess {
            return .success(s.message)
        }
        let f = result as! HL7ParseResultFailure
        return .failure(errors: f.errors, partialMessage: f.partialMessage)
    }
}

public extension HL7Message {
    /// Typed segment access: `message.segment(INVSegment.self, named: "INV")`.
    func segment<T: TypedSegment>(_ type: T.Type, named name: String) -> T? {
        return segmentNamed(name: name) as? T
    }

    /// All typed segments of a type: `message.segments(ZSNSegment.self, named: "ZSN")`.
    func segments<T: TypedSegment>(_ type: T.Type, named name: String) -> [T] {
        return segmentsNamed(name: name).compactMap { $0 as? T }
    }
}
