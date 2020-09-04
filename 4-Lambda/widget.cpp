#include "widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
{
	setWindowTitle("Lambda");
	resize(600, 400);

	b = new QPushButton(this);
	b->setText("Button");
	b->resize(100, 50);
	b->move(250, 200);

	//lambda结合信号
	connect(b, &QPushButton::clicked, this, []() {qDebug() << "Lambda" << endl;});
}

Widget::~Widget()
{
}

