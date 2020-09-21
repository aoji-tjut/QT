#ifndef WIDGET_H
#define WIDGET_H

#include "thread1.h"
#include "thread2.h"
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QCloseEvent>
#include <QThread>	//线程
#include <QMutex>   //互斥锁

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

signals:
	void WidgetSignal();	//用于调用Thread2线程处理函数

protected:
	void closeEvent(QCloseEvent* ev) override;

private slots:
	void on_bt_sleep_clicked();
	void on_bt_thread1_clicked();
	void on_bt_thread2_clicked();
	void on_bt_stop1_clicked();
	void on_bt_stop2_clicked();

private:
	Ui::Widget* ui;

	QTimer* id;
	int num;

	Thread1* thread1;

	Thread2* thread2;
	QThread* qthread;

	QMutex* mutex;
};
#endif // WIDGET_H
