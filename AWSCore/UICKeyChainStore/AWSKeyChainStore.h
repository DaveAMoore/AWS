//
//  AWSKeyChainStore.h
//  AWSKeyChainStore
//
//  Created by Kishikawa Katsumi on 11/11/20.
//  Copyright (c) 2011 Kishikawa Katsumi. All rights reserved.
//

#import <Foundation/Foundation.h>

#if !__has_feature(nullability)
#define NS_ASSUME_NONNULL_BEGIN
#define NS_ASSUME_NONNULL_END
#define nullable
#define nonnull
#define null_unspecified
#define null_resettable
#define __nullable
#define __nonnull
#define __null_unspecified
#endif

#if __has_extension(objc_generics)
#define AWS_KEY_TYPE <NSString *>
#define AWS_CREDENTIAL_TYPE <NSDictionary <NSString *, NSString *>*>
#else
#define AWS_KEY_TYPE
#define AWS_CREDENTIAL_TYPE
#endif

NS_ASSUME_NONNULL_BEGIN

extern NSString * const AWSKeyChainStoreErrorDomain;

typedef NS_ENUM(NSInteger, AWSKeyChainStoreErrorCode) {
    AWSKeyChainStoreErrorInvalidArguments = 1,
};

typedef NS_ENUM(NSInteger, AWSKeyChainStoreItemClass) {
    AWSKeyChainStoreItemClassGenericPassword = 1,
    AWSKeyChainStoreItemClassInternetPassword,
};

typedef NS_ENUM(NSInteger, AWSKeyChainStoreProtocolType) {
    AWSKeyChainStoreProtocolTypeFTP = 1,
    AWSKeyChainStoreProtocolTypeFTPAccount,
    AWSKeyChainStoreProtocolTypeHTTP,
    AWSKeyChainStoreProtocolTypeIRC,
    AWSKeyChainStoreProtocolTypeNNTP,
    AWSKeyChainStoreProtocolTypePOP3,
    AWSKeyChainStoreProtocolTypeSMTP,
    AWSKeyChainStoreProtocolTypeSOCKS,
    AWSKeyChainStoreProtocolTypeIMAP,
    AWSKeyChainStoreProtocolTypeLDAP,
    AWSKeyChainStoreProtocolTypeAppleTalk,
    AWSKeyChainStoreProtocolTypeAFP,
    AWSKeyChainStoreProtocolTypeTelnet,
    AWSKeyChainStoreProtocolTypeSSH,
    AWSKeyChainStoreProtocolTypeFTPS,
    AWSKeyChainStoreProtocolTypeHTTPS,
    AWSKeyChainStoreProtocolTypeHTTPProxy,
    AWSKeyChainStoreProtocolTypeHTTPSProxy,
    AWSKeyChainStoreProtocolTypeFTPProxy,
    AWSKeyChainStoreProtocolTypeSMB,
    AWSKeyChainStoreProtocolTypeRTSP,
    AWSKeyChainStoreProtocolTypeRTSPProxy,
    AWSKeyChainStoreProtocolTypeDAAP,
    AWSKeyChainStoreProtocolTypeEPPC,
    AWSKeyChainStoreProtocolTypeNNTPS,
    AWSKeyChainStoreProtocolTypeLDAPS,
    AWSKeyChainStoreProtocolTypeTelnetS,
    AWSKeyChainStoreProtocolTypeIRCS,
    AWSKeyChainStoreProtocolTypePOP3S,
};

typedef NS_ENUM(NSInteger, AWSKeyChainStoreAuthenticationType) {
    AWSKeyChainStoreAuthenticationTypeNTLM = 1,
    AWSKeyChainStoreAuthenticationTypeMSN,
    AWSKeyChainStoreAuthenticationTypeDPA,
    AWSKeyChainStoreAuthenticationTypeRPA,
    AWSKeyChainStoreAuthenticationTypeHTTPBasic,
    AWSKeyChainStoreAuthenticationTypeHTTPDigest,
    AWSKeyChainStoreAuthenticationTypeHTMLForm,
    AWSKeyChainStoreAuthenticationTypeDefault,
};

typedef NS_ENUM(NSInteger, AWSKeyChainStoreAccessibility) {
    AWSKeyChainStoreAccessibilityWhenUnlocked = 1,
    AWSKeyChainStoreAccessibilityAfterFirstUnlock,
    AWSKeyChainStoreAccessibilityAlways,
    AWSKeyChainStoreAccessibilityWhenPasscodeSetThisDeviceOnly
    __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0),
    AWSKeyChainStoreAccessibilityWhenUnlockedThisDeviceOnly,
    AWSKeyChainStoreAccessibilityAfterFirstUnlockThisDeviceOnly,
    AWSKeyChainStoreAccessibilityAlwaysThisDeviceOnly,
}
__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_4_0);

typedef NS_ENUM(unsigned long, AWSKeyChainStoreAuthenticationPolicy) {
    AWSKeyChainStoreAuthenticationPolicyUserPresence        = 1 << 0,
    AWSKeyChainStoreAuthenticationPolicyTouchIDAny          NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 1,
    AWSKeyChainStoreAuthenticationPolicyTouchIDCurrentSet   NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 3,
    AWSKeyChainStoreAuthenticationPolicyDevicePasscode      NS_ENUM_AVAILABLE(10_11, 9_0) = 1u << 4,
    AWSKeyChainStoreAuthenticationPolicyControlOr           NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 14,
    AWSKeyChainStoreAuthenticationPolicyControlAnd          NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 15,
    AWSKeyChainStoreAuthenticationPolicyPrivateKeyUsage     NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 30,
    AWSKeyChainStoreAuthenticationPolicyApplicationPassword NS_ENUM_AVAILABLE(10_12_1, 9_0) = 1u << 31,
}__OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);

@interface AWSKeyChainStore : NSObject

@property (nonatomic, readonly) AWSKeyChainStoreItemClass itemClass;

@property (nonatomic, readonly, nullable) NSString *service;
@property (nonatomic, readonly, nullable) NSString *accessGroup;

@property (nonatomic, readonly, nullable) NSURL *server;
@property (nonatomic, readonly) AWSKeyChainStoreProtocolType protocolType;
@property (nonatomic, readonly) AWSKeyChainStoreAuthenticationType authenticationType;

@property (nonatomic) AWSKeyChainStoreAccessibility accessibility;
@property (nonatomic, readonly) AWSKeyChainStoreAuthenticationPolicy authenticationPolicy
__OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);
@property (nonatomic) BOOL useAuthenticationUI;

@property (nonatomic) BOOL synchronizable;

@property (nonatomic, nullable) NSString *authenticationPrompt
__OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);

@property (nonatomic, readonly, nullable) NSArray AWS_KEY_TYPE *allKeys;
@property (nonatomic, readonly, nullable) NSArray *allItems;

+ (NSString *)defaultService;
+ (void)setDefaultService:(NSString *)defaultService;

+ (AWSKeyChainStore *)keyChainStore;
+ (AWSKeyChainStore *)keyChainStoreWithService:(nullable NSString *)service;
+ (AWSKeyChainStore *)keyChainStoreWithService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

+ (AWSKeyChainStore *)keyChainStoreWithServer:(NSURL *)server protocolType:(AWSKeyChainStoreProtocolType)protocolType;
+ (AWSKeyChainStore *)keyChainStoreWithServer:(NSURL *)server protocolType:(AWSKeyChainStoreProtocolType)protocolType authenticationType:(AWSKeyChainStoreAuthenticationType)authenticationType;

- (instancetype)init;
- (instancetype)initWithService:(nullable NSString *)service;
- (instancetype)initWithService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

- (instancetype)initWithServer:(NSURL *)server protocolType:(AWSKeyChainStoreProtocolType)protocolType;
- (instancetype)initWithServer:(NSURL *)server protocolType:(AWSKeyChainStoreProtocolType)protocolType authenticationType:(AWSKeyChainStoreAuthenticationType)authenticationType;

+ (nullable NSString *)stringForKey:(NSString *)key;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

+ (nullable NSData *)dataForKey:(NSString *)key;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

- (BOOL)contains:(nullable NSString *)key;

- (BOOL)setString:(nullable NSString *)string forKey:(nullable NSString *)key;
- (BOOL)setString:(nullable NSString *)string forKey:(nullable NSString *)key label:(nullable NSString *)label comment:(nullable NSString *)comment;
- (nullable NSString *)stringForKey:(NSString *)key;

- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key;
- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key label:(nullable NSString *)label comment:(nullable NSString *)comment;
- (nullable NSData *)dataForKey:(NSString *)key;

+ (BOOL)removeItemForKey:(NSString *)key;
+ (BOOL)removeItemForKey:(NSString *)key service:(nullable NSString *)service;
+ (BOOL)removeItemForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

