#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("TCPClient");
	ui->bt_disconnect->setEnabled(false);
    ui->bt_send->setEnabled(false);
    QRegExp rx("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.)"
			   "{3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");	//IP正则表达式
	ui->line_ip->setValidator(new QRegExpValidator(rx, this));		//IP验证
	ui->line_ip->setPlaceholderText("127.0.0.1");
	ui->line_port->setValidator(new QIntValidator(0, 65535, this));	//端口号验证
    ui->text_recv->setFont(QFont("Helvetica", 15, QFont::Normal));
    ui->text_send->setFont(QFont("Helvetica", 15, QFont::Normal));
	ui->text_recv->setReadOnly(true);
	ui->text_send->installEventFilter(this);

	this->tcp_socket = new QTcpSocket(this);

	connect(this->tcp_socket, &QTcpSocket::connected, this, &Widget::Connect);	//连接成功
	connect(this->tcp_socket, &QTcpSocket::readyRead, this, &Widget::Receive);	//接收数据
    connect(this, &Widget::CtrlEnter, this, &Widget::on_bt_send_clicked);       //自定义信号 发送数据
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
				emit CtrlEnter();	//发送自定义信号 调用on_bt_send_clicked槽函数
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
    quint16 port;
    if(ui->line_ip->text().isEmpty())
    {
        ip = "127.0.0.1";
    }
    else
    {
        ip = ui->line_ip->text();
    }
    port = ui->line_port->text().toUInt();

	//尝试建立连接 连接成功发送QTcpSocket::connected信号
	this->tcp_socket->connectToHost(QHostAddress(ip), port);
}

//连接成功
void Widget::Connect()
{
    ui->text_recv->setTextColor(Qt::green);
    ui->text_recv->setText("Successfully connected to the server");
    ui->line_ip->setEnabled(false);
    ui->line_port->setEnabled(false);
	ui->bt_connect->setEnabled(false);
	ui->bt_disconnect->setEnabled(true);
    ui->bt_send->setEnabled(true);
}

//主动断开连接
void Widget::on_bt_disconnect_clicked()
{
	this->tcp_socket->disconnectFromHost();
	this->tcp_socket->close();

    ui->text_recv->setTextColor(Qt::red);
    ui->text_recv->append("Disconnect from server");
    ui->line_ip->setEnabled(true);
    ui->line_port->setEnabled(true);
	ui->bt_connect->setEnabled(true);
	ui->bt_disconnect->setEnabled(false);
    ui->bt_send->setEnabled(false);
}

//接收数据
void Widget::Receive()
{
	QByteArray text = this->tcp_socket->readAll();
	ui->text_recv->setTextColor(Qt::black);
	ui->text_recv->append(text);
}

//发送数据
void Widget::on_bt_send_clicked()
{
	QString text = ui->text_send->toPlainText();
	if(text.isEmpty())
	{
		QMessageBox::warning(this, "Warning", "Cannot send empty message");
		return;
	}

	this->tcp_socket->write(text.toUtf8().data());
	ui->text_recv->setTextColor(Qt::black);
	ui->text_recv->append(text);
	ui->text_send->setText("");
}

//关闭窗口
void Widget::on_bt_close_clicked()
{
	close();	//触发closeEvent
}
