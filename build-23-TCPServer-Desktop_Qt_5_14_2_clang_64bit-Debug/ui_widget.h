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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *bt_listen;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *line_client_ip;
    QLineEdit *line_client_port;
    QLineEdit *line_server_port;
    QLabel *label;
    QLineEdit *line_server_ip;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *text_recv;
    QTextEdit *text_send;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_send;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 600);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        bt_listen = new QPushButton(widget_3);
        bt_listen->setObjectName(QString::fromUtf8("bt_listen"));

        gridLayout->addWidget(bt_listen, 0, 6, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        line_client_ip = new QLineEdit(widget_3);
        line_client_ip->setObjectName(QString::fromUtf8("line_client_ip"));
        line_client_ip->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_client_ip, 0, 4, 1, 1);

        line_client_port = new QLineEdit(widget_3);
        line_client_port->setObjectName(QString::fromUtf8("line_client_port"));
        line_client_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_client_port, 1, 4, 1, 1);

        line_server_port = new QLineEdit(widget_3);
        line_server_port->setObjectName(QString::fromUtf8("line_server_port"));
        line_server_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_server_port, 1, 1, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_server_ip = new QLineEdit(widget_3);
        line_server_ip->setObjectName(QString::fromUtf8("line_server_ip"));
        line_server_ip->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_server_ip, 0, 1, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 5, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_recv = new QTextEdit(widget);
        text_recv->setObjectName(QString::fromUtf8("text_recv"));

        verticalLayout->addWidget(text_recv);

        text_send = new QTextEdit(widget);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        verticalLayout->addWidget(text_send);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        bt_send = new QPushButton(widget_2);
        bt_send->setObjectName(QString::fromUtf8("bt_send"));
        bt_send->setMinimumSize(QSize(80, 0));
        bt_send->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(bt_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bt_close = new QPushButton(widget_2);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));
        bt_close->setMinimumSize(QSize(80, 0));
        bt_close->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(bt_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Client Port:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Client IP:", nullptr));
        bt_listen->setText(QCoreApplication::translate("Widget", "Listen", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Server IP:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Server Port:", nullptr));
        bt_send->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        bt_close->setText(QCoreApplication::translate("Widget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
