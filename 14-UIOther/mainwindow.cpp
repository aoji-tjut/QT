#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setWindowTitle("UIOther");
	setFixedSize(600, 400);

	//StackedWidget
	ui->stackedWidget->setCurrentIndex(0);	//设置当前页
	connect(ui->scroll_area, &QPushButton::clicked, this,
	[ = ]() {ui->stackedWidget->setCurrentIndex(0);});
	connect(ui->tool_box, &QPushButton::clicked, this,
	[ = ]() {ui->stackedWidget->setCurrentIndex(1);});
	connect(ui->tab_widget, &QPushButton::clicked, this,
	[ = ]() {ui->stackedWidget->setCurrentIndex(2);});
	connect(ui->combo_box, &QPushButton::clicked, this,
	[ = ]() {ui->stackedWidget->setCurrentIndex(3);});
	connect(ui->label_movie, &QPushButton::clicked, this,
	[ = ]() {ui->stackedWidget->setCurrentIndex(4);});

	//Combo Box
	ui->comboBox->addItem("item1");
	ui->comboBox->addItem("item2");
	ui->comboBox->addItem("item3");

	//Label + Movie
	QMovie* movie = new QMovie(":/source/mario.gif");
	ui->label->setMovie(movie);
	movie->start();
}

MainWindow::~MainWindow()
{
	delete ui;
}

