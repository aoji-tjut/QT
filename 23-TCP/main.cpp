#include "server.h"
#include "client.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Server w1;
	Client w2;

	w1.show();
	w2.show();

	return a.exec();
}
