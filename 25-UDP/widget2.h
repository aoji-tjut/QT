#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QString>
#include <QUdpSocket>   //UDP通信套接字

namespace Ui {
	class Widget2;
}

class Widget2 : public QWidget
{
	Q_OBJECT

public:
	explicit Widget2(QWidget* parent = nullptr);
	~Widget2();

private slots:
	void on_bt_send_clicked();
	void on_bt_close_clicked();

private:
	Ui::Widget2* ui;
	QUdpSocket* udp_socket;
};

#endif // WIDGET2_H
