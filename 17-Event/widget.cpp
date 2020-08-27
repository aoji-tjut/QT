#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	//label设置
	ui->key_label->setFont(QFont("Helvetica", 30, QFont::Normal));
	ui->key_label->setAlignment(Qt::AlignCenter);
	ui->timer_label->setFont(QFont("Helvetica", 30, QFont::Normal));
	ui->timer_label->setAlignment(Qt::AlignCenter);

	//启动定时器
	this->id = this->startTimer(500);	//启动定时器 1000ms为间隔 返回定时器ID

	//给mouse_label控件安装事件过滤器
	ui->mouse_label->installEventFilter(this);	//指定父对象
}

//键盘按下
void Widget::keyPressEvent(QKeyEvent* ev)
{
	ui->key_label->setText(QString("Key Press\n%1").arg(char(ev->key())));

	if((ev->modifiers() == (Qt::ControlModifier | Qt::AltModifier)) &&
			(ev->key() == Qt::Key_A))
	{
		ui->key_label->setText(QString("Key Press\nControl+Alt+A"));
	}
}

//定时器
void Widget::timerEvent(QTimerEvent* ev)
{
	static int i = 0;
	ui->timer_label->setText(QString("Timer\n%1").arg(++i));

	if(i > 10)
	{
		killTimer(this->id);
		ui->timer_label->setText(QString("Kill Timer"));
	}
}

//关闭
void Widget::closeEvent(QCloseEvent* ev)
{
	int ret = QMessageBox::question(this, "Question", "是否关闭窗口？");
	if(ret == QMessageBox::Yes)
	{
		ev->accept();	//接收事件
	}
	else
	{
		ev->ignore();	//忽略事件 继续传递给父窗口(不是父类)
	}
}

//事件拦截
bool Widget::eventFilter(QObject* obj, QEvent* ev)
{
	//返回true 用户处理
	//返回false 父类处理

	if(obj == ui->mouse_label)
	{
		//拦截ui->mouse_label
		if(ev->type() == QEvent::MouseButtonDblClick)
		{
			//拦截QEvent::MouseButtonDblClick
			QMouseEvent* e = static_cast<QMouseEvent*>(ev);

			ui->mouse_label->setStyleSheet("color:red;");
			QPoint pos = e->pos();
			QPoint global_pos = e->globalPos();
			QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
						  arg(pos.x()).arg(pos.y()).
						  arg(global_pos.x()).arg(global_pos.y());

			switch (e->button())
			{
				case Qt::LeftButton:
					str = "Left Double Click\n" + str;
					break;
				case Qt::RightButton:
					str = "Right Double Click\n" + str;
					break;
				case Qt::MidButton:
					str = "Mid Double Click\n" + str;
					break;
				default:
					break;
			}

			str = "Event Filter Intercept\n" + str;
			ui->mouse_label->setText(str);

			return true;
		}
		else
		{
			//其他事件父类处理
			return QWidget::eventFilter(obj, ev);
		}
	}
	else
	{
		//其他控件父类处理
		return QWidget::eventFilter(obj, ev);
	}
}

Widget::~Widget()
{
	delete ui;
}
