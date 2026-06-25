#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class Hl7CoreAckScope, Hl7CoreAckSeverity, Hl7CoreEQUBuilder, Hl7CoreEQUSegmentCompanion, Hl7CoreERRBuilder, Hl7CoreERRSegmentCompanion, Hl7CoreHL7Builder, Hl7CoreHL7BuilderBuilder, Hl7CoreHL7BuilderCompanion, Hl7CoreHL7Component, Hl7CoreHL7ComponentCompanion, Hl7CoreHL7Date, Hl7CoreHL7Delimiters, Hl7CoreHL7DelimitersCompanion, Hl7CoreHL7Escaping, Hl7CoreHL7Field, Hl7CoreHL7FieldCompanion, Hl7CoreHL7Lexer, Hl7CoreHL7LexerLexResult, Hl7CoreHL7Message, Hl7CoreHL7MessageKind, Hl7CoreHL7MessageKindCompanion, Hl7CoreHL7ParseError, Hl7CoreHL7ParseResult, Hl7CoreHL7ParseResultFailure, Hl7CoreHL7ParseResultSuccess, Hl7CoreHL7Parser, Hl7CoreHL7ParserBuilder, Hl7CoreHL7Segment, Hl7CoreHL7SegmentBuilder, Hl7CoreHL7SegmentCompanion, Hl7CoreHL7Version, Hl7CoreHL7VersionCompanion, Hl7CoreINVBuilder, Hl7CoreINVSegmentCompanion, Hl7CoreInrU05Scope, Hl7CoreInrU06Scope, Hl7CoreInuU05Scope, Hl7CoreKotlinArray<T>, Hl7CoreKotlinByteArray, Hl7CoreKotlinByteIterator, Hl7CoreKotlinEnum<E>, Hl7CoreKotlinEnumCompanion, Hl7CoreKotlinException, Hl7CoreKotlinThrowable, Hl7CoreMSABuilder, Hl7CoreMSASegmentCompanion, Hl7CoreMSHBuilder, Hl7CoreMSHSegment, Hl7CoreMSHSegmentCompanion, Hl7CoreMessageScope, Hl7CoreMllp, Hl7CoreNTEBuilder, Hl7CoreNTESegmentCompanion, Hl7CoreOBXSegmentCompanion, Hl7CoreORCBuilder, Hl7CoreORCSegmentCompanion, Hl7CorePIDBuilder, Hl7CorePIDSegmentCompanion, Hl7CorePV1Builder, Hl7CorePV1SegmentCompanion, Hl7CoreQAKSegmentCompanion, Hl7CoreQPDBuilder, Hl7CoreQPDSegmentCompanion, Hl7CoreQbpQ11Scope, Hl7CoreRCPBuilder, Hl7CoreRCPSegmentCompanion, Hl7CoreRXCBuilder, Hl7CoreRXCSegmentCompanion, Hl7CoreRXDBuilder, Hl7CoreRXDSegmentCompanion, Hl7CoreRXEBuilder, Hl7CoreRXESegmentCompanion, Hl7CoreRXRBuilder, Hl7CoreRXRSegmentCompanion, Hl7CoreRdeO11Scope, Hl7CoreRdsO13Scope, Hl7CoreSegmentCapabilities, Hl7CoreSegmentDefinition, Hl7CoreTypedSegment, Hl7CoreValidationConfig, Hl7CoreValidationConfigCompanion, Hl7CoreValidationIssue, Hl7CoreValidationResult, Hl7CoreValidationResultCompanion, Hl7CoreZADBuilder, Hl7CoreZADSegmentCompanion, Hl7CoreZINBuilder, Hl7CoreZINSegmentCompanion, Hl7CoreZPRSegmentCompanion, Hl7CoreZSNBuilder, Hl7CoreZSNSegmentCompanion, Hl7CoreZSVBuilder, Hl7CoreZSVSegmentCompanion;

@protocol Hl7CoreKotlinComparable, Hl7CoreKotlinIterator;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface Hl7CoreBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface Hl7CoreBase (Hl7CoreBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface Hl7CoreMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface Hl7CoreMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorHl7CoreKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface Hl7CoreNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface Hl7CoreByte : Hl7CoreNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface Hl7CoreUByte : Hl7CoreNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface Hl7CoreShort : Hl7CoreNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface Hl7CoreUShort : Hl7CoreNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface Hl7CoreInt : Hl7CoreNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface Hl7CoreUInt : Hl7CoreNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface Hl7CoreLong : Hl7CoreNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface Hl7CoreULong : Hl7CoreNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface Hl7CoreFloat : Hl7CoreNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface Hl7CoreDouble : Hl7CoreNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface Hl7CoreBoolean : Hl7CoreNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * Convenience facade wiring a parser, builder, and validator together with the
 * PillCounter extension segments (ZSN/ZSV/ZAD) pre-registered.
 *
 * Apps that need finer control can build [HL7Parser]/[HL7Builder]/[HL7Validator]
 * directly; this is the batteries-included entry point.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7")))
@interface Hl7CoreHL7 : Hl7CoreBase
- (instancetype)initWithVersion:(NSString *)version strictMode:(BOOL)strictMode validationConfig:(Hl7CoreValidationConfig *)validationConfig extraSegments:(NSArray<Hl7CoreSegmentDefinition *> *)extraSegments __attribute__((swift_name("init(version:strictMode:validationConfig:extraSegments:)"))) __attribute__((objc_designated_initializer));

/** Validates [message] and returns the encoded ACK^R01. */
- (NSString *)ackMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("ack(message:)")));
- (Hl7CoreHL7Builder *)build __attribute__((swift_name("build()")));
- (Hl7CoreHL7ParseResult *)parseRaw:(NSString *)raw __attribute__((swift_name("parse(raw:)")));
- (Hl7CoreHL7ParseResult *)parseMllpBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("parseMllp(bytes:)")));
- (Hl7CoreValidationResult *)validateMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("validate(message:)")));
@end


/**
 * Message-scope DSLs. Each scope exposes only the segment blocks valid for its
 * message type; repeating segments append to the ordered builder list. The MSH
 * block is always available and its message type is set automatically by the
 * owning [HL7Builder] method.
 *
 * Usage (from the owning builder method):
 * ```
 * builder.rdsO13 {
 *     msh { it.sendingApplication = "..." }
 *     orc { it.orderControl = "RE" }
 *     rxd { it.dispenseGiveCode = "..." }
 *     zsn { it.setId = "1" }   // repeating
 * }
 * ```
 */
__attribute__((swift_name("MessageScope")))
@interface Hl7CoreMessageScope : Hl7CoreBase

/**
 * Message-scope DSLs. Each scope exposes only the segment blocks valid for its
 * message type; repeating segments append to the ordered builder list. The MSH
 * block is always available and its message type is set automatically by the
 * owning [HL7Builder] method.
 *
 * Usage (from the owning builder method):
 * ```
 * builder.rdsO13 {
 *     msh { it.sendingApplication = "..." }
 *     orc { it.orderControl = "RE" }
 *     rxd { it.dispenseGiveCode = "..." }
 *     zsn { it.setId = "1" }   // repeating
 * }
 * ```
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Message-scope DSLs. Each scope exposes only the segment blocks valid for its
 * message type; repeating segments append to the ordered builder list. The MSH
 * block is always available and its message type is set automatically by the
 * owning [HL7Builder] method.
 *
 * Usage (from the owning builder method):
 * ```
 * builder.rdsO13 {
 *     msh { it.sendingApplication = "..." }
 *     orc { it.orderControl = "RE" }
 *     rxd { it.dispenseGiveCode = "..." }
 *     zsn { it.setId = "1" }   // repeating
 * }
 * ```
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (Hl7CoreHL7SegmentBuilder *)addBuilder:(Hl7CoreHL7SegmentBuilder *)builder block:(void (^)(Hl7CoreHL7SegmentBuilder *))block __attribute__((swift_name("add(builder:block:)")));

/** Configure the MSH header. */
- (void)mshBlock:(void (^)(Hl7CoreMSHBuilder *))block __attribute__((swift_name("msh(block:)")));
@end


/** Scope for ACK^R01 acknowledgement. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckScope")))
@interface Hl7CoreAckScope : Hl7CoreMessageScope

/** Scope for ACK^R01 acknowledgement. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for ACK^R01 acknowledgement. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreERRBuilder *)errBlock:(void (^)(Hl7CoreERRBuilder *))block __attribute__((swift_name("err(block:)")));
- (Hl7CoreMSABuilder *)msaBlock:(void (^)(Hl7CoreMSABuilder *))block __attribute__((swift_name("msa(block:)")));
@end


/**
 * Base class for typed segment builders. Subclasses expose named `var`
 * properties that write plain [String]s into 1-based (field, component) slots.
 * [build] assembles a generic [HL7Segment], trimming trailing empty fields per
 * the segment's version cap.
 */
__attribute__((swift_name("HL7SegmentBuilder")))
@interface Hl7CoreHL7SegmentBuilder : Hl7CoreBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));

/**
 * Flushes the subclass's named properties into the (field, component) cells.
 * Called automatically by [build]. MSH overrides [build] entirely and does
 * not use this hook.
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));

/** Builds the generic segment for the given delimiters and version. */
- (Hl7CoreHL7Segment *)buildDelimiters:(Hl7CoreHL7Delimiters *)delimiters version:(Hl7CoreHL7Version *)version __attribute__((swift_name("build(delimiters:version:)")));

/** Reads back the plain value of field [n] (component 1), or "".
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)getN:(int32_t)n __attribute__((swift_name("get(n:)")));

/** Reads back component [c] of field [n], or "".
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)getN:(int32_t)n c:(int32_t)c __attribute__((swift_name("get(n:c:)")));

/** Sets the plain value of field [n] (component 1).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)setN:(int32_t)n value:(NSString * _Nullable)value __attribute__((swift_name("set(n:value:)")));

/** Sets component [c] of field [n].
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)setN:(int32_t)n c:(int32_t)c value:(NSString * _Nullable)value __attribute__((swift_name("set(n:c:value:)")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EQUBuilder")))
@interface Hl7CoreEQUBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable equipmentId __attribute__((swift_name("equipmentId")));
@property NSString * _Nullable equipmentState __attribute__((swift_name("equipmentState")));
@property NSString * _Nullable eventDateTime __attribute__((swift_name("eventDateTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ERRBuilder")))
@interface Hl7CoreERRBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable errorCode __attribute__((swift_name("errorCode")));
@property NSString * _Nullable errorText __attribute__((swift_name("errorText")));
@property NSString * _Nullable fieldPosition __attribute__((swift_name("fieldPosition")));
@property NSString * _Nullable segmentId __attribute__((swift_name("segmentId")));
@property NSString * _Nullable severity __attribute__((swift_name("severity")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface Hl7CoreKotlinThrowable : Hl7CoreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (Hl7CoreKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Hl7CoreKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface Hl7CoreKotlinException : Hl7CoreKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Thrown when a message fails build-time validation. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7BuildException")))
@interface Hl7CoreHL7BuildException : Hl7CoreKotlinException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Hl7CoreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * Builds typed HL7 messages. Construct via [builder]; one method per supported
 * message type. Each method auto-sets MSH-9 (message type) and the version,
 * assembles the scope's segments, and returns an [HL7Message] you can
 * [HL7Message.encode].
 *
 * ```
 * val builder = HL7Builder.builder()
 *     .defaultVersion("2.5")
 *     .registerCustomSegment(ZSNSegment.Definition)
 *     .build()
 *
 * val raw = builder.rdsO13 {
 *     msh { it.sendingApplication = "PillCounter"; it.messageControlId = "1782200001" }
 *     rxd { it.dispenseGiveCode = "00093-0058-01"; it.actualDispenseAmount = "90" }
 *     zsn { it.setId = "1"; it.packageSerialNumber = "21N4F9XK0042" }
 * }.encode()
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Builder")))
@interface Hl7CoreHL7Builder : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreHL7BuilderCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreHL7Message *)ackBlock:(void (^)(Hl7CoreAckScope *))block __attribute__((swift_name("ack(block:)")));
- (Hl7CoreHL7Message *)inrU05Block:(void (^)(Hl7CoreInrU05Scope *))block __attribute__((swift_name("inrU05(block:)")));
- (Hl7CoreHL7Message *)inrU06Block:(void (^)(Hl7CoreInrU06Scope *))block __attribute__((swift_name("inrU06(block:)")));
- (Hl7CoreHL7Message *)inuU05Block:(void (^)(Hl7CoreInuU05Scope *))block __attribute__((swift_name("inuU05(block:)")));
- (Hl7CoreHL7Message *)qbpQ11Block:(void (^)(Hl7CoreQbpQ11Scope *))block __attribute__((swift_name("qbpQ11(block:)")));
- (Hl7CoreHL7Message *)rdeO11Block:(void (^)(Hl7CoreRdeO11Scope *))block __attribute__((swift_name("rdeO11(block:)")));
- (Hl7CoreHL7Message *)rdsO13Block:(void (^)(Hl7CoreRdsO13Scope *))block __attribute__((swift_name("rdsO13(block:)")));
@end


/** Fluent builder for [HL7Builder]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Builder.Builder")))
@interface Hl7CoreHL7BuilderBuilder : Hl7CoreBase

/** Fluent builder for [HL7Builder]. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Fluent builder for [HL7Builder]. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreHL7Builder *)build __attribute__((swift_name("build()")));
- (Hl7CoreHL7BuilderBuilder *)defaultVersionVersion:(NSString *)version __attribute__((swift_name("defaultVersion(version:)")));
- (Hl7CoreHL7BuilderBuilder *)defaultVersionVersion_:(Hl7CoreHL7Version *)version __attribute__((swift_name("defaultVersion(version_:)")));
- (Hl7CoreHL7BuilderBuilder *)delimitersD:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("delimiters(d:)")));
- (Hl7CoreHL7BuilderBuilder *)fillTimestampsEnabled:(BOOL)enabled __attribute__((swift_name("fillTimestamps(enabled:)")));
- (Hl7CoreHL7BuilderBuilder *)registerCustomSegmentDefinition:(Hl7CoreSegmentDefinition *)definition __attribute__((swift_name("registerCustomSegment(definition:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Builder.Companion")))
@interface Hl7CoreHL7BuilderCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7BuilderCompanion *shared __attribute__((swift_name("shared")));

/** Entry point: `HL7Builder.builder()...build()`. */
- (Hl7CoreHL7BuilderBuilder *)builder __attribute__((swift_name("builder()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVBuilder")))
@interface Hl7CoreINVBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable inventoryLocationIdentifier __attribute__((swift_name("inventoryLocationIdentifier")));
@property NSString * _Nullable inventoryOnHandQuantity __attribute__((swift_name("inventoryOnHandQuantity")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable substanceCodeSystem __attribute__((swift_name("substanceCodeSystem")));
@property NSString * _Nullable substanceName __attribute__((swift_name("substanceName")));
@property NSString * _Nullable units __attribute__((swift_name("units")));
@end


/** Scope for INR^U05 inventory count response (INV + ZIN rows). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InrU05Scope")))
@interface Hl7CoreInrU05Scope : Hl7CoreMessageScope

/** Scope for INR^U05 inventory count response (INV + ZIN rows). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for INR^U05 inventory count response (INV + ZIN rows). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreEQUBuilder *)equBlock:(void (^)(Hl7CoreEQUBuilder *))block __attribute__((swift_name("equ(block:)")));
- (Hl7CoreINVBuilder *)invBlock:(void (^)(Hl7CoreINVBuilder *))block __attribute__((swift_name("inv(block:)")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CoreZINBuilder *)zinBlock:(void (^)(Hl7CoreZINBuilder *))block __attribute__((swift_name("zin(block:)")));
@end


/** Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InrU06Scope")))
@interface Hl7CoreInrU06Scope : Hl7CoreMessageScope

/** Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreEQUBuilder *)equBlock:(void (^)(Hl7CoreEQUBuilder *))block __attribute__((swift_name("equ(block:)")));
- (Hl7CoreINVBuilder *)invBlock:(void (^)(Hl7CoreINVBuilder *))block __attribute__((swift_name("inv(block:)")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CoreZADBuilder *)zadBlock:(void (^)(Hl7CoreZADBuilder *))block __attribute__((swift_name("zad(block:)")));
@end


/** Scope for INU^U05 unsolicited inventory update. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InuU05Scope")))
@interface Hl7CoreInuU05Scope : Hl7CoreMessageScope

/** Scope for INU^U05 unsolicited inventory update. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for INU^U05 unsolicited inventory update. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreEQUBuilder *)equBlock:(void (^)(Hl7CoreEQUBuilder *))block __attribute__((swift_name("equ(block:)")));
- (Hl7CoreINVBuilder *)invBlock:(void (^)(Hl7CoreINVBuilder *))block __attribute__((swift_name("inv(block:)")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreZINBuilder *)zinBlock:(void (^)(Hl7CoreZINBuilder *))block __attribute__((swift_name("zin(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSABuilder")))
@interface Hl7CoreMSABuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable acknowledgmentCode __attribute__((swift_name("acknowledgmentCode")));
@property NSString * _Nullable messageControlId __attribute__((swift_name("messageControlId")));
@property NSString * _Nullable textMessage __attribute__((swift_name("textMessage")));
@end


/**
 * MSH builder. MSH is special: field 1 is the field separator and field 2 is the
 * encoding characters, which are emitted literally by [HL7Segment.encode]. We
 * store MSH-2 as fields[0] (matching the parse layout) and MSH-3.. thereafter.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSHBuilder")))
@interface Hl7CoreMSHBuilder : Hl7CoreHL7SegmentBuilder

/**
 * MSH builder. MSH is special: field 1 is the field separator and field 2 is the
 * encoding characters, which are emitted literally by [HL7Segment.encode]. We
 * store MSH-2 as fields[0] (matching the parse layout) and MSH-3.. thereafter.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * MSH builder. MSH is special: field 1 is the field separator and field 2 is the
 * encoding characters, which are emitted literally by [HL7Segment.encode]. We
 * store MSH-2 as fields[0] (matching the parse layout) and MSH-3.. thereafter.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/** Builds the MSH segment directly (handles the MSH-1/MSH-2 quirk). */
- (Hl7CoreHL7Segment *)buildDelimiters:(Hl7CoreHL7Delimiters *)delimiters version:(Hl7CoreHL7Version *)version __attribute__((swift_name("build(delimiters:version:)")));
@property NSString * _Nullable countryCode __attribute__((swift_name("countryCode")));
@property NSString * _Nullable dateTimeOfMessage __attribute__((swift_name("dateTimeOfMessage")));
@property NSString * _Nullable messageControlId __attribute__((swift_name("messageControlId")));
@property NSString * _Nullable processingId __attribute__((swift_name("processingId")));
@property NSString * _Nullable receivingApplication __attribute__((swift_name("receivingApplication")));
@property NSString * _Nullable receivingFacility __attribute__((swift_name("receivingFacility")));
@property NSString * _Nullable sendingApplication __attribute__((swift_name("sendingApplication")));
@property NSString * _Nullable sendingFacility __attribute__((swift_name("sendingFacility")));
@property NSString * _Nullable versionId __attribute__((swift_name("versionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NTEBuilder")))
@interface Hl7CoreNTEBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable comment __attribute__((swift_name("comment")));
@property NSString * _Nullable commentType __attribute__((swift_name("commentType")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable sourceOfComment __attribute__((swift_name("sourceOfComment")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OBXBuilder")))
@interface Hl7CoreOBXBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable observationId __attribute__((swift_name("observationId")));
@property NSString * _Nullable observationValue __attribute__((swift_name("observationValue")));
@property NSString * _Nullable resultStatus __attribute__((swift_name("resultStatus")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable units __attribute__((swift_name("units")));
@property NSString * _Nullable valueType __attribute__((swift_name("valueType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ORCBuilder")))
@interface Hl7CoreORCBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dateTimeOfTransaction __attribute__((swift_name("dateTimeOfTransaction")));
@property NSString * _Nullable fillerOrderNumber __attribute__((swift_name("fillerOrderNumber")));
@property NSString * _Nullable orderControl __attribute__((swift_name("orderControl")));
@property NSString * _Nullable orderStatus __attribute__((swift_name("orderStatus")));
@property NSString * _Nullable orderingProviderId __attribute__((swift_name("orderingProviderId")));
@property NSString * _Nullable placerOrderNumber __attribute__((swift_name("placerOrderNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PIDBuilder")))
@interface Hl7CorePIDBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dateOfBirth __attribute__((swift_name("dateOfBirth")));
@property NSString * _Nullable familyName __attribute__((swift_name("familyName")));
@property NSString * _Nullable givenName __attribute__((swift_name("givenName")));
@property NSString * _Nullable patientId __attribute__((swift_name("patientId")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable sex __attribute__((swift_name("sex")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PV1Builder")))
@interface Hl7CorePV1Builder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable patientClass __attribute__((swift_name("patientClass")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable visitNumber __attribute__((swift_name("visitNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QAKBuilder")))
@interface Hl7CoreQAKBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable messageQueryName __attribute__((swift_name("messageQueryName")));
@property NSString * _Nullable queryResponseStatus __attribute__((swift_name("queryResponseStatus")));
@property NSString * _Nullable queryTag __attribute__((swift_name("queryTag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QPDBuilder")))
@interface Hl7CoreQPDBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable drugName __attribute__((swift_name("drugName")));
@property NSString * _Nullable equipmentId __attribute__((swift_name("equipmentId")));
@property NSString * _Nullable messageQueryName __attribute__((swift_name("messageQueryName")));
@property NSString * _Nullable ndc __attribute__((swift_name("ndc")));
@property NSString * _Nullable queryTag __attribute__((swift_name("queryTag")));
@end


/** Scope for QBP^Q11 pre-count / stock-on-hand query (§12). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QbpQ11Scope")))
@interface Hl7CoreQbpQ11Scope : Hl7CoreMessageScope

/** Scope for QBP^Q11 pre-count / stock-on-hand query (§12). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for QBP^Q11 pre-count / stock-on-hand query (§12). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreQPDBuilder *)qpdBlock:(void (^)(Hl7CoreQPDBuilder *))block __attribute__((swift_name("qpd(block:)")));
- (Hl7CoreRCPBuilder *)rcpBlock:(void (^)(Hl7CoreRCPBuilder *))block __attribute__((swift_name("rcp(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RCPBuilder")))
@interface Hl7CoreRCPBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable quantityLimitedRequest __attribute__((swift_name("quantityLimitedRequest")));
@property NSString * _Nullable queryPriority __attribute__((swift_name("queryPriority")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXCBuilder")))
@interface Hl7CoreRXCBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable componentAmount __attribute__((swift_name("componentAmount")));
@property NSString * _Nullable componentCode __attribute__((swift_name("componentCode")));
@property NSString * _Nullable componentType __attribute__((swift_name("componentType")));
@property NSString * _Nullable componentUnits __attribute__((swift_name("componentUnits")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXDBuilder")))
@interface Hl7CoreRXDBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable actualDispenseAmount __attribute__((swift_name("actualDispenseAmount")));
@property NSString * _Nullable actualDispenseUnits __attribute__((swift_name("actualDispenseUnits")));
@property NSString * _Nullable dateTimeDispensed __attribute__((swift_name("dateTimeDispensed")));
@property NSString * _Nullable dispenseGiveCode __attribute__((swift_name("dispenseGiveCode")));
@property NSString * _Nullable dispenseGiveCodeSystem __attribute__((swift_name("dispenseGiveCodeSystem")));
@property NSString * _Nullable dispenseGiveName __attribute__((swift_name("dispenseGiveName")));
@property NSString * _Nullable dispenseSubIdCounter __attribute__((swift_name("dispenseSubIdCounter")));
@property NSString * _Nullable dispensingProviderId __attribute__((swift_name("dispensingProviderId")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXEBuilder")))
@interface Hl7CoreRXEBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dispenseAmount __attribute__((swift_name("dispenseAmount")));
@property NSString * _Nullable giveAmountMinimum __attribute__((swift_name("giveAmountMinimum")));
@property NSString * _Nullable giveCode __attribute__((swift_name("giveCode")));
@property NSString * _Nullable giveCodeSystem __attribute__((swift_name("giveCodeSystem")));
@property NSString * _Nullable giveName __attribute__((swift_name("giveName")));
@property NSString * _Nullable giveUnits __attribute__((swift_name("giveUnits")));
@property NSString * _Nullable prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXRBuilder")))
@interface Hl7CoreRXRBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable administrationSiteCode __attribute__((swift_name("administrationSiteCode")));
@property NSString * _Nullable routeCode __attribute__((swift_name("routeCode")));
@property NSString * _Nullable routeText __attribute__((swift_name("routeText")));
@end


/** Scope for RDE^O11 dispense order. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RdeO11Scope")))
@interface Hl7CoreRdeO11Scope : Hl7CoreMessageScope

/** Scope for RDE^O11 dispense order. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for RDE^O11 dispense order. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CorePIDBuilder *)pidBlock:(void (^)(Hl7CorePIDBuilder *))block __attribute__((swift_name("pid(block:)")));
- (Hl7CorePV1Builder *)pv1Block:(void (^)(Hl7CorePV1Builder *))block __attribute__((swift_name("pv1(block:)")));
- (Hl7CoreRXCBuilder *)rxcBlock:(void (^)(Hl7CoreRXCBuilder *))block __attribute__((swift_name("rxc(block:)")));
- (Hl7CoreRXEBuilder *)rxeBlock:(void (^)(Hl7CoreRXEBuilder *))block __attribute__((swift_name("rxe(block:)")));
- (Hl7CoreRXRBuilder *)rxrBlock:(void (^)(Hl7CoreRXRBuilder *))block __attribute__((swift_name("rxr(block:)")));
@end


/** Scope for RDS^O13 dispense response (+ optional ZSN/ZSV from §10/§13). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RdsO13Scope")))
@interface Hl7CoreRdsO13Scope : Hl7CoreMessageScope

/** Scope for RDS^O13 dispense response (+ optional ZSN/ZSV from §10/§13). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Scope for RDS^O13 dispense response (+ optional ZSN/ZSV from §10/§13). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CorePIDBuilder *)pidBlock:(void (^)(Hl7CorePIDBuilder *))block __attribute__((swift_name("pid(block:)")));
- (Hl7CoreRXCBuilder *)rxcBlock:(void (^)(Hl7CoreRXCBuilder *))block __attribute__((swift_name("rxc(block:)")));
- (Hl7CoreRXDBuilder *)rxdBlock:(void (^)(Hl7CoreRXDBuilder *))block __attribute__((swift_name("rxd(block:)")));
- (Hl7CoreRXEBuilder *)rxeBlock:(void (^)(Hl7CoreRXEBuilder *))block __attribute__((swift_name("rxe(block:)")));
- (Hl7CoreRXRBuilder *)rxrBlock:(void (^)(Hl7CoreRXRBuilder *))block __attribute__((swift_name("rxr(block:)")));
- (Hl7CoreZSNBuilder *)zsnBlock:(void (^)(Hl7CoreZSNBuilder *))block __attribute__((swift_name("zsn(block:)")));
- (Hl7CoreZSVBuilder *)zsvBlock:(void (^)(Hl7CoreZSVBuilder *))block __attribute__((swift_name("zsv(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZADBuilder")))
@interface Hl7CoreZADBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable adjustmentDateTime __attribute__((swift_name("adjustmentDateTime")));
@property NSString * _Nullable adjustmentQuantity __attribute__((swift_name("adjustmentQuantity")));
@property NSString * _Nullable adjustmentReason __attribute__((swift_name("adjustmentReason")));
@property NSString * _Nullable adjustmentType __attribute__((swift_name("adjustmentType")));
@property NSString * _Nullable approvedBy __attribute__((swift_name("approvedBy")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@end


/** ZIN builder (existing inventory-count row). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZINBuilder")))
@interface Hl7CoreZINBuilder : Hl7CoreHL7SegmentBuilder

/** ZIN builder (existing inventory-count row). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** ZIN builder (existing inventory-count row). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dispenseType __attribute__((swift_name("dispenseType")));
@property NSString * _Nullable expiry __attribute__((swift_name("expiry")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable quantity __attribute__((swift_name("quantity")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSNBuilder")))
@interface Hl7CoreZSNBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable nationalDrugCode __attribute__((swift_name("nationalDrugCode")));
@property NSString * _Nullable packageSerialNumber __attribute__((swift_name("packageSerialNumber")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable transactionType __attribute__((swift_name("transactionType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSVBuilder")))
@interface Hl7CoreZSVBuilder : Hl7CoreHL7SegmentBuilder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable rejectionReason __attribute__((swift_name("rejectionReason")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable validationStatus __attribute__((swift_name("validationStatus")));
@property NSString * _Nullable validationTimestamp __attribute__((swift_name("validationTimestamp")));
@property NSString * _Nullable validatorId __attribute__((swift_name("validatorId")));
@end


/**
 * The five HL7 v2.x encoding characters.
 *
 * The field separator is taken from the 4th character of the MSH segment
 * (the character immediately after "MSH"). The remaining four are read from
 * MSH-2 ("encoding characters"), in order: component, repetition, escape,
 * subcomponent.
 *
 * Per the HL7 spec, delimiters must always be read from the message itself —
 * never assumed — because a sender may use non-standard characters.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Delimiters")))
@interface Hl7CoreHL7Delimiters : Hl7CoreBase
- (instancetype)initWithField:(unichar)field component:(unichar)component repetition:(unichar)repetition escape:(unichar)escape subcomponent:(unichar)subcomponent __attribute__((swift_name("init(field:component:repetition:escape:subcomponent:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreHL7DelimitersCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreHL7Delimiters *)doCopyField:(unichar)field component:(unichar)component repetition:(unichar)repetition escape:(unichar)escape subcomponent:(unichar)subcomponent __attribute__((swift_name("doCopy(field:component:repetition:escape:subcomponent:)")));

/**
 * The five HL7 v2.x encoding characters.
 *
 * The field separator is taken from the 4th character of the MSH segment
 * (the character immediately after "MSH"). The remaining four are read from
 * MSH-2 ("encoding characters"), in order: component, repetition, escape,
 * subcomponent.
 *
 * Per the HL7 spec, delimiters must always be read from the message itself —
 * never assumed — because a sender may use non-standard characters.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The five HL7 v2.x encoding characters.
 *
 * The field separator is taken from the 4th character of the MSH segment
 * (the character immediately after "MSH"). The remaining four are read from
 * MSH-2 ("encoding characters"), in order: component, repetition, escape,
 * subcomponent.
 *
 * Per the HL7 spec, delimiters must always be read from the message itself —
 * never assumed — because a sender may use non-standard characters.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * The five HL7 v2.x encoding characters.
 *
 * The field separator is taken from the 4th character of the MSH segment
 * (the character immediately after "MSH"). The remaining four are read from
 * MSH-2 ("encoding characters"), in order: component, repetition, escape,
 * subcomponent.
 *
 * Per the HL7 spec, delimiters must always be read from the message itself —
 * never assumed — because a sender may use non-standard characters.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) unichar component __attribute__((swift_name("component")));

/** The MSH-2 string ("^~\&" by default) — the four encoding chars in order. */
@property (readonly) NSString *encodingCharacters __attribute__((swift_name("encodingCharacters")));
@property (readonly) unichar escape __attribute__((swift_name("escape")));
@property (readonly) unichar field __attribute__((swift_name("field")));
@property (readonly) unichar repetition __attribute__((swift_name("repetition")));
@property (readonly) unichar subcomponent __attribute__((swift_name("subcomponent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Delimiters.Companion")))
@interface Hl7CoreHL7DelimitersCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7DelimitersCompanion *shared __attribute__((swift_name("shared")));

/**
 * Derives delimiters from a raw MSH segment line.
 *
 * Layout: `MSH` + <field-sep> + <encoding-chars> + <field-sep> + ...
 * e.g. `MSH|^~\&|...` → field='|', component='^', repetition='~',
 * escape='\', subcomponent='&'.
 *
 * Falls back to [DEFAULT] for any character that cannot be read, so a
 * truncated header still yields a usable delimiter set.
 */
- (Hl7CoreHL7Delimiters *)fromMshLineMshLine:(NSString *)mshLine __attribute__((swift_name("fromMshLine(mshLine:)")));

/** Standard HL7 delimiters: `|^~\&`. */
@property (readonly) Hl7CoreHL7Delimiters *DEFAULT __attribute__((swift_name("DEFAULT")));
@end


/**
 * Escapes and unescapes HL7 v2.x text using the message's [HL7Delimiters].
 *
 * Canonical escape table (single source of truth — fixes the swapped ~/&
 * mapping that existed in the old builder):
 *
 * | character        | escape |
 * |------------------|--------|
 * | escape   (`\`)   | `\E\`  |
 * | field    (`\|`)  | `\F\`  |
 * | component(`^`)   | `\S\`  |
 * | subcomp  (`&`)   | `\T\`  |
 * | repetition(`~`)  | `\R\`  |
 *
 * On decode we additionally handle `\Xhh..\` (hex bytes → UTF-8) and pass any
 * unrecognized `\...\` sequence through verbatim so non-delimiter escapes
 * (e.g. formatting `\.br\` or custom `\Zxx\`) survive a round trip.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Escaping")))
@interface Hl7CoreHL7Escaping : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Escapes and unescapes HL7 v2.x text using the message's [HL7Delimiters].
 *
 * Canonical escape table (single source of truth — fixes the swapped ~/&
 * mapping that existed in the old builder):
 *
 * | character        | escape |
 * |------------------|--------|
 * | escape   (`\`)   | `\E\`  |
 * | field    (`\|`)  | `\F\`  |
 * | component(`^`)   | `\S\`  |
 * | subcomp  (`&`)   | `\T\`  |
 * | repetition(`~`)  | `\R\`  |
 *
 * On decode we additionally handle `\Xhh..\` (hex bytes → UTF-8) and pass any
 * unrecognized `\...\` sequence through verbatim so non-delimiter escapes
 * (e.g. formatting `\.br\` or custom `\Zxx\`) survive a round trip.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hL7Escaping __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7Escaping *shared __attribute__((swift_name("shared")));

/**
 * Escapes a raw application string for the wire. The escape character is
 * replaced first so that escapes introduced for the other delimiters are
 * not double-escaped.
 */
- (NSString *)escapeRaw:(NSString *)raw d:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("escape(raw:d:)")));

/**
 * Decodes wire text to a raw string. Resolves the five delimiter escapes,
 * `\Xhh..\` hex sequences, and leaves unknown escapes intact.
 */
- (NSString *)unescapeWire:(NSString *)wire d:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("unescape(wire:d:)")));
@end


/**
 * MLLP (Minimal Lower Layer Protocol) framing used to transport HL7 over TCP.
 * Each frame is: <VT 0x0B> message <FS 0x1C><CR 0x0D>.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Mllp")))
@interface Hl7CoreMllp : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * MLLP (Minimal Lower Layer Protocol) framing used to transport HL7 over TCP.
 * Each frame is: <VT 0x0B> message <FS 0x1C><CR 0x0D>.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mllp __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreMllp *shared __attribute__((swift_name("shared")));

/** Strips MLLP framing bytes and returns the raw HL7 message text. */
- (NSString *)stripBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("strip(bytes:)")));

/** Wraps a raw HL7 string in MLLP framing bytes. */
- (Hl7CoreKotlinByteArray *)wrapHl7:(NSString *)hl7 __attribute__((swift_name("wrap(hl7:)")));
@end


/**
 * A parsed HL7 message: an ordered list of typed segments plus the delimiters
 * and version they were parsed with. Segment order is preserved exactly as
 * received, so the message re-serializes losslessly.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Message")))
@interface Hl7CoreHL7Message : Hl7CoreBase

/** Re-serializes the message to wire text (segments joined by CR). */
- (NSString *)encode __attribute__((swift_name("encode()")));

/** Re-serializes and wraps in MLLP framing for TCP transport. */
- (Hl7CoreKotlinByteArray *)encodeMllp __attribute__((swift_name("encodeMllp()")));

/**
 * First segment of type [T] with the given [name], or null.
 * Kotlin: `message.segment<RXDSegment>("RXD")`.
 */
- (Hl7CoreTypedSegment * _Nullable)segmentName:(NSString *)name __attribute__((swift_name("segment(name:)")));

/** First typed segment with the given name, or null. */
- (Hl7CoreTypedSegment * _Nullable)segmentNamedName:(NSString *)name __attribute__((swift_name("segmentNamed(name:)")));

/** All segments of type [T] with the given [name]. */
- (NSArray<Hl7CoreTypedSegment *> *)segmentsName:(NSString *)name __attribute__((swift_name("segments(name:)")));

/** All typed segments with the given name, in order. */
- (NSArray<Hl7CoreTypedSegment *> *)segmentsNamedName:(NSString *)name __attribute__((swift_name("segmentsNamed(name:)")));
@property (readonly) Hl7CoreHL7Delimiters *delimiters __attribute__((swift_name("delimiters")));

/** The MSH header (always first), or null if somehow absent. */
@property (readonly) Hl7CoreMSHSegment * _Nullable header __attribute__((swift_name("header")));

/** Business classification (DISPENSE, INVENTORY_ADJUSTMENT, QUERY, …). */
@property (readonly) Hl7CoreHL7MessageKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *messageCode __attribute__((swift_name("messageCode")));
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));
@property (readonly) NSString *messageType __attribute__((swift_name("messageType")));

/** The underlying generic AST segments (lossless). */
@property (readonly) NSArray<Hl7CoreHL7Segment *> *rawSegments __attribute__((swift_name("rawSegments")));
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));
@property (readonly) NSString *triggerEvent __attribute__((swift_name("triggerEvent")));
@property (readonly) NSArray<Hl7CoreTypedSegment *> *typedSegments __attribute__((swift_name("typedSegments")));
@property (readonly) Hl7CoreHL7Version *version __attribute__((swift_name("version")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol Hl7CoreKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface Hl7CoreKotlinEnum<E> : Hl7CoreBase <Hl7CoreKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end


/**
 * Business classification of a parsed message, derived from message type,
 * trigger event, ORC-1, and payload.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7MessageKind")))
@interface Hl7CoreHL7MessageKind : Hl7CoreKotlinEnum<Hl7CoreHL7MessageKind *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Business classification of a parsed message, derived from message type,
 * trigger event, ORC-1, and payload.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Hl7CoreHL7MessageKindCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Hl7CoreHL7MessageKind *dispense __attribute__((swift_name("dispense")));
@property (class, readonly) Hl7CoreHL7MessageKind *dispenseOrder __attribute__((swift_name("dispenseOrder")));
@property (class, readonly) Hl7CoreHL7MessageKind *cancelOrder __attribute__((swift_name("cancelOrder")));
@property (class, readonly) Hl7CoreHL7MessageKind *inventoryResponse __attribute__((swift_name("inventoryResponse")));
@property (class, readonly) Hl7CoreHL7MessageKind *inventoryAdjustment __attribute__((swift_name("inventoryAdjustment")));
@property (class, readonly) Hl7CoreHL7MessageKind *inventoryRequest __attribute__((swift_name("inventoryRequest")));
@property (class, readonly) Hl7CoreHL7MessageKind *inventoryUpdate __attribute__((swift_name("inventoryUpdate")));
@property (class, readonly) Hl7CoreHL7MessageKind *query __attribute__((swift_name("query")));
@property (class, readonly) Hl7CoreHL7MessageKind *queryResponse __attribute__((swift_name("queryResponse")));
@property (class, readonly) Hl7CoreHL7MessageKind *acknowledgment __attribute__((swift_name("acknowledgment")));
@property (class, readonly) Hl7CoreHL7MessageKind *unknown __attribute__((swift_name("unknown")));
+ (Hl7CoreKotlinArray<Hl7CoreHL7MessageKind *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Hl7CoreHL7MessageKind *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7MessageKind.Companion")))
@interface Hl7CoreHL7MessageKindCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7MessageKindCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreHL7MessageKind *)fromMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("from(message:)")));
@end


/**
 * Describes a custom (typically Z-) segment so the parser and builder can treat
 * it as a first-class typed segment without any core changes.
 *
 * A definition pairs the 3-char segment [name] with a [factory] that wraps a
 * generic [HL7Segment] into its typed view. Register on the parser/builder via
 * `registerCustomSegment(...)`.
 *
 * The built-in Z-segments (ZSN, ZSV, ZAD, ZIN, ZPR) ship as ready-made
 * definitions (see their companion objects, e.g. [org.rite.hl7.model.segment.ZSNSegment.Definition]).
 */
__attribute__((swift_name("SegmentDefinition")))
@interface Hl7CoreSegmentDefinition : Hl7CoreBase
- (instancetype)initWithName:(NSString *)name factory:(Hl7CoreTypedSegment *(^)(Hl7CoreHL7Segment *))factory __attribute__((swift_name("init(name:factory:)"))) __attribute__((objc_designated_initializer));
@property (readonly) Hl7CoreTypedSegment *(^factory)(Hl7CoreHL7Segment *) __attribute__((swift_name("factory")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * Maps segment names to typed-view factories. Ships with all standard segments
 * pre-registered; custom (Z-)segments are added via [register]. Unknown segments
 * fall back to [GenericSegment] (lossless).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentRegistry")))
@interface Hl7CoreSegmentRegistry : Hl7CoreBase

/**
 * Maps segment names to typed-view factories. Ships with all standard segments
 * pre-registered; custom (Z-)segments are added via [register]. Unknown segments
 * fall back to [GenericSegment] (lossless).
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Maps segment names to typed-view factories. Ships with all standard segments
 * pre-registered; custom (Z-)segments are added via [register]. Unknown segments
 * fall back to [GenericSegment] (lossless).
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)isRegisteredName:(NSString *)name __attribute__((swift_name("isRegistered(name:)")));

/** Registers (or overrides) a custom segment definition. */
- (void)registerDefinition:(Hl7CoreSegmentDefinition *)definition __attribute__((swift_name("register(definition:)")));

/** Wraps a generic segment into its typed view, or [GenericSegment] if unregistered. */
- (Hl7CoreTypedSegment *)wrapRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("wrap(raw:)")));
@end


/**
 * Base class for all typed segment views. A typed segment is a thin wrapper over
 * a generic [HL7Segment]; its properties are computed getters over fixed 1-based
 * field indices. Every value is a plain [String] — date/enum conversion belongs
 * in the service layer, not here.
 *
 * Subclasses expose named getters like:
 * ```
 * val lotNumber: String get() = fieldValue(15)
 * ```
 */
__attribute__((swift_name("TypedSegment")))
@interface Hl7CoreTypedSegment : Hl7CoreBase
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));

/** Plain value of component [c] (1-based) within field [n] (1-based).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)componentN:(int32_t)n c:(int32_t)c __attribute__((swift_name("component(n:c:)")));

/** Raw [HL7Component] for advanced access.
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (Hl7CoreHL7Component *)componentOfN:(int32_t)n c:(int32_t)c __attribute__((swift_name("componentOf(n:c:)")));

/** Plain value of field [n] (1-based).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)fieldValueN:(int32_t)n __attribute__((swift_name("fieldValue(n:)")));

/** Plain value of subcomponent [s] within component [c] of field [n] (all 1-based).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)subcomponentN:(int32_t)n c:(int32_t)c s:(int32_t)s __attribute__((swift_name("subcomponent(n:c:s:)")));
@property (readonly) Hl7CoreHL7Segment *raw __attribute__((swift_name("raw")));

/** Segment name (e.g. "MSH", "RXD"). */
@property (readonly) NSString *segmentName __attribute__((swift_name("segmentName")));
@end


/**
 * One component of an HL7 field. A component is a list of subcomponents
 * (separated by `&` on the wire). Stored values are already unescaped.
 *
 * All accessors are 1-based to match HL7 spec numbering.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Component")))
@interface Hl7CoreHL7Component : Hl7CoreBase
- (instancetype)initWithSubcomponents:(NSArray<NSString *> *)subcomponents __attribute__((swift_name("init(subcomponents:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreHL7ComponentCompanion *companion __attribute__((swift_name("companion")));

/** Serializes this component back to wire text (escaping each subcomponent). */
- (NSString *)encodeD:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("encode(d:)")));

/** Value of subcomponent [n] (1-based), or empty string if absent. */
- (NSString *)subcomponentN:(int32_t)n __attribute__((swift_name("subcomponent(n:)")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<NSString *> *subcomponents __attribute__((swift_name("subcomponents")));

/** First subcomponent — the common case when a component is a plain value. */
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Component.Companion")))
@interface Hl7CoreHL7ComponentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7ComponentCompanion *shared __attribute__((swift_name("shared")));

/** Parses one component's wire text into subcomponents (unescaping each). */
- (Hl7CoreHL7Component *)parseRaw:(NSString *)raw d:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("parse(raw:d:)")));
@property (readonly) Hl7CoreHL7Component *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * One field of an HL7 segment. A field may have multiple repetitions
 * (separated by `~` on the wire); each repetition is a list of components.
 *
 * Most callers only ever touch the first repetition; convenience accessors
 * ([component], [value]) operate on it. All indices are 1-based.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Field")))
@interface Hl7CoreHL7Field : Hl7CoreBase
- (instancetype)initWithRepetitions:(NSArray<NSArray<Hl7CoreHL7Component *> *> *)repetitions __attribute__((swift_name("init(repetitions:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreHL7FieldCompanion *companion __attribute__((swift_name("companion")));

/** Component [c] (1-based) of the first repetition, or [HL7Component.EMPTY]. */
- (Hl7CoreHL7Component *)componentC:(int32_t)c __attribute__((swift_name("component(c:)")));

/** Component [c] (1-based) of repetition [r] (1-based). */
- (Hl7CoreHL7Component *)componentR:(int32_t)r c:(int32_t)c __attribute__((swift_name("component(r:c:)")));

/** Serializes this field back to wire text. */
- (NSString *)encodeD:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("encode(d:)")));

/** Repetition [r] (1-based) as a list of components, or empty list if absent. */
- (NSArray<Hl7CoreHL7Component *> *)repetitionR:(int32_t)r __attribute__((swift_name("repetition(r:)")));

/** Components of the first repetition. */
@property (readonly) NSArray<Hl7CoreHL7Component *> *first __attribute__((swift_name("first")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<NSArray<Hl7CoreHL7Component *> *> *repetitions __attribute__((swift_name("repetitions")));

/** First component, first subcomponent of the first repetition — the plainest value. */
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Field.Companion")))
@interface Hl7CoreHL7FieldCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7FieldCompanion *shared __attribute__((swift_name("shared")));

/** A field holding a single plain value (one repetition, one component, one subcomponent). */
- (Hl7CoreHL7Field *)ofValue:(NSString *)value __attribute__((swift_name("of(value:)")));

/** Parses one field's wire text into repetitions → components → subcomponents. */
- (Hl7CoreHL7Field *)parseRaw:(NSString *)raw d:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("parse(raw:d:)")));
@property (readonly) Hl7CoreHL7Field *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * A generic, fully-parsed HL7 segment: a name plus a list of [HL7Field]s.
 * This is the lossless representation every typed segment is projected from.
 *
 * Field access is 1-based to match HL7 numbering. The MSH-1 quirk (where field
 * 1 is the field separator itself and field 2 is the encoding characters) is
 * handled in exactly one place — here — so no other code needs to know about it.
 *
 * @param name        3-char segment name (e.g. "MSH", "RXD", "ZSN")
 * @param fields      parsed fields, indexed from MSH-2 / segment-1 onward
 * @param delimiters  the delimiter set this segment was parsed with (used for re-encode)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Segment")))
@interface Hl7CoreHL7Segment : Hl7CoreBase
- (instancetype)initWithName:(NSString *)name fields:(NSArray<Hl7CoreHL7Field *> *)fields delimiters:(Hl7CoreHL7Delimiters *)delimiters __attribute__((swift_name("init(name:fields:delimiters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreHL7SegmentCompanion *companion __attribute__((swift_name("companion")));

/** Component [c] (1-based) of field [n] (1-based). */
- (Hl7CoreHL7Component *)componentN:(int32_t)n c:(int32_t)c __attribute__((swift_name("component(n:c:)")));

/** Plain value of component [c] of field [n]. */
- (NSString *)componentValueN:(int32_t)n c:(int32_t)c __attribute__((swift_name("componentValue(n:c:)")));

/** Re-serializes this segment to wire text (name + fields joined by the field separator). */
- (NSString *)encodeD:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("encode(d:)")));

/**
 * Returns field [n] (1-based).
 *
 * For MSH, field 1 is the field separator and field 2 is the encoding
 * characters; both are synthesized so callers can read MSH-1..MSH-n
 * uniformly with every other segment.
 */
- (Hl7CoreHL7Field *)fieldN:(int32_t)n __attribute__((swift_name("field(n:)")));

/** Plain value of field [n] (first repetition, first component, first subcomponent). */
- (NSString *)fieldValueN:(int32_t)n __attribute__((swift_name("fieldValue(n:)")));
@property (readonly) Hl7CoreHL7Delimiters *delimiters __attribute__((swift_name("delimiters")));

/** The highest 1-based field index present in this segment. */
@property (readonly) int32_t fieldCount __attribute__((swift_name("fieldCount")));
@property (readonly) NSArray<Hl7CoreHL7Field *> *fields __attribute__((swift_name("fields")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Segment.Companion")))
@interface Hl7CoreHL7SegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7SegmentCompanion *shared __attribute__((swift_name("shared")));

/**
 * Parses a single segment line (already stripped of the terminator)
 * into a generic [HL7Segment]. For MSH, the field separator and encoding
 * characters are consumed so that fields[0] holds MSH-2.
 */
- (Hl7CoreHL7Segment *)parseLine:(NSString *)line d:(Hl7CoreHL7Delimiters *)d __attribute__((swift_name("parse(line:d:)")));
@end


/** EQU — Equipment Detail. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EQUSegment")))
@interface Hl7CoreEQUSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreEQUSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *alertLevel __attribute__((swift_name("alertLevel")));
@property (readonly) NSString *equipmentId __attribute__((swift_name("equipmentId")));
@property (readonly) NSString *equipmentState __attribute__((swift_name("equipmentState")));
@property (readonly) NSString *eventDateTime __attribute__((swift_name("eventDateTime")));
@property (readonly) NSString *localRemoteControlState __attribute__((swift_name("localRemoteControlState")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EQUSegment.Companion")))
@interface Hl7CoreEQUSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEQUSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** ERR — Error. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ERRSegment")))
@interface Hl7CoreERRSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreERRSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *applicationErrorCode __attribute__((swift_name("applicationErrorCode")));
@property (readonly) NSString *applicationErrorText __attribute__((swift_name("applicationErrorText")));
@property (readonly) NSString *diagnosticInformation __attribute__((swift_name("diagnosticInformation")));
@property (readonly) NSString *errorCode __attribute__((swift_name("errorCode")));
@property (readonly) NSString *errorText __attribute__((swift_name("errorText")));
@property (readonly) NSString *fieldPosition __attribute__((swift_name("fieldPosition")));
@property (readonly) NSString *segmentId __attribute__((swift_name("segmentId")));
@property (readonly) NSString *sequence __attribute__((swift_name("sequence")));
@property (readonly) NSString *severity __attribute__((swift_name("severity")));
@property (readonly) NSString *userMessage __attribute__((swift_name("userMessage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ERRSegment.Companion")))
@interface Hl7CoreERRSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreERRSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * Lossless fallback for any segment without a registered typed view (unknown
 * Z-segments, vendor segments). Exposes generic 1-based field access and
 * re-serializes byte-for-byte through the same machinery as typed segments.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenericSegment")))
@interface Hl7CoreGenericSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));

/** Plain value of field [n] (1-based). Public generic accessor. */
- (NSString *)valueN:(int32_t)n __attribute__((swift_name("value(n:)")));

/** Plain value of component [c] within field [n] (1-based). */
- (NSString *)valueN:(int32_t)n c:(int32_t)c __attribute__((swift_name("value(n:c:)")));
@end


/**
 * INV — Inventory Detail.
 *
 * Field map per the project reference / INR^U06 example:
 * `INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVSegment")))
@interface Hl7CoreINVSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreINVSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *inventoryLocationIdentifier __attribute__((swift_name("inventoryLocationIdentifier")));
@property (readonly) NSString *inventoryOnHandQuantity __attribute__((swift_name("inventoryOnHandQuantity")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *substanceCodeSystem __attribute__((swift_name("substanceCodeSystem")));
@property (readonly) NSString *substanceName __attribute__((swift_name("substanceName")));
@property (readonly) NSString *units __attribute__((swift_name("units")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVSegment.Companion")))
@interface Hl7CoreINVSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreINVSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** MSA — Message Acknowledgement. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSASegment")))
@interface Hl7CoreMSASegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreMSASegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *acknowledgmentCode __attribute__((swift_name("acknowledgmentCode")));
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));
@property (readonly) NSString *textMessage __attribute__((swift_name("textMessage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSASegment.Companion")))
@interface Hl7CoreMSASegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreMSASegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** MSH — Message Header. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSHSegment")))
@interface Hl7CoreMSHSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreMSHSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *countryCode __attribute__((swift_name("countryCode")));
@property (readonly) NSString *dateTimeOfMessage __attribute__((swift_name("dateTimeOfMessage")));
@property (readonly) NSString *encodingCharacters __attribute__((swift_name("encodingCharacters")));
@property (readonly) NSString *fieldSeparator __attribute__((swift_name("fieldSeparator")));
@property (readonly) NSString *messageCode __attribute__((swift_name("messageCode")));
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));
@property (readonly) NSString *messageType __attribute__((swift_name("messageType")));
@property (readonly) NSString *processingId __attribute__((swift_name("processingId")));
@property (readonly) NSString *receivingApplication __attribute__((swift_name("receivingApplication")));
@property (readonly) NSString *receivingFacility __attribute__((swift_name("receivingFacility")));
@property (readonly) NSString *security __attribute__((swift_name("security")));
@property (readonly) NSString *sendingApplication __attribute__((swift_name("sendingApplication")));
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));
@property (readonly) NSString *triggerEvent __attribute__((swift_name("triggerEvent")));
@property (readonly) NSString *versionId __attribute__((swift_name("versionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSHSegment.Companion")))
@interface Hl7CoreMSHSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreMSHSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** NTE — Notes and Comments. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NTESegment")))
@interface Hl7CoreNTESegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreNTESegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *comment __attribute__((swift_name("comment")));
@property (readonly) NSString *commentType __attribute__((swift_name("commentType")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *sourceOfComment __attribute__((swift_name("sourceOfComment")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NTESegment.Companion")))
@interface Hl7CoreNTESegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreNTESegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** OBX — Observation/Result. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OBXSegment")))
@interface Hl7CoreOBXSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreOBXSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *abnormalFlags __attribute__((swift_name("abnormalFlags")));
@property (readonly) NSString *dateTimeOfObservation __attribute__((swift_name("dateTimeOfObservation")));
@property (readonly) NSString *observationCodeSystem __attribute__((swift_name("observationCodeSystem")));
@property (readonly) NSString *observationId __attribute__((swift_name("observationId")));
@property (readonly) NSString *observationMethod __attribute__((swift_name("observationMethod")));
@property (readonly) NSString *observationSubId __attribute__((swift_name("observationSubId")));
@property (readonly) NSString *observationText __attribute__((swift_name("observationText")));
@property (readonly) NSString *observationValue __attribute__((swift_name("observationValue")));
@property (readonly) NSString *referenceRange __attribute__((swift_name("referenceRange")));
@property (readonly) NSString *responsibleObserver __attribute__((swift_name("responsibleObserver")));
@property (readonly) NSString *resultStatus __attribute__((swift_name("resultStatus")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *units __attribute__((swift_name("units")));
@property (readonly) NSString *valueType __attribute__((swift_name("valueType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OBXSegment.Companion")))
@interface Hl7CoreOBXSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOBXSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** ORC — Common Order. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ORCSegment")))
@interface Hl7CoreORCSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreORCSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *dateTimeOfTransaction __attribute__((swift_name("dateTimeOfTransaction")));
@property (readonly) NSString *fillerOrderNamespace __attribute__((swift_name("fillerOrderNamespace")));
@property (readonly) NSString *fillerOrderNumber __attribute__((swift_name("fillerOrderNumber")));
@property (readonly) NSString *orderControl __attribute__((swift_name("orderControl")));
@property (readonly) NSString *orderStatus __attribute__((swift_name("orderStatus")));
@property (readonly) NSString *orderingFacility __attribute__((swift_name("orderingFacility")));
@property (readonly) NSString *orderingProviderFamilyName __attribute__((swift_name("orderingProviderFamilyName")));
@property (readonly) NSString *orderingProviderGivenName __attribute__((swift_name("orderingProviderGivenName")));
@property (readonly) NSString *orderingProviderId __attribute__((swift_name("orderingProviderId")));
@property (readonly) NSString *placerOrderNamespace __attribute__((swift_name("placerOrderNamespace")));
@property (readonly) NSString *placerOrderNumber __attribute__((swift_name("placerOrderNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ORCSegment.Companion")))
@interface Hl7CoreORCSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreORCSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** PID — Patient Identification. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PIDSegment")))
@interface Hl7CorePIDSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CorePIDSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *city __attribute__((swift_name("city")));
@property (readonly) NSString *country __attribute__((swift_name("country")));
@property (readonly) NSString *dateOfBirth __attribute__((swift_name("dateOfBirth")));
@property (readonly) NSString *familyName __attribute__((swift_name("familyName")));
@property (readonly) NSString *givenName __attribute__((swift_name("givenName")));
@property (readonly) NSString *middleName __attribute__((swift_name("middleName")));
@property (readonly) NSString *patientId __attribute__((swift_name("patientId")));
@property (readonly) NSString *patientIdAssigningAuthority __attribute__((swift_name("patientIdAssigningAuthority")));
@property (readonly) NSString *patientIdType __attribute__((swift_name("patientIdType")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *sex __attribute__((swift_name("sex")));
@property (readonly) NSString *state __attribute__((swift_name("state")));
@property (readonly) NSString *streetAddress __attribute__((swift_name("streetAddress")));
@property (readonly) NSString *zipCode __attribute__((swift_name("zipCode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PIDSegment.Companion")))
@interface Hl7CorePIDSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePIDSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** PV1 — Patient Visit. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PV1Segment")))
@interface Hl7CorePV1Segment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CorePV1SegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *admitDateTime __attribute__((swift_name("admitDateTime")));
@property (readonly) NSString *attendingDoctorFamilyName __attribute__((swift_name("attendingDoctorFamilyName")));
@property (readonly) NSString *attendingDoctorGivenName __attribute__((swift_name("attendingDoctorGivenName")));
@property (readonly) NSString *attendingDoctorId __attribute__((swift_name("attendingDoctorId")));
@property (readonly) NSString *bed __attribute__((swift_name("bed")));
@property (readonly) NSString *facility __attribute__((swift_name("facility")));
@property (readonly) NSString *patientClass __attribute__((swift_name("patientClass")));
@property (readonly) NSString *pointOfCare __attribute__((swift_name("pointOfCare")));
@property (readonly) NSString *room __attribute__((swift_name("room")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *visitNumber __attribute__((swift_name("visitNumber")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PV1Segment.Companion")))
@interface Hl7CorePV1SegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePV1SegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** QAK — Query Acknowledgement (RSP^K11). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QAKSegment")))
@interface Hl7CoreQAKSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreQAKSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *messageQueryName __attribute__((swift_name("messageQueryName")));
@property (readonly) NSString *queryResponseStatus __attribute__((swift_name("queryResponseStatus")));
@property (readonly) NSString *queryTag __attribute__((swift_name("queryTag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QAKSegment.Companion")))
@interface Hl7CoreQAKSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreQAKSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** QPD — Query Parameter Definition (used by QBP^Q11 / RSP^K11). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QPDSegment")))
@interface Hl7CoreQPDSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreQPDSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *drugName __attribute__((swift_name("drugName")));
@property (readonly) NSString *equipmentId __attribute__((swift_name("equipmentId")));
@property (readonly) NSString *messageQueryName __attribute__((swift_name("messageQueryName")));
@property (readonly) NSString *ndc __attribute__((swift_name("ndc")));
@property (readonly) NSString *queryNameCode __attribute__((swift_name("queryNameCode")));
@property (readonly) NSString *queryTag __attribute__((swift_name("queryTag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("QPDSegment.Companion")))
@interface Hl7CoreQPDSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreQPDSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** RCP — Response Control Parameter (query). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RCPSegment")))
@interface Hl7CoreRCPSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreRCPSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *quantityLimitedRequest __attribute__((swift_name("quantityLimitedRequest")));
@property (readonly) NSString *queryPriority __attribute__((swift_name("queryPriority")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RCPSegment.Companion")))
@interface Hl7CoreRCPSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreRCPSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** RXC — Pharmacy/Treatment Component Order. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXCSegment")))
@interface Hl7CoreRXCSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreRXCSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *componentAmount __attribute__((swift_name("componentAmount")));
@property (readonly) NSString *componentCode __attribute__((swift_name("componentCode")));
@property (readonly) NSString *componentCodeSystem __attribute__((swift_name("componentCodeSystem")));
@property (readonly) NSString *componentName __attribute__((swift_name("componentName")));
@property (readonly) NSString *componentStrength __attribute__((swift_name("componentStrength")));
@property (readonly) NSString *componentStrengthUnits __attribute__((swift_name("componentStrengthUnits")));
@property (readonly) NSString *componentType __attribute__((swift_name("componentType")));
@property (readonly) NSString *componentUnitsCode __attribute__((swift_name("componentUnitsCode")));
@property (readonly) NSString *componentUnitsText __attribute__((swift_name("componentUnitsText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXCSegment.Companion")))
@interface Hl7CoreRXCSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreRXCSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** RXD — Pharmacy/Treatment Dispense. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXDSegment")))
@interface Hl7CoreRXDSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreRXDSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *actualDispenseAmount __attribute__((swift_name("actualDispenseAmount")));
@property (readonly) NSString *actualDispenseUnits __attribute__((swift_name("actualDispenseUnits")));
@property (readonly) NSString *actualDispenseUnitsText __attribute__((swift_name("actualDispenseUnitsText")));
@property (readonly) NSString *actualDosageFormCode __attribute__((swift_name("actualDosageFormCode")));
@property (readonly) NSString *dateTimeDispensed __attribute__((swift_name("dateTimeDispensed")));
@property (readonly) NSString *dispenseGiveCode __attribute__((swift_name("dispenseGiveCode")));
@property (readonly) NSString *dispenseGiveCodeSystem __attribute__((swift_name("dispenseGiveCodeSystem")));
@property (readonly) NSString *dispenseGiveName __attribute__((swift_name("dispenseGiveName")));
@property (readonly) NSString *dispenseSubIdCounter __attribute__((swift_name("dispenseSubIdCounter")));
@property (readonly) NSString *dispensingProviderFamilyName __attribute__((swift_name("dispensingProviderFamilyName")));
@property (readonly) NSString *dispensingProviderGivenName __attribute__((swift_name("dispensingProviderGivenName")));
@property (readonly) NSString *dispensingProviderId __attribute__((swift_name("dispensingProviderId")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property (readonly) NSString *substanceManufacturerName __attribute__((swift_name("substanceManufacturerName")));
@property (readonly) NSString *substitutionStatus __attribute__((swift_name("substitutionStatus")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXDSegment.Companion")))
@interface Hl7CoreRXDSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreRXDSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** RXE — Pharmacy/Treatment Encoded Order. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXESegment")))
@interface Hl7CoreRXESegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreRXESegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *deliverToLocation __attribute__((swift_name("deliverToLocation")));
@property (readonly) NSString *dispenseAmount __attribute__((swift_name("dispenseAmount")));
@property (readonly) NSString *dispenseUnitsCode __attribute__((swift_name("dispenseUnitsCode")));
@property (readonly) NSString *dispenseUnitsText __attribute__((swift_name("dispenseUnitsText")));
@property (readonly) NSString *dosageFormCode __attribute__((swift_name("dosageFormCode")));
@property (readonly) NSString *dosageFormText __attribute__((swift_name("dosageFormText")));
@property (readonly) NSString *giveAmountMaximum __attribute__((swift_name("giveAmountMaximum")));
@property (readonly) NSString *giveAmountMinimum __attribute__((swift_name("giveAmountMinimum")));
@property (readonly) NSString *giveCode __attribute__((swift_name("giveCode")));
@property (readonly) NSString *giveCodeSystem __attribute__((swift_name("giveCodeSystem")));
@property (readonly) NSString *giveName __attribute__((swift_name("giveName")));
@property (readonly) NSString *giveUnitsCode __attribute__((swift_name("giveUnitsCode")));
@property (readonly) NSString *giveUnitsText __attribute__((swift_name("giveUnitsText")));
@property (readonly) NSString *numberOfRefills __attribute__((swift_name("numberOfRefills")));
@property (readonly) NSString *prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property (readonly) NSString *providerAdministrationInstructions __attribute__((swift_name("providerAdministrationInstructions")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXESegment.Companion")))
@interface Hl7CoreRXESegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreRXESegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** RXR — Pharmacy/Treatment Route. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXRSegment")))
@interface Hl7CoreRXRSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreRXRSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *administrationDeviceCode __attribute__((swift_name("administrationDeviceCode")));
@property (readonly) NSString *administrationDeviceText __attribute__((swift_name("administrationDeviceText")));
@property (readonly) NSString *administrationSiteCode __attribute__((swift_name("administrationSiteCode")));
@property (readonly) NSString *administrationSiteText __attribute__((swift_name("administrationSiteText")));
@property (readonly) NSString *routeCode __attribute__((swift_name("routeCode")));
@property (readonly) NSString *routeCodeSystem __attribute__((swift_name("routeCodeSystem")));
@property (readonly) NSString *routeText __attribute__((swift_name("routeText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RXRSegment.Companion")))
@interface Hl7CoreRXRSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreRXRSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZAD — Inventory Adjustment. New §11 extension.
 *
 * Field map (project-authoritative):
 * `ZAD|setId|adjustmentType|adjustmentQuantity|adjustmentReason|adjustmentDateTime|approvedBy`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZADSegment")))
@interface Hl7CoreZADSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZADSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *adjustmentDateTime __attribute__((swift_name("adjustmentDateTime")));
@property (readonly) NSString *adjustmentQuantity __attribute__((swift_name("adjustmentQuantity")));
@property (readonly) NSString *adjustmentReason __attribute__((swift_name("adjustmentReason")));
@property (readonly) NSString *adjustmentType __attribute__((swift_name("adjustmentType")));
@property (readonly) NSString *approvedBy __attribute__((swift_name("approvedBy")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZADSegment.Companion")))
@interface Hl7CoreZADSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZADSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZIN — Inventory count row (existing Z-segment).
 * Format: `ZIN|setId|dispenseType|quantity|lotNumber|expiry`
 * dispenseType ∈ { OPENED, SEALED, NA, EXPECTED_ON_HAND, ... }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZINSegment")))
@interface Hl7CoreZINSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZINSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *dispenseType __attribute__((swift_name("dispenseType")));
@property (readonly) NSString *expiry __attribute__((swift_name("expiry")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *quantity __attribute__((swift_name("quantity")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZINSegment.Companion")))
@interface Hl7CoreZINSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZINSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZPR — Transaction priority (existing Z-segment).
 * Format: `ZPR|setId|PRIORITY|<STAT|URGENT|ROUTINE|TIMED>`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZPRSegment")))
@interface Hl7CoreZPRSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZPRSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *priority __attribute__((swift_name("priority")));
@property (readonly) NSString *qualifier __attribute__((swift_name("qualifier")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZPRSegment.Companion")))
@interface Hl7CoreZPRSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZPRSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZSN — Serial Number Capture (DSCSA). New §10 extension.
 *
 * Field map (project-authoritative):
 * `ZSN|setId|packageSerialNumber|nationalDrugCode|lotNumber|expirationDate|transactionType`
 * transactionType: D = dispense, R = return.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSNSegment")))
@interface Hl7CoreZSNSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZSNSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *nationalDrugCode __attribute__((swift_name("nationalDrugCode")));
@property (readonly) NSString *packageSerialNumber __attribute__((swift_name("packageSerialNumber")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *transactionType __attribute__((swift_name("transactionType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSNSegment.Companion")))
@interface Hl7CoreZSNSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZSNSegmentCompanion *shared __attribute__((swift_name("shared")));

/** Register on parser/builder via `registerCustomSegment(ZSNSegment.Definition)`. */
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZSV — Stock Bottle Validation Assertion. New §13 extension.
 *
 * Field map (project-authoritative):
 * `ZSV|setId|validationStatus|validationTimestamp|validatorId|rejectionReason`
 * validationStatus: VA = valid, VR = rejected.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSVSegment")))
@interface Hl7CoreZSVSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZSVSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *rejectionReason __attribute__((swift_name("rejectionReason")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *validationStatus __attribute__((swift_name("validationStatus")));
@property (readonly) NSString *validationTimestamp __attribute__((swift_name("validationTimestamp")));
@property (readonly) NSString *validatorId __attribute__((swift_name("validatorId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSVSegment.Companion")))
@interface Hl7CoreZSVSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZSVSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * Splits a raw HL7 message string into generic [HL7Segment]s.
 *
 * Responsibilities:
 *  - normalize line endings (`\r\n`, `\n` → `\r`) and split into segment lines
 *  - read the delimiter set from the MSH line (never assumed)
 *  - parse each line into a generic segment using those delimiters
 *
 * It does NO domain interpretation — that is the parser/typed layer's job.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Lexer")))
@interface Hl7CoreHL7Lexer : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Splits a raw HL7 message string into generic [HL7Segment]s.
 *
 * Responsibilities:
 *  - normalize line endings (`\r\n`, `\n` → `\r`) and split into segment lines
 *  - read the delimiter set from the MSH line (never assumed)
 *  - parse each line into a generic segment using those delimiters
 *
 * It does NO domain interpretation — that is the parser/typed layer's job.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hL7Lexer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7Lexer *shared __attribute__((swift_name("shared")));
- (Hl7CoreHL7LexerLexResult *)lexRaw:(NSString *)raw __attribute__((swift_name("lex(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Lexer.LexResult")))
@interface Hl7CoreHL7LexerLexResult : Hl7CoreBase
- (instancetype)initWithSegments:(NSArray<Hl7CoreHL7Segment *> *)segments delimiters:(Hl7CoreHL7Delimiters *)delimiters errors:(NSArray<NSString *> *)errors __attribute__((swift_name("init(segments:delimiters:errors:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreHL7LexerLexResult *)doCopySegments:(NSArray<Hl7CoreHL7Segment *> *)segments delimiters:(Hl7CoreHL7Delimiters *)delimiters errors:(NSArray<NSString *> *)errors __attribute__((swift_name("doCopy(segments:delimiters:errors:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Hl7CoreHL7Delimiters *delimiters __attribute__((swift_name("delimiters")));

/** Lines that could not be lexed (e.g. before MSH); empty on success. */
@property (readonly) NSArray<NSString *> *errors __attribute__((swift_name("errors")));
@property (readonly) NSArray<Hl7CoreHL7Segment *> *segments __attribute__((swift_name("segments")));
@end


/** A single parse-time problem. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7ParseError")))
@interface Hl7CoreHL7ParseError : Hl7CoreBase
- (instancetype)initWithMessage:(NSString *)message segmentName:(NSString * _Nullable)segmentName lineIndex:(Hl7CoreInt * _Nullable)lineIndex __attribute__((swift_name("init(message:segmentName:lineIndex:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreHL7ParseError *)doCopyMessage:(NSString *)message segmentName:(NSString * _Nullable)segmentName lineIndex:(Hl7CoreInt * _Nullable)lineIndex __attribute__((swift_name("doCopy(message:segmentName:lineIndex:)")));

/** A single parse-time problem. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A single parse-time problem. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A single parse-time problem. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Hl7CoreInt * _Nullable lineIndex __attribute__((swift_name("lineIndex")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) NSString * _Nullable segmentName __attribute__((swift_name("segmentName")));
@end


/**
 * Outcome of [HL7Parser.parse].
 *
 * - [Success] carries the parsed [message].
 * - [Failure] carries the collected [errors] and, in non-strict mode, a
 *   [partialMessage] containing the segments that parsed successfully.
 *
 * Swift pattern-matches this as `if case .success(let message) = ...`.
 */
__attribute__((swift_name("HL7ParseResult")))
@interface Hl7CoreHL7ParseResult : Hl7CoreBase
@property (readonly) BOOL isSuccess __attribute__((swift_name("isSuccess")));

/** The message if successful, else the partial message (may be null). */
@property (readonly) Hl7CoreHL7Message * _Nullable messageOrNull __attribute__((swift_name("messageOrNull")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7ParseResult.Failure")))
@interface Hl7CoreHL7ParseResultFailure : Hl7CoreHL7ParseResult
- (instancetype)initWithErrors:(NSArray<Hl7CoreHL7ParseError *> *)errors partialMessage:(Hl7CoreHL7Message * _Nullable)partialMessage __attribute__((swift_name("init(errors:partialMessage:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreHL7ParseResultFailure *)doCopyErrors:(NSArray<Hl7CoreHL7ParseError *> *)errors partialMessage:(Hl7CoreHL7Message * _Nullable)partialMessage __attribute__((swift_name("doCopy(errors:partialMessage:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<Hl7CoreHL7ParseError *> *errors __attribute__((swift_name("errors")));
@property (readonly) Hl7CoreHL7Message * _Nullable partialMessage __attribute__((swift_name("partialMessage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7ParseResult.Success")))
@interface Hl7CoreHL7ParseResultSuccess : Hl7CoreHL7ParseResult
- (instancetype)initWithMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreHL7ParseResultSuccess *)doCopyMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("doCopy(message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Hl7CoreHL7Message *message __attribute__((swift_name("message")));
@end


/**
 * Parses raw HL7 text (or MLLP frames) into a typed [HL7Message].
 *
 * Construct via the fluent [Builder]; the resulting parser is immutable and
 * thread-safe — create once and inject.
 *
 * ```
 * val parser = HL7Parser.Builder()
 *     .defaultVersion("2.5")
 *     .registerCustomSegment(ZSNSegment.Definition)
 *     .strictMode(false)
 *     .build()
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Parser")))
@interface Hl7CoreHL7Parser : Hl7CoreBase

/** Parses raw HL7 text. Returns [HL7ParseResult.Success] or [HL7ParseResult.Failure]. */
- (Hl7CoreHL7ParseResult *)parseRaw:(NSString *)raw __attribute__((swift_name("parse(raw:)")));

/** Parses an MLLP-framed byte array. */
- (Hl7CoreHL7ParseResult *)parseMllpBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("parseMllp(bytes:)")));
@end


/** Fluent builder for [HL7Parser]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Parser.Builder")))
@interface Hl7CoreHL7ParserBuilder : Hl7CoreBase

/** Fluent builder for [HL7Parser]. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Fluent builder for [HL7Parser]. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreHL7Parser *)build __attribute__((swift_name("build()")));
- (Hl7CoreHL7ParserBuilder *)defaultVersionVersion:(NSString *)version __attribute__((swift_name("defaultVersion(version:)")));
- (Hl7CoreHL7ParserBuilder *)defaultVersionVersion_:(Hl7CoreHL7Version *)version __attribute__((swift_name("defaultVersion(version_:)")));

/** Registers a custom (Z-)segment definition (e.g. `ZSNSegment.Definition`). */
- (Hl7CoreHL7ParserBuilder *)registerCustomSegmentDefinition:(Hl7CoreSegmentDefinition *)definition __attribute__((swift_name("registerCustomSegment(definition:)")));

/** When false (default), parse errors still return successfully-parsed segments. */
- (Hl7CoreHL7ParserBuilder *)strictModeStrict:(BOOL)strict __attribute__((swift_name("strictMode(strict:)")));
@end


/**
 * Timestamp helpers for HL7 builders. [now] returns the current local time
 * formatted as `yyyyMMddHHmmss` (HL7 TS format).
 *
 * The platform [currentLocalDateTime] returns ISO `yyyy-MM-dd'T'HH:mm:ss`;
 * we strip the separators to the HL7 form here so no platform code changes.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Date")))
@interface Hl7CoreHL7Date : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Timestamp helpers for HL7 builders. [now] returns the current local time
 * formatted as `yyyyMMddHHmmss` (HL7 TS format).
 *
 * The platform [currentLocalDateTime] returns ISO `yyyy-MM-dd'T'HH:mm:ss`;
 * we strip the separators to the HL7 form here so no platform code changes.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hL7Date __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7Date *shared __attribute__((swift_name("shared")));

/** Current local time as `yyyyMMddHHmmss`. */
- (NSString *)now __attribute__((swift_name("now()")));

/** Converts ISO `yyyy-MM-dd'T'HH:mm:ss` to HL7 `yyyyMMddHHmmss`. */
- (NSString *)toHl7Iso:(NSString *)iso __attribute__((swift_name("toHl7(iso:)")));
@end


/**
 * Builds an ACK^R01 response for an inbound message and a [ValidationResult].
 * MSA-1 carries the worst severity (AA/AE/AR); one ERR is emitted per issue.
 * Sender/receiver are swapped from the inbound header so the ACK routes back.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckBuilder")))
@interface Hl7CoreAckBuilder : Hl7CoreBase
- (instancetype)initWithBuilder:(Hl7CoreHL7Builder *)builder __attribute__((swift_name("init(builder:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreHL7Message *)buildInbound:(Hl7CoreHL7Message *)inbound result:(Hl7CoreValidationResult *)result __attribute__((swift_name("build(inbound:result:)")));
@end


/** ACK severity for a validation issue, mapped to MSA-1 codes. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckSeverity")))
@interface Hl7CoreAckSeverity : Hl7CoreKotlinEnum<Hl7CoreAckSeverity *>
+ (instancetype)alloc __attribute__((unavailable));

/** ACK severity for a validation issue, mapped to MSA-1 codes. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Hl7CoreAckSeverity *accept __attribute__((swift_name("accept")));
@property (class, readonly) Hl7CoreAckSeverity *error __attribute__((swift_name("error")));
@property (class, readonly) Hl7CoreAckSeverity *reject __attribute__((swift_name("reject")));
+ (Hl7CoreKotlinArray<Hl7CoreAckSeverity *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Hl7CoreAckSeverity *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end


/**
 * Validates a parsed [HL7Message] against required-field, message-shape, and
 * spec extension rules (§11/§12/§13), producing a [ValidationResult] that drives
 * the ACK code.
 *
 * Rules follow the project-authoritative Z-segment layout:
 *  - QBP^Q11: QPD-1 must equal the configured query name → else AR.
 *  - ZAD: adjustmentType and adjustmentReason must be recognized → else AR;
 *    a reason that requires a comment must have one → else AE.
 *  - ZSV: a rejected validation (VR) must carry a rejection reason → else AE.
 *
 * Construct with a [ValidationConfig] to override the site defaults.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Validator")))
@interface Hl7CoreHL7Validator : Hl7CoreBase
- (instancetype)initWithConfig:(Hl7CoreValidationConfig *)config __attribute__((swift_name("init(config:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreValidationResult *)validateMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("validate(message:)")));
@end


/**
 * Site-configurable inputs for the validator. Defaults follow the PillCounter
 * spec; partners may override per site (the spec's "downloadable text file" model).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationConfig")))
@interface Hl7CoreValidationConfig : Hl7CoreBase
- (instancetype)initWithKnownAdjustmentReasons:(NSSet<NSString *> *)knownAdjustmentReasons knownAdjustmentTypes:(NSSet<NSString *> *)knownAdjustmentTypes expectedQueryName:(NSString *)expectedQueryName commentRequiredReasons:(NSSet<NSString *> *)commentRequiredReasons __attribute__((swift_name("init(knownAdjustmentReasons:knownAdjustmentTypes:expectedQueryName:commentRequiredReasons:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreValidationConfigCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreValidationConfig *)doCopyKnownAdjustmentReasons:(NSSet<NSString *> *)knownAdjustmentReasons knownAdjustmentTypes:(NSSet<NSString *> *)knownAdjustmentTypes expectedQueryName:(NSString *)expectedQueryName commentRequiredReasons:(NSSet<NSString *> *)commentRequiredReasons __attribute__((swift_name("doCopy(knownAdjustmentReasons:knownAdjustmentTypes:expectedQueryName:commentRequiredReasons:)")));

/**
 * Site-configurable inputs for the validator. Defaults follow the PillCounter
 * spec; partners may override per site (the spec's "downloadable text file" model).
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Site-configurable inputs for the validator. Defaults follow the PillCounter
 * spec; partners may override per site (the spec's "downloadable text file" model).
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Site-configurable inputs for the validator. Defaults follow the PillCounter
 * spec; partners may override per site (the spec's "downloadable text file" model).
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Adjustment reasons that require a non-empty comment (currently none in the user layout). */
@property (readonly) NSSet<NSString *> *commentRequiredReasons __attribute__((swift_name("commentRequiredReasons")));

/** The literal query name QPD-1 must carry for a stock-on-hand query. */
@property (readonly) NSString *expectedQueryName __attribute__((swift_name("expectedQueryName")));

/** Adjustment reason codes the PMS recognizes (ZAD-4 / adjustmentReason). */
@property (readonly) NSSet<NSString *> *knownAdjustmentReasons __attribute__((swift_name("knownAdjustmentReasons")));

/** Adjustment types the PMS recognizes (ZAD-2 / adjustmentType). */
@property (readonly) NSSet<NSString *> *knownAdjustmentTypes __attribute__((swift_name("knownAdjustmentTypes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationConfig.Companion")))
@interface Hl7CoreValidationConfigCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreValidationConfigCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreValidationConfig *DEFAULT __attribute__((swift_name("DEFAULT")));
@property (readonly) NSSet<NSString *> *DEFAULT_ADJUSTMENT_REASONS __attribute__((swift_name("DEFAULT_ADJUSTMENT_REASONS")));
@property (readonly) NSSet<NSString *> *DEFAULT_ADJUSTMENT_TYPES __attribute__((swift_name("DEFAULT_ADJUSTMENT_TYPES")));
@property (readonly) NSString *DEFAULT_QUERY_NAME __attribute__((swift_name("DEFAULT_QUERY_NAME")));
@end


/** A single validation problem, carrying enough to build an ERR segment. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationIssue")))
@interface Hl7CoreValidationIssue : Hl7CoreBase
- (instancetype)initWithSeverity:(Hl7CoreAckSeverity *)severity errorText:(NSString *)errorText segmentId:(NSString * _Nullable)segmentId fieldPosition:(NSString * _Nullable)fieldPosition errorCode:(NSString * _Nullable)errorCode __attribute__((swift_name("init(severity:errorText:segmentId:fieldPosition:errorCode:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreValidationIssue *)doCopySeverity:(Hl7CoreAckSeverity *)severity errorText:(NSString *)errorText segmentId:(NSString * _Nullable)segmentId fieldPosition:(NSString * _Nullable)fieldPosition errorCode:(NSString * _Nullable)errorCode __attribute__((swift_name("doCopy(severity:errorText:segmentId:fieldPosition:errorCode:)")));

/** A single validation problem, carrying enough to build an ERR segment. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A single validation problem, carrying enough to build an ERR segment. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A single validation problem, carrying enough to build an ERR segment. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable errorCode __attribute__((swift_name("errorCode")));
@property (readonly) NSString *errorText __attribute__((swift_name("errorText")));
@property (readonly) NSString * _Nullable fieldPosition __attribute__((swift_name("fieldPosition")));
@property (readonly) NSString * _Nullable segmentId __attribute__((swift_name("segmentId")));
@property (readonly) Hl7CoreAckSeverity *severity __attribute__((swift_name("severity")));
@end


/** Aggregated validation outcome. [worst] decides the ACK code. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationResult")))
@interface Hl7CoreValidationResult : Hl7CoreBase
- (instancetype)initWithIssues:(NSArray<Hl7CoreValidationIssue *> *)issues __attribute__((swift_name("init(issues:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreValidationResultCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL isValid __attribute__((swift_name("isValid")));
@property (readonly) NSArray<Hl7CoreValidationIssue *> *issues __attribute__((swift_name("issues")));

/** Highest severity present (REJECT > ERROR > ACCEPT). */
@property (readonly) Hl7CoreAckSeverity *worst __attribute__((swift_name("worst")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationResult.Companion")))
@interface Hl7CoreValidationResultCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreValidationResultCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreValidationResult *VALID __attribute__((swift_name("VALID")));
@end


/**
 * HL7 v2.x versions this library understands. [DEFAULT] is used when MSH-12 is
 * absent or unrecognized.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Version")))
@interface Hl7CoreHL7Version : Hl7CoreKotlinEnum<Hl7CoreHL7Version *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * HL7 v2.x versions this library understands. [DEFAULT] is used when MSH-12 is
 * absent or unrecognized.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Hl7CoreHL7VersionCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Hl7CoreHL7Version *v21 __attribute__((swift_name("v21")));
@property (class, readonly) Hl7CoreHL7Version *v22 __attribute__((swift_name("v22")));
@property (class, readonly) Hl7CoreHL7Version *v23 __attribute__((swift_name("v23")));
@property (class, readonly) Hl7CoreHL7Version *v231 __attribute__((swift_name("v231")));
@property (class, readonly) Hl7CoreHL7Version *v24 __attribute__((swift_name("v24")));
@property (class, readonly) Hl7CoreHL7Version *v25 __attribute__((swift_name("v25")));
@property (class, readonly) Hl7CoreHL7Version *v251 __attribute__((swift_name("v251")));
@property (class, readonly) Hl7CoreHL7Version *v26 __attribute__((swift_name("v26")));
@property (class, readonly) Hl7CoreHL7Version *v27 __attribute__((swift_name("v27")));
@property (class, readonly) Hl7CoreHL7Version *v28 __attribute__((swift_name("v28")));
+ (Hl7CoreKotlinArray<Hl7CoreHL7Version *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Hl7CoreHL7Version *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *wire __attribute__((swift_name("wire")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Version.Companion")))
@interface Hl7CoreHL7VersionCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7VersionCompanion *shared __attribute__((swift_name("shared")));

/** Resolves an MSH-12 value (e.g. "2.5", "2.5.1") to a version, defaulting to [DEFAULT]. */
- (Hl7CoreHL7Version *)fromMsh12:(NSString * _Nullable)msh12 __attribute__((swift_name("from(msh12:)")));
@property (readonly) Hl7CoreHL7Version *DEFAULT __attribute__((swift_name("DEFAULT")));
@end


/**
 * Single registry of the maximum field count a segment carries per HL7 version.
 * Replaces the old per-segment `*VersionCapabilities` objects.
 *
 * Used on the BUILD side to trim trailing fields beyond the version cap, and
 * available on the PARSE side for version-aware validation. Unknown segments
 * (Z-segments, vendor segments) have no cap.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentCapabilities")))
@interface Hl7CoreSegmentCapabilities : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Single registry of the maximum field count a segment carries per HL7 version.
 * Replaces the old per-segment `*VersionCapabilities` objects.
 *
 * Used on the BUILD side to trim trailing fields beyond the version cap, and
 * available on the PARSE side for version-aware validation. Unknown segments
 * (Z-segments, vendor segments) have no cap.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)segmentCapabilities __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSegmentCapabilities *shared __attribute__((swift_name("shared")));

/** Max 1-based field index for [segment] at [version], or null if uncapped (e.g. Z-segments). */
- (Hl7CoreInt * _Nullable)maxFieldsSegment:(NSString *)segment version:(Hl7CoreHL7Version *)version __attribute__((swift_name("maxFields(segment:version:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CurrentLocalDateTime_iosKt")))
@interface Hl7CoreCurrentLocalDateTime_iosKt : Hl7CoreBase
+ (NSString *)currentLocalDateTime __attribute__((swift_name("currentLocalDateTime()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface Hl7CoreKotlinByteArray : Hl7CoreBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(Hl7CoreByte *(^)(Hl7CoreInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (Hl7CoreKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface Hl7CoreKotlinArray<T> : Hl7CoreBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(Hl7CoreInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<Hl7CoreKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface Hl7CoreKotlinEnumCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol Hl7CoreKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface Hl7CoreKotlinByteIterator : Hl7CoreBase <Hl7CoreKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Hl7CoreByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
