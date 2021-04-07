/*
 * IJKMediaFramework.h
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

#import <UIKit/UIKit.h>

//! Project version number for IJKMediaFramework.
FOUNDATION_EXPORT double YDLIJKMediaFrameworkVersionNumber;

//! Project version string for IJKMediaFramework.
FOUNDATION_EXPORT const unsigned char YDLIJKMediaFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <IJKMediaFrameworkWithSSL/PublicHeader.h>
#import <YDLIJKMediaFramework/YDLIJKMediaPlayback.h>
#import <YDLIJKMediaFramework/YDLIJKMPMoviePlayerController.h>
#import <YDLIJKMediaFramework/YDLIJKFFOptions.h>
#import <YDLIJKMediaFramework/YDLIJKFFMoviePlayerController.h>
#import <YDLIJKMediaFramework/YDLIJKAVMoviePlayerController.h>
#import <YDLIJKMediaFramework/YDLIJKMediaModule.h>
#import <YDLIJKMediaFramework/YDLIJKMediaPlayer.h>
#import <YDLIJKMediaFramework/YDLIJKNotificationManager.h>
#import <YDLIJKMediaFramework/YDLIJKKVOController.h>
#import <YDLIJKMediaFramework/YDLIJKSDLGLViewProtocol.h>

// backward compatible for old names
#define YDLIJKMediaPlaybackIsPreparedToPlayDidChangeNotification YDLIJKMPMediaPlaybackIsPreparedToPlayDidChangeNotification
#define YDLIJKMoviePlayerLoadStateDidChangeNotification YDLIJKMPMoviePlayerLoadStateDidChangeNotification
#define YDLIJKMoviePlayerPlaybackDidFinishNotification YDLIJKMPMoviePlayerPlaybackDidFinishNotification
#define YDLIJKMoviePlayerPlaybackDidFinishReasonUserInfoKey YDLIJKMPMoviePlayerPlaybackDidFinishReasonUserInfoKey
#define YDLIJKMoviePlayerPlaybackStateDidChangeNotification YDLIJKMPMoviePlayerPlaybackStateDidChangeNotification
#define YDLIJKMoviePlayerIsAirPlayVideoActiveDidChangeNotification YDLIJKMPMoviePlayerIsAirPlayVideoActiveDidChangeNotification
#define YDLIJKMoviePlayerVideoDecoderOpenNotification YDLIJKMPMoviePlayerVideoDecoderOpenNotification
#define YDLIJKMoviePlayerFirstVideoFrameRenderedNotification YDLIJKMPMoviePlayerFirstVideoFrameRenderedNotification
#define YDLIJKMoviePlayerFirstAudioFrameRenderedNotification YDLIJKMPMoviePlayerFirstAudioFrameRenderedNotification
#define YDLIJKMoviePlayerFirstAudioFrameDecodedNotification YDLIJKMPMoviePlayerFirstAudioFrameDecodedNotification
#define YDLIJKMoviePlayerFirstVideoFrameDecodedNotification YDLIJKMPMoviePlayerFirstVideoFrameDecodedNotification
#define YDLIJKMoviePlayerOpenInputNotification YDLIJKMPMoviePlayerOpenInputNotification
#define YDLIJKMoviePlayerFindStreamInfoNotification YDLIJKMPMoviePlayerFindStreamInfoNotification
#define YDLIJKMoviePlayerComponentOpenNotification YDLIJKMPMoviePlayerComponentOpenNotification

#define YDLIJKMPMoviePlayerAccurateSeekCompleteNotification YDLIJKMPMoviePlayerAccurateSeekCompleteNotification
#define YDLIJKMoviePlayerSeekAudioStartNotification YDLIJKMPMoviePlayerSeekAudioStartNotification
#define YDLIJKMoviePlayerSeekVideoStartNotification YDLIJKMPMoviePlayerSeekVideoStartNotification

