#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget* parent = nullptr);

protected:
	//重写事件虚函数
	void mousePressEvent(QMouseEvent* ev) override;			//鼠标按下
	void mouseReleaseEvent(QMouseEvent* ev) override;		//鼠标抬起
	void mouseDoubleClickEvent(QMouseEvent* ev) override;	//鼠标双击
	void mouseMoveEvent(QMouseEvent* ev) override;			//鼠标移动
	void leaveEvent(QEvent* ev) override;					//离开
	//eventFilter()->event()->override...
	bool event(QEvent* ev) override;						//事件分发
	bool eventFilter(QObject* obj, QEvent* ev) override;	//事件过滤

signals:

};

#endif // MYLABEL_H
