#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("TCPServer");
	resize(600, 600);
    ui->bt_send->setEnabled(false);
    ui->bt_file->setEnabled(false);
    ui->line_server_ip->setEnabled(false);
    ui->line_client_ip->setEnabled(false);
    ui->line_client_port->setEnabled(false);
	ui->line_server_port->setValidator(new QIntValidator(0, 65535, this));	//端口号验证
    ui->text_recv->setFont(QFont("Helvetica", 15, QFont::Normal));
    ui->text_send->setFont(QFont("Helvetica", 15, QFont::Normal));
	ui->text_recv->setReadOnly(true);
	ui->text_send->installEventFilter(this);
    ui->progress_bar->setEnabled(false);
    ui->progress_bar->setValue(0);

	this->tcp_server = new QTcpServer(this);
	this->tcp_socket = nullptr;
    this->id = new QTimer(this);
	this->file_flag = false;
	this->recv_size = 0;

	SetServerIP();

	connect(this->tcp_server, &QTcpServer::newConnection, this, &Widget::Connect);	//连接成功
    connect(this, &Widget::CtrlEnter, this, &Widget::on_bt_send_clicked);           //自定义信号 发送数据
	connect(this->id, &QTimer::timeout, this, [ = ]()                               //发送文件
    {
        this->id->stop();
        SendFile();
    });
}

Widget::~Widget()
{
	delete ui;
}

//窗口关闭事件
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
				emit CtrlEnter();	//发送自定义信号 调用on_bt_send_clicked槽函数
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

	if(ui->line_server_ip->text().isEmpty())
	{
		QMessageBox::critical(this, "Error", "No network");
		exit(-1);
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
    ui->text_recv->setText("Wait for client to connect......");
    ui->line_server_port->setEnabled(false);
    ui->bt_listen->setEnabled(false);
}

//连接成功
void Widget::Connect()
{
	//得到通信套接字
	this->tcp_socket = this->tcp_server->nextPendingConnection();

	//设置tcp_socket信号与槽函数
    connect(this->tcp_socket, &QTcpSocket::readyRead, this, &Widget::Receive);          //接收数据
	connect(this->tcp_socket, &QTcpSocket::disconnected, this, &Widget::Disconnect);	//接收数据
    void (QTcpSocket::*signal)(QAbstractSocket::SocketError) = &QTcpSocket::error;
    void (Widget::*slot)(QAbstractSocket::SocketError) = &Widget::Error;
    connect(this->tcp_socket, signal, this, slot);                                      //连接出错

	//获取客户端信息
	QString ip = this->tcp_socket->peerAddress().toString();
	quint16 port = this->tcp_socket->peerPort();

	//显示
    ui->text_recv->setTextColor(Qt::green);
    ui->text_recv->setText("Client connection is successful");
	ui->line_client_ip->setText(ip);
	ui->line_client_port->setText(QString::number(port));

    //按钮可用
	ui->bt_send->setEnabled(true);
    ui->bt_file->setEnabled(true);
    ui->progress_bar->setEnabled(true);
}

//连接出错
void Widget::Error(QAbstractSocket::SocketError)
{
	if(this->tcp_socket->error() == QAbstractSocket::RemoteHostClosedError)
    {
        return;
    }

    ui->text_recv->setTextColor(Qt::red);
    ui->text_recv->append(this->tcp_socket->errorString());
    ui->bt_send->setEnabled(false);
    ui->bt_file->setEnabled(false);
    ui->progress_bar->setEnabled(false);
	ui->progress_bar->setValue(0);
}

//客户端主动断开连接
void Widget::Disconnect()
{
    this->tcp_socket = nullptr;
    ui->text_recv->setTextColor(Qt::red);
    ui->text_recv->append("Client disconnected");
    ui->line_client_ip->setText("");
    ui->line_client_port->setText("");
    ui->bt_send->setEnabled(false);
    ui->bt_file->setEnabled(false);
    ui->progress_bar->setEnabled(false);
	ui->progress_bar->setValue(0);
}

//接收数据
void Widget::Receive()
{
    //一次性读完
    QByteArray buf = this->tcp_socket->readAll();

    //是文件头
    if(buf.startsWith("Send file information"))
    {
        //获取文件信息
		this->file_flag = true;
		this->recv_file_name_size = QString(buf).section(QRegExp("[()]"), 3, 3);
		this->recv_file_name = QString(this->recv_file_name_size).section(',', 0, 0);
		this->recv_file_size = QString(this->recv_file_name_size).section(',', 1, 1).toInt();

        //打开文件
        this->recv_file.setFileName(this->recv_file_name);
        if(!this->recv_file.open(QIODevice::WriteOnly))
        {
            ui->text_recv->setTextColor(Qt::red);
            ui->text_recv->append("Fail to open the file");
            this->recv_file.close();
            return;
        }

		//显示
		QString head = QString("Receive file information: (name, size) = (%1, %2)").
					   arg(this->recv_file_name).arg(this->recv_file_size);
        ui->text_recv->setTextColor(Qt::black);
        ui->text_recv->append(head);
    }
    //不是文件头
    else
    {
        //是文件
        if(this->file_flag)
        {
            //写文件
			qint64 len = this->recv_file.write(buf);
			this->recv_size += len;
			ui->progress_bar->setValue((double(this->recv_size) /
										double(this->recv_file_size)) * 100);
			if(this->recv_size == this->recv_file_size)
            {
				this->file_flag = false;
				this->recv_size = 0;
                this->recv_file.close();
                ui->text_recv->setTextColor(Qt::black);
                ui->text_recv->append("File received successfully");
            }
        }
        //不是文件
        else
        {
            ui->text_recv->setTextColor(Qt::black);
            ui->text_recv->append(buf);
        }
    }
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

//打开文件 发送文件信息
void Widget::on_bt_file_clicked()
{
    //得到文件路径
	QString path = QFileDialog::getOpenFileName(this, "Open", "/");
    if(path.isEmpty())
    {
        ui->text_recv->setTextColor(Qt::red);
        ui->text_recv->append("File path error");
        return;
    }

    //获取文件信息
    QFileInfo info(path);
	QString file_name = info.fileName();
	this->send_file_size = info.size();

    //打开文件
    this->send_file.setFileName(path);
    if(!this->send_file.open(QIODevice::ReadOnly))
    {
        ui->text_recv->setTextColor(Qt::red);
        ui->text_recv->append("Fail to open the file");
        this->send_file.close();
        return;
    }

	//发送文件时禁止发送文本
	ui->bt_send->setEnabled(false);

    //发送文件信息
	QString head = QString("Send file information: (name, size) = (%1, %2)").
				   arg(file_name).arg(this->send_file_size);
	qint64 len = this->tcp_socket->write(head.toUtf8().data());
    if(!len)
    {
        ui->text_recv->setTextColor(Qt::red);
        ui->text_recv->append("Failed to send file information");
        this->send_file.close();
		ui->bt_send->setEnabled(true);
        return;
    }
    ui->text_recv->setTextColor(Qt::black);
    ui->text_recv->append(head);

    //防止TCP粘包问题 使用定时器延时1000ms 之后发送文件
    this->id->start(1000);
}

//发送文件
void Widget::SendFile()
{
    //初始化
	qint64 len = 0;
	qint64 send_size = 0;
    char buf[BUFSIZ];

    //边读边写
    do
    {
		memset(buf, 0, BUFSIZ);
		len = this->send_file.read(buf, BUFSIZ);
		len = this->tcp_socket->write(buf, len);
		send_size += len;
		ui->progress_bar->setValue((double(send_size) /
									double(this->send_file_size)) * 100);
	} while(len);

    //全部写完
	if(send_size != this->send_file_size)
    {
        ui->text_recv->setTextColor(Qt::red);
        ui->text_recv->append("File sending failed");
        this->send_file.close();
		ui->bt_send->setEnabled(true);
        return;
    }
    this->send_file.close();
    ui->text_recv->setTextColor(Qt::black);
    ui->text_recv->append("File sent successfully");
	ui->bt_send->setEnabled(true);
}
