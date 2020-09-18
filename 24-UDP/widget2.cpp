#include "widget2.h"
#include "ui_widget2.h"

Widget2::Widget2(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::Widget2)
{
	ui->setupUi(this);

	setWindowTitle("UDP:8888");
	ui->line_ip->setText("127.0.0.1");
	ui->line_port->setText("6666");

	this->udp_socket = new QUdpSocket(this);
	this->udp_socket->bind(QHostAddress::AnyIPv4, 8888);	//设定本端端口8888

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

Widget2::~Widget2()
{
	delete ui;
}

void Widget2::on_bt_send_clicked()
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

void Widget2::on_bt_close_clicked()
{
	close();
}
