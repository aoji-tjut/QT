#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	qsrand(time(nullptr));
	x1 = qrand() % 400;
	y1 = qrand() % 400;
	x2 = qrand() % 400;
	y2 = qrand() % 400;
}

void Widget::paintEvent(QPaintEvent*)
{
	QPainter p;
	QPen pen;
	QBrush brush;

	//设置画笔
	pen.setColor(QColor(255, 0, 0));	//颜色 Qt::red
	pen.setWidth(3);					//宽度
	pen.setStyle(Qt::DashLine);			//风格

	//设置画刷
	brush.setColor(QColor(0, 0, 255));	//颜色
	brush.setStyle(Qt::Dense3Pattern);	//风格

	//开始画
	p.begin(this);											//开始绘图 指定绘图设备
	p.setPen(pen);											//设置画笔
	p.setBrush(brush);										//设置画刷
	p.drawPixmap(rect(), QPixmap(":/source/LiAo.jpeg"));	//背景
	p.drawLine(x1, y1, x2, y2);								//直线
	p.drawRect(50, 50, 300, 300);							//矩形
	p.drawEllipse(QPoint(200, 200), 100, 100);				//圆
	p.drawEllipse(QPoint(200, 200), 200, 100);				//椭圆
	p.drawEllipse(QPoint(200, 200), 100, 200);				//椭圆
	p.end();												//结束绘图
}

void Widget::on_pushButton_clicked()
{
	while(true)
	{
		x1 = qrand() % width();
		y1 = qrand() % height();
		x2 = qrand() % width();
		y2 = qrand() % height();

		if( abs(x1 - x2) > width() / 2 || abs(y1 - y2) > height() / 2)
		{
			break;
		}
	}

	update();	//间接触发绘图事件
}

Widget::~Widget()
{
	delete ui;
}
