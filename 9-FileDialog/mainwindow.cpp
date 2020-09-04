#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("FileDialog");
	resize(600, 400);

	b = new QPushButton(this);
	b->setText("Open File");
	b->resize(100, 50);
	b->move(250, 200);

	connect(b, &QPushButton::clicked, this, &MainWindow::OpenFile);
}

MainWindow::~MainWindow()
{
}

//文件对话框
void MainWindow::OpenFile()
{
	//返回值：文件路径
	//参数：父对象 窗口名 起始路径 筛选文件
	QString path = QFileDialog::getOpenFileName(this, "OpenFile", "/",
				   "Image(*.jpg *.png);;Text(*.txt)");
	qDebug() << path << endl;
}
