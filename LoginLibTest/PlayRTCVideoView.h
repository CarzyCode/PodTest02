//
//  PlayRTCVideoView.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCVideoView_h__
#define __PlayRTCVideoView_h__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Frame Size 변경 시 알려주기 위한 인터페이스
 */
@protocol VideoFrameObserver <NSObject>
@required
-(void)onFrameSize:(CGSize)size;
@end


@class PlayRTCVideoView;
@class PlayRTCI420Frame;
@interface PlayRTCVideoRenderer : NSObject
{
    __weak PlayRTCVideoView* videoView;
}
@property(nonatomic, weak) PlayRTCVideoView* videoView;

// The size of the frame.
- (void)setSize:(CGSize)size;

// The frame to be displayed.
- (void)renderFrame:(PlayRTCI420Frame*)frame;

@end

@interface PlayRTCVideoView : UIView {
    __weak id<VideoFrameObserver> observer;
}
@property(nonatomic, weak)id<VideoFrameObserver> observer;
- (instancetype)initWithFrame:(CGRect)frame;
- (PlayRTCVideoRenderer*)getVideoRenderer;

@end

#endif
