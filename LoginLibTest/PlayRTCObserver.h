//
//  PlayRTCObserver.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCObserver_h__
#define __PlayRTCObserver_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"
#import "PlayRTC.h"
#import "PlayRTCData.h"
#import "PlayRTCMedia.h"

/**
 * PlayRTC 객체의 이벤트를 전달받기 위한 리스너 인터페이스로 PlayRTC 에 PlayRTCObserver 인터페이스를 구현한 구현 개체를 등록 해야한다.
 */
@protocol PlayRTCObserver <NSObject>
@required
/**
 * PlayRTC 개체의 createChannel 또는 connectChannel 메소드를 호출하여 PlayRTC 플랫폼의 서비스 채널에 
 * 입장하게 되면 PlayRTC SDK는 채널 관련 정보를 받으며, 채널 아이디를 전달 하기 위해 onConnectChannel을 호출
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param channelId NSString, PlayRTC 플랫폼 서비스의 채널아이디.
 * @param reason NSString, createChannel을 호출하여 채널에 입장한 경우 “create”, connectChannel을 호출한 경우 “connect”
 */
-(void)onConnectChannel:(PlayRTC*)obj channelId:(NSString*)channelId reason:(NSString*)reason;

/**
 * 상호 연결확인 과정(ring)을 설정하였다면 채널에 먼저 입장한 SDK는 나중에 채널에 입장한 사용자로부터 연결 의사를 묻는 요청을 수신하게되고 onRing을 호출.
 * onRing이 호출 되면 사용자로부터 수락 여부를 입력받아 상대방에게 전달하도록 해야 한다.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 */
-(void)onRing:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid;

/**
 * PlayRTCSetting 에서 상호연결 확인과정(ring)을 설정하였다면 채널에 나중에 입장한 SDK는 경우먼저 입장한 사용자로부터 연결수락의사를 물어보고 상대로부터승인을받으면 onAccept를 호출
 * SDK는내부적으로 시그널서버에 접속하여 시그널링을 진행한다.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 */
-(void)onAccept:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid;

/**
 * Application 개발자가 정의한 사용자 정의 데이터를 채널 서비스를 통해 전달 받으면 PlayRTC SDK는 수신 전문 데이터의 가공 처리 없이 onUserCommand 를 호출하여 전달.
 * 개발자가 이 호출을 받으면 절적한 대응을 구현하여야 한다.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 */
-(void)onReject:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid;

/**
 * Application 개발자가 정의한 사용자 정의 데이터를 채널 서비스를 통해 전달 받으면 PlayRTC SDK는 수신 전문 데이터의 가공 처리 없이 onUserCommand 를 호출하여 전달.
 * 개발자는 onUserCommand 호출 시 데이터에 맞는 대응을 구현해야한다
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param data NSString, 상대방이 전송한 데이터 문자열
 */
-(void)onUserCommand:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid data:(NSString*)data;


/**
 * PlayRTCMedia는 PlayRTC SDK 설정에서 영상/음성 스트리밍을 사용하도록 설정하면, 로컬 단말의 미디어 스트림을 생성하고 PlayRTCMedia를  onAddLocalStream이벤트를 통해 전달.
 * onAddLocalStream 를 통해 PlayRTCMedia를 전달 받으면PlayRTCVideView 객체의 영상 스트림 렌더러를 전달해야 한다.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param media PlayRTCMedia,  미디어스트림처리를위한  PlayRTCMedoa 인터페이스.
 */
-(void)onAddLocalStream:(PlayRTC*)obj media:(PlayRTCMedia*)media;

/**
 * PlayRTC SDK가 P2P연결이 수립되어 상대방의 미디어 스트림을 수신하면 PlayRTCMedia 를 사용자에게 전달하기 위해  onAddRemoteStream 인를 호출.
 * onAddRemoteStream 를 통해 PlayRTCMedia를 전달 받으면PlayRTCVideView 객체의 영상 스트림 렌더러를 전달해야 한다.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param media PlayRTCMedia,  미디어스트림처리를위한  PlayRTCMedoa 인터페이스.
 */
-(void)onAddRemoteStream:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid media:(PlayRTCMedia*)media;

/**
 *  PlayRTCData는 PlayRTC SDK 설정에서데이터통신을 사용하도록 설정하면 상대방과의 P2P 데이터 채널 연결이 수립될때생성되어 onDataStream 이벤트를통해전달
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param data PlayRTCData, P2P 데이터 전송 처리를 위한 PlayRTCData 인터페이스.
 */
-(void)onAddDataStream:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid data:(PlayRTCData*)data;

/**
 * 채널 서버로부터 채널퇴장 Command를 받거나 채널 종료 시 호출 되며 SDK는 채널에서 연결을 맺은 모든 P2P 연결을종료하고 P2P 연결 객체를 모두해제한후 최종적으로 채널서버와의 연결 개체를 해제한다. 
 * onDisconnectChannel은 PlayRTC가 채널 퇴장을 알리기 위해 호출하는 이벤트.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param reason NSString,  disconnectChannel을 호출하여 채널에서 퇴장한 경우 “disconnect”, deleteChannel을 호출한 경우 “delete”
 */
-(void)onDisconnectChannel:(PlayRTC*)obj reason:(NSString*)reason;

/**
 * PlayRTC가 상대방의 채널퇴장을 알리기 위해 호출되는 이벤트
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 */
-(void)onOtherDisconnectChannel:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid;

/**
 * PlayRTC 에서발생하는오류를전달받는이벤트인터페이스.
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param status PlayRTCStatus, PlayRTC 상태 정의 코드. PlayRTCStatus 참고
 * @param code PlayRTCCode, PlayRTC 오류 정의 코드. PlayRTCCode 항목 참고
 * @param desc NSString, Description
 */
-(void)onError:(PlayRTC*)obj status:(PlayRTCStatus)status code:(PlayRTCCode)code desc:(NSString*)desc;

/**
 * PlayRTC의 상태 변경사항을 전달받는 이벤트 인터페이스.
 * PlayRTC상태 정의는 enum PlayRTCStatus 항목 참고
 * @param obj PlayRTC, PlayRTC 인터페이스
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param status PlayRTCStatus, PlayRTC 상태 정의 코드. PlayRTCStatus 참고
 * @param desc NSString, Description
 */
-(void)onStateChange:(PlayRTC*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid status:(PlayRTCStatus)status desc:(NSString*)desc;

@end

#endif
