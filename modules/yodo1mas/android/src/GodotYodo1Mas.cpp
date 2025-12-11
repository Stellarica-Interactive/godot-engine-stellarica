#include "GodotYodo1Mas.h"

#ifdef ANDROID_ENABLED

#include "core/config/engine.h"
#include "platform/android/jni_utils.h"

#define JAVA_CLASS_NAME "com/stellarica/godot/GodotYodo1Mas"

static GodotYodo1Mas *singleton = nullptr;

GodotYodo1Mas::GodotYodo1Mas() {
	singleton = this;
	initialized = false;
}

GodotYodo1Mas::~GodotYodo1Mas() {
	singleton = nullptr;
}

bool GodotYodo1Mas::isInitialized() {
	return initialized;
}

void GodotYodo1Mas::setGDPR(bool gdpr) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "setGDPR", "(Z)V");
		if (method) {
			env->CallStaticVoidMethod(cls, method, (jboolean)gdpr);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::setCCPA(bool ccpa) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "setCCPA", "(Z)V");
		if (method) {
			env->CallStaticVoidMethod(cls, method, (jboolean)ccpa);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::setCOPPA(bool coppa) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "setCOPPA", "(Z)V");
		if (method) {
			env->CallStaticVoidMethod(cls, method, (jboolean)coppa);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::init(const String &appId) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;)V");
		if (method) {
			jstring jAppId = env->NewStringUTF(appId.utf8().get_data());
			env->CallStaticVoidMethod(cls, method, jAppId);
			env->DeleteLocalRef(jAppId);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::setBannerCallback() {
	// Callbacks are handled in Java
}

void GodotYodo1Mas::setInterstitialAdCallback() {
	// Callbacks are handled in Java
}

void GodotYodo1Mas::setRewardedAdCallback() {
	// Callbacks are handled in Java
}

void GodotYodo1Mas::showReportAd() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "showReportAd", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::loadBannerAd(const String &size, const String& horizontalAlignment, const String& verticalAlignment, const String& placementId) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "loadBannerAd", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		if (method) {
			jstring jSize = env->NewStringUTF(size.utf8().get_data());
			jstring jHAlign = env->NewStringUTF(horizontalAlignment.utf8().get_data());
			jstring jVAlign = env->NewStringUTF(verticalAlignment.utf8().get_data());
			jstring jPlacementId = env->NewStringUTF(placementId.utf8().get_data());

			env->CallStaticVoidMethod(cls, method, jSize, jHAlign, jVAlign, jPlacementId);

			env->DeleteLocalRef(jSize);
			env->DeleteLocalRef(jHAlign);
			env->DeleteLocalRef(jVAlign);
			env->DeleteLocalRef(jPlacementId);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::hideBannerAd() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "hideBannerAd", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::showBannerAd() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "showBannerAd", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

bool GodotYodo1Mas::isInterstitialAdLoaded() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL_V(env, false);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "isInterstitialAdLoaded", "()Z");
		if (method) {
			jboolean result = env->CallStaticBooleanMethod(cls, method);
			env->DeleteLocalRef(cls);
			return (bool)result;
		}
		env->DeleteLocalRef(cls);
	}
	return false;
}

void GodotYodo1Mas::initializeInterstitialAd() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "initializeInterstitialAd", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::showInterstitialAd(const String& placementId) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "showInterstitialAd", "(Ljava/lang/String;)V");
		if (method) {
			jstring jPlacementId = env->NewStringUTF(placementId.utf8().get_data());
			env->CallStaticVoidMethod(cls, method, jPlacementId);
			env->DeleteLocalRef(jPlacementId);
		}
		env->DeleteLocalRef(cls);
	}
}

bool GodotYodo1Mas::isAppOpenAdLoaded() {
	// TODO: Implement if Yodo1Mas supports app open ads on Android
	return false;
}

void GodotYodo1Mas::initializeAppOpenAd() {
	// TODO: Implement if Yodo1Mas supports app open ads on Android
}

void GodotYodo1Mas::showAppOpenAd(const String& placementId) {
	// TODO: Implement if Yodo1Mas supports app open ads on Android
}

bool GodotYodo1Mas::isRewardedAdLoaded() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL_V(env, false);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "isRewardedAdLoaded", "()Z");
		if (method) {
			jboolean result = env->CallStaticBooleanMethod(cls, method);
			env->DeleteLocalRef(cls);
			return (bool)result;
		}
		env->DeleteLocalRef(cls);
	}
	return false;
}

void GodotYodo1Mas::initializeRewardedAd() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "initializeRewardedAd", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::showRewardedAd(const String& placementId) {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "showRewardedAd", "(Ljava/lang/String;)V");
		if (method) {
			jstring jPlacementId = env->NewStringUTF(placementId.utf8().get_data());
			env->CallStaticVoidMethod(cls, method, jPlacementId);
			env->DeleteLocalRef(jPlacementId);
		}
		env->DeleteLocalRef(cls);
	}
}

void GodotYodo1Mas::updateBannerPosition() {
	JNIEnv *env = get_jni_env();
	ERR_FAIL_NULL(env);

	jclass cls = env->FindClass(JAVA_CLASS_NAME);
	if (cls) {
		jmethodID method = env->GetStaticMethodID(cls, "updateBannerPosition", "()V");
		if (method) {
			env->CallStaticVoidMethod(cls, method);
		}
		env->DeleteLocalRef(cls);
	}
}

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

// JNI callback methods
extern "C" {

JNIEXPORT void JNICALL Java_com_stellarica_godot_GodotYodo1Mas_emitSignal(JNIEnv *env, jclass cls, jstring signalName) {
	if (singleton) {
		const char *signal_cstr = env->GetStringUTFChars(signalName, nullptr);
		String signal = String(signal_cstr);
		singleton->emit_signal(StringName(signal));
		env->ReleaseStringUTFChars(signalName, signal_cstr);
	}
}

}

#endif // ANDROID_ENABLED
