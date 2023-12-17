#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QWidget(parent), ui(new UI::Login)
{
	ui->setupUI(this);
}

Login::~Login()
{
	delete ui;
}