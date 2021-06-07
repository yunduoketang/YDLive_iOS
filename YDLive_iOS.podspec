Pod::Spec.new do |s|

    s.name         = "YDLive_iOS"
    s.summary      = "YDLive SDK for iOS."
  
    s.homepage     = "https://github.com/yunduoketang/YDLive_iOS.git"
  
    s.license      = "MIT"
  
    s.author             = { "yunduoketang" => "admin@yuuxin.com" }
    s.version = "1.2.1.1"
    s.platform     = :ios
    s.platform     = :ios, "9.0"
  
    s.source       = { :git => "https://github.com/yunduoketang/YDLive_iOS.git", :tag => "#{s.version}" }
  
   s.source_files  =  "Files/YDLiveSDK.framework/Headers/*.h"
    # s.exclude_files = "Classes/Exclude"
  
    s.public_header_files = "Files/YDLiveSDK.framework/Headers/*.h"
  
    s.resources = "Files/YDLiveAuthMessage.plist"

    s.vendored_frameworks = "Files/YDLiveSDK.framework"
  
    s.requires_arc = true
  
    s.frameworks = 
    "UIKit", "OpenAL", "Accelerate", "ReplayKit", "AVFoundation", "WebKit", 
    "AudioToolbox", "CoreGraphics", "CoreMedia", "CoreVideo", "MediaPlayer", 
    "MobileCoreServices", "OpenGLES", "QuartzCore", "Foundation", "VideoToolbox"

    s.libraries = "sqlite3", "resolv", "c++", "z", "bz2"
  
    s.dependency 'AFNetworking', '4.0.1'
    s.dependency 'SDWebImage', '5.10.2'
    s.dependency 'MBProgressHUD', '1.2.0'
    s.dependency 'Masonry', '1.1.0'

    s.dependency 'TEduBoard_iOS','2.5.5.22'
    s.dependency 'TXIMSDK_iOS','5.1.2'
    s.dependency 'TXLiteAVSDK_TRTC','7.2.8980'

    # # tx oss
    s.dependency 'QCloudCOSXML/Transfer', '5.8.1'
  
    # #ali oss
    s.dependency 'AliyunOSSiOS', '~> 2.10.9'
    # #qiNiu oss
    # # pod 'Qiniu', '8.0.0'
  
    #声网 rtc
    s.dependency 'AgoraRtcEngine_iOS', '~> 2.9.0.107'
  
    #tx 快直播
    # s.dependency 'TWebRTC', :git=>'https://github.com/tencentyun/TWebRTC-IOS-SDK.git' , :tag => '2.1.11'
    # s.dependency 'LiveEB_IOS', :git=>'https://github.com/tencentyun/leb-ios-sdk.git' , :tag => '2.1.10'
  
    #ali 快直播
    s.dependency 'RtsSDK', '1.3.0'
    s.dependency 'AliPlayerSDK_iOS', '5.2.1'
    s.dependency 'AliPlayerSDK_iOS_ARTC', '5.2.1'
  
  end