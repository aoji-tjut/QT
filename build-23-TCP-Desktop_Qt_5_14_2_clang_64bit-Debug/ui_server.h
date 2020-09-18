/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

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

class Ui_Server
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLineEdit *line_server_port;
    QLabel *label_3;
    QLineEdit *line_client_ip;
    QPushButton *bt_listen;
    QLineEdit *line_server_ip;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *line_client_port;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *text_recv;
    QTextEdit *text_send;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_send;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_file;
    QProgressBar *progress_bar;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(600, 600);
        gridLayout_2 = new QGridLayout(Server);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_3 = new QWidget(Server);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_server_port = new QLineEdit(widget_3);
        line_server_port->setObjectName(QString::fromUtf8("line_server_port"));
        line_server_port->setMinimumSize(QSize(120, 0));
        line_server_port->setMaximumSize(QSize(120, 16777215));
        line_server_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_server_port, 1, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        line_client_ip = new QLineEdit(widget_3);
        line_client_ip->setObjectName(QString::fromUtf8("line_client_ip"));
        line_client_ip->setMinimumSize(QSize(120, 0));
        line_client_ip->setMaximumSize(QSize(120, 16777215));
        line_client_ip->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_client_ip, 0, 5, 1, 1);

        bt_listen = new QPushButton(widget_3);
        bt_listen->setObjectName(QString::fromUtf8("bt_listen"));
        bt_listen->setMinimumSize(QSize(100, 0));
        bt_listen->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(bt_listen, 0, 7, 2, 1);

        line_server_ip = new QLineEdit(widget_3);
        line_server_ip->setObjectName(QString::fromUtf8("line_server_ip"));
        line_server_ip->setMinimumSize(QSize(120, 0));
        line_server_ip->setMaximumSize(QSize(120, 16777215));
        line_server_ip->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_server_ip, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 6, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        line_client_port = new QLineEdit(widget_3);
        line_client_port->setObjectName(QString::fromUtf8("line_client_port"));
        line_client_port->setMinimumSize(QSize(120, 0));
        line_client_port->setMaximumSize(QSize(120, 16777215));
        line_client_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(line_client_port, 1, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 8, 1, 1);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);

        widget = new QWidget(Server);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_recv = new QTextEdit(widget);
        text_recv->setObjectName(QString::fromUtf8("text_recv"));

        verticalLayout->addWidget(text_recv);

        text_send = new QTextEdit(widget);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        verticalLayout->addWidget(text_send);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(Server);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bt_send = new QPushButton(widget_2);
        bt_send->setObjectName(QString::fromUtf8("bt_send"));
        bt_send->setMinimumSize(QSize(100, 0));
        bt_send->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(bt_send);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        bt_file = new QPushButton(widget_2);
        bt_file->setObjectName(QString::fromUtf8("bt_file"));
        bt_file->setMinimumSize(QSize(100, 0));
        bt_file->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(bt_file);

        progress_bar = new QProgressBar(widget_2);
        progress_bar->setObjectName(QString::fromUtf8("progress_bar"));
        progress_bar->setMinimumSize(QSize(100, 0));
        progress_bar->setMaximumSize(QSize(16777215, 16777215));
        progress_bar->setValue(24);

        horizontalLayout->addWidget(progress_bar);


        gridLayout_2->addWidget(widget_2, 2, 0, 1, 1);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        label_3->setText(QCoreApplication::translate("Server", "Client IP:", nullptr));
        bt_listen->setText(QCoreApplication::translate("Server", "Listen", nullptr));
        label_4->setText(QCoreApplication::translate("Server", "Client Port:", nullptr));
        label->setText(QCoreApplication::translate("Server", "Server IP:", nullptr));
        label_2->setText(QCoreApplication::translate("Server", "Server Port:", nullptr));
        bt_send->setText(QCoreApplication::translate("Server", "Send", nullptr));
        bt_file->setText(QCoreApplication::translate("Server", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
