#include "rect.h"

Rect::Rect(QObject* parent) : QObject(parent)
{
	this->width = 400;
	this->height = 400;
	this->image = QImage(this->width, this->height, QImage::Format_ARGB32);
	this->brush = QBrush();
	this->brush.setStyle(Qt::SolidPattern);
	this->stop = false;
}

void Rect::Run()
{
	qsrand(time(nullptr));

	while(!this->stop)
	{
		DrawRect();
		QThread::msleep(100);
	}
}

void Rect::DrawRect()
{
	this->brush.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	this->painter.begin(&this->image);
	this->painter.setBrush(this->brush);
	this->painter.drawRect(QRect(QPoint(qrand() % this->width, qrand() % this->height),
								 QPoint(qrand() % this->width, qrand() % this->height)));
	this->painter.end();
	emit Update(this->image);
}

void Rect::Reset(int width, int height)
{
	this->width = width;
	this->height = height;
	this->image = QImage(this->width, this->height, QImage::Format_ARGB32);
}

void Rect::SetStop(bool flag)
{
	this->stop = flag;
}
