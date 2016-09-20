//
//  PlayRTCDataHeader.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCDataHeader_h__
#define __PlayRTCDataHeader_h__

#import <Foundation/Foundation.h>

/**
 * PlayRTCData 데이터 정보를 담는 데이터 Class
 *
 *  - index : int, 데이터 패킷 분할 전송 index
 *  - size : uint64_t, 데이터 전체 크기
 *  - id : uint64_t, 전송하는 데이터의 고유 아이디
 *  - dataType : int, text 0, binary 1
 *  - fileName : NSString, 파일 전송일 경우 파일 명
 *  - mimeType : NSString, 파일 전송일 경우 파일의 Mime Type
 *
 */
@interface PlayRTCDataHeader : NSObject
/**
 * PlayRTC Data-Stream 데이터의 분할 Chunk index를 반환한다.
 * @return int
 */
-(int)getIndex;
/**
 * PlayRTC Data-Stream 데이터의 분할 Chunk index를 지정한다.
 * @return int
 */
-(void)setIndex:(int)idx;

/**
 * PlayRTC Data-Stream 데이터의 분할 Chunk 수를 반환한다.
 * @return int
 */
-(int)getCount;
/**
 * PlayRTC Data-Stream 데이터의 고유 아이디를 반환한다.
 * @return uint64_t
 */
-(uint64_t)getId;
/**
 * PlayRTC Data-Stream 데이터의 전체 사이즈를 반환한다.
 * @return uint64_t
 */
-(uint64_t)getSize;
/**
 * PlayRTC Data-Stream 데이터 유형을 반환한다.
 * int, text 0, binary 1
 * @return int
 */
-(int)getType;
/**
 * PlayRTC Data-Stream 데이터 유형이 바이너리인지 여부를 반환한다.
 * @return BOOL
 */
-(BOOL)isBinary;
/**
 * 파일 전송일 경우 파일 명을 반환한다.
 * @return NSString
 */
-(NSString*)getFileName;
/**
 * 파일 전송일 경우 파일의 Mime Type을 반환한다.
 * @return NSString
 */
-(NSString*)getMimeType;
@end

#endif
