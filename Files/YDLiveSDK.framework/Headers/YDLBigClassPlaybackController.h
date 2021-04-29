//
//  YDLBigClassPlaybackController.h
//  YDLiveSDK
//
//  Created by Lugick Wang on 2021/1/29.
//

#import <YDLiveSDK/YDLiveSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YDLBigClassPlaybackController : YDLBaseViewController

@property (nonatomic, copy) NSString *recordIdentifier;

@property (nonatomic, copy) void (^exitCallback)(void);

@end

NS_ASSUME_NONNULL_END
