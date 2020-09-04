#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("IrregularWindow");
	setFixedSize(400, 400);

	Image();

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint |
				   windowFlags());					//隐藏边框 窗口置顶
	setAttribute(Qt::WA_TranslucentBackground);		//隐藏背景
}

Widget::~Widget()
{
	delete ui;
}

//重写绘图事件
void Widget::paintEvent(QPaintEvent*)
{
	QPainter p;
	p.begin(this);
	p.drawPixmap(QRect(0, 0, 400, 200), QPixmap("./image.png"),
				 QRect(0, 0, 400, 200));	//只画上半部分
	p.end();
}

void Widget::Image()
{
	QPainter p;
	QBrush brush;
	QImage image(400, 400, QImage::Format_ARGB32);

	brush.setStyle(Qt::SolidPattern);

	//在image上绘图
	p.begin(&image);
	p.setRenderHint(QPainter::Antialiasing);

	brush.setColor(QColor(255, 0, 0));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 140, 140);

	brush.setColor(QColor(255, 97, 0));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 120, 120);

	brush.setColor(QColor(255, 255, 0));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 100, 100);

	brush.setColor(QColor(0, 255, 0));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 80, 80);

	brush.setColor(QColor(0, 255, 255));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 60, 60);

	brush.setColor(QColor(0, 0, 255));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 40, 40);

	brush.setColor(QColor(160, 32, 240));
	p.setBrush(brush);
	p.drawEllipse(QPoint(200, 200), 20, 20);

	p.end();

	image.save("./image.png");	//透明图必须为png
}

void Widget::mousePressEvent(QMouseEvent* ev)
{
	if(ev->button() == Qt::LeftButton)
	{
		this->pos = ev->globalPos() - this->frameGeometry().topLeft();
	}
}

void Widget::mouseDoubleClickEvent(QMouseEvent* ev)
{
	if(ev->button() == Qt::LeftButton)
	{
		exit(0);
	}
}

void Widget::mouseMoveEvent(QMouseEvent* ev)
{
	if(ev->buttons()& Qt::LeftButton)
	{
		move(ev->globalPos() - this->pos);
	}
}
