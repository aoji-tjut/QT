#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
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
	void mouseMoveEvent(QMouseEvent* ev) override;			//鼠标移动
	void leaveEvent(QEvent* ev) override;					//离开
	bool event(QEvent* ev) override;						//事件分发

signals:

};

#endif // MYLABEL_H
