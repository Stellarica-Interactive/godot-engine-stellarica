/**************************************************************************/
/*  GodotYodo1Mas.mm                                                      */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "GodotYodo1Mas.h"
#import "Yodo1Mas.h"
#import "Yodo1MasBanner.h"
#import "drivers/apple_embedded/godot_app_delegate.h"

static GodotYodo1Mas* godotYodo1MasInstance = NULL;

static Yodo1MasBannerAdView* bannerView = NULL;


// BEGIN CALLBALS
@interface GodotYodo1MasBannerAd: NSObject<Yodo1MasBannerAdViewDelegate>

- (void)setAdDelegate;

@end

@implementation GodotYodo1MasBannerAd

- (void)setAdDelegate {
	if (bannerView) {
		bannerView.adDelegate = self;
	}
}

- (void)onBannerAdLoaded:(Yodo1MasBannerAdView *)banner {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onBannerAdLoaded");
	godotYodo1MasInstance->emit_signal("onBannerAdLoaded");
}

- (void)onBannerAdFailedToLoad:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onBannerAdFailedToLoad");
	godotYodo1MasInstance->emit_signal("onBannerAdFailedToLoad");
}

- (void)onBannerAdOpened:(Yodo1MasBannerAdView *)banner {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onBannerAdOpened");
	godotYodo1MasInstance->emit_signal("onBannerAdOpened");
}

- (void)onBannerAdFailedToOpen:(Yodo1MasBannerAdView *)banner withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onBannerAdFailedToOpen");
	godotYodo1MasInstance->emit_signal("onBannerAdFailedToOpen");
}

- (void)onBannerAdClosed:(Yodo1MasBannerAdView *)banner {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onBannerAdClosed");
	godotYodo1MasInstance->emit_signal("onBannerAdClosed");
}

@end


@interface GodotYodo1MasInterstitialAd: NSObject<Yodo1MasInterstitialDelegate>

- (void)setAdDelegate;

@end


@implementation GodotYodo1MasInterstitialAd

- (void)setAdDelegate {
	Yodo1MasInterstitialAd* interstitialAd = [Yodo1MasInterstitialAd sharedInstance];
	interstitialAd.adDelegate = self;
}

- (void)onInterstitialAdLoaded:(Yodo1MasInterstitialAd *)ad {
	NSLog(@"GodotYodo1MasInterstitialAd -> onInterstitialAdLoaded");
	godotYodo1MasInstance->emit_signal("onInterstitialAdLoaded");
}

- (void)onInterstitialAdFailedToLoad:(Yodo1MasInterstitialAd *)ad withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasInterstitialAd -> onInterstitialAdFailedToLoad");
	godotYodo1MasInstance->emit_signal("onInterstitialAdFailedToLoad");
}

- (void)onInterstitialAdOpened:(Yodo1MasInterstitialAd *)ad {
	NSLog(@"GodotYodo1MasInterstitialAd -> onInterstitialAdOpened");
	godotYodo1MasInstance->emit_signal("onInterstitialAdOpened");
}

- (void)onInterstitialAdFailedToOpen:(Yodo1MasInterstitialAd *)ad withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasInterstitialAd -> onInterstitialAdFailedToOpen");
	godotYodo1MasInstance->emit_signal("onInterstitialAdFailedToOpen");
}

- (void)onInterstitialAdClosed:(Yodo1MasInterstitialAd *)ad {
	NSLog(@"GodotYodo1MasInterstitialAd -> onInterstitialAdClosed");
	godotYodo1MasInstance->emit_signal("onInterstitialAdClosed");
}

@end


@interface GodotYodo1MasRewardedAd: NSObject<Yodo1MasRewardDelegate>

- (void)setAdDelegate;

@end


@implementation GodotYodo1MasRewardedAd

- (void)setAdDelegate {
	Yodo1MasRewardAd* rewardAd = [Yodo1MasRewardAd sharedInstance];
	rewardAd.adDelegate = self;
}

