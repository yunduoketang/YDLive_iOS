//
//  YDLSmallClassViewController.h
//  YDLiveSDK
//
//  Created by Lugick Wang on 2020/11/27.
//  Copyright © 2020 yunduoketang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YDLBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN


@interface YDLSmallClassViewController : YDLBaseViewController

@property (nonatomic, copy) void (^exitCallback)(void);

@end

NS_ASSUME_NONNULL_END
