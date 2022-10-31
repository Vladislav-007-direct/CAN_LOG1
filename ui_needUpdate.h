/********************************************************************************
** Form generated from reading UI file 'needUpdate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEEDUPDATE_H
#define UI_NEEDUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NeedUpdate
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NeedUpdate)
    {
        if (NeedUpdate->objectName().isEmpty())
            NeedUpdate->setObjectName(QString::fromUtf8("NeedUpdate"));
        NeedUpdate->resize(400, 101);
        verticalLayout = new QVBoxLayout(NeedUpdate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(NeedUpdate);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(NeedUpdate);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NeedUpdate);
        QObject::connect(buttonBox, SIGNAL(accepted()), NeedUpdate, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NeedUpdate, SLOT(reject()));

        QMetaObject::connectSlotsByName(NeedUpdate);
    } // setupUi

    void retranslateUi(QDialog *NeedUpdate)
    {
        NeedUpdate->setWindowTitle(QCoreApplication::translate("NeedUpdate", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NeedUpdate", "\320\230\320\274\320\265\320\265\321\202\321\201\321\217 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260. \320\235\320\260\321\207\320\260\321\202\321\214 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeedUpdate: public Ui_NeedUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEEDUPDATE_H
