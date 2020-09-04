#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setWindowTitle("UIQListQTreeQTable");
	setFixedSize(600, 400);

	ListWidget();
	TreeWidget();
	TableWidget();
}

MainWindow::~MainWindow()
{
	delete ui;
}

//列
void MainWindow::ListWidget()
{
	//添加一项
	QListWidgetItem* list_item = new QListWidgetItem("item");
	list_item->setTextAlignment(Qt::AlignHCenter);	//水平居中
	ui->listWidget->addItem(list_item);

	//添加多项
	QStringList string_list;
	string_list << "list1" << "list2" << "list3";
	ui->listWidget->addItems(string_list);
}

//树
void MainWindow::TreeWidget()
{
	//设置水平头
	ui->treeWidget->setHeaderLabels(QStringList() << "root" << "child");

	//添加根节点
	QTreeWidgetItem* root_item1 = new QTreeWidgetItem(QStringList() << "root1");
	QTreeWidgetItem* root_item2 = new QTreeWidgetItem(QStringList() << "root2");
	ui->treeWidget->addTopLevelItem(root_item1);
	ui->treeWidget->addTopLevelItem(root_item2);

	//添加子节点
	root_item1->addChild(new QTreeWidgetItem(QStringList() << "child1"));
	root_item1->addChild(new QTreeWidgetItem(QStringList() << "child2"));
	root_item2->addChild(new QTreeWidgetItem(QStringList() << "child3"));
	root_item2->addChild(new QTreeWidgetItem(QStringList() << "child4"));
}

//表格
void MainWindow::TableWidget()
{
	//设置行列数
	ui->tableWidget->setRowCount(4);
	ui->tableWidget->setColumnCount(5);

	//设置表头
	ui->tableWidget->setHorizontalHeaderLabels(
		QStringList() << "column1" << "column2" << "column3" << "column4" << "column5");
	ui->tableWidget->setVerticalHeaderLabels(
		QStringList() << "row1" << "row2" << "row3" << "row4");

	//设置内容并居中
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			char str[8];
			sprintf(str, "(%d,%d)", i + 1, j + 1);
			QTableWidgetItem* item = new QTableWidgetItem(str);
			item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui->tableWidget->setItem(i, j, item);
		}
	}
}
