#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	ui->label->setAlignment(Qt::AlignCenter);	//居中
	ui->label->setStyleSheet("QLabel{"
							 "color:red;"
							 "border-image:url(:/source/night.JPG);"
							 "}");
	ui->pushButton->setStyleSheet("QPushButton{"
								  "color:red;"
								  "border:5px outset blue;"
								  "}"
								  "QPushButton:hover{border-image:url(:/source/LiAo.jpeg);}"
								 );
}

Widget::~Widget()
{
	delete ui;
}

