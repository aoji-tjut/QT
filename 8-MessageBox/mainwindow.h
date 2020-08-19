#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>	//标准对话框

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void Question();

private:
	QPushButton* b1;
	QPushButton* b2;
	QPushButton* b3;
	QPushButton* b4;
	QPushButton* b5;
};
#endif // MAINWINDOW_H
