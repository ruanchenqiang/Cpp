#include <QCoreApplication>
#include <QPainter>
#include <QPalette>

#include "ui_widget.h"

void UI_Widget::setupUI(QWidget *w)
{
	if (w->objectName().isEmpty())
	{
		w->setObjectName(QString::fromUtf8("Widget"));
	}

	w->setFixedSize(600, 400);

	QPalette palette;
	palette.setColor(QPalette::Background, Qt::black);
	w->setPalette(palette);

	this->retranslateUI(w);
}

void UI_Widget::retranslateUI(QWidget *w)
{
	w->setWindowTitle(QCoreApplication::translate("Widget", "letter-rain", nullptr));
}
