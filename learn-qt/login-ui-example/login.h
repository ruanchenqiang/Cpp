#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace UI
{
	class Login;
}

class Login : public QWidget
{
	Q_OBJECT

public:
	explicit Login(QWidget *parent = nullptr);
	~Login();

private:
	UI::Login *ui;
};

#endif // LOGIN_H