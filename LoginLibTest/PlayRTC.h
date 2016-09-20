//
//  PlayRTC.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 7. 17..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTC_h__
#define __PlayRTC_h__

#import <Foundation/Foundation.h>
#import "SDKEnvInfo.h"
#import "PlayRTCDefine.h"
#import "PlayRTCSettings.h"
#import "PlayRTCConfig.h"
#import "PlayRTCServiceHelperListener.h"
#import "PlayRTCStatsReportObserver.h"

@class PlayRTCConnetor;
@interface PlayRTC : NSObject

/**
 * PlayRTC SDK 정보를 반환한다.
 * @see SDKEnvInfo.h
 * @return SDKEnvInfo
 */
- (SDKEnvInfo*)getSdkEnvInfo:(NSString*)peerId;

/**
 * PlayRTC 서비스 설정 정보 객체를 반환한다.
 * PlayRTCSettings객체에서 정의한 설정값이 SDK에 최우선으로 반영이 된다.
 * @see PlayRTCSettings.h
 * @return PlayRTCSettings
 */
- (PlayRTCSettings*)getSettings;

/**
 * Local Media Stream을 반환한다
 * @see PlayRTCMedia.h
 * @return id PlayRTCMedia
 */
- (id)getLocalMedia;

/**
 * Remote Media Stream을 반환한다
 * @param peerId NSString, PlayRTC 플랫폼 채널 서비스의 Peer 아이디
 * @see PlayRTCMedia.h
 * @return PlayRTCMedia
 */
- (id)getRemoteMedia:(NSString*)peerId;

/**
 * DataChannel Stream을 반환한다
 * @param peerId NSString, PlayRTC 플랫폼 채널 서비스의 Peer 아이디
 * @see PlayRTCData.h
 * @return PlayRTCData
 */
- (id)getData:(NSString*)peerId;

/**
 * 채널에 입장하여 할당 받은 User의 Peer 아이디를 반환한다.
 * @return NSString
 */
- (NSString*)getPeerId;

/**
 * 채널에 전달한 Application의 User 아이디를 반환한다.
 * @return NSString
 */
- (NSString*)getPeerUid;

/**
 * 채널 아이디를 반환한다.
 * @return NSString
 */
- (NSString*)getChannelId;

/**
 * PlayRTC 플랫폼 채널 서비스에 새로 채널을 생성한다.
 * 채널 생성 시 채널아이디와 서비스 설정 정보, 사용자 토큰을 전달 받아 채널에 입장한다.
 *
 * @param parameters NSDictionary, 생성하는 채널및 peer에 유지할 부가 데이터 항목을 전달, 데이터는 채널이 close 될때 까지 유지된다.
 * - channel NSDictionary, 채널에 대한 부가 정보
 *   - channelName NSString, 채널에 대한 NickName
 * - peer NSDictionary, peer(사용자)에 대한 부가 정보
 *   - userId NSString, User에 대한 ID로  User에 대한 ID로 application에서 사용하는 사용자 아이디
 *   - userName NSString, User에 대한 Nickname
*/
- (void)createChannel:(NSDictionary*)parameters;

/**
 * PlayRTC 플랫폼 채널 서비스에 생성 되어 있는 채널에 입장한다.
 * 채널아이디와 서비스 설정 정보, 사용자 토큰을 전달 받아 채널에 입장한다.
 *
 * @param channelId String, PlayRTC 플랫폼 채널 서비스의 채널 아이디
 * @param parameters NSDictionary, 사용자 관련 부가 정보를 전달할 수 있다.
 * - peer NSDictionary, peer(사용자)에 대한 부가 정보
 *   - userId NSString, User에 대한 ID로  User에 대한 ID로 application에서 사용하는 사용자 아이디
 *   - userName NSString, User에 대한 Nickname
 */
- (void)connectChannel:(NSString*)channelId parameters:(NSDictionary*)parameters;

/**
 * PlayRTC 플랫폼 채널에서 퇴장한다.<br>
 *
 * @param peerId NSString, 채널을 퇴장하는 PlayRTC 플랫폼 채널 서비스의 User 아이디
 */
- (void)disconnectChannel:(NSString*)peerId;

/**
 * PlayRTC 플랫폼 채널을 종료한다.
 */
- (void)deleteChannel;

