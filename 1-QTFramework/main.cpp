#include "widget.h"
#include <QApplication>     //应用程序类

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);     //有且只有一个应用程序对象a

    Widget w;                       //Widget继承QWidget w窗口对象
	w.setWindowTitle("QTFramework");	//窗口标题
	w.show();                       //显示窗口

    return a.exec();                //进入事件循环
}
