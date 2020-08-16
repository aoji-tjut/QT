#include "widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
{
	setWindowTitle("Main Window");
	resize(600, 400);

	b_sub = new QPushButton(this);
	b_sub->setText("Sub");
	b_sub->resize(100, 50);
	b_sub->move(100, 150);

	b_close.setParent(this);
	b_close.setText("Close");
	b_close.resize(100, 50);
	b_close.move(400, 150);

	//信号处理
	//信号发出者 信号名 信号接收者 槽函数名
	connect(b_sub, &QPushButton::released, this, &Widget::MainToSub);
	connect(&b_close, &QPushButton::released, this, &Widget::close);
	//传参区分重载信号与槽函数 信号与槽函数参数要一一对应
	connect(&sw, SIGNAL(Signal()), this, SLOT(DealSignal()));
	connect(&sw, SIGNAL(Signal(QString)), this, SLOT(DealSignal(QString)));
}

//自定义槽函数
void Widget::MainToSub()
{
	this->hide();
	sw.show();
}

//自定义槽函数
void Widget::DealSignal()
{
	sw.hide();
	this->show();
}

//自定义槽函数
void Widget::DealSignal(QString str)
{
	qDebug() << str.toUtf8().data() << endl;
}

Widget::~Widget()
{
}