/**
 * 상대방에게 User-Defined Command를  데이터 가공없이 그대로 전달한다.
 * @param peerId NSString, PlayRTC 플랫폼 채널 서비스의 User 아이디
 * @param data NSString, 데이터 문자열 데이터 형식은 개별 application에서 정의 한 형태
 */
- (void)userCommand:(NSString*)peerId data:(NSString*)data;

/**
 * ring 요청을 받은 경우 연결 수락 메세지를 상대에게 전달
 * @param peerId NSString, PlayRTC 플랫폼 채널 서비스의 User 아이디
 */
- (void)accept:(NSString*)peerId;

/**
 * ring 요청을 받은 경우 연결 거부 메세지를 상대에게 전달
 * @param peerId NSString, PlayRTC 플랫폼 채널 서비스의 User 아이디
 */
- (void)reject:(NSString*)peerId;

/**
 * PlayRTC 플랫폼 채널 서비스에 생성되어 있는 채널 목록을 조회한다.
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)getChannelList:(id<PlayRTCServiceHelperListener>)listener;

/**
 * PlayRTC 플랫폼 채널 서비스에 생성되어 있는 채널 정보를 조회한다.
 * @param channelId NSString, 채널의 아이디
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @see PlayRTCServiceHelperListener.h
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)getChannel:(NSString*)channelId listener:(id<PlayRTCServiceHelperListener>)listener;

/**
 * PlayRTC 채널서비스에 생성되어 있는 채널 정보를 채널 이름으로 조회한다.
 * @param channelName NSString, 채널 이름
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @see PlayRTCServiceHelperListener.h
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)searchChannelByName:(NSString*)channelName listener:(id<PlayRTCServiceHelperListener>)listener;

/**
 * PlayRTC 채널서비스에 생성되어 있는 채널 정보를 채널 아이디로 조회한다.
 * @param channelId NSString, 채널 아이디
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @see PlayRTCServiceHelperListener.h
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)searchChannelById:(NSString*)channelId listener:(id<PlayRTCServiceHelperListener>)listener;

/**
 * PlayRTC 플랫폼 채널 서비스에  입장한 User 정보 목록을 조회한다.
 * @param channelId NSString, 채널의 아이디
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @see PlayRTCServiceHelperListener.h
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)getPeerList:(NSString*)channelId listener:(id<PlayRTCServiceHelperListener>)listener;

/**
 * PlayRTC 플랫폼 채널 서비스에 입장한 특정 User 정보를 조회하기 위해서 요청하는 인터페이스
 * @param channelId NSString, 채널의 아이디
 * @param peerId NSString, 채널에 입장한 User의 아이디
 * @param listener PlayRTCServiceHelperListener, 응답을 받기 위한 리스너 인터페이스
 * @see PlayRTCServiceHelperListener.h
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)getPeer:(NSString*)channelId peerId:(NSString*)peerId listener:(id<PlayRTCServiceHelperListener>)listener;

/**
 * AVAudioSession 제어 기능을 활성화 시키는 인터페이스
 * @return BOOL, 서비스 실패 시 false
 */
- (BOOL)enableAudioSession;

/**
 * 음성을 출력하는 Speaker를 지정하는 인터페이스
 * enableAudioSession를 호출하여 AudioSession Manager를 활성화 시켜야 한다.
 * @param enable BOOL, TRUE 지정 시 외부 Speaker로 소리가 출력되고, FALSE 시 EAR-Speaker로 출력. 기본은 EAR-Speaker
 * @return BOOL, 서비스 호출 실패 시 false
 */
- (BOOL)setLoudspeakerEnable:(BOOL)enable;

/**
 * P2P연결 후 전/후면 카메라를 전환한다.
 */
- (void)switchCamera;

/**
 * P2P 상태 체크 리포트를 시작하는 인터페이스
 * @param interval long, 최소값 2000(2초) msec
 * @param reportObserver PlayRTCStatsReportObserver, 리포트 데이터를 전달 받기 위한 인터페이스
 * @return
 */
- (void)startStatsReport:(long)interval observer:(id<PlayRTCStatsReportObserver>)reportObserver;
/**
 * P2P 상태 체크 리포트를 중지하는 인터페이스
 */
- (void)stopStatsReport;
@end

#endif
