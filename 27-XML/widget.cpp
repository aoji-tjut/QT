#include "widget.h"
#include "ui_widget.h"
#include "xml.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	XML::CreateXML("./test.xml");
	XML::AppendXML("./test.xml");
	XML::ReadXML("./test.xml");
}

Widget::~Widget()
{
	delete ui;
}

