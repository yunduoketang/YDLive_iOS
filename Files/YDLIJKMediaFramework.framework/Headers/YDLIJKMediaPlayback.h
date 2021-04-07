/*
 * IJKMediaPlayback.h
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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, YDLIJKMPMovieScalingMode) {
    YDLIJKMPMovieScalingModeNone,       // No scaling
    YDLIJKMPMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    YDLIJKMPMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    YDLIJKMPMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, YDLIJKMPMoviePlaybackState) {
    YDLIJKMPMoviePlaybackStateStopped,
    YDLIJKMPMoviePlaybackStatePlaying,
    YDLIJKMPMoviePlaybackStatePaused,
    YDLIJKMPMoviePlaybackStateInterrupted,
    YDLIJKMPMoviePlaybackStateSeekingForward,
    YDLIJKMPMoviePlaybackStateSeekingBackward
};

typedef NS_OPTIONS(NSUInteger, YDLIJKMPMovieLoadState) {
    YDLIJKMPMovieLoadStateUnknown        = 0,
    YDLIJKMPMovieLoadStatePlayable       = 1 << 0,
    YDLIJKMPMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    YDLIJKMPMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

typedef NS_ENUM(NSInteger, YDLIJKMPMovieFinishReason) {
    YDLIJKMPMovieFinishReasonPlaybackEnded,
    YDLIJKMPMovieFinishReasonPlaybackError,
    YDLIJKMPMovieFinishReasonUserExited
};

// -----------------------------------------------------------------------------
// Thumbnails

typedef NS_ENUM(NSInteger, YDLIJKMPMovieTimeOption) {
    YDLIJKMPMovieTimeOptionNearestKeyFrame,
    YDLIJKMPMovieTimeOptionExact
};

@protocol YDLIJKMediaPlayback;

#pragma mark YDLIJKMediaPlayback

@protocol YDLIJKMediaPlayback <NSObject>

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (void)shutdown;
- (void)setPauseInBackground:(BOOL)pause;

@property(nonatomic, readonly)  UIView *view;
@property(nonatomic)            NSTimeInterval currentPlaybackTime;
@property(nonatomic, readonly)  NSTimeInterval duration;
@property(nonatomic, readonly)  NSTimeInterval playableDuration;
@property(nonatomic, readonly)  NSInteger bufferingProgress;

@property(nonatomic, readonly)  BOOL isPreparedToPlay;
@property(nonatomic, readonly)  YDLIJKMPMoviePlaybackState playbackState;
@property(nonatomic, readonly)  YDLIJKMPMovieLoadState loadState;
@property(nonatomic, readonly) int isSeekBuffering;
@property(nonatomic, readonly) int isAudioSync;
@property(nonatomic, readonly) int isVideoSync;

@property(nonatomic, readonly) int64_t numberOfBytesTransferred;

@property(nonatomic, readonly) CGSize naturalSize;
@property(nonatomic) YDLIJKMPMovieScalingMode scalingMode;
@property(nonatomic) BOOL shouldAutoplay;

@property (nonatomic) BOOL allowsMediaAirPlay;
@property (nonatomic) BOOL isDanmakuMediaAirPlay;
@property (nonatomic, readonly) BOOL airPlayMediaActive;

@property (nonatomic) float playbackRate;
@property (nonatomic) float playbackVolume;

- (UIImage *)thumbnailImageAtCurrentTime;

#pragma mark Notifications

#ifdef __cplusplus
#define YDLIJK_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define YDLIJK_EXTERN extern __attribute__((visibility ("default")))
#endif

// -----------------------------------------------------------------------------
//  MPMediaPlayback.h

// Posted when the prepared state changes of an object conforming to the MPMediaPlayback protocol changes.
// This supersedes MPMoviePlayerContentPreloadDidFinishNotification.
YDLIJK_EXTERN NSString *const YDLIJKMPMediaPlaybackIsPreparedToPlayDidChangeNotification;

// -----------------------------------------------------------------------------
//  MPMoviePlayerController.h
//  Movie Player Notifications

// Posted when the scaling mode changes.
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerScalingModeDidChangeNotification;

// Posted when movie playback ends or a user exits playback.
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerPlaybackDidFinishNotification;
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerPlaybackDidFinishReasonUserInfoKey; // NSNumber (IJKMPMovieFinishReason)

// Posted when the playback state changes, either programatically or by the user.
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerPlaybackStateDidChangeNotification;

// Posted when the network load state changes.
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerLoadStateDidChangeNotification;

// Posted when the movie player begins or ends playing video via AirPlay.
YDLIJK_EXTERN NSString* const YDLIJKMPMoviePlayerIsAirPlayVideoActiveDidChangeNotification;

// -----------------------------------------------------------------------------
// Movie Property Notifications

// Calling -prepareToPlay on the movie player will begin determining movie properties asynchronously.
// These notifications are posted when the associated movie property becomes available.
YDLIJK_EXTERN NSString* const YDLIJKMPMovieNaturalSizeAvailableNotification;

// -----------------------------------------------------------------------------
//  Extend Notifications

YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerVideoDecoderOpenNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerFirstVideoFrameRenderedNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerFirstAudioFrameRenderedNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerFirstAudioFrameDecodedNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerFirstVideoFrameDecodedNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerOpenInputNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerFindStreamInfoNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerComponentOpenNotification;

YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerDidSeekCompleteNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerDidSeekCompleteTargetKey;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerDidSeekCompleteErrorKey;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerDidAccurateSeekCompleteCurPos;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerAccurateSeekCompleteNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerSeekAudioStartNotification;
YDLIJK_EXTERN NSString *const YDLIJKMPMoviePlayerSeekVideoStartNotification;

@end

#pragma mark YDLIJKMediaUrlOpenDelegate

// Must equal to the defination in ijkavformat/ijkavformat.h
typedef NS_ENUM(NSInteger, YDLIJKMediaEvent) {

    // Notify Events
    YDLIJKMediaEvent_WillHttpOpen         = 1,       // attr: url
    YDLIJKMediaEvent_DidHttpOpen          = 2,       // attr: url, error, http_code
    YDLIJKMediaEvent_WillHttpSeek         = 3,       // attr: url, offset
    YDLIJKMediaEvent_DidHttpSeek          = 4,       // attr: url, offset, error, http_code
    // Control Message
    YDLIJKMediaCtrl_WillTcpOpen           = 0x20001, // YDLIJKMediaUrlOpenData: no args
    YDLIJKMediaCtrl_DidTcpOpen            = 0x20002, // YDLIJKMediaUrlOpenData: error, family, ip, port, fd
    YDLIJKMediaCtrl_WillHttpOpen          = 0x20003, // YDLIJKMediaUrlOpenData: url, segmentIndex, retryCounter
    YDLIJKMediaCtrl_WillLiveOpen          = 0x20005, // YDLIJKMediaUrlOpenData: url, retryCounter
    YDLIJKMediaCtrl_WillConcatSegmentOpen = 0x20007, // YDLIJKMediaUrlOpenData: url, segmentIndex, retryCounter
};

#define YDLIJKMediaEventAttrKey_url            @"url"
#define YDLIJKMediaEventAttrKey_host           @"host"
#define YDLIJKMediaEventAttrKey_error          @"error"
#define YDLIJKMediaEventAttrKey_time_of_event  @"time_of_event"
#define YDLIJKMediaEventAttrKey_http_code      @"http_code"
#define YDLIJKMediaEventAttrKey_offset         @"offset"
#define YDLIJKMediaEventAttrKey_file_size      @"file_size"

// event of YDLIJKMediaUrlOpenEvent_xxx
@interface YDLIJKMediaUrlOpenData: NSObject

- (id)initWithUrl:(NSString *)url
            event:(YDLIJKMediaEvent)event
     segmentIndex:(int)segmentIndex
     retryCounter:(int)retryCounter;

@property(nonatomic, readonly) YDLIJKMediaEvent event;
@property(nonatomic, readonly) int segmentIndex;
@property(nonatomic, readonly) int retryCounter;

@property(nonatomic, retain) NSString *url;
@property(nonatomic, assign) int fd;
@property(nonatomic, strong) NSString *msg;
@property(nonatomic) int error; // set a negative value to indicate an error has occured.
@property(nonatomic, getter=isHandled)    BOOL handled;     // auto set to YES if url changed
@property(nonatomic, getter=isUrlChanged) BOOL urlChanged;  // auto set to YES by url changed

@end

@protocol YDLIJKMediaUrlOpenDelegate <NSObject>

- (void)willOpenUrl:(YDLIJKMediaUrlOpenData*) urlOpenData;

@end

@protocol YDLIJKMediaNativeInvokeDelegate <NSObject>

- (int)invoke:(YDLIJKMediaEvent)event attributes:(NSDictionary *)attributes;

@end
