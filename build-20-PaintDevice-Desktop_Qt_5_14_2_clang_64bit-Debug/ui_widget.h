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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *bt_pixmap;
    QPushButton *bt_bitmap;
    QPushButton *bt_image;
    QPushButton *bt_picture;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(430, 0, 141, 401));
        widget->setMinimumSize(QSize(124, 381));
        widget->setContextMenuPolicy(Qt::DefaultContextMenu);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bt_pixmap = new QPushButton(widget);
        bt_pixmap->setObjectName(QString::fromUtf8("bt_pixmap"));

        verticalLayout->addWidget(bt_pixmap);

        bt_bitmap = new QPushButton(widget);
        bt_bitmap->setObjectName(QString::fromUtf8("bt_bitmap"));

        verticalLayout->addWidget(bt_bitmap);

        bt_image = new QPushButton(widget);
        bt_image->setObjectName(QString::fromUtf8("bt_image"));

        verticalLayout->addWidget(bt_image);

        bt_picture = new QPushButton(widget);
        bt_picture->setObjectName(QString::fromUtf8("bt_picture"));

        verticalLayout->addWidget(bt_picture);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        bt_pixmap->setText(QCoreApplication::translate("Widget", "Pixmap", nullptr));
        bt_bitmap->setText(QCoreApplication::translate("Widget", "Bitmap", nullptr));
        bt_image->setText(QCoreApplication::translate("Widget", "Image", nullptr));
        bt_picture->setText(QCoreApplication::translate("Widget", "Picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
