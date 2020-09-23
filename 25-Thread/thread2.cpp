#include "thread2.h"

Thread2::Thread2(QObject* parent) : QObject(parent)
{

}

//线程处理函数
void Thread2::Run()
{
	qDebug() << "Thread2\t" << QThread::currentThread() << endl;

	while(!this->stop)
	{
		//每1000ms Widget::lcd++
		emit Thread2Signal();
		QThread::msleep(1000);
	}
}

void Thread2::SetStop(bool stop)
{
	this->stop = stop;
}