- (void)onRewardAdLoaded:(Yodo1MasRewardAd *)ad {
	NSLog(@"GodotYodo1MasRewardedAd -> GodotYodo1MasRewardedAd");
	godotYodo1MasInstance->emit_signal("onRewardAdLoaded");
}

- (void)onRewardAdFailedToLoad:(Yodo1MasRewardAd *)ad withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasRewardedAd -> onRewardAdFailedToLoad");
	godotYodo1MasInstance->emit_signal("onRewardAdFailedToLoad");
}

- (void)onRewardAdOpened:(Yodo1MasRewardAd *)ad {
	NSLog(@"GodotYodo1MasRewardedAd -> onRewardAdOpened");
	godotYodo1MasInstance->emit_signal("onRewardAdOpened");
}

- (void)onRewardAdFailedToOpen:(Yodo1MasRewardAd *)ad withError:(Yodo1MasError *)error {
	NSLog(@"GodotYodo1MasRewardedAd -> onRewardAdFailedToOpen");
	godotYodo1MasInstance->emit_signal("onRewardAdFailedToOpen");
}

- (void)onRewardAdClosed:(Yodo1MasRewardAd *)ad {
	NSLog(@"GodotYodo1MasRewardedAd -> onRewardAdClosed");
	godotYodo1MasInstance->emit_signal("onRewardAdClosed");
}

- (void)onRewardAdEarned:(Yodo1MasRewardAd *)ad {
	NSLog(@"GodotYodo1MasRewardedAd -> onRewardAdEarned");
	godotYodo1MasInstance->emit_signal("onRewardAdEarned");
}

@end

// END CALLBALS

@interface RotationObserver : NSObject
@property (nonatomic, assign) GodotYodo1Mas *owner;
@end

@implementation RotationObserver

- (void)orientationChanged:(NSNotification *)notification {
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
		godotYodo1MasInstance->updateBannerPosition();
	});
}

@end


// BEGIN INITIALIZATION

bool initialized;
bool rewardAdinitializeRequest;
NSString* bannerHAlign;
NSString* bannerVAlign;
RotationObserver* rotationObserver;

GodotYodo1Mas::GodotYodo1Mas() {
	godotYodo1MasInstance = this;
}

GodotYodo1Mas::~GodotYodo1Mas() {
}

bool GodotYodo1Mas::isInitialized() {
	return initialized;
}

void GodotYodo1Mas::setGDPR(bool gdpr) {
	NSLog(@"GodotYodo1MasWrapper -> setGDPR, %d", gdpr);
	[Yodo1Mas sharedInstance].isGDPRUserConsent = gdpr;
}
void GodotYodo1Mas::setCCPA(bool ccpa) {
	NSLog(@"GodotYodo1MasWrapper -> setCCPA, %d", ccpa);
	[Yodo1Mas sharedInstance].isCCPADoNotSell = ccpa;
}	
void GodotYodo1Mas::setCOPPA(bool coppa) {
	NSLog(@"GodotYodo1MasWrapper -> setCOPPA, %d", coppa);
	[Yodo1Mas sharedInstance].isCOPPAAgeRestricted = coppa;
}

void GodotYodo1Mas::init(const String &appId) {
    NSLog(@"GodotYodo1MasWrapper init");
	rotationObserver = [[RotationObserver alloc] init];
	[[NSNotificationCenter defaultCenter] addObserver:rotationObserver
											 selector:@selector(orientationChanged:)
												 name:UIDeviceOrientationDidChangeNotification
											   object:nil];

	setInterstitialAdCallback();
	setRewardedAdCallback();
		
	NSString *appIdPr = [NSString stringWithCString:appId.utf8().get_data() encoding: NSUTF8StringEncoding];
    [[Yodo1Mas sharedInstance] initMasWithAppKey:appIdPr successful:^{
		initialized = true;
		NSLog(@"GodotYodo1MasWrapper -> initialize successful");
		godotYodo1MasInstance->emit_signal("onMasInitSuccessful");
		if (rewardAdinitializeRequest) {
			initializeRewardedAd();
		}
    } fail:^(NSError * _Nonnull error) {
		NSLog(@"GodotYodo1MasWrapper -> initialize error: %@", error);
		godotYodo1MasInstance->emit_signal("onMasInitFailed");
    }];
}

void GodotYodo1Mas::setBannerCallback() {
    static GodotYodo1MasBannerAd* bannerAd;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bannerAd = [[GodotYodo1MasBannerAd alloc] init];
    });
    [bannerAd setAdDelegate];
}

void GodotYodo1Mas::setInterstitialAdCallback() {
    static GodotYodo1MasInterstitialAd* interstitialAd;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        interstitialAd = [[GodotYodo1MasInterstitialAd alloc] init];
    });
    [interstitialAd setAdDelegate];
}

void GodotYodo1Mas::setRewardedAdCallback() {
    static GodotYodo1MasRewardedAd* rewardedAd;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        rewardedAd = [[GodotYodo1MasRewardedAd alloc] init];
    });
	[rewardedAd setAdDelegate];
}


// END INITIALIZATION



// BEGIN REPORT AD

void GodotYodo1Mas::showReportAd() {
	if (!initialized) {
		NSLog(@"GodotYodo1MasWrapper not initialized");
		return;
	}
	return [[Yodo1Mas sharedInstance] showPopupToReportAd];
}

// END REPORT AD



// BEGIN BANNER AD

void GodotYodo1Mas::loadBannerAd(const String &size, const String& horizontalALignment, const String& verticalAlignment, const String& placementId) {
	if (!initialized) {
		NSLog(@"loadBannerAd: GodotYodo1MasWrapper not initialized");
		return;
	}
	if (bannerView) {
		[bannerView removeFromSuperview];
		bannerView = nil;
	}
	
	NSLog(@"loadBannerAd: Setting up banner view");

	// Create banner
	bannerView = [[Yodo1MasBannerAdView alloc] init];
	
	NSString *placement = [NSString stringWithCString:placementId.utf8().get_data() encoding: NSUTF8StringEncoding];
	[bannerView setAdPlacement:placement];
	
	setBannerCallback();
	
	NSString *sizePr = [NSString stringWithCString:size.utf8().get_data() encoding: NSUTF8StringEncoding];

	// Size mapping – optional, defaults to adaptive
	if ([sizePr isEqualToString:@"Banner"]) {
		bannerView.adSize = Yodo1MasBannerAdSizeBanner;
	} else if ([sizePr isEqualToString:@"LargeBanner"]) {
		bannerView.adSize = Yodo1MasBannerAdSizeLargeBanner;
	} else {
		bannerView.adSize = Yodo1MasBannerAdSizeBanner; // fallback
	}

	[bannerView loadAd];

	// Add to main view
	UIView *rootView = [UIApplication sharedApplication].keyWindow.rootViewController.view;
	[rootView addSubview:bannerView];
	
	bannerHAlign = [NSString stringWithCString:horizontalALignment.utf8().get_data() encoding: NSUTF8StringEncoding];
	bannerVAlign = [NSString stringWithCString:verticalAlignment.utf8().get_data() encoding: NSUTF8StringEncoding];
	
	godotYodo1MasInstance->updateBannerPosition();
}

void GodotYodo1Mas::updateBannerPosition() {
	if (!bannerView) {
		NSLog(@"[updateBannerPosition] not having, returning");
		return;
	}


	UIView *rootView = [UIApplication sharedApplication].keyWindow.rootViewController.view;
	CGFloat x = 0;
	CGFloat y = 0;
	
	CGSize size = [Yodo1MasBanner sizeFromAdSize:bannerView.adSize];
	
	CGFloat width = size.width;
	CGFloat height = size.height;

	// Horizontal alignment
	if ([bannerHAlign isEqualToString:@"Center"]) {
		x = (rootView.bounds.size.width - width) * 0.5;
	} else if ([bannerHAlign isEqualToString:@"Right"]) {
		x = rootView.bounds.size.width - width;
	} // default: left
	

	// Vertical alignment
	if ([bannerVAlign isEqualToString:@"Center"]) {
		y = (rootView.bounds.size.height) * 0.5;
	} else if ([bannerVAlign isEqualToString:@"Bottom"]) {
		y = rootView.bounds.size.height - height;
	} // default: top
	
	NSLog(@"[updateBannerPosition] setting banner position: [%@, %@]", bannerHAlign, bannerVAlign);
	NSLog(@"[updateBannerPosition] setting banner size: [%f, %f]", width, height);

	bannerView.frame = CGRectMake(x, y, width, height);
}

void GodotYodo1Mas::hideBannerAd() {
	if (bannerView) {
		NSLog(@"[hideBannerAd] hiding banner ad");
		bannerView.hidden = YES;
	}
}

void GodotYodo1Mas::showBannerAd() {
	if (bannerView) {
		NSLog(@"[showBannerAd] showing banner ad");
		bannerView.hidden = NO;
	}
}

// END BANNER AD



// BEGIN INTERSTITIAL AD

bool GodotYodo1Mas::isInterstitialAdLoaded() {
	return [[Yodo1MasInterstitialAd sharedInstance] isLoaded];
}

void GodotYodo1Mas::initializeInterstitialAd() {
	if (!initialized) {
		NSLog(@"[GodotYodo1MasWrapper -> initializeInterstitialAd]:  not initialized");
		return;
	}
	[[Yodo1MasInterstitialAd sharedInstance] loadAd];
}

void GodotYodo1Mas::showInterstitialAd(const String& placementId) {
    if (!initialized) {
        NSLog(@"GodotYodo1MasWrapper not initialized");
        return;
    }
	
	bool isLoaded = isInterstitialAdLoaded();
	NSLog(@"GodotYodo1MasWrapper isInterstitialAdLoaded %d", isLoaded);
	if(!isLoaded) {
		godotYodo1MasInstance->emit_signal("on_interstitial_ad_not_loaded");
		return;
	}

    NSLog(@"GodotYodo1MasWrapper showInterstitialAd");
	NSString *placementIdPr = [NSString stringWithCString:placementId.utf8().get_data() encoding: NSUTF8StringEncoding];
	[[Yodo1MasInterstitialAd sharedInstance] showAdWithPlacement:placementIdPr];
}

// END INTERSTITIAL AD



// BEGIN APP OPEN AD

bool GodotYodo1Mas::isAppOpenAdLoaded() {
	return false; // TODO
}

void GodotYodo1Mas::initializeAppOpenAd() {
	// TODO
}

void GodotYodo1Mas::showAppOpenAd(const String& placementId) {
	// TODO
}

// END APP OPEN AD



// BEGIN REWARDED AD

bool GodotYodo1Mas::isRewardedAdLoaded() {
	return [[Yodo1MasRewardAd sharedInstance] isLoaded];
}

void GodotYodo1Mas::initializeRewardedAd() {
	if (!initialized) {
		NSLog(@"GodotYodo1Mas -> initializeRewardedAd: GodotYodo1MasWrapper Module not initialized");
		rewardAdinitializeRequest = true;
		return;
	}

	[[Yodo1MasRewardAd sharedInstance] loadAd];
}

void GodotYodo1Mas::showRewardedAd(const String& placementId) {
    if (!initialized) {
        NSLog(@"GodotYodo1MasWrapper Module not initialized");
        return;
    }
	
	bool isLoaded = isRewardedAdLoaded();
	NSLog(@"GodotYodo1MasWrapper isRewardedAdLoaded %d", isLoaded);
	if(!isLoaded) {
		initializeRewardedAd();
		godotYodo1MasInstance->emit_signal("onRewardAdFailedToLoad");
		return;
	}
    
	NSLog(@"GodotYodo1MasWrapper showRewardedVideo");
	NSString *placementIdPr = [NSString stringWithCString:placementId.utf8().get_data() encoding: NSUTF8StringEncoding];
	[[Yodo1MasRewardAd sharedInstance] showAdWithPlacement:placementIdPr];
}

// END REWARDED AD

void GodotYodo1Mas::_bind_methods() {
    ClassDB::bind_method("init", &GodotYodo1Mas::init);

    ClassDB::bind_method("setGDPR", &GodotYodo1Mas::setGDPR);
	ClassDB::bind_method("setCCPA", &GodotYodo1Mas::setCCPA);
	ClassDB::bind_method("setCOPPA", &GodotYodo1Mas::setCOPPA);
	
	ClassDB::bind_method("showReportAd", &GodotYodo1Mas::showReportAd);

	ClassDB::bind_method("loadBannerAd", &GodotYodo1Mas::loadBannerAd);
	ClassDB::bind_method("hideBannerAd", &GodotYodo1Mas::hideBannerAd);
	ClassDB::bind_method("showBannerAd", &GodotYodo1Mas::showBannerAd);

	ClassDB::bind_method("isInterstitialAdLoaded", &GodotYodo1Mas::isInterstitialAdLoaded);
	ClassDB::bind_method("initializeInterstitialAd", &GodotYodo1Mas::initializeInterstitialAd);
	ClassDB::bind_method("showInterstitialAd", &GodotYodo1Mas::showInterstitialAd);


	ClassDB::bind_method("isAppOpenAdLoaded", &GodotYodo1Mas::isAppOpenAdLoaded);
	ClassDB::bind_method("initializeAppOpenAd", &GodotYodo1Mas::initializeAppOpenAd);
	ClassDB::bind_method("showAppOpenAd", &GodotYodo1Mas::showAppOpenAd);

	ClassDB::bind_method("initializeRewardedAd", &GodotYodo1Mas::initializeRewardedAd);
	ClassDB::bind_method("showRewardedAd", &GodotYodo1Mas::showRewardedAd);

	ADD_SIGNAL(MethodInfo("onMasInitSuccessful"));
	ADD_SIGNAL(MethodInfo("onMasInitFailed"));

	ADD_SIGNAL(MethodInfo("onBannerAdLoaded"));
	ADD_SIGNAL(MethodInfo("onBannerAdFailedToLoad"));
	ADD_SIGNAL(MethodInfo("onBannerAdOpened"));
	ADD_SIGNAL(MethodInfo("onBannerAdFailedToOpen"));
	ADD_SIGNAL(MethodInfo("onBannerAdClosed"));

	ADD_SIGNAL(MethodInfo("onInterstitialAdLoaded"));
	ADD_SIGNAL(MethodInfo("onInterstitialAdFailedToLoad"));
	ADD_SIGNAL(MethodInfo("onInterstitialAdOpened"));
	ADD_SIGNAL(MethodInfo("onInterstitialAdFailedToOpen"));
	ADD_SIGNAL(MethodInfo("onInterstitialAdClosed"));

	ADD_SIGNAL(MethodInfo("onAppOpenAdLoaded"));
	ADD_SIGNAL(MethodInfo("onAppOpenAdFailedToLoad"));
	ADD_SIGNAL(MethodInfo("onAppOpenAdOpened"));
	ADD_SIGNAL(MethodInfo("onAppOpenAdFailedToOpen"));
	ADD_SIGNAL(MethodInfo("onAppOpenAdClosed"));

	ADD_SIGNAL(MethodInfo("onRewardAdLoaded"));
	ADD_SIGNAL(MethodInfo("onRewardAdFailedToLoad"));
	ADD_SIGNAL(MethodInfo("onRewardAdOpened"));
	ADD_SIGNAL(MethodInfo("onRewardAdFailedToOpen"));
	ADD_SIGNAL(MethodInfo("onRewardAdEarned"));
	ADD_SIGNAL(MethodInfo("onRewardAdClosed"));
}
