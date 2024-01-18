#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    this->ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
