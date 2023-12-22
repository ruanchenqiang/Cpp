#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i = 1; i <= 10; ++i)
    {
        DragButton *btn = new DragButton(ui->label);

        btn->setText(QString::number(i));
        btn->setGeometry(5 + (i - 1) * 55, 5, 50, 50);
        button.push_back(btn);
    }

    connect(ui->circleButton, SIGNAL(clicked(bool)), this, SLOT(circleButtonClicked()));
    connect(ui->squareButton, SIGNAL(clicked(bool)), this, SLOT(squareButtonClicked()));
    connect(ui->triangleButton, SIGNAL(clicked(bool)), this, SLOT(triangleButtonClicked()));

    connect(ui->blackButton, SIGNAL(clicked(bool)), this, SLOT(blackButtonClicked()));
    connect(ui->greenButton, SIGNAL(clicked(bool)), this, SLOT(greenButtonClicked()));
    connect(ui->redButton, SIGNAL(clicked(bool)), this, SLOT(redButtonClicked()));

    connect(ui->moveCheckBox, SIGNAL(stateChanged(int)), this, SLOT(moveCheckBoxStateChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButtonStyle(const DragButton::ButtonStyle &style)
{
    foreach (DragButton *btn, button)
    {
        btn->setStyle(style);
    }
}

void Widget::setButtonColor(const DragButton::ButtonColor &color)
{
    foreach (DragButton *btn, button)
    {
        btn->setColor(color);
    }
}

void Widget::setButtonDrag(bool drag)
{
    foreach (DragButton *btn, button)
    {
        btn->setDragEnable(drag);
    }
}

void Widget::circleButtonClicked()
{
    this->setButtonStyle(DragButton::ButtonStyle::CIRCLE);
}

void Widget::squareButtonClicked()
{
    this->setButtonStyle(DragButton::ButtonStyle::SQUARE);
}

void Widget::triangleButtonClicked()
{
    this->setButtonStyle(DragButton::ButtonStyle::TRIANGLE);
}

void Widget::blackButtonClicked()
{
    this->setButtonColor(DragButton::ButtonColor::BLACK);
}

void Widget::greenButtonClicked()
{
    this->setButtonColor(DragButton::ButtonColor::GREEN);
}

void Widget::redButtonClicked()
{
    this->setButtonColor(DragButton::ButtonColor::RED);
}

void Widget::moveCheckBoxStateChanged(int state)
{
    bool drag = (state != 0);

    this->setButtonDrag(drag);
}
