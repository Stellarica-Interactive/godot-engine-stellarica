//
//  Yodo1MasNativeAdView.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2022/1/10.
//

#import <UIKit/UIKit.h>
#import "Yodo1MasNativeAdViewBuilder.h"
#import "Yodo1MasError.h"
#import "Yodo1MasAdValue.h"

NS_ASSUME_NONNULL_BEGIN

@class Yodo1MasNativeAdView;
@protocol Yodo1MasNativeAdViewDelegate <NSObject>

@optional;
- (void)onNativeAdLoaded:(Yodo1MasNativeAdView *)view;
- (void)onNativeAdFailedToLoad:(Yodo1MasNativeAdView *)view withError:(Yodo1MasError *)error;

@end

@protocol Yodo1MasNativeAdRevenueDelegate <NSObject>

@optional
- (void)onNativeAdPayRevenue:(Yodo1MasNativeAdView *)ad withAdValue:(Yodo1MasAdValue*)adValue;

@end

@interface Yodo1MasNativeAdView : UIView

@property (nonatomic, strong) UIColor *adBackgroundColor;
@property (nonatomic, weak) id<Yodo1MasNativeAdViewDelegate> adDelegate;
@property (nonatomic, weak) id<Yodo1MasNativeAdRevenueDelegate> adRevenueDelegate;

- (void)setAdPlacement:(NSString * _Nonnull)adPlacement;

/**
 * Set custom data to tie ad events to.
 *
 * @param customData The custom data to tie the showing ad’s events to. Maximum size is 8KB.
 */
- (void)setCustomData:(NSString * _Nonnull)customData;

/**
 * At present, this function is still in the testing stage, please do not use it for now
 * @param name
 * @param builder
 */
- (void)setLayoutXib:(NSString *)name builder:(Yodo1MasNativeAdViewBuilder *)builder;

/**
 * At present, this function is still in the testing stage, please do not use it for now
 * @param view
 * @param builder
 */
- (void)setLayoutView:(Class)view builder:(Yodo1MasNativeAdViewBuilder *)builder;
- (BOOL)isLoaded;
- (void)loadAd;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
