/********************************************************************************
** Form generated from reading UI file 'cansendwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANSENDWIDGET_H
#define UI_CANSENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CANSendWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *send;
    QPushButton *stop;
    QLabel *label_2;
    QLineEdit *repeats;
    QSpacerItem *horizontalSpacer;
    QPushButton *load;
    QPushButton *save;
    QScrollArea *scrollArea;
    QWidget *sendWidgetList;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *CANSendWindow)
    {
        if (CANSendWindow->objectName().isEmpty())
            CANSendWindow->setObjectName(QString::fromUtf8("CANSendWindow"));
        CANSendWindow->resize(668, 530);
        verticalLayout = new QVBoxLayout(CANSendWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        send = new QPushButton(CANSendWindow);
        send->setObjectName(QString::fromUtf8("send"));

        horizontalLayout->addWidget(send);

        stop = new QPushButton(CANSendWindow);
        stop->setObjectName(QString::fromUtf8("stop"));

        horizontalLayout->addWidget(stop);

        label_2 = new QLabel(CANSendWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        repeats = new QLineEdit(CANSendWindow);
        repeats->setObjectName(QString::fromUtf8("repeats"));
        repeats->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(repeats);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        load = new QPushButton(CANSendWindow);
        load->setObjectName(QString::fromUtf8("load"));

        horizontalLayout->addWidget(load);

        save = new QPushButton(CANSendWindow);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout->addWidget(save);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(CANSendWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        sendWidgetList = new QWidget();
        sendWidgetList->setObjectName(QString::fromUtf8("sendWidgetList"));
        sendWidgetList->setGeometry(QRect(0, 0, 648, 479));
        verticalLayout_2 = new QVBoxLayout(sendWidgetList);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea->setWidget(sendWidgetList);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(CANSendWindow);

        QMetaObject::connectSlotsByName(CANSendWindow);
    } // setupUi

    void retranslateUi(QWidget *CANSendWindow)
    {
        CANSendWindow->setWindowTitle(QCoreApplication::translate("CANSendWindow", "Form", nullptr));
        send->setText(QCoreApplication::translate("CANSendWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        stop->setText(QCoreApplication::translate("CANSendWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("CANSendWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\271 \320\276\320\261\321\211\320\265\320\263\320\276 \321\206\320\270\320\272\320\273\320\260:", nullptr));
        repeats->setText(QCoreApplication::translate("CANSendWindow", "1", nullptr));
        load->setText(QCoreApplication::translate("CANSendWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        save->setText(QCoreApplication::translate("CANSendWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CANSendWindow: public Ui_CANSendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANSENDWIDGET_H
