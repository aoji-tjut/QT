#include "client.h"
#include "ui_client.h"

Client::Client(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Client)
{
	ui->setupUi(this);

	setWindowTitle("TCPClient");
	resize(600, 600);
	ui->bt_disconnect->setEnabled(false);
	ui->bt_send->setEnabled(false);
	ui->bt_file->setEnabled(false);
	QRegExp rx("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.)"
			   "{3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");	//IP正则表达式
	ui->line_ip->setValidator(new QRegExpValidator(rx, this));		//IP验证
	ui->line_ip->setPlaceholderText("127.0.0.1");
	ui->line_port->setValidator(new QIntValidator(0, 65535, this));	//端口号验证
	ui->text_recv->setFont(QFont("Helvetica", 15, QFont::Normal));
	ui->text_send->setFont(QFont("Helvetica", 15, QFont::Normal));
	ui->text_recv->setReadOnly(true);
	ui->text_send->installEventFilter(this);
	ui->progress_bar->setEnabled(false);
	ui->progress_bar->setValue(0);

	this->tcp_socket = new QTcpSocket(this);
	this->id = new QTimer(this);
	this->file_flag = false;
	this->recv_size = 0;

	connect(this->tcp_socket, &QTcpSocket::connected, this, &Client::Connect);	//连接成功
	connect(this->tcp_socket, &QTcpSocket::readyRead, this, &Client::Receive);	//接收数据
	connect(this, &Client::CtrlEnter, this, &Client::on_bt_send_clicked);       //自定义信号 发送数据
	connect(this->id, &QTimer::timeout, this, [ = ]()                           //发送文件
	{
		this->id->stop();
		SendFile();
	});
}

Client::~Client()
{
	delete ui;
}

//关闭窗口事件点击叉子 同点击Close
void Client::closeEvent(QCloseEvent* ev)
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
bool Client::eventFilter(QObject* obj, QEvent* ev)
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
void Client::on_bt_connect_clicked()
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
void Client::Connect()
{
	ui->text_recv->setTextColor(Qt::green);
	ui->text_recv->setText("Successfully connected to the server");
	ui->line_ip->setEnabled(false);
	ui->line_port->setEnabled(false);
	ui->bt_connect->setEnabled(false);
	ui->bt_disconnect->setEnabled(true);
	ui->bt_send->setEnabled(true);
	ui->bt_file->setEnabled(true);
	ui->progress_bar->setEnabled(true);
}

//主动断开连接
void Client::on_bt_disconnect_clicked()
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
	ui->bt_file->setEnabled(false);
	ui->progress_bar->setEnabled(false);
	ui->progress_bar->setValue(0);
}

//接收数据
void Client::Receive()
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
		this->recv_file.setFileName(recv_file_name);
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
void Client::on_bt_send_clicked()
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
void Client::on_bt_file_clicked()
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

	//防止TCP粘包问题 使用定时器延时100ms 之后发送文件
	this->id->start(100);
}

//发送文件
void Client::SendFile()
{
	//初始化
	qint64 len = 0;
	qint64 send_size = 0;
	char buf[BUFSIZ];
	ui->progress_bar->setValue(0);

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
		ui->text_recv->append("Failed to send file");
		this->send_file.close();
		ui->bt_send->setEnabled(true);
		return;
	}
	this->send_file.close();
	ui->text_recv->setTextColor(Qt::black);
	ui->text_recv->append("File sent successfully");
	ui->bt_send->setEnabled(true);
}
