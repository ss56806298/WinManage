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

//�������
protected:
	QTcpSocket * m_pTcpSocket;	//SOCKET

//����
private:
	Ui::QtGuiApplication1Class ui;

//�ӽ���
protected:
	//����
	bool EncryptBuffer(BYTE cbBuffer[], WORD wPacketSize);
	//����
	bool CrevasseBuffer(BYTE cbBuffer[], WORD wPacketSize);

private	Q_SLOTS:
	//SOCKET��ȡ
	bool OnTcpSocketRead();
	//��¼��ť���
	bool OnLoginButtonClick();

	//˽�й�������
private:
	//��ʼ��
	bool InitializeNetworkSocket();
	//��������
	bool SendData(void * pData, WORD wDataSize, WORD wMainCmdID, WORD wSubCmdID);
};