+ (BOOL)removeAllItems;
+ (BOOL)removeAllItemsForService:(nullable NSString *)service;
+ (BOOL)removeAllItemsForService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup;

- (BOOL)removeItemForKey:(NSString *)key;

- (BOOL)removeAllItems;

- (nullable NSString *)objectForKeyedSubscript:(NSString<NSCopying> *)key;
- (void)setObject:(nullable NSString *)obj forKeyedSubscript:(NSString<NSCopying> *)key;

+ (nullable NSArray AWS_KEY_TYPE *)allKeysWithItemClass:(AWSKeyChainStoreItemClass)itemClass;
- (nullable NSArray AWS_KEY_TYPE *)allKeys;

+ (nullable NSArray *)allItemsWithItemClass:(AWSKeyChainStoreItemClass)itemClass;
- (nullable NSArray *)allItems;

- (void)setAccessibility:(AWSKeyChainStoreAccessibility)accessibility authenticationPolicy:(AWSKeyChainStoreAuthenticationPolicy)authenticationPolicy
__OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);

#if TARGET_OS_IOS
- (void)sharedPasswordWithCompletion:(nullable void (^)(NSString * __nullable account, NSString * __nullable password, NSError * __nullable error))completion;
- (void)sharedPasswordForAccount:(NSString *)account completion:(nullable void (^)(NSString * __nullable password, NSError * __nullable error))completion;

- (void)setSharedPassword:(nullable NSString *)password forAccount:(NSString *)account completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)removeSharedPasswordForAccount:(NSString *)account completion:(nullable void (^)(NSError * __nullable error))completion;

+ (void)requestSharedWebCredentialWithCompletion:(nullable void (^)(NSArray AWS_CREDENTIAL_TYPE *credentials, NSError * __nullable error))completion;
+ (void)requestSharedWebCredentialForDomain:(nullable NSString *)domain account:(nullable NSString *)account completion:(nullable void (^)(NSArray AWS_CREDENTIAL_TYPE *credentials, NSError * __nullable error))completion;

+ (NSString *)generatePassword;
#endif

@end

@interface AWSKeyChainStore (ErrorHandling)

+ (nullable NSString *)stringForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (nullable NSString *)stringForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (nullable NSData *)dataForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (nullable NSData *)dataForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

- (BOOL)setString:(nullable NSString *)string forKey:(NSString * )key error:(NSError * __nullable __autoreleasing * __nullable)error;
- (BOOL)setString:(nullable NSString *)string forKey:(NSString * )key label:(nullable NSString *)label comment:(nullable NSString *)comment error:(NSError * __nullable __autoreleasing * __nullable)error;

- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key label:(nullable NSString *)label comment:(nullable NSString *)comment error:(NSError * __nullable __autoreleasing * __nullable)error;

- (nullable NSString *)stringForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
- (nullable NSData *)dataForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)removeItemForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)removeItemForKey:(NSString *)key service:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)removeItemForKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)removeAllItemsWithError:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)removeAllItemsForService:(nullable NSString *)service error:(NSError * __nullable __autoreleasing * __nullable)error;
+ (BOOL)removeAllItemsForService:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup error:(NSError * __nullable __autoreleasing * __nullable)error;

- (BOOL)removeItemForKey:(NSString *)key error:(NSError * __nullable __autoreleasing * __nullable)error;
- (BOOL)removeAllItemsWithError:(NSError * __nullable __autoreleasing * __nullable)error;

@end

@interface AWSKeyChainStore (ForwardCompatibility)

+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setString:(nullable NSString *)value forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup genericAttribute:(nullable id)genericAttribute;
+ (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key service:(nullable NSString *)service accessGroup:(nullable NSString *)accessGroup genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

- (BOOL)setString:(nullable NSString *)string forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute;
- (BOOL)setString:(nullable NSString *)string forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute;
- (BOOL)setData:(nullable NSData *)data forKey:(NSString *)key genericAttribute:(nullable id)genericAttribute error:(NSError * __nullable __autoreleasing * __nullable)error;

@end

@interface AWSKeyChainStore (Deprecation)

- (void)synchronize __attribute__((deprecated("calling this method is no longer required")));
- (BOOL)synchronizeWithError:(NSError * __nullable __autoreleasing * __nullable)error __attribute__((deprecated("calling this method is no longer required")));

@end

NS_ASSUME_NONNULL_END
