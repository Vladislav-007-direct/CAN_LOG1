/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FwDialog
{
public:
    QPlainTextEdit *log;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *dev_fw_info;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLabel *have_fw_info;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *updatebn;
    QPushButton *closebn;
    QProgressBar *progressBar;
    QLabel *status;

    void setupUi(QDialog *FwDialog)
    {
        if (FwDialog->objectName().isEmpty())
            FwDialog->setObjectName(QString::fromUtf8("FwDialog"));
        FwDialog->resize(331, 301);
        log = new QPlainTextEdit(FwDialog);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(10, 10, 311, 131));
        log->setReadOnly(true);
        groupBox = new QGroupBox(FwDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 151, 80));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 131, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dev_fw_info = new QLabel(formLayoutWidget);
        dev_fw_info->setObjectName(QString::fromUtf8("dev_fw_info"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dev_fw_info);

        groupBox_2 = new QGroupBox(FwDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(160, 150, 161, 80));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 20, 141, 51));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        have_fw_info = new QLabel(formLayoutWidget_2);
        have_fw_info->setObjectName(QString::fromUtf8("have_fw_info"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, have_fw_info);

        horizontalLayoutWidget = new QWidget(FwDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 230, 317, 56));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        updatebn = new QPushButton(horizontalLayoutWidget);
        updatebn->setObjectName(QString::fromUtf8("updatebn"));
        updatebn->setEnabled(false);

        verticalLayout->addWidget(updatebn);

        closebn = new QPushButton(horizontalLayoutWidget);
        closebn->setObjectName(QString::fromUtf8("closebn"));

        verticalLayout->addWidget(closebn);


        horizontalLayout->addLayout(verticalLayout);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);

        status = new QLabel(horizontalLayoutWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setMinimumSize(QSize(60, 0));

        horizontalLayout->addWidget(status);


        retranslateUi(FwDialog);
        QObject::connect(closebn, SIGNAL(clicked()), FwDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FwDialog);
    } // setupUi

    void retranslateUi(QDialog *FwDialog)
    {
        FwDialog->setWindowTitle(QCoreApplication::translate("FwDialog", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FwDialog", "\320\222\320\265\321\200\321\201\320\270\321\217 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("FwDialog", "FW", nullptr));
        dev_fw_info->setText(QCoreApplication::translate("FwDialog", "---", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FwDialog", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\260\321\217 \320\262\320\265\321\200\321\201\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("FwDialog", "FW", nullptr));
        have_fw_info->setText(QCoreApplication::translate("FwDialog", "---", nullptr));
        updatebn->setText(QCoreApplication::translate("FwDialog", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        closebn->setText(QCoreApplication::translate("FwDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FwDialog: public Ui_FwDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
