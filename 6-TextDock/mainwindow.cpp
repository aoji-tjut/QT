#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("TextDock");
	resize(600, 400);

	//核心部件 最多一个 set
	QTextEdit* test = new QTextEdit(this);
	setCentralWidget(test);

	//浮动窗口 可以多个 add
	QDockWidget* dock = new QDockWidget(this);
	addDockWidget(Qt::LeftDockWidgetArea, dock);	//默认左侧
}

MainWindow::~MainWindow()
{
}

