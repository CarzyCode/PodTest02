//
//  PlayRTCDataSendObserver.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCDataSendObserver_h__
#define __PlayRTCDataSendObserver_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"

@class PlayRTCData;
/**
 * 데이터 전송 결과를 전달 받아 처리하기 위한 이벤트 인터페이스
 */
@protocol PlayRTCDataSendObserver <NSObject>

/**
 * 데이터 전송에 진행 상태를 전달하는 인터페이스.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param dataId uint64_t, PlayRTC Data-Stream 데이터의 고유 아이디
 * @param size uint64_t, PlayRTC Data-Stream 데이터의 전체 사이즈
 * @param send uint64_t, PlayRTC Data-Stream 전송 데이터의 누적 사이즈
 * @param index int PlayRTC Data-Stream 데이터의 분할 Chunk index
 * @param count int PlayRTC Data-Stream 데이터의 분할 Chunk 수
 */
-(void)onSending:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid dataId:(uint64_t)dataId size:(uint64_t)size send:(uint64_t)send index:(int)index count:(int)count;

/**
 * 데이터 전송에 성공했을 경우 호출되는 인터페이스.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param dataId uint64_t, PlayRTC Data-Stream 데이터의 고유 아이디
 * @param size uint64_t, PlayRTC Data-Stream 데이터의 전체 사이즈
 */
-(void)onSendSuccess:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid dataId:(uint64_t)dataId size:(uint64_t)size;

/**
 * 데이터 전송 시 오류발생 시 이벤트를 전달하는 인터페이스.
 * @param obj PlayRTCData
 * @param peerId NSString,  PlayRTC 플랫폼 채널 서비스의 User 아이디.
 * @param peerUid NSString, 사용자의 application에서 사용하는 아이디로 채널연결 시 입력한값, 없으면 “”
 * @param dataId uint64_t, PlayRTC Data-Stream 데이터의 고유 아이디
 * @param code PlayRTCDataCode, PlayRTCData 객체의 상태
 * @param desc NSString, Description
 */
-(void)onSendError:(PlayRTCData*)obj peerId:(NSString*)peerId peerUid:(NSString*)peerUid dataId:(uint64_t)dataId code:(PlayRTCDataCode)code desc:(NSString*)desc;

@end

#endif
