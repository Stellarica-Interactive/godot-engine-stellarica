//
//  Yodo1MasInterstitialAd.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2022/5/5.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasError.h"
#import "Yodo1MasDefinedMacros.h"
#import "Yodo1MasAdValue.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasInterstitialAd;
@protocol Yodo1MasInterstitialDelegate <NSObject>

@optional
- (void)onInterstitialAdLoaded:(Yodo1MasInterstitialAd *)ad;
- (void)onInterstitialAdFailedToLoad:(Yodo1MasInterstitialAd *)ad withError:(Yodo1MasError *)error;
- (void)onInterstitialAdOpened:(Yodo1MasInterstitialAd *)ad;
- (void)onInterstitialAdFailedToOpen:(Yodo1MasInterstitialAd *)ad withError:(Yodo1MasError *)error;
- (void)onInterstitialAdClosed:(Yodo1MasInterstitialAd *)ad;

@end

@protocol Yodo1MasInterstitialAdRevenueDelegate <NSObject>

@optional
- (void)onInterstitialAdPayRevenue:(Yodo1MasInterstitialAd *)ad withAdValue:(Yodo1MasAdValue*)adValue;

@end

@interface Yodo1MasInterstitialAd : NSObject

@property (nonatomic, weak) id<Yodo1MasInterstitialDelegate> adDelegate;
@property (nonatomic, weak) id<Yodo1MasInterstitialAdRevenueDelegate> adRevenueDelegate;
@property (nonatomic, assign) BOOL autoDelayIfLoadFail;

+ (Yodo1MasInterstitialAd *)sharedInstance;
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
