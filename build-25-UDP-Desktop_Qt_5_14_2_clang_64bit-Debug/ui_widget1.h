/********************************************************************************
** Form generated from reading UI file 'widget1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET1_H
#define UI_WIDGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget1
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *line_ip;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *line_port;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *text_recv;
    QTextEdit *text_send;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *bt_send;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *bt_close;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *Widget1)
    {
        if (Widget1->objectName().isEmpty())
            Widget1->setObjectName(QString::fromUtf8("Widget1"));
        Widget1->resize(600, 600);
        gridLayout = new QGridLayout(Widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(Widget1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_ip = new QLineEdit(widget_2);
        line_ip->setObjectName(QString::fromUtf8("line_ip"));

        horizontalLayout->addWidget(line_ip);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line_port = new QLineEdit(widget_2);
        line_port->setObjectName(QString::fromUtf8("line_port"));

        horizontalLayout->addWidget(line_port);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(Widget1);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_recv = new QTextEdit(widget);
        text_recv->setObjectName(QString::fromUtf8("text_recv"));

        verticalLayout->addWidget(text_recv);

        text_send = new QTextEdit(widget);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        verticalLayout->addWidget(text_send);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_3 = new QWidget(Widget1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        bt_send = new QPushButton(widget_3);
        bt_send->setObjectName(QString::fromUtf8("bt_send"));

        horizontalLayout_2->addWidget(bt_send);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        bt_close = new QPushButton(widget_3);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));

        horizontalLayout_2->addWidget(bt_close);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addWidget(widget_3, 2, 0, 1, 1);


        retranslateUi(Widget1);

        QMetaObject::connectSlotsByName(Widget1);
    } // setupUi

    void retranslateUi(QWidget *Widget1)
    {
        Widget1->setWindowTitle(QCoreApplication::translate("Widget1", "Widget1", nullptr));
        bt_send->setText(QCoreApplication::translate("Widget1", "send", nullptr));
        bt_close->setText(QCoreApplication::translate("Widget1", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget1: public Ui_Widget1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET1_H
