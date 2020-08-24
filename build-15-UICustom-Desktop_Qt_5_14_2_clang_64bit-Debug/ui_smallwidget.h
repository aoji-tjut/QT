/********************************************************************************
** Form generated from reading UI file 'smallwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIDGET_H
#define UI_SMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmallWidget
{
public:
    QGridLayout *gridLayout;
    QSpinBox *hspinBox;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QSpinBox *vspinBox;

    void setupUi(QWidget *SmallWidget)
    {
        if (SmallWidget->objectName().isEmpty())
            SmallWidget->setObjectName(QString::fromUtf8("SmallWidget"));
        SmallWidget->resize(575, 245);
        gridLayout = new QGridLayout(SmallWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hspinBox = new QSpinBox(SmallWidget);
        hspinBox->setObjectName(QString::fromUtf8("hspinBox"));
        hspinBox->setMaximum(99);

        gridLayout->addWidget(hspinBox, 0, 0, 1, 1);

        horizontalSlider = new QSlider(SmallWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(99);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 1, 1, 1);

        verticalSlider = new QSlider(SmallWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 2, 1, 1);

        vspinBox = new QSpinBox(SmallWidget);
        vspinBox->setObjectName(QString::fromUtf8("vspinBox"));
        vspinBox->setMaximum(100);

        gridLayout->addWidget(vspinBox, 1, 2, 1, 1);


        retranslateUi(SmallWidget);

        QMetaObject::connectSlotsByName(SmallWidget);
    } // setupUi

    void retranslateUi(QWidget *SmallWidget)
    {
        SmallWidget->setWindowTitle(QCoreApplication::translate("SmallWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmallWidget: public Ui_SmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
