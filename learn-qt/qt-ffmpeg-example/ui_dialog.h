#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QtWidgets>

class UI_Dialog
{
public:
	void setupUI(QDialog *Dialog);
	void retranslateUI(QDialog *Dialog);

public:
	QGridLayout *gridLayout;

	QHBoxLayout *horizontalLayout_0_0;
	QLabel *fromLabel_0_0;
	QLineEdit *fromLineEdit_0_0;
	QPushButton *fileOpenButton_0_0;

	QHBoxLayout *horizontalLayout_1_0;
	QLabel *toLabel_1_0;
	QLineEdit *toLineEdit_1_0;
	QSpacerItem *horizontalSpacer_1_0;

	QHBoxLayout *horizontalLayout_2_0;
	QPushButton *startButton_2_0;
	QSpacerItem *horizontalSpacer_2_0;

	QTextEdit *textEdit_3_0;

	QHBoxLayout *horizontalLayout_4_0;
	QLabel *transcodingStatusLabel_4_0;
	QSpacerItem *horizontalSpacer_4_0;

	QHBoxLayout *horizontalLayout_5_0;
	QPushButton *playInputButton_5_0;
	QPushButton *playOutputButton_5_0;

	QPushButton *pushButton_6_1;
};

namespace UI
{
	class Dialog : public UI_Dialog
	{
	};
} // namespace UI

#endif // UI_DIALOG_H