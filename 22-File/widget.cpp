#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setFixedSize(600, 400);
	setWindowTitle("File");
}

Widget::~Widget()
{
	delete ui;
}

//读
void Widget::on_bt_read_clicked()
{
	//获取路径
	QString path = QFileDialog::getOpenFileName(
					   this, "OpenFile", "/", "txt(*.txt)");	//打开文件对话框
	if(path.isEmpty())
	{
		return;
	}

	//打开文件
	QFile file(path);	//文件对象
	if(file.open(QIODevice::ReadOnly))	//只读打开 成功返回true
	{
		//获取文件信息
		QFileInfo info(file);
		QString str = QString("文件名：%1\n文件大小：%2字节\n绝对路径：%3\n\n").
					  arg(info.fileName()).arg(info.size()).arg(info.absolutePath());

		//一次性读完
		//QByteArray arr=file.readAll();
		//ui->textEdit->setText(QString(arr));

		//按行读
		QByteArray arr;
		while(!file.atEnd())
		{
			arr += file.readLine();
		}
		ui->textEdit->setText(str + QString(arr));

		file.close();
	}
}

//写
void Widget::on_bt_write_clicked()
{
	//获取路径
	QString path = QFileDialog::getSaveFileName(
					   this, "SaveFile", "/", "txt(*.txt)");	//保存文件对话框
	if(path.isEmpty())
	{
		return;
	}

	//打开文件
	QFile file(path);	//文件对象
	if(file.open(QIODevice::WriteOnly))		//只写打开 成功返回true
	{
		QString str = ui->textEdit->toPlainText();	//获取内容

		file.write(str.toUtf8());

		file.close();
	}
}
