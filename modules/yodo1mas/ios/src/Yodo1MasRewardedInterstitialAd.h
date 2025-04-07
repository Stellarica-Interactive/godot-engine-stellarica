//
//  Yodo1MasRewardedInterstitialAd.h
//  AFNetworking
//
//  Created by 周玉震 on 2022/9/26.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasError.h"
#import "Yodo1MasDefinedMacros.h"
#import "Yodo1MasAdValue.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasRewardedInterstitialAd;
@protocol Yodo1MasRewardedInterstitialAdDelegate <NSObject>

@optional
- (void)onRewardedInterstitialAdLoaded:(Yodo1MasRewardedInterstitialAd *)ad;
- (void)onRewardedInterstitialAdFailedToLoad:(Yodo1MasRewardedInterstitialAd *)ad withError:(Yodo1MasError *)error;
- (void)onRewardedInterstitialAdOpened:(Yodo1MasRewardedInterstitialAd *)ad;
- (void)onRewardedInterstitialAdFailedToOpen:(Yodo1MasRewardedInterstitialAd *)ad withError:(Yodo1MasError *)error;
- (void)onRewardedInterstitialAdClosed:(Yodo1MasRewardedInterstitialAd *)ad;
- (void)onRewardedInterstitialAdEarned:(Yodo1MasRewardedInterstitialAd *)ad;

@end

@protocol Yodo1MasRewardedInterstitialAdRevenueDelegate <NSObject>

@optional
- (void)onRewardedInterstitialAdPayRevenue:(Yodo1MasRewardedInterstitialAd *)ad withAdValue:(Yodo1MasAdValue*)adValue;

@end

@interface Yodo1MasRewardedInterstitialAd : NSObject

@property (nonatomic, weak) id<Yodo1MasRewardedInterstitialAdDelegate> adDelegate;
@property (nonatomic, weak) id<Yodo1MasRewardedInterstitialAdRevenueDelegate> adRevenueDelegate;

@property (nonatomic, assign) BOOL autoDelayIfLoadFail;

+ (Yodo1MasRewardedInterstitialAd *)sharedInstance;
+ (instancetype)new MAS_UNAVAILABLE_ATTRIBUTE;
- (instancetype)init MAS_UNAVAILABLE_ATTRIBUTE;
- (BOOL)isLoaded;
- (void)loadAd;
- (void)loadAndShowAd MAS_UNAVAILABLE_ATTRIBUTE;
- (void)loadAndShowAdWithPlacement:(NSString * _Nullable)placement MAS_UNAVAILABLE_ATTRIBUTE;
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
