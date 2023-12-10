#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QWidget>

class UI_Widget
{
public:
	void setupUI(QWidget *w);
	void retranslateUI(QWidget *w);
};

namespace UI
{
	class Widget : public UI_Widget
	{
	};
} // namespace UI

#endif // UI_WIDGET_H