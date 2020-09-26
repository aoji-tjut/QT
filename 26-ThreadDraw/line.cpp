#include "line.h"

Line::Line(QObject* parent) : QObject(parent)
{
	this->width = 400;
	this->height = 400;
	this->image = QImage(this->width, this->height, QImage::Format_ARGB32);
	this->pen = QPen();
	this->pen.setWidth(3);
	this->stop = false;
}

void Line::Run()
{
	qsrand(time(nullptr));
	while(!this->stop)
	{
		DrawLine();
		QThread::msleep(100);
	}
}

void Line::DrawLine()
{
	this->pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	this->painter.begin(&this->image);
	this->painter.setPen(this->pen);
	this->painter.drawLine(qrand() % this->width, qrand() % this->height,
						   qrand() % this->width, qrand() % this->height);
	this->painter.end();
	emit Update(this->image);
}

void Line::Reset(int width, int height)
{
	this->width = width;
	this->height = height;
	this->image = QImage(this->width, this->height, QImage::Format_ARGB32);
}

void Line::SetStop(bool flag)
{
	this->stop = flag;
}
