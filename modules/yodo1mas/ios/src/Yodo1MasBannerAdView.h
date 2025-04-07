//
//  Yodo1MasBannerAdView.h
//  AFNetworking
//
//  Created by 周玉震 on 2021/10/27.
//

#import <UIKit/UIKit.h>
#import "Yodo1MasBanner.h"
#import "Yodo1MasAdValue.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasBannerAdView;
@class Yodo1MasError;
@protocol Yodo1MasBannerAdViewDelegate <NSObject>

@optional;
- (void)onBannerAdLoaded:(Yodo1MasBannerAdView *)banner;
- (void)onBannerAdFailedToLoad:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error;
- (void)onBannerAdOpened:(Yodo1MasBannerAdView *)banner;
- (void)onBannerAdFailedToOpen:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error;
- (void)onBannerAdClosed:(Yodo1MasBannerAdView *)banner;

@end

@protocol Yodo1MasBannerAdRevenueDelegate <NSObject>

@optional
- (void)onBannerAdPayRevenue:(Yodo1MasBannerAdView *)ad withAdValue:(Yodo1MasAdValue*)adValue;

@end

@interface Yodo1MasBannerAdView : UIView

@property (nonatomic, assign, readonly) Yodo1MasBannerAdSize adSize;
@property (nonatomic, weak) id<Yodo1MasBannerAdViewDelegate> adDelegate;
@property (nonatomic, weak) id<Yodo1MasBannerAdRevenueDelegate> adRevenueDelegate;

- (instancetype)initWithPlacement:(NSString *)placement size:(Yodo1MasBannerAdSize)size;
- (void)setAdPlacement:(NSString * _Nonnull)adPlacement;

/**
 * Set custom data to tie ad events to.
 *
 * @param customData The custom data to tie the showing ad’s events to. Maximum size is 8KB.
 */
- (void)setCustomData:(NSString *)customData;
- (void)setAdSize:(Yodo1MasBannerAdSize)adSize;
- (BOOL)isLoaded;
- (void)loadAd;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
