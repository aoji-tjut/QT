#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QAction>		//信号
#include <QMenuBar>		//菜单栏
#include <QMenu>		//菜单
#include <QToolBar>		//工具栏
#include <QStatusBar>		//状态栏
#include <QLabel>		//标签

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
};
#endif // MAINWINDOW_H
