#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class UI_Login
{
public:
	void setupUI(QWidget *parent);
	void retranslateUI(QWidget *parent);

public:
	QGridLayout *gridLayout;

	QLabel *icon;
	QLineEdit *username;
	QPushButton *registration;
	QLineEdit *pwd;
	QPushButton *forgotPwd;
	QCheckBox *rememberPwd;
	QCheckBox *automaticLogin;
	QPushButton *login;
};

namespace UI
{
	class Login : public UI_Login
	{
	};
} // namespace UI

#endif // UI_LOGIN_H