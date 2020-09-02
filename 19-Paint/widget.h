#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>	//绘图
#include <QPen>		//画笔
#include <QBrush>	//画刷

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
	//重写绘图事件 在窗口绘图必须在绘图事件中实现
	//当窗口重绘时 绘图事件自动调用
	void paintEvent(QPaintEvent* ev) override;

private slots:
	void on_pushButton_clicked();

private:
	Ui::Widget* ui;
	int x1, y1, x2, y2;
};
#endif // WIDGET_H
