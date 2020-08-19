#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDialog>		//对话框

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void ModalDialog();
	void NoModalDialog();

private:
	QPushButton* b1;
	QPushButton* b2;
};
#endif // MAINWINDOW_H
