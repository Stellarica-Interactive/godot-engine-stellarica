/**************************************************************************/
/*  GodotYodo1Mas.h                                                       */
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

#pragma once

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

	void loadBannerAd(const String &size, const String &horizontalAlignment, const String &verticalAlignment, const String &placementId);
	void hideBannerAd();
	void showBannerAd();

	bool isInterstitialAdLoaded();
	void initializeInterstitialAd();
	void showInterstitialAd(const String &placementId);

	bool isAppOpenAdLoaded();
	void initializeAppOpenAd();
	void showAppOpenAd(const String &placementId);

	bool isRewardedAdLoaded();
	void initializeRewardedAd();
	void showRewardedAd(const String &placementId);

	void updateBannerPosition();

	GodotYodo1Mas();
	~GodotYodo1Mas();
};