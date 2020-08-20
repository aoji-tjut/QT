#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//设置默认
	//单选按钮
	ui->radioButton1->setChecked(true);
	ui->radioButton4->setChecked(true);
	//单选按钮 0未选 1半选 2全选
	ui->checkBox1->setCheckState(Qt::CheckState(1));
	ui->checkBox3->setCheckState(Qt::CheckState(2));

	//信号处理
	//按钮
	connect(ui->pushButton, &QPushButton::clicked, this,
	[]() {qDebug() << "pushButton" << endl;});
	connect(ui->toolButton, &QPushButton::clicked, this,
	[]() {qDebug() << "toolButton" << endl;});
	//单选
	connect(ui->radioButton1, &QRadioButton::clicked, this,
	[]() {qDebug() << "radioButton1" << endl;});
	connect(ui->radioButton2, &QRadioButton::clicked, this,
	[]() {qDebug() << "radioButton2" << endl;});
	connect(ui->radioButton3, &QRadioButton::clicked, this,
	[]() {qDebug() << "radioButton3" << endl;});
	connect(ui->radioButton4, &QRadioButton::clicked, this,
	[]() {qDebug() << "radioButton4" << endl;});
	//多选 0未选 1半选 2全选
	connect(ui->checkBox1, &QCheckBox::stateChanged, this,
	[](int state) {qDebug() << "checkBox1" << state << endl;});
	connect(ui->checkBox2, &QCheckBox::stateChanged, this,
	[](int state) {qDebug() << "checkBox2" << state << endl;});
	connect(ui->checkBox3, &QCheckBox::stateChanged, this,
	[](int state) {qDebug() << "checkBox3" << state << endl;});
	connect(ui->checkBox4, &QCheckBox::stateChanged, this,
	[](int state) {qDebug() << "checkBox4" << state << endl;});
}

MainWindow::~MainWindow()
{
	delete ui;
}

