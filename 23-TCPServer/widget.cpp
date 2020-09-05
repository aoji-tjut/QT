#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("TCPServer");
	ui->text_recv->setReadOnly(true);
}

Widget::~Widget()
{
	delete ui;
}

