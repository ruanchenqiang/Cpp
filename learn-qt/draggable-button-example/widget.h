#ifndef WIDGET_H
#define WIDGET_H

#include <QVector>
#include <QWidget>

#include "dragbutton.h"

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void setButtonStyle(const DragButton::ButtonStyle &style);
    void setButtonColor(const DragButton::ButtonColor &color);
    void setButtonDrag(bool drag);

private slots:
    void circleButtonClicked();
    void squareButtonClicked();
    void triangleButtonClicked();

    void blackButtonClicked();
    void greenButtonClicked();
    void redButtonClicked();

    void moveCheckBoxStateChanged(int state);

private:
    Ui::Widget *ui;
    QVector<DragButton *> button;
};

#endif // WIDGET_H
