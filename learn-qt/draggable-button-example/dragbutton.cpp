#include <QMouseEvent>
#include <QPainter>

#include "dragbutton.h"

DragButton::DragButton(QWidget *parent) : QWidget(parent)
{
	this->dragEnable = false;
	this->flickerEnable = false;

	this->text = "";
	this->style = DragButton::ButtonStyle::CIRCLE;
	this->color = DragButton::ButtonColor::GREEN;
	this->alarmColor = DragButton::ButtonColor::RED;

	this->imgPath = makeImgPath(this->color, this->style);

	this->timer = new QTimer(this);
	timer->setInterval(200);

	connect(timer, SIGNAL(timeout()), this, SLOT(changeImgPath()));

	// 注册事件过滤器
	this->installEventFilter(this);
}

bool DragButton::getDragEnable()
{
	return this->dragEnable;
}

void DragButton::setDragEnable(bool enable)
{
	this->dragEnable = enable;
}

QString DragButton::getText()
{
	return this->text;
}

void DragButton::setText(const QString &text)
{
	if (this->text == text)
	{
		return;
	}

	this->text = text;
	this->update();
}

DragButton::ButtonColor DragButton::getAlarmColor()
{
	return this->alarmColor;
}

void DragButton::setAlarmColor(const ButtonColor &color)
{
	if (this->alarmColor == color)
	{
		return;
	}

	this->alarmColor = color;
	this->update();
}

DragButton::ButtonColor DragButton::getColor()
{
	return this->color;
}

void DragButton::setColor(const ButtonColor &color)
{
	if (this->color == color)
	{
		return;
	}

	this->color = color;
	this->imgPath = makeImgPath(this->color, this->style);
	this->update();

	// 如果跟告警颜色一样就启动定时器
	if (this->color == alarmColor)
	{
		flickerEnable = true;

		if (!timer->isActive())
		{
			timer->start();
		}
	}
	else
	{
		flickerEnable = false;

		if (timer->isActive())
		{
			timer->stop();
		}
	}
}

DragButton::ButtonStyle DragButton::getStyle()
{
	return this->style;
}

void DragButton::setStyle(const ButtonStyle &style)
{
	if (this->style == style)
	{
		return;
	}

	this->style = style;
	this->imgPath = makeImgPath(this->color, this->style);
	this->update();
}

void DragButton::paintImg(QPainter &painter)
{
	double width = this->width();
	double height = this->height();
	QImage img(this->imgPath);

	if (!img.isNull())
	{
		img = img.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		painter.drawImage(0, 0, img);
	}
}

void DragButton::paintText(QPainter &painter)
{
	double width = this->width();
	double height = this->height();

	// 设置字体
	QFont font;
	font.setPixelSize(height * 0.3);
	font.setBold(true);

	// 在合适的位置绘制文本
	QRectF rect = this->rect();
	if (style == ButtonStyle::TRIANGLE)
	{
		double y = (height / 3);
		rect = QRectF(0, y, width, height - y);
	}

	painter.setFont(font);
	painter.setPen(Qt::white);
	painter.drawText(rect, Qt::AlignCenter, text);
}

void DragButton::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);

	// 绘制背景
	this->paintImg(painter);
	// 绘制文本
	this->paintText(painter);
}

bool DragButton::eventFilter(QObject *watched, QEvent *event)
{
	switch (event->type())
	{
	case QEvent::MouseButtonPress:
	{
		QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

		// 鼠标左键
		if (mouseEvent->button() == Qt::LeftButton)
		{
			lastPoint = mouseEvent->pos();
			pressEnable = true;

			return true;
		}

		break;
	}
	case QEvent::MouseButtonRelease:
	{
		pressEnable = false;
		break;
	}
	case QEvent::MouseMove:
	{
		// 控件允许被拖动
		if (dragEnable && pressEnable)
		{
			QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

			int dx = mouseEvent->pos().x() - lastPoint.x();
			int dy = mouseEvent->pos().y() - lastPoint.y();

			this->move(this->x() + dx, this->y() + dy);

			return true;
		}

		break;
	}
	case QEvent::MouseButtonDblClick:
	{
		break;
	}
	default:
	{
		break;
	}
	}

	return QWidget::eventFilter(watched, event);
}

QString DragButton::makeImgPath(const ButtonColor &color, const ButtonStyle &style)
{
	QString colorStr = colorStrMap.value(color);
	QString styleStr = styleStrMap.value(style);

	return QString("resources/icon_%1_%2.png").arg(colorStr).arg(styleStr);
}

void DragButton::changeImgPath()
{
	if (flickerEnable)
	{
		this->imgPath = makeImgPath(DragButton::ButtonColor::BLACK, this->style);
	}
	else
	{
		this->imgPath = makeImgPath(this->color, this->style);
	}

	flickerEnable = !flickerEnable;
	this->update();
}

DragButton::~DragButton()
{
	if (timer->isActive())
	{
		timer->stop();
	}
}
