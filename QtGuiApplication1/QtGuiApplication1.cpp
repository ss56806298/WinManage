#include "Packet.h"
#include "CMD_Common.h"
#include "CMD_Login.h"
#include <assert.h>
#include "QtGuiApplication1.h"
#include <QValidator>

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//字体
	QFont font("Microsoft YaHei", 13);

	//Label
	ui.LabelAccount->setFont(font);
	ui.LabelPassword->setFont(font);

	ui.LabelTip->setStyleSheet("color:red;");

	//LineEdit
	QRegExp regExp("^[A-Za-z0-9]+$");
	QRegExpValidator *pattern = new QRegExpValidator(regExp, this);
	ui.LineEditAccount->setValidator(pattern);
	ui.LineEditAccount->setMaxLength(20);

	ui.LineEditPassword->setValidator(pattern);
	ui.LineEditPassword->setEchoMode(QLineEdit::Password);
	ui.LineEditPassword->setMaxLength(20);

	//SOCKET
	m_pTcpSocket = new QTcpSocket();

	//信号
	connect(ui.ButtonLogin, &QPushButton::clicked, this, &QtGuiApplication1::OnLoginButtonClick);	//登录按钮click
	
}

//析构函数
QtGuiApplication1::~QtGuiApplication1()
{
	delete m_pTcpSocket;
}

//加密
bool QtGuiApplication1::EncryptBuffer(BYTE cbBuffer[], WORD wPacketSize)
{
	//校验参数
	assert(wPacketSize >= sizeof(TCP_Head));
	assert(wPacketSize <= (sizeof(TCP_Head) + MAX_ASYNCHRONISM_DATA));
	
	//校验码与字节映射
	BYTE cbCheckCode = 0;
	BYTE cbSendRound = 0;
	for (WORD i = sizeof(TCP_Info); i < wPacketSize; i++)
	{
		cbCheckCode += cbBuffer[i];
		cbBuffer[i] = g_SendByteMap[(BYTE)(cbBuffer[i] + cbSendRound)];
		cbSendRound += 3;
	}

	//填写信息头
	TCP_Head * pHead = (TCP_Head *)cbBuffer;
	pHead->TCPInfo.cbCheckCode = ~cbCheckCode + 1;
	pHead->TCPInfo.wPacketSize = wPacketSize;
	pHead->TCPInfo.cbDataKind = SOCKET_TCP_VER;

	return true;
}

//解密
bool QtGuiApplication1::CrevasseBuffer(BYTE cbBuffer[], WORD wPacketSize)
{


	//校验码与字节映射
	return true;
}

//初始化网络连接
bool QtGuiApplication1::InitializeNetworkSocket()
{
	ui.LabelTip->setText("");

	m_pTcpSocket->connectToHost("127.0.0.1", 8300);

	if (!m_pTcpSocket->waitForConnected(30000))
	{
		ui.LabelTip->setText(QStringLiteral("连接服务器发生错误"));
		return false;
	}

	connect(m_pTcpSocket, &QTcpSocket::readyRead, this, &QtGuiApplication1::OnTcpSocketRead);

	return true;
}

//网络读取事件
bool QtGuiApplication1::OnTcpSocketRead()
{
	char recvMsg[1024] = { 0 };
	int recvRe = m_pTcpSocket->read(recvMsg, 1024);

	if (recvRe == -1)
	{
		return true;
	}

	return true;
}

//发送数据
bool QtGuiApplication1::SendData(void * pData, WORD wDataSize, WORD wMainCmdID, WORD wSubCmdID)
{
	BYTE cbBuffer[MAX_ASYNCHRONISM_DATA];

	//协议头构造
	TCP_Head * pHead = (TCP_Head *)cbBuffer;
	pHead->CommandInfo.wMainCmdID = wMainCmdID;
	pHead->CommandInfo.wSubCmdID = wSubCmdID;

	if (wDataSize > 0)
	{
		assert(pData != NULL);
		memcpy(pHead + 1, pData, wDataSize);
	}

	EncryptBuffer(cbBuffer, sizeof(TCP_Head) + wDataSize);

	char pcbBuffer[MAX_ASYNCHRONISM_DATA];
	memcpy(pcbBuffer, cbBuffer, sizeof(TCP_Head) + wDataSize);

	m_pTcpSocket->write(pcbBuffer, sizeof(TCP_Head) + wDataSize);

	return true;
}

//按下登录按钮
bool QtGuiApplication1::OnLoginButtonClick()
{
	ui.LabelAccount->setText(ui.LineEditAccount->text());

	if (!InitializeNetworkSocket()) return true;

	CMD_LS_LoginAccount LoginAccount;
	memset(&LoginAccount, 0, sizeof(LoginAccount));

	//LoginAccount

	return true;
}