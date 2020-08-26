#include "mylabel.h"

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{
	//自定义控件
	this->setMouseTracking(true);	//追踪鼠标
	this->setFont(QFont("Helvetica", 30, QFont::Normal));
	this->setAlignment(Qt::AlignCenter);

	//安装事件过滤器
	this->installEventFilter(this);
}

//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());	//格式化输出字符串 类似sprintf

	switch (ev->button())
	{
		case Qt::LeftButton:
			str = "Press Left Button\n" + str;
			break;
		case Qt::RightButton:
			str = "Press Right Button\n" + str;
			break;
		case Qt::MidButton:
			str = "Press Mid Button\n" + str;
			break;
		default:
			break;
	}

	this->setStyleSheet("color:black;");
	this->setText(str);
}

//鼠标抬起
void MyLabel::mouseReleaseEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());

	switch (ev->button())
	{
		case Qt::LeftButton:
			str = "Release Left Button\n" + str;
			break;
		case Qt::RightButton:
			str = "Release Right Button\n" + str;
			break;
		case Qt::MidButton:
			str = "Release Mid Button\n" + str;
			break;
		default:
			break;
	}

	this->setStyleSheet("color:black;");
	this->setText(str);
}

//鼠标双击
void MyLabel::mouseDoubleClickEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());

	switch (ev->button())
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

	this->setText(str);
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Event\nMove\nPos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());

	this->setText(str);
}

//鼠标离开
void MyLabel::leaveEvent(QEvent* ev)
{
	this->setStyleSheet("color:black;");
	this->setText(QString("Leave Event"));
}

//事件分发
bool MyLabel::event(QEvent* ev)
{
	//返回true 用户处理
	//返回false 父类处理

	//拦截QEvent::MouseMove
	if(ev->type() == QEvent::MouseMove)
	{
		this->setStyleSheet("color:blue;");
		QMouseEvent* e = static_cast<QMouseEvent*>(ev);
		MyLabel::mouseMoveEvent(e);

		return true;
	}
	else
	{
		return QLabel::event(ev);
	}
}

bool MyLabel::eventFilter(QObject* obj, QEvent* ev)
{
	//返回true 用户处理
	//返回false 父类处理

	//QEvent::MouseButtonDblClick
	if(obj == this)
	{
		if(ev->type() == QEvent::MouseButtonDblClick)
		{
			this->setStyleSheet("color:red;");
			this->setText("EventFilter\nMouseButtonDblClick");
			QMouseEvent* e = static_cast<QMouseEvent*>(ev);
			MyLabel::mouseDoubleClickEvent(e);

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return QLabel::eventFilter(obj, ev);
	}
}
