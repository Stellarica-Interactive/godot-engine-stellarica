//
//  Yodo1MasError.h
//  AFNetworking
//
//  Created by ZhouYuzhen on 2020/12/16.
//

#import "Yodo1MasCommon.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasError : NSError

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey, id> *)dict NS_UNAVAILABLE;
- (instancetype)initWitCode:(Yodo1MasErrorCode)code message:(NSString *_Nullable)message;

- (NSDictionary *)getJsonObject;

@end

NS_ASSUME_NONNULL_END
