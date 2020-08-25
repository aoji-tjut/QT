/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    MyLabel *mouse_label;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *key_label;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *timer_label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        gridLayout_4 = new QGridLayout(Widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mouse_label = new MyLabel(widget);
        mouse_label->setObjectName(QString::fromUtf8("mouse_label"));
        mouse_label->setMinimumSize(QSize(300, 200));
        mouse_label->setMaximumSize(QSize(300, 200));
        mouse_label->setFrameShape(QFrame::Box);
        mouse_label->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(mouse_label, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget, 0, 0, 2, 1);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        key_label = new QLabel(widget_2);
        key_label->setObjectName(QString::fromUtf8("key_label"));
        key_label->setMinimumSize(QSize(200, 100));
        key_label->setMaximumSize(QSize(200, 100));
        key_label->setFrameShape(QFrame::Box);
        key_label->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(key_label, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        timer_label = new QLabel(widget_3);
        timer_label->setObjectName(QString::fromUtf8("timer_label"));
        timer_label->setMinimumSize(QSize(200, 100));
        timer_label->setMaximumSize(QSize(200, 100));
        timer_label->setFrameShape(QFrame::Box);
        timer_label->setTextFormat(Qt::AutoText);

        gridLayout_3->addWidget(timer_label, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_3, 1, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Event", nullptr));
        mouse_label->setText(QString());
        key_label->setText(QString());
        timer_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
