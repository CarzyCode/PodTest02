//
//  PlayRTCDefine.h
//  PlayRTC
//
//  Created by ds3grk on 2014. 8. 1..
//  Copyright (c) 2014년 playrtc. All rights reserved.
//

#ifndef __PlayRTCDefine_h_
#define __PlayRTCDefine_h_

#ifndef LOG_VERBOSE
#define LOG_VERBOSE 1
#define LOG_TRACE   2
#define LOG_WARN    3
#define LOG_ERROR   4
#endif

#ifndef BYTE
#define BYTE UInt8
#endif

#define DC_DATA_TYPE_TEXT 			0
#define DC_DATA_TYPE_BINARY         1

#ifndef NETWORK_TYPE_NONE
#define NETWORK_TYPE_NONE   1
#define NETWORK_TYPE_WIFI   1
#define NETWORK_TYPE_MOBILE 2
#define NETWORK_TYPE_2G     21
#define NETWORK_TYPE_3G     22
#define NETWORK_TYPE_4G     23
#endif

typedef enum {
    CameraTypeFront,
    CameraTypeBack
}CameraType;




/**
 * PlayRTC SDK 상태값 정의 
 * PlayRTCObserver의 onStateChange/onError 인터페이스로 전달
 */
typedef enum  {
    PlayRTCStatusNone = 0,
    PlayRTCStatusInitialize = (1<<1),                 /* 라이브러리 초기화 작업 단계  */
    PlayRTCStatusChannelStart = (1<<2),               /* 채채널 연결 준비(open) 단계 */
    PlayRTCStatusChannelConnect = (1<<3),             /* 채널 연결(connect) 단계 */
    PlayRTCStatusLocalMedia = (1<<4),                 /* Local Media 생성  */
    PlayRTCStatusChanneling = (1<<5),				  /* 채널 입장, Channeling */
    PlayRTCStatusRing = (1<<6),                       /* Are you ready 단계, 연결 수락 여부를 묻거나 받은 상태 offer/answer 공통  */
    PlayRTCStatusPeerCreation = (1<<7),               /* Peer 객체 Creation  */
    PlayRTCStatusSignaling = (1<<8),                  /* 시그널링 시그널 데이터 교환 */
    PlayRTCStatusPeerConnecting = (1<<9),             /* Peer 연결 Checking 상태  */
    PlayRTCStatusPeerDataChannel = (1<<10),           /* Peer DataChannel 연결 */
    PlayRTCStatusPeerMedia = (1<<11),                 /* Peer Media 생성 */
    PlayRTCStatusPeerSuccess = (1<<12),               /* Peer 연결 성공 */
    PlayRTCStatusPeerConnected = (1<<13),             /* Peer 연결 수립 상태 */
    PlayRTCStatusPeerDisconnected = (1<<14),       	  /* Peer 연결 해제 */
    PlayRTCStatusPeerClosed = (1<<15),                /* Peer 종료 */
    PlayRTCStatusUserCommand = (1<<16),               /* 사용자 정의 Command & Data */
    PlayRTCStatusChannelDisconnected = (1<<17),       /* Channel 서버 연결 종료 */
    PlayRTCStatusClosed = (1<<18),                    /* PlayRTC 종료 */
    PlayRTCStatusNetworkConnected = (1<<19),          /* Network Connectivity Status connected */
    PlayRTCStatusNetworkDisconnected = (1<<20)        /* Network Connectivity Status disconnected */
}PlayRTCStatus;

/**
 * PlayRTC SDK 오류코드값 정의
 * PlayRTCObserver의 onError 인터페이스로 전달
 */
typedef enum  {
    PlayRTCCodeNone,
    PlayRTCCodeMissingParameter,            /* 필수 Parameter가 없음 */
    PlayRTCCodeInvalidParameter,            /* 잘못된 Parameter */
    PlayRTCCodeVersionUnsupported,          /* SDK 버전 지원하지 않음 */
    PlayRTCCodeNotInitialize,               /* 라이브러리 초기화 실패 */
    PlayRTCCodeMediaUnsupported,			/* LocalMedia 획득 실패 */
    PlayRTCCodeConnectionFail,				/* 채널/시그널 서버 연결 실패 */
    PlayRTCCodeDisconnectFail,				/* 채널 퇴장 실패 */
    PlayRTCCodeSendRequestFail,             /* 데이터 전송 실패 */
    PlayRTCCodeMessageSyntax,               /* 데이터 문법 오류 */
    PlayRTCCodeProjectIdInvalid,			/* 프로젝트 아이디 오류 */
    PlayRTCCodeTokenInvalid,				/* 사용자 토큰 오류 */
    PlayRTCCodeTokenExpired,				/* 사용자 토큰 기간 만료 */
    PlayRTCCodeChannelIdInvalid,			/* 채널링 채널아이디 오류 */
    PlayRTCCodeServiceError,				/* 채널링/시그널링 서비스 오류 */
    PlayRTCCodePeerMaxCount,				/* Peer 접속 인원 허용 초과 */
    PlayRTCCodePeerIdInvalid,               /* Peer 아이디 오류 */
    PlayRTCCodePeerIdAlready,               /* Peer 아이디 중복 사용 오류 */
    PlayRTCCodePeerInternalError,           /* Peer 내부 오류 */
    PlayRTCCodePeerConnectionFail,          /* Peer 연결 실패 */
    PlayRTCCodeSdpCreationFail,             /* Peer SDP 생성 오류 */
    PlayRTCCodeSdpRegistrationFail,         /* Peer SDP 등록 오류 */
    PlayRTCCodeDataChannelCreationFail,		/* DataChannel 생성 오류 */
    PlayRTCCodeNotConnect,                  /* PlayRTC 채널 연결 객체가 없거나 채널에  연결되어 있지않음 */
    PlayRTCCodeConnectAlready               /* 이미 채널에 입장해 있음 */
}PlayRTCCode ;

/**
 * PlayRTCData 데이터 Type 정의
 */
typedef enum {
    PlayRTCDataTypeText,   /* Text 데이터 */
    PlayRTCDataTypeBinary  /* Binary 데이터 */
}PlayRTCDataType;

/**
 * PlayRTCData 상태값 정의
 * PlayRTCDataObserver의 onStateChange/onError 인터페이스로 전달
 */
typedef enum {
    PlayRTCDataStatusNone,
    PlayRTCDataStatusConnecting,
    PlayRTCDataStatusOpen,
    PlayRTCDataStatusClosing,
    PlayRTCDataStatusClosed
}PlayRTCDataStatus;

/**
 * PlayRTCData 오류코드값 정의
 * PlayRTCDataObserver의 onError 인터페이스로 전달
 */
typedef enum {
    PlayRTCDataCodeNone,
    PlayRTCDataCodeNotOpend,
    PlayRTCDataCodeSendBusy,
    PlayRTCDataCodeSendFail,
    PlayRTCDataCodeFileIO,
    PlayRTCDataCodeParseFail
}PlayRTCDataCode;


typedef enum  {
    WIRED_HEADSET,
    SPEAKER_PHONE,
    EAR_SPEAKER,
    BLUETOOTH
} PlayRTCAudioDevice;

#endif
