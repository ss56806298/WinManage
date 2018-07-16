#pragma once

#include "CommonHeader.h"
#include <QtWidgets/QWidget>
#include <QtNetwork/QtNetwork>
#include "ui_QtGuiApplication1.h"

class QtGuiApplication1 : public QWidget
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
	~QtGuiApplication1();

//组件变量
protected:
	QTcpSocket * m_pTcpSocket;	//SOCKET

//界面
private:
	Ui::QtGuiApplication1Class ui;

//加解密
protected:
	//加密
	bool EncryptBuffer(BYTE cbBuffer[], WORD wPacketSize);
	//解密
	bool CrevasseBuffer(BYTE cbBuffer[], WORD wPacketSize);

private	Q_SLOTS:
	//SOCKET读取
	bool OnTcpSocketRead();
	//登录按钮点击
	bool OnLoginButtonClick();

	//私有公共函数
private:
	//初始化
	bool InitializeNetworkSocket();
	//发送数据
	bool SendData(void * pData, WORD wDataSize, WORD wMainCmdID, WORD wSubCmdID);
};
