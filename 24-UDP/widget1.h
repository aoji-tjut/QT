#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include <QString>
#include <QUdpSocket>   //UDP通信套接字

QT_BEGIN_NAMESPACE
namespace Ui { class Widget1; }
QT_END_NAMESPACE

class Widget1 : public QWidget
{
	Q_OBJECT

public:
	Widget1(QWidget* parent = nullptr);
	~Widget1();

private slots:
	void on_bt_send_clicked();
	void on_bt_close_clicked();

private:
	Ui::Widget1* ui;
	QUdpSocket* udp_socket;
};
#endif // WIDGET1_H
