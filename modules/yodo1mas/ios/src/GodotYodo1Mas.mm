#include "GodotYodo1Mas.h"
#import "app_delegate.h"
#import "Yodo1Mas.h"

static GodotYodo1Mas *godotYodo1MasInstance = NULL;


// BEGIN CALLBALS
@interface GodotYodo1MasBannerAd: NSObject<Yodo1MasBannerAdDelegate>

@end

@implementation GodotYodo1MasBannerAd

- (void)setAdDelegate {
	//[Yodo1MasInterstitialAd sharedInstance].adDelegate = self;
}

- (void)onAdOpened:(Yodo1MasAdEvent *)event {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onAdOpened");
    godotYodo1MasInstance->emit_signal("onBannerAdOpened");
}

- (void)onAdClosed:(Yodo1MasAdEvent *)event {
	NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onAdClosed");
    godotYodo1MasInstance->emit_signal("onBannerAdClosed");
}

- (void)onAdError:(Yodo1MasAdEvent *)event error:(Yodo1MasError *)error {
	if (error.code != Yodo1MasErrorCodeAdLoadFail) {
		NSLog(@"GodotYodo1MasWrapper -> GodotYodo1MasBannerAd onAdError, %d", (int)error.code);
	    godotYodo1MasInstance->emit_signal("on_banner_ad_error", (int)error.code);	
	}
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



// BEGIN INITIALIZATION

bool initialized;
	
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

	setBannerCallback();
	setInterstitialAdCallback();	
	setRewardedAdCallback();
		
	NSString *appIdPr = [NSString stringWithCString:appId.utf8().get_data() encoding: NSUTF8StringEncoding];
    [[Yodo1Mas sharedInstance] initMasWithAppKey:appIdPr successful:^{
		initialized = true;
		NSLog(@"GodotYodo1MasWrapper -> initialize successful");
    } fail:^(NSError * _Nonnull error) {
		NSLog(@"GodotYodo1MasWrapper -> initialize error: %@", error);
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
	// TODO
	//[[Yodo1MasBannerAd]]
}

void GodotYodo1Mas::hideBannerAd() {
	// TODO
}

void GodotYodo1Mas::showBannerAd() {
	// TODO
	//NSString *placementIdPr = [NSString stringWithCString:placementId.utf8().get_data() encoding: NSUTF8StringEncoding];
	//[[Yodo1MasRewardAd sharedInstance] showAdWithPlacement:placementIdPr];
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



// BEGIN REWARDED AD

bool GodotYodo1Mas::isRewardedAdLoaded() {
	return [[Yodo1MasRewardAd sharedInstance] isLoaded];
}

void GodotYodo1Mas::initializeRewardedAd() {
	if (!initialized) {
		NSLog(@"GodotYodo1MasWrapper Module not initialized");
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
