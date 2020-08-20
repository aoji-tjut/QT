/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 50));

        verticalLayout->addWidget(pushButton);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(200, 50));
        QFont font;
        font.setPointSize(13);
        toolButton->setFont(font);
        toolButton->setTabletTracking(false);
        toolButton->setFocusPolicy(Qt::TabFocus);
        toolButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/source/LiAo.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setCheckable(false);
        toolButton->setAutoRepeat(false);
        toolButton->setAutoExclusive(false);
        toolButton->setPopupMode(QToolButton::DelayedPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setAutoRaise(false);
        toolButton->setArrowType(Qt::NoArrow);

        verticalLayout->addWidget(toolButton);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton1 = new QRadioButton(groupBox);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));

        verticalLayout_2->addWidget(radioButton1);

        radioButton2 = new QRadioButton(groupBox);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        verticalLayout_2->addWidget(radioButton2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton3 = new QRadioButton(groupBox_2);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));

        verticalLayout_4->addWidget(radioButton3);

        radioButton4 = new QRadioButton(groupBox_2);
        radioButton4->setObjectName(QString::fromUtf8("radioButton4"));

        verticalLayout_4->addWidget(radioButton4);


        verticalLayout_3->addWidget(groupBox_2);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        checkBox1 = new QCheckBox(groupBox_3);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setTristate(true);

        verticalLayout_5->addWidget(checkBox1);

        checkBox2 = new QCheckBox(groupBox_3);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));
        checkBox2->setTristate(true);

        verticalLayout_5->addWidget(checkBox2);

        checkBox3 = new QCheckBox(groupBox_3);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));

        verticalLayout_5->addWidget(checkBox3);

        checkBox4 = new QCheckBox(groupBox_3);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));

        verticalLayout_5->addWidget(checkBox4);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UIButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "ToolButton", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox1", nullptr));
        radioButton1->setText(QCoreApplication::translate("MainWindow", "RadioButton1", nullptr));
        radioButton2->setText(QCoreApplication::translate("MainWindow", "RadioButton2", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox2", nullptr));
        radioButton3->setText(QCoreApplication::translate("MainWindow", "RadioButton3", nullptr));
        radioButton4->setText(QCoreApplication::translate("MainWindow", "RadioButton4", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "GroupBox3", nullptr));
        checkBox1->setText(QCoreApplication::translate("MainWindow", "CheckBox1", nullptr));
        checkBox2->setText(QCoreApplication::translate("MainWindow", "CheckBox2", nullptr));
        checkBox3->setText(QCoreApplication::translate("MainWindow", "CheckBox3", nullptr));
        checkBox4->setText(QCoreApplication::translate("MainWindow", "CheckBox4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
