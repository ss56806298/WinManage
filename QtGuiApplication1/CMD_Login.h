#pragma once
#ifndef CMD_LOGIN_HEAD_FILE
#define CMD_LOGIN_HEAD_FILE

#include "CommonHeader.h"

//��¼��������
#define MDM_LS_LOGIN 1

#define SUB_LS_LOGIN_ACCOUNT 101

//�˺ŵ�¼
struct CMD_LS_LoginAccount
{
	WORD wVersion;							//�汾
	TCHAR szAccount[LEN_ACCOUNT];			//�˺�
	TCHAR szPassword[LEN_PASSWORD];			//����
};

#endif