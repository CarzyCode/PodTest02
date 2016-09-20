//
//  PlayRTCData.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCData_h__
#define __PlayRTCData_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"

@protocol PlayRTCDataObserver;
@protocol PlayRTCDataSendObserver;

/**
 * P2P 데이터 통신을 제공하기 위한 인터페이스 Class
 * PlayRTC SDK에서 PlayRTCData 인터페이스 구현 개체를 생성하여 PlayRTCObserver의
 * onAddDataStream를 통해 전달.
 * PlayRTCData를 전달받으면 데이터 수신과 상태 및 오류 정보를 전달 받기 위해 PlayRTCDataObserver
 * 인터페이스 를 구현 한 개체를 등록해야 한다.
 */
@interface PlayRTCData : NSObject

/**
 * PlayRTCData 객체의 상태 및 오류  정보, 데이터 수신 상태를 전달 받기 위한 PlayRTCDataObserver 인터페이스를 구현한 개체를 PlayRTCData에 등록
 * @param listener id<PlayRTCDataObserver>
 */
-(void)setEventObserver:(id<PlayRTCDataObserver>)listener;

/**
 * PlayRTCData 객체의 상태를 반환
 * @return PlayRTCDataStatus
 * PlayRTCDataStatus
 *      PlayRTCDataStatusNone,
 *      PlayRTCDataStatusConnecting,
 *      PlayRTCDataStatusOpen,
 *      PlayRTCDataStatusCodeNone,
 *      PlayRTCDataStatusClosing,
 *      PlayRTCDataStatusClosed
 */
-(PlayRTCDataStatus)getStatus;

/**
 * 데이터 통신 채널을 통해 텍스트데이터를 전송
 * @param text NSString
 * @param observer id<PlayRTCDataSendObserver>
 * @return uint64_t 전송 데이터 스트림 아이디
 */
-(uint64_t)sendText:(NSString*)text observer:(id<PlayRTCDataSendObserver>)observer;

/**
 * 데이터 통신 채널을 통해 Binary 데이터를 전송
 * @param data NSData
 * @param mimeType NSString
 * @param observer id<PlayRTCDataSendObserver>
 * @return uint64_t 전송 데이터 스트림 아이디
 */
-(uint64_t)sendByte:(NSData*)data mimeType:(NSString*)mimeType observer:(id<PlayRTCDataSendObserver>)observer;

/**
 * 데이터 통신 채널을 통해 파일을 전송
 * @param filePath NSString
 * @param observer id<PlayRTCDataSendObserver>
 * @return uint64_t 전송 데이터 스트림 아이디
 */
-(uint64_t)sendFileData:(NSString*)filePath observer:(id<PlayRTCDataSendObserver>)observer;
@end

#endif
