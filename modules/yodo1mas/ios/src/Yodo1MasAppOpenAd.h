//
//  Yodo1MasAppOpenAd.h
//  AFNetworking
//
//  Created by 周玉震 on 2022/9/26.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasError.h"
#import "Yodo1MasDefinedMacros.h"
#import "Yodo1MasAdValue.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasAppOpenAd;
@protocol Yodo1MasAppOpenAdDelegate <NSObject>

@optional
- (void)onAppOpenAdLoaded:(Yodo1MasAppOpenAd *)ad;
- (void)onAppOpenAdFailedToLoad:(Yodo1MasAppOpenAd *)ad withError:(Yodo1MasError *)error;
- (void)onAppOpenAdOpened:(Yodo1MasAppOpenAd *)ad;
- (void)onAppOpenAdFailedToOpen:(Yodo1MasAppOpenAd *)ad withError:(Yodo1MasError *)error;
- (void)onAppOpenAdClosed:(Yodo1MasAppOpenAd *)ad;

@end

@protocol Yodo1MasAppOpenAdRevenueDelegate <NSObject>

@optional
- (void)onAppOpenAdPayRevenue:(Yodo1MasAppOpenAd *)ad withAdValue:(Yodo1MasAdValue*)adValue;

@end

@interface Yodo1MasAppOpenAd : NSObject

@property (nonatomic, weak) id<Yodo1MasAppOpenAdDelegate> adDelegate;
@property (nonatomic, weak) id<Yodo1MasAppOpenAdRevenueDelegate> adRevenueDelegate;

@property (nonatomic, assign) BOOL autoDelayIfLoadFail;

+ (Yodo1MasAppOpenAd *)sharedInstance;
+ (instancetype)new MAS_UNAVAILABLE_ATTRIBUTE;
- (instancetype)init MAS_UNAVAILABLE_ATTRIBUTE;
- (BOOL)isLoaded;
- (void)loadAd;
- (void)loadAndShowAd MAS_DEPRECATED_ATTRIBUTE;
- (void)loadAndShowAdWithPlacement:(NSString * _Nullable)placement MAS_DEPRECATED_ATTRIBUTE;
- (void)showAd;
- (void)showAdWithPlacement:(NSString * _Nullable)placement;

/**
 * Show the loaded rewarded ad for a given placement and custom data to tie ad events to.
 *
 * @param placement The placement to tie the showing ad’s events to.
 * @param customData The custom data to tie the showing ad’s events to. Maximum size is 8KB.
 */
- (void)showAdWithPlacement:(NSString * _Nullable)placement customData:(nullable NSString *)customData;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
