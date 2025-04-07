//
//  Yodo1MasCallback.h
//  Pods
//
//  Created by 周玉震 on 2022/5/17.
//

#ifndef Yodo1MasCallback_h
#define Yodo1MasCallback_h

#import "Yodo1MasAdEvent.h"
#import "Yodo1MasError.h"
#import "Yodo1MasSdkConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^Yodo1MasInitSuccessful)(void);
typedef void (^Yodo1MasInitFail)(Yodo1MasError *);

typedef void (^Yodo1MasInitSuccessfulHandler)(Yodo1MasSdkConfiguration *);
typedef void (^Yodo1MasInitFailHandler)(Yodo1MasError *);

typedef void (^Yodo1MasUmpCompletionHandler)(Yodo1MasError *_Nullable);

@protocol Yodo1MasAdDelegate <NSObject>

@optional
- (void)onAdOpened:(Yodo1MasAdEvent *)event;
- (void)onAdClosed:(Yodo1MasAdEvent *)event;
- (void)onAdError:(Yodo1MasAdEvent *)event error:(Yodo1MasError *)error;

@end

@protocol Yodo1MasRewardAdDelegate <NSObject, Yodo1MasAdDelegate>

@optional
- (void)onAdRewardEarned:(Yodo1MasAdEvent *)event;

@end

@protocol Yodo1MasInterstitialAdDelegate <NSObject, Yodo1MasAdDelegate>

@end

@protocol Yodo1MasBannerAdDelegate <NSObject, Yodo1MasAdDelegate>

@end

@protocol Yodo1MasAppStatusDelegate <NSObject>

@optional
- (void)onApplicationEnterForeground;

@end

NS_ASSUME_NONNULL_END

#endif /* Yodo1MasCallback_h */
