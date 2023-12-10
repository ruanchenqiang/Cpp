#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>
#include <QProcess>
#include <QTextEdit>

namespace UI
{
	class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = nullptr);
	~Dialog();

private slots:
	void on_startButton_2_0_clicked();
	void readyReadStandardOutput();
	void processStarted();
	void encodingFinished();
	void on_fileOpenButton_0_0_clicked();
	void on_playInputButton_5_0_clicked();
	void on_playOutputButton_5_0_clicked();

private:
	UI::Dialog *ui;
	QProcess *mTranscodingProcess;
	QProcess *mInputPlayProcess;
	QProcess *mOutputPlayProcess;
	QString mOutputString;
};

#endif // DIALOG_H