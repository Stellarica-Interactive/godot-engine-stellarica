#ifndef GodotYodo1Mas_h
#define GodotYodo1Mas_h

#include "core/object/ref_counted.h"

class GodotYodo1Mas : public RefCounted {
    GDCLASS(GodotYodo1Mas, RefCounted);

    bool initialized;
protected:
    static void _bind_methods();

public:
	bool isInitialized();
    void init(const String &appId);

    void setBannerCallback();
    void setInterstitialAdCallback();	
    void setRewardedAdCallback();
	
	void setGDPR(bool gdpr);
	void setCCPA(bool ccpa);	
	void setCOPPA(bool coppa);
	
	void showReportAd();
	
	void loadBannerAd(const String &size, const String& horizontalALignment, const String& verticalAlignment, const String& placementId);
	void hideBannerAd();
	void showBannerAd();

	bool isInterstitialAdLoaded();
    void initializeInterstitialAd();
	void showInterstitialAd(const String& placementId);
	
	bool isAppOpenAdLoaded();
	void initializeAppOpenAd();
	void showAppOpenAd(const String& placementId);

	bool isRewardedAdLoaded();
	void initializeRewardedAd();
    void showRewardedAd(const String& placementId);
	
	void updateBannerPosition();

    GodotYodo1Mas();
    ~GodotYodo1Mas();
};

#endif
