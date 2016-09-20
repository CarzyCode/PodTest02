//
//  PlayRTCStatReport.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 26..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCStatReport_h_
#define __PlayRTCStatReport_h_

#import <Foundation/Foundation.h>
#import "PlayRTCDefine.h"


@interface RatingValue : NSObject
-(int)getLevel;
-(float)getValue;
@end

@interface PlayRTCStatReport : NSObject
-(NSString*)getLocalCandidate;
-(NSString*)getRemoteCandidate;
-(int)getLocalFrameWidth;
-(int)getLocalFrameHeight;
-(int)getRemoteFrameWidth;
-(int)getRemoteFrameHeight;
-(int)getLocalFrameRate;
-(int)getRemoteFrameRate;
-(int)getAvailableSendBandwidth;
-(int)getAvailableReceiveBandwidth;
-(int)getRtt;
-(RatingValue*)getRttRating;
-(RatingValue*)getFractionRating;
-(RatingValue*)getLocalAudioFractionLost;
-(RatingValue*)getLocalVideoFractionLost;
-(RatingValue*)getRemoteAudioFractionLost;
-(RatingValue*)getRemoteVideoFractionLost;
@end
#endif
