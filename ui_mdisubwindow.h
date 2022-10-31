/********************************************************************************
** Form generated from reading UI file 'mdisubwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDISUBWINDOW_H
#define UI_MDISUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiSubWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *header;
    QPlainTextEdit *log;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveLog;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *send;
    QPushButton *clear;

    void setupUi(QWidget *MdiSubWindow)
    {
        if (MdiSubWindow->objectName().isEmpty())
            MdiSubWindow->setObjectName(QString::fromUtf8("MdiSubWindow"));
        MdiSubWindow->resize(658, 479);
        verticalLayout = new QVBoxLayout(MdiSubWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        header = new QLineEdit(MdiSubWindow);
        header->setObjectName(QString::fromUtf8("header"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        header->setFrame(false);
        header->setReadOnly(true);

        verticalLayout->addWidget(header);

        log = new QPlainTextEdit(MdiSubWindow);
        log->setObjectName(QString::fromUtf8("log"));
        log->setFont(font);
        log->setReadOnly(true);
        log->setMaximumBlockCount(1000000);

        verticalLayout->addWidget(log);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveLog = new QPushButton(MdiSubWindow);
        saveLog->setObjectName(QString::fromUtf8("saveLog"));

        horizontalLayout->addWidget(saveLog);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MdiSubWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        send = new QPushButton(MdiSubWindow);
        send->setObjectName(QString::fromUtf8("send"));

        horizontalLayout->addWidget(send);

        clear = new QPushButton(MdiSubWindow);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setMaximumSize(QSize(300, 16777215));
        clear->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(clear);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MdiSubWindow);

        QMetaObject::connectSlotsByName(MdiSubWindow);
    } // setupUi

    void retranslateUi(QWidget *MdiSubWindow)
    {
        MdiSubWindow->setWindowTitle(QCoreApplication::translate("MdiSubWindow", "Form", nullptr));
        header->setText(QString());
        saveLog->setText(QCoreApplication::translate("MdiSubWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        pushButton->setText(QCoreApplication::translate("MdiSubWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        send->setText(QCoreApplication::translate("MdiSubWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \320\272\320\260\320\264\321\200\320\276\320\262", nullptr));
        clear->setText(QCoreApplication::translate("MdiSubWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\213\320\262\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MdiSubWindow: public Ui_MdiSubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDISUBWINDOW_H
