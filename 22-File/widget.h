#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QFile>		//文件
#include <QFileDialog>	//文件对话框
#include <QFileInfo>	//文件信息
#include <QDataStream>  //二进制文件流
#include <QTextStream>  //文本文件流
#include <QBuffer>      //内存文件

//输出[文件名:行号]
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

	void ReadDataStream();
	void WriteDataStream();
	void ReadTextStream();
	void WriteTextStream();
	void Buffer();

private slots:
	void on_bt_read_clicked();
	void on_bt_write_clicked();

private:
	Ui::Widget* ui;
};
#endif // WIDGET_H
