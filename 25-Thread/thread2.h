#ifndef THREAD2_H
#define THREAD2_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Thread2 : public QObject
{
	Q_OBJECT
public:
	explicit Thread2(QObject* parent = nullptr);

	void Run();		//线程处理函数
	void SetStop(bool);

signals:
	void Thread2Signal();

private:
	bool stop;
};

#endif // THREAD2_H
