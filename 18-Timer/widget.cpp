#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("Timer");
	setFixedSize(600, 400);

	//label
	ui->label->setFont(QFont("Helvetica", 30, QFont::Normal));
	ui->label->setAlignment(Qt::AlignCenter);

	//button
	ui->pushButton->setText("暂停");
	connect(ui->pushButton, &QPushButton::clicked, this, &Widget::ChangeState);

	//定时器
	this->id = new QTimer(this);
	this->id->start(500);
	connect(this->id, &QTimer::timeout, this, &Widget::Timer);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::Timer()
{
	static int i = 0;
	ui->label->setText(QString("Timer\n%1").arg(++i));
}

void Widget::ChangeState()
{
	if(this->id->isActive())
	{
		this->id->stop();
		ui->pushButton->setText("继续");
		ui->pushButton->repaint();	//重绘
	}
	else
	{
		this->id->start(500);
		ui->pushButton->setText("暂停");
		ui->pushButton->repaint();	//重绘
	}
}
