#include <QApplication>
#include <QDesktopWidget>

#include "widget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QDesktopWidget *desktop = QApplication::desktop();

	Widget w;

	w.show();
	w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);

	return app.exec();
}