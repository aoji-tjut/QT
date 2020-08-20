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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QPushButton *tab_widget;
    QPushButton *tool_box;
    QStackedWidget *stackedWidget;
    QWidget *stack1;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_56;
    QPushButton *pushButton;
    QPushButton *pushButton_59;
    QPushButton *pushButton_58;
    QPushButton *pushButton_18;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_55;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_60;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_57;
    QPushButton *pushButton_17;
    QPushButton *pushButton_14;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *stack2;
    QGridLayout *gridLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *stack3;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *stack4;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page_4;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *combo_box;
    QPushButton *label_movie;
    QPushButton *scroll_area;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tab_widget = new QPushButton(centralwidget);
        tab_widget->setObjectName(QString::fromUtf8("tab_widget"));

        gridLayout_7->addWidget(tab_widget, 2, 1, 1, 1);

        tool_box = new QPushButton(centralwidget);
        tool_box->setObjectName(QString::fromUtf8("tool_box"));

        gridLayout_7->addWidget(tool_box, 1, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stack1 = new QWidget();
        stack1->setObjectName(QString::fromUtf8("stack1"));
        gridLayout_3 = new QGridLayout(stack1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(stack1);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 264));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_56 = new QPushButton(scrollAreaWidgetContents);
        pushButton_56->setObjectName(QString::fromUtf8("pushButton_56"));

        gridLayout->addWidget(pushButton_56, 2, 4, 1, 1);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_59 = new QPushButton(scrollAreaWidgetContents);
        pushButton_59->setObjectName(QString::fromUtf8("pushButton_59"));

        gridLayout->addWidget(pushButton_59, 4, 4, 1, 1);

        pushButton_58 = new QPushButton(scrollAreaWidgetContents);
        pushButton_58->setObjectName(QString::fromUtf8("pushButton_58"));

        gridLayout->addWidget(pushButton_58, 5, 4, 1, 1);

        pushButton_18 = new QPushButton(scrollAreaWidgetContents);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 5, 2, 1, 1);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 3, 3, 1, 1);

        pushButton_13 = new QPushButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 4, 3, 1, 1);

        pushButton_55 = new QPushButton(scrollAreaWidgetContents);
        pushButton_55->setObjectName(QString::fromUtf8("pushButton_55"));

        gridLayout->addWidget(pushButton_55, 0, 4, 1, 1);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 3, 1, 1);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 2, 1, 1);

        pushButton_60 = new QPushButton(scrollAreaWidgetContents);
        pushButton_60->setObjectName(QString::fromUtf8("pushButton_60"));

        gridLayout->addWidget(pushButton_60, 3, 4, 1, 1);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        pushButton_15 = new QPushButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 4, 2, 1, 1);

        pushButton_16 = new QPushButton(scrollAreaWidgetContents);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 5, 3, 1, 1);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 3, 2, 1, 1);

        pushButton_57 = new QPushButton(scrollAreaWidgetContents);
        pushButton_57->setObjectName(QString::fromUtf8("pushButton_57"));

        gridLayout->addWidget(pushButton_57, 1, 4, 1, 1);

        pushButton_17 = new QPushButton(scrollAreaWidgetContents);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout->addWidget(pushButton_17, 5, 1, 1, 1);

        pushButton_14 = new QPushButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 4, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        stackedWidget->addWidget(stack1);
        stack2 = new QWidget();
        stack2->setObjectName(QString::fromUtf8("stack2"));
        gridLayout_2 = new QGridLayout(stack2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolBox = new QToolBox(stack2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 436, 164));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 436, 164));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("Page 3"));

        gridLayout_2->addWidget(toolBox, 0, 0, 1, 1);

        stackedWidget->addWidget(stack2);
        stack3 = new QWidget();
        stack3->setObjectName(QString::fromUtf8("stack3"));
        gridLayout_4 = new QGridLayout(stack3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(stack3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(stack3);
        stack4 = new QWidget();
        stack4->setObjectName(QString::fromUtf8("stack4"));
        gridLayout_5 = new QGridLayout(stack4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        comboBox = new QComboBox(stack4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_5->addWidget(comboBox, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        stackedWidget->addWidget(stack4);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_6 = new QGridLayout(page_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer = new QSpacerItem(177, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(177, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        stackedWidget->addWidget(page_4);

        gridLayout_7->addWidget(stackedWidget, 0, 0, 5, 1);

        combo_box = new QPushButton(centralwidget);
        combo_box->setObjectName(QString::fromUtf8("combo_box"));

        gridLayout_7->addWidget(combo_box, 3, 1, 1, 1);

        label_movie = new QPushButton(centralwidget);
        label_movie->setObjectName(QString::fromUtf8("label_movie"));

        gridLayout_7->addWidget(label_movie, 4, 1, 1, 1);

        scroll_area = new QPushButton(centralwidget);
        scroll_area->setObjectName(QString::fromUtf8("scroll_area"));

        gridLayout_7->addWidget(scroll_area, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        toolBox->setCurrentIndex(2);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UIOther", nullptr));
        tab_widget->setText(QCoreApplication::translate("MainWindow", "Tab Widget", nullptr));
        tool_box->setText(QCoreApplication::translate("MainWindow", "Tool Box", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_56->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_59->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_58->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_55->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_60->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_57->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Page 2", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Page 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        combo_box->setText(QCoreApplication::translate("MainWindow", "Combo Box", nullptr));
        label_movie->setText(QCoreApplication::translate("MainWindow", "Label Movie", nullptr));
        scroll_area->setText(QCoreApplication::translate("MainWindow", "Scroll Area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
