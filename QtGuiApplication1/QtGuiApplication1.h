#pragma once

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

private:
	Ui::QtGuiApplication1Class ui;

private	Q_SLOTS:
	bool OnLoginButtonClick();
};
