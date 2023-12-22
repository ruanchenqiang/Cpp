/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *circleButton;
    QPushButton *squareButton;
    QPushButton *triangleButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *blackButton;
    QPushButton *greenButton;
    QPushButton *redButton;
    QFrame *line_2;
    QCheckBox *moveCheckBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(602, 436);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 561, 321));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 370, 521, 30));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        circleButton = new QPushButton(layoutWidget);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));

        horizontalLayout_5->addWidget(circleButton);

        squareButton = new QPushButton(layoutWidget);
        squareButton->setObjectName(QString::fromUtf8("squareButton"));

        horizontalLayout_5->addWidget(squareButton);

        triangleButton = new QPushButton(layoutWidget);
        triangleButton->setObjectName(QString::fromUtf8("triangleButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(triangleButton->sizePolicy().hasHeightForWidth());
        triangleButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(triangleButton);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        blackButton = new QPushButton(layoutWidget);
        blackButton->setObjectName(QString::fromUtf8("blackButton"));

        horizontalLayout_4->addWidget(blackButton);

        greenButton = new QPushButton(layoutWidget);
        greenButton->setObjectName(QString::fromUtf8("greenButton"));

        horizontalLayout_4->addWidget(greenButton);

        redButton = new QPushButton(layoutWidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));

        horizontalLayout_4->addWidget(redButton);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_2);

        moveCheckBox = new QCheckBox(layoutWidget);
        moveCheckBox->setObjectName(QString::fromUtf8("moveCheckBox"));

        horizontalLayout_6->addWidget(moveCheckBox);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        label->setText(QString());
        circleButton->setText(QCoreApplication::translate("Widget", "\345\234\206\345\275\242", nullptr));
        squareButton->setText(QCoreApplication::translate("Widget", "\346\255\243\346\226\271\345\275\242", nullptr));
        triangleButton->setText(QCoreApplication::translate("Widget", "\344\270\211\350\247\222\345\275\242", nullptr));
        blackButton->setText(QCoreApplication::translate("Widget", "\351\273\221\350\211\262", nullptr));
        greenButton->setText(QCoreApplication::translate("Widget", "\347\273\277\350\211\262", nullptr));
        redButton->setText(QCoreApplication::translate("Widget", "\347\272\242\350\211\262", nullptr));
        moveCheckBox->setText(QCoreApplication::translate("Widget", "\346\213\226\345\212\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
