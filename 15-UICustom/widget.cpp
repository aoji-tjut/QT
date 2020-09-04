#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("UICustom");
	setFixedSize(600, 400);
}

Widget::~Widget()
{
	delete ui;
}

