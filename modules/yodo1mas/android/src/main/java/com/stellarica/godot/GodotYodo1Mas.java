package com.stellarica.godot;

import android.app.Activity;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;

import com.yodo1.mas.Yodo1Mas;
import com.yodo1.mas.error.Yodo1MasError;
import com.yodo1.mas.banner.Yodo1MasBannerAdView;
import com.yodo1.mas.banner.Yodo1MasBannerAdListener;
import com.yodo1.mas.banner.Yodo1MasBannerAdSize;
import com.yodo1.mas.helper.model.Yodo1MasAdBuildConfig;
import com.yodo1.mas.helper.model.Yodo1MasSdkConfiguration;
import com.yodo1.mas.interstitial.Yodo1MasInterstitialAd;
import com.yodo1.mas.interstitial.Yodo1MasInterstitialAdListener;
// import com.yodo1.mas.rewarded.Yodo1MasRewardAd;
// import com.yodo1.mas.rewarded.Yodo1MasRewardAdListener;

import org.godotengine.godot.Godot;

public class GodotYodo1Mas {
    private static final String TAG = "GodotYodo1Mas";
    private static Activity activity;
    private static Yodo1MasBannerAdView bannerAdView = null;
    private static String bannerHAlign = "Left";
    private static String bannerVAlign = "Top";
    private static boolean interstitialAdLoaded = false;
    private static boolean rewardedAdLoaded = false;

    public static void initialize(Activity godotActivity) {
        activity = godotActivity;
    }

    public static void setGDPR(boolean gdpr) {
        Log.d(TAG, "setGDPR: " + gdpr);
        Yodo1Mas.getInstance().setGDPR(gdpr);
    }

    public static void setCCPA(boolean ccpa) {
        Log.d(TAG, "setCCPA: " + ccpa);
        Yodo1Mas.getInstance().setCCPA(ccpa);
    }

    public static void setCOPPA(boolean coppa) {
        Log.d(TAG, "setCOPPA: " + coppa);
        Yodo1Mas.getInstance().setCOPPA(coppa);
    }

    public static void init(final String appId) {
        Log.d(TAG, "Initializing Yodo1 MAS with appId: " + appId);

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Yodo1MasAdBuildConfig config = new Yodo1MasAdBuildConfig.Builder()
                        .enableUserPrivacyDialog(true)
                        .build();

                Yodo1Mas.getInstance().setAdBuildConfig(config);
                Yodo1Mas.getInstance().initMas(activity, appId, new Yodo1Mas.InitListener() {
                    @Override
                    public void onMasInitSuccessful(Yodo1MasSdkConfiguration sdkConfig) {
                        Log.d(TAG, "Yodo1 MAS initialized successfully");
                        emitSignal("onMasInitSuccessful");
                    }

                    @Override
                    public void onMasInitFailed(@NonNull Yodo1MasError error) {
                        Log.e(TAG, "Yodo1 MAS initialization failed: " + error.getMessage());
                        emitSignal("onMasInitFailed");
                    }
                });

                setupInterstitialCallbacks();
                setupRewardedCallbacks();
            }
        });
    }

    public static void showReportAd() {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // Yodo1Mas.getInstance().showReportDialog(activity);
                Log.d(TAG, "showReportAd - not implemented in current SDK");
            }
        });
    }

    // Banner Ad Methods
    public static void loadBannerAd(final String size, final String horizontalAlignment,
                                    final String verticalAlignment, final String placementId) {
        Log.d(TAG, "loadBannerAd: size=" + size + ", hAlign=" + horizontalAlignment +
                   ", vAlign=" + verticalAlignment + ", placement=" + placementId);

        bannerHAlign = horizontalAlignment;
        bannerVAlign = verticalAlignment;

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (bannerAdView != null) {
                    FrameLayout layout = (FrameLayout) activity.findViewById(android.R.id.content);
                    layout.removeView(bannerAdView);
                    bannerAdView.destroy();
                    bannerAdView = null;
                }

                bannerAdView = new Yodo1MasBannerAdView(activity);

                // Set banner size
                Yodo1MasBannerAdSize bannerSize = Yodo1MasBannerAdSize.Banner;
                if ("LargeBanner".equals(size)) {
                    bannerSize = Yodo1MasBannerAdSize.LargeBanner;
                } else if ("IABMediumRectangle".equals(size)) {
                    bannerSize = Yodo1MasBannerAdSize.IABMediumRectangle;
                }
                bannerAdView.setAdSize(bannerSize);

                // Set callbacks
                bannerAdView.setAdListener(new Yodo1MasBannerAdListener() {
                    @Override
                    public void onBannerAdLoaded(Yodo1MasBannerAdView bannerAdView) {
                        Log.d(TAG, "onBannerAdLoaded");
                        emitSignal("onBannerAdLoaded");
                    }

                    @Override
                    public void onBannerAdFailedToLoad(Yodo1MasBannerAdView bannerAdView, @NonNull Yodo1MasError error) {
                        Log.e(TAG, "onBannerAdFailedToLoad: " + error.getMessage());
                        emitSignal("onBannerAdFailedToLoad");
                    }

                    @Override
                    public void onBannerAdOpened(Yodo1MasBannerAdView bannerAdView) {
                        Log.d(TAG, "onBannerAdOpened");
                        emitSignal("onBannerAdOpened");
                    }

                    @Override
                    public void onBannerAdFailedToOpen(Yodo1MasBannerAdView bannerAdView, @NonNull Yodo1MasError error) {
                        Log.e(TAG, "onBannerAdFailedToOpen: " + error.getMessage());
                        emitSignal("onBannerAdFailedToOpen");
                    }

                    @Override
                    public void onBannerAdClosed(Yodo1MasBannerAdView bannerAdView) {
                        Log.d(TAG, "onBannerAdClosed");
                        emitSignal("onBannerAdClosed");
                    }
                });

                // Add to layout
                FrameLayout layout = (FrameLayout) activity.findViewById(android.R.id.content);
                FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(
                    FrameLayout.LayoutParams.WRAP_CONTENT,
                    FrameLayout.LayoutParams.WRAP_CONTENT
                );
                updateBannerGravity(params);
                layout.addView(bannerAdView, params);

                // Load the ad
                bannerAdView.loadAd();
            }
        });
    }

    private static void updateBannerGravity(FrameLayout.LayoutParams params) {
        int gravity = 0;

        // Horizontal alignment
        if ("Center".equals(bannerHAlign)) {
            gravity |= Gravity.CENTER_HORIZONTAL;
        } else if ("Right".equals(bannerHAlign)) {
            gravity |= Gravity.RIGHT;
        } else {
            gravity |= Gravity.LEFT;
        }

        // Vertical alignment
        if ("Center".equals(bannerVAlign)) {
            gravity |= Gravity.CENTER_VERTICAL;
        } else if ("Bottom".equals(bannerVAlign)) {
            gravity |= Gravity.BOTTOM;
        } else {
            gravity |= Gravity.TOP;
        }

        params.gravity = gravity;
    }

    public static void hideBannerAd() {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (bannerAdView != null) {
                    bannerAdView.setVisibility(View.GONE);
                }
            }
        });
    }

    public static void showBannerAd() {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (bannerAdView != null) {
                    bannerAdView.setVisibility(View.VISIBLE);
                }
            }
        });
    }

    public static void updateBannerPosition() {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (bannerAdView != null) {
                    FrameLayout.LayoutParams params = (FrameLayout.LayoutParams) bannerAdView.getLayoutParams();
                    if (params != null) {
                        updateBannerGravity(params);
                        bannerAdView.setLayoutParams(params);
                    }
                }
            }
        });
    }

    // Interstitial Ad Methods
    private static void setupInterstitialCallbacks() {
        Yodo1MasInterstitialAd.getInstance().setAdListener(new Yodo1MasInterstitialAdListener() {
            @Override
            public void onInterstitialAdLoaded(Yodo1MasInterstitialAd ad) {
                Log.d(TAG, "onInterstitialAdLoaded");
                interstitialAdLoaded = true;
                emitSignal("onInterstitialAdLoaded");
            }

            @Override
            public void onInterstitialAdFailedToLoad(Yodo1MasInterstitialAd ad, @NonNull Yodo1MasError error) {
                Log.e(TAG, "onInterstitialAdFailedToLoad: " + error.getMessage());
                interstitialAdLoaded = false;
                emitSignal("onInterstitialAdFailedToLoad");
            }

            @Override
            public void onInterstitialAdOpened(Yodo1MasInterstitialAd ad) {
                Log.d(TAG, "onInterstitialAdOpened");
                emitSignal("onInterstitialAdOpened");
            }

            @Override
            public void onInterstitialAdFailedToOpen(Yodo1MasInterstitialAd ad, @NonNull Yodo1MasError error) {
                Log.e(TAG, "onInterstitialAdFailedToOpen: " + error.getMessage());
                emitSignal("onInterstitialAdFailedToOpen");
            }

            @Override
            public void onInterstitialAdClosed(Yodo1MasInterstitialAd ad) {
                Log.d(TAG, "onInterstitialAdClosed");
                interstitialAdLoaded = false;
                emitSignal("onInterstitialAdClosed");
            }
        });
    }

    public static boolean isInterstitialAdLoaded() {
        return interstitialAdLoaded;
    }

    public static void initializeInterstitialAd() {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Yodo1MasInterstitialAd.getInstance().loadAd(activity);
            }
        });
    }

    public static void showInterstitialAd(final String placementId) {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (interstitialAdLoaded) {
                    Yodo1MasInterstitialAd.getInstance().showAd(activity);
                } else {
                    Log.w(TAG, "Interstitial ad not loaded");
                    emitSignal("onInterstitialAdFailedToLoad");
                }
            }
        });
    }

    // Rewarded Ad Methods - TODO: Update for v4.17.1 API
    private static void setupRewardedCallbacks() {
        // Rewarded ads API changed in v4.17.1 - needs updating
        Log.w(TAG, "Rewarded ads not yet implemented for Yodo1 MAS v4.17.1");
    }

    public static boolean isRewardedAdLoaded() {
        return rewardedAdLoaded;
    }

    public static void initializeRewardedAd() {
        Log.w(TAG, "Rewarded ads not yet implemented for Yodo1 MAS v4.17.1");
    }

    public static void showRewardedAd(final String placementId) {
        Log.w(TAG, "Rewarded ads not yet implemented for Yodo1 MAS v4.17.1");
    }

    // Native method to emit signals to Godot C++ side
    public static native void emitSignal(String signalName);
}
