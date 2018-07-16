#pragma once
#ifndef CMD_LOGIN_HEAD_FILE
#define CMD_LOGIN_HEAD_FILE

#include "CommonHeader.h"

//µÇÂ¼·şÎñÃüÁî
#define MDM_LS_LOGIN 1

#define SUB_LS_LOGIN_ACCOUNT 101

//ÕËºÅµÇÂ¼
struct CMD_LS_LoginAccount
{
	WORD wVersion;							//°æ±¾
	TCHAR szAccount[LEN_ACCOUNT];			//ÕËºÅ
	TCHAR szPassword[LEN_PASSWORD];			//ÃÜÂë
};

#endif