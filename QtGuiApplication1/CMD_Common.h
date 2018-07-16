#pragma once
#ifndef CMD_COMMON_HEAD_FILE
#define CMD_COMMON_HEAD_FILE

#include "CommonHeader.h"

//TCP��Ϣ
struct TCP_Info
{
	BYTE							cbDataKind;							//��������
	BYTE							cbCheckCode;						//У���ֶ�
	WORD							wPacketSize;						//���ݴ�С
};

//TCP��������
struct TCP_Command
{
	WORD							wMainCmdID;							//��������
	WORD							wSubCmdID;							//��������
};

//TCPЭ��ͷ
struct TCP_Head
{
	TCP_Info						TCPInfo;							//�����ṹ
	TCP_Command						CommandInfo;						//������Ϣ
};

//Э��ͷ
struct NTY_TCPNetworkReadEvent
{
	WORD							wDataSize;							//���ݴ�С
	DWORD							dwSocketID;							//�����ʶ
	TCP_Command						Command;							//������Ϣ
};

#endif