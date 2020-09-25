#ifndef WIDGET_H
#define WIDGET_H

#include "line.h"
#include "rect.h"
#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

	void GetImageLine(QImage);
	void GetImageRect(QImage);

protected:
	void paintEvent(QPaintEvent*) override;
	void closeEvent(QCloseEvent*) override;

private:
	Ui::Widget* ui;
	QImage image_line;
	QImage image_rect;

	Line* line;
	Rect* rect;
	QThread* thread_line;
	QThread* thread_rect;

signals:
	void StartThread();
};
#endif // WIDGET_H
