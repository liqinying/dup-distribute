//
// Created by think on 11/4/22.
//

typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
//typedef signed __int64      INT64, *PINT64;
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned int        UINT32, *PUINT32;
//typedef unsigned __int64    UINT64, *PUINT64;
typedef float               FLOAT;
typedef float REAL32;
typedef double REAL64;

#define SEACOMMHEADER       0x66666666

#define BDCOMMHEADER        0xEB

#define PLAYBACKHEADER      0x88888888
#define PLAYBACK_START      1
#define PLAYBACK_END        2

typedef struct SeaCommunication
{
    UINT32 PacketHead;
    UINT32 PayloadSize;
    UINT16 ChunkNum;
    UINT16 ChunkID;
    UINT32 DataTime;
    FLOAT Longitude;
    FLOAT Latitude;
    UINT16 SystemID;
    UINT16 DataType;
}SeaCommunication;

typedef struct BDCommunication
{
    UINT8 PacketHead;
    UINT16 SystemID;
    UINT16 DataType;
}BDCommunication;

typedef struct replayProtocol
{
    UINT32 PacketHead;
    UINT8  CommandType;
    UINT32 StartTime;       // 历史数据的起始时间，精度为秒，返回从1970年1月1日(UTC)开始所经过的秒数
    UINT32 EndTime;         // 历史数据的结束时间，精度为秒，返回从1970年1月1日(UTC)开始所经过的秒数
    UINT8  Speed;           // 倍速，最小5倍速，最大60倍速
}ReplayProtocol;
