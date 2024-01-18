#ifndef WIDGETEHKHUE_H
#define WIDGETEHKHUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

#include "countdown.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Countdown *countdown;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 400);
        countdown = new Countdown(Widget);
        countdown->setObjectName(QString::fromUtf8("countdown"));
        countdown->setGeometry(QRect(150, 150, 60, 60));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
    } // retranslateUi
};

namespace Ui
{
    class Widget : public Ui_Widget
    {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGETEHKHUE_H
