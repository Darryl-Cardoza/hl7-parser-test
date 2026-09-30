#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class Hl7CoreAckCode, Hl7CoreAckCodeAA, Hl7CoreAckCodeAE, Hl7CoreAckCodeAR, Hl7CoreAckCodeCA, Hl7CoreAckCodeCE, Hl7CoreAckCodeCR, Hl7CoreAckCodeCompanion, Hl7CoreAckCodeUnknown, Hl7CoreAckScope, Hl7CoreAckSeverity, Hl7CoreBTSBuilder, Hl7CoreBTSSegmentCompanion, Hl7CoreDeviceINVBuilder, Hl7CoreEQUBuilder, Hl7CoreEQUSegmentCompanion, Hl7CoreERRBuilder, Hl7CoreERRSegmentCompanion, Hl7CoreEquipmentState, Hl7CoreEquipmentStateA, Hl7CoreEquipmentStateCL, Hl7CoreEquipmentStateCO, Hl7CoreEquipmentStateCompanion, Hl7CoreEquipmentStateDC, Hl7CoreEquipmentStateDI, Hl7CoreEquipmentStateES, Hl7CoreEquipmentStateI, Hl7CoreEquipmentStateID, Hl7CoreEquipmentStateIN, Hl7CoreEquipmentStateOP, Hl7CoreEquipmentStatePA, Hl7CoreEquipmentStatePD, Hl7CoreEquipmentStatePU, Hl7CoreEquipmentStateRS, Hl7CoreEquipmentStateUNK, Hl7CoreEquipmentStateUnknown, Hl7CoreHL7Builder, Hl7CoreHL7BuilderBuilder, Hl7CoreHL7BuilderCompanion, Hl7CoreHL7Component, Hl7CoreHL7ComponentCompanion, Hl7CoreHL7Date, Hl7CoreHL7Delimiters, Hl7CoreHL7DelimitersCompanion, Hl7CoreHL7Escaping, Hl7CoreHL7Field, Hl7CoreHL7FieldCompanion, Hl7CoreHL7Lexer, Hl7CoreHL7LexerLexResult, Hl7CoreHL7Message, Hl7CoreHL7MessageKind, Hl7CoreHL7MessageKindCompanion, Hl7CoreHL7ParseError, Hl7CoreHL7ParseResult, Hl7CoreHL7ParseResultFailure, Hl7CoreHL7ParseResultSuccess, Hl7CoreHL7Parser, Hl7CoreHL7ParserBuilder, Hl7CoreHL7Segment, Hl7CoreHL7SegmentBuilder, Hl7CoreHL7SegmentCompanion, Hl7CoreHL7ValidatorCompanion, Hl7CoreHL7Version, Hl7CoreHL7VersionCompanion, Hl7CoreINVBuilder, Hl7CoreINVSegmentCompanion, Hl7CoreInrU05Scope, Hl7CoreInrU06Scope, Hl7CoreInuU05Scope, Hl7CoreInventoryCountINVBuilder, Hl7CoreKotlinArray<T>, Hl7CoreKotlinByteArray, Hl7CoreKotlinByteIterator, Hl7CoreKotlinEnum<E>, Hl7CoreKotlinEnumCompanion, Hl7CoreKotlinException, Hl7CoreKotlinThrowable, Hl7CoreMSABuilder, Hl7CoreMSASegmentCompanion, Hl7CoreMSHBuilder, Hl7CoreMSHSegment, Hl7CoreMSHSegmentCompanion, Hl7CoreMessageScope, Hl7CoreMllp, Hl7CoreNTEBuilder, Hl7CoreNTESegmentCompanion, Hl7CoreOBXBuilder, Hl7CoreOBXSegmentCompanion, Hl7CoreORCBuilder, Hl7CoreORCSegment, Hl7CoreORCSegmentCompanion, Hl7CoreObsResultStatus, Hl7CoreObsResultStatusC, Hl7CoreObsResultStatusCompanion, Hl7CoreObsResultStatusD, Hl7CoreObsResultStatusF, Hl7CoreObsResultStatusI, Hl7CoreObsResultStatusN, Hl7CoreObsResultStatusO, Hl7CoreObsResultStatusP, Hl7CoreObsResultStatusR, Hl7CoreObsResultStatusS, Hl7CoreObsResultStatusU, Hl7CoreObsResultStatusUnknown, Hl7CoreObsResultStatusW, Hl7CoreObsResultStatusX, Hl7CoreOrderBlockScope, Hl7CoreOrderControl, Hl7CoreOrderControlAF, Hl7CoreOrderControlCA, Hl7CoreOrderControlCompanion, Hl7CoreOrderControlDC, Hl7CoreOrderControlDF, Hl7CoreOrderControlFU, Hl7CoreOrderControlHD, Hl7CoreOrderControlNW, Hl7CoreOrderControlOC, Hl7CoreOrderControlOD, Hl7CoreOrderControlOH, Hl7CoreOrderControlOK, Hl7CoreOrderControlRE, Hl7CoreOrderControlRF, Hl7CoreOrderControlRO, Hl7CoreOrderControlRP, Hl7CoreOrderControlSC, Hl7CoreOrderControlUA, Hl7CoreOrderControlUnknown, Hl7CoreOrderControlXO, Hl7CoreOrderGroup, Hl7CoreOrderStatus, Hl7CoreOrderStatusA, Hl7CoreOrderStatusCA, Hl7CoreOrderStatusCM, Hl7CoreOrderStatusCompanion, Hl7CoreOrderStatusDC, Hl7CoreOrderStatusER, Hl7CoreOrderStatusHD, Hl7CoreOrderStatusIP, Hl7CoreOrderStatusRP, Hl7CoreOrderStatusSC, Hl7CoreOrderStatusUnknown, Hl7CorePIDBuilder, Hl7CorePIDSegmentCompanion, Hl7CorePV1Builder, Hl7CorePV1SegmentCompanion, Hl7CorePriority, Hl7CorePriorityA, Hl7CorePriorityC, Hl7CorePriorityCompanion, Hl7CorePriorityP, Hl7CorePriorityPRN, Hl7CorePriorityR, Hl7CorePriorityS, Hl7CorePriorityT, Hl7CorePriorityUD, Hl7CorePriorityUnknown, Hl7CoreQAKSegmentCompanion, Hl7CoreQPDBuilder, Hl7CoreQPDSegmentCompanion, Hl7CoreQbpQ11Scope, Hl7CoreRCPBuilder, Hl7CoreRCPSegmentCompanion, Hl7CoreRXCBuilder, Hl7CoreRXCSegmentCompanion, Hl7CoreRXDBuilder, Hl7CoreRXDSegmentCompanion, Hl7CoreRXEBuilder, Hl7CoreRXESegment, Hl7CoreRXESegmentCompanion, Hl7CoreRXRBuilder, Hl7CoreRXRSegment, Hl7CoreRXRSegmentCompanion, Hl7CoreRdeO11Scope, Hl7CoreRdsO13Scope, Hl7CoreScanSource, Hl7CoreSegmentCapabilities, Hl7CoreSegmentDefinition, Hl7CoreSubstanceStatus, Hl7CoreSubstanceStatusCE, Hl7CoreSubstanceStatusCW, Hl7CoreSubstanceStatusCompanion, Hl7CoreSubstanceStatusEE, Hl7CoreSubstanceStatusEW, Hl7CoreSubstanceStatusNE, Hl7CoreSubstanceStatusNW, Hl7CoreSubstanceStatusOE, Hl7CoreSubstanceStatusOK, Hl7CoreSubstanceStatusOW, Hl7CoreSubstanceStatusQE, Hl7CoreSubstanceStatusQW, Hl7CoreSubstanceStatusUnknown, Hl7CoreSubstitutionStatus, Hl7CoreSubstitutionStatusBrandAsGeneric, Hl7CoreSubstitutionStatusBrandMandatedByLaw, Hl7CoreSubstitutionStatusCompanion, Hl7CoreSubstitutionStatusG, Hl7CoreSubstitutionStatusGenericNotAvailable, Hl7CoreSubstitutionStatusGenericNotInStock, Hl7CoreSubstitutionStatusN, Hl7CoreSubstitutionStatusNoSelection, Hl7CoreSubstitutionStatusNotAllowed, Hl7CoreSubstitutionStatusPatientRequested, Hl7CoreSubstitutionStatusPharmacistSelected, Hl7CoreSubstitutionStatusT, Hl7CoreSubstitutionStatusUnknown, Hl7CoreTQ, Hl7CoreTQ1Segment, Hl7CoreTQ1SegmentCompanion, Hl7CoreTQCompanion, Hl7CoreTypedSegment, Hl7CoreValidationConfig, Hl7CoreValidationConfigCompanion, Hl7CoreValidationIssue, Hl7CoreValidationResult, Hl7CoreValidationResultCompanion, Hl7CoreZADBuilder, Hl7CoreZADSegmentCompanion, Hl7CoreZCCBuilder, Hl7CoreZCCSegmentCompanion, Hl7CoreZINBuilder, Hl7CoreZINSegmentCompanion, Hl7CoreZNIBuilder, Hl7CoreZNISegmentCompanion, Hl7CoreZPRSegment, Hl7CoreZPRSegmentCompanion, Hl7CoreZSNBuilder, Hl7CoreZSNSegmentCompanion, Hl7CoreZSVBuilder, Hl7CoreZSVSegmentCompanion, Hl7CoreZUIDispenseBuilder, Hl7CoreZUIOrderBuilder, Hl7CoreZUISegmentCompanion, Hl7CoreZadReasonCode, Hl7CoreZsnTransactionType, Hl7CoreZsvMatchStrength, Hl7CoreZsvValidationResult, Hl7CoreZuiTransactionStatus;

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
- (NSArray<Hl7CoreHL7ParseResult *> *)parseMllpBatchBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("parseMllpBatch(bytes:)")));
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

/** Sets field [n] as multiple `~`-separated repetitions (e.g. a list of image paths).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)setRepeatedN:(int32_t)n values:(NSArray<NSString *> * _Nullable)values __attribute__((swift_name("setRepeated(n:values:)")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * BTS — Batch Trailer Segment (standard control segment, HL7 v2.5.1 §2.19).
 * Used per-message to mark this message's position within a chunked inventory
 * sync: BTS-1 = this chunk's 1-based index (numeric), BTS-2 = total chunk
 * count for this sync (numeric — NOT free text), BTS-3 = this chunk's item
 * total (numeric).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BTSBuilder")))
@interface Hl7CoreBTSBuilder : Hl7CoreHL7SegmentBuilder

/**
 * BTS — Batch Trailer Segment (standard control segment, HL7 v2.5.1 §2.19).
 * Used per-message to mark this message's position within a chunked inventory
 * sync: BTS-1 = this chunk's 1-based index (numeric), BTS-2 = total chunk
 * count for this sync (numeric — NOT free text), BTS-3 = this chunk's item
 * total (numeric).
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * BTS — Batch Trailer Segment (standard control segment, HL7 v2.5.1 §2.19).
 * Used per-message to mark this message's position within a chunked inventory
 * sync: BTS-1 = this chunk's 1-based index (numeric), BTS-2 = total chunk
 * count for this sync (numeric — NOT free text), BTS-3 = this chunk's item
 * total (numeric).
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable batchComment __attribute__((swift_name("batchComment")));
@property NSString * _Nullable batchMessageCount __attribute__((swift_name("batchMessageCount")));
@property NSString * _Nullable batchTotals __attribute__((swift_name("batchTotals")));
@end


/**
 * INV — Device Inventory Sync row (vendor cycle-count payload, e.g. Parata
 * robot INU^U05). Distinct field layout from [INVBuilder]'s project-compact
 * INV; both share the wire segment name "INV" — see [org.rite.hl7.model.segment.INVSegment]
 * for how readers tell the two apart.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceINVBuilder")))
@interface Hl7CoreDeviceINVBuilder : Hl7CoreHL7SegmentBuilder

/**
 * INV — Device Inventory Sync row (vendor cycle-count payload, e.g. Parata
 * robot INU^U05). Distinct field layout from [INVBuilder]'s project-compact
 * INV; both share the wire segment name "INV" — see [org.rite.hl7.model.segment.INVSegment]
 * for how readers tell the two apart.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * INV — Device Inventory Sync row (vendor cycle-count payload, e.g. Parata
 * robot INU^U05). Distinct field layout from [INVBuilder]'s project-compact
 * INV; both share the wire segment name "INV" — see [org.rite.hl7.model.segment.INVSegment]
 * for how readers tell the two apart.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable itemCode __attribute__((swift_name("itemCode")));
@property NSString * _Nullable itemName __attribute__((swift_name("itemName")));
@property NSString * _Nullable locationCode __attribute__((swift_name("locationCode")));
@property NSString * _Nullable locationText __attribute__((swift_name("locationText")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable packageSize __attribute__((swift_name("packageSize")));
@property NSString * _Nullable quantityAvailable __attribute__((swift_name("quantityAvailable")));
@property NSString * _Nullable quantityExpected __attribute__((swift_name("quantityExpected")));
@property NSString * _Nullable quantityOnHand __attribute__((swift_name("quantityOnHand")));
@property NSString * _Nullable statusCode __attribute__((swift_name("statusCode")));
@property NSString * _Nullable statusText __attribute__((swift_name("statusText")));
@property NSString * _Nullable typeCode __attribute__((swift_name("typeCode")));
@property NSString * _Nullable typeText __attribute__((swift_name("typeText")));
@property NSString * _Nullable unitsCode __attribute__((swift_name("unitsCode")));
@property NSString * _Nullable unitsText __attribute__((swift_name("unitsText")));
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
- (Hl7CoreHL7Message *)rdeO25Block:(void (^)(Hl7CoreRdeO11Scope *))block __attribute__((swift_name("rdeO25(block:)")));
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


/** Field positions per [org.rite.hl7.model.segment.INVSegment]'s project-specific compact layout. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVBuilder")))
@interface Hl7CoreINVBuilder : Hl7CoreHL7SegmentBuilder

/** Field positions per [org.rite.hl7.model.segment.INVSegment]'s project-specific compact layout. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Field positions per [org.rite.hl7.model.segment.INVSegment]'s project-specific compact layout. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable inventoryOnHandQuantity __attribute__((swift_name("inventoryOnHandQuantity")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable substanceCode __attribute__((swift_name("substanceCode")));
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


/**
 * Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11).
 * ZIN rows are a project extension used alongside INV so PMS can see the
 * opened/sealed breakdown behind each INV row's combined on-hand total.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InrU06Scope")))
@interface Hl7CoreInrU06Scope : Hl7CoreMessageScope

/**
 * Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11).
 * ZIN rows are a project extension used alongside INV so PMS can see the
 * opened/sealed breakdown behind each INV row's combined on-hand total.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Scope for INR^U06 inventory adjustment (INV + ZAD pairs from §11).
 * ZIN rows are a project extension used alongside INV so PMS can see the
 * opened/sealed breakdown behind each INV row's combined on-hand total.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/** Per-message chunk trailer — present only when this message is one chunk of a split sync. */
- (Hl7CoreBTSBuilder *)btsBlock:(void (^)(Hl7CoreBTSBuilder *))block __attribute__((swift_name("bts(block:)")));
- (Hl7CoreEQUBuilder *)equBlock:(void (^)(Hl7CoreEQUBuilder *))block __attribute__((swift_name("equ(block:)")));
- (Hl7CoreINVBuilder *)invBlock:(void (^)(Hl7CoreINVBuilder *))block __attribute__((swift_name("inv(block:)")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CoreZADBuilder *)zadBlock:(void (^)(Hl7CoreZADBuilder *))block __attribute__((swift_name("zad(block:)")));
- (Hl7CoreZINBuilder *)zinBlock:(void (^)(Hl7CoreZINBuilder *))block __attribute__((swift_name("zin(block:)")));
@end


/**
 * Scope for INU^U05 inventory update — sent as the response to a
 * PMS-initiated INR^U06 request (or unsolicited). INV carries each drug/lot
 * group's combined on-hand total; ZIN rows underneath break that total down
 * by dispenseType (OPENED/SEALED).
 *
 * ZAD is not part of the standard INU_U05 definition; it's kept here as a
 * project-specific extension so cycle-count adjustment reason/approver data
 * still travels on the response.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InuU05Scope")))
@interface Hl7CoreInuU05Scope : Hl7CoreMessageScope

/**
 * Scope for INU^U05 inventory update — sent as the response to a
 * PMS-initiated INR^U06 request (or unsolicited). INV carries each drug/lot
 * group's combined on-hand total; ZIN rows underneath break that total down
 * by dispenseType (OPENED/SEALED).
 *
 * ZAD is not part of the standard INU_U05 definition; it's kept here as a
 * project-specific extension so cycle-count adjustment reason/approver data
 * still travels on the response.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Scope for INU^U05 inventory update — sent as the response to a
 * PMS-initiated INR^U06 request (or unsolicited). INV carries each drug/lot
 * group's combined on-hand total; ZIN rows underneath break that total down
 * by dispenseType (OPENED/SEALED).
 *
 * ZAD is not part of the standard INU_U05 definition; it's kept here as a
 * project-specific extension so cycle-count adjustment reason/approver data
 * still travels on the response.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/** Per-message chunk trailer — present only when this message is one chunk of a split sync. */
- (Hl7CoreBTSBuilder *)btsBlock:(void (^)(Hl7CoreBTSBuilder *))block __attribute__((swift_name("bts(block:)")));
- (Hl7CoreEQUBuilder *)equBlock:(void (^)(Hl7CoreEQUBuilder *))block __attribute__((swift_name("equ(block:)")));
- (Hl7CoreINVBuilder *)invBlock:(void (^)(Hl7CoreINVBuilder *))block __attribute__((swift_name("inv(block:)")));

/**
 * Standard-first count-result row (see `plan/inu-u05-field-spec.md`) — one
 * per physical bottle, repeating. Follow with [obx] rows whose `subId` is
 * set to this row's `setId` to attach sealed/open qty, image refs, and the
 * system/counted/adjustment breakdown to this specific bottle.
 */
- (Hl7CoreInventoryCountINVBuilder *)invCountBlock:(void (^)(Hl7CoreInventoryCountINVBuilder *))block __attribute__((swift_name("invCount(block:)")));

/** Vendor cycle-count payload row (e.g. Parata robot) — repeating, distinct layout from [inv]. */
- (Hl7CoreDeviceINVBuilder *)invDeviceBlock:(void (^)(Hl7CoreDeviceINVBuilder *))block __attribute__((swift_name("invDevice(block:)")));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreOBXBuilder *)obxBlock:(void (^)(Hl7CoreOBXBuilder *))block __attribute__((swift_name("obx(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CoreZADBuilder *)zadBlock:(void (^)(Hl7CoreZADBuilder *))block __attribute__((swift_name("zad(block:)")));

/** 24-field device inventory row with GS1 — repeating, non-standard extension. */
- (Hl7CoreZCCBuilder *)zccBlock:(void (^)(Hl7CoreZCCBuilder *))block __attribute__((swift_name("zcc(block:)")));
- (Hl7CoreZINBuilder *)zinBlock:(void (^)(Hl7CoreZINBuilder *))block __attribute__((swift_name("zin(block:)")));
@end


/**
 * INV — Inventory Count Result row (standard-first redesign, INU^U05 count
 * response per `plan/inu-u05-field-spec.md`). Distinct field layout from
 * [DeviceINVBuilder] (Parata-style, no leading Set-ID) and [INVBuilder]
 * (project-compact) — all three share the wire segment name "INV"; see
 * [org.rite.hl7.model.segment.INVSegment] for how readers tell them apart.
 *
 * Wire example:
 * `INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InventoryCountINVBuilder")))
@interface Hl7CoreInventoryCountINVBuilder : Hl7CoreHL7SegmentBuilder

/**
 * INV — Inventory Count Result row (standard-first redesign, INU^U05 count
 * response per `plan/inu-u05-field-spec.md`). Distinct field layout from
 * [DeviceINVBuilder] (Parata-style, no leading Set-ID) and [INVBuilder]
 * (project-compact) — all three share the wire segment name "INV"; see
 * [org.rite.hl7.model.segment.INVSegment] for how readers tell them apart.
 *
 * Wire example:
 * `INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123`
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * INV — Inventory Count Result row (standard-first redesign, INU^U05 count
 * response per `plan/inu-u05-field-spec.md`). Distinct field layout from
 * [DeviceINVBuilder] (Parata-style, no leading Set-ID) and [INVBuilder]
 * (project-compact) — all three share the wire segment name "INV"; see
 * [org.rite.hl7.model.segment.INVSegment] for how readers tell them apart.
 *
 * Wire example:
 * `INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384||||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123`
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable codingSystem __attribute__((swift_name("codingSystem")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable gtin __attribute__((swift_name("gtin")));
@property NSString * _Nullable itemCode __attribute__((swift_name("itemCode")));
@property NSString * _Nullable itemName __attribute__((swift_name("itemName")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable quantityAvailable __attribute__((swift_name("quantityAvailable")));
@property NSString * _Nullable quantityExpected __attribute__((swift_name("quantityExpected")));
@property NSString * _Nullable quantityOnHand __attribute__((swift_name("quantityOnHand")));
@property NSString * _Nullable serialNumber __attribute__((swift_name("serialNumber")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable statusCode __attribute__((swift_name("statusCode")));
@property NSString * _Nullable statusTable __attribute__((swift_name("statusTable")));
@property NSString * _Nullable statusText __attribute__((swift_name("statusText")));
@property NSString * _Nullable typeCode __attribute__((swift_name("typeCode")));
@property NSString * _Nullable typeTable __attribute__((swift_name("typeTable")));
@property NSString * _Nullable typeText __attribute__((swift_name("typeText")));
@property NSString * _Nullable unitsCode __attribute__((swift_name("unitsCode")));
@property NSString * _Nullable unitsCodeSystem __attribute__((swift_name("unitsCodeSystem")));
@property NSString * _Nullable unitsText __attribute__((swift_name("unitsText")));
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
@property NSString * _Nullable observationText __attribute__((swift_name("observationText")));
@property NSString * _Nullable observationValue __attribute__((swift_name("observationValue")));

/** OBX-5.2 — second component of observation value (e.g. bottle count alongside a qty in observationValue). Null omits the component. */
@property NSString * _Nullable observationValue2 __attribute__((swift_name("observationValue2")));
@property NSString * _Nullable resultStatus __attribute__((swift_name("resultStatus")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));

/** OBX-4 — Observation Sub-ID. Set to a parent INV row's Set-ID (INV-1) to link this OBX to that bottle; leave null for message-level OBX rows (e.g. OPERATOR_ID/OPERATOR_NAME). */
@property NSString * _Nullable subId __attribute__((swift_name("subId")));
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


/** Receiver for [RdeO11Scope.order]'s block — delegates straight back to the owning scope. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderBlockScope")))
@interface Hl7CoreOrderBlockScope : Hl7CoreBase
- (instancetype)initWithScope:(Hl7CoreRdeO11Scope *)scope __attribute__((swift_name("init(scope:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreNTEBuilder *)nteBlock:(void (^)(Hl7CoreNTEBuilder *))block __attribute__((swift_name("nte(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CoreRXCBuilder *)rxcBlock:(void (^)(Hl7CoreRXCBuilder *))block __attribute__((swift_name("rxc(block:)")));
- (Hl7CoreRXEBuilder *)rxeBlock:(void (^)(Hl7CoreRXEBuilder *))block __attribute__((swift_name("rxe(block:)")));
- (Hl7CoreRXRBuilder *)rxrBlock:(void (^)(Hl7CoreRXRBuilder *))block __attribute__((swift_name("rxr(block:)")));
- (Hl7CoreZUIOrderBuilder *)zuiBlock:(void (^)(Hl7CoreZUIOrderBuilder *))block __attribute__((swift_name("zui(block:)")));
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
@property NSString * _Nullable dispensingProviderFamilyName __attribute__((swift_name("dispensingProviderFamilyName")));
@property NSString * _Nullable dispensingProviderGivenName __attribute__((swift_name("dispensingProviderGivenName")));
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

/**
 * Sugar for one repeating order block: equivalent to calling
 * [orc]/[rxe]/[rxr] directly in sequence. Purely for readability when
 * building a multi-order RDE^O11 message — no functional difference,
 * since segments are always appended in call order regardless.
 */
- (void)orderBlock:(void (^)(Hl7CoreOrderBlockScope *))block __attribute__((swift_name("order(block:)")));
- (Hl7CorePIDBuilder *)pidBlock:(void (^)(Hl7CorePIDBuilder *))block __attribute__((swift_name("pid(block:)")));
- (Hl7CorePV1Builder *)pv1Block:(void (^)(Hl7CorePV1Builder *))block __attribute__((swift_name("pv1(block:)")));
- (Hl7CoreRXCBuilder *)rxcBlock:(void (^)(Hl7CoreRXCBuilder *))block __attribute__((swift_name("rxc(block:)")));
- (Hl7CoreRXEBuilder *)rxeBlock:(void (^)(Hl7CoreRXEBuilder *))block __attribute__((swift_name("rxe(block:)")));
- (Hl7CoreRXRBuilder *)rxrBlock:(void (^)(Hl7CoreRXRBuilder *))block __attribute__((swift_name("rxr(block:)")));
- (Hl7CoreZUIOrderBuilder *)zuiBlock:(void (^)(Hl7CoreZUIOrderBuilder *))block __attribute__((swift_name("zui(block:)")));
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
- (Hl7CoreOBXBuilder *)obxBlock:(void (^)(Hl7CoreOBXBuilder *))block __attribute__((swift_name("obx(block:)")));
- (Hl7CoreORCBuilder *)orcBlock:(void (^)(Hl7CoreORCBuilder *))block __attribute__((swift_name("orc(block:)")));
- (Hl7CorePIDBuilder *)pidBlock:(void (^)(Hl7CorePIDBuilder *))block __attribute__((swift_name("pid(block:)")));
- (Hl7CoreRXCBuilder *)rxcBlock:(void (^)(Hl7CoreRXCBuilder *))block __attribute__((swift_name("rxc(block:)")));
- (Hl7CoreRXDBuilder *)rxdBlock:(void (^)(Hl7CoreRXDBuilder *))block __attribute__((swift_name("rxd(block:)")));
- (Hl7CoreRXEBuilder *)rxeBlock:(void (^)(Hl7CoreRXEBuilder *))block __attribute__((swift_name("rxe(block:)")));
- (Hl7CoreRXRBuilder *)rxrBlock:(void (^)(Hl7CoreRXRBuilder *))block __attribute__((swift_name("rxr(block:)")));
- (Hl7CoreZNIBuilder *)zniBlock:(void (^)(Hl7CoreZNIBuilder *))block __attribute__((swift_name("zni(block:)")));
- (Hl7CoreZSNBuilder *)zsnBlock:(void (^)(Hl7CoreZSNBuilder *))block __attribute__((swift_name("zsn(block:)")));
- (Hl7CoreZSVBuilder *)zsvBlock:(void (^)(Hl7CoreZSVBuilder *))block __attribute__((swift_name("zsv(block:)")));
- (Hl7CoreZUIDispenseBuilder *)zuiBlock:(void (^)(Hl7CoreZUIDispenseBuilder *))block __attribute__((swift_name("zui(block:)")));
@end


/** Scan/capture source values shared by ZSV-5 (scanSource) and ZSN-8 (captureSource). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScanSource")))
@interface Hl7CoreScanSource : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** Scan/capture source values shared by ZSV-5 (scanSource) and ZSN-8 (captureSource). */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)scanSource __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreScanSource *shared __attribute__((swift_name("shared")));

/** 2D DataMatrix. */
@property (readonly) NSString *GS1 __attribute__((swift_name("GS1")));
@property (readonly) NSString *MANUAL __attribute__((swift_name("MANUAL")));

/** UPC-A/GTIN linear barcode. */
@property (readonly) NSString *NDC_LINEAR __attribute__((swift_name("NDC_LINEAR")));

/** ZSN-8 only. */
@property (readonly) NSString *UNKNOWN __attribute__((swift_name("UNKNOWN")));
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
@property NSString * _Nullable comment __attribute__((swift_name("comment")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@end


/** Field positions per [org.rite.hl7.model.segment.ZCCSegment] — 24-field device inventory row with GS1. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZCCBuilder")))
@interface Hl7CoreZCCBuilder : Hl7CoreHL7SegmentBuilder

/** Field positions per [org.rite.hl7.model.segment.ZCCSegment] — 24-field device inventory row with GS1. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Field positions per [org.rite.hl7.model.segment.ZCCSegment] — 24-field device inventory row with GS1. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable cellLocation __attribute__((swift_name("cellLocation")));
@property NSString * _Nullable countStatus __attribute__((swift_name("countStatus")));
@property NSString * _Nullable drugName __attribute__((swift_name("drugName")));
@property NSString * _Nullable drugType __attribute__((swift_name("drugType")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable gtin __attribute__((swift_name("gtin")));
@property NSArray<NSString *> * _Nullable imagePaths __attribute__((swift_name("imagePaths")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable manufacturer __attribute__((swift_name("manufacturer")));
@property NSString * _Nullable manufacturerCode __attribute__((swift_name("manufacturerCode")));
@property NSString * _Nullable manufacturingDate __attribute__((swift_name("manufacturingDate")));
@property NSString * _Nullable ndcCode __attribute__((swift_name("ndcCode")));
@property NSString * _Nullable notes __attribute__((swift_name("notes")));
@property NSString * _Nullable openContainers __attribute__((swift_name("openContainers")));
@property NSString * _Nullable openCount __attribute__((swift_name("openCount")));
@property NSString * _Nullable operatorName __attribute__((swift_name("operatorName")));
@property NSString * _Nullable packageSize __attribute__((swift_name("packageSize")));
@property NSString * _Nullable reorderLevel __attribute__((swift_name("reorderLevel")));
@property NSString * _Nullable sealedContainers __attribute__((swift_name("sealedContainers")));
@property NSString * _Nullable sealedCount __attribute__((swift_name("sealedCount")));
@property NSString * _Nullable serialNumber __attribute__((swift_name("serialNumber")));
@property NSString * _Nullable stockStatus __attribute__((swift_name("stockStatus")));
@property NSString * _Nullable totalQuantity __attribute__((swift_name("totalQuantity")));
@property NSString * _Nullable unitOfMeasureCode __attribute__((swift_name("unitOfMeasureCode")));
@property NSString * _Nullable unitOfMeasureCodeSystem __attribute__((swift_name("unitOfMeasureCodeSystem")));
@property NSString * _Nullable unitOfMeasureText __attribute__((swift_name("unitOfMeasureText")));
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


/** ZNI Eyecon-to-Computer dispense result builder (fields 1-15 mirrored, result data from field 16). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZNIBuilder")))
@interface Hl7CoreZNIBuilder : Hl7CoreHL7SegmentBuilder

/** ZNI Eyecon-to-Computer dispense result builder (fields 1-15 mirrored, result data from field 16). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** ZNI Eyecon-to-Computer dispense result builder (fields 1-15 mirrored, result data from field 16). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable countType __attribute__((swift_name("countType")));
@property NSString * _Nullable dispenseAmount __attribute__((swift_name("dispenseAmount")));
@property NSString * _Nullable drugName __attribute__((swift_name("drugName")));
@property NSString * _Nullable fillNumber __attribute__((swift_name("fillNumber")));
@property NSString * _Nullable fillerOrderNumber __attribute__((swift_name("fillerOrderNumber")));
@property NSString * _Nullable mode __attribute__((swift_name("mode")));
@property NSString * _Nullable ndc __attribute__((swift_name("ndc")));
@property NSString * _Nullable packetVersion __attribute__((swift_name("packetVersion")));
@property NSString * _Nullable patientFamilyName __attribute__((swift_name("patientFamilyName")));
@property NSString * _Nullable patientGivenName __attribute__((swift_name("patientGivenName")));
@property NSString * _Nullable prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property NSString * _Nullable resultStatus __attribute__((swift_name("resultStatus")));
@property NSString * _Nullable stockBottleBarcode __attribute__((swift_name("stockBottleBarcode")));
@property NSString * _Nullable stockBottleVerification __attribute__((swift_name("stockBottleVerification")));
@property NSString * _Nullable substitutionStatus __attribute__((swift_name("substitutionStatus")));
@property NSString * _Nullable userName __attribute__((swift_name("userName")));
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
@property NSString * _Nullable captureSource __attribute__((swift_name("captureSource")));
@property NSString * _Nullable captureTimestamp __attribute__((swift_name("captureTimestamp")));
@property NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));
@property NSString * _Nullable nationalDrugCode __attribute__((swift_name("nationalDrugCode")));
@property NSString * _Nullable packageSerialNumber __attribute__((swift_name("packageSerialNumber")));
@property NSString * _Nullable quantityFromThisStockItem __attribute__((swift_name("quantityFromThisStockItem")));
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
@property NSString * _Nullable dispensedNdc __attribute__((swift_name("dispensedNdc")));
@property NSString * _Nullable matchStrength __attribute__((swift_name("matchStrength")));
@property NSString * _Nullable scanSource __attribute__((swift_name("scanSource")));
@property NSString * _Nullable scannedNdc __attribute__((swift_name("scannedNdc")));
@property NSString * _Nullable setId __attribute__((swift_name("setId")));
@property NSString * _Nullable validationResult __attribute__((swift_name("validationResult")));
@property NSString * _Nullable validationTimestamp __attribute__((swift_name("validationTimestamp")));
@property NSString * _Nullable validator __attribute__((swift_name("validator")));
@end


/** ZUI pharmacy-dispense-message builder (RDS, VIVID → PMSS). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZUIDispenseBuilder")))
@interface Hl7CoreZUIDispenseBuilder : Hl7CoreHL7SegmentBuilder

/** ZUI pharmacy-dispense-message builder (RDS, VIVID → PMSS). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** ZUI pharmacy-dispense-message builder (RDS, VIVID → PMSS). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dispensedQuantity __attribute__((swift_name("dispensedQuantity")));
@property NSString * _Nullable drugExpirationDate __attribute__((swift_name("drugExpirationDate")));
@property NSString * _Nullable drugImage __attribute__((swift_name("drugImage")));
@property NSString * _Nullable drugLotNumber __attribute__((swift_name("drugLotNumber")));
@property NSString * _Nullable drugSerialNumber __attribute__((swift_name("drugSerialNumber")));
@property NSString * _Nullable fillNumber __attribute__((swift_name("fillNumber")));
@property NSString * _Nullable ndc __attribute__((swift_name("ndc")));
@property NSString * _Nullable rxNumber __attribute__((swift_name("rxNumber")));
@property NSString * _Nullable transactionOrderId __attribute__((swift_name("transactionOrderId")));
@property NSString * _Nullable transactionStatus __attribute__((swift_name("transactionStatus")));
@property NSString * _Nullable vividUserName __attribute__((swift_name("vividUserName")));
@end


/** ZUI order-data-packet builder (RDE^O11, PMSS → VIVID). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZUIOrderBuilder")))
@interface Hl7CoreZUIOrderBuilder : Hl7CoreHL7SegmentBuilder

/** ZUI order-data-packet builder (RDE^O11, PMSS → VIVID). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** ZUI order-data-packet builder (RDE^O11, PMSS → VIVID). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)apply __attribute__((swift_name("apply()")));
@property NSString * _Nullable dispenseQuantity __attribute__((swift_name("dispenseQuantity")));
@property NSString * _Nullable drugName __attribute__((swift_name("drugName")));
@property NSString * _Nullable fillNumber __attribute__((swift_name("fillNumber")));
@property NSString * _Nullable ndc __attribute__((swift_name("ndc")));
@property NSString * _Nullable patientFamilyName __attribute__((swift_name("patientFamilyName")));
@property NSString * _Nullable patientGivenName __attribute__((swift_name("patientGivenName")));
@property NSString * _Nullable rxNumber __attribute__((swift_name("rxNumber")));
@property NSString * _Nullable transactionOrderId __attribute__((swift_name("transactionOrderId")));
@end


/** ZAD-4 default reason codes (configurable per site; open string, not a hard enum). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZadReasonCode")))
@interface Hl7CoreZadReasonCode : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** ZAD-4 default reason codes (configurable per site; open string, not a hard enum). */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)zadReasonCode __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZadReasonCode *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *BROKEN __attribute__((swift_name("BROKEN")));
@property (readonly) NSString *CYCLE_COUNT __attribute__((swift_name("CYCLE_COUNT")));
@property (readonly) NSString *DAMAGED_IN_TRANSIT __attribute__((swift_name("DAMAGED_IN_TRANSIT")));
@property (readonly) NSString *EXPIRED __attribute__((swift_name("EXPIRED")));
@property (readonly) NSString *PHYSICAL_INVENTORY __attribute__((swift_name("PHYSICAL_INVENTORY")));
@property (readonly) NSString *PO_RECEIPT __attribute__((swift_name("PO_RECEIPT")));
@property (readonly) NSString *RETURN_TO_SUPPLIER __attribute__((swift_name("RETURN_TO_SUPPLIER")));
@property (readonly) NSString *TOTALLY_MADE_UP __attribute__((swift_name("TOTALLY_MADE_UP")));
@property (readonly) NSString *TRANSFER_IN __attribute__((swift_name("TRANSFER_IN")));
@property (readonly) NSString *TRANSFER_OUT __attribute__((swift_name("TRANSFER_OUT")));
@end


/** ZSN-6 transaction type values. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZsnTransactionType")))
@interface Hl7CoreZsnTransactionType : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** ZSN-6 transaction type values. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)zsnTransactionType __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZsnTransactionType *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *DISPENSE __attribute__((swift_name("DISPENSE")));
@property (readonly) NSString *RETURN __attribute__((swift_name("RETURN")));
@end


/** ZSV-8 match strength values. Expected populated when validationResult is MATCH or SUBSTITUTION. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZsvMatchStrength")))
@interface Hl7CoreZsvMatchStrength : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** ZSV-8 match strength values. Expected populated when validationResult is MATCH or SUBSTITUTION. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)zsvMatchStrength __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZsvMatchStrength *shared __attribute__((swift_name("shared")));

/** 11-digit NDC exact match. */
@property (readonly) NSString *EXACT __attribute__((swift_name("EXACT")));

/** GPI-equivalent generic match. */
@property (readonly) NSString *GENERIC __attribute__((swift_name("GENERIC")));

/** 10-digit NDC fallback match. */
@property (readonly) NSString *NDC10 __attribute__((swift_name("NDC10")));
@end


/** ZSV-4 validation result values. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZsvValidationResult")))
@interface Hl7CoreZsvValidationResult : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** ZSV-4 validation result values. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)zsvValidationResult __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZsvValidationResult *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *MATCH __attribute__((swift_name("MATCH")));
@property (readonly) NSString *MISMATCH __attribute__((swift_name("MISMATCH")));
@property (readonly) NSString *OVERRIDE __attribute__((swift_name("OVERRIDE")));
@property (readonly) NSString *SUBSTITUTION __attribute__((swift_name("SUBSTITUTION")));
@end


/** ZUI dispense-message transaction status values (Pharmacy Dispense Message field 8). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZuiTransactionStatus")))
@interface Hl7CoreZuiTransactionStatus : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));

/** ZUI dispense-message transaction status values (Pharmacy Dispense Message field 8). */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)zuiTransactionStatus __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZuiTransactionStatus *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *CANCELLED __attribute__((swift_name("CANCELLED")));
@property (readonly) NSString *DONE __attribute__((swift_name("DONE")));
@property (readonly) NSString *OVERFILL __attribute__((swift_name("OVERFILL")));
@property (readonly) NSString *PARTIAL __attribute__((swift_name("PARTIAL")));
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

/**
 * Splits a byte stream containing one or more concatenated MLLP frames
 * (e.g. multiple messages sent back-to-back over the same MLLP connection)
 * and returns the raw HL7 message text of each frame, in order.
 *
 * An unterminated trailing frame (no EB+CR at end — network truncation or
 * partial write) is included as-is. The downstream parser will return a
 * [HL7ParseResult.Failure] for it; it does not affect other frames.
 */
- (NSArray<NSString *> *)stripAllBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("stripAll(bytes:)")));

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

