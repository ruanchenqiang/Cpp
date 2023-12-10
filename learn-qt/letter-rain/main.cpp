#include <QApplication>
#include <QDesktopWidget>

#include "widget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Widget w;
	QDesktopWidget *desktop = QApplication::desktop();

	w.show();
	// 窗口居中
	w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);

	return app.exec();
}
