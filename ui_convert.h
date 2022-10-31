/********************************************************************************
** Form generated from reading UI file 'convert.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERT_H
#define UI_CONVERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *openfiles;
    QListWidget *files;
    QPushButton *convert;
    QProgressBar *progress;
    QLabel *status;

    void setupUi(QWidget *ConvertForm)
    {
        if (ConvertForm->objectName().isEmpty())
            ConvertForm->setObjectName(QString::fromUtf8("ConvertForm"));
        ConvertForm->resize(332, 223);
        ConvertForm->setAcceptDrops(true);
        gridLayout_2 = new QGridLayout(ConvertForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openfiles = new QPushButton(ConvertForm);
        openfiles->setObjectName(QString::fromUtf8("openfiles"));

        gridLayout->addWidget(openfiles, 2, 0, 1, 1);

        files = new QListWidget(ConvertForm);
        files->setObjectName(QString::fromUtf8("files"));

        gridLayout->addWidget(files, 0, 0, 1, 1);

        convert = new QPushButton(ConvertForm);
        convert->setObjectName(QString::fromUtf8("convert"));

        gridLayout->addWidget(convert, 2, 1, 1, 1);

        progress = new QProgressBar(ConvertForm);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(0);
        progress->setTextVisible(false);

        gridLayout->addWidget(progress, 3, 1, 1, 1);

        status = new QLabel(ConvertForm);
        status->setObjectName(QString::fromUtf8("status"));

        gridLayout->addWidget(status, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ConvertForm);

        QMetaObject::connectSlotsByName(ConvertForm);
    } // setupUi

    void retranslateUi(QWidget *ConvertForm)
    {
        ConvertForm->setWindowTitle(QCoreApplication::translate("ConvertForm", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\276\321\200 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        openfiles->setText(QCoreApplication::translate("ConvertForm", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213...", nullptr));
        convert->setText(QCoreApplication::translate("ConvertForm", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConvertForm: public Ui_ConvertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERT_H
