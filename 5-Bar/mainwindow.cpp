#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("Bar");
	resize(600, 400);

	//菜单栏 最多一个 set
	QMenuBar* menu_bar = menuBar();		//菜单栏
	menu_bar->setNativeMenuBar(false);	//mac下添加此句
	setMenuBar(menu_bar);

	QMenu* file_file = menu_bar->addMenu("File");		//菜单名 返回菜单指针
	QAction* file_new = file_file->addAction("New");	//菜单项 返回信号
	file_file->addSeparator();							//菜单分割线
	QAction* file_open = file_file->addAction("Open");	//菜单项 返回信号

	connect(file_new, &QAction::triggered, this, []() {qDebug() << "File->New" << endl;});	//处理信号
	connect(file_open, &QAction::triggered, this, []() {qDebug() << "File->Open" << endl;});//处理信号

	//工具栏 可以多个 add
	QToolBar* tool_bar = new QToolBar(this);
	addToolBar(Qt::LeftToolBarArea, tool_bar);		//默认左侧
	tool_bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea |
							  Qt::TopToolBarArea);	//只允许上、左、右停靠

	QAction* tool = tool_bar->addAction("Tool");	//工具项 返回信号
	tool_bar->addAction(tool);						//添加信号
	connect(tool, &QAction::triggered, this, []() {qDebug() << "Tool->Tool" << endl;});		//处理信号

	QPushButton* b = new QPushButton(this);
	b->setText("Button");
	tool_bar->addWidget(b);							//添加控件
	connect(b, &QPushButton::clicked, this, []() {qDebug() << "Tool->Button" << endl;});	//处理信号

	//状态栏 最多一个 set
	QStatusBar* status_bar = statusBar();
	setStatusBar(status_bar);
	status_bar->addWidget(new QLabel("Status Bar(left)", this));			//左侧
	status_bar->addPermanentWidget(new QLabel("Status Bar(right)", this));	//右侧
}

MainWindow::~MainWindow()
{
}
