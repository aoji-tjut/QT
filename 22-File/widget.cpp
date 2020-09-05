#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setFixedSize(600, 400);
	setWindowTitle("File");
	ui->textEdit->setFont(QFont("Helvetica", 20, QFont::Normal));

	WriteDataStream();
	ReadDataStream();
	WriteTextStream();
	ReadTextStream();
	Buffer();
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
	QFile file(path);
	if(file.open(QIODevice::ReadOnly))	//只读打开 成功返回true
	{
		//获取文件信息
		QFileInfo info(file);
		QString str = QString("文件名：%1\n文件大小：%2字节\n文件路径：%3\n\n").
					  arg(info.fileName()).arg(info.size()).arg(info.filePath());

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
	QFile file(path);
	if(file.open(QIODevice::WriteOnly))		//只写打开 成功返回true
	{
		QString str = ui->textEdit->toPlainText();	//获取内容
		file.write(str.toUtf8());

		file.close();
	}
}

//读二进制文件
void Widget::ReadDataStream()
{
	QFile file("./data.txt");
	if(file.open(QIODevice::ReadOnly))
	{
		QDataStream stream(&file);
		QString str;
		int i;
		stream >> str >> i;
		cout << str.toUtf8().data() << i << endl;

		file.close();
	}
}

//写二进制文件
void Widget::WriteDataStream()
{
	QFile file("./data.txt");
	if(file.open(QIODevice::WriteOnly))
	{
		QDataStream stream(&file);
		stream << QString("二进制文件") << 666;

		file.close();
	}
}

//读文本文件
void Widget::ReadTextStream()
{
	QFile file("./text.txt");
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		stream.setCodec("UTF-8");	//可以指定编码

		//读文本文件必须一次性读完或按行读
		QString str = stream.readAll();
		cout << str.toUtf8().data() << endl;

		file.close();
	}
}

//写文本文件
void Widget::WriteTextStream()
{
	QFile file("./text.txt");
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		stream.setCodec("UTF-8");				//可以指定编码
		stream << QString("文本文件") << 666;		//"文本文件"与666之间没有间隔

		file.close();
	}
}

//内存文件 类似QFile
void Widget::Buffer()
{
	QByteArray arr;
	QBuffer buf(&arr);

	//写
	if(buf.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&buf);	//使用文本流写入buf
		stream.setCodec("UTF-8");
		stream << QString("内存文件") << 666;

		buf.close();
	}

	//读
	if(buf.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&buf);	//使用文本流读取buf
		stream.setCodec("UTF-8");	//可以指定编码
		QString str = stream.readAll();
		cout << str.toUtf8().data() << endl;

		buf.close();
	}
}
