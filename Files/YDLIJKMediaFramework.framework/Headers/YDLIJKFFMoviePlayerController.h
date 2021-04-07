/*
 * IJKFFMoviePlayerController.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import "YDLIJKMediaPlayback.h"
#import "YDLIJKFFMonitor.h"
#import "YDLIJKFFOptions.h"
#import "YDLIJKSDLGLViewProtocol.h"

// media meta
#define k_YDLIJKM_KEY_FORMAT         @"format"
#define k_YDLIJKM_KEY_DURATION_US    @"duration_us"
#define k_YDLIJKM_KEY_START_US       @"start_us"
#define k_YDLIJKM_KEY_BITRATE        @"bitrate"

// stream meta
#define k_YDLIJKM_KEY_TYPE           @"type"
#define k_YDLIJKM_VAL_TYPE__VIDEO    @"video"
#define k_YDLIJKM_VAL_TYPE__AUDIO    @"audio"
#define k_YDLIJKM_VAL_TYPE__UNKNOWN  @"unknown"

#define k_YDLIJKM_KEY_CODEC_NAME      @"codec_name"
#define k_YDLIJKM_KEY_CODEC_PROFILE   @"codec_profile"
#define k_YDLIJKM_KEY_CODEC_LONG_NAME @"codec_long_name"

// stream: video
#define k_YDLIJKM_KEY_WIDTH          @"width"
#define k_YDLIJKM_KEY_HEIGHT         @"height"
#define k_YDLIJKM_KEY_FPS_NUM        @"fps_num"
#define k_YDLIJKM_KEY_FPS_DEN        @"fps_den"
#define k_YDLIJKM_KEY_TBR_NUM        @"tbr_num"
#define k_YDLIJKM_KEY_TBR_DEN        @"tbr_den"
#define k_YDLIJKM_KEY_SAR_NUM        @"sar_num"
#define k_YDLIJKM_KEY_SAR_DEN        @"sar_den"
// stream: audio
#define k_YDLIJKM_KEY_SAMPLE_RATE    @"sample_rate"
#define k_YDLIJKM_KEY_CHANNEL_LAYOUT @"channel_layout"

#define kk_YDLIJKM_KEY_STREAMS       @"streams"

typedef enum YDLIJKLogLevel {
    k_IJK_LOG_UNKNOWN = 0,
    k_IJK_LOG_DEFAULT = 1,

    k_IJK_LOG_VERBOSE = 2,
    k_IJK_LOG_DEBUG   = 3,
    k_IJK_LOG_INFO    = 4,
    k_IJK_LOG_WARN    = 5,
    k_IJK_LOG_ERROR   = 6,
    k_IJK_LOG_FATAL   = 7,
    k_IJK_LOG_SILENT  = 8,
} YDLIJKLogLevel;

@interface YDLIJKFFMoviePlayerController : NSObject <YDLIJKMediaPlayback>

- (id)initWithContentURL:(NSURL *)aUrl
             withOptions:(YDLIJKFFOptions *)options;

- (id)initWithContentURLString:(NSString *)aUrlString
                   withOptions:(YDLIJKFFOptions *)options;

- (id)initWithMoreContent:(NSURL *)aUrl
             withOptions:(YDLIJKFFOptions *)options
              withGLView:(UIView<YDLIJKSDLGLViewProtocol> *)glView;

- (id)initWithMoreContentString:(NSString *)aUrlString
                 withOptions:(YDLIJKFFOptions *)options
                  withGLView:(UIView<YDLIJKSDLGLViewProtocol> *)glView;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (int64_t)trafficStatistic;
- (float)dropFrameRate;

- (void)setPauseInBackground:(BOOL)pause;
- (BOOL)isVideoToolboxOpen;

- (void)setHudValue:(NSString *)value forKey:(NSString *)key;

+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(YDLIJKLogLevel)logLevel;
+ (BOOL)checkIfFFmpegVersionMatch:(BOOL)showAlert;
+ (BOOL)checkIfPlayerVersionMatch:(BOOL)showAlert
                            version:(NSString *)version;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;
@property(nonatomic) BOOL shouldShowHudView;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(YDLIJKFFOptionCategory)category;

- (void)setOptionIntValue:(int64_t)value
                   forKey:(NSString *)key
               ofCategory:(YDLIJKFFOptionCategory)category;



- (void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;

@property (nonatomic, retain) id<YDLIJKMediaUrlOpenDelegate> segmentOpenDelegate;
@property (nonatomic, retain) id<YDLIJKMediaUrlOpenDelegate> tcpOpenDelegate;
@property (nonatomic, retain) id<YDLIJKMediaUrlOpenDelegate> httpOpenDelegate;
@property (nonatomic, retain) id<YDLIJKMediaUrlOpenDelegate> liveOpenDelegate;

@property (nonatomic, retain) id<YDLIJKMediaNativeInvokeDelegate> nativeInvokeDelegate;

- (void)shutdown;

#pragma mark KVO properties
@property (nonatomic, readonly) YDLIJKFFMonitor *monitor;

@end

#define YDLIJK_FF_IO_TYPE_READ (1)
void YDLIJKFFIOStatDebugCallback(const char *url, int type, int bytes);
void YDLIJKFFIOStatRegister(void (*cb)(const char *url, int type, int bytes));

void YDLIJKFFIOStatCompleteDebugCallback(const char *url,
                                      int64_t read_bytes, int64_t total_size,
                                      int64_t elpased_time, int64_t total_duration);
void YDLIJKFFIOStatCompleteRegister(void (*cb)(const char *url,
                                            int64_t read_bytes, int64_t total_size,
                                            int64_t elpased_time, int64_t total_duration));
