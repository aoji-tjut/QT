#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>	//定时器

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

	void Timer();
	void ChangeState();

private:
	Ui::Widget* ui;
	QTimer* id;
	int state;
};
#endif // WIDGET_H
