//
//  Yodo1MasAdValue.h
//  Yodo1MasCore
//
//  Created by Sunmeng on 2024/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasAdValue : NSObject

/**
 * The ad network from which this ad was loaded.
 */
@property (nonatomic, copy, readonly) NSString *networkName;

/// The ad's value.
@property (nonatomic, assign, readonly) double revenue;

/**
 * The precision of the revenue value for this ad.
 *
 * Possible values are:
 * - "publisher_defined" - If the revenue is the price assigned to the line item by the publisher.
 * - "exact" - If the revenue is the resulting price of a real-time auction.
 * - "estimated" - If the revenue is the price obtained by auto-CPM.
 * - "undefined" - If we do not have permission from the ad network to share impression-level data.
 * - "" - An empty string, if revenue and precision are not valid (for example, in test mode).
 */
@property (nonatomic, copy, readonly) NSString *revenuePrecision;

/// The value's currency code.
@property(nonatomic, nonnull, readonly) NSString *currency;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (NSDictionary *)getJsonObject;

@end

NS_ASSUME_NONNULL_END
