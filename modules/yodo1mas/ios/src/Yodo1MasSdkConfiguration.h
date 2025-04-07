//
//  Yodo1MasSdkConfiguration.h
//  Yodo1MasCore
//
//  Created by Sunmeng on 2024/10/17.
//  Copyright © 2024 Yodo1 Games. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasCommon.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class contains various properties of the MAS SDK configuration.
 */
@interface Yodo1MasSdkConfiguration : NSObject

/**
 * This enum represents the user's geography used to determine the type of consent flow shown to the user.
 */
typedef NS_ENUM(NSInteger, Yodo1MasConsentFlowUserGeography) {
    /**
     * User's geography is unknown.
     */
    Yodo1MasConsentFlowUserGeographyUnknown = 0,
    /**
     * The user is in GDPR region.
     */
    Yodo1MasConsentFlowUserGeographyGdpr = 1,
    /**
     * The user is in a non-GDPR region.
     */
    Yodo1MasConsentFlowUserGeographyOther = 2,
};

/**
 * MAS SDK-defined app tracking transparency status values (extended to include "unavailable" state on iOS before iOS14).
 */
typedef NS_ENUM(NSInteger, Yodo1MasATTrackingStatus) {
    /**
     * Device is on iOS before iOS14, AppTrackingTransparency.framework is not available.
     */
    Yodo1MasATTrackingStatusSystemLow = -1,

    /**
     * The user has not yet received an authorization request to authorize access to app-related data that can be used for tracking the user or the device.
     */
    Yodo1MasATTrackingStatusNotDetermined = 0,
    
    /**
     * Authorization to access app-related data that can be used for tracking the user or the device is restricted.
     */
    Yodo1MasATTrackingStatusRestricted = 1,
    
    /**
     * The user denies authorization to access app-related data that can be used for tracking the user or the device.
     */
    Yodo1MasATTrackingStatusDenied = 2,
    
    /**
     * The user authorizes access to app-related data that can be used for tracking the user or the device.
     */
    Yodo1MasATTrackingStatusAuthorized = 3,
};

/**
 * Get the user's geography used to determine the type of consent flow shown to the user.
 * If no such determination could be made, @c Yodo1MasConsentFlowUserGeography will be returned.
 */
@property (nonatomic, assign, readonly) Yodo1MasConsentFlowUserGeography consentFlowUserGeography;

/**
 * Get the user's age when you’re using age gate by MAS.
 */
@property (nonatomic, assign, readonly) NSInteger userAge;

/**
 * Indicates whether or not the user authorizes access to app-related data that can be used for tracking the user or the device.
 *
 * @warning Users can revoke permission at any time through the "Allow Apps To Request To Track" privacy setting on the device.
 */
@property (nonatomic, assign, readonly) Yodo1MasATTrackingStatus attrackingStatus;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (NSDictionary *)getJsonObject;

@end

NS_ASSUME_NONNULL_END
