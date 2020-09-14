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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_port;
    QPushButton *bt_disconnect;
    QPushButton *bt_connect;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *line_ip;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *text_recv;
    QTextEdit *text_send;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_send;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *bt_file;
    QProgressBar *progress_bar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 600);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        line_port = new QLineEdit(widget);
        line_port->setObjectName(QString::fromUtf8("line_port"));
        line_port->setMinimumSize(QSize(120, 0));
        line_port->setMaximumSize(QSize(120, 16777215));
        line_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_port, 1, 2, 1, 1);

        bt_disconnect = new QPushButton(widget);
        bt_disconnect->setObjectName(QString::fromUtf8("bt_disconnect"));
        bt_disconnect->setMinimumSize(QSize(100, 0));
        bt_disconnect->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(bt_disconnect, 1, 4, 1, 1);

        bt_connect = new QPushButton(widget);
        bt_connect->setObjectName(QString::fromUtf8("bt_connect"));
        bt_connect->setMinimumSize(QSize(100, 0));
        bt_connect->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(bt_connect, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        line_ip = new QLineEdit(widget);
        line_ip->setObjectName(QString::fromUtf8("line_ip"));
        line_ip->setMinimumSize(QSize(120, 0));
        line_ip->setMaximumSize(QSize(120, 16777215));
        line_ip->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_ip, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_recv = new QTextEdit(widget_2);
        text_recv->setObjectName(QString::fromUtf8("text_recv"));

        verticalLayout->addWidget(text_recv);

        text_send = new QTextEdit(widget_2);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        verticalLayout->addWidget(text_send);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        bt_send = new QPushButton(widget_3);
        bt_send->setObjectName(QString::fromUtf8("bt_send"));
        bt_send->setMinimumSize(QSize(100, 0));
        bt_send->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(bt_send);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        bt_file = new QPushButton(widget_3);
        bt_file->setObjectName(QString::fromUtf8("bt_file"));
        bt_file->setMinimumSize(QSize(100, 0));
        bt_file->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(bt_file);

        progress_bar = new QProgressBar(widget_3);
        progress_bar->setObjectName(QString::fromUtf8("progress_bar"));
        progress_bar->setMinimumSize(QSize(100, 0));
        progress_bar->setMaximumSize(QSize(16777215, 16777215));
        progress_bar->setValue(24);

        horizontalLayout->addWidget(progress_bar);


        gridLayout_2->addWidget(widget_3, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Server IP:", nullptr));
        bt_disconnect->setText(QCoreApplication::translate("Widget", "Disconnect", nullptr));
        bt_connect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Server Port:", nullptr));
        bt_send->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        bt_file->setText(QCoreApplication::translate("Widget", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
