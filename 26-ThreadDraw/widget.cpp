#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setWindowTitle("Thread Draw");
	resize(800, 400);

	this->line = new Line;
	this->thread_line = new QThread(this);
	this->line->moveToThread(this->thread_line);
	this->thread_line->start();
	connect(this, &Widget::StartThread, this->line, &Line::Run);
	connect(this->line, &Line::Update, this, &Widget::GetImageLine);

	this->rect = new Rect;
	this->thread_rect = new QThread(this);
	this->rect->moveToThread(this->thread_rect);
	this->thread_rect->start();
	connect(this, &Widget::StartThread, this->rect, &Rect::Run);
	connect(this->rect, &Rect::Update, this, &Widget::GetImageRect);

	emit StartThread();
}

Widget::~Widget()
{
	delete ui;
	delete this->line;
	delete this->rect;
}

void Widget::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);
	painter.drawImage(0, 0, this->image_line);
	painter.drawImage(width() / 2, 0, this->image_rect);
	painter.end();
}

void Widget::resizeEvent(QResizeEvent*)
{
	this->line->Reset(width() / 2, height());
	this->rect->Reset(width() / 2, height());
}

void Widget::closeEvent(QCloseEvent*)
{
	this->line->SetStop(true);
	this->thread_line->quit();
	this->thread_line->wait();

	this->rect->SetStop(true);
	this->thread_rect->quit();
	this->thread_rect->wait();
}

void Widget::GetImageLine(QImage image)
{
	this->image_line = image;
	update();
}

void Widget::GetImageRect(QImage image)
{
	this->image_rect = image;
	update();
}
