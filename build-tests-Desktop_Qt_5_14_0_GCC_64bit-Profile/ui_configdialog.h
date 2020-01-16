/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_configDialog
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *userLabel_3;
    QLabel *label_3;
    QLineEdit *clientBackupLine;
    QPushButton *searchBackupButton;
    QPushButton *searchSSHButton;
    QLineEdit *clientKeyLine;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *hostLabel;
    QLineEdit *serverDailyLine;
    QLineEdit *serverHostLine;
    QLabel *userLabel;
    QLabel *hostLabel_2;
    QLineEdit *serverUserLine;
    QLineEdit *serverBackupLine;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName(QString::fromUtf8("configDialog"));
        configDialog->resize(380, 463);
        configDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        gridLayout_5 = new QGridLayout(configDialog);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_5 = new QGroupBox(configDialog);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        userLabel_3 = new QLabel(groupBox_5);
        userLabel_3->setObjectName(QString::fromUtf8("userLabel_3"));
        userLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(userLabel_3, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 2, 0, 1, 1);

        clientBackupLine = new QLineEdit(groupBox_5);
        clientBackupLine->setObjectName(QString::fromUtf8("clientBackupLine"));
        clientBackupLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(clientBackupLine, 1, 2, 1, 3);

        searchBackupButton = new QPushButton(groupBox_5);
        searchBackupButton->setObjectName(QString::fromUtf8("searchBackupButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchBackupButton->sizePolicy().hasHeightForWidth());
        searchBackupButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qss_icons/rc/search_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchBackupButton->setIcon(icon);

        gridLayout_6->addWidget(searchBackupButton, 1, 5, 1, 1);

        searchSSHButton = new QPushButton(groupBox_5);
        searchSSHButton->setObjectName(QString::fromUtf8("searchSSHButton"));
        searchSSHButton->setIcon(icon);
        searchSSHButton->setIconSize(QSize(16, 16));

        gridLayout_6->addWidget(searchSSHButton, 2, 5, 1, 1);

        clientKeyLine = new QLineEdit(groupBox_5);
        clientKeyLine->setObjectName(QString::fromUtf8("clientKeyLine"));

        gridLayout_6->addWidget(clientKeyLine, 2, 2, 1, 3);


        gridLayout_5->addWidget(groupBox_5, 2, 0, 1, 1);

        groupBox = new QGroupBox(configDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hostLabel = new QLabel(groupBox);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));
        hostLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(hostLabel, 6, 0, 1, 1);

        serverDailyLine = new QLineEdit(groupBox);
        serverDailyLine->setObjectName(QString::fromUtf8("serverDailyLine"));
        serverDailyLine->setEchoMode(QLineEdit::Normal);
        serverDailyLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(serverDailyLine, 8, 1, 1, 1);

        serverHostLine = new QLineEdit(groupBox);
        serverHostLine->setObjectName(QString::fromUtf8("serverHostLine"));
        serverHostLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(serverHostLine, 6, 1, 1, 1);

        userLabel = new QLabel(groupBox);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(userLabel, 3, 0, 1, 1);

        hostLabel_2 = new QLabel(groupBox);
        hostLabel_2->setObjectName(QString::fromUtf8("hostLabel_2"));
        hostLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(hostLabel_2, 8, 0, 1, 1);

        serverUserLine = new QLineEdit(groupBox);
        serverUserLine->setObjectName(QString::fromUtf8("serverUserLine"));
        serverUserLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(serverUserLine, 3, 1, 1, 1);

        serverBackupLine = new QLineEdit(groupBox);
        serverBackupLine->setObjectName(QString::fromUtf8("serverBackupLine"));
        serverBackupLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(serverBackupLine, 9, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 9, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(configDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(configDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), configDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QCoreApplication::translate("configDialog", "Connect", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("configDialog", "CLIENT", nullptr));
        userLabel_3->setText(QCoreApplication::translate("configDialog", "Backup", nullptr));
        label_3->setText(QCoreApplication::translate("configDialog", "SSH Key", nullptr));
        clientBackupLine->setPlaceholderText(QString());
        searchBackupButton->setText(QString());
        searchSSHButton->setText(QString());
        clientKeyLine->setPlaceholderText(QString());
        groupBox->setTitle(QCoreApplication::translate("configDialog", "SERVER", nullptr));
        hostLabel->setText(QCoreApplication::translate("configDialog", "Hostname", nullptr));
        serverDailyLine->setPlaceholderText(QString());
        serverHostLine->setPlaceholderText(QString());
        userLabel->setText(QCoreApplication::translate("configDialog", "Username", nullptr));
        hostLabel_2->setText(QCoreApplication::translate("configDialog", "DailyBackup", nullptr));
        serverUserLine->setPlaceholderText(QString());
        serverBackupLine->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("configDialog", "Backup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
