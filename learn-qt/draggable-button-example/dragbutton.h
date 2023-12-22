#ifndef DRAGBUTTON_H
#define DRAGBUTTON_H

#include <QMap>
#include <QTimer>

#include <QWidget>

class DragButton : public QWidget
{
	Q_OBJECT

public:
	enum class ButtonStyle
	{
		CIRCLE,
		SQUARE,
		TRIANGLE,
	};

	enum class ButtonColor
	{
		BLACK,
		GREEN,
		RED,
	};

	const QMap<ButtonStyle, QString> styleStrMap = {
		{ButtonStyle::CIRCLE, "circle"},
		{ButtonStyle::SQUARE, "square"},
		{ButtonStyle::TRIANGLE, "triangle"},
	};

	const QMap<ButtonColor, QString> colorStrMap = {
		{ButtonColor::BLACK, "black"},
		{ButtonColor::GREEN, "green"},
		{ButtonColor::RED, "red"},
	};

private:
	// 拖动开关
	bool dragEnable;
	// 闪烁开关
	bool flickerEnable;
	// 鼠标点击开关
	bool pressEnable;

	// 文本
	QString text;
	// 样式
	ButtonStyle style;
	// 颜色
	ButtonColor color;
	// 告警颜色
	ButtonColor alarmColor;

	// 图片路径
	QString imgPath;

	// 鼠标点击位置
	QPoint lastPoint;

	// 闪烁定时器
	QTimer *timer;

public:
	explicit DragButton(QWidget *parent = nullptr);
	~DragButton();

public:
	bool getDragEnable();
	void setDragEnable(bool enable);

	QString getText();
	void setText(const QString &text);

	ButtonColor getAlarmColor();
	void setAlarmColor(const ButtonColor &color);

	ButtonColor getColor();
	void setColor(const ButtonColor &color);

	ButtonStyle getStyle();
	void setStyle(const ButtonStyle &style);

protected:
	void paintImg(QPainter &painter);
	void paintText(QPainter &painter);
	void paintEvent(QPaintEvent *);
	bool eventFilter(QObject *watched, QEvent *event);

private:
	QString makeImgPath(const ButtonColor &color, const ButtonStyle &style);

private slots:
	void changeImgPath();
};

#endif // DRAGBUTTON_H