//
//  Yodo1Mas.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "Yodo1MasAdBuildConfig.h"
#import "Yodo1MasAdEvent.h"
#import "Yodo1MasAdValue.h"
#import "Yodo1MasCallback.h"
#import "Yodo1MasCommon.h"
#import "Yodo1MasDefinedMacros.h"
#import "Yodo1MasError.h"
#import "Yodo1MasSdkConfiguration.h"

#import "Yodo1MasRewardAd.h"
#import "Yodo1MasInterstitialAd.h"
#import "Yodo1MasAppOpenAd.h"
#import "Yodo1MasRewardedInterstitialAd.h"
#import "Yodo1MasNativeAdView.h"
#import "Yodo1MasBannerAdView.h"

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1Mas : NSObject

#pragma mark - SDK Properties

/**
 * The SDK configuration object that the SDK creates when you initialize the SDK.
 */
@property (nonatomic, strong, readonly) Yodo1MasSdkConfiguration *configuration;

/**
 * The user's age when you’re using age gate by MAS.
 */
@property (nonatomic, assign, readonly) NSInteger userAge;

/**
 * Indicates whether or not the user authorizes access to app-related data that can be used for tracking the user or the device.
 *
 * @warning Users can revoke permission at any time through the "Allow Apps To Request To Track" privacy setting on the device.
 */
@property (nonatomic, assign, readonly) Yodo1MasATTrackingStatus attrackingStatus;

/**
 * An identifier for the current user. This identifier will be tied to SDK events and MAS's optional S2S postbacks.
 *
 * If you use reward validation, you can optionally set an identifier that MAS will include with its currency validation postbacks (for example, a username
 * or email address). MAS will include this in the postback when MAS pings your currency endpoint from our server.
 *
 * Maximum size is 8KB.
 */
@property (nonatomic, copy, nullable) NSString *userIdentifier;


@property (nonatomic, weak) id<Yodo1MasAppStatusDelegate> appStatusDelegate;

#pragma mark - Privacy Settings

/**
 * Sets/Checks whether or not the user has provided consent for information-sharing with MAS.
 */
@property (nonatomic, assign) BOOL isGDPRUserConsent;

/**
 * Marks/Checks the user as age-restricted (i.e. under 16).
 */
@property (nonatomic, assign) BOOL isCOPPAAgeRestricted;

/**
 * Sets/Checks whether or not the user has opted out of the sale of their personal information.
 */
@property (nonatomic, assign) BOOL isCCPADoNotSell;

@property (nonatomic, assign) Yodo1MasPersonalizedAdState isPersonalizedState;

#pragma mark - SDK Initialization

/**
 * Whether the SDK has fully been initialized without errors and the completion callback called.
 */
@property (nonatomic, assign, readonly, getter=isInitialized) BOOL initialized;

+ (Yodo1Mas *)sharedInstance;
+ (NSString *)sdkVersion;
+ (instancetype)new MAS_UNAVAILABLE_ATTRIBUTE;
- (instancetype)init MAS_UNAVAILABLE_ATTRIBUTE;
- (void)setAdBuildConfig:(Yodo1MasAdBuildConfig *)buildConfig;

- (void)initMasWithSuccessful:(Yodo1MasInitSuccessful _Nullable)successful fail:(Yodo1MasInitFail _Nullable)fail;
- (void)initMasWithAppKey:(NSString *)appKey successful:(Yodo1MasInitSuccessful _Nullable)successful fail:(Yodo1MasInitFail _Nullable)fail;
- (void)initMasWithAppKey:(NSString *)appKey successfulHandler:(Yodo1MasInitSuccessfulHandler _Nullable)successfulHandler failHandler:(Yodo1MasInitFailHandler _Nullable)failHandler;

- (void)showPopupToReportAd;
- (void)showDebugger;

- (void)showUmpForExistingUser:(Yodo1MasUmpCompletionHandler _Nullable)completionHandler;

- (NSString*)getIABTCFString:(NSString*)key;

@end

@interface Yodo1Mas (Deprecated)

@property (nonatomic, assign, readonly) BOOL isInit MAS_DEPRECATED_MSG_ATTRIBUTE("Use `isInitialized` instead");

@property (nonatomic, weak) id<Yodo1MasRewardAdDelegate> rewardAdDelegate MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasRewardAd` instead");
@property (nonatomic, weak) id<Yodo1MasInterstitialAdDelegate> interstitialAdDelegate MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasInterstitialAd` instead");
@property (nonatomic, weak) id<Yodo1MasBannerAdDelegate> bannerAdDelegate MAS_UNAVAILABLE_MSG_ATTRIBUTE("`Use `Yodo1MasBannerAdView` instead");

- (void)initWithSuccessful:(Yodo1MasInitSuccessful _Nullable)successful fail:(Yodo1MasInitFail _Nullable)fail MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `initMasWithSuccessful:fail:` instead");
- (void)initWithAppKey:(NSString *)appKey successful:(Yodo1MasInitSuccessful _Nullable)successful fail:(Yodo1MasInitFail _Nullable)fail MAS_UNAVAILABLE_MSG_ATTRIBUTE("`Use `initMasWithAppKey:successful:fail:` instead");
- (void)initWithAppId:(NSString *)appId successful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `initMasWithAppKey:successful:fail:` instead");

- (BOOL)isRewardAdLoaded MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasRewardAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/rewarded_video");
/**
 *  Show the ad, if the ad is already loaded
*/
- (void)showRewardAd MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasRewardAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/rewarded_video");
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
*/
- (void)showRewardAdWithPlacement:(NSString * _Nullable)placement MAS_UNAVAILABLE_MSG_ATTRIBUTE(" Use `Yodo1MasRewardAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/rewarded_video");

- (BOOL)isInterstitialAdLoaded MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasInterstitialAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/interstitial");
/**
 *  Show the ad, if the ad is already loaded
*/
- (void)showInterstitialAd MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasInterstitialAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/interstitial");
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
*/
- (void)showInterstitialAdWithPlacement:(NSString * _Nullable)placement MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasInterstitialAd` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/interstitial");

- (BOOL)isBannerAdLoaded MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");
- (void)showBannerAd MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
 */
- (void)showBannerAdWithPlacement:(NSString * _Nullable)placement MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here  https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");
/**
 *
 * Show the ad, if the ad is already loaded
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 *
 */
- (void)showBannerAdWithAlign:(Yodo1MasAdBannerAlign)align MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here  https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");

/**
 *
 * Show the ad, if the ad is already loaded
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 * @param offset horizontal offset and vertical offset, offset.x > 0, the banner will move to the right. offset.x < 0, the banner will move to the left, offset.y > 0, the banner will move to the bottom. offset.y < 0, the banner will move to the top
 */
- (void)showBannerAdWithAlign:(Yodo1MasAdBannerAlign)align offset:(CGPoint)offset MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here  https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");
/**
 *
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 * @param offset horizontal offset and vertical offset,  offset.x > 0, the banner will move to the right. offset.x < 0, the banner will move to the left, offset.y > 0, the banner will move to the bottom. offset.y < 0, the banner will move to the top
 *
 */
- (void)showBannerAdWithPlacement:(NSString * __nullable)placement align:(Yodo1MasAdBannerAlign)align offset:(CGPoint)offset MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");

- (void)dismissBannerAd MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");
/**
 * hide banner ads
 * @param destroy if destroy == YES, the ads displayed in the next call to showBanner are different. if destroy == NO, the ads displayed in the next call to showBanner are same
*/
- (void)dismissBannerAdWithDestroy:(BOOL)destroy MAS_UNAVAILABLE_MSG_ATTRIBUTE("Use `Yodo1MasBannerAdView` instead. You can get details from here  https://developers.yodo1.com/docs/sdk/getting_started/ad_units/banner");

@end

NS_ASSUME_NONNULL_END
