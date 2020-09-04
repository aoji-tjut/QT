#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("Dialog");
	resize(600, 400);

	b1 = new QPushButton(this);
	b1->setText("Modal");
	b1->resize(100, 50);
	b1->move(100, 200);
	b2 = new QPushButton(this);
	b2->setText("No Modal");
	b2->resize(100, 50);
	b2->move(400, 200);

	connect(b1, &QPushButton::clicked, this, &MainWindow::ModalDialog);
	connect(b2, &QPushButton::clicked, this, &MainWindow::NoModalDialog);
}

MainWindow::~MainWindow()
{
}

//模态对话框
void MainWindow::ModalDialog()
{
	QDialog model_dialog;
	model_dialog.setWindowTitle("模态对话框");
	model_dialog.resize(300, 200);
	model_dialog.exec();	//阻塞
}

//非模态对话框
void MainWindow::NoModalDialog()
{
	//局部栈区变量不会显示对话框 会直接释放
	QDialog* no_model_dialog = new QDialog;					//堆区指针 不指定父对象
	no_model_dialog->setAttribute(Qt::WA_DeleteOnClose);	//对话框关闭时释放指针 防止多次使用占用内存
	no_model_dialog->setWindowTitle("非模态对话框");
	no_model_dialog->resize(300, 200);
	no_model_dialog->show();								//非阻塞
	//可以设置为全局栈区变量避免直接释放 也可避免内存问题
}
