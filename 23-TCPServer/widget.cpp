#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("TCPServer");
	ui->line_server_ip->setReadOnly(true);
	ui->line_client_ip->setReadOnly(true);
	ui->line_client_port->setReadOnly(true);
	ui->line_server_port->setValidator(new QIntValidator(1, 65535, this));	//端口号范围
	ui->bt_send->setEnabled(false);
	ui->text_recv->setReadOnly(true);
	ui->text_send->installEventFilter(this);

	this->tcp_server = new QTcpServer(this);
	this->tcp_socket = nullptr;

	SetServerIP();

	connect(this->tcp_server, &QTcpServer::newConnection, this, &Widget::Connect);	//连接成功
}

Widget::~Widget()
{
	delete ui;
}

//窗口关闭事件 点击叉子 同点击Close
void Widget::closeEvent(QCloseEvent* ev)
{
	if(QMessageBox::question(this, "Close", "Close Server?") == QMessageBox::No)
	{
		ev->ignore();
		return;
	}

	//连接成功后需要关闭套接字
	if(this->tcp_socket)
	{
		this->tcp_socket->disconnectFromHost();
		this->tcp_socket->close();
	}
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

//获取本地IP
void Widget::SetServerIP()
{
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
	QString ip;
	for (QHostAddress address : list)
	{
		if(address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			ip = address.toString();
			if(ip == "127.0.0.1")
			{
				continue;
			}
			ui->line_server_ip->setText(ip);
		}
	}
}

//监听
void Widget::on_bt_listen_clicked()
{
	if(ui->line_server_port->text().isEmpty())
	{
		QMessageBox::warning(this, "Warning", "Enter Server Port");
		return;
	}

	this->tcp_server->listen(QHostAddress::AnyIPv4, ui->line_server_port->text().toUInt());
	ui->text_recv->setText("等待客户端连接......");
	ui->bt_listen->setEnabled(false);
	ui->line_server_port->setReadOnly(true);
}

//连接成功
void Widget::Connect()
{
	//得到通信套接字
	this->tcp_socket = this->tcp_server->nextPendingConnection();

	//设置tcp_socket信号与槽函数
	connect(this->tcp_socket, &QTcpSocket::readyRead, this, &Widget::Receive);	//接收数据
	void (QTcpSocket::*signal)(QAbstractSocket::SocketError) = &QTcpSocket::error;
	void (Widget::*slot)(QAbstractSocket::SocketError) = &Widget::Disconnect;
	connect(this->tcp_socket, signal, this, slot);								//连接出错

	//获取客户端信息
	QString ip = this->tcp_socket->peerAddress().toString();
	quint16 port = this->tcp_socket->peerPort();

	//显示
	ui->text_recv->setText("客户端连接成功");
	ui->line_client_ip->setText(ip);
	ui->line_client_port->setText(QString::number(port));

	//发送按钮可用
	ui->bt_send->setEnabled(true);
}

//客户端主动断开连接
void Widget::Disconnect(QAbstractSocket::SocketError)
{
	if(this->tcp_socket->error() == QAbstractSocket::RemoteHostClosedError)
	{
		this->tcp_socket = nullptr;
		ui->text_recv->append("客户端断开连接");
		ui->line_client_ip->setText("");
		ui->line_client_port->setText("");
		ui->bt_send->setEnabled(false);
	}
	else
	{
		ui->text_recv->append(this->tcp_socket->errorString());
	}
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
