#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::SmallWidget)
{
	ui->setupUi(this);

	//h
	ui->hspinBox->setRange(0, 100);
	ui->horizontalSlider->setRange(0, 100);
	void (QSpinBox::*signal_h)(int) = &QSpinBox::valueChanged;	//使用函数指针解决函数重载
	connect(ui->hspinBox, signal_h, ui->horizontalSlider,
			&QSlider::setValue);	//hspinBox->horizontalSlider
	connect(ui->horizontalSlider, &QSlider::valueChanged, ui->hspinBox,
			&QSpinBox::setValue);	//horizontalSlider->hspinBox

	//v
	ui->vspinBox->setRange(-100, 100);
	ui->verticalSlider->setRange(-100, 100);
	ui->hspinBox->setValue(0);
	void (QSpinBox::*signal_v)(int) = &QSpinBox::valueChanged;	//使用函数指针解决函数重载
	connect(ui->vspinBox, signal_v, ui->verticalSlider,
			&QSlider::setValue);	//vspinBox->verticalSlider
	connect(ui->verticalSlider, &QSlider::valueChanged, ui->vspinBox,
			&QSpinBox::setValue);	//verticalSlider->vspinBox
}

SmallWidget::~SmallWidget()
{
	delete ui;
}
