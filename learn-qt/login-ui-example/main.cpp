#include <QApplication>
#include <QDesktopWidget>

#include "login.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QDesktopWidget *desktop = QApplication::desktop();

	Login login;

	login.show();
	login.move((desktop->width() - login.width()) / 2, (desktop->height() - login.height()) / 2);

	return app.exec();
}