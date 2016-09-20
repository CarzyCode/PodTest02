//
//  PlayRTCDataObserver.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCDataObserver_h__
#define __PlayRTCDataObserver_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"
#import "PlayRTCDataHeader.h"
#import "PlayRTCData.h"

/**
 * PlayRTCData 객체를  통해서 P2P 데이터 통신 시 발생하는 주요 이벤트를 전달 받아 처리하기 위한 이벤트 인터페이스
 */
@protocol PlayRTCDataObserver <NSObject>
@required

/*
 * 상대방이 전송한 데이터를 처음 수신할 경우 데이터의 헤더정보를 읽어 알려준다.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력
 * @param header : PlayRTCDataHeader, 데이터 정보
 *  - index : int, 데이터 패킷 분할 전송 index
 *  - count : int, 데이터 패킷 분할 count
 *  - size : uint64_t, 데이터 전체 크기
 *  - id : uint64_t, 전송하는 데이터의 고유 아이디
 *  - dataType : int, text 0, binary 1
 *  - fileName : NSString, 파일 전송일 경우 파일 명
 *  - mimeType : NSString, 파일 전송일 경우 파일의 Mime Type
 */
-(void)onDataReady:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid header:(PlayRTCDataHeader*)header;

/**
 * 데이터 수신 진행 상태를 전달하는 인터페이스.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력
 * @param header : PlayRTCDataHeader, 데이터 정보
 *  - index : int, 데이터 패킷 분할 전송 index
 *  - count : int, 데이터 패킷 분할 count
 *  - size : uint64_t, 데이터 전체 크기
 *  - id : uint64_t, 전송하는 데이터의 고유 아이디
 *  - dataType : int, text 0, binary 1
 *  - fileName : NSString, 파일 전송일 경우 파일 명
 *  - mimeType : NSString, 파일 전송일 경우 파일의 Mime Type
 * @param recvSize uint64_t, 수신받은 데이터의 누적 크기
 * @param data NSData, PlayRTC Data-Stream 데이터
 */
-(void)onProgress:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid header:(PlayRTCDataHeader*)header recvSize:(uint64_t)recvSize data:(NSData*)data;

/*
 * 데이터 수신 종료
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력
 * @param header : PlayRTCDataHeader, 데이터 정보
 *  - index : int, 데이터 패킷 분할 전송 index
 *  - count : int, 데이터 패킷 분할 count
 *  - size : uint64_t, 데이터 전체 크기
 *  - id : uint64_t, 전송하는 데이터의 고유 아이디
 *  - dataType : int, text 0, binary 1
 *  - fileName : NSString, 파일 전송일 경우 파일 명
 *  - mimeType : NSString, 파일 전송일 경우 파일의 Mime Type
 */
-(void)onFinishLoading:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid header:(PlayRTCDataHeader*)header;

/*
 * PlayRTCData 오류 발생 시
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력
 * @param dataId uint64_t, PlayRTC Data-Stream 데이터의 고유 아이디
 * @param code PlayRTCDataCode, PlayRTCData 객체의 상태
 * @param desc NSString, Description
 */
-(void)onError:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid dataId:(uint64_t)dataId code:(PlayRTCDataCode)code desc:(NSString*)desc;

/*
 * PlayRTCData의 주요 상태를 전달 받는다.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력
 * @param dataId uint64_t, PlayRTC Data-Stream 데이터의 고유 아이디
 * @param state PlayRTCDataStatus, 상태 정의
 */
-(void)onStateChange:(PlayRTCData*)obj peerId:(NSString*)peerId  peerUid:(NSString*)peerUid state:(PlayRTCDataStatus)state;
@end

#endif
