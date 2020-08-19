#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("Dialog");
	resize(600, 400);

	b1 = new QPushButton(this);
	b1->setText("Quession");
	b1->resize(100, 50);
	b1->move(250, 50);
	b2 = new QPushButton(this);
	b2->setText("Information");
	b2->resize(100, 50);
	b2->move(100, 100);
	b3 = new QPushButton(this);
	b3->setText("Warning");
	b3->resize(100, 50);
	b3->move(400, 100);
	b4 = new QPushButton(this);
	b4->setText("Critical");
	b4->resize(100, 50);
	b4->move(100, 250);
	b5 = new QPushButton(this);
	b5->setText("About");
	b5->resize(100, 50);
	b5->move(400, 250);

	connect(b1, &QPushButton::clicked, this, &MainWindow::Question);
	connect(b2, &QPushButton::clicked, this,
	[ = ]()	{QMessageBox::information(this, "Information", "Information...");});
	connect(b3, &QPushButton::clicked, this,
	[ = ]() {QMessageBox::warning(this, "Warning", "Warning...");});
	connect(b4, &QPushButton::clicked, this,
	[ = ]() {QMessageBox::critical(this, "Critical", "Critical...");});
	connect(b5, &QPushButton::clicked, this,
	[ = ]() {QMessageBox::about(this, "About", "About...");});
}

//“问题”对话框
void MainWindow::Question()
{
	//返回值：选择结果
	//参数：父对象 窗口名 内容 选项 默认选项
	int ret = QMessageBox::question(this, "Question", "Question...",
									QMessageBox::Yes | QMessageBox::No,
									QMessageBox::No);
	switch (ret)
	{
		case QMessageBox::Yes:
			qDebug() << "Yes" << endl;
			break;
		case QMessageBox::No:
			qDebug() << "No" << endl;
			break;
		default:
			break;
	}
}

MainWindow::~MainWindow()
{
}
