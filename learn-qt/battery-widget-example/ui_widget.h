#ifndef WIDGETEHKHUE_H
#define WIDGETEHKHUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

#include "battery.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Battery *battery;
    QSlider *horizontalSlider;
    QCheckBox *animationCheckBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(528, 376);
        battery = new Battery(Widget);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(30, 30, 391, 201));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 270, 391, 31));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        animationCheckBox = new QCheckBox(Widget);
        animationCheckBox->setObjectName(QString::fromUtf8("animationCheckBox"));
        animationCheckBox->setGeometry(QRect(450, 270, 51, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        animationCheckBox->setText(QCoreApplication::translate("Widget", "\345\212\250\347\224\273", nullptr));
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
