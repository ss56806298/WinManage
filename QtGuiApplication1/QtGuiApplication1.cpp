#include "QtGuiApplication1.h"
#include <QValidator>

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//����
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

	//�ź�
	connect(ui.ButtonLogin, &QPushButton::clicked, this, &QtGuiApplication1::OnLoginButtonClick);
}

//��������
QtGuiApplication1::~QtGuiApplication1()
{
	delete m_pTcpSocket;
}

//���µ�¼��ť
bool QtGuiApplication1::OnLoginButtonClick()
{
	ui.LabelTip->setText("");

	m_pTcpSocket->connectToHost("127.0.0.1", 8310);

	if (!m_pTcpSocket->waitForConnected(30000))
	{
		ui.LabelTip->setText(QStringLiteral("���ӷ�������������"));
		return false;
	}
	return true;
}