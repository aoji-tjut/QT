#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QValidator>   //验证器
#include <QHostAddress> //ip地址
#include <QTcpSocket>   //通信套接字

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
	void closeEvent(QCloseEvent* ev) override;
	bool eventFilter(QObject* obj, QEvent* ev) override;

signals:
    void CtrlEnter();

private slots:
	void Connect();
	void Receive();
	void on_bt_connect_clicked();
    void on_bt_disconnect_clicked();
	void on_bt_send_clicked();
	void on_bt_close_clicked();

private:
	Ui::Widget* ui;
	QTcpSocket* tcp_socket;
};
#endif // WIDGET_H
