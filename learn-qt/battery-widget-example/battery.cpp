#include <QPainter>

#include "battery.h"

Battery::Battery(QWidget *parent) : QWidget(parent)
{
	this->animationEnable = false;

	this->value = 20;
	this->minValue = 0;
	this->maxValue = 100;
	this->alarmValue = 20;
	this->animationValue = this->value;

	this->direction = Battery::SliderDirection::RIGHT;

	this->borderTopLeftX = 5;
	this->borderTopLeftY = 5;

	this->timer = new QTimer(this);
	timer->setInterval(10);

	connect(this->timer, SIGNAL(timeout()), this, SLOT(changeAnimationValue()));
}

bool Battery::getAnimationEnable()
{
	return this->animationEnable;
}

void Battery::setAnimationEnable(bool enable)
{
	this->animationEnable = enable;
}

void Battery::setTimerStart()
{
	if (!timer->isActive())
	{
		timer->start();
	}
}

void Battery::setTimerStop()
{
	if (timer->isActive())
	{
		timer->stop();
	}
}

double Battery::getAlarmValue()
{
	return this->alarmValue;
}

void Battery::setAlarmValue(double value)
{
	if (this->alarmValue == value)
	{
		return;
	}

	this->alarmValue = value;
	this->update();
}

double Battery::getValue()
{
	return this->value;
}

void Battery::setValue(double value)
{
	if (this->value == value)
	{
		return;
	}

	if (value < this->value)
	{
		this->direction = Battery::SliderDirection::LEFT;
	}
	else
	{
		this->direction = Battery::SliderDirection::RIGHT;
	}

	this->value = value;
	this->update();

	if (this->animationEnable)
	{
		this->setTimerStart();
	}
	else
	{
		this->setTimerStop();
		this->animationValue = value;
	}
}

void Battery::paintBorder(QPainter &painter)
{
	painter.save();

	painter.setPen(QPen(QColor(100, 100, 100), 10));
	painter.setBrush(Qt::NoBrush);
	painter.drawRoundedRect(this->border, 10, 10);

	painter.restore();
}

void Battery::paintBody(QPainter &painter)
{
	if (this->animationValue == this->minValue)
	{
		return;
	}

	painter.save();

	double width = this->width();
	double height = this->height();
	int margin = qMin(width, height) / 20;
	double unit = (this->border.width() - (margin * 2)) / (this->maxValue - this->minValue);
	double bodyWidth = (this->animationValue * unit);
	QPointF bodyTopLeft(this->borderTopLeftX + margin, this->borderTopLeftY + margin);
	QPointF bodyBottomRight(this->borderTopLeftX + margin + bodyWidth, this->borderBottomRightY - margin);
	QRectF body(bodyTopLeft, bodyBottomRight);

	painter.setPen(Qt::NoPen);
	if (this->animationValue <= this->alarmValue)
	{
		painter.setBrush(QColor(250, 118, 113));
	}
	else
	{
		painter.setBrush(QColor(50, 205, 51));
	}
	painter.drawRoundedRect(body, 10, 10);

	painter.restore();
}

void Battery::paintHead(QPainter &painter)
{
	painter.save();

	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(100, 100, 100));
	painter.drawRoundedRect(this->head, 5, 5);

	painter.restore();
}

void Battery::paintValue(QPainter &painter)
{
	painter.save();

	QFont font;

	font.setFamily("Microsoft YaHei");
	font.setPointSize(50);
	// font.setItalic(true);

	painter.setFont(font);
	painter.setPen(QColor(0, 160, 230));
	painter.drawText(this->border, Qt::AlignCenter, QString::number(int(this->animationValue)));

	painter.restore();
}

void Battery::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	// painter.setPen(QColor(0, 160, 230));
	// painter.drawRect(0, 0, this->width(), this->height());

	// 绘制边框
	this->paintBorder(painter);
	// 绘制主体
	this->paintBody(painter);
	// 绘制头部
	this->paintHead(painter);
	// 绘制电量值
	this->paintValue(painter);
}

void Battery::resizeEvent(QResizeEvent *)
{
	double width = this->width();
	double height = this->height();
	double headWidth = (width / 10);
	double headHeight = (height / 3);

	this->borderBottomRightX = (width - headWidth);
	this->borderBottomRightY = (height - this->borderTopLeftY);

	QPointF borderTopLeft(this->borderTopLeftX, this->borderTopLeftY);
	QPointF borderBottomRight(this->borderBottomRightX, this->borderBottomRightY);
	QPointF headTopLeft(width - headWidth, headHeight);
	QPointF headBottomRight(width, height - headHeight);

	this->border = QRectF(borderTopLeft, borderBottomRight);
	this->head = QRectF(headTopLeft, headBottomRight);
}

void Battery::changeAnimationValue()
{
	double step = 0.5;

	if (this->direction == Battery::SliderDirection::LEFT)
	{
		this->animationValue -= step;
		if (this->animationValue <= this->value)
		{
			this->animationValue = this->value;
			this->setTimerStop();
		}
	}
	else
	{
		this->animationValue += step;
		if (this->animationValue >= this->value)
		{
			this->animationValue = this->value;
			this->setTimerStop();
		}
	}

	this->update();
}

Battery::~Battery()
{
	this->setTimerStop();
}
