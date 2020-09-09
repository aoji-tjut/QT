#include "widget1.h"
#include "widget2.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Widget1 w1;
	Widget2 w2;
	w1.show();
	w2.show();

	return a.exec();
}
