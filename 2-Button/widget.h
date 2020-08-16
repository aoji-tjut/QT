#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

private:
    QPushButton b1;
    QPushButton* b2;
};
#endif // WIDGET_H
