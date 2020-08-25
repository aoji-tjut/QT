#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
	void keyPressEvent(QKeyEvent* ev) override;
	void timerEvent(QTimerEvent* ev) override;

private:
	Ui::Widget* ui;
	int TimerID;
};
#endif // WIDGET_H
