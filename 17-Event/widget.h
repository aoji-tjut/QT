#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

protected:
	//重写事件虚函数
	void keyPressEvent(QKeyEvent* ev) override;				//键盘
	void timerEvent(QTimerEvent* ev) override;				//定时器
	void closeEvent(QCloseEvent* ev) override;				//关闭窗口
	//拦截顺序:eventFilter->event eventFilter更好
	bool eventFilter(QObject* obj, QEvent* ev) override;	//事件过滤

private:
	Ui::Widget* ui;
	int id;
};
#endif // WIDGET_H
