#include <QDialog>
#include <QtWidgets>

#include "dialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Dialog w;
	QDesktopWidget *desktop = QApplication::desktop();

	w.show();
	// 窗口居中
	w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);

	return app.exec();
}