/**
 * Repeating RDE^O11 order groups ({ ORC + RXE + RXR + [ZPR] }), derived
 * from [typedSegments]. Empty if the message has no ORC segment.
 */
@property (readonly) NSArray<Hl7CoreOrderGroup *> *orderGroups __attribute__((swift_name("orderGroups")));

/** The underlying generic AST segments (lossless). */
@property (readonly) NSArray<Hl7CoreHL7Segment *> *rawSegments __attribute__((swift_name("rawSegments")));
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));
@property (readonly) NSString *sequenceNumber __attribute__((swift_name("sequenceNumber")));
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
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR/TQ1 segment trailing it, up to (not including) the next ORC.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderGroup")))
@interface Hl7CoreOrderGroup : Hl7CoreBase
- (instancetype)initWithOrc:(Hl7CoreORCSegment *)orc rxe:(Hl7CoreRXESegment * _Nullable)rxe rxr:(NSArray<Hl7CoreRXRSegment *> *)rxr zpr:(NSArray<Hl7CoreZPRSegment *> *)zpr tq1:(Hl7CoreTQ1Segment * _Nullable)tq1 __attribute__((swift_name("init(orc:rxe:rxr:zpr:tq1:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreOrderGroup *)doCopyOrc:(Hl7CoreORCSegment *)orc rxe:(Hl7CoreRXESegment * _Nullable)rxe rxr:(NSArray<Hl7CoreRXRSegment *> *)rxr zpr:(NSArray<Hl7CoreZPRSegment *> *)zpr tq1:(Hl7CoreTQ1Segment * _Nullable)tq1 __attribute__((swift_name("doCopy(orc:rxe:rxr:zpr:tq1:)")));

/**
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR/TQ1 segment trailing it, up to (not including) the next ORC.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR/TQ1 segment trailing it, up to (not including) the next ORC.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * One repeating RDE^O11 order block: the ORC that anchors it plus every
 * RXE/RXR/ZPR/TQ1 segment trailing it, up to (not including) the next ORC.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Hl7CoreORCSegment *orc __attribute__((swift_name("orc")));

/** TQ1-9 -> ORC-7.6 (TQ.6) -> ZPR.priority fallback, first non-blank wins. */
@property (readonly) NSString *resolvedPriority __attribute__((swift_name("resolvedPriority")));
@property (readonly) Hl7CoreRXESegment * _Nullable rxe __attribute__((swift_name("rxe")));
@property (readonly) NSArray<Hl7CoreRXRSegment *> *rxr __attribute__((swift_name("rxr")));
@property (readonly) Hl7CoreTQ1Segment * _Nullable tq1 __attribute__((swift_name("tq1")));
@property (readonly) NSArray<Hl7CoreZPRSegment *> *zpr __attribute__((swift_name("zpr")));
@end


/**
 * Describes a custom (typically Z-) segment so the parser and builder can treat
 * it as a first-class typed segment without any core changes.
 *
 * A definition pairs the 3-char segment [name] with a [factory] that wraps a
 * generic [HL7Segment] into its typed view. Register on the parser/builder via
 * `registerCustomSegment(...)`.
 *
 * The built-in Z-segments (ZSN, ZSV, ZAD, ZIN, ZPR, ZNI) ship as ready-made
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

/** Plain value of the first component of every repetition (`~`-separated) of field [n].
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSArray<NSString *> *)repetitionsN:(int32_t)n __attribute__((swift_name("repetitions(n:)")));

/** Plain value of subcomponent [s] within component [c] of field [n] (all 1-based).
 *
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)subcomponentN:(int32_t)n c:(int32_t)c s:(int32_t)s __attribute__((swift_name("subcomponent(n:c:s:)")));

/** Highest 1-based field index present — lets callers distinguish same-named dialects by shape. */
@property (readonly) int32_t fieldCount __attribute__((swift_name("fieldCount")));
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

__attribute__((swift_name("AckCode")))
@interface Hl7CoreAckCode : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreAckCodeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.AA")))
@interface Hl7CoreAckCodeAA : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeAA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.AE")))
@interface Hl7CoreAckCodeAE : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeAE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.AR")))
@interface Hl7CoreAckCodeAR : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aR __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeAR *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.CA")))
@interface Hl7CoreAckCodeCA : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeCA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.CE")))
@interface Hl7CoreAckCodeCE : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeCE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.CR")))
@interface Hl7CoreAckCodeCR : Hl7CoreAckCode
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cR __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeCR *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.Companion")))
@interface Hl7CoreAckCodeCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreAckCodeCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreAckCode *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckCode.Unknown")))
@interface Hl7CoreAckCodeUnknown : Hl7CoreAckCode
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreAckCodeUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((swift_name("EquipmentState")))
@interface Hl7CoreEquipmentState : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreEquipmentStateCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.A")))
@interface Hl7CoreEquipmentStateA : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)a __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.CL")))
@interface Hl7CoreEquipmentStateCL : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cL __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateCL *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.CO")))
@interface Hl7CoreEquipmentStateCO : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cO __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateCO *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.Companion")))
@interface Hl7CoreEquipmentStateCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreEquipmentState *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.DC")))
@interface Hl7CoreEquipmentStateDC : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateDC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.DI")))
@interface Hl7CoreEquipmentStateDI : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dI __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateDI *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.ES")))
@interface Hl7CoreEquipmentStateES : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eS __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateES *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.I")))
@interface Hl7CoreEquipmentStateI : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)i __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateI *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.ID")))
@interface Hl7CoreEquipmentStateID : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)iD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateID *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.IN")))
@interface Hl7CoreEquipmentStateIN : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)iN __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateIN *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.OP")))
@interface Hl7CoreEquipmentStateOP : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oP __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateOP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.PA")))
@interface Hl7CoreEquipmentStatePA : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStatePA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.PD")))
@interface Hl7CoreEquipmentStatePD : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStatePD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.PU")))
@interface Hl7CoreEquipmentStatePU : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pU __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStatePU *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.RS")))
@interface Hl7CoreEquipmentStateRS : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rS __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateRS *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.UNK")))
@interface Hl7CoreEquipmentStateUNK : Hl7CoreEquipmentState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)uNK __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreEquipmentStateUNK *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquipmentState.Unknown")))
@interface Hl7CoreEquipmentStateUnknown : Hl7CoreEquipmentState
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreEquipmentStateUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((swift_name("ObsResultStatus")))
@interface Hl7CoreObsResultStatus : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreObsResultStatusCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.C")))
@interface Hl7CoreObsResultStatusC : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)c __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.Companion")))
@interface Hl7CoreObsResultStatusCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreObsResultStatus *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.D")))
@interface Hl7CoreObsResultStatusD : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)d __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.F")))
@interface Hl7CoreObsResultStatusF : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)f __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusF *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.I")))
@interface Hl7CoreObsResultStatusI : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)i __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusI *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.N")))
@interface Hl7CoreObsResultStatusN : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)n __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusN *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.O")))
@interface Hl7CoreObsResultStatusO : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)o __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusO *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.P")))
@interface Hl7CoreObsResultStatusP : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)p __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.R")))
@interface Hl7CoreObsResultStatusR : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)r __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusR *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.S")))
@interface Hl7CoreObsResultStatusS : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)s __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusS *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.U")))
@interface Hl7CoreObsResultStatusU : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)u __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusU *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.Unknown")))
@interface Hl7CoreObsResultStatusUnknown : Hl7CoreObsResultStatus
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreObsResultStatusUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.W")))
@interface Hl7CoreObsResultStatusW : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)w __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObsResultStatus.X")))
@interface Hl7CoreObsResultStatusX : Hl7CoreObsResultStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)x __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreObsResultStatusX *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("OrderControl")))
@interface Hl7CoreOrderControl : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreOrderControlCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.AF")))
@interface Hl7CoreOrderControlAF : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aF __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlAF *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.CA")))
@interface Hl7CoreOrderControlCA : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlCA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.Companion")))
@interface Hl7CoreOrderControlCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreOrderControl *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.DC")))
@interface Hl7CoreOrderControlDC : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlDC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.DF")))
@interface Hl7CoreOrderControlDF : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dF __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlDF *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.FU")))
@interface Hl7CoreOrderControlFU : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)fU __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlFU *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.HD")))
@interface Hl7CoreOrderControlHD : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlHD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.NW")))
@interface Hl7CoreOrderControlNW : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)nW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlNW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.OC")))
@interface Hl7CoreOrderControlOC : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlOC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.OD")))
@interface Hl7CoreOrderControlOD : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlOD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.OH")))
@interface Hl7CoreOrderControlOH : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oH __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlOH *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.OK")))
@interface Hl7CoreOrderControlOK : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oK __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlOK *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.RE")))
@interface Hl7CoreOrderControlRE : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlRE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.RF")))
@interface Hl7CoreOrderControlRF : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rF __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlRF *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.RO")))
@interface Hl7CoreOrderControlRO : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rO __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlRO *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.RP")))
@interface Hl7CoreOrderControlRP : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rP __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlRP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.SC")))
@interface Hl7CoreOrderControlSC : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlSC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.UA")))
@interface Hl7CoreOrderControlUA : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)uA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlUA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.Unknown")))
@interface Hl7CoreOrderControlUnknown : Hl7CoreOrderControl
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreOrderControlUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderControl.XO")))
@interface Hl7CoreOrderControlXO : Hl7CoreOrderControl
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)xO __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderControlXO *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("OrderStatus")))
@interface Hl7CoreOrderStatus : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreOrderStatusCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.A")))
@interface Hl7CoreOrderStatusA : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)a __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.CA")))
@interface Hl7CoreOrderStatusCA : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cA __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusCA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.CM")))
@interface Hl7CoreOrderStatusCM : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cM __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusCM *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.Companion")))
@interface Hl7CoreOrderStatusCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreOrderStatus *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.DC")))
@interface Hl7CoreOrderStatusDC : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusDC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.ER")))
@interface Hl7CoreOrderStatusER : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eR __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusER *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.HD")))
@interface Hl7CoreOrderStatusHD : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusHD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.IP")))
@interface Hl7CoreOrderStatusIP : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)iP __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusIP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.RP")))
@interface Hl7CoreOrderStatusRP : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rP __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusRP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.SC")))
@interface Hl7CoreOrderStatusSC : Hl7CoreOrderStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sC __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreOrderStatusSC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus.Unknown")))
@interface Hl7CoreOrderStatusUnknown : Hl7CoreOrderStatus
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreOrderStatusUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((swift_name("Priority")))
@interface Hl7CorePriority : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CorePriorityCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.A")))
@interface Hl7CorePriorityA : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)a __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityA *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.C")))
@interface Hl7CorePriorityC : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)c __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityC *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.Companion")))
@interface Hl7CorePriorityCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CorePriority *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.P")))
@interface Hl7CorePriorityP : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)p __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityP *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.PRN")))
@interface Hl7CorePriorityPRN : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pRN __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityPRN *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.R")))
@interface Hl7CorePriorityR : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)r __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityR *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.S")))
@interface Hl7CorePriorityS : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)s __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityS *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.T")))
@interface Hl7CorePriorityT : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)t __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityT *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.UD")))
@interface Hl7CorePriorityUD : Hl7CorePriority
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)uD __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CorePriorityUD *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Priority.Unknown")))
@interface Hl7CorePriorityUnknown : Hl7CorePriority
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CorePriorityUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((swift_name("SubstanceStatus")))
@interface Hl7CoreSubstanceStatus : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreSubstanceStatusCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.CE")))
@interface Hl7CoreSubstanceStatusCE : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusCE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.CW")))
@interface Hl7CoreSubstanceStatusCW : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusCW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.Companion")))
@interface Hl7CoreSubstanceStatusCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreSubstanceStatus *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.EE")))
@interface Hl7CoreSubstanceStatusEE : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusEE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.EW")))
@interface Hl7CoreSubstanceStatusEW : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusEW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.NE")))
@interface Hl7CoreSubstanceStatusNE : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)nE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusNE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.NW")))
@interface Hl7CoreSubstanceStatusNW : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)nW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusNW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.OE")))
@interface Hl7CoreSubstanceStatusOE : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusOE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.OK")))
@interface Hl7CoreSubstanceStatusOK : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oK __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusOK *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.OW")))
@interface Hl7CoreSubstanceStatusOW : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusOW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.QE")))
@interface Hl7CoreSubstanceStatusQE : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)qE __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusQE *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.QW")))
@interface Hl7CoreSubstanceStatusQW : Hl7CoreSubstanceStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)qW __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstanceStatusQW *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstanceStatus.Unknown")))
@interface Hl7CoreSubstanceStatusUnknown : Hl7CoreSubstanceStatus
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreSubstanceStatusUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end

