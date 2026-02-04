#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class ComposeAppAckDecision, ComposeAppAckDecisionAccept, ComposeAppAckDecisionError, ComposeAppAckDecisionReject, ComposeAppAckGenerator, ComposeAppAcknowledgmentData, ComposeAppCompleteHL7Message, ComposeAppComponentData, ComposeAppCustomSegmentData, ComposeAppDispenseData, ComposeAppErrorData, ComposeAppHL7Constants, ComposeAppHL7MessageBuilderCompanion, ComposeAppHL7Utils, ComposeAppHl7ParserCompanion, ComposeAppInventoryBinData, ComposeAppInventoryData, ComposeAppKotlinArray<T>, ComposeAppKotlinByteArray, ComposeAppKotlinByteIterator, ComposeAppKotlinException, ComposeAppKotlinIllegalStateException, ComposeAppKotlinRuntimeException, ComposeAppKotlinThrowable, ComposeAppMedicationData, ComposeAppMessageHeaderData, ComposeAppMshFields, ComposeAppMshVersionCapabilities, ComposeAppNoteData, ComposeAppOrderData, ComposeAppPatientData, ComposeAppRouteData, ComposeAppRxdVersionCapabilities, ComposeAppVisitData;

@protocol ComposeAppKotlinIterator;

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
@interface ComposeAppBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface ComposeAppBase (ComposeAppBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface ComposeAppMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface ComposeAppMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorComposeAppKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface ComposeAppNumber : NSNumber
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
@interface ComposeAppByte : ComposeAppNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface ComposeAppUByte : ComposeAppNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface ComposeAppShort : ComposeAppNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface ComposeAppUShort : ComposeAppNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface ComposeAppInt : ComposeAppNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface ComposeAppUInt : ComposeAppNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface ComposeAppLong : ComposeAppNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface ComposeAppULong : ComposeAppNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface ComposeAppFloat : ComposeAppNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface ComposeAppDouble : ComposeAppNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface ComposeAppBoolean : ComposeAppNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("AckDecision")))
@interface ComposeAppAckDecision : ComposeAppBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckDecision.Accept")))
@interface ComposeAppAckDecisionAccept : ComposeAppAckDecision
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)accept __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppAckDecisionAccept *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckDecision.Error")))
@interface ComposeAppAckDecisionError : ComposeAppAckDecision
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppAckDecisionError *)doCopyMessage:(NSString *)message __attribute__((swift_name("doCopy(message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckDecision.Reject")))
@interface ComposeAppAckDecisionReject : ComposeAppAckDecision
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppAckDecisionReject *)doCopyMessage:(NSString *)message __attribute__((swift_name("doCopy(message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end


/**
 * HL7 ACK / NACK generator
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AckGenerator")))
@interface ComposeAppAckGenerator : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * HL7 ACK / NACK generator
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)ackGenerator __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppAckGenerator *shared __attribute__((swift_name("shared")));

/**
 * Fallback AR when MSH cannot be parsed
 */
- (NSString *)fallbackRejectReason:(NSString *)reason __attribute__((swift_name("fallbackReject(reason:)")));
- (NSString *)generateMsh:(ComposeAppMshFields *)msh decision:(ComposeAppAckDecision *)decision __attribute__((swift_name("generate(msh:decision:)")));
@end


/**
 * Minimal extracted MSH fields required for ACK generation.
 * Parsing happens OUTSIDE the ACK generator.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MshFields")))
@interface ComposeAppMshFields : ComposeAppBase
- (instancetype)initWithSendingApp:(NSString *)sendingApp sendingFacility:(NSString *)sendingFacility receivingApp:(NSString *)receivingApp receivingFacility:(NSString *)receivingFacility messageControlId:(NSString *)messageControlId version:(NSString *)version __attribute__((swift_name("init(sendingApp:sendingFacility:receivingApp:receivingFacility:messageControlId:version:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppMshFields *)doCopySendingApp:(NSString *)sendingApp sendingFacility:(NSString *)sendingFacility receivingApp:(NSString *)receivingApp receivingFacility:(NSString *)receivingFacility messageControlId:(NSString *)messageControlId version:(NSString *)version __attribute__((swift_name("doCopy(sendingApp:sendingFacility:receivingApp:receivingFacility:messageControlId:version:)")));

/**
 * Minimal extracted MSH fields required for ACK generation.
 * Parsing happens OUTSIDE the ACK generator.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Minimal extracted MSH fields required for ACK generation.
 * Parsing happens OUTSIDE the ACK generator.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Minimal extracted MSH fields required for ACK generation.
 * Parsing happens OUTSIDE the ACK generator.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));
@property (readonly) NSString *receivingApp __attribute__((swift_name("receivingApp")));
@property (readonly) NSString *receivingFacility __attribute__((swift_name("receivingFacility")));
@property (readonly) NSString *sendingApp __attribute__((swift_name("sendingApp")));
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));
@property (readonly) NSString *version __attribute__((swift_name("version")));
@end


/**
 * Comprehensive HL7 Message Builder
 * Converts CompleteHL7Message data class back to HL7 format
 * Supports all standard segments: MSH, PID, PV1, ORC, RXE, RXR, RXC, RXD, EQU, INV, MSA, ERR, NTE
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7MessageBuilder")))
@interface ComposeAppHL7MessageBuilder : ComposeAppBase

/**
 * Comprehensive HL7 Message Builder
 * Converts CompleteHL7Message data class back to HL7 format
 * Supports all standard segments: MSH, PID, PV1, ORC, RXE, RXR, RXC, RXD, EQU, INV, MSA, ERR, NTE
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Comprehensive HL7 Message Builder
 * Converts CompleteHL7Message data class back to HL7 format
 * Supports all standard segments: MSH, PID, PV1, ORC, RXE, RXR, RXC, RXD, EQU, INV, MSA, ERR, NTE
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) ComposeAppHL7MessageBuilderCompanion *companion __attribute__((swift_name("companion")));

/**
 * Build complete HL7 message from CompleteHL7Message data class
 */
- (NSString *)buildMessage:(ComposeAppCompleteHL7Message *)message __attribute__((swift_name("build(message:)")));

/**
 * Build message for specific message types with validation
 */
- (NSString *)buildTypedMessageMessage:(ComposeAppCompleteHL7Message *)message __attribute__((swift_name("buildTypedMessage(message:)")));

/**
 * Build with MLLP framing for network transmission
 */
- (ComposeAppKotlinByteArray *)buildWithMllpMessage:(ComposeAppCompleteHL7Message *)message __attribute__((swift_name("buildWithMllp(message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7MessageBuilder.Companion")))
@interface ComposeAppHL7MessageBuilderCompanion : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppHL7MessageBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MshVersionCapabilities")))
@interface ComposeAppMshVersionCapabilities : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mshVersionCapabilities __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppMshVersionCapabilities *shared __attribute__((swift_name("shared")));
- (int32_t)maxFieldVersion:(NSString *)version __attribute__((swift_name("maxField(version:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxdVersionCapabilities")))
@interface ComposeAppRxdVersionCapabilities : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)rxdVersionCapabilities __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppRxdVersionCapabilities *shared __attribute__((swift_name("shared")));
- (int32_t)maxFieldVersion:(NSString *)version __attribute__((swift_name("maxField(version:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AcknowledgmentData")))
@interface ComposeAppAcknowledgmentData : ComposeAppBase
- (instancetype)initWithAcknowledgmentCode:(NSString *)acknowledgmentCode messageControlId:(NSString *)messageControlId textMessage:(NSString * _Nullable)textMessage errorCondition:(NSString * _Nullable)errorCondition __attribute__((swift_name("init(acknowledgmentCode:messageControlId:textMessage:errorCondition:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppAcknowledgmentData *)doCopyAcknowledgmentCode:(NSString *)acknowledgmentCode messageControlId:(NSString *)messageControlId textMessage:(NSString * _Nullable)textMessage errorCondition:(NSString * _Nullable)errorCondition __attribute__((swift_name("doCopy(acknowledgmentCode:messageControlId:textMessage:errorCondition:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed acknowledgment code (AA=Accept, AE=Error, AR=Reject) (MSA-1) **/
@property (readonly) NSString *acknowledgmentCode __attribute__((swift_name("acknowledgmentCode")));

/** Parsed error condition derived from ERR segment (if present) **/
@property (readonly) NSString * _Nullable errorCondition __attribute__((swift_name("errorCondition")));

/** Parsed message control ID correlating to original MSH-10 (MSA-2) **/
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));

/** Parsed human-readable acknowledgment text (MSA-3) **/
@property (readonly) NSString * _Nullable textMessage __attribute__((swift_name("textMessage")));
@end


/**
 * Main HL7 message container holding all parsed segments
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompleteHL7Message")))
@interface ComposeAppCompleteHL7Message : ComposeAppBase
- (instancetype)initWithMessageId:(NSString *)messageId messageType:(NSString *)messageType triggerEvent:(NSString *)triggerEvent timestamp:(NSString *)timestamp sendingFacility:(NSString *)sendingFacility header:(ComposeAppMessageHeaderData *)header patient:(ComposeAppPatientData * _Nullable)patient visit:(ComposeAppVisitData * _Nullable)visit order:(ComposeAppOrderData * _Nullable)order medications:(NSArray<ComposeAppMedicationData *> *)medications routes:(NSArray<ComposeAppRouteData *> *)routes components:(NSArray<ComposeAppComponentData *> *)components dispenses:(NSArray<ComposeAppDispenseData *> *)dispenses inventory:(ComposeAppInventoryData * _Nullable)inventory acknowledgment:(ComposeAppAcknowledgmentData * _Nullable)acknowledgment notes:(NSArray<ComposeAppNoteData *> *)notes customSegments:(NSArray<ComposeAppCustomSegmentData *> *)customSegments errors:(NSArray<ComposeAppErrorData *> *)errors __attribute__((swift_name("init(messageId:messageType:triggerEvent:timestamp:sendingFacility:header:patient:visit:order:medications:routes:components:dispenses:inventory:acknowledgment:notes:customSegments:errors:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppCompleteHL7Message *)doCopyMessageId:(NSString *)messageId messageType:(NSString *)messageType triggerEvent:(NSString *)triggerEvent timestamp:(NSString *)timestamp sendingFacility:(NSString *)sendingFacility header:(ComposeAppMessageHeaderData *)header patient:(ComposeAppPatientData * _Nullable)patient visit:(ComposeAppVisitData * _Nullable)visit order:(ComposeAppOrderData * _Nullable)order medications:(NSArray<ComposeAppMedicationData *> *)medications routes:(NSArray<ComposeAppRouteData *> *)routes components:(NSArray<ComposeAppComponentData *> *)components dispenses:(NSArray<ComposeAppDispenseData *> *)dispenses inventory:(ComposeAppInventoryData * _Nullable)inventory acknowledgment:(ComposeAppAcknowledgmentData * _Nullable)acknowledgment notes:(NSArray<ComposeAppNoteData *> *)notes customSegments:(NSArray<ComposeAppCustomSegmentData *> *)customSegments errors:(NSArray<ComposeAppErrorData *> *)errors __attribute__((swift_name("doCopy(messageId:messageType:triggerEvent:timestamp:sendingFacility:header:patient:visit:order:medications:routes:components:dispenses:inventory:acknowledgment:notes:customSegments:errors:)")));

/**
 * Main HL7 message container holding all parsed segments
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Main HL7 message container holding all parsed segments
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Main HL7 message container holding all parsed segments
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** MSA + ERR: HL7 acknowledgment response **/
@property (readonly) ComposeAppAcknowledgmentData * _Nullable acknowledgment __attribute__((swift_name("acknowledgment")));

/** RXC: Components for compound medications **/
@property (readonly) NSArray<ComposeAppComponentData *> *components __attribute__((swift_name("components")));

/** Z-segments: Custom non-standard HL7 segments **/
@property (readonly) NSArray<ComposeAppCustomSegmentData *> *customSegments __attribute__((swift_name("customSegments")));

/** RXD: Medication dispensing records **/
@property (readonly) NSArray<ComposeAppDispenseData *> *dispenses __attribute__((swift_name("dispenses")));

/** ERR: HL7 processing and validation errors **/
@property (readonly) NSArray<ComposeAppErrorData *> *errors __attribute__((swift_name("errors")));

/** Parsed MSH header containing message metadata **/
@property (readonly) ComposeAppMessageHeaderData *header __attribute__((swift_name("header")));

/** EQU + INV: Inventory and equipment status **/
@property (readonly) ComposeAppInventoryData * _Nullable inventory __attribute__((swift_name("inventory")));

/** RXE: Medication order details **/
@property (readonly) NSArray<ComposeAppMedicationData *> *medications __attribute__((swift_name("medications")));

/** MSH-10: Unique message control ID used as primary key **/
@property (readonly) NSString *messageId __attribute__((swift_name("messageId")));

/** MSH-9.1: HL7 message type (e.g. ADT, ORM, RDS) **/
@property (readonly) NSString *messageType __attribute__((swift_name("messageType")));

/** NTE: Free-text notes and comments **/
@property (readonly) NSArray<ComposeAppNoteData *> *notes __attribute__((swift_name("notes")));

/** ORC: Order control and order identifiers **/
@property (readonly) ComposeAppOrderData * _Nullable order __attribute__((swift_name("order")));

/** PID: Patient demographic information **/
@property (readonly) ComposeAppPatientData * _Nullable patient __attribute__((swift_name("patient")));

/** RXR: Medication administration routes **/
@property (readonly) NSArray<ComposeAppRouteData *> *routes __attribute__((swift_name("routes")));

/** MSH-4: Sending facility identifier (used for idempotency) **/
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));

/** MSH-7: Date and time when message was created **/
@property (readonly) NSString *timestamp __attribute__((swift_name("timestamp")));

/** MSH-9.2: HL7 trigger event (e.g. A01, O13) **/
@property (readonly) NSString *triggerEvent __attribute__((swift_name("triggerEvent")));

/** PV1: Patient visit and encounter details **/
@property (readonly) ComposeAppVisitData * _Nullable visit __attribute__((swift_name("visit")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ComponentData")))
@interface ComposeAppComponentData : ComposeAppBase
- (instancetype)initWithComponentType:(NSString * _Nullable)componentType ndcOrComponentCode:(NSString * _Nullable)ndcOrComponentCode componentName:(NSString * _Nullable)componentName componentCodeSystem:(NSString * _Nullable)componentCodeSystem componentAmount:(NSString * _Nullable)componentAmount componentUnitsCode:(NSString * _Nullable)componentUnitsCode componentUnitsText:(NSString * _Nullable)componentUnitsText componentStrength:(NSString * _Nullable)componentStrength componentStrengthUnits:(NSString * _Nullable)componentStrengthUnits __attribute__((swift_name("init(componentType:ndcOrComponentCode:componentName:componentCodeSystem:componentAmount:componentUnitsCode:componentUnitsText:componentStrength:componentStrengthUnits:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppComponentData *)doCopyComponentType:(NSString * _Nullable)componentType ndcOrComponentCode:(NSString * _Nullable)ndcOrComponentCode componentName:(NSString * _Nullable)componentName componentCodeSystem:(NSString * _Nullable)componentCodeSystem componentAmount:(NSString * _Nullable)componentAmount componentUnitsCode:(NSString * _Nullable)componentUnitsCode componentUnitsText:(NSString * _Nullable)componentUnitsText componentStrength:(NSString * _Nullable)componentStrength componentStrengthUnits:(NSString * _Nullable)componentStrengthUnits __attribute__((swift_name("doCopy(componentType:ndcOrComponentCode:componentName:componentCodeSystem:componentAmount:componentUnitsCode:componentUnitsText:componentStrength:componentStrengthUnits:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed amount of this component in the compound (RXC-3) **/
@property (readonly) NSString * _Nullable componentAmount __attribute__((swift_name("componentAmount")));

/** Parsed coding system for component identifier (typically NDC) (RXC-2.3) **/
@property (readonly) NSString * _Nullable componentCodeSystem __attribute__((swift_name("componentCodeSystem")));

/** Parsed component or substance name (RXC-2.2) **/
@property (readonly) NSString * _Nullable componentName __attribute__((swift_name("componentName")));

/** Parsed strength or concentration of the component (RXC-5) **/
@property (readonly) NSString * _Nullable componentStrength __attribute__((swift_name("componentStrength")));

/** Parsed units for component strength (RXC-6) **/
@property (readonly) NSString * _Nullable componentStrengthUnits __attribute__((swift_name("componentStrengthUnits")));

/** Parsed component type indicator (e.g., A=Additive, B=Base) (RXC-1) **/
@property (readonly) NSString * _Nullable componentType __attribute__((swift_name("componentType")));

/** Parsed unit code for component amount (RXC-4.1) **/
@property (readonly) NSString * _Nullable componentUnitsCode __attribute__((swift_name("componentUnitsCode")));

/** Parsed unit text for component amount (RXC-4.2) **/
@property (readonly) NSString * _Nullable componentUnitsText __attribute__((swift_name("componentUnitsText")));

/** Parsed NDC or component code used for barcode validation (RXC-2.1) **/
@property (readonly) NSString * _Nullable ndcOrComponentCode __attribute__((swift_name("ndcOrComponentCode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CustomSegmentData")))
@interface ComposeAppCustomSegmentData : ComposeAppBase
- (instancetype)initWithSegmentType:(NSString *)segmentType field1:(NSString * _Nullable)field1 field2:(NSString * _Nullable)field2 field3:(NSString * _Nullable)field3 field4:(NSString * _Nullable)field4 field5:(NSString * _Nullable)field5 field6:(NSString * _Nullable)field6 allFields:(NSDictionary<ComposeAppInt *, NSString *> *)allFields __attribute__((swift_name("init(segmentType:field1:field2:field3:field4:field5:field6:allFields:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppCustomSegmentData *)doCopySegmentType:(NSString *)segmentType field1:(NSString * _Nullable)field1 field2:(NSString * _Nullable)field2 field3:(NSString * _Nullable)field3 field4:(NSString * _Nullable)field4 field5:(NSString * _Nullable)field5 field6:(NSString * _Nullable)field6 allFields:(NSDictionary<ComposeAppInt *, NSString *> *)allFields __attribute__((swift_name("doCopy(segmentType:field1:field2:field3:field4:field5:field6:allFields:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed dynamic map of all custom segment fields (fieldIndex → value) **/
@property (readonly) NSDictionary<ComposeAppInt *, NSString *> *allFields __attribute__((swift_name("allFields")));

/** Parsed custom segment field 1 **/
@property (readonly) NSString * _Nullable field1 __attribute__((swift_name("field1")));

/** Parsed custom segment field 2 **/
@property (readonly) NSString * _Nullable field2 __attribute__((swift_name("field2")));

/** Parsed custom segment field 3 **/
@property (readonly) NSString * _Nullable field3 __attribute__((swift_name("field3")));

/** Parsed custom segment field 4 **/
@property (readonly) NSString * _Nullable field4 __attribute__((swift_name("field4")));

/** Parsed custom segment field 5 **/
@property (readonly) NSString * _Nullable field5 __attribute__((swift_name("field5")));

/** Parsed custom segment field 6 **/
@property (readonly) NSString * _Nullable field6 __attribute__((swift_name("field6")));

/** Parsed custom segment name (e.g., ZDS, ZRX, ZINV) **/
@property (readonly) NSString *segmentType __attribute__((swift_name("segmentType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DispenseData")))
@interface ComposeAppDispenseData : ComposeAppBase
- (instancetype)initWithDispenseSubId:(NSString * _Nullable)dispenseSubId drugCode:(NSString *)drugCode drugName:(NSString *)drugName drugCodeSystem:(NSString * _Nullable)drugCodeSystem dateTimeDispensed:(NSString * _Nullable)dateTimeDispensed quantityDispensed:(NSString *)quantityDispensed unitCode:(NSString *)unitCode unitText:(NSString * _Nullable)unitText dosageFormCode:(NSString * _Nullable)dosageFormCode dosageFormText:(NSString * _Nullable)dosageFormText prescriptionNumber:(NSString * _Nullable)prescriptionNumber pharmacistId:(NSString * _Nullable)pharmacistId pharmacistFamilyName:(NSString * _Nullable)pharmacistFamilyName pharmacistGivenName:(NSString * _Nullable)pharmacistGivenName substituteCode:(NSString * _Nullable)substituteCode deliverToLocation:(NSString * _Nullable)deliverToLocation needsHumanReview:(NSString * _Nullable)needsHumanReview dispensingNotes:(NSString * _Nullable)dispensingNotes lotNumber:(NSString * _Nullable)lotNumber expirationDate:(NSString * _Nullable)expirationDate substanceManufacturerName:(NSString * _Nullable)substanceManufacturerName cellId:(NSString * _Nullable)cellId cellLocation:(NSString * _Nullable)cellLocation __attribute__((swift_name("init(dispenseSubId:drugCode:drugName:drugCodeSystem:dateTimeDispensed:quantityDispensed:unitCode:unitText:dosageFormCode:dosageFormText:prescriptionNumber:pharmacistId:pharmacistFamilyName:pharmacistGivenName:substituteCode:deliverToLocation:needsHumanReview:dispensingNotes:lotNumber:expirationDate:substanceManufacturerName:cellId:cellLocation:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppDispenseData *)doCopyDispenseSubId:(NSString * _Nullable)dispenseSubId drugCode:(NSString *)drugCode drugName:(NSString *)drugName drugCodeSystem:(NSString * _Nullable)drugCodeSystem dateTimeDispensed:(NSString * _Nullable)dateTimeDispensed quantityDispensed:(NSString *)quantityDispensed unitCode:(NSString *)unitCode unitText:(NSString * _Nullable)unitText dosageFormCode:(NSString * _Nullable)dosageFormCode dosageFormText:(NSString * _Nullable)dosageFormText prescriptionNumber:(NSString * _Nullable)prescriptionNumber pharmacistId:(NSString * _Nullable)pharmacistId pharmacistFamilyName:(NSString * _Nullable)pharmacistFamilyName pharmacistGivenName:(NSString * _Nullable)pharmacistGivenName substituteCode:(NSString * _Nullable)substituteCode deliverToLocation:(NSString * _Nullable)deliverToLocation needsHumanReview:(NSString * _Nullable)needsHumanReview dispensingNotes:(NSString * _Nullable)dispensingNotes lotNumber:(NSString * _Nullable)lotNumber expirationDate:(NSString * _Nullable)expirationDate substanceManufacturerName:(NSString * _Nullable)substanceManufacturerName cellId:(NSString * _Nullable)cellId cellLocation:(NSString * _Nullable)cellLocation __attribute__((swift_name("doCopy(dispenseSubId:drugCode:drugName:drugCodeSystem:dateTimeDispensed:quantityDispensed:unitCode:unitText:dosageFormCode:dosageFormText:prescriptionNumber:pharmacistId:pharmacistFamilyName:pharmacistGivenName:substituteCode:deliverToLocation:needsHumanReview:dispensingNotes:lotNumber:expirationDate:substanceManufacturerName:cellId:cellLocation:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed automation-specific dispensing cell identifier **/
@property (readonly) NSString * _Nullable cellId __attribute__((swift_name("cellId")));

/** Parsed automation-specific dispensing cell location **/
@property (readonly) NSString * _Nullable cellLocation __attribute__((swift_name("cellLocation")));

/** Parsed date and time medication was dispensed (RXD-3) **/
@property (readonly) NSString * _Nullable dateTimeDispensed __attribute__((swift_name("dateTimeDispensed")));

/** Parsed location where medication was delivered (RXD-13) **/
@property (readonly) NSString * _Nullable deliverToLocation __attribute__((swift_name("deliverToLocation")));

/** Parsed dispense sub-identifier (RXD-1) **/
@property (readonly) NSString * _Nullable dispenseSubId __attribute__((swift_name("dispenseSubId")));

/** Parsed free-text dispensing notes (RXD-15) **/
@property (readonly) NSString * _Nullable dispensingNotes __attribute__((swift_name("dispensingNotes")));

/** Parsed dosage form code (tablet, vial, etc.) (RXD-6.1) **/
@property (readonly) NSString * _Nullable dosageFormCode __attribute__((swift_name("dosageFormCode")));

/** Parsed dosage form text (RXD-6.2) **/
@property (readonly) NSString * _Nullable dosageFormText __attribute__((swift_name("dosageFormText")));

/** Parsed dispensed drug code (RXD-2.1) **/
@property (readonly) NSString *drugCode __attribute__((swift_name("drugCode")));

/** Parsed coding system for drug identifier (RXD-2.3) **/
@property (readonly) NSString * _Nullable drugCodeSystem __attribute__((swift_name("drugCodeSystem")));

/** Parsed dispensed drug name (RXD-2.2) **/
@property (readonly) NSString *drugName __attribute__((swift_name("drugName")));

/** Parsed medication expiration date (RXD-19) **/
@property (readonly) NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));

/** Parsed medication lot number (RXD-18) **/
@property (readonly) NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));

/** Parsed human review requirement indicator (RXD-14) **/
@property (readonly) NSString * _Nullable needsHumanReview __attribute__((swift_name("needsHumanReview")));

/** Parsed dispensing pharmacist family name (RXD-10.2) **/
@property (readonly) NSString * _Nullable pharmacistFamilyName __attribute__((swift_name("pharmacistFamilyName")));

/** Parsed dispensing pharmacist given name (RXD-10.3) **/
@property (readonly) NSString * _Nullable pharmacistGivenName __attribute__((swift_name("pharmacistGivenName")));

/** Parsed dispensing pharmacist identifier (RXD-10.1) **/
@property (readonly) NSString * _Nullable pharmacistId __attribute__((swift_name("pharmacistId")));

/** Parsed prescription number associated with dispense (RXD-7) **/
@property (readonly) NSString * _Nullable prescriptionNumber __attribute__((swift_name("prescriptionNumber")));

/** Parsed quantity actually dispensed (RXD-4) **/
@property (readonly) NSString *quantityDispensed __attribute__((swift_name("quantityDispensed")));

/** Parsed manufacturer name of dispensed substance (RXD-20) **/
@property (readonly) NSString * _Nullable substanceManufacturerName __attribute__((swift_name("substanceManufacturerName")));

/** Parsed substitution status or code (RXD-11) **/
@property (readonly) NSString * _Nullable substituteCode __attribute__((swift_name("substituteCode")));

/** Parsed unit code for dispensed quantity (RXD-5.1) **/
@property (readonly) NSString *unitCode __attribute__((swift_name("unitCode")));

/** Parsed unit text for dispensed quantity (RXD-5.2) **/
@property (readonly) NSString * _Nullable unitText __attribute__((swift_name("unitText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorData")))
@interface ComposeAppErrorData : ComposeAppBase
- (instancetype)initWithSegmentId:(NSString * _Nullable)segmentId sequence:(NSString * _Nullable)sequence fieldPosition:(NSString * _Nullable)fieldPosition errorCode:(NSString * _Nullable)errorCode errorDescription:(NSString * _Nullable)errorDescription severity:(NSString * _Nullable)severity applicationErrorCode:(NSString * _Nullable)applicationErrorCode applicationErrorText:(NSString * _Nullable)applicationErrorText diagnosticInfo:(NSString * _Nullable)diagnosticInfo userMessage:(NSString * _Nullable)userMessage __attribute__((swift_name("init(segmentId:sequence:fieldPosition:errorCode:errorDescription:severity:applicationErrorCode:applicationErrorText:diagnosticInfo:userMessage:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppErrorData *)doCopySegmentId:(NSString * _Nullable)segmentId sequence:(NSString * _Nullable)sequence fieldPosition:(NSString * _Nullable)fieldPosition errorCode:(NSString * _Nullable)errorCode errorDescription:(NSString * _Nullable)errorDescription severity:(NSString * _Nullable)severity applicationErrorCode:(NSString * _Nullable)applicationErrorCode applicationErrorText:(NSString * _Nullable)applicationErrorText diagnosticInfo:(NSString * _Nullable)diagnosticInfo userMessage:(NSString * _Nullable)userMessage __attribute__((swift_name("doCopy(segmentId:sequence:fieldPosition:errorCode:errorDescription:severity:applicationErrorCode:applicationErrorText:diagnosticInfo:userMessage:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed application-specific error code (ERR-5.1) **/
@property (readonly) NSString * _Nullable applicationErrorCode __attribute__((swift_name("applicationErrorCode")));

/** Parsed application-specific error description (ERR-5.2) **/
@property (readonly) NSString * _Nullable applicationErrorText __attribute__((swift_name("applicationErrorText")));

/** Parsed diagnostic or system-level information (ERR-7) **/
@property (readonly) NSString * _Nullable diagnosticInfo __attribute__((swift_name("diagnosticInfo")));

/** Parsed HL7-defined error code (ERR-3.1) **/
@property (readonly) NSString * _Nullable errorCode __attribute__((swift_name("errorCode")));

/** Parsed description of the HL7 error (ERR-3.2) **/
@property (readonly) NSString * _Nullable errorDescription __attribute__((swift_name("errorDescription")));

/** Parsed field position that caused the error (ERR-2.3) **/
@property (readonly) NSString * _Nullable fieldPosition __attribute__((swift_name("fieldPosition")));

/** Parsed segment ID where the error occurred (ERR-2.1) **/
@property (readonly) NSString * _Nullable segmentId __attribute__((swift_name("segmentId")));

/** Parsed repetition or sequence number of the segment (ERR-2.2) **/
@property (readonly) NSString * _Nullable sequence __attribute__((swift_name("sequence")));

/** Parsed severity of the error (E=Error, W=Warning, I=Info) (ERR-4) **/
@property (readonly) NSString * _Nullable severity __attribute__((swift_name("severity")));

/** Parsed user-friendly error message (ERR-8) **/
@property (readonly) NSString * _Nullable userMessage __attribute__((swift_name("userMessage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InventoryBinData")))
@interface ComposeAppInventoryBinData : ComposeAppBase
- (instancetype)initWithSubstanceId:(NSString *)substanceId substanceName:(NSString * _Nullable)substanceName substanceCodeSystem:(NSString * _Nullable)substanceCodeSystem substanceStatus:(NSString * _Nullable)substanceStatus cellId:(NSString *)cellId cellLocation:(NSString * _Nullable)cellLocation quantityOnHand:(NSString * _Nullable)quantityOnHand availableQuantity:(NSString * _Nullable)availableQuantity quantityUnitCode:(NSString * _Nullable)quantityUnitCode quantityUnitText:(NSString * _Nullable)quantityUnitText expirationDate:(NSString * _Nullable)expirationDate lotNumber:(NSString * _Nullable)lotNumber manufacturerName:(NSString * _Nullable)manufacturerName supplierName:(NSString * _Nullable)supplierName onOrderQuantity:(NSString * _Nullable)onOrderQuantity __attribute__((swift_name("init(substanceId:substanceName:substanceCodeSystem:substanceStatus:cellId:cellLocation:quantityOnHand:availableQuantity:quantityUnitCode:quantityUnitText:expirationDate:lotNumber:manufacturerName:supplierName:onOrderQuantity:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppInventoryBinData *)doCopySubstanceId:(NSString *)substanceId substanceName:(NSString * _Nullable)substanceName substanceCodeSystem:(NSString * _Nullable)substanceCodeSystem substanceStatus:(NSString * _Nullable)substanceStatus cellId:(NSString *)cellId cellLocation:(NSString * _Nullable)cellLocation quantityOnHand:(NSString * _Nullable)quantityOnHand availableQuantity:(NSString * _Nullable)availableQuantity quantityUnitCode:(NSString * _Nullable)quantityUnitCode quantityUnitText:(NSString * _Nullable)quantityUnitText expirationDate:(NSString * _Nullable)expirationDate lotNumber:(NSString * _Nullable)lotNumber manufacturerName:(NSString * _Nullable)manufacturerName supplierName:(NSString * _Nullable)supplierName onOrderQuantity:(NSString * _Nullable)onOrderQuantity __attribute__((swift_name("doCopy(substanceId:substanceName:substanceCodeSystem:substanceStatus:cellId:cellLocation:quantityOnHand:availableQuantity:quantityUnitCode:quantityUnitText:expirationDate:lotNumber:manufacturerName:supplierName:onOrderQuantity:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed available quantity for dispensing (INV-9) **/
@property (readonly) NSString * _Nullable availableQuantity __attribute__((swift_name("availableQuantity")));

/** Parsed container or bin identifier (INV-5) **/
@property (readonly) NSString *cellId __attribute__((swift_name("cellId")));

/** Parsed physical location of the inventory bin **/
@property (readonly) NSString * _Nullable cellLocation __attribute__((swift_name("cellLocation")));

/** Parsed expiration date of the substance (INV-12) **/
@property (readonly) NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));

/** Parsed lot or batch number of the substance (INV-16) **/
@property (readonly) NSString * _Nullable lotNumber __attribute__((swift_name("lotNumber")));

/** Parsed manufacturer name of the substance (INV-17) **/
@property (readonly) NSString * _Nullable manufacturerName __attribute__((swift_name("manufacturerName")));

/** Parsed quantity currently on order for this substance (INV-19) **/
@property (readonly) NSString * _Nullable onOrderQuantity __attribute__((swift_name("onOrderQuantity")));

/** Parsed current quantity on hand in the bin (INV-8) **/
@property (readonly) NSString * _Nullable quantityOnHand __attribute__((swift_name("quantityOnHand")));

/** Parsed unit code for inventory quantity (INV-11.1) **/
@property (readonly) NSString * _Nullable quantityUnitCode __attribute__((swift_name("quantityUnitCode")));

/** Parsed unit text for inventory quantity (INV-11.2) **/
@property (readonly) NSString * _Nullable quantityUnitText __attribute__((swift_name("quantityUnitText")));

/** Parsed coding system for substance identifier (INV-1.3) **/
@property (readonly) NSString * _Nullable substanceCodeSystem __attribute__((swift_name("substanceCodeSystem")));

/** Parsed substance identifier code (INV-1.1) **/
@property (readonly) NSString *substanceId __attribute__((swift_name("substanceId")));

/** Parsed substance name or description (INV-1.2) **/
@property (readonly) NSString * _Nullable substanceName __attribute__((swift_name("substanceName")));

/** Parsed current substance status (available, expired, etc.) (INV-2) **/
@property (readonly) NSString * _Nullable substanceStatus __attribute__((swift_name("substanceStatus")));

/** Parsed supplier or vendor name of the substance (INV-18) **/
@property (readonly) NSString * _Nullable supplierName __attribute__((swift_name("supplierName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InventoryData")))
@interface ComposeAppInventoryData : ComposeAppBase
- (instancetype)initWithEquipmentId:(NSString *)equipmentId equipmentIdNamespace:(NSString * _Nullable)equipmentIdNamespace eventDateTime:(NSString * _Nullable)eventDateTime equipmentState:(NSString * _Nullable)equipmentState equipmentName:(NSString * _Nullable)equipmentName equipmentType:(NSString * _Nullable)equipmentType bins:(NSArray<ComposeAppInventoryBinData *> *)bins __attribute__((swift_name("init(equipmentId:equipmentIdNamespace:eventDateTime:equipmentState:equipmentName:equipmentType:bins:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppInventoryData *)doCopyEquipmentId:(NSString *)equipmentId equipmentIdNamespace:(NSString * _Nullable)equipmentIdNamespace eventDateTime:(NSString * _Nullable)eventDateTime equipmentState:(NSString * _Nullable)equipmentState equipmentName:(NSString * _Nullable)equipmentName equipmentType:(NSString * _Nullable)equipmentType bins:(NSArray<ComposeAppInventoryBinData *> *)bins __attribute__((swift_name("doCopy(equipmentId:equipmentIdNamespace:eventDateTime:equipmentState:equipmentName:equipmentType:bins:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed inventory bins associated with this equipment **/
@property (readonly) NSArray<ComposeAppInventoryBinData *> *bins __attribute__((swift_name("bins")));

/** Parsed equipment identifier code (EQU-1.1) **/
@property (readonly) NSString *equipmentId __attribute__((swift_name("equipmentId")));

/** Parsed namespace for equipment identifier (EQU-1.2) **/
@property (readonly) NSString * _Nullable equipmentIdNamespace __attribute__((swift_name("equipmentIdNamespace")));

/** Parsed human-readable equipment name **/
@property (readonly) NSString * _Nullable equipmentName __attribute__((swift_name("equipmentName")));

/** Parsed current operational state of the equipment (EQU-3) **/
@property (readonly) NSString * _Nullable equipmentState __attribute__((swift_name("equipmentState")));

/** Parsed equipment type or classification **/
@property (readonly) NSString * _Nullable equipmentType __attribute__((swift_name("equipmentType")));

/** Parsed date and time of the inventory event (EQU-2) **/
@property (readonly) NSString * _Nullable eventDateTime __attribute__((swift_name("eventDateTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MedicationData")))
@interface ComposeAppMedicationData : ComposeAppBase
- (instancetype)initWithDrugCode:(NSString *)drugCode drugName:(NSString *)drugName drugCodeSystem:(NSString * _Nullable)drugCodeSystem requestedQty:(NSString * _Nullable)requestedQty requestedQtyMax:(NSString * _Nullable)requestedQtyMax qtyUnitCode:(NSString * _Nullable)qtyUnitCode qtyUnitText:(NSString * _Nullable)qtyUnitText dosageFormCode:(NSString * _Nullable)dosageFormCode dosageFormText:(NSString * _Nullable)dosageFormText adminInstructions:(NSString * _Nullable)adminInstructions deliverToLocation:(NSString * _Nullable)deliverToLocation dispenseAmount:(NSString * _Nullable)dispenseAmount dispenseUnitsCode:(NSString * _Nullable)dispenseUnitsCode dispenseUnitsText:(NSString * _Nullable)dispenseUnitsText numberOfRefills:(NSString * _Nullable)numberOfRefills pharmacistVerifierId:(NSString * _Nullable)pharmacistVerifierId pharmacyInstructions:(NSString * _Nullable)pharmacyInstructions __attribute__((swift_name("init(drugCode:drugName:drugCodeSystem:requestedQty:requestedQtyMax:qtyUnitCode:qtyUnitText:dosageFormCode:dosageFormText:adminInstructions:deliverToLocation:dispenseAmount:dispenseUnitsCode:dispenseUnitsText:numberOfRefills:pharmacistVerifierId:pharmacyInstructions:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppMedicationData *)doCopyDrugCode:(NSString *)drugCode drugName:(NSString *)drugName drugCodeSystem:(NSString * _Nullable)drugCodeSystem requestedQty:(NSString * _Nullable)requestedQty requestedQtyMax:(NSString * _Nullable)requestedQtyMax qtyUnitCode:(NSString * _Nullable)qtyUnitCode qtyUnitText:(NSString * _Nullable)qtyUnitText dosageFormCode:(NSString * _Nullable)dosageFormCode dosageFormText:(NSString * _Nullable)dosageFormText adminInstructions:(NSString * _Nullable)adminInstructions deliverToLocation:(NSString * _Nullable)deliverToLocation dispenseAmount:(NSString * _Nullable)dispenseAmount dispenseUnitsCode:(NSString * _Nullable)dispenseUnitsCode dispenseUnitsText:(NSString * _Nullable)dispenseUnitsText numberOfRefills:(NSString * _Nullable)numberOfRefills pharmacistVerifierId:(NSString * _Nullable)pharmacistVerifierId pharmacyInstructions:(NSString * _Nullable)pharmacyInstructions __attribute__((swift_name("doCopy(drugCode:drugName:drugCodeSystem:requestedQty:requestedQtyMax:qtyUnitCode:qtyUnitText:dosageFormCode:dosageFormText:adminInstructions:deliverToLocation:dispenseAmount:dispenseUnitsCode:dispenseUnitsText:numberOfRefills:pharmacistVerifierId:pharmacyInstructions:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed administration instructions for the medication (RXE-7) **/
@property (readonly) NSString * _Nullable adminInstructions __attribute__((swift_name("adminInstructions")));

/** Parsed location where medication should be delivered (RXE-8) **/
@property (readonly) NSString * _Nullable deliverToLocation __attribute__((swift_name("deliverToLocation")));

/** Parsed amount to dispense per action (RXE-10) **/
@property (readonly) NSString * _Nullable dispenseAmount __attribute__((swift_name("dispenseAmount")));

/** Parsed unit code for dispensed amount (RXE-11.1) **/
@property (readonly) NSString * _Nullable dispenseUnitsCode __attribute__((swift_name("dispenseUnitsCode")));

/** Parsed unit text for dispensed amount (RXE-11.2) **/
@property (readonly) NSString * _Nullable dispenseUnitsText __attribute__((swift_name("dispenseUnitsText")));

/** Parsed dosage form code indicating medication form (RXE-6.1) **/
@property (readonly) NSString * _Nullable dosageFormCode __attribute__((swift_name("dosageFormCode")));

/** Parsed dosage form text (RXE-6.2) **/
@property (readonly) NSString * _Nullable dosageFormText __attribute__((swift_name("dosageFormText")));

/** Parsed medication identifier code (RXE-2.1) **/
@property (readonly) NSString *drugCode __attribute__((swift_name("drugCode")));

/** Parsed coding system for medication identifier (e.g., RXNORM) (RXE-2.3) **/
@property (readonly) NSString * _Nullable drugCodeSystem __attribute__((swift_name("drugCodeSystem")));

/** Parsed medication display name (RXE-2.2) **/
@property (readonly) NSString *drugName __attribute__((swift_name("drugName")));

/** Parsed number of refills allowed (RXE-12) **/
@property (readonly) NSString * _Nullable numberOfRefills __attribute__((swift_name("numberOfRefills")));

/** Parsed pharmacist identifier who verified the order (RXE-14.1) **/
@property (readonly) NSString * _Nullable pharmacistVerifierId __attribute__((swift_name("pharmacistVerifierId")));

/** Parsed free-text pharmacy instructions (RXE-21) **/
@property (readonly) NSString * _Nullable pharmacyInstructions __attribute__((swift_name("pharmacyInstructions")));

/** Parsed unit code for requested quantity (RXE-5.1) **/
@property (readonly) NSString * _Nullable qtyUnitCode __attribute__((swift_name("qtyUnitCode")));

/** Parsed unit text for requested quantity (RXE-5.2) **/
@property (readonly) NSString * _Nullable qtyUnitText __attribute__((swift_name("qtyUnitText")));

/** Parsed quantity requested to be dispensed (RXE-3) **/
@property (readonly) NSString * _Nullable requestedQty __attribute__((swift_name("requestedQty")));

/** Parsed maximum quantity allowed to dispense (RXE-4) **/
@property (readonly) NSString * _Nullable requestedQtyMax __attribute__((swift_name("requestedQtyMax")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageHeaderData")))
@interface ComposeAppMessageHeaderData : ComposeAppBase
- (instancetype)initWithFieldSeparator:(NSString *)fieldSeparator encodingCharacters:(NSString *)encodingCharacters sendingApplication:(NSString *)sendingApplication sendingFacility:(NSString *)sendingFacility receivingApplication:(NSString *)receivingApplication receivingFacility:(NSString *)receivingFacility messageDateTime:(NSString *)messageDateTime messageType:(NSString *)messageType triggerEvent:(NSString *)triggerEvent messageControlId:(NSString *)messageControlId processingId:(NSString *)processingId versionId:(NSString *)versionId countryCode:(NSString * _Nullable)countryCode __attribute__((swift_name("init(fieldSeparator:encodingCharacters:sendingApplication:sendingFacility:receivingApplication:receivingFacility:messageDateTime:messageType:triggerEvent:messageControlId:processingId:versionId:countryCode:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppMessageHeaderData *)doCopyFieldSeparator:(NSString *)fieldSeparator encodingCharacters:(NSString *)encodingCharacters sendingApplication:(NSString *)sendingApplication sendingFacility:(NSString *)sendingFacility receivingApplication:(NSString *)receivingApplication receivingFacility:(NSString *)receivingFacility messageDateTime:(NSString *)messageDateTime messageType:(NSString *)messageType triggerEvent:(NSString *)triggerEvent messageControlId:(NSString *)messageControlId processingId:(NSString *)processingId versionId:(NSString *)versionId countryCode:(NSString * _Nullable)countryCode __attribute__((swift_name("doCopy(fieldSeparator:encodingCharacters:sendingApplication:sendingFacility:receivingApplication:receivingFacility:messageDateTime:messageType:triggerEvent:messageControlId:processingId:versionId:countryCode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed optional country code if present (MSH-17) **/
@property (readonly) NSString * _Nullable countryCode __attribute__((swift_name("countryCode")));

/** Parsed encoding characters defining HL7 delimiters (MSH-2) **/
@property (readonly) NSString *encodingCharacters __attribute__((swift_name("encodingCharacters")));

/** Parsed field separator used in this HL7 message (MSH-1) **/
@property (readonly) NSString *fieldSeparator __attribute__((swift_name("fieldSeparator")));

/** Parsed unique message control ID for ACK and idempotency (MSH-10) **/
@property (readonly) NSString *messageControlId __attribute__((swift_name("messageControlId")));

/** Parsed message creation date and time (MSH-7) **/
@property (readonly) NSString *messageDateTime __attribute__((swift_name("messageDateTime")));

/** Parsed HL7 message type (e.g., ADT, RDS, ORM) (MSH-9.1) **/
@property (readonly) NSString *messageType __attribute__((swift_name("messageType")));

/** Parsed processing mode indicator (P=Production, T=Test) (MSH-11) **/
@property (readonly) NSString *processingId __attribute__((swift_name("processingId")));

/** Parsed receiving application identifier (MSH-5) **/
@property (readonly) NSString *receivingApplication __attribute__((swift_name("receivingApplication")));

/** Parsed receiving facility identifier (MSH-6) **/
@property (readonly) NSString *receivingFacility __attribute__((swift_name("receivingFacility")));

/** Parsed sending application identifier (MSH-3) **/
@property (readonly) NSString *sendingApplication __attribute__((swift_name("sendingApplication")));

/** Parsed sending facility identifier (MSH-4) **/
@property (readonly) NSString *sendingFacility __attribute__((swift_name("sendingFacility")));

/** Parsed HL7 trigger event (e.g., A01, O13) (MSH-9.2) **/
@property (readonly) NSString *triggerEvent __attribute__((swift_name("triggerEvent")));

/** Parsed HL7 version identifier (e.g., 2.3, 2.5.1) (MSH-12) **/
@property (readonly) NSString *versionId __attribute__((swift_name("versionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NoteData")))
@interface ComposeAppNoteData : ComposeAppBase
- (instancetype)initWithSetId:(NSString * _Nullable)setId sourceOfComment:(NSString * _Nullable)sourceOfComment comment:(NSString *)comment commentType:(NSString * _Nullable)commentType __attribute__((swift_name("init(setId:sourceOfComment:comment:commentType:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppNoteData *)doCopySetId:(NSString * _Nullable)setId sourceOfComment:(NSString * _Nullable)sourceOfComment comment:(NSString *)comment commentType:(NSString * _Nullable)commentType __attribute__((swift_name("doCopy(setId:sourceOfComment:comment:commentType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed note or comment text (NTE-3) **/
@property (readonly) NSString *comment __attribute__((swift_name("comment")));

/** Parsed note type or classification (NTE-4) **/
@property (readonly) NSString * _Nullable commentType __attribute__((swift_name("commentType")));

/** Parsed note set identifier (NTE-1) **/
@property (readonly) NSString * _Nullable setId __attribute__((swift_name("setId")));

/** Parsed source of the comment (NTE-2) **/
@property (readonly) NSString * _Nullable sourceOfComment __attribute__((swift_name("sourceOfComment")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderData")))
@interface ComposeAppOrderData : ComposeAppBase
- (instancetype)initWithOrderControl:(NSString *)orderControl placerOrderId:(NSString *)placerOrderId placerOrderNamespace:(NSString * _Nullable)placerOrderNamespace fillerOrderId:(NSString * _Nullable)fillerOrderId fillerOrderNamespace:(NSString * _Nullable)fillerOrderNamespace orderStatus:(NSString * _Nullable)orderStatus orderDateTime:(NSString * _Nullable)orderDateTime orderingProviderId:(NSString * _Nullable)orderingProviderId orderingProviderFamilyName:(NSString * _Nullable)orderingProviderFamilyName orderingProviderGivenName:(NSString * _Nullable)orderingProviderGivenName orderingFacility:(NSString * _Nullable)orderingFacility __attribute__((swift_name("init(orderControl:placerOrderId:placerOrderNamespace:fillerOrderId:fillerOrderNamespace:orderStatus:orderDateTime:orderingProviderId:orderingProviderFamilyName:orderingProviderGivenName:orderingFacility:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppOrderData *)doCopyOrderControl:(NSString *)orderControl placerOrderId:(NSString *)placerOrderId placerOrderNamespace:(NSString * _Nullable)placerOrderNamespace fillerOrderId:(NSString * _Nullable)fillerOrderId fillerOrderNamespace:(NSString * _Nullable)fillerOrderNamespace orderStatus:(NSString * _Nullable)orderStatus orderDateTime:(NSString * _Nullable)orderDateTime orderingProviderId:(NSString * _Nullable)orderingProviderId orderingProviderFamilyName:(NSString * _Nullable)orderingProviderFamilyName orderingProviderGivenName:(NSString * _Nullable)orderingProviderGivenName orderingFacility:(NSString * _Nullable)orderingFacility __attribute__((swift_name("doCopy(orderControl:placerOrderId:placerOrderNamespace:fillerOrderId:fillerOrderNamespace:orderStatus:orderDateTime:orderingProviderId:orderingProviderFamilyName:orderingProviderGivenName:orderingFacility:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed filler order identifier assigned by receiving system (ORC-3.1) **/
@property (readonly) NSString * _Nullable fillerOrderId __attribute__((swift_name("fillerOrderId")));

/** Parsed namespace for filler order identifier (ORC-3.2) **/
@property (readonly) NSString * _Nullable fillerOrderNamespace __attribute__((swift_name("fillerOrderNamespace")));

/** Parsed order control code driving order workflow (ORC-1) **/
@property (readonly) NSString *orderControl __attribute__((swift_name("orderControl")));

/** Parsed date and time the order was created or last updated (ORC-9) **/
@property (readonly) NSString * _Nullable orderDateTime __attribute__((swift_name("orderDateTime")));

/** Parsed current status of the order (ORC-5) **/
@property (readonly) NSString * _Nullable orderStatus __attribute__((swift_name("orderStatus")));

/** Parsed facility that originated the order (ORC-21) **/
@property (readonly) NSString * _Nullable orderingFacility __attribute__((swift_name("orderingFacility")));

/** Parsed ordering provider family name (ORC-12.2) **/
@property (readonly) NSString * _Nullable orderingProviderFamilyName __attribute__((swift_name("orderingProviderFamilyName")));

/** Parsed ordering provider given name (ORC-12.3) **/
@property (readonly) NSString * _Nullable orderingProviderGivenName __attribute__((swift_name("orderingProviderGivenName")));

/** Parsed ordering provider identifier (ORC-12.1) **/
@property (readonly) NSString * _Nullable orderingProviderId __attribute__((swift_name("orderingProviderId")));

/** Parsed placer order identifier used as primary business ID (ORC-2.1) **/
@property (readonly) NSString *placerOrderId __attribute__((swift_name("placerOrderId")));

/** Parsed namespace for placer order identifier (ORC-2.2) **/
@property (readonly) NSString * _Nullable placerOrderNamespace __attribute__((swift_name("placerOrderNamespace")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PatientData")))
@interface ComposeAppPatientData : ComposeAppBase
- (instancetype)initWithPatientId:(NSString *)patientId patientIdAssigningAuthority:(NSString * _Nullable)patientIdAssigningAuthority patientIdType:(NSString * _Nullable)patientIdType familyName:(NSString * _Nullable)familyName givenName:(NSString * _Nullable)givenName middleName:(NSString * _Nullable)middleName dateOfBirth:(NSString * _Nullable)dateOfBirth sex:(NSString * _Nullable)sex streetAddress:(NSString * _Nullable)streetAddress city:(NSString * _Nullable)city state:(NSString * _Nullable)state zipCode:(NSString * _Nullable)zipCode country:(NSString * _Nullable)country __attribute__((swift_name("init(patientId:patientIdAssigningAuthority:patientIdType:familyName:givenName:middleName:dateOfBirth:sex:streetAddress:city:state:zipCode:country:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppPatientData *)doCopyPatientId:(NSString *)patientId patientIdAssigningAuthority:(NSString * _Nullable)patientIdAssigningAuthority patientIdType:(NSString * _Nullable)patientIdType familyName:(NSString * _Nullable)familyName givenName:(NSString * _Nullable)givenName middleName:(NSString * _Nullable)middleName dateOfBirth:(NSString * _Nullable)dateOfBirth sex:(NSString * _Nullable)sex streetAddress:(NSString * _Nullable)streetAddress city:(NSString * _Nullable)city state:(NSString * _Nullable)state zipCode:(NSString * _Nullable)zipCode country:(NSString * _Nullable)country __attribute__((swift_name("doCopy(patientId:patientIdAssigningAuthority:patientIdType:familyName:givenName:middleName:dateOfBirth:sex:streetAddress:city:state:zipCode:country:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed patient city (PID-11.3) **/
@property (readonly) NSString * _Nullable city __attribute__((swift_name("city")));

/** Parsed patient country (PID-11.6) **/
@property (readonly) NSString * _Nullable country __attribute__((swift_name("country")));

/** Parsed patient date of birth (YYYYMMDD) (PID-7) **/
@property (readonly) NSString * _Nullable dateOfBirth __attribute__((swift_name("dateOfBirth")));

/** Parsed patient family/last name (PID-5.1) **/
@property (readonly) NSString * _Nullable familyName __attribute__((swift_name("familyName")));

/** Parsed patient given/first name (PID-5.2) **/
@property (readonly) NSString * _Nullable givenName __attribute__((swift_name("givenName")));

/** Parsed patient middle name or initial (PID-5.3) **/
@property (readonly) NSString * _Nullable middleName __attribute__((swift_name("middleName")));

/** Parsed primary patient identifier (MRN) (PID-3.1) **/
@property (readonly) NSString *patientId __attribute__((swift_name("patientId")));

/** Parsed assigning authority for patient identifier (PID-3.4) **/
@property (readonly) NSString * _Nullable patientIdAssigningAuthority __attribute__((swift_name("patientIdAssigningAuthority")));

/** Parsed identifier type code (MR, SS, etc.) (PID-3.5) **/
@property (readonly) NSString * _Nullable patientIdType __attribute__((swift_name("patientIdType")));

/** Parsed administrative sex (PID-8) **/
@property (readonly) NSString * _Nullable sex __attribute__((swift_name("sex")));

/** Parsed patient state or province (PID-11.4) **/
@property (readonly) NSString * _Nullable state __attribute__((swift_name("state")));

/** Parsed patient street address (PID-11.1) **/
@property (readonly) NSString * _Nullable streetAddress __attribute__((swift_name("streetAddress")));

/** Parsed patient postal or ZIP code (PID-11.5) **/
@property (readonly) NSString * _Nullable zipCode __attribute__((swift_name("zipCode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RouteData")))
@interface ComposeAppRouteData : ComposeAppBase
- (instancetype)initWithRouteCode:(NSString * _Nullable)routeCode routeText:(NSString * _Nullable)routeText routeCodeSystem:(NSString * _Nullable)routeCodeSystem adminSiteCode:(NSString * _Nullable)adminSiteCode adminSiteText:(NSString * _Nullable)adminSiteText adminDeviceCode:(NSString * _Nullable)adminDeviceCode adminDeviceText:(NSString * _Nullable)adminDeviceText __attribute__((swift_name("init(routeCode:routeText:routeCodeSystem:adminSiteCode:adminSiteText:adminDeviceCode:adminDeviceText:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppRouteData *)doCopyRouteCode:(NSString * _Nullable)routeCode routeText:(NSString * _Nullable)routeText routeCodeSystem:(NSString * _Nullable)routeCodeSystem adminSiteCode:(NSString * _Nullable)adminSiteCode adminSiteText:(NSString * _Nullable)adminSiteText adminDeviceCode:(NSString * _Nullable)adminDeviceCode adminDeviceText:(NSString * _Nullable)adminDeviceText __attribute__((swift_name("doCopy(routeCode:routeText:routeCodeSystem:adminSiteCode:adminSiteText:adminDeviceCode:adminDeviceText:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed administration device code (RXR-3.1) **/
@property (readonly) NSString * _Nullable adminDeviceCode __attribute__((swift_name("adminDeviceCode")));

/** Parsed administration device text (RXR-3.2) **/
@property (readonly) NSString * _Nullable adminDeviceText __attribute__((swift_name("adminDeviceText")));

/** Parsed administration site code (RXR-2.1) **/
@property (readonly) NSString * _Nullable adminSiteCode __attribute__((swift_name("adminSiteCode")));

/** Parsed administration site text (RXR-2.2) **/
@property (readonly) NSString * _Nullable adminSiteText __attribute__((swift_name("adminSiteText")));

/** Parsed medication administration route code (RXR-1.1) **/
@property (readonly) NSString * _Nullable routeCode __attribute__((swift_name("routeCode")));

/** Parsed coding system for route identifier (RXR-1.3) **/
@property (readonly) NSString * _Nullable routeCodeSystem __attribute__((swift_name("routeCodeSystem")));

/** Parsed medication administration route text (RXR-1.2) **/
@property (readonly) NSString * _Nullable routeText __attribute__((swift_name("routeText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VisitData")))
@interface ComposeAppVisitData : ComposeAppBase
- (instancetype)initWithVisitNumber:(NSString * _Nullable)visitNumber visitNumberAssigningAuthority:(NSString * _Nullable)visitNumberAssigningAuthority patientClass:(NSString * _Nullable)patientClass locPointOfCare:(NSString * _Nullable)locPointOfCare locRoom:(NSString * _Nullable)locRoom locBed:(NSString * _Nullable)locBed locFacility:(NSString * _Nullable)locFacility attendingDoctorId:(NSString * _Nullable)attendingDoctorId attendingDoctorFamilyName:(NSString * _Nullable)attendingDoctorFamilyName attendingDoctorGivenName:(NSString * _Nullable)attendingDoctorGivenName admitDateTime:(NSString * _Nullable)admitDateTime __attribute__((swift_name("init(visitNumber:visitNumberAssigningAuthority:patientClass:locPointOfCare:locRoom:locBed:locFacility:attendingDoctorId:attendingDoctorFamilyName:attendingDoctorGivenName:admitDateTime:)"))) __attribute__((objc_designated_initializer));
- (ComposeAppVisitData *)doCopyVisitNumber:(NSString * _Nullable)visitNumber visitNumberAssigningAuthority:(NSString * _Nullable)visitNumberAssigningAuthority patientClass:(NSString * _Nullable)patientClass locPointOfCare:(NSString * _Nullable)locPointOfCare locRoom:(NSString * _Nullable)locRoom locBed:(NSString * _Nullable)locBed locFacility:(NSString * _Nullable)locFacility attendingDoctorId:(NSString * _Nullable)attendingDoctorId attendingDoctorFamilyName:(NSString * _Nullable)attendingDoctorFamilyName attendingDoctorGivenName:(NSString * _Nullable)attendingDoctorGivenName admitDateTime:(NSString * _Nullable)admitDateTime __attribute__((swift_name("doCopy(visitNumber:visitNumberAssigningAuthority:patientClass:locPointOfCare:locRoom:locBed:locFacility:attendingDoctorId:attendingDoctorFamilyName:attendingDoctorGivenName:admitDateTime:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Parsed patient admission date and time (PV1-44) **/
@property (readonly) NSString * _Nullable admitDateTime __attribute__((swift_name("admitDateTime")));

/** Parsed attending doctor family name (PV1-7.2) **/
@property (readonly) NSString * _Nullable attendingDoctorFamilyName __attribute__((swift_name("attendingDoctorFamilyName")));

/** Parsed attending doctor given name (PV1-7.3) **/
@property (readonly) NSString * _Nullable attendingDoctorGivenName __attribute__((swift_name("attendingDoctorGivenName")));

/** Parsed attending doctor identifier (PV1-7.1) **/
@property (readonly) NSString * _Nullable attendingDoctorId __attribute__((swift_name("attendingDoctorId")));

/** Parsed bed identifier within the room (PV1-3.3) **/
@property (readonly) NSString * _Nullable locBed __attribute__((swift_name("locBed")));

/** Parsed facility identifier for patient location (PV1-3.4) **/
@property (readonly) NSString * _Nullable locFacility __attribute__((swift_name("locFacility")));

/** Parsed point of care or ward/unit (PV1-3.1) **/
@property (readonly) NSString * _Nullable locPointOfCare __attribute__((swift_name("locPointOfCare")));

/** Parsed room identifier within the care location (PV1-3.2) **/
@property (readonly) NSString * _Nullable locRoom __attribute__((swift_name("locRoom")));

/** Parsed patient class (Inpatient, Outpatient, etc.) (PV1-2) **/
@property (readonly) NSString * _Nullable patientClass __attribute__((swift_name("patientClass")));

/** Parsed visit/encounter number (PV1-19.1) **/
@property (readonly) NSString * _Nullable visitNumber __attribute__((swift_name("visitNumber")));

/** Parsed assigning authority for visit number (PV1-19.4) **/
@property (readonly) NSString * _Nullable visitNumberAssigningAuthority __attribute__((swift_name("visitNumberAssigningAuthority")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Constants")))
@interface ComposeAppHL7Constants : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hL7Constants __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppHL7Constants *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *COMPONENT_SEPARATOR __attribute__((swift_name("COMPONENT_SEPARATOR")));
@property (readonly) NSString *ENCODING_CHARACTERS __attribute__((swift_name("ENCODING_CHARACTERS")));
@property (readonly) NSString *ESCAPE_CHARACTER __attribute__((swift_name("ESCAPE_CHARACTER")));
@property (readonly) NSString *FIELD_SEPARATOR __attribute__((swift_name("FIELD_SEPARATOR")));
@property (readonly) NSString *REPETITION_SEPARATOR __attribute__((swift_name("REPETITION_SEPARATOR")));
@property (readonly) NSString *SEGMENT_TERMINATOR __attribute__((swift_name("SEGMENT_TERMINATOR")));
@property (readonly) NSString *SUBCOMPONENT_SEPARATOR __attribute__((swift_name("SUBCOMPONENT_SEPARATOR")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7Utils")))
@interface ComposeAppHL7Utils : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hL7Utils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppHL7Utils *shared __attribute__((swift_name("shared")));
- (NSString *)buildComponentParts:(ComposeAppKotlinArray<NSString *> *)parts __attribute__((swift_name("buildComponent(parts:)")));
- (NSString *)buildFieldValue:(NSString * _Nullable)value __attribute__((swift_name("buildField(value:)")));
- (NSString *)buildSegmentSegmentType:(NSString *)segmentType fields:(ComposeAppKotlinArray<NSString *> *)fields __attribute__((swift_name("buildSegment(segmentType:fields:)")));

/**
 * Escape HL7 special characters
 */
- (NSString *)escapeHL7TextText:(NSString * _Nullable)text __attribute__((swift_name("escapeHL7Text(text:)")));

/**
 * Generate unique HL7 Message Control ID (MSH-10)
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)generateMessageControlIdWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("generateMessageControlId(completionHandler:)")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface ComposeAppKotlinThrowable : ComposeAppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (ComposeAppKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) ComposeAppKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface ComposeAppKotlinException : ComposeAppKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Hl7ParseException")))
@interface ComposeAppHl7ParseException : ComposeAppKotlinException
- (instancetype)initWithMessage:(NSString *)message segment:(NSString * _Nullable)segment field:(NSString * _Nullable)field cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:segment:field:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) NSString * _Nullable segment __attribute__((swift_name("segment")));
@end


/***************** HL7 PARSER *******************/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Hl7Parser")))
@interface ComposeAppHl7Parser : ComposeAppBase

/***************** HL7 PARSER *******************/
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/***************** HL7 PARSER *******************/
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) ComposeAppHl7ParserCompanion *companion __attribute__((swift_name("companion")));

/** Parse raw HL7 string into CompleteHL7Message **/
- (ComposeAppCompleteHL7Message *)parseHl7Message:(NSString *)hl7Message __attribute__((swift_name("parse(hl7Message:)")));

/*** Parse HL7 message received over (TCP) ***/
- (ComposeAppCompleteHL7Message *)parseMllpMessageMllpWrapped:(ComposeAppKotlinByteArray *)mllpWrapped __attribute__((swift_name("parseMllpMessage(mllpWrapped:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Hl7Parser.Companion")))
@interface ComposeAppHl7ParserCompanion : ComposeAppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) ComposeAppHl7ParserCompanion *shared __attribute__((swift_name("shared")));
@end

@interface ComposeAppCompleteHL7Message (Extensions)

/**
 * Generate idempotency key for database unique constraint
 * Recommended: (sending_facility + placer_order_id + order_control)
 */
- (NSString *)generateIdempotencyKey __attribute__((swift_name("generateIdempotencyKey()")));

/**
 * Alternative idempotency key using message control ID
 * Use when the same order might be sent multiple times with different control codes
 */
- (NSString *)generateMessageIdempotencyKey __attribute__((swift_name("generateMessageIdempotencyKey()")));

/**
 * Extension function to build HL7 message with MLLP framing
 */
- (ComposeAppKotlinByteArray *)toHL7BytesWithMllp __attribute__((swift_name("toHL7BytesWithMllp()")));

/**
 * Extension function to build HL7 message from CompleteHL7Message
 */
- (NSString *)toHL7String __attribute__((swift_name("toHL7String()")));

/**
 * Extension function to build typed message with validation
 */
- (NSString *)toTypedHL7String __attribute__((swift_name("toTypedHL7String()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CurrentLocalDateTime_iosKt")))
@interface ComposeAppCurrentLocalDateTime_iosKt : ComposeAppBase
+ (NSString *)currentLocalDateTime __attribute__((swift_name("currentLocalDateTime()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquBuilderKt")))
@interface ComposeAppEquBuilderKt : ComposeAppBase
+ (NSString *)buildEQUInventory:(ComposeAppInventoryData *)inventory __attribute__((swift_name("buildEQU(inventory:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EquParserKt")))
@interface ComposeAppEquParserKt : ComposeAppBase

/**
 * Parses inventory equipment and associated inventory bins.
 * Combines EQU (equipment) with related INV (bin) segments.
 */
+ (ComposeAppInventoryData * _Nullable)parseInventorySegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseInventory(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HL7ParserKt")))
@interface ComposeAppHL7ParserKt : ComposeAppBase
+ (NSString * _Nullable)parseHl7TimestampHl7Time:(NSString *)hl7Time __attribute__((swift_name("parseHl7Timestamp(hl7Time:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvBuilderKt")))
@interface ComposeAppInvBuilderKt : ComposeAppBase
+ (NSString *)buildINVBin:(ComposeAppInventoryBinData *)bin __attribute__((swift_name("buildINV(bin:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvParserKt")))
@interface ComposeAppInvParserKt : ComposeAppBase

/**
 * Parses an INV segment and extracts inventory bin information.
 * Each INV represents a single storage bin or container.
 */
+ (ComposeAppInventoryBinData *)parseInventoryBinInv:(NSArray<NSString *> *)inv compSep:(NSString *)compSep __attribute__((swift_name("parseInventoryBin(inv:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MshBuilderKt")))
@interface ComposeAppMshBuilderKt : ComposeAppBase

/**
 * Serializes a MessageHeaderData object into an HL7 MSH segment.
 *
 * HL7 MSH rules:
 * - MSH-1 (Field Separator) is implicit and NOT serialized as a field.
 * - Fields are positional and must include empty placeholders.
 * - Maximum allowed fields depend on HL7 version (2.1 → 2.8).
 */
+ (NSString *)buildMSHHeader:(ComposeAppMessageHeaderData *)header __attribute__((swift_name("buildMSH(header:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MshParserKt")))
@interface ComposeAppMshParserKt : ComposeAppBase

/**
 * Parses the MSH segment and extracts message-level metadata.
 * MSH must be parsed first because it defines separators and message identity.
 */
+ (ComposeAppMessageHeaderData *)mshParserMsh:(NSString *)msh __attribute__((swift_name("mshParser(msh:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrcBuilderKt")))
@interface ComposeAppOrcBuilderKt : ComposeAppBase
+ (NSString *)buildORCOrder:(ComposeAppOrderData *)order __attribute__((swift_name("buildORC(order:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrcParserKt")))
@interface ComposeAppOrcParserKt : ComposeAppBase

/**
 * Parses the ORC segment and extracts order-level information.
 * ORC defines order control, identifiers, and ordering provider details.
 */
+ (ComposeAppOrderData * _Nullable)parseOrderSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseOrder(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PidBuilderKt")))
@interface ComposeAppPidBuilderKt : ComposeAppBase
+ (NSString *)buildPIDPatient:(ComposeAppPatientData *)patient __attribute__((swift_name("buildPID(patient:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PidParserKt")))
@interface ComposeAppPidParserKt : ComposeAppBase

/**
 * Parses the PID segment and extracts patient identity and demographic details.
 * Returns null if the PID segment is not present in the message.
 */
+ (ComposeAppPatientData * _Nullable)patientParserSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("patientParser(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Pv1BuilderKt")))
@interface ComposeAppPv1BuilderKt : ComposeAppBase
+ (NSString *)buildPV1Visit:(ComposeAppVisitData *)visit __attribute__((swift_name("buildPV1(visit:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Pv1ParserKt")))
@interface ComposeAppPv1ParserKt : ComposeAppBase

/**
 * Parses the PV1 segment and extracts patient visit and encounter details.
 * PV1 defines where the patient is located and who is responsible for care.
 */
+ (ComposeAppVisitData * _Nullable)parseVisitSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseVisit(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxcBuilderKt")))
@interface ComposeAppRxcBuilderKt : ComposeAppBase

/**
 * Builds the HL7 RXC (Pharmacy/Treatment Component) segment.
 */
+ (NSString *)buildRXCComponent:(ComposeAppComponentData *)component __attribute__((swift_name("buildRXC(component:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxcParserKt")))
@interface ComposeAppRxcParserKt : ComposeAppBase

/**
 * Parses RXC segments and extracts compound medication component details.
 * Each RXC represents a single ingredient or component of a compounded medication.
 */
+ (NSArray<ComposeAppComponentData *> *)parseComponentsSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseComponents(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxdBuilderKt")))
@interface ComposeAppRxdBuilderKt : ComposeAppBase

/**
 * Serializes a DispenseData object into an HL7 RXD segment.
 *
 * RXD notes:
 * - RXD is stable across HL7 v2.1–v2.8
 * - Field positions must be preserved
 * - Empty placeholders are required
 */
+ (NSString *)buildRXDDispense:(ComposeAppDispenseData *)dispense hl7Version:(NSString *)hl7Version __attribute__((swift_name("buildRXD(dispense:hl7Version:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxdParserKt")))
@interface ComposeAppRxdParserKt : ComposeAppBase

/**
 * Parses RXD segments and extracts actual medication dispense information.
 * Each RXD represents what was physically dispensed to the patient.
 */
+ (NSArray<ComposeAppDispenseData *> *)parseDispensesSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseDispenses(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxeBuilderKt")))
@interface ComposeAppRxeBuilderKt : ComposeAppBase

/**
 * Builds the HL7 RXE (Pharmacy/Treatment Encoded Order) segment.
 */
+ (NSString *)buildRXEMedication:(ComposeAppMedicationData *)medication __attribute__((swift_name("buildRXE(medication:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxeParserKt")))
@interface ComposeAppRxeParserKt : ComposeAppBase

/**
 * Parses RXE segments and extracts medication order details.
 * Each RXE represents one ordered medication.
 */
+ (NSArray<ComposeAppMedicationData *> *)parseMedicationsSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseMedications(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxrBuilderKt")))
@interface ComposeAppRxrBuilderKt : ComposeAppBase
+ (NSString *)buildRXRRoute:(ComposeAppRouteData *)route __attribute__((swift_name("buildRXR(route:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RxrParserKt")))
@interface ComposeAppRxrParserKt : ComposeAppBase

/**
 * Parses RXR segments and extracts medication administration route details.
 * Each RXR defines how and where a medication is administered.
 */
+ (NSArray<ComposeAppRouteData *> *)parseRoutesSegments:(NSDictionary<NSString *, NSArray<NSArray<NSString *> *> *> *)segments compSep:(NSString *)compSep __attribute__((swift_name("parseRoutes(segments:compSep:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface ComposeAppKotlinByteArray : ComposeAppBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(ComposeAppByte *(^)(ComposeAppInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (ComposeAppKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface ComposeAppKotlinRuntimeException : ComposeAppKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface ComposeAppKotlinIllegalStateException : ComposeAppKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface ComposeAppKotlinCancellationException : ComposeAppKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(ComposeAppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface ComposeAppKotlinArray<T> : ComposeAppBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(ComposeAppInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<ComposeAppKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol ComposeAppKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface ComposeAppKotlinByteIterator : ComposeAppBase <ComposeAppKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (ComposeAppByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
