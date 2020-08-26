#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	//label设置
	ui->key_label->setFont(QFont("Helvetica", 30, QFont::Normal));
	ui->key_label->setAlignment(Qt::AlignCenter);
	ui->timer_label->setFont(QFont("Helvetica", 30, QFont::Normal));
	ui->timer_label->setAlignment(Qt::AlignCenter);

	//启动定时器
	this->id = this->startTimer(500);	//启动定时器 1000ms为间隔 返回定时器ID
}

//键盘按下
void Widget::keyPressEvent(QKeyEvent* ev)
{
	ui->key_label->setText(QString("Key Press\n%1").arg(char(ev->key())));
}

//定时器
void Widget::timerEvent(QTimerEvent* ev)
{
	static int i = 0;
	ui->timer_label->setText(QString("Timer\n%1").arg(++i));

	if(i > 10)
	{
		killTimer(this->id);
		ui->timer_label->setText(QString("Kill Timer"));
	}
}

//关闭
void Widget::closeEvent(QCloseEvent* ev)
{
	int ret = QMessageBox::question(this, "Question", "是否关闭窗口？");
	if(ret == QMessageBox::Yes)
	{
		ev->accept();	//接收事件
	}
	else
	{
		ev->ignore();	//忽略事件 继续传递给父窗口(不是父类)
	}
}

Widget::~Widget()
{
	delete ui;
}
