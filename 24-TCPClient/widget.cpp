#include "widget.h"
#include "ui_widget.h"
#include <QValidator>

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("TCPClient");
	ui->bt_send->setEnabled(false);
	ui->bt_disconnect->setEnabled(false);
	ui->line_ip->setPlaceholderText("127.0.0.1");
	ui->text_recv->setReadOnly(true);
	ui->text_send->installEventFilter(this);

	this->tcp_socket = new QTcpSocket(this);

	connect(this->tcp_socket, &QTcpSocket::connected, this, &Widget::Connect);	//连接成功
	connect(this->tcp_socket, &QTcpSocket::readyRead, this, &Widget::Receive);	//接收数据
}

Widget::~Widget()
{
	delete ui;
}

//关闭窗口事件点击叉子 同点击Close
void Widget::closeEvent(QCloseEvent* ev)
{
	if(QMessageBox::question(this, "Close", "Close Client?") == QMessageBox::No)
	{
		ev->ignore();
		return;
	}

	this->tcp_socket->disconnectFromHost();
	this->tcp_socket->close();
}

//事件过滤 Ctrl+Enter发送
bool Widget::eventFilter(QObject* obj, QEvent* ev)
{
	if(obj == ui->text_send)
	{
		if(ev->type() == QEvent::KeyPress)
		{
			QKeyEvent* e = static_cast<QKeyEvent*>(ev);
			if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_Return &&
					ui->bt_send->isEnabled())
			{
				on_bt_send_clicked();
				return true;
			}
		}
	}

	return QWidget::eventFilter(obj, ev);
}

//尝试连接
void Widget::on_bt_connect_clicked()
{
	if(ui->line_port->text().isEmpty())
	{
		QMessageBox::warning(this, "Warning", "Enter Port");
		return;
	}

	//获取服务器信息
	QString ip;
	if(ui->line_ip->text().isEmpty())
	{
		ip = "127.0.0.1";
	}
	else
	{
		ip = ui->line_ip->text();
	}
	quint16 port = ui->line_port->text().toUInt();

	//尝试建立连接 连接成功发送QTcpSocket::connected信号
	this->tcp_socket->connectToHost(QHostAddress(ip), port);
}

//连接成功
void Widget::Connect()
{
	ui->text_recv->setText("与服务器连接成功");
	ui->bt_send->setEnabled(true);
	ui->bt_connect->setEnabled(false);
	ui->bt_disconnect->setEnabled(true);
}

//主动断开连接
void Widget::on_bt_disconnect_clicked()
{
	this->tcp_socket->disconnectFromHost();
	this->tcp_socket->close();

	ui->text_recv->append("与服务器断开连接");
	ui->bt_send->setEnabled(false);
	ui->bt_connect->setEnabled(true);
	ui->bt_disconnect->setEnabled(false);
}

//接收数据
void Widget::Receive()
{
	QByteArray text = this->tcp_socket->readAll();
	ui->text_recv->append(text);
}

//发送数据
void Widget::on_bt_send_clicked()
{
	QString text = ui->text_send->toPlainText();
	if(text.isEmpty())
	{
		return;
	}

	this->tcp_socket->write(text.toUtf8().data());
	ui->text_recv->append(text);
	ui->text_send->setText("");
}

//关闭窗口
void Widget::on_bt_close_clicked()
{
	close();	//触发closeEvent
}
