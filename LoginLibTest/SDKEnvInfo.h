//
//  SDKEnvInfo.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 26..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __SDKEnvInfo_h_
#define __SDKEnvInfo_h_

#import <Foundation/Foundation.h>

@interface SDKEnvInfo : NSObject
{
    NSString* platformType;     /* 플랫폼 유형, "ios" */
    NSString* deviceName;       /* 단말기정보" */
    NSString* browserType;      /* 브라우저 유형, 사용 안함 */
    NSString* browserVersion;   /* 브라우버 버전, 사용 안함 */
    NSString* networkType;      /* 연결된 네트워크 유형 */
    NSString* sdkType;          /* SDK 유형 */
    NSString* sdkVersion;       /* SDK의 버전 "1.0.0" */
}
@property (strong, nonatomic) NSString* platformType;
@property (strong, nonatomic) NSString* deviceName;
@property (strong, nonatomic) NSString* browserType;
@property (strong, nonatomic) NSString* browserVersion;
@property (strong, nonatomic) NSString* networkType;
@property (strong, nonatomic) NSString* sdkType;
@property (strong, nonatomic) NSString* sdkVersion;
-(id)init;
@end
#endif
