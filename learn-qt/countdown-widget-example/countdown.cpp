#include <QPainter>

#include "countdown.h"

Countdown::Countdown(QWidget *parent) : QWidget(parent)
{
	this->countdown = 10;

	this->interval = 100;
	this->millisecond = 0;

	this->startAngle = 90;
	this->spanAngle = -360;
	this->stepAngle = ((360.0 / this->countdown) / (1000 / this->interval));

	this->timer = new QTimer(this);
	timer->setInterval(this->interval);

	this->isFirstEnter = true;

	connect(this->timer, SIGNAL(timeout()), this, SLOT(changeProgress()));
}

void Countdown::setTimerStart()
{
	if (!timer->isActive())
	{
		timer->start();
	}
}

void Countdown::setTimerStop()
{
	if (timer->isActive())
	{
		timer->stop();
	}
}

void Countdown::paintX(QPainter &painter)
{
	painter.save();

	painter.setPen(QPen(QColor(250, 118, 113), 3));
	painter.drawLine(this->xRect.topLeft(), this->xRect.bottomRight());
	painter.drawLine(this->xRect.topRight(), this->xRect.bottomLeft());

	painter.restore();
}

void Countdown::paintCountdown(QPainter &painter)
{
	painter.save();

	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);

	painter.setFont(font);
	painter.setPen(QPen(QColor(0, 160, 230), 3));
	painter.drawText(this->countdownRect, Qt::AlignCenter, QString::number(int(this->countdown)));

	painter.restore();
}

void Countdown::paintProgressBar(QPainter &painter)
{
	painter.save();

	painter.setPen(QPen(QColor(0, 160, 230), 5));
	painter.drawArc(5, 5, 50, 50, this->startAngle * 16, this->spanAngle * 16);

	painter.restore();
}

void Countdown::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	// painter.setPen(QColor(0, 160, 230));
	// painter.drawRect(0, 0, this->width(), this->height());

	if (this->countdown == 0)
	{
		this->paintX(painter);
	}
	else
	{
		this->paintCountdown(painter);
	}

	this->paintProgressBar(painter);
}

bool Countdown::event(QEvent *event)
{
	switch (event->type())
	{
	case QEvent::Enter:
		this->enterEvent(event);
		break;
	case QEvent::Leave:
		this->leaveEvent(event);
		break;
	default:
		break;
	}

	return QWidget::event(event);
}

void Countdown::enterEvent(QEvent *event)
{
	if (this->isFirstEnter)
	{
		this->setTimerStart();
		this->isFirstEnter = !this->isFirstEnter;
	}
}

void Countdown::leaveEvent(QEvent *event)
{
}

void Countdown::mousePressEvent(QMouseEvent *event)
{
	// 鼠标左键
	if (event->button() == Qt::LeftButton)
	{
		this->lastPoint = event->pos();
	}
}

void Countdown::mouseReleaseEvent(QMouseEvent *event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		;
	}
}

void Countdown::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->pos().x() - lastPoint.x();
	int dy = event->pos().y() - lastPoint.y();

	this->move(this->x() + dx, this->y() + dy);
}

void Countdown::resizeEvent(QResizeEvent *event)
{
	double width = this->width();
	double height = this->height();

	this->xRect = QRectF(QPointF(20, 20), QPointF(width - 20, height - 20));
	this->countdownRect = QRectF(QPointF(10, 10), QPointF(width - 10, height - 10));
}

void Countdown::changeProgress()
{
	this->millisecond += this->interval;
	this->startAngle -= this->stepAngle;
	this->spanAngle += this->stepAngle;

	if (this->startAngle <= -270)
	{
		this->startAngle = -270;
		this->setTimerStop();
	}

	if (this->spanAngle >= 0)
	{
		this->spanAngle = 0;
		this->setTimerStop();
	}

	if (this->millisecond >= 1000)
	{
		this->countdown -= (this->millisecond / 1000);

		if (this->countdown <= 0)
		{
			this->countdown = 0;
			this->setTimerStop();
		}

		this->millisecond = (this->millisecond % 1000);
	}

	this->update();
}

Countdown::~Countdown()
{
	this->setTimerStop();
}
