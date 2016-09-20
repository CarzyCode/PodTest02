//
//  PlayRTCReport.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 26..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCReport_h_
#define __PlayRTCReport_h_

#import <Foundation/Foundation.h>

//#define TEST_REPORT


@interface PlayRTCReport : NSObject

+(PlayRTCReport*)getInstance;

-(long long)gerCurrentTimeStamp;
-(void)reset;
-(void)startStatTimer:(id)peer;
-(void)stopStatTimer;

-(void)setTesterName:(NSString*)name;
-(void)setTesterLocation:(NSString*)location;
-(void)setChannelName:(NSString*)name;
-(void)setChannelCount:(int)count;
-(void)setTestStartTime;
-(void)setTestEndTime;
-(void)setCallEndTime;
-(NSString*)getTestType;
-(void)setTestType:(NSString*)type;
-(NSString*)getCarrierName;
-(void)setCarrierName:(NSString*)name;
-(NSString*)getTestSubType;
-(void)setTestSubType:(NSString*)type;
-(NSString*)getChannelId;
-(void)setChannelId:(NSString*)chlId;
-(NSString*)getLocalTokenId;
-(void)setLocalTokenId:(NSString*)token;
-(NSString*)getPeerTokenId;
-(void)setPeerTokenId:(NSString*)token;
-(void)setCallType:(NSString*)type;
-(void)setLocalCandidateType:(NSString*)type;
-(void)setRemoteCandidateType:(NSString*)type;
-(void)setDevice:(NSString*)name;
-(void)setOsVersion:(NSString*)ver;
-(void)setBrowserVersion:(NSString*)ver;
-(void)setNetworkType:(NSString*)type;
-(void)setResultCode:(NSString*)code;
-(long long)getChannelConnectTime;
-(void)setChannelConnectTime;
-(long long)getCallSetupStartTime;
-(void)setCallSetupStartTime;
-(void)setCallSetupEndTime;
-(long long)getCallDropTime;
-(void)setCallDropTime;
-(void)setCallDropTime:(long long)time;
-(BOOL)isCallDrop;
-(void)setCallDrop:(BOOL)drop;

-(long long)getFileSendTime;
-(void)setFileSendStartTime;
-(void)setFileSendEndTime;
-(long long)getFileSendEndTime;
-(NSString*)getFileSendName;
-(void)setFileSendName:(NSString*)name;
-(long)getFileSendSize;
-(void)setFileSendSize:(long)size;
-(int)getFileSendTotal;
-(void)setFileSendTotal:(int)total;
-(int)getFileSendCount;
-(void)setFileSendCount:(int)count;
-(NSString*)getFileRecvName;
-(void)setFileRecvName:(NSString*)name;
-(long)getFileRecvSize;
-(void)setFileRecvSize:(long)size;
-(void)setFileRecvStartTime;
-(long long)getFileRecvStartTime;
-(void)setFileRecvEndTime;
-(long long)getFileRecvEndTime;
-(long long)getFileRecvTime;
-(int)getFileRecvTotal;
-(void)setFileRecvTotal:(int)total;
-(int)getFileRecvCount;
-(void)setFileRecvCount:(int)count;
-(void)setFrameSendWidthSize:(NSString*)width;
-(void)setFrameSendHeightSize:(NSString*)height;
-(void)setFrameRecvWidthSize:(NSString*)width;
-(void)setFrameRecvHeightSize:(NSString*)height;
-(void)setFrameSendRate:(NSString*)rate;
-(void)setFrameRecvRate:(NSString*)rate;
-(void)setCpuMemory:(NSString*)cpu memory:(NSString*)mem;
-(NSString*)getReportString;
@end
#endif
