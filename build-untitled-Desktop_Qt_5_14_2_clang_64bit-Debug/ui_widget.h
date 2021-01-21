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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget_2;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(671, 478);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 631, 101));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 81, 41));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 40, 112, 32));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 40, 112, 32));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 40, 171, 32));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 130, 631, 321));
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 30, 211, 251));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(390, 30, 211, 251));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\237\272\344\272\216\345\217\214\351\200\232\351\201\223\347\232\204\347\273\206\350\203\236\345\233\242\345\235\227\345\210\206\345\211\262\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\273\206\350\203\236\345\233\242\345\235\227\345\210\206\345\211\262", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\347\273\206\350\203\236\346\240\270\345\210\206\345\211\262", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\233\242\345\235\227\344\270\255\345\215\225\344\270\252\347\273\206\350\203\236\345\210\206\345\211\262", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\350\257\267\344\270\212\344\274\240\345\233\276\345\203\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\210\206\345\211\262\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
