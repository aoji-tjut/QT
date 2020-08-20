#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>	//插入ListWidget的项
#include <QStringList>		//相当于string<list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void ListWidget();
	void TreeWidget();
	void TableWidget();

private:
	Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
