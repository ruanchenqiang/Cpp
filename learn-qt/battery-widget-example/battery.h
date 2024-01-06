#ifndef BATTERY_H
#define BATTERY_H

#include <QTimer>
#include <QWidget>

class Battery : public QWidget
{
	Q_OBJECT

public:
	enum class SliderDirection
	{
		LEFT,
		RIGHT,
	};

private:
	// 动画开关
	bool animationEnable;

	// 电量值
	double value;
	// 电量最小值
	double minValue;
	// 电量最大值
	double maxValue;
	// 电量告警值
	double alarmValue;
	// 动画电量
	double animationValue;

	// 方向
	SliderDirection direction;

	// 电池边框左上点的横纵坐标
	double borderTopLeftX;
	double borderTopLeftY;
	// 电池边框右下点的横纵坐标
	double borderBottomRightX;
	double borderBottomRightY;
	// 电池边框
	QRectF border;
	// 电池头部
	QRectF head;

	// 动画定时器
	QTimer *timer;

public:
	explicit Battery(QWidget *parent = nullptr);
	~Battery();

public:
	bool getAnimationEnable();
	void setAnimationEnable(bool enable);

	double getAlarmValue();
	void setAlarmValue(double value);

	double getValue();
	void setValue(double value);

protected:
	void paintBorder(QPainter &painter);
	void paintBody(QPainter &painter);
	void paintHead(QPainter &painter);
	void paintValue(QPainter &painter);
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);

private:
	void setTimerStart();
	void setTimerStop();

private slots:
	void changeAnimationValue();
};

#endif // BATTERY_H