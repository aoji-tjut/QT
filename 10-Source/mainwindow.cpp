#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowTitle("Source");
	resize(600, 400);

	b = new QPushButton(this);
	b->resize(100, 100);
	b->move(250, 150);
	b->setIcon(QIcon(":/source/LiAo.jpeg"));
	b->setIconSize(QSize(80, 80));
	connect(b, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
}

