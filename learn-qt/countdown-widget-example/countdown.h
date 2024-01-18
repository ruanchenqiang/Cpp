#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QTimer>
#include <QWidget>

class Countdown : public QWidget
{
	Q_OBJECT

private:
	// 倒计时
	int countdown;

	// X边框
	QRectF xRect;
	// 倒计时边框
	QRectF countdownRect;

	// 定时器间隔
	int interval;
	// 累计间隔
	int millisecond;

	// 起始角度
	double startAngle;
	// 跨度
	double spanAngle;
	// 步长
	double stepAngle;

	// 鼠标点击位置
	QPoint lastPoint;

	// 是否第一次悬停
	bool isFirstEnter;

	// 动画计时器
	QTimer *timer;

public:
	explicit Countdown(QWidget *parent = nullptr);
	~Countdown();

protected:
	void paintX(QPainter &painter);
	void paintCountdown(QPainter &painter);
	void paintProgressBar(QPainter &painter);
	void paintEvent(QPaintEvent *event);

	bool event(QEvent *event);
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	void setTimerStart();
	void setTimerStop();

private slots:
	void changeProgress();
};

#endif // COUNTDOWN_H