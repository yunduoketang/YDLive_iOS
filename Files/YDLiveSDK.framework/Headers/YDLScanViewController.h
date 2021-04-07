//
//  YDLScanViewController.h
//  YDLiveSDK
//
//  Created by Lugick Wang on 2020/12/11.
//  Copyright © 2020 yunduoketang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YDLBaseViewController.h"



NS_ASSUME_NONNULL_BEGIN

@interface YDLScanViewController : YDLBaseViewController

- (void)scanResult:(void(^)(NSString *))result;

@end

NS_ASSUME_NONNULL_END
