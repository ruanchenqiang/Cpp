#include <QPainter>

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new UI::Widget)
{
	this->ui->setupUI(this);

	int width = this->width();
	int height = this->height();
	int interval = 10;
	int pixel_size = 10;
	int num_rain = width / interval;

	for (int i = 0; i < num_rain; ++i)
	{
		int x = i * interval;
		int y = 0;

		m_letter_rain.push_back(LetterRain(x, y, height, pixel_size, 8));
	}

	m_timer_id = this->startTimer(50);
}

void Widget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	for (auto &letter_rain : m_letter_rain)
	{
		letter_rain.paint(&painter);
	}
}

void Widget::timerEvent(QTimerEvent *event)
{
	for (auto &letter_rain : m_letter_rain)
	{
		int fall_speed = (qrand() % 16 + 16);
		// int fall_speed = 32;

		letter_rain.fall(fall_speed);
	}

	this->update();
}

Widget::~Widget()
{
	delete ui;
}
