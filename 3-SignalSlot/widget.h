#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "subwidget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

private slots:	//槽函数关键字 自定义槽函数
	//槽函数 对接收的信号进行处理 返回值void 可以有参数 需要实现 可以重载
	void MainToSub();
	void Slot();
	void Slot(QString);

private:
	SubWidget sw;
	QPushButton* b_sub;
	QPushButton b_close;
};

#endif // WIDGET_H
