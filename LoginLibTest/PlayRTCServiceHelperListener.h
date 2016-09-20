//
//  PlayRTCServiceHelperListener.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//
#ifndef __PlayRTCServiceHelperListener_h_
#define __PlayRTCServiceHelperListener_h_

#import <Foundation/Foundation.h>

/**
 *  PlayRTC Service Helper의 응답  결과를 받기 위한 Interface를 정의한 리스너 Class<br>
 *  IPlayRTCServiceAdapter의 구현 객체 인터페이스 호출 시 IPlayRTCServiceHelperListener 구현 객체를 전달하여 응답  결과를 수신한다.
*/
@protocol PlayRTCServiceHelperListener <NSObject>
@required

/**
 * PlayRTCServiceHelperListener 구현 객체의 서비스 응답을 전달하기 위한 인터페이스 <br>
 * @param code int, http status code
 * @param statusMsg NSString, http status message
 * @param returnParam id, 요청 시 전달 한 Object을 다시 되돌려 준다.
 * @param oData NSDictionary, 서비스 응답 데이터
 */
- (void)onServiceHelperResponse:(int)code statusMsg:(NSString*)statusMsg returnParam:(id)returnParam data:(NSDictionary*)oData;

/**
 * PlayRTCServiceHelperListener 구현 객체의 서비스 요청 실패를 전달하기 위한 인터페이스 <br>
 * @param code int, 요청 실패 코드, http status code
 * @param statusMsg NSString, http status message
 * @param returnParam id, 요청 시 전달 한 Object을 다시 되돌려 준다.
 */
- (void)onServiceHelperFail:(int)code statusMsg:(NSString*)statusMsg returnParam:(id)returnParam;

@end

#endif
