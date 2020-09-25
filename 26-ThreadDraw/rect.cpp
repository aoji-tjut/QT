#include "rect.h"

Rect::Rect(QObject* parent) : QObject(parent)
{
	this->image = QImage(400, 400, QImage::Format_ARGB32);
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
	this->painter.drawRect(QRect(QPoint(qrand() % 400, qrand() % 400), QPoint(qrand() % 400, qrand() % 400)));
	this->painter.end();

	emit Update(this->image);
}

void Rect::SetStop(bool flag)
{
	this->stop = flag;
}
