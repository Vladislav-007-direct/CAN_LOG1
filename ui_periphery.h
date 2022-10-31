/********************************************************************************
** Form generated from reading UI file 'periphery.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIPHERY_H
#define UI_PERIPHERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Periphery
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *vparmsScroll_4;
    QWidget *scrollAreaWidgetContents_9;
    QVBoxLayout *verticalLayout_39;
    QVBoxLayout *ainsVLt;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *log;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addElement;
    QPushButton *sendPeriphery;
    QPushButton *updatePeriphery;

    void setupUi(QDialog *Periphery)
    {
        if (Periphery->objectName().isEmpty())
            Periphery->setObjectName(QString::fromUtf8("Periphery"));
        Periphery->resize(891, 659);
        verticalLayout = new QVBoxLayout(Periphery);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vparmsScroll_4 = new QScrollArea(Periphery);
        vparmsScroll_4->setObjectName(QString::fromUtf8("vparmsScroll_4"));
        vparmsScroll_4->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 869, 437));
        verticalLayout_39 = new QVBoxLayout(scrollAreaWidgetContents_9);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        ainsVLt = new QVBoxLayout();
        ainsVLt->setObjectName(QString::fromUtf8("ainsVLt"));
        verticalSpacer_8 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ainsVLt->addItem(verticalSpacer_8);


        verticalLayout_39->addLayout(ainsVLt);

        vparmsScroll_4->setWidget(scrollAreaWidgetContents_9);

        verticalLayout_2->addWidget(vparmsScroll_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        log = new QPlainTextEdit(Periphery);
        log->setObjectName(QString::fromUtf8("log"));

        horizontalLayout->addWidget(log);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addElement = new QPushButton(Periphery);
        addElement->setObjectName(QString::fromUtf8("addElement"));

        verticalLayout_3->addWidget(addElement);

        sendPeriphery = new QPushButton(Periphery);
        sendPeriphery->setObjectName(QString::fromUtf8("sendPeriphery"));

        verticalLayout_3->addWidget(sendPeriphery);

        updatePeriphery = new QPushButton(Periphery);
        updatePeriphery->setObjectName(QString::fromUtf8("updatePeriphery"));

        verticalLayout_3->addWidget(updatePeriphery);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(Periphery);

        QMetaObject::connectSlotsByName(Periphery);
    } // setupUi

    void retranslateUi(QDialog *Periphery)
    {
        Periphery->setWindowTitle(QCoreApplication::translate("Periphery", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\277\320\265\321\200\320\270\321\204\320\265\321\200\320\270\320\270 (\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262)", nullptr));
        addElement->setText(QCoreApplication::translate("Periphery", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        sendPeriphery->setText(QCoreApplication::translate("Periphery", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        updatePeriphery->setText(QCoreApplication::translate("Periphery", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Periphery: public Ui_Periphery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIPHERY_H
