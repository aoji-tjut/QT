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

	//信号处理 信号可以连接槽函数也可以连接信号
	//信号与槽函数参数类型要一一对应 参数个数可以信号>槽函数
	//参数：信号发送者 信号名 信号接收者 槽函数名(信号名)
	connect(b_sub, &QPushButton::clicked, this, &Widget::MainToSub);
	connect(&b_close, &QPushButton::clicked, this, &Widget::close);
	//传参区分重载信号与槽函数
	void (SubWidget::*p_signal)() = &SubWidget::Signal;
	void (SubWidget::*q_signal)(QString) = &SubWidget::Signal;
	void (Widget::*p_slot)() = &Widget::Slot;
	void (Widget::*q_slot)(QString) = &Widget::Slot;
	connect(&sw, p_signal, this, p_slot);
	connect(&sw, q_signal, this, q_slot);
	//QT4 依然可用 不安全
	//connect(&sw, SIGNAL(Signal()), this, SLOT(Slot()));
	//connect(&sw, SIGNAL(Signal(QString)), this, SLOT(Slot(QString)));
}

//自定义槽函数
void Widget::MainToSub()
{
	this->hide();
	sw.show();
}

//自定义槽函数
void Widget::Slot()
{
	sw.hide();
	this->show();
}

//自定义槽函数
void Widget::Slot(QString str)
{
	qDebug() << str.toUtf8().data() << endl;
}

Widget::~Widget()
{
}
