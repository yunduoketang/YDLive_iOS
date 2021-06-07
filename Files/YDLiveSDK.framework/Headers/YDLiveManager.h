//
//  YDLiveManager.h
//  YDLiveSDK
//
//  Created by Lugick Wang on 2021/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YDLiveManager : NSObject
+ (YDLiveManager *)sharedInstance;

///0dev 1rel 2正式
- (void)setServiceMode:(NSInteger)mode;

/// 初始化 service
/// @param realName 用户名
/// @param roomIdentifier 房间号
/// @param userType /// 1:学生 2:老师 3:助教 4:巡课
/// @param accessKey 房间密码
/// @param sign 用户的签名
/// @param uniqueKey 用来标记用户的唯一标记
/// @param complete roomType 1:1对1 2:小班课 3:大班课 4 双师
- (void)initServiceWithRealName:(NSString *)realName
                 roomIdentifier:(NSString *)roomIdentifier
                       userType:(NSInteger)userType
                      accessKey:(NSString * _Nullable)accessKey
                           sign:(NSString * _Nullable)sign
                      uniqueKey:(NSString * _Nullable)uniqueKey
                       complete:(void(^)(NSError *error,  NSInteger roomType))complete;

@end

NS_ASSUME_NONNULL_END
