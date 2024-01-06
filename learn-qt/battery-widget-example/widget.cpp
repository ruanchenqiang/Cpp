#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    this->ui->setupUi(this);
    this->ui->horizontalSlider->setValue(20);

    connect(this->ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(int)));
    connect(this->ui->animationCheckBox, SIGNAL(stateChanged(int)), this, SLOT(animationCheckBoxStateChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setBatteryAnimation(bool animation)
{
    this->ui->battery->setAnimationEnable(animation);
}

void Widget::setBatteryValue(int value)
{
    this->ui->battery->setValue(value);
}

void Widget::animationCheckBoxStateChanged(int state)
{
    bool animation = (state != 0);

    this->setBatteryAnimation(animation);
}

void Widget::sliderValueChanged(int value)
{
    this->setBatteryValue(value);
}