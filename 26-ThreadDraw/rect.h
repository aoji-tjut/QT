#ifndef RECT_H
#define RECT_H

#include <ctime>
#include <QObject>
#include <QPainter>
#include <QImage>
#include <QBrush>
#include <QThread>

class Rect : public QObject
{
	Q_OBJECT
public:
	explicit Rect(QObject* parent = nullptr);

	void Run();
	void DrawRect();
	void SetStop(bool);

signals:
	void Update(QImage);

private:
	QPainter painter;
	QImage image;
	QBrush brush;
	bool stop;
};

#endif // RECT_H
