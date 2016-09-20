//
//  PlayRTCFactory.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 7. 17..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCFactory_h__
#define __PlayRTCFactory_h__

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"
#import "PlayRTCObserver.h"
#import "PlayRTCSettings.h"
#import "PlayRTCConfig.h"
#import "PlayRTC.h"

@interface PlayRTCFactory : NSObject

/**
 * PlayRTCConfig 인터페이스를 구현한 PlayRTC Implement를 반환한다
 * @return PlayRTCConfig
 */
+ (PlayRTCConfig*)createConfig;

/**
 * PlayRTC 인터페이스를 구현한 PlayRTC Implement를 반환한다
 * @param settings PlayRTCSettings, PlayRTC Configureation
 * @param observer PlayRTCObserver, PlayRTC Event 리스너
 * @return PlayRTC
 */
+ (PlayRTC*)newInstance:(PlayRTCSettings*)settings observer:(id<PlayRTCObserver>)observer;

/**
 * PlayRTC 인터페이스를 구현한 PlayRTC Implement를 반환한다
 * @param config PlayRTCConfig, PlayRTC Configureation
 * @param observer PlayRTCObserver, PlayRTC Event 리스너
 * @return PlayRTC
 */
+ (PlayRTC*)createPlayRTC:(PlayRTCConfig*)config observer:(id<PlayRTCObserver>)observer;
@end

#endif
