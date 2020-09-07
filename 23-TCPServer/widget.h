#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QIntValidator>        //数字限制
#include <QTcpServer>           //监听套接字
#include <QTcpSocket>           //通信套接字
#include <QNetworkInterface>    //主机网络

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

	void SetServerIP();

protected:
	void closeEvent(QCloseEvent* ev) override;
	bool eventFilter(QObject* obj, QEvent* ev) override;

private slots:
	void Connect();
	void Disconnect(QAbstractSocket::SocketError);
	void Receive();
	void on_bt_send_clicked();
	void on_bt_close_clicked();
	void on_bt_listen_clicked();

private:
	Ui::Widget* ui;
	QTcpServer* tcp_server;
	QTcpSocket* tcp_socket;
};
#endif // WIDGET_H
