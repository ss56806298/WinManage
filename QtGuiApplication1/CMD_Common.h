#pragma once
#ifndef CMD_COMMON_HEAD_FILE
#define CMD_COMMON_HEAD_FILE

#include "CommonHeader.h"

//TCP信息
struct TCP_Info
{
	BYTE							cbDataKind;							//数据类型
	BYTE							cbCheckCode;						//校验字段
	WORD							wPacketSize;						//数据大小
};

//TCP数字命令
struct TCP_Command
{
	WORD							wMainCmdID;							//主命令码
	WORD							wSubCmdID;							//子命令码
};

//TCP协议头
struct TCP_Head
{
	TCP_Info						TCPInfo;							//基础结构
	TCP_Command						CommandInfo;						//命令信息
};

//协议头
struct NTY_TCPNetworkReadEvent
{
	WORD							wDataSize;							//数据大小
	DWORD							dwSocketID;							//网络标识
	TCP_Command						Command;							//命令信息
};

#endif