#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QImage>
#include <QPicture>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

	void paintEvent(QPaintEvent* ev) override;
	void Pixmap();
	void Bitmap();
	void Image();
	void Picture();

private slots:
	void on_bt_pixmap_clicked();
	void on_bt_bitmap_clicked();
	void on_bt_image_clicked();
	void on_bt_picture_clicked();

private:
	Ui::Widget* ui;
	int flag;
};
#endif // WIDGET_H
