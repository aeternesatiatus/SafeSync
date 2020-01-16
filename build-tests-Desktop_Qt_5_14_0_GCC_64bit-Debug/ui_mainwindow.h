/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *settingsGroup;
    QGridLayout *gridLayout_3;
    QGroupBox *serverSettingsGroup;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *CServerHostButton;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *CServerUserButton;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *CServerDailyButton;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer;
    QPushButton *CServerBackupButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *clientSettingsGroup;
    QGridLayout *gridLayout_5;
    QPushButton *changeSSHButton;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *changeBackupButton;
    QGroupBox *resetSettingsGroup;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *hResetButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *CSearchButton;
    QPushButton *CSyncButton;
    QPushButton *CLogButton;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_18;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(609, 438);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"    border-width: 1px;\n"
"    border-color: rgb(80, 80, 80);\n"
"    border-style: solid;\n"
"    padding: 5px;\n"
"    border-radius: 0px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(219, 219, 219, 255), stop:1 rgba(255, 255, 255, 255));\n"
"    border-color: rgb(54, 159, 190);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(221, 221, 221, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QGroupBox {\n"
"    color: rgb(0, 0, 0);\n"
"    font-size: 12px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        settingsGroup = new QGroupBox(centralWidget);
        settingsGroup->setObjectName(QString::fromUtf8("settingsGroup"));
        gridLayout_3 = new QGridLayout(settingsGroup);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        serverSettingsGroup = new QGroupBox(settingsGroup);
        serverSettingsGroup->setObjectName(QString::fromUtf8("serverSettingsGroup"));
        gridLayout_4 = new QGridLayout(serverSettingsGroup);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        CServerHostButton = new QPushButton(serverSettingsGroup);
        CServerHostButton->setObjectName(QString::fromUtf8("CServerHostButton"));

        gridLayout_4->addWidget(CServerHostButton, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 0, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 1, 0, 1, 1);

        CServerUserButton = new QPushButton(serverSettingsGroup);
        CServerUserButton->setObjectName(QString::fromUtf8("CServerUserButton"));

        gridLayout_4->addWidget(CServerUserButton, 1, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_14, 1, 2, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_21, 2, 0, 1, 1);

        CServerDailyButton = new QPushButton(serverSettingsGroup);
        CServerDailyButton->setObjectName(QString::fromUtf8("CServerDailyButton"));

        gridLayout_4->addWidget(CServerDailyButton, 2, 1, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_22, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 3, 0, 1, 1);

        CServerBackupButton = new QPushButton(serverSettingsGroup);
        CServerBackupButton->setObjectName(QString::fromUtf8("CServerBackupButton"));

        gridLayout_4->addWidget(CServerBackupButton, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 3, 2, 1, 1);


        gridLayout_3->addWidget(serverSettingsGroup, 0, 0, 2, 2);

        clientSettingsGroup = new QGroupBox(settingsGroup);
        clientSettingsGroup->setObjectName(QString::fromUtf8("clientSettingsGroup"));
        gridLayout_5 = new QGridLayout(clientSettingsGroup);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        changeSSHButton = new QPushButton(clientSettingsGroup);
        changeSSHButton->setObjectName(QString::fromUtf8("changeSSHButton"));

        gridLayout_5->addWidget(changeSSHButton, 1, 1, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_26, 0, 2, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_25, 0, 0, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_20, 1, 2, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_19, 1, 0, 1, 1);

        changeBackupButton = new QPushButton(clientSettingsGroup);
        changeBackupButton->setObjectName(QString::fromUtf8("changeBackupButton"));

        gridLayout_5->addWidget(changeBackupButton, 0, 1, 1, 1);


        gridLayout_3->addWidget(clientSettingsGroup, 2, 0, 1, 2);

        resetSettingsGroup = new QGroupBox(settingsGroup);
        resetSettingsGroup->setObjectName(QString::fromUtf8("resetSettingsGroup"));
        gridLayout_2 = new QGridLayout(resetSettingsGroup);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        resetButton = new QPushButton(resetSettingsGroup);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout_2->addWidget(resetButton, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        hResetButton = new QPushButton(resetSettingsGroup);
        hResetButton->setObjectName(QString::fromUtf8("hResetButton"));

        gridLayout_2->addWidget(hResetButton, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 2, 1, 1);

        CSearchButton = new QPushButton(resetSettingsGroup);
        CSearchButton->setObjectName(QString::fromUtf8("CSearchButton"));

        gridLayout_2->addWidget(CSearchButton, 3, 1, 1, 1);

        CSyncButton = new QPushButton(resetSettingsGroup);
        CSyncButton->setObjectName(QString::fromUtf8("CSyncButton"));

        gridLayout_2->addWidget(CSyncButton, 2, 1, 1, 1);

        CLogButton = new QPushButton(resetSettingsGroup);
        CLogButton->setObjectName(QString::fromUtf8("CLogButton"));

        gridLayout_2->addWidget(CLogButton, 4, 1, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_17, 4, 0, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 4, 2, 1, 1);


        gridLayout_3->addWidget(resetSettingsGroup, 0, 2, 3, 1);


        gridLayout->addWidget(settingsGroup, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        settingsGroup->setTitle(QCoreApplication::translate("MainWindow", "SETTINGS", nullptr));
        serverSettingsGroup->setTitle(QCoreApplication::translate("MainWindow", "SERVER", nullptr));
        CServerHostButton->setText(QCoreApplication::translate("MainWindow", "Change Hostname", nullptr));
        CServerUserButton->setText(QCoreApplication::translate("MainWindow", "Change Username", nullptr));
        CServerDailyButton->setText(QCoreApplication::translate("MainWindow", "Change DailyBackup Path", nullptr));
        CServerBackupButton->setText(QCoreApplication::translate("MainWindow", "Change Backup Path", nullptr));
        clientSettingsGroup->setTitle(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        changeSSHButton->setText(QCoreApplication::translate("MainWindow", "Change SSH Key Path", nullptr));
        changeBackupButton->setText(QCoreApplication::translate("MainWindow", "Change Backup Path", nullptr));
        resetSettingsGroup->setTitle(QString());
        resetButton->setText(QCoreApplication::translate("MainWindow", "SOFT RESET", nullptr));
        hResetButton->setText(QCoreApplication::translate("MainWindow", "HARD RESET", nullptr));
        CSearchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        CSyncButton->setText(QCoreApplication::translate("MainWindow", "Manual Sync", nullptr));
        CLogButton->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
