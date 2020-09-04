#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>		//文件
#include <QFileDialog>	//文件对话框
#include <QFileInfo>	//文件信息
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

private slots:
	void on_bt_read_clicked();
	void on_bt_write_clicked();

private:
	Ui::Widget* ui;
};
#endif // WIDGET_H
