#include "widget1.h"
#include "ui_widget1.h"

Widget1::Widget1(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget1)
{
	ui->setupUi(this);

	setWindowTitle("UDP:6666");
	ui->line_ip->setText("127.0.0.1");
	ui->line_port->setText("8888");

	this->udp_socket = new QUdpSocket(this);
	this->udp_socket->bind(QHostAddress::AnyIPv4, 6666);	//设定本端端口6666

	//组播(群聊) 必须是D类ip地址
	this->udp_socket->joinMulticastGroup(QHostAddress("224.0.0.1"));	//加入
	this->udp_socket->leaveMulticastGroup(QHostAddress("224.0.0.1"));	//离开

	connect(this->udp_socket, &QUdpSocket::readyRead, this, [ = ]()
	{
		char buf[BUFSIZ] = {0};
		QHostAddress ip;
		quint16 port;
		qint64 len = this->udp_socket->readDatagram(
						 buf, sizeof(buf), &ip, &port);	//获取文字、对方ip、对方端口

		if(len)
		{
			QString text = QString("[%1 @ %2]: %3").arg(ip.toString()).arg(port).arg(buf);
			ui->text_recv->append(text);
		}
	});
}

Widget1::~Widget1()
{
	delete ui;
}

void Widget1::on_bt_send_clicked()
{
	//获取对方ip、端口
	QString ip = ui->line_ip->text();
	quint16 port = ui->line_port->text().toUInt();

	//获取发送内容
	QString text = ui->text_send->toPlainText();

	//发送数据
	this->udp_socket->writeDatagram(text.toUtf8(), QHostAddress(ip), port);

	//本地处理
	ui->text_recv->append("[local host] : " + text);
	ui->text_send->setText("");
}

void Widget1::on_bt_close_clicked()
{
	close();
}
