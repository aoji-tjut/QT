#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
	Q_OBJECT
public:
	explicit SubWidget(QWidget* parent = nullptr);

public slots:	//槽函数关键字 自定义槽函数
	//槽函数 对接收的信号进行处理 返回值void 可以有参数 需要实现 可以重载
	void SubToMain();

private:
	QPushButton* b_main;
	QPushButton b_close;

signals:	//信号关键字 自定义信号
	//信号就是函数 返回值void 可以有参数 只需声明无需实现 可以重载
	void Signal();
	void Signal(QString);
};

#endif // SUBWIDGET_H
