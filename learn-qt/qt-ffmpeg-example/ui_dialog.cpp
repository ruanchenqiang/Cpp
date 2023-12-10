#include "ui_dialog.h"

void UI_Dialog::setupUI(QDialog *Dialog)
{
	if (Dialog->objectName().isEmpty())
	{
		Dialog->setObjectName(QString::fromUtf8("Dialog"));
	}
	Dialog->resize(500, 506);

	gridLayout = new QGridLayout(Dialog);
	gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
	// 设置布局中部件之间的间距
	gridLayout->setSpacing(6);
	// 设置布局的左、上、右、下到窗体边缘的距离
	gridLayout->setContentsMargins(11, 11, 11, 11);

	horizontalLayout_0_0 = new QHBoxLayout();
	horizontalLayout_0_0->setObjectName(QString::fromUtf8("horizontalLayout_0_0"));
	horizontalLayout_0_0->setSpacing(6);

	fromLabel_0_0 = new QLabel(Dialog);
	fromLabel_0_0->setObjectName(QString::fromUtf8("fromLabel_0_0"));

	fromLineEdit_0_0 = new QLineEdit(Dialog);
	fromLineEdit_0_0->setObjectName(QString::fromUtf8("fromLineEdit_0_0"));

	fileOpenButton_0_0 = new QPushButton(Dialog);
	fileOpenButton_0_0->setObjectName(QString::fromUtf8("fileOpenButton_0_0"));

	horizontalLayout_0_0->addWidget(fromLabel_0_0);
	horizontalLayout_0_0->addWidget(fromLineEdit_0_0);
	horizontalLayout_0_0->addWidget(fileOpenButton_0_0);

	horizontalLayout_1_0 = new QHBoxLayout();
	horizontalLayout_1_0->setObjectName(QString::fromUtf8("horizontalLayout_1_0"));
	horizontalLayout_1_0->setSpacing(6);

	toLabel_1_0 = new QLabel(Dialog);
	toLabel_1_0->setObjectName(QString::fromUtf8("toLabel_1_0"));

	toLineEdit_1_0 = new QLineEdit(Dialog);
	toLineEdit_1_0->setObjectName(QString::fromUtf8("toLineEdit_1_0"));

	horizontalSpacer_1_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_1_0->addWidget(toLabel_1_0);
	horizontalLayout_1_0->addWidget(toLineEdit_1_0);
	horizontalLayout_1_0->addItem(horizontalSpacer_1_0);

	horizontalLayout_2_0 = new QHBoxLayout();
	horizontalLayout_2_0->setObjectName(QString::fromUtf8("horizontalLayout_2_0"));
	horizontalLayout_2_0->setSpacing(6);

	startButton_2_0 = new QPushButton(Dialog);
	startButton_2_0->setObjectName(QString::fromUtf8("startButton_2_0"));

	horizontalSpacer_2_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_2_0->addWidget(startButton_2_0);
	horizontalLayout_2_0->addItem(horizontalSpacer_2_0);

	textEdit_3_0 = new QTextEdit(Dialog);
	textEdit_3_0->setObjectName(QString::fromUtf8("textEdit_3_0"));

	horizontalLayout_4_0 = new QHBoxLayout();
	horizontalLayout_4_0->setSpacing(6);
	horizontalLayout_4_0->setObjectName(QString::fromUtf8("horizontalLayout_4_0"));

	transcodingStatusLabel_4_0 = new QLabel(Dialog);
	transcodingStatusLabel_4_0->setObjectName(QString::fromUtf8("transcodingStatusLabel_4_0"));

	horizontalSpacer_4_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_4_0->addWidget(transcodingStatusLabel_4_0);
	horizontalLayout_4_0->addItem(horizontalSpacer_4_0);

	horizontalLayout_5_0 = new QHBoxLayout();
	horizontalLayout_5_0->setSpacing(6);
	horizontalLayout_5_0->setObjectName(QString::fromUtf8("horizontalLayout_5_0"));

	playInputButton_5_0 = new QPushButton(Dialog);
	playInputButton_5_0->setObjectName(QString::fromUtf8("playInputButton_5_0"));

	playOutputButton_5_0 = new QPushButton(Dialog);
	playOutputButton_5_0->setObjectName(QString::fromUtf8("playOutputButton_5_0"));

	horizontalLayout_5_0->addWidget(playInputButton_5_0);
	horizontalLayout_5_0->addWidget(playOutputButton_5_0);

	pushButton_6_1 = new QPushButton(Dialog);
	pushButton_6_1->setObjectName(QString::fromUtf8("pushButton_6_1"));

	gridLayout->addLayout(horizontalLayout_0_0, 0, 0, 1, 2);
	gridLayout->addLayout(horizontalLayout_1_0, 1, 0, 1, 2);
	gridLayout->addLayout(horizontalLayout_2_0, 2, 0, 1, 1);
	gridLayout->addWidget(textEdit_3_0, 3, 0, 1, 2);
	gridLayout->addLayout(horizontalLayout_4_0, 4, 0, 1, 2);
	gridLayout->addLayout(horizontalLayout_5_0, 5, 0, 1, 2);
	gridLayout->addWidget(pushButton_6_1, 6, 1, 1, 1);

	this->retranslateUI(Dialog);

	QObject::connect(pushButton_6_1, SIGNAL(clicked()), Dialog, SLOT(close()));

	QMetaObject::connectSlotsByName(Dialog);
}

void UI_Dialog::retranslateUI(QDialog *Dialog)
{
	Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "QT-FFmpeg", nullptr));

	fromLabel_0_0->setText(QCoreApplication::translate("Dialog", "From:", nullptr));
	fileOpenButton_0_0->setText(QCoreApplication::translate("Dialog", "Browse...", nullptr));

	toLabel_1_0->setText(QCoreApplication::translate("Dialog", "To:", nullptr));

	startButton_2_0->setText(QCoreApplication::translate("Dialog", "Convert", nullptr));

	transcodingStatusLabel_4_0->setText(QCoreApplication::translate("Dialog", "Transcoding Status:", nullptr));

	playInputButton_5_0->setText(QCoreApplication::translate("Dialog", "Play Input", nullptr));
	playOutputButton_5_0->setText(QCoreApplication::translate("Dialog", "Play Output", nullptr));

	pushButton_6_1->setText(QCoreApplication::translate("Dialog", "Close", nullptr));
}
