//
//  PlayRTCSettings.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCSettings_h__
#define __PlayRTCSettings_h__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayRTCDefine.h"

/**
 * 단말기 전후면 카메라 사용 여부 설정<br>
 * - (BOOL)isFrontCameraEnable
 * 		전면 카메라 사용 여부
 * - (void)setFrontCameraEnable:(BOOL)enable
 * 		전면 카메라 사용 여부 지정
 * - (BOOL)isBackCameraEnable;
 * 		전면 카메라 사용 여부
 * - (void)setBackCameraEnable:(BOOL)enable
 * 		후면 카메라 사용 여부 지정
 */
@interface VideoSetting : NSObject
{
    BOOL frontCameraEnable;
    BOOL backCameraEnable;
}

/**
 * 전면 카메라 사용 여부
 * @return BOOL
 */
- (BOOL)isFrontCameraEnable;
/**
 * 후면 카메라 사용 여부
 * @return BOOL
 */
- (BOOL)isBackCameraEnable;
/**
 * 전면 카메라 사용 여부
 * @param enable BOOL
 */
- (void)setFrontCameraEnable:(BOOL)enable;

/**
 * 후면 카메라 사용 여부 지정
 * @param enable BOOL
 */
- (void)setBackCameraEnable:(BOOL)enable;

@end

/**
 * PlayRTC 채널링에 필요한 설정 정보
 */
@interface ChannelSetting : NSObject
{
    /**
     * 채널 서비스 서버 url
     */
    NSString* channelUrl;
    /**
     * 채널 입장 시 선 입장 사용자에게 연결 야부를 묻는 과정을 수행할 지 여부
     */
    BOOL ringEnable;
    
}

/**
 * 채널 Url 반환
 * @return String
 */
- (NSString*)getUrl;
/**
 * 채널 입장 시 선 입장 사용자에게 연결 야부를 묻는 과정을 수행할 지 여부를 반환
 * @return BOOL
 */
- (BOOL)isRing;
/**
 * 채널 입장 시 선 입장 사용자에게 연결 야부를 묻는 과정을 수행할 지 여부를 지정
 * @param ring BOOL
 */
- (void)setRing:(BOOL)ring;

@end


/**
 * ICE 서버 정보를 설정한다.<br>
 * 기본적으로 PlayRTC 채널 서비스에서 전달 받은 서비스 설정의  ICE 서버 정보를 사용하나 외부의 ICE 서버를 설정할 수 있다.<br>
 *
 */
@interface ICEServerSetting : NSObject
{
    NSMutableArray* list;
    BOOL userIceSetting;
}
@property (assign) BOOL userIceSetting;
@property (strong, nonatomic) NSMutableArray* list;
- (void)addIceServer:(NSString*)url username:(NSString*)username credential:(NSString*)credential;
- (void)resetIceServer:(NSString*)url username:(NSString*)username credential:(NSString*)credential;
@end

/**
 * 전송 영상 해상도
 */
@interface ConstraintSetting : NSObject



@end


/**
 * 콘솔 로그 레벨 설정
 * 기본 로그 레벨 LOG_TRACE
 */
@interface ConsoleLog : NSObject
{
    /**
     * 콘솔 로그 레벨, default LOG_TRACE
     */
    int logLevel;
}

/**
 * 콘솔 로그 레벨 설정 반환
 * @return int
 */
- (int)getLevel;

/**
 * 콘솔 로그 레벨 설정 지정
 * @param level int
 */
- (void)setLevel:(int)level;
@end


/**
 * File 로그 레벨 설정 <br>
 * 기본 File 로그 레벨 PlayRTCSettings.DEBUG<br>
 * 로그 파일 폴더 Path와 파일 유지 일자 설정이 있다. <br>
 */
@interface FileLog : NSObject
{
    /**
     * File 로그 레벨, default LOG_TRACE
     */
    int logLevel;
    /**
     * 로그 파일 폴더 Path
     */
    NSString* logPath;
    /**
     * 파일 유지 일자, 기본 10일
     */
    int logRolling;
}

/**
 * 파일 로그 레벨 설정 반환
 * @return int
 */
- (int)getLevel;

/**
 * 파일 로그 레벨 설정 지정
 * @param level
 */
- (void)setLevel:(int)level;

/**
 * 파일 유지 일자를 빈환 , 기본 10일
 * @return int
 */
- (int)getRolling;

/**
 *  파일 유지 일자를 지정, 일수
 * @param rolling int, 파일 유지 일수
 */
- (void)setRolling:(int)rolling;

/**
 * 로그 파일 폴더 반환
 * @return String
 */
- (NSString*)getLogPath;

/**
 * 로그 파일 폴더 설정
 * @param logPath NSString
 */
- (void)setLogPath:(NSString*)path;
@end

@interface MonitorLog : NSObject
{
    NSString* logPath;
    int logRolling;
}
- (int)getRolling;
- (void)setRolling:(int)rolling;
- (NSString*)getLogPath;
- (void)setLogPath:(NSString*)path;
@end

/**
 * PlayRTC SDK 로깅 설정 <br>
 * 멤버
 * - ConsoleLog* console;
 * 		콘솔 로그 설정
 * - FileLog* file
 * 		파일 로그 설정
 * - NSString* cachePath
 * 		주요 로그  서버 전송을 위한 관련 파일 Cache 폴더
 * - long retryQueueDelays
 * 		주요 로그  서버 전송 실패 시 재전송 시도 지연 시간
 * - long retryCacheDelays
 * 		주요 로그  서버 재전송 실패 로그(Cache 로그)  재전송 시도 지연 시간
 * 멤버 인터페이스
 * - (long)getRetryQueueDelays
 * 		주요 로그 서버 전송 실패 시 재전송 시도 지연 시간을 반환, 기본 500 msec
 * - (void)setRetryQueueDelays:(long)delays
 * 		주요 로그 서버 전송 실패 시 재전송 시도 지연 시간을 지정
 * - (long)getRetryCacheDelays
 * 		주요 로그  서버 재전송 실패 로그(Cache 로그) 재전송 시도 지연 시간을 반환, 기본 10000 msec(10 sec)
 * - (void)setRetryCacheDelays:(long)delays
 * 		주요 로그  서버 재전송 실패 로그(Cache 로그) 재전송 시도 지연 시간을 지정
 * - (NSString*)getCachePath
 * 		주요 로그 서버 재 전송을 위한 관련 파일 Cache 폴더를 반환 , 미지정 시 재전송 안함
 * - (void)setCachePath:(NSString*)path
 * 		주요 로그 서버 재 전송을 위한 관련 파일 Cache 폴더를 지정
 */
@interface LogSetting : NSObject
{
    ConsoleLog* console;
    FileLog* file;
    /* 내부에서 사용 */
    MonitorLog* monitor;
    NSString* cachePath;
    long retryQueueDelays;
    long retryCacheDelays;
    
}

@property (strong, nonatomic) ConsoleLog* console;
@property (strong, nonatomic) FileLog* file;
@property (strong, nonatomic) MonitorLog* monitor;

/**
 * 주요 로그 서버 전송 실패 시 재전송 시도 지연 시간을 반환, 기본 500 msec
 * @return long
 */
- (long)getRetryQueueDelays;
/**
 * 주요 로그 서버 전송 실패 시 재전송 시도 지연 시간을 지정
 * @param retryQueueDelays long
 */
- (void)setRetryQueueDelays:(long)delays;
/**
 * 주요 로그  서버 재전송 실패 로그(Cache 로그) 재전송 시도 지연 시간을 반환, 기본 10000 msec(10 sec)
 * @return long
 */
- (long)getRetryCacheDelays;
/**
 * 주요 로그  서버 재전송 실패 로그(Cache 로그) 재전송 시도 지연 시간을 지정
 * @param retryCacheDelays long
 */
