//
//  YDLHud.h
//  YDLiveSDK
//
//  Created by Lugick Wang on 2020/11/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YDLHud : NSObject

+ (void)showLoading;

+ (void)showWithMessage:(NSString *)msg;

+ (void)hide;


@end

NS_ASSUME_NONNULL_END
