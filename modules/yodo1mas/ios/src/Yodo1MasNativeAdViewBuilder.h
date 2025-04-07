//
//  Yodo1MasNativeAdViewBuilder.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2022/2/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasNativeAdViewBuilder : NSObject

@property (nonatomic, assign) NSInteger titleTextViewTag;
@property (nonatomic, assign) NSInteger bodyTextViewTag;
@property (nonatomic, assign) NSInteger advertiserTextViewTag;
@property (nonatomic, assign) NSInteger iconImageViewTag;
@property (nonatomic, assign) NSInteger mediaContentViewGroupTag;
@property (nonatomic, assign) NSInteger optionsContentViewGroupTag;
@property (nonatomic, assign) NSInteger callToActionButtonTag;

@end

NS_ASSUME_NONNULL_END
