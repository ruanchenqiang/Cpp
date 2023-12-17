#include <QCoreApplication>
#include <QPixmap>

#include "ui_login.h"

void UI_Login::setupUI(QWidget *parent)
{
	if (parent->objectName().isEmpty())
	{
		parent->setObjectName(QString::fromUtf8("Widget"));
	}
	parent->resize(300, 200);

	gridLayout = new QGridLayout(parent);
	gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

	icon = new QLabel(parent);
	icon->setObjectName(QString::fromUtf8("icon"));
	icon->setPixmap(QPixmap("qt.jpg").scaled(90, 90));
	
	username = new QLineEdit(parent);
	username->setObjectName(QString::fromUtf8("username"));
	username->setMaxLength(128);
	
	registration = new QPushButton(parent);
	registration->setObjectName(QString::fromUtf8("registration"));
	
	pwd = new QLineEdit(parent);
	pwd->setObjectName(QString::fromUtf8("pwd"));
	pwd->setMaxLength(64);
	
	forgotPwd = new QPushButton(parent);
	forgotPwd->setObjectName(QString::fromUtf8("forgotPwd"));

	rememberPwd = new QCheckBox(parent);
	rememberPwd->setObjectName(QString::fromUtf8("rememberPwd"));

	automaticLogin = new QCheckBox(parent);
	automaticLogin->setObjectName(QString::fromUtf8("automaticLogin"));

	login = new QPushButton(parent);
	login->setObjectName(QString::fromUtf8("login"));

	gridLayout->addWidget(icon, 0, 0, 2, 2);
	gridLayout->addWidget(username, 0, 2, 1, 2);
	gridLayout->addWidget(registration, 0, 4, 1, 1);
	gridLayout->addWidget(pwd, 1, 2, 1, 2);
	gridLayout->addWidget(forgotPwd, 1, 4, 1, 1);
	gridLayout->addWidget(rememberPwd, 2, 2, 1, 1);
	gridLayout->addWidget(automaticLogin, 2, 3, 1, 1);
	gridLayout->addWidget(login, 3, 2, 1, 2);

	this->retranslateUI(parent);

	// QMetaObject::connectSlotsByName(parent);
}

void UI_Login::retranslateUI(QWidget *parent)
{
	parent->setWindowTitle(QCoreApplication::translate("Widget", "Login", nullptr));

	username->setPlaceholderText("邮箱");
	registration->setText(QCoreApplication::translate("Widget", "注册账号", nullptr));
	pwd->setPlaceholderText("密码");
	forgotPwd->setText(QCoreApplication::translate("Widget", "忘记密码", nullptr));
	rememberPwd->setText(QCoreApplication::translate("Widget", "记住密码", nullptr));
	automaticLogin->setText(QCoreApplication::translate("Widget", "自动登录", nullptr));
	login->setText(QCoreApplication::translate("Widget", "登录", nullptr));
}