- (void)setRetryCacheDelays:(long)delays;
/**
 * 주요 로그 서버 재 전송을 위한 관련 파일 Cache 폴더를 반환 , 미지정 시 재전송 안함
 * @return NSString
 */
- (NSString*)getCachePath;
/**
 * 요 로그 서버 재 전송을 위한 관련 파일 Cache 폴더를 지정, 미지정 시 재전송 안함
 * @param path NSString
 */
- (void)setCachePath:(NSString*)path;
@end

/**
 * PlayRTC SDK 사용을 위한 설정 정보를 정의한 Class
 * 주요 설정 정보
 *
 * 1. PlayRTC 프로젝트 정보
 * 2. 로깅 정보 (콘솔/파일, 로그레벨)
 * 3. 채널 서버 정보
 * 4. NAG 정보
 * 5. ICE 서버 정보
 * 6. 미디서 사용 설정 (video/Audio/Data)
 *
 */
@interface PlayRTCSettings : NSObject
{
    BOOL videoEnable;
    BOOL audioEnable;
    BOOL dataEnable;

    VideoSetting* video;
    /**
     *  PlayRTC 채널링에 필요한 설정 정보
     */
    ChannelSetting* channel;
    
    /**
     * ICE 서버 정보를 설정한다
     */
    ICEServerSetting* iceServers;
    /**
     * 로그 설정
     */
    LogSetting* log;
    
    /**
     * 전송 영상 해상도
     */
    ConstraintSetting* constraint;
}
@property (strong, nonatomic) VideoSetting* video;
@property (strong, nonatomic) ChannelSetting *channel;
@property (strong, nonatomic) ICEServerSetting *iceServers;
@property (strong, nonatomic) LogSetting *log;
@property (strong, nonatomic) ConstraintSetting *constraint;

/**
 * PlayRTC Application의 SK T-DEV 프로젝트 아이디를 반환한다.
 * @return NSString
 */
- (NSString*)getTDCProjectId;

/**
 * PlayRTC Application의 SK T-DEV 프로제트 아이디를 저장한다.
 * @param prjId NSString
 */
- (void)setTDCProjectId:(NSString*)prjId;

/**
 * T-DEV API 연동을 위한 HTTP Header 설정 값을 반환한다.
 * @return String
 */
- (NSString*)getTDCLicense;

/**
 * T-DEV API 연동을 위한 HTTP Header 설정 값을 저장한다.
 * @param lcs String
 */
- (void)setTDCLicense:(NSString*)lcs;

/**
 * T-DEV API 연동을 위한 HTTP Header 설정 값을 반환한다.
 * 기본적으로 미사용 상태
 * @return NSString
 */
- (NSString*)getTDCHttpReferer;
/**
 * T-DEV API 연동을 위한 HTTP Header 설정 값을 저장한다.
 * @param httpReferer NSString
 */
- (void)setTDCHttpReferer:(NSString*)httpReferer;

/**
 * PlayRTC Video-Stream 사용 여부를 반환한다.
 * @return BOOL
 */
- (BOOL)isVideoEnable;

/**
 * PlayRTC Video-Stream 사용 여부를 저장한다.
 * @param enable BOOL
 */
- (void)setVideoEnable:(BOOL)enable;

/**
 * PlayRTC Audio-Stream 사용 여부를 반환한다.
 * @return BOOL
 */
- (BOOL)isAudioEnable;

/**
 * PlayRTC Audio-Stream 사용 여부를 저장한다.
 * @param enable BOOL
 */
- (void)setAudioEnable:(BOOL)enable;

/**
 * PlayRTC Data-Stream 사용 여부를 반환한다.
 * @return BOOL
 */
- (BOOL)isDataEnable;

/**
 * PlayRTC Data-Stream 사용 여부를 저장한다.
 * @param enable BOOL
 */
- (void)setDataEnable:(BOOL)enable;


@end

#endif

