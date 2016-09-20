//
//  PlayRTCStatsReportObserver.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCStatsReportObserver_h__
#define __PlayRTCStatsReportObserver_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"
#import "PlayRTCStatReport.h"

/**
 * PlayRTC 객체의 이벤트를 전달받기 위한 리스너 인터페이스로 PlayRTC 에 PlayRTCObserver 인터페이스를 구현한 구현 개체를 등록 해야한다.
 */
@protocol PlayRTCStatsReportObserver <NSObject>
@required
/**
 * PlayRTC 개체의 상태정보를 전달하기 위해 onStatsReport를 호출
 * @param report PlayRTCStatsReport, 상태정보 객체  인터페이스
 */
-(void)onStatsReport:(PlayRTCStatReport*)report;

@end

#endif
