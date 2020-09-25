#include "line.h"

Line::Line(QObject* parent) : QObject(parent)
{

	this->image = QImage(400, 400, QImage::Format_ARGB32);
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
	this->painter.drawLine(qrand() % 400, qrand() % 400, qrand() % 400, qrand() % 400);
	this->painter.end();

	emit Update(this->image);
}

void Line::SetStop(bool flag)
{
	this->stop = flag;
}
