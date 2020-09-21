#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("Thread");
	setFixedSize(600, 400);
	this->id = new QTimer(this);
	this->num = 0;
	ui->lcd->display(this->num);
	this->mutex = new QMutex();
	qDebug() << "Main Thread\t" << QThread::currentThread() << endl;

	//主线程
	connect(id, &QTimer::timeout, this, [ = ]()
	{
		ui->lcd->display(++this->num);
	});

	//QT4 继承QThread类 重写线程处理函数run()
	this->thread1 = new Thread1(this);
	connect(this->thread1, &Thread1::Thread1Signal, this, [ = ]()
	{
		this->mutex->lock();
		ui->lcd->display(this->num += 2);
		this->mutex->unlock();
	});

	//QT5 继承QObject类 重写自定义线程处理函数
	this->thread2 = new Thread2;				//创建自定义线程 不能指定父对象 控制线程逻辑
	this->qthread = new QThread(this);			//创建子线程 控制thread2启动终止
	this->thread2->moveToThread(this->qthread);	//把自定义线程加到子线程 qthread是thread2的父对象
	connect(this, &Widget::WidgetSignal, this->thread2, &Thread2::Run);
	connect(this->thread2, &Thread2::Thread2Signal, this, [ = ]()
	{
		this->mutex->lock();
		ui->lcd->display(this->num -= 3);
		this->mutex->unlock();
	});

	//connect()第五个参数：
	//默认：单线程使用直接，多线程使用队列。
	//直接：槽函数所在线程与发送者一致。
	//队列：槽函数所在线程与接收者一致。
}

Widget::~Widget()
{
	delete ui;

	//没有放在对象树 析构函数释放
	delete this->mutex;
	delete this->thread2;
}

void Widget::closeEvent(QCloseEvent* ev)
{
	if(this->thread1->isRunning())
	{
		QMessageBox::critical(this, "Error", "Thread1 is running");
		ev->ignore();
	}

	if(this->qthread->isRunning())
	{
		QMessageBox::critical(this, "Error", "Thread2 is running");
		ev->ignore();
	}
}

//阻塞主线程
void Widget::on_bt_sleep_clicked()
{
	if(QMessageBox::question(this, "Question", "Block for 5 seconds?") == QMessageBox::No)
	{
		return;
	}

	this->id->start(100);
	QThread::sleep(5);
	this->id->stop();
	QMessageBox::information(this, "Information", "Sleep end");
}

//QT4多线程
void Widget::on_bt_thread1_clicked()
{
	if(this->thread1->isRunning())
	{
		return;
	}

	this->thread1->SetStop(false);
	this->thread1->start();		//启动线程 间接调用线程处理函数run()
}

//QT5多线程
void Widget::on_bt_thread2_clicked()
{
	if(this->qthread->isRunning())
	{
		return;
	}

	this->thread2->SetStop(false);
	this->qthread->start();		//启动线程 没有启动线程处理函数
	emit WidgetSignal();		//启动线程处理函数Run 必须通过信号和槽函数
}

//停止QT4线程
void Widget::on_bt_stop1_clicked()
{
	if(this->thread1->isRunning())
	{
		this->thread1->SetStop(true);
		this->thread1->quit();	//关闭线程
		this->thread1->wait();	//等待线程处理完毕
		QMessageBox::information(this, "Information", "Thread1 quit");
	}
}

//停止QT5线程
void Widget::on_bt_stop2_clicked()
{
	if(this->qthread->isRunning())
	{
		this->thread2->SetStop(true);
		this->qthread->quit();  //关闭线程
		this->qthread->wait();  //等待线程处理完毕
		QMessageBox::information(this, "Information", "Thread2 quit");
	}
}