__attribute__((swift_name("SubstitutionStatus")))
@interface Hl7CoreSubstitutionStatus : Hl7CoreBase
@property (class, readonly, getter=companion) Hl7CoreSubstitutionStatusCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *code __attribute__((swift_name("code")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.BrandAsGeneric")))
@interface Hl7CoreSubstitutionStatusBrandAsGeneric : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)brandAsGeneric __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusBrandAsGeneric *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.BrandMandatedByLaw")))
@interface Hl7CoreSubstitutionStatusBrandMandatedByLaw : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)brandMandatedByLaw __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusBrandMandatedByLaw *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.Companion")))
@interface Hl7CoreSubstitutionStatusCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreSubstitutionStatus *)fromRaw:(NSString *)raw __attribute__((swift_name("from(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.G")))
@interface Hl7CoreSubstitutionStatusG : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)g __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusG *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.GenericNotAvailable")))
@interface Hl7CoreSubstitutionStatusGenericNotAvailable : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)genericNotAvailable __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusGenericNotAvailable *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.GenericNotInStock")))
@interface Hl7CoreSubstitutionStatusGenericNotInStock : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)genericNotInStock __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusGenericNotInStock *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.N")))
@interface Hl7CoreSubstitutionStatusN : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)n __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusN *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.NoSelection")))
@interface Hl7CoreSubstitutionStatusNoSelection : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)noSelection __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusNoSelection *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.NotAllowed")))
@interface Hl7CoreSubstitutionStatusNotAllowed : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)notAllowed __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusNotAllowed *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.PatientRequested")))
@interface Hl7CoreSubstitutionStatusPatientRequested : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)patientRequested __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusPatientRequested *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.PharmacistSelected")))
@interface Hl7CoreSubstitutionStatusPharmacistSelected : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pharmacistSelected __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusPharmacistSelected *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.T")))
@interface Hl7CoreSubstitutionStatusT : Hl7CoreSubstitutionStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)t __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreSubstitutionStatusT *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubstitutionStatus.Unknown")))
@interface Hl7CoreSubstitutionStatusUnknown : Hl7CoreSubstitutionStatus
- (instancetype)initWithRaw:(NSString *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
- (Hl7CoreSubstitutionStatusUnknown *)doCopyRaw:(NSString *)raw __attribute__((swift_name("doCopy(raw:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *raw __attribute__((swift_name("raw")));
@end


/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4), used inline in
 * fields like ORC-7. Every component is a plain String (raw, "" if absent);
 * [explicitTimes] is the one structured extra, and it degrades to an empty
 * list rather than throwing when TQ.2 doesn't have the expected shape.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TQ")))
@interface Hl7CoreTQ : Hl7CoreBase
- (instancetype)initWithQuantity:(NSString *)quantity interval:(NSString *)interval intervalCode:(NSString *)intervalCode explicitTimes:(NSArray<NSString *> *)explicitTimes duration:(NSString *)duration startDateTime:(NSString *)startDateTime endDateTime:(NSString *)endDateTime priority:(NSString *)priority condition:(NSString *)condition text:(NSString *)text conjunction:(NSString *)conjunction orderSequencing:(NSString *)orderSequencing occurrenceDuration:(NSString *)occurrenceDuration totalOccurrences:(NSString *)totalOccurrences __attribute__((swift_name("init(quantity:interval:intervalCode:explicitTimes:duration:startDateTime:endDateTime:priority:condition:text:conjunction:orderSequencing:occurrenceDuration:totalOccurrences:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreTQCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreTQ *)doCopyQuantity:(NSString *)quantity interval:(NSString *)interval intervalCode:(NSString *)intervalCode explicitTimes:(NSArray<NSString *> *)explicitTimes duration:(NSString *)duration startDateTime:(NSString *)startDateTime endDateTime:(NSString *)endDateTime priority:(NSString *)priority condition:(NSString *)condition text:(NSString *)text conjunction:(NSString *)conjunction orderSequencing:(NSString *)orderSequencing occurrenceDuration:(NSString *)occurrenceDuration totalOccurrences:(NSString *)totalOccurrences __attribute__((swift_name("doCopy(quantity:interval:intervalCode:explicitTimes:duration:startDateTime:endDateTime:priority:condition:text:conjunction:orderSequencing:occurrenceDuration:totalOccurrences:)")));

/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4), used inline in
 * fields like ORC-7. Every component is a plain String (raw, "" if absent);
 * [explicitTimes] is the one structured extra, and it degrades to an empty
 * list rather than throwing when TQ.2 doesn't have the expected shape.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4), used inline in
 * fields like ORC-7. Every component is a plain String (raw, "" if absent);
 * [explicitTimes] is the one structured extra, and it degrades to an empty
 * list rather than throwing when TQ.2 doesn't have the expected shape.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * TQ — Timing/Quantity (legacy composite, HL7 v2.3/2.4), used inline in
 * fields like ORC-7. Every component is a plain String (raw, "" if absent);
 * [explicitTimes] is the one structured extra, and it degrades to an empty
 * list rather than throwing when TQ.2 doesn't have the expected shape.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *condition __attribute__((swift_name("condition")));
@property (readonly) NSString *conjunction __attribute__((swift_name("conjunction")));
@property (readonly) NSString *duration __attribute__((swift_name("duration")));
@property (readonly) NSString *endDateTime __attribute__((swift_name("endDateTime")));
@property (readonly) NSArray<NSString *> *explicitTimes __attribute__((swift_name("explicitTimes")));
@property (readonly) NSString *interval __attribute__((swift_name("interval")));
@property (readonly) NSString *intervalCode __attribute__((swift_name("intervalCode")));

/** No end date and no total-occurrences cap -> schedule runs until cancelled. */
@property (readonly) BOOL isOpenEnded __attribute__((swift_name("isOpenEnded")));

/** TQ.9 = "S" (sequential) — TQ.10 should carry the predecessor link. */
@property (readonly) BOOL isSequential __attribute__((swift_name("isSequential")));
@property (readonly) NSString *occurrenceDuration __attribute__((swift_name("occurrenceDuration")));
@property (readonly) NSString *orderSequencing __attribute__((swift_name("orderSequencing")));
@property (readonly) NSString *priority __attribute__((swift_name("priority")));
@property (readonly) NSString *quantity __attribute__((swift_name("quantity")));
@property (readonly) NSString *startDateTime __attribute__((swift_name("startDateTime")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@property (readonly) NSString *totalOccurrences __attribute__((swift_name("totalOccurrences")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TQ.Companion")))
@interface Hl7CoreTQCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreTQCompanion *shared __attribute__((swift_name("shared")));
- (Hl7CoreTQ *)parseField:(Hl7CoreHL7Field *)field __attribute__((swift_name("parse(field:)")));
@end


/**
 * BTS — Batch Trailer Segment (standard HL7 v2 control segment).
 *
 * Used here as a per-message trailer (not inside a BHS/BTS batch envelope,
 * since the receiving PMS parses one MSH-rooted message per MLLP frame) to
 * mark a large inventory sync split across multiple independently-ACKed
 * messages: which chunk this is, of how many, and this chunk's item total.
 *
 * Field map (per HL7 v2.5.1 Control chapter) — all three fields are numeric:
 * `BTS|batchMessageCount|batchTotalChunks|batchTotals`
 * - BTS-1 Batch Message Count — this chunk's 1-based index within the sync.
 * - BTS-2 Batch Comment — repurposed here to carry the total chunk count for
 *   this sync (a number, e.g. "10"), not free text.
 * - BTS-3 Batch Totals — this chunk's item total (repeatable per spec).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BTSSegment")))
@interface Hl7CoreBTSSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreBTSSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *batchComment __attribute__((swift_name("batchComment")));
@property (readonly) NSString *batchMessageCount __attribute__((swift_name("batchMessageCount")));
@property (readonly) NSString *batchTotals __attribute__((swift_name("batchTotals")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BTSSegment.Companion")))
@interface Hl7CoreBTSSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreBTSSegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * EQU — Equipment Detail. Standard HL7 EQU-1 is the equipment identifier
 * itself (no leading Set-ID) — but every wire example in
 * `plan/inventory/HL7_v2_5_1_INR_U06_Official_Specification.md` (and real
 * devices following it) prefixes a bare sequence number before the ID
 * composite. Detect which shape this row uses: a leading Set-ID is present
 * when field 1 has no second component (a bare value, not composite) while
 * field 2 does — i.e. field 2 looks like the real ID, not field 1.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EQUSegment")))
@interface Hl7CoreEQUSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreEQUSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *alertLevel __attribute__((swift_name("alertLevel")));
@property (readonly) NSString *equipmentId __attribute__((swift_name("equipmentId")));
@property (readonly) Hl7CoreEquipmentState *equipmentState __attribute__((swift_name("equipmentState")));
@property (readonly) NSString *equipmentStateRaw __attribute__((swift_name("equipmentStateRaw")));
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
 * INV — Inventory Detail. The "INV" segment name is reused for three unrelated
 * vendor/project field maps — direction/dialect isn't in MSH-9 here (all three
 * appear under INU^U05 / INR^U05), so callers distinguish by shape:
 * - compact layout never sets past field 6
 * - device-sync (Parata) layout has NO leading Set-ID, item identifier at field 1
 * - count-result layout (this project's standard-first redesign) HAS a leading
 *   Set-ID and its item identifier composite is at field 2, not field 1
 * Check [fieldCount] and whether field 1 parses as a composite item identifier
 * vs. a bare Set-ID before deciding which accessor group applies.
 *
 * Compact layout (project-specific, warehouse/PMS inventory sync). Wire example:
 * `INV|1|00069015505^Drug Name^NDC|LOT-A|20251201|150|EA`
 * - INV-1 Set ID
 * - INV-2 Substance Identifier (CE) — NDC^name^codingSystem
 * - INV-3 Lot Number
 * - INV-4 Expiration Date
 * - INV-5 On-Hand Quantity
 * - INV-6 Quantity Units
 *
 * Device Inventory Sync layout (vendor cycle-count payload, e.g. Parata
 * robot INU^U05, no leading Set-ID). Wire example:
 * `INV|NDC001^LISINOPRIL 10MG^L|A^Active^HL70383|DRUG^Drug^HL70384|CELL_A1^Cell A1^L|||55|55|55|1|TAB^Tablets^UCUM|20260131|||LOTLIS001`
 * - INV-1 Item Identifier — NDC^name^codingSystem
 * - INV-2 Status — code^text^table
 * - INV-3 Item Type — code^text^table
 * - INV-4 Location — code^text
 * - INV-7/8/9 Quantity on hand / available / expected
 * - INV-10 Package size
 * - INV-11 Units — code^text^codeSystem
 * - INV-12 Expiration date
 * - INV-15 Lot number
 *
 * Count-Result layout (standard-first INU^U05 count response, see
 * `plan/inu-u05-field-spec.md`; built by [org.rite.hl7.builder.InventoryCountINVBuilder]).
 * Wire example:
 * `INV|1|00009-5134-03^LISINOPRIL 10MG TAB^L^SERIAL001^00300095134032|A^Active^HL70383|DRUG^Drug^HL70384|||50|50|50|TAB^Tablets^UCUM|20280630||||ABC123`
 * - INV-1 Set ID — every child OBX's OBX-4 points back at this value
 * - INV-2 Item Identifier — NDC^name^codingSystem^serial^GTIN
 * - INV-3 Status — code^text^table
 * - INV-4 Item Type — code^text^table
 * - INV-7/8/9 Quantity on hand / available / expected
 * - INV-10 Units — code^text^codeSystem
 * - INV-12 Expiration date
 * - INV-15 Lot number
 *
 * Bottle identity = INV-2.1 (NDC) + INV-15 (lot) + INV-12 (expiry) + INV-2.4
 * (serial), all four together — two rows sharing an NDC but differing in
 * lot/expiry/serial are distinct bottles, never merged.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVSegment")))
@interface Hl7CoreINVSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreINVSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *countCodingSystem __attribute__((swift_name("countCodingSystem")));
@property (readonly) NSString *countExpirationDate __attribute__((swift_name("countExpirationDate")));
@property (readonly) NSString *countGtin __attribute__((swift_name("countGtin")));
@property (readonly) NSString *countItemCode __attribute__((swift_name("countItemCode")));
@property (readonly) NSString *countItemName __attribute__((swift_name("countItemName")));
@property (readonly) NSString *countLotNumber __attribute__((swift_name("countLotNumber")));
@property (readonly) NSString *countQuantityAvailable __attribute__((swift_name("countQuantityAvailable")));
@property (readonly) NSString *countQuantityExpected __attribute__((swift_name("countQuantityExpected")));
@property (readonly) NSString *countQuantityOnHand __attribute__((swift_name("countQuantityOnHand")));

/** Serial number — distinguishes two otherwise-identical bottles (same NDC/lot/expiry). */
@property (readonly) NSString *countSerialNumber __attribute__((swift_name("countSerialNumber")));
@property (readonly) NSString *countSetId __attribute__((swift_name("countSetId")));
@property (readonly) NSString *countStatusCode __attribute__((swift_name("countStatusCode")));
@property (readonly) NSString *countTypeCode __attribute__((swift_name("countTypeCode")));
@property (readonly) NSString *countUnitsCode __attribute__((swift_name("countUnitsCode")));
@property (readonly) NSString *countUnitsText __attribute__((swift_name("countUnitsText")));
@property (readonly) NSString *deviceExpirationDate __attribute__((swift_name("deviceExpirationDate")));
@property (readonly) NSString *deviceItemName __attribute__((swift_name("deviceItemName")));
@property (readonly) NSString *deviceLocationCode __attribute__((swift_name("deviceLocationCode")));
@property (readonly) NSString *deviceLocationText __attribute__((swift_name("deviceLocationText")));
@property (readonly) NSString *deviceLotNumber __attribute__((swift_name("deviceLotNumber")));
@property (readonly) NSString *devicePackageSize __attribute__((swift_name("devicePackageSize")));
@property (readonly) NSString *deviceQuantityAvailable __attribute__((swift_name("deviceQuantityAvailable")));
@property (readonly) NSString *deviceQuantityExpected __attribute__((swift_name("deviceQuantityExpected")));
@property (readonly) NSString *deviceQuantityOnHand __attribute__((swift_name("deviceQuantityOnHand")));
@property (readonly) NSString *deviceTypeCode __attribute__((swift_name("deviceTypeCode")));
@property (readonly) NSString *deviceUnitsCode __attribute__((swift_name("deviceUnitsCode")));
@property (readonly) NSString *deviceUnitsText __attribute__((swift_name("deviceUnitsText")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *inventoryOnHandQuantity __attribute__((swift_name("inventoryOnHandQuantity")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *substanceCode __attribute__((swift_name("substanceCode")));
@property (readonly) NSString *substanceCodeSystem __attribute__((swift_name("substanceCodeSystem")));
@property (readonly) NSString *substanceIdentifier __attribute__((swift_name("substanceIdentifier")));
@property (readonly) NSString *substanceName __attribute__((swift_name("substanceName")));
@property (readonly) Hl7CoreSubstanceStatus *substanceStatus __attribute__((swift_name("substanceStatus")));
@property (readonly) NSString *substanceStatusRaw __attribute__((swift_name("substanceStatusRaw")));
@property (readonly) NSString *units __attribute__((swift_name("units")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("INVSegment.Companion")))
@interface Hl7CoreINVSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreINVSegmentCompanion *shared __attribute__((swift_name("shared")));

/** Compact rows never populate past field 6; device-sync/count-result rows run to field 15. */
@property (readonly) int32_t DEVICE_SYNC_FIELD_THRESHOLD __attribute__((swift_name("DEVICE_SYNC_FIELD_THRESHOLD")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/** MSA — Message Acknowledgement. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MSASegment")))
@interface Hl7CoreMSASegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreMSASegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) Hl7CoreAckCode *acknowledgmentCode __attribute__((swift_name("acknowledgmentCode")));
@property (readonly) NSString *acknowledgmentCodeRaw __attribute__((swift_name("acknowledgmentCodeRaw")));
@property (readonly) NSString *delayedAcknowledgmentType __attribute__((swift_name("delayedAcknowledgmentType")));
@property (readonly) NSString *errorCondition __attribute__((swift_name("errorCondition")));
@property (readonly) NSString *expectedSequenceNumber __attribute__((swift_name("expectedSequenceNumber")));
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
@property (readonly) NSString *acceptAcknowledgmentType __attribute__((swift_name("acceptAcknowledgmentType")));
@property (readonly) NSString *applicationAcknowledgmentType __attribute__((swift_name("applicationAcknowledgmentType")));
@property (readonly) NSString *continuationPointer __attribute__((swift_name("continuationPointer")));
@property (readonly) NSString *countryCode __attribute__((swift_name("countryCode")));
@property (readonly) NSString *dateTimeOfMessage __attribute__((swift_name("dateTimeOfMessage")));
@property (readonly) NSString *encodingCharacters __attribute__((swift_name("encodingCharacters")));
@property (readonly) NSString *fieldSeparator __attribute__((swift_name("fieldSeparator")));
@property (readonly) NSString *messageCode __attribute__((swift_name("messageCode")));
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));
@property (readonly) NSString *messageStructure __attribute__((swift_name("messageStructure")));
@property (readonly) NSString *messageType __attribute__((swift_name("messageType")));
@property (readonly) NSString *processingId __attribute__((swift_name("processingId")));
@property (readonly) NSString *receivingApplication __attribute__((swift_name("receivingApplication")));
@property (readonly) NSString *receivingFacility __attribute__((swift_name("receivingFacility")));
@property (readonly) NSString *security __attribute__((swift_name("security")));
@property (readonly) NSString *sendingApplication __attribute__((swift_name("sendingApplication")));
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));
@property (readonly) NSString *sequenceNumber __attribute__((swift_name("sequenceNumber")));
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
@property (readonly) NSString *dateTimeOfAnalysis __attribute__((swift_name("dateTimeOfAnalysis")));
@property (readonly) NSString *dateTimeOfObservation __attribute__((swift_name("dateTimeOfObservation")));
@property (readonly) NSString *effectiveDateOfReferenceRange __attribute__((swift_name("effectiveDateOfReferenceRange")));
@property (readonly) NSString *equipmentInstance __attribute__((swift_name("equipmentInstance")));
@property (readonly) NSString *observationCodeSystem __attribute__((swift_name("observationCodeSystem")));
@property (readonly) NSString *observationId __attribute__((swift_name("observationId")));
@property (readonly) NSString *observationMethod __attribute__((swift_name("observationMethod")));
@property (readonly) NSString *observationSubId __attribute__((swift_name("observationSubId")));
@property (readonly) NSString *observationText __attribute__((swift_name("observationText")));
@property (readonly) NSString *observationValue __attribute__((swift_name("observationValue")));
@property (readonly) NSString *producersId __attribute__((swift_name("producersId")));
@property (readonly) NSString *referenceRange __attribute__((swift_name("referenceRange")));
@property (readonly) NSString *responsibleObserver __attribute__((swift_name("responsibleObserver")));
@property (readonly) Hl7CoreObsResultStatus *resultStatus __attribute__((swift_name("resultStatus")));
@property (readonly) NSString *resultStatusRaw __attribute__((swift_name("resultStatusRaw")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *units __attribute__((swift_name("units")));
@property (readonly) NSString *userDefinedAccessChecks __attribute__((swift_name("userDefinedAccessChecks")));
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
@property (readonly) NSString *enteringOrganization __attribute__((swift_name("enteringOrganization")));
@property (readonly) NSString *fillerOrderNamespace __attribute__((swift_name("fillerOrderNamespace")));
@property (readonly) NSString *fillerOrderNumber __attribute__((swift_name("fillerOrderNumber")));
@property (readonly) Hl7CoreOrderControl *orderControl __attribute__((swift_name("orderControl")));
@property (readonly) NSString *orderControlRaw __attribute__((swift_name("orderControlRaw")));
@property (readonly) NSString *orderEffectiveDateTime __attribute__((swift_name("orderEffectiveDateTime")));
@property (readonly) Hl7CoreOrderStatus *orderStatus __attribute__((swift_name("orderStatus")));
@property (readonly) NSString *orderStatusRaw __attribute__((swift_name("orderStatusRaw")));
@property (readonly) NSString *orderingFacility __attribute__((swift_name("orderingFacility")));
@property (readonly) NSString *orderingProviderFamilyName __attribute__((swift_name("orderingProviderFamilyName")));
@property (readonly) NSString *orderingProviderGivenName __attribute__((swift_name("orderingProviderGivenName")));
@property (readonly) NSString *orderingProviderId __attribute__((swift_name("orderingProviderId")));
@property (readonly) NSString *placerOrderNamespace __attribute__((swift_name("placerOrderNamespace")));
@property (readonly) NSString *placerOrderNumber __attribute__((swift_name("placerOrderNumber")));
@property (readonly) Hl7CoreTQ *quantityTiming __attribute__((swift_name("quantityTiming")));
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
- (NSArray<NSString *> *)patientIdList __attribute__((swift_name("patientIdList()")));
@property (readonly) NSString *city __attribute__((swift_name("city")));
@property (readonly) NSString *country __attribute__((swift_name("country")));
@property (readonly) NSString *dateOfBirth __attribute__((swift_name("dateOfBirth")));
@property (readonly) NSString *familyName __attribute__((swift_name("familyName")));
@property (readonly) NSString *givenName __attribute__((swift_name("givenName")));
@property (readonly) NSString *maritalStatus __attribute__((swift_name("maritalStatus")));
@property (readonly) NSString *middleName __attribute__((swift_name("middleName")));
@property (readonly) NSString *patientAccountNumber __attribute__((swift_name("patientAccountNumber")));
@property (readonly) NSString *patientId __attribute__((swift_name("patientId")));
@property (readonly) NSString *patientIdAssigningAuthority __attribute__((swift_name("patientIdAssigningAuthority")));
@property (readonly) NSString *patientIdType __attribute__((swift_name("patientIdType")));
@property (readonly) NSString *phoneBusiness __attribute__((swift_name("phoneBusiness")));
@property (readonly) NSString *phoneHome __attribute__((swift_name("phoneHome")));
@property (readonly) NSString *primaryLanguage __attribute__((swift_name("primaryLanguage")));
@property (readonly) NSString *race __attribute__((swift_name("race")));
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
@property (readonly) NSString *dischargeDatetime __attribute__((swift_name("dischargeDatetime")));
@property (readonly) NSString *dischargeDisposition __attribute__((swift_name("dischargeDisposition")));
@property (readonly) NSString *facility __attribute__((swift_name("facility")));
@property (readonly) NSString *hospitalService __attribute__((swift_name("hospitalService")));
@property (readonly) NSString *patientClass __attribute__((swift_name("patientClass")));
@property (readonly) NSString *pointOfCare __attribute__((swift_name("pointOfCare")));
@property (readonly) NSString *readmissionIndicator __attribute__((swift_name("readmissionIndicator")));
@property (readonly) NSString *referringDoctorFamilyName __attribute__((swift_name("referringDoctorFamilyName")));
@property (readonly) NSString *referringDoctorId __attribute__((swift_name("referringDoctorId")));
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
@property (readonly) NSString *componentDrugStrengthVolume __attribute__((swift_name("componentDrugStrengthVolume")));
@property (readonly) NSString *componentName __attribute__((swift_name("componentName")));
@property (readonly) NSString *componentStrength __attribute__((swift_name("componentStrength")));
@property (readonly) NSString *componentStrengthUnits __attribute__((swift_name("componentStrengthUnits")));
@property (readonly) NSString *componentType __attribute__((swift_name("componentType")));
@property (readonly) NSString *componentUnitsCode __attribute__((swift_name("componentUnitsCode")));
@property (readonly) NSString *componentUnitsText __attribute__((swift_name("componentUnitsText")));
@property (readonly) NSString *supplementaryCode __attribute__((swift_name("supplementaryCode")));
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
@property (readonly) NSString *dispensingProviderId __attribute__((swift_name("dispensingProviderId")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *pharmacyOrderType __attribute__((swift_name("pharmacyOrderType")));
@property (readonly) NSString *prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property (readonly) NSString *substanceManufacturerName __attribute__((swift_name("substanceManufacturerName")));
@property (readonly) Hl7CoreSubstitutionStatus *substitutionStatus __attribute__((swift_name("substitutionStatus")));
@property (readonly) NSString *substitutionStatusRaw __attribute__((swift_name("substitutionStatusRaw")));
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
@property (readonly) NSString *controlledSubstanceSchedule __attribute__((swift_name("controlledSubstanceSchedule")));
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
@property (readonly) NSString *orderingProviderDeaNumber __attribute__((swift_name("orderingProviderDeaNumber")));
@property (readonly) NSString *prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property (readonly) NSString *providerAdministrationInstructions __attribute__((swift_name("providerAdministrationInstructions")));
@property (readonly) Hl7CoreSubstitutionStatus *substitutionStatus __attribute__((swift_name("substitutionStatus")));
@property (readonly) NSString *substitutionStatusRaw __attribute__((swift_name("substitutionStatusRaw")));
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
@property (readonly) NSString *administrationMethod __attribute__((swift_name("administrationMethod")));
@property (readonly) NSString *administrationSiteCode __attribute__((swift_name("administrationSiteCode")));
@property (readonly) NSString *administrationSiteText __attribute__((swift_name("administrationSiteText")));
@property (readonly) NSString *routeCode __attribute__((swift_name("routeCode")));
@property (readonly) NSString *routeCodeSystem __attribute__((swift_name("routeCodeSystem")));
@property (readonly) NSString *routeText __attribute__((swift_name("routeText")));
@property (readonly) NSString *routingInstruction __attribute__((swift_name("routingInstruction")));
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


/** TQ1 — Timing/Quantity (standalone, HL7 v2.5+). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TQ1Segment")))
@interface Hl7CoreTQ1Segment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreTQ1SegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *condition __attribute__((swift_name("condition")));
@property (readonly) NSString *conjunction __attribute__((swift_name("conjunction")));
@property (readonly) NSString *endDateTime __attribute__((swift_name("endDateTime")));
@property (readonly) NSString *explicitTime __attribute__((swift_name("explicitTime")));
@property (readonly) NSString *occurrenceDuration __attribute__((swift_name("occurrenceDuration")));
@property (readonly) Hl7CorePriority *priority __attribute__((swift_name("priority")));
@property (readonly) NSString *priorityRaw __attribute__((swift_name("priorityRaw")));
@property (readonly) NSString *quantity __attribute__((swift_name("quantity")));
@property (readonly) NSString *relativeTimeAndUnits __attribute__((swift_name("relativeTimeAndUnits")));
@property (readonly) NSString *repeatPattern __attribute__((swift_name("repeatPattern")));
@property (readonly) NSString *serviceDuration __attribute__((swift_name("serviceDuration")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *startDateTime __attribute__((swift_name("startDateTime")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@property (readonly) NSString *totalOccurrences __attribute__((swift_name("totalOccurrences")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TQ1Segment.Companion")))
@interface Hl7CoreTQ1SegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreTQ1SegmentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Hl7CoreSegmentDefinition *Definition __attribute__((swift_name("Definition")));
@property (readonly) NSString *NAME __attribute__((swift_name("NAME")));
@end


/**
 * ZAD — Inventory Adjustment. New §11 extension.
 *
 * Field map (project-authoritative):
 * `ZAD|setId|adjustmentType|adjustmentQuantity|adjustmentReason|adjustmentDateTime|approvedBy|comment`
 * adjustmentType (sign): + add, - subtract, O overwrite QOH.
 * adjustmentReason: see [org.rite.hl7.builder.ZadReasonCode] for default site reason codes.
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
@property (readonly) NSString *comment __attribute__((swift_name("comment")));
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
 * ZCC — Device Inventory Row with GS1 (24-field vendor cycle-count payload,
 * e.g. Parata robot). Flattens what the [INVSegment]/[OBXSegment] device-sync
 * pair split across multiple segments into one row per drug. New extension.
 *
 * Field map (project-authoritative):
 * `ZCC|ndcCode|drugName|drugType|manufacturer|manufacturerCode|gtin|cellLocation|totalQuantity|sealedCount|sealedContainers|openCount|openContainers|lotNumber|serialNumber|expirationDate|manufacturingDate|unitOfMeasure|packageSize|reorderLevel|stockStatus|imagePaths|countStatus|operatorName|notes`
 * drugType: TABLET / CAPSULE / LIQUID / INJECTION.
 * unitOfMeasure: CE — code^text^codingSystem (e.g. "TAB^Tablets^UCUM").
 * stockStatus: OK / LOW / CRITICAL / EMPTY.
 * imagePaths: `~`-repeated (standard HL7 repetition separator) — see [imagePaths].
 * countStatus: COMPLETE / IN_PROGRESS / EMPTY.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZCCSegment")))
@interface Hl7CoreZCCSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZCCSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *cellLocation __attribute__((swift_name("cellLocation")));
@property (readonly) NSString *countStatus __attribute__((swift_name("countStatus")));
@property (readonly) NSString *drugName __attribute__((swift_name("drugName")));
@property (readonly) NSString *drugType __attribute__((swift_name("drugType")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *gtin __attribute__((swift_name("gtin")));
@property (readonly) NSArray<NSString *> *imagePaths __attribute__((swift_name("imagePaths")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *manufacturer __attribute__((swift_name("manufacturer")));
@property (readonly) NSString *manufacturerCode __attribute__((swift_name("manufacturerCode")));
@property (readonly) NSString *manufacturingDate __attribute__((swift_name("manufacturingDate")));
@property (readonly) NSString *ndcCode __attribute__((swift_name("ndcCode")));
@property (readonly) NSString *notes __attribute__((swift_name("notes")));
@property (readonly) NSString *openContainers __attribute__((swift_name("openContainers")));
@property (readonly) NSString *openCount __attribute__((swift_name("openCount")));
@property (readonly) NSString *operatorName __attribute__((swift_name("operatorName")));
@property (readonly) NSString *packageSize __attribute__((swift_name("packageSize")));
@property (readonly) NSString *reorderLevel __attribute__((swift_name("reorderLevel")));
@property (readonly) NSString *sealedContainers __attribute__((swift_name("sealedContainers")));
@property (readonly) NSString *sealedCount __attribute__((swift_name("sealedCount")));
@property (readonly) NSString *serialNumber __attribute__((swift_name("serialNumber")));
@property (readonly) NSString *stockStatus __attribute__((swift_name("stockStatus")));
@property (readonly) NSString *totalQuantity __attribute__((swift_name("totalQuantity")));
@property (readonly) NSString *unitOfMeasureCode __attribute__((swift_name("unitOfMeasureCode")));
@property (readonly) NSString *unitOfMeasureCodeSystem __attribute__((swift_name("unitOfMeasureCodeSystem")));
@property (readonly) NSString *unitOfMeasureText __attribute__((swift_name("unitOfMeasureText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZCCSegment.Companion")))
@interface Hl7CoreZCCSegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZCCSegmentCompanion *shared __attribute__((swift_name("shared")));

/** Register on parser/builder via `registerCustomSegment(ZCCSegment.Definition)`. */
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
 * ZNI — Eyecon Native Interface order packet (Computer → Eyecon, "CtoE").
 * Source: Avery Weigh-Tronix GSE-02 "Eyecon Native Interface Protocol" (X25).
 *
 * Field map (minimum valid packet = fields 1-14; max = fields 1-15):
 * `ZNI|mode|ndc|stockBottleBarcode|drugName|stockBottleVerification|userName|countType||packetVersion|patientName|fillerOrderNumber|substitutionStatus|dispenseAmount|prescriptionNumber|fillNumber`
 * mode: B/b buffer, I/i immediate, C cycle count, Q query inventory.
 * stockBottleVerification: A always / N never / U user-choice / blank defer to Eyecon setting.
 * substitutionStatus: Y/N/A (default A).
 * Field 8 is reserved for future use and always sent blank.
 *
 * Note: the EtoC result packet reuses the "ZNI" segment name with a different field map
 * (fields 1-15 mirrored, result data starting at field 16) — direction must be
 * determined from MSH-9 before assuming this order-packet shape applies.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZNISegment")))
@interface Hl7CoreZNISegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZNISegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *countType __attribute__((swift_name("countType")));
@property (readonly) NSString *dispenseAmount __attribute__((swift_name("dispenseAmount")));
@property (readonly) NSString *drugName __attribute__((swift_name("drugName")));
@property (readonly) NSString *fillNumber __attribute__((swift_name("fillNumber")));
@property (readonly) NSString *fillerOrderNumber __attribute__((swift_name("fillerOrderNumber")));
@property (readonly) NSString *mode __attribute__((swift_name("mode")));
@property (readonly) NSString *ndc __attribute__((swift_name("ndc")));
@property (readonly) NSString *packetVersion __attribute__((swift_name("packetVersion")));
@property (readonly) NSString *patientFamilyName __attribute__((swift_name("patientFamilyName")));
@property (readonly) NSString *patientGivenName __attribute__((swift_name("patientGivenName")));
@property (readonly) NSString *prescriptionNumber __attribute__((swift_name("prescriptionNumber")));
@property (readonly) NSString *stockBottleBarcode __attribute__((swift_name("stockBottleBarcode")));
@property (readonly) NSString *stockBottleVerification __attribute__((swift_name("stockBottleVerification")));
@property (readonly) NSString *substitutionStatus __attribute__((swift_name("substitutionStatus")));
@property (readonly) NSString *userName __attribute__((swift_name("userName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZNISegment.Companion")))
@interface Hl7CoreZNISegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZNISegmentCompanion *shared __attribute__((swift_name("shared")));
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
 * `ZSN|setId|packageSerialNumber|nationalDrugCode|lotNumber|expirationDate|transactionType|quantityFromThisStockItem|captureSource|captureTimestamp`
 * transactionType: D = dispense, R = return.
 * captureSource: GS1 / NDC_LINEAR / MANUAL / UNKNOWN.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSNSegment")))
@interface Hl7CoreZSNSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZSNSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *captureSource __attribute__((swift_name("captureSource")));
@property (readonly) NSString *captureTimestamp __attribute__((swift_name("captureTimestamp")));
@property (readonly) NSString *expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString *lotNumber __attribute__((swift_name("lotNumber")));
@property (readonly) NSString *nationalDrugCode __attribute__((swift_name("nationalDrugCode")));
@property (readonly) NSString *packageSerialNumber __attribute__((swift_name("packageSerialNumber")));
@property (readonly) NSString *quantityFromThisStockItem __attribute__((swift_name("quantityFromThisStockItem")));
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
 * ZSV — Stock-bottle Validation segment. New §13 extension.
 *
 * Field map (project-authoritative):
 * `ZSV|setId|dispensedNdc|scannedNdc|validationResult|scanSource|validator|validationTimestamp|matchStrength`
 * dispensedNdc: echoes RXD-2.1 — the NDC the system expected.
 * scannedNdc: what the device actually read from the bottle barcode.
 * validationResult: MATCH / SUBSTITUTION / OVERRIDE / MISMATCH.
 * scanSource: GS1 (2D DataMatrix) / NDC_LINEAR (UPC-A/GTIN) / MANUAL.
 * validator: XCN — user_id^^first-name of the operator who performed the scan.
 * validationTimestamp: yyyyMMddHHmmss — when the scan was accepted.
 * matchStrength: EXACT (11-digit NDC) / GENERIC (GPI-equivalent) / NDC10 (10-digit fallback).
 *   Required when validationResult is MATCH or SUBSTITUTION.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZSVSegment")))
@interface Hl7CoreZSVSegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZSVSegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *dispensedNdc __attribute__((swift_name("dispensedNdc")));
@property (readonly) NSString *matchStrength __attribute__((swift_name("matchStrength")));
@property (readonly) NSString *scanSource __attribute__((swift_name("scanSource")));
@property (readonly) NSString *scannedNdc __attribute__((swift_name("scannedNdc")));
@property (readonly) NSString *setId __attribute__((swift_name("setId")));
@property (readonly) NSString *validationResult __attribute__((swift_name("validationResult")));
@property (readonly) NSString *validationTimestamp __attribute__((swift_name("validationTimestamp")));
@property (readonly) NSString *validator __attribute__((swift_name("validator")));
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
 * ZUI — Order Data Packet / Pharmacy Dispense Message. The "ZUI" segment name is
 * reused for two unrelated field maps depending on message type — direction must
 * be determined from MSH-9 before deciding which accessor group applies.
 *
 * Order Data Packet (RDE^O11, PMSS → VIVID):
 * `ZUI|ndc|drugName|patientName|transactionOrderId|dispenseQuantity|rxNumber|fillNumber`
 * ndc: required, 11-digit NDC.
 * patientName: family^given.
 * transactionOrderId: required, order ID or Rx number (numeric).
 * dispenseQuantity: required, numeric.
 * rxNumber: required, numeric.
 * fillNumber: optional, numeric.
 *
 * Pharmacy Dispense Message (RDS, VIVID → PMSS):
 * `ZUI|ndc|vividUserName|transactionOrderId|rxNumber|fillNumber|dispensedQuantity|transactionStatus|drugImage|drugLotNumber|drugSerialNumber|drugExpirationDate`
 * vividUserName: "Anonymous" if in Anonymous Mode.
 * transactionStatus: Done / Cancelled / Partial / Overfill — see [org.rite.hl7.builder.ZuiTransactionStatus].
 * drugImage: optional, base64 encoded string.
 * drugLotNumber / drugSerialNumber / drugExpirationDate: optional GS1 fields; expirationDate is yyMMdd.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZUISegment")))
@interface Hl7CoreZUISegment : Hl7CoreTypedSegment
- (instancetype)initWithRaw:(Hl7CoreHL7Segment *)raw __attribute__((swift_name("init(raw:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreZUISegmentCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *dispenseFillNumber __attribute__((swift_name("dispenseFillNumber")));
@property (readonly) NSString *dispenseRxNumber __attribute__((swift_name("dispenseRxNumber")));
@property (readonly) NSString *dispenseTransactionOrderId __attribute__((swift_name("dispenseTransactionOrderId")));
@property (readonly) NSString *dispenseVividUserName __attribute__((swift_name("dispenseVividUserName")));
@property (readonly) NSString *dispensedQuantity __attribute__((swift_name("dispensedQuantity")));
@property (readonly) NSString *drugExpirationDate __attribute__((swift_name("drugExpirationDate")));
@property (readonly) NSString *drugImage __attribute__((swift_name("drugImage")));
@property (readonly) NSString *drugLotNumber __attribute__((swift_name("drugLotNumber")));
@property (readonly) NSString *drugSerialNumber __attribute__((swift_name("drugSerialNumber")));

/** Shared by both layouts (field 1 in both). */
@property (readonly) NSString *ndc __attribute__((swift_name("ndc")));
@property (readonly) NSString *orderDispenseQuantity __attribute__((swift_name("orderDispenseQuantity")));
@property (readonly) NSString *orderDrugName __attribute__((swift_name("orderDrugName")));
@property (readonly) NSString *orderFillNumber __attribute__((swift_name("orderFillNumber")));
@property (readonly) NSString *orderPatientFamilyName __attribute__((swift_name("orderPatientFamilyName")));
@property (readonly) NSString *orderPatientGivenName __attribute__((swift_name("orderPatientGivenName")));
@property (readonly) NSString *orderRxNumber __attribute__((swift_name("orderRxNumber")));
@property (readonly) NSString *orderTransactionOrderId __attribute__((swift_name("orderTransactionOrderId")));
@property (readonly) NSString *transactionStatus __attribute__((swift_name("transactionStatus")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZUISegment.Companion")))
@interface Hl7CoreZUISegmentCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreZUISegmentCompanion *shared __attribute__((swift_name("shared")));
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

/**
 * Parses a byte stream containing one or more concatenated MLLP frames
 * (multiple HL7 messages sent back-to-back over the same MLLP connection),
 * returning one [HL7ParseResult] per frame in order. A malformed frame
 * fails independently and does not affect the others.
 */
- (NSArray<Hl7CoreHL7ParseResult *> *)parseMllpBatchBytes:(Hl7CoreKotlinByteArray *)bytes __attribute__((swift_name("parseMllpBatch(bytes:)")));
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
 * MSA-1 carries the worst severity (AA/AE/AR). One ERR segment is emitted per
 * non-ACCEPT issue, ordered as they appear in [ValidationResult.issues].
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
 *  - MSH: must be present, must carry a message type with a component
 *    separator, and a non-blank control ID (MSH-10) → else AR.
 *  - QBP^Q11: QPD-1 must equal the configured query name → else AR.
 *  - ZAD: adjustmentType and adjustmentReason must be recognized → else AR;
 *    a reason that requires a comment must have one → else AE.
 *  - RDE^O11 / RDE^O01: ZUI (Vivid) or ZNI (Eyecon), each validated on their
 *    own required fields (NDC, quantity, Rx number); otherwise ORC + at least
 *    one RXE required — ORC-1 must be a known order control code, ORC-2 must
 *    be present (any shape — Rx number format is not checked), and (for
 *    non-cancel orders) each RXE needs a valid-shaped NDC and a bounded
 *    whole-number quantity; any ZPR present must carry a known priority
 *    (case-insensitive). Patient name, route, order status, and HL7 version
 *    are content the PMS may omit or vary freely and are not validated.
 *  - INR^U06 without ZAD (plain count request): at least one OBX (each with a
 *    valid NDC and numeric value) or one RXE (each with a valid NDC) required;
 *    any ZIN quantity must not be negative.
 *  - MSH-9 = ACK, or any other unsupported message type/trigger → AR.
 *
 * Construct with a [ValidationConfig] to override the site defaults.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Validator")))
@interface Hl7CoreHL7Validator : Hl7CoreBase
- (instancetype)initWithConfig:(Hl7CoreValidationConfig *)config __attribute__((swift_name("init(config:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreHL7ValidatorCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreValidationResult *)validateMessage:(Hl7CoreHL7Message *)message __attribute__((swift_name("validate(message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Validator.Companion")))
@interface Hl7CoreHL7ValidatorCompanion : Hl7CoreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Hl7CoreHL7ValidatorCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * Site-configurable inputs for the validator. Defaults follow the PillCounter
 * spec; partners may override per site (the spec's "downloadable text file" model).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ValidationConfig")))
@interface Hl7CoreValidationConfig : Hl7CoreBase
- (instancetype)initWithKnownAdjustmentReasons:(NSSet<NSString *> *)knownAdjustmentReasons knownAdjustmentTypes:(NSSet<NSString *> *)knownAdjustmentTypes expectedQueryName:(NSString *)expectedQueryName commentRequiredReasons:(NSSet<NSString *> *)commentRequiredReasons knownOrderControlCodes:(NSSet<NSString *> *)knownOrderControlCodes knownPriorities:(NSSet<NSString *> *)knownPriorities maxQuantity:(int32_t)maxQuantity __attribute__((swift_name("init(knownAdjustmentReasons:knownAdjustmentTypes:expectedQueryName:commentRequiredReasons:knownOrderControlCodes:knownPriorities:maxQuantity:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Hl7CoreValidationConfigCompanion *companion __attribute__((swift_name("companion")));
- (Hl7CoreValidationConfig *)doCopyKnownAdjustmentReasons:(NSSet<NSString *> *)knownAdjustmentReasons knownAdjustmentTypes:(NSSet<NSString *> *)knownAdjustmentTypes expectedQueryName:(NSString *)expectedQueryName commentRequiredReasons:(NSSet<NSString *> *)commentRequiredReasons knownOrderControlCodes:(NSSet<NSString *> *)knownOrderControlCodes knownPriorities:(NSSet<NSString *> *)knownPriorities maxQuantity:(int32_t)maxQuantity __attribute__((swift_name("doCopy(knownAdjustmentReasons:knownAdjustmentTypes:expectedQueryName:commentRequiredReasons:knownOrderControlCodes:knownPriorities:maxQuantity:)")));

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

/** ORC-1 order control codes the PMS recognizes for dispense orders. */
@property (readonly) NSSet<NSString *> *knownOrderControlCodes __attribute__((swift_name("knownOrderControlCodes")));

/** ZPR-3 priority values the PMS recognizes (matched case-insensitively). */
@property (readonly) NSSet<NSString *> *knownPriorities __attribute__((swift_name("knownPriorities")));

/** Maximum accepted whole-pill dispense/adjustment quantity. */
@property (readonly) int32_t maxQuantity __attribute__((swift_name("maxQuantity")));
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
@property (readonly) int32_t DEFAULT_MAX_QUANTITY __attribute__((swift_name("DEFAULT_MAX_QUANTITY")));
@property (readonly) NSSet<NSString *> *DEFAULT_ORDER_CONTROL_CODES __attribute__((swift_name("DEFAULT_ORDER_CONTROL_CODES")));
@property (readonly) NSSet<NSString *> *DEFAULT_PRIORITIES __attribute__((swift_name("DEFAULT_PRIORITIES")));
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
@property (class, readonly) Hl7CoreHL7Version *v271 __attribute__((swift_name("v271")));
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
