#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  //QWidget窗口类

class Widget : public QWidget
{
    Q_OBJECT    //Q_OBJECT宏 允许类中使用信号和槽机制


public:
	Widget(QWidget* parent = nullptr);  //构造 默认空指针
    ~Widget();  //析构
};
#endif // WIDGET_H
