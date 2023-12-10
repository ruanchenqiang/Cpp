#ifndef WIDGET_H
#define WIDGET_H

#include <QPaintEvent>
#include <QTimerEvent>
#include <QVector>
#include <QWidget>

#include "letterrain.h"

namespace UI
{
	class Widget;
}

class Widget : public QWidget
{
public:
	explicit Widget(QWidget *parent = nullptr);
	~Widget();

protected:
	void paintEvent(QPaintEvent *event) override;
	void timerEvent(QTimerEvent *event) override;

private:
	UI::Widget *ui;
	QVector<LetterRain> m_letter_rain;
	int m_timer_id;
};

#endif // WIDGET_H