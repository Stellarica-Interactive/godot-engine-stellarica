//
//  Yodo1MasCommon.h
//  Pods
//
//  Created by ZhouYuzhen on 2020/12/17.
//

#ifndef Yodo1MasCommon_h
#define Yodo1MasCommon_h

#define kNotificationYodo1MasSdkInit @"Yodo1MasSdkInit"

typedef NS_ENUM(NSInteger, Yodo1MasAdType) {
    Yodo1MasAdTypeReward = 1,
    Yodo1MasAdTypeInterstitial = 2,
    Yodo1MasAdTypeBanner = 3,
    Yodo1MasAdTypeNative = 4,
    Yodo1MasAdTypeRewardedInterstitial = 5,
    Yodo1MasAdTypeAppOpen = 6
};

typedef NS_ENUM(NSInteger, Yodo1MasAdPriceType) {
    Yodo1MasAdPriceTypeNone,
    Yodo1MasAdPriceTypeMediation,
    Yodo1MasAdPriceTypeAuto,
    Yodo1MasAdPriceTypeManual,
    Yodo1MasAdPriceTypeBidding,
    Yodo1MasAdPriceTypeClientBidding
};

typedef NS_ENUM(NSInteger, Yodo1MasAdEventCode) {
    Yodo1MasAdEventCodeError = -1,
    Yodo1MasAdEventCodeOpened = 1001,
    Yodo1MasAdEventCodeClosed = 1002,
    Yodo1MasAdEventCodeLoaded = 1003,
    Yodo1MasAdEventCodeLoadFail = 1004,
    Yodo1MasAdEventCodeOpenFail = 1005,
    Yodo1MasAdEventCodeRewardEarned = 2001,
    Yodo1MasAdEventCodePayRevenue = 2002,
};

typedef NS_ENUM(NSInteger, Yodo1MasErrorCode) {
    Yodo1MasErrorCodeUnknown = -1,
    
    Yodo1MasErrorCodeConfigNetwork = -100000, //No WIFI/4G or Request Timeout
    Yodo1MasErrorCodeConfigGet = -100501, //Data parsing failed
    Yodo1MasErrorCodeAppKeyIllegal = -400000, //Invalid AppKey or Wrong AppKey
    Yodo1MasErrorCodeAppKeyUnverified = -400001, //AppKey Bundle ID Admob ID not match please check your app profile
    Yodo1MasErrorCodeNncessaryIdUnverified = -400002, //Invalid AppLovinSdkKey
    Yodo1MasErrorCodeSdkUninitialized = -500000, //Sdk Uninitialized
    Yodo1MasErrorCodeAdConfigNull = -600000, // Wrong ad type call.Please check your app profile on MAS to ensure you have selected the correct ad type.
    Yodo1MasErrorCodeAdUninitialized = -600001, // Ads Uninitialized
    Yodo1MasErrorCodeAdNoLoaded = -600200, // Ad not avaliable,no cache
    Yodo1MasErrorCodeAdShowFail = -600201, //Ad not avaliable,unable to show
    Yodo1MasErrorCodeAdLoadFail = -600202, // Ad load failed
    
    Yodo1MasErrorCodeAdBannerSizeNotSupport = -600203, // Unsupported banner size is used, please contact your CS
    Yodo1MasErrorCodeMultipleBannerNotSupport = -600204, // The ad configuration does not support multiple banners, please contact your CS
    Yodo1MasErrorCodeCappingPacingNotMet = -600205, // Ad requests are blocked by MAS capping/pacing feature
    Yodo1MasErrorCodeAdServingLimited = -600206, // The ad serving is limited due to more than 20 consecutive failed requests during this session. Please relaunch the application to initiate the ad request again.
        
    Yodo1MasErrorCodeUMPDisable = -700000, // UMP was disabled
    Yodo1MasErrorCodeNotEUGeography = -700001, // Non-EU Geography
    Yodo1MasErrorCodeAdmobIdNotExist = -700002, // AdMob App ID was missing
    Yodo1MasErrorCodeConsentFormError = -700003, // Consent form error

};

typedef NS_ENUM(NSInteger, Yodo1MasPersonalizedAdState) {
    Yodo1MasPersonalizedAdOn = 0,
    Yodo1MasPersonalizedAdOff = 1,
};

#endif /* Yodo1MasCommon_h */
