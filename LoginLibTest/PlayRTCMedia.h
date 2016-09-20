//
//  PlayRTCMedia.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCMedia_h__
#define __PlayRTCMedia_h__

#import <Foundation/Foundation.h>
#import "PlayRTCVideoView.h"

/**
 * 미디어스트림 타입 정의
 */
typedef enum {
    LocalMedia, //로컬미디어스트림
    RemoteMedia // 상대방 P2P 미디어스트림
}MediaSourceType;

/**
 * PlayRTC SDK는 로컬 또는 상대방의 영상/음성 스트림을 획득 시 PlayRTCMedia 인터페이스를 구현한 객체를 생성한 후
 * onAddLocalStream/onAddRemoreStream 이벤트 인터페이스를 호출하여 PlayRTCMedia 인터페이스 를 전달한다.
 * PlayRTCMedia를 전달 받으면 영상 출력 뷰(PlayRTCVieoView)에 영상을 출력하도록 처리해야 한다.
 */
@interface PlayRTCMedia : NSObject

/**
 * Application에서 사용하는 사용자의 아이디를 반환.
 * @return NSString*
 */
-(NSString*)getUserId;
/**
 * 채널에서 부여받은 사용자의 아이디를 반환.
 * @return NSString
 */
-(NSString*)getUserPid;

/**
 * Video 스트림을 가지고 있는 지 여부를반 반환
 * @return BOOL
 */
-(BOOL)hasVideoStream;

/**
 * Audio 스트림을 가지고 있는 지 여부를반 반환
 * @return BOOL
 */
-(BOOL)hasAudioStream;

/**
 * Enum MediaSourceType을 반환.
 * @return MediaSourceType
 */
-(MediaSourceType)getSourceType;

/**
 * 전달받은  PlayRTCVideoView의 Renderer를 반환.
 * @return PlayRTCVideoRenderer
 */
-(PlayRTCVideoRenderer*)getVideoRenderer;
/**
 * 영상 스트림을 출력하기 위해 Renderer가 구현되어 있는  PlayRTCVideoView의 Renderer를 전달받는다.
 * @param renderer PlayRTCVideoRenderer
 */
-(void)setVideoRenderer:(PlayRTCVideoRenderer*)renderer;

/**
 * Video 스트림을 Mute 합니다. 로컬스트림을 Mute하는 경우 상대방에게 영상이 출력되지 않는다.
 * @param mute BOOL, true이면 mute 설정, false이면 mute 해제
 * @return BOOL
 */
-(BOOL)setVideoMute:(BOOL)mute;

/**
 * Audio 스트림을 Mute 합니다. 로컬스트림을 Mute하는 경우 상대방에게 소리가 출력되지 않는다.
 * @param mute BOOL, true이면 mute 설정, false이면 mute 해제
 * @return BOOL
 */
-(BOOL)setAudioMute:(BOOL)mute;

@end

#endif
