/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_FindDevices;
    QTextBrowser *textBrowser_USRPinfo;
    QGridLayout *gridLayout_4;
    QCustomPlot *customPlot1;
    QTabWidget *tabWidget;
    QWidget *tab_ChannelA;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_BandwidthMHzCH0;
    QLineEdit *lineEdit_GaindBCH0;
    QLineEdit *lineEdit_FreqGHzCH0;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox_AntennaCH0;
    QWidget *tab_ChannelB;
    QPushButton *pushButton_Plot;
    QPushButton *pushButton_AddData;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_Connect = new QPushButton(centralwidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setEnabled(false);

        gridLayout_3->addWidget(pushButton_Connect, 0, 1, 1, 1);

        pushButton_FindDevices = new QPushButton(centralwidget);
        pushButton_FindDevices->setObjectName(QStringLiteral("pushButton_FindDevices"));

        gridLayout_3->addWidget(pushButton_FindDevices, 0, 0, 1, 1);

        textBrowser_USRPinfo = new QTextBrowser(centralwidget);
        textBrowser_USRPinfo->setObjectName(QStringLiteral("textBrowser_USRPinfo"));

        gridLayout_3->addWidget(textBrowser_USRPinfo, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        customPlot1 = new QCustomPlot(centralwidget);
        customPlot1->setObjectName(QStringLiteral("customPlot1"));

        gridLayout_4->addWidget(customPlot1, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout_4);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_ChannelA = new QWidget();
        tab_ChannelA->setObjectName(QStringLiteral("tab_ChannelA"));
        gridLayout_2 = new QGridLayout(tab_ChannelA);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(tab_ChannelA);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_BandwidthMHzCH0 = new QLineEdit(tab_ChannelA);
        lineEdit_BandwidthMHzCH0->setObjectName(QStringLiteral("lineEdit_BandwidthMHzCH0"));

        gridLayout->addWidget(lineEdit_BandwidthMHzCH0, 1, 1, 1, 1);

        lineEdit_GaindBCH0 = new QLineEdit(tab_ChannelA);
        lineEdit_GaindBCH0->setObjectName(QStringLiteral("lineEdit_GaindBCH0"));

        gridLayout->addWidget(lineEdit_GaindBCH0, 2, 1, 1, 1);

        lineEdit_FreqGHzCH0 = new QLineEdit(tab_ChannelA);
        lineEdit_FreqGHzCH0->setObjectName(QStringLiteral("lineEdit_FreqGHzCH0"));

        gridLayout->addWidget(lineEdit_FreqGHzCH0, 0, 1, 1, 1);

        lineEdit_6 = new QLineEdit(tab_ChannelA);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        lineEdit_5 = new QLineEdit(tab_ChannelA);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label = new QLabel(tab_ChannelA);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab_ChannelA);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_ChannelA);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 6, 1, 1, 1);

        label_4 = new QLabel(tab_ChannelA);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(tab_ChannelA);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(tab_ChannelA);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(tab_ChannelA);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        comboBox_AntennaCH0 = new QComboBox(tab_ChannelA);
        comboBox_AntennaCH0->setObjectName(QStringLiteral("comboBox_AntennaCH0"));
        comboBox_AntennaCH0->setEditable(false);

        gridLayout->addWidget(comboBox_AntennaCH0, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_ChannelA, QString());
        tab_ChannelB = new QWidget();
        tab_ChannelB->setObjectName(QStringLiteral("tab_ChannelB"));
        tabWidget->addTab(tab_ChannelB, QString());

        formLayout->setWidget(1, QFormLayout::LabelRole, tabWidget);

        pushButton_Plot = new QPushButton(centralwidget);
        pushButton_Plot->setObjectName(QStringLiteral("pushButton_Plot"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_Plot);

        pushButton_AddData = new QPushButton(centralwidget);
        pushButton_AddData->setObjectName(QStringLiteral("pushButton_AddData"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_AddData);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        pushButton_FindDevices->setText(QApplication::translate("MainWindow", "Find Devices", 0));
        label_2->setText(QApplication::translate("MainWindow", "Bandwidth [MHz]", 0));
        lineEdit_BandwidthMHzCH0->setText(QApplication::translate("MainWindow", "50", 0));
        lineEdit_GaindBCH0->setText(QApplication::translate("MainWindow", "60", 0));
        lineEdit_FreqGHzCH0->setText(QApplication::translate("MainWindow", "2.45", 0));
        label->setText(QApplication::translate("MainWindow", "Frequency [GHz]", 0));
        label_3->setText(QApplication::translate("MainWindow", "Gain [dB]", 0));
        label_4->setText(QApplication::translate("MainWindow", "Antenna", 0));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        comboBox_AntennaCH0->clear();
        comboBox_AntennaCH0->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TX/RX", 0)
         << QApplication::translate("MainWindow", "RX2", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_ChannelA), QApplication::translate("MainWindow", "Channel A", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_ChannelB), QApplication::translate("MainWindow", "Channel B", 0));
        pushButton_Plot->setText(QApplication::translate("MainWindow", "Plot", 0));
        pushButton_AddData->setText(QApplication::translate("MainWindow", "Add data", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
