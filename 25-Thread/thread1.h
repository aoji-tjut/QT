#ifndef THREAD1_H
#define THREAD1_H

#include <QDebug>
#include <QThread>

class Thread1 : public QThread
{
	Q_OBJECT
public:
	explicit Thread1(QObject* parent = nullptr);

	void SetStop(bool);

protected:
	void run() override;	//重写线程处理函数 必须通过start()间接调用

signals:
	void Thread1Signal();

private:
	bool stop;
};

#endif // THREAD1_H
