#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QProcess>
#include <QScrollBar>
#include <QString>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new UI::Dialog)
{
	this->ui->setupUI(this);

	// Play button for output - initially disabled
	ui->playOutputButton_5_0->setEnabled(false);

	// Create three processes
	// 1.transcoding, 2.input play 3.output play
	mTranscodingProcess = new QProcess(this);
	mInputPlayProcess = new QProcess(this);
	mOutputPlayProcess = new QProcess(this);

	connect(mTranscodingProcess, SIGNAL(started()),
			this, SLOT(processStarted()));
	connect(mTranscodingProcess, SIGNAL(readyReadStandardOutput()),
			this, SLOT(readyReadStandardOutput()));
	connect(mTranscodingProcess, SIGNAL(finished(int)),
			this, SLOT(encodingFinished()));
}

void Dialog::processStarted()
{
	qDebug() << "processStarted()";
}

// conversion start
void Dialog::on_startButton_2_0_clicked()
{
	QString input = ui->fromLineEdit_0_0->text();
	if (input.isEmpty())
	{
		qDebug() << "No input";
		QMessageBox::information(this, tr("ffmpeg"), tr("Input file not specified"));
		return;
	}

	QString output = ui->toLineEdit_1_0->text();
	if (output.isEmpty())
	{
		qDebug() << "No output";
		QMessageBox::information(this, tr("ffmpeg"), tr("Output file not specified"));
		return;
	}

	QString fileName = ui->toLineEdit_1_0->text();
	qDebug() << "output file check " << fileName;
	qDebug() << "QFile::exists(fileName) = " << QFile::exists(fileName);
	if (QFile::exists(fileName))
	{
		if (QMessageBox::question(this,
								  tr("ffmpeg"),
								  tr("There already exists a file called %1 in "
									 "the current directory. Overwrite?")
									  .arg(fileName),
								  QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::No)
			return;

		QFile::remove(fileName);
		while (QFile::exists(fileName))
		{
			qDebug() << "output file still there";
		}
	}

	QString program = "/usr/bin/ffmpeg";
	QStringList arguments;

	arguments << "-i" << input << output;

	qDebug() << arguments;

	mTranscodingProcess->setProcessChannelMode(QProcess::MergedChannels);
	mTranscodingProcess->start(program, arguments);
}

void Dialog::readyReadStandardOutput()
{
	mOutputString.append(mTranscodingProcess->readAllStandardOutput());
	ui->textEdit_3_0->setText(mOutputString);

	// put the slider at the bottom
	ui->textEdit_3_0->verticalScrollBar()->setSliderPosition(ui->textEdit_3_0->verticalScrollBar()->maximum());
}

void Dialog::encodingFinished()
{
	// Set the encoding status by checking output file's existence
	QString fileName = ui->toLineEdit_1_0->text();

	if (QFile::exists(fileName))
	{
		ui->transcodingStatusLabel_4_0->setText("Transcoding Status: Successful!");
		ui->playOutputButton_5_0->setEnabled(true);
	}
	else
	{
		ui->transcodingStatusLabel_4_0->setText("Transcoding Status: Failed!");
	}
}

// Browse... button clicked - this is for input file
void Dialog::on_fileOpenButton_0_0_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,
													tr("Open File"),
													"./",
													tr("videoss (*.mp4 *.mov *.avi)"));

	if (!fileName.isEmpty())
	{
		ui->fromLineEdit_0_0->setText(fileName);
	}
}

void Dialog::on_playInputButton_5_0_clicked()
{
	QString program = "/usr/bin/ffplay";
	QStringList arguments;
	QString input = ui->fromLineEdit_0_0->text();

	arguments << "-x"
			  << "500";
	arguments << "-y"
			  << "500";
	arguments << input;

	mInputPlayProcess->start(program, arguments);
}

void Dialog::on_playOutputButton_5_0_clicked()
{
	QString program = "/usr/bin/ffplay";
	QStringList arguments;
	QString output = ui->toLineEdit_1_0->text();

	arguments << "-x"
			  << "500";
	arguments << "-y"
			  << "500";
	arguments << output;

	mInputPlayProcess->start(program, arguments);
}

Dialog::~Dialog()
{
	delete ui;
}
