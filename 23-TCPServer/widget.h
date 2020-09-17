#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QValidator>           //验证器
#include <QNetworkInterface>    //主机网络
#include <QTcpServer>           //监听套接字
#include <QTcpSocket>           //通信套接字
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>

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
    void SendFile();

protected:
	void closeEvent(QCloseEvent* ev) override;
	bool eventFilter(QObject* obj, QEvent* ev) override;

signals:
    void CtrlEnter();

private slots:
	void Connect();
    void Disconnect();
    void Error(QAbstractSocket::SocketError);
	void Receive();
    void on_bt_listen_clicked();
	void on_bt_send_clicked();
    void on_bt_file_clicked();

private:
	Ui::Widget* ui;
	QTcpServer* tcp_server;			//监听套接字
	QTcpSocket* tcp_socket;			//通信套接字
	QTimer* id;						//定时器

	QFile send_file;				//发送的文件对象
	qint64 send_file_size;			//已发送的文件大小

	QFile recv_file;				//接收的文件对象
	QString recv_file_name_size;	//接收的文件名+大小
	QString recv_file_name;			//接收的文件名
	qint64 recv_file_size;			//接收的文件大小
	qint64 recv_size;				//已接收的文件大小

	bool file_flag;					//是否为文件的标记
};
#endif // WIDGET_H
