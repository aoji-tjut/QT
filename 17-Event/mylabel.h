#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget* parent = nullptr);

protected:
	//重写事件虚函数
	void mousePressEvent(QMouseEvent* ev) override;
	void mouseReleaseEvent(QMouseEvent* ev) override;
	void mouseMoveEvent(QMouseEvent* ev) override;
	void leaveEvent(QEvent* ev) override;

signals:

};

#endif // MYLABEL_H
