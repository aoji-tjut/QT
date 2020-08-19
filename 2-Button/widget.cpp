#include "widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
{
	//this是父窗口

	setWindowTitle("Button");	//相当于调用this->setWindowTitle()
	resize(600, 400);			//相当于调用this->resize()

	//按钮
	b1.setParent(this);     //指定按钮的父对象
	b1.setText("Button1");	//按钮内容
	b1.resize(100, 50);     //按钮大小
	b1.move(100, 150);      //移动按钮

	b2 = new QPushButton(this);		//指定按钮的父对象
	b2->setText("Button2");
	b2->resize(100, 50);
	b2->move(400, 150);
}

Widget::~Widget()
{
}
