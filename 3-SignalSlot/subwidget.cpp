#include "subwidget.h"

SubWidget::SubWidget(QWidget* parent) : QWidget(parent)
{
	setWindowTitle("Sub Window");
	resize(500, 300);

	b_main = new QPushButton(this);
	b_main->setText("Main");
	b_main->resize(100, 50);
	b_main->move(50, 150);

	b_close.setParent(this);
	b_close.setText("Close");
	b_close.resize(100, 50);
	b_close.move(350, 150);

	//信号处理
	//信号发出者 信号名 信号接收者 槽函数名
	connect(b_main, &QPushButton::released, this, &SubWidget::SubToMain);
	connect(&b_close, &QPushButton::released, this, &SubWidget::close);
}

//自定义槽函数
void SubWidget::SubToMain()
{
	//发送自定义信号
	emit Signal();
	emit Signal("重载信号");
}
