#include "thread1.h"

Thread1::Thread1(QObject* parent) : QThread(parent)
{

}

//线程处理函数
void Thread1::run()
{
	qDebug() << "Thread1\t" << Thread1::currentThread() << endl;

	while(!this->stop)
	{
		//每500ms Widget::lcd++
		emit Thread1Signal();
		QThread::msleep(500);
	}
}

void Thread1::SetStop(bool stop)
{
	this->stop = stop;
}
