#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	this->flag = 0;
	Pixmap();
	Bitmap();
	Image();
	Picture();
}

//重写绘图事件
void Widget::paintEvent(QPaintEvent*)
{
	QPainter p;
	QPixmap pixmap;
	QBitmap bitmap;
	QImage image;
	QPicture picture;

	//在窗口上绘图
	p.begin(this);
	switch (this->flag)
	{
		case 1:
			pixmap.load("./pixmap.jpg");
			p.drawPixmap(0, 0, pixmap.width(), pixmap.height(), pixmap);
			break;
		case 2:
			bitmap.load("./bitmap.jpg");
			p.drawPixmap(QRect(0, 0, bitmap.width(), bitmap.height()), bitmap);
			break;
		case 3:
			image.load("./image.jpg");
			p.drawImage(QRect(0, 0, image.width(), image.height()), image);
			break;
		case 4:
			picture.load("./picture.jpg");
			p.drawPicture(QPoint(0, 0), picture);
		default:
			break;
	}
	p.end();
}

//针对屏幕优化 与平台相关 不能对图片进行修改
void Widget::Pixmap()
{
	QPainter p;
	QPixmap pixmap(400, 400);

	//在pixmap上绘图
	p.begin(&pixmap);
	p.drawPixmap(QRect(0, 0, 400, 400), QPixmap(":/source/LiAo.jpeg"));
	p.end();

	pixmap.save("./pixmap.jpg");	//保存图片
}

//Pixmap子类 只能绘制灰度图
void Widget::Bitmap()
{
	QPainter p;
	QBitmap bitmap(400, 400);

	//在bitmap上绘图
	p.begin(&bitmap);
	p.drawPixmap(QRect(0, 0, 400, 400), QBitmap(":/source/LiAo.jpeg"));
	p.end();

	bitmap.save("./bitmap.jpg");	//保存图片
}

//与平台无关 可以对图片进行修改 可以在线程中绘图
void Widget::Image()
{
	QPainter p;
	QImage image(400, 400, QImage::Format_RGB32);

	//在image上绘图
	p.begin(&image);
	p.drawImage(QRect(0, 0, 400, 400), QImage(":/source/LiAo.jpeg"));
	//更改像素
	for(int x = 0; x < 400; x++)
	{
		for(int y = 0; y < 400; y++)
		{
			QColor c = image.pixelColor(x, y);
			if(c.red() < 100 && c.blue() < 100 && c.green() < 100)
			{
				image.setPixel(x, y, qRgb(0, 0, 255));
			}
		}
	}
	p.end();

	image.save("./image.jpg");	//保存图片
}

//用于保存、读取绘图状态(二进制文件)
void Widget::Picture()
{
	QPainter p;
	QPicture picture;

	//在picture上绘图
	p.begin(&picture);
	p.drawPixmap(QRect(0, 0, 400, 400), QPixmap(":/source/LiAo.jpeg"));
	p.end();

	picture.save("./picture.jpg");	//保存图片
}

void Widget::on_bt_pixmap_clicked()
{
	this->flag = 1;
	repaint();
}

void Widget::on_bt_bitmap_clicked()
{
	this->flag = 2;
	repaint();
}

void Widget::on_bt_image_clicked()
{
	this->flag = 3;
	repaint();
}

void Widget::on_bt_picture_clicked()
{
	this->flag = 4;
	repaint();
}

Widget::~Widget()
{
	delete ui;
}
