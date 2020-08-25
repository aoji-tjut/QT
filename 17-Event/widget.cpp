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
	this->TimerID = this->startTimer(500);	//启动定时器 1000ms为间隔 返回定时器ID
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
		killTimer(this->TimerID);
		ui->timer_label->setText(QString("Kill Timer"));
	}
}

Widget::~Widget()
{
	delete ui;
}
