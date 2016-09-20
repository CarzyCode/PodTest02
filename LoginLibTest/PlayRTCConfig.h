//
//  PlayRTCConfig.h
//  PlayRTC
//
//  Created by ds3grk on 2015. 11. 9
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCConfig_h__
#define __PlayRTCConfig_h__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayRTCDefine.h"

/**
 * PlayRTC Video-Stream 설정 Class.
 */
@interface PlayRTCVideoConfig : NSObject
/**
 * PlayRTC Video-Stream 전송 여부를 지정한다.
 * default TRUE, FALSE 지정 시 read-only mode로 동작
 * @param enable BOOL
 */
-(void)setEnable:(BOOL)enable;
/**
 * PlayRTC Video영상을 위한 카메라를 지정한다.
 * @param camera CameraType
 * @see PlayRTCDefine.h
 *   CameraTypeFront : 전방 카메라
 *   CameraTypeBack : 후방 카메라
 */
-(void)setCameraType:(CameraType)camera;

// ios sdk는 640x480 해상도만 지원하며, 네트워크 사정에 따라 작은 해상도로 자동으로 적용됨.
// 현재 미지원 기능
-(void)setMaxFrameSize:(int)width height:(int)height;
// ios sdk는 640x480 해상도만 지원하며, 네트워크 사정에 따라 작은 해상도로 자동으로 적용됨.
// 현재 미지원 기능
-(void)setMinFrameSize:(int)width height:(int)height;
// ios sdk는 30으로 초기 지정되며, 네트워크 사정에 따라 작은 값으로 자동으로 적용됨.
// 현재 미지원 기능
-(void)setMaxFrameRate:(int)frameRate;
// ios sdk는 15으로 초기 지정되며, 네트워크 사정에 따라 작은 값으로 자동으로 적용됨.
// 현재 미지원 기능
-(void)setMinFrameRate:(int)frameRate;

@end

/**
 * PlayRTC Audio-Stream 설정 Class.
 */
@interface PlayRTCAudioConfig : NSObject
/**
 * PlayRTC Audio-Stream 전송 여부를 지정한다.
 * default TRUE, FALSE 지정 시 read-only mode로 동작
 * @param enable BOOL
 */
-(void)setEnable:(BOOL)enable;
/**
 * PlayRTC Audio Echo-Cancellation 기능 사용을 지정한다.
 * default TRUE
 * @param enable BOOL
 */
-(void)setEchoCancellationEnable:(BOOL)enable;
/**
 * PlayRTC Audio Auto-GainControl 기능 사용을 지정한다.
 * default TRUE
 * @param enable BOOL
 */
-(void)setAutoGainControlEnable:(BOOL)enable;
/**
 * PlayRTC Audio Noise-Suppression 기능 사용을 지정한다.
 * default TRUE
 * @param enable BOOL
 */
-(void)setNoiseSuppressionEnable:(BOOL)enable;
/**
 * PlayRTC Audio Highpass-Filter 기능 사용을 지정한다.
 * default TRUE
 * @param enable BOOL
 */
-(void)setHighpassFilterEnable:(BOOL)enable;

@end

/**
 * PlayRTC Data-Stream 설정 Class.
 */
@interface PlayRTCDataConfig : NSObject
/**
 * PlayRTC Data-Stream 사용 여부를 지정한다.
 * default FALSE
 * @param enable BOOL
 */
-(void)setEnable:(BOOL)enable;

@end

/**
 * PlayRTC P2P-Stream BandWidth 설정 Class.
 */
@interface PlayRTCBandWidthConfig : NSObject
/**
 * PlayRTC Video-Stream BandWidth를 지정한다.
 * default 2500
 * @param bitrateKbps int
 */
-(void)setVideoBitrateKbps:(int)bitrateKbps;
/**
 * PlayRTC Audio-Stream BandWidth를 지정한다.
 * default 50
 * @param bitrateKbps int
 */
-(void)setAudioBitrateKbps:(int)bitrateKbps;
/**
 * PlayRTC Data-Stream BandWidth를 지정한다.
 * default 1638
 * @param bitrateKbps int
 */
-(void)setDataBitrateKbps:(int)bitrateKbps;

@end

/**
 * 콘솔 로그 설정 Class.
 * 기본 로그 레벨 LOG_TRACE
 */
@interface PlayRTCLogConsoleConfig : NSObject
/**
 * 콘솔 로그 레벨 설정 지정
 * default LOG_TRACE
 * @param level int
 */
-(void)setLevel:(int)level;
@end

/**
 * File 로그 설정 Class.
 * 기본 로그 레벨 LOG_TRACE
 */
@interface PlayRTCLogFileConfig : NSObject
/**
 * File 로그 레벨 설정 지정
 * default LOG_TRACE
 * @param level int
 */
-(void)setLevel:(int)level;
/**
 *  파일 유지 일자를 지정, 일수, default 10
 * @param rolling int, 파일 유지 일수
 */
-(void)setRolling:(int)rolling;
/**
 * 로그 파일 폴더 설정, 미지정 시 로깅 안함
 * @param logPath NSString
 */
-(void)setLogPath:(NSString*)path;
@end

/**
 * PlayRTC SDK 로깅 설정 Class.
 */
@interface PlayRTCLogConfig : NSObject
{
    PlayRTCVideoConfig* video;
    PlayRTCLogFileConfig* file;
}
@property (strong, nonatomic) PlayRTCLogConsoleConfig* console;
@property (strong, nonatomic) PlayRTCLogFileConfig* file;

@end

@interface PlayRTCICEServerConfig : NSObject
-(void)add:(NSString*)url username:(NSString*)username credential:(NSString*)credential;

@end

/**
 * PlayRTC SDK 사용을 위한 설정 정보를 정의한 Class
 * 설정 정보
 *
 * - PlayRTC 프로젝트 ID
 * - 채널 입장 시 선 입장 사용자에게 연결 여부를 묻는 과정을 수행할 지 여부를 지정
 * - 로깅 정보 (콘솔/파일, 로그레벨)
 * - PlayRTC Video-Stream 설정
 * - PlayRTC Audio-Stream 설정
 * - PlayRTC Data-Stream 설정
 * - PlayRTC P2P-Stream Bandwidth 설정
 */
@interface PlayRTCConfig : NSObject
{
    PlayRTCVideoConfig* video;
    PlayRTCAudioConfig* audio;
    PlayRTCDataConfig* data;
    PlayRTCBandWidthConfig* bandwidth;
    PlayRTCLogConfig* log;
    PlayRTCICEServerConfig* iceServers;
    
}
@property (strong, nonatomic) PlayRTCVideoConfig* video;
@property (strong, nonatomic) PlayRTCAudioConfig* audio;
@property (strong, nonatomic) PlayRTCDataConfig* data;
@property (strong, nonatomic) PlayRTCBandWidthConfig* bandwidth;
@property (strong, nonatomic) PlayRTCLogConfig* log;
@property (strong, nonatomic) PlayRTCICEServerConfig* iceServers;



/**
 * PlayRTC Application의 SK T-DEV 프로제트 아이디를 저장한다.
 * @param projectId NSString
 */
- (void)setProjectId:(NSString*)projectId;
/**
 * 채널 입장 시 선 입장 사용자에게 연결 야부를 묻는 과정을 수행할 지 여부를 지정
 * @param enable BOOL
 */
- (void)setRingEnable:(BOOL)enable;

@end

#endif

