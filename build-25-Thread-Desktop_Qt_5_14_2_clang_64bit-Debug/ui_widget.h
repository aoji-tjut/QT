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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLCDNumber *lcd;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *bt_thread1;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_stop1;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_thread2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *bt_sleep;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *bt_stop2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lcd = new QLCDNumber(widget_2);
        lcd->setObjectName(QString::fromUtf8("lcd"));

        gridLayout->addWidget(lcd, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        bt_thread1 = new QPushButton(widget);
        bt_thread1->setObjectName(QString::fromUtf8("bt_thread1"));

        gridLayout_3->addWidget(bt_thread1, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        bt_stop1 = new QPushButton(widget);
        bt_stop1->setObjectName(QString::fromUtf8("bt_stop1"));

        gridLayout_3->addWidget(bt_stop1, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        bt_thread2 = new QPushButton(widget);
        bt_thread2->setObjectName(QString::fromUtf8("bt_thread2"));

        gridLayout_3->addWidget(bt_thread2, 0, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        bt_sleep = new QPushButton(widget);
        bt_sleep->setObjectName(QString::fromUtf8("bt_sleep"));

        gridLayout_3->addWidget(bt_sleep, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        bt_stop2 = new QPushButton(widget);
        bt_stop2->setObjectName(QString::fromUtf8("bt_stop2"));

        gridLayout_3->addWidget(bt_stop2, 1, 5, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        bt_thread1->setText(QCoreApplication::translate("Widget", "Thread1", nullptr));
        bt_stop1->setText(QCoreApplication::translate("Widget", "Stop1", nullptr));
        bt_thread2->setText(QCoreApplication::translate("Widget", "Thread2", nullptr));
        bt_sleep->setText(QCoreApplication::translate("Widget", "Sleep", nullptr));
        bt_stop2->setText(QCoreApplication::translate("Widget", "Stop2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
