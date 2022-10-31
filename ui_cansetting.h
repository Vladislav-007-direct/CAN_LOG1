/********************************************************************************
** Form generated from reading UI file 'cansetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANSETTING_H
#define UI_CANSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CANSetting
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QComboBox *canTypeID;
    QLabel *label_11;
    QComboBox *canSpeed;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *can1_protocol_lb;
    QComboBox *canMode;
    QLabel *label_13;
    QComboBox *canProtocol;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *canLogging;
    QCheckBox *canFilter;
    QCheckBox *canAddOptions;
    QGroupBox *additionalSettingsGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *canIDHEX;
    QLabel *label_2;
    QComboBox *canIDcondition;
    QLabel *label_3;
    QLineEdit *canIDvalue;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QListWidget *startByteLength;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *log;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendConfig;

    void setupUi(QDialog *CANSetting)
    {
        if (CANSetting->objectName().isEmpty())
            CANSetting->setObjectName(QString::fromUtf8("CANSetting"));
        CANSetting->resize(419, 357);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CANSetting->sizePolicy().hasHeightForWidth());
        CANSetting->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(CANSetting);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_15 = new QLabel(CANSetting);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_15);

        canTypeID = new QComboBox(CANSetting);
        canTypeID->addItem(QString());
        canTypeID->addItem(QString());
        canTypeID->setObjectName(QString::fromUtf8("canTypeID"));
        sizePolicy.setHeightForWidth(canTypeID->sizePolicy().hasHeightForWidth());
        canTypeID->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(canTypeID);

        label_11 = new QLabel(CANSetting);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_11);

        canSpeed = new QComboBox(CANSetting);
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->addItem(QString());
        canSpeed->setObjectName(QString::fromUtf8("canSpeed"));
        sizePolicy.setHeightForWidth(canSpeed->sizePolicy().hasHeightForWidth());
        canSpeed->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(canSpeed);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        can1_protocol_lb = new QLabel(CANSetting);
        can1_protocol_lb->setObjectName(QString::fromUtf8("can1_protocol_lb"));
        can1_protocol_lb->setEnabled(false);

        horizontalLayout_5->addWidget(can1_protocol_lb);

        canMode = new QComboBox(CANSetting);
        canMode->addItem(QString());
        canMode->addItem(QString());
        canMode->setObjectName(QString::fromUtf8("canMode"));
        canMode->setEnabled(false);

        horizontalLayout_5->addWidget(canMode);

        label_13 = new QLabel(CANSetting);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setEnabled(false);

        horizontalLayout_5->addWidget(label_13);

        canProtocol = new QComboBox(CANSetting);
        canProtocol->addItem(QString());
        canProtocol->addItem(QString());
        canProtocol->addItem(QString());
        canProtocol->addItem(QString());
        canProtocol->addItem(QString());
        canProtocol->setObjectName(QString::fromUtf8("canProtocol"));
        canProtocol->setEnabled(false);

        horizontalLayout_5->addWidget(canProtocol);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        canLogging = new QCheckBox(CANSetting);
        canLogging->setObjectName(QString::fromUtf8("canLogging"));

        verticalLayout_2->addWidget(canLogging);

        canFilter = new QCheckBox(CANSetting);
        canFilter->setObjectName(QString::fromUtf8("canFilter"));

        verticalLayout_2->addWidget(canFilter);

        canAddOptions = new QCheckBox(CANSetting);
        canAddOptions->setObjectName(QString::fromUtf8("canAddOptions"));

        verticalLayout_2->addWidget(canAddOptions);

        additionalSettingsGroup = new QGroupBox(CANSetting);
        additionalSettingsGroup->setObjectName(QString::fromUtf8("additionalSettingsGroup"));
        additionalSettingsGroup->setEnabled(false);
        verticalLayout = new QVBoxLayout(additionalSettingsGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(additionalSettingsGroup);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        canIDHEX = new QLineEdit(additionalSettingsGroup);
        canIDHEX->setObjectName(QString::fromUtf8("canIDHEX"));
        sizePolicy.setHeightForWidth(canIDHEX->sizePolicy().hasHeightForWidth());
        canIDHEX->setSizePolicy(sizePolicy);
        canIDHEX->setMaximumSize(QSize(65, 16777215));
        canIDHEX->setMaxLength(11);

        horizontalLayout->addWidget(canIDHEX);

        label_2 = new QLabel(additionalSettingsGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        canIDcondition = new QComboBox(additionalSettingsGroup);
        canIDcondition->addItem(QString());
        canIDcondition->addItem(QString());
        canIDcondition->addItem(QString());
        canIDcondition->addItem(QString());
        canIDcondition->addItem(QString());
        canIDcondition->addItem(QString());
        canIDcondition->setObjectName(QString::fromUtf8("canIDcondition"));

        horizontalLayout->addWidget(canIDcondition);

        label_3 = new QLabel(additionalSettingsGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        canIDvalue = new QLineEdit(additionalSettingsGroup);
        canIDvalue->setObjectName(QString::fromUtf8("canIDvalue"));
        sizePolicy.setHeightForWidth(canIDvalue->sizePolicy().hasHeightForWidth());
        canIDvalue->setSizePolicy(sizePolicy);
        canIDvalue->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(canIDvalue);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(additionalSettingsGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        startByteLength = new QListWidget(additionalSettingsGroup);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        new QListWidgetItem(startByteLength);
        startByteLength->setObjectName(QString::fromUtf8("startByteLength"));
        sizePolicy.setHeightForWidth(startByteLength->sizePolicy().hasHeightForWidth());
        startByteLength->setSizePolicy(sizePolicy);
        startByteLength->setMaximumSize(QSize(150, 20));
        startByteLength->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        startByteLength->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        startByteLength->setAutoScroll(false);
        startByteLength->setProperty("showDropIndicator", QVariant(false));
        startByteLength->setSelectionMode(QAbstractItemView::ContiguousSelection);
        startByteLength->setFlow(QListView::LeftToRight);

        horizontalLayout_2->addWidget(startByteLength);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(additionalSettingsGroup);

        log = new QPlainTextEdit(CANSetting);
        log->setObjectName(QString::fromUtf8("log"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy2);
        log->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        log->setFont(font);
        log->setReadOnly(true);

        verticalLayout_2->addWidget(log);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        sendConfig = new QPushButton(CANSetting);
        sendConfig->setObjectName(QString::fromUtf8("sendConfig"));
        sizePolicy.setHeightForWidth(sendConfig->sizePolicy().hasHeightForWidth());
        sendConfig->setSizePolicy(sizePolicy);
        sendConfig->setMinimumSize(QSize(40, 0));

        horizontalLayout_3->addWidget(sendConfig);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(CANSetting);
        QObject::connect(canAddOptions, SIGNAL(toggled(bool)), additionalSettingsGroup, SLOT(setEnabled(bool)));

        canTypeID->setCurrentIndex(1);
        canSpeed->setCurrentIndex(0);
        canMode->setCurrentIndex(1);
        canProtocol->setCurrentIndex(1);
        startByteLength->setCurrentRow(0);


        QMetaObject::connectSlotsByName(CANSetting);
    } // setupUi

    void retranslateUi(QDialog *CANSetting)
    {
        CANSetting->setWindowTitle(QCoreApplication::translate("CANSetting", "Dialog", nullptr));
        label_15->setText(QCoreApplication::translate("CANSetting", "\320\242\320\270\320\277 \320\270\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200\320\260:", nullptr));
        canTypeID->setItemText(0, QCoreApplication::translate("CANSetting", "11bit", nullptr));
        canTypeID->setItemText(1, QCoreApplication::translate("CANSetting", "29bit", nullptr));

        label_11->setText(QCoreApplication::translate("CANSetting", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", nullptr));
        canSpeed->setItemText(0, QCoreApplication::translate("CANSetting", "20K", nullptr));
        canSpeed->setItemText(1, QCoreApplication::translate("CANSetting", "50K", nullptr));
        canSpeed->setItemText(2, QCoreApplication::translate("CANSetting", "100K", nullptr));
        canSpeed->setItemText(3, QCoreApplication::translate("CANSetting", "125K", nullptr));
        canSpeed->setItemText(4, QCoreApplication::translate("CANSetting", "250K", nullptr));
        canSpeed->setItemText(5, QCoreApplication::translate("CANSetting", "500K", nullptr));
        canSpeed->setItemText(6, QCoreApplication::translate("CANSetting", "667K", nullptr));
        canSpeed->setItemText(7, QCoreApplication::translate("CANSetting", "1M", nullptr));

        can1_protocol_lb->setText(QCoreApplication::translate("CANSetting", "\320\237\321\200\320\276\321\202\320\276\320\272\320\276\320\273:", nullptr));
        canMode->setItemText(0, QCoreApplication::translate("CANSetting", "disable", nullptr));
        canMode->setItemText(1, QCoreApplication::translate("CANSetting", "normal", nullptr));

        label_13->setText(QCoreApplication::translate("CANSetting", "\320\240\320\265\320\266\320\270\320\274:", nullptr));
        canProtocol->setItemText(0, QCoreApplication::translate("CANSetting", "disable", nullptr));
        canProtocol->setItemText(1, QCoreApplication::translate("CANSetting", "normal", nullptr));
        canProtocol->setItemText(2, QCoreApplication::translate("CANSetting", "loopback", nullptr));
        canProtocol->setItemText(3, QCoreApplication::translate("CANSetting", "silent", nullptr));
        canProtocol->setItemText(4, QCoreApplication::translate("CANSetting", "silent loopback", nullptr));

        canLogging->setText(QCoreApplication::translate("CANSetting", "\320\233\320\276\320\263\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\275\320\260 \321\204\320\273\320\265\321\210", nullptr));
        canFilter->setText(QCoreApplication::translate("CANSetting", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        canAddOptions->setText(QCoreApplication::translate("CANSetting", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        additionalSettingsGroup->setTitle(QCoreApplication::translate("CANSetting", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("CANSetting", "CAN ID (Hex):", nullptr));
        canIDHEX->setText(QCoreApplication::translate("CANSetting", "00 00 00 00", nullptr));
        label_2->setText(QCoreApplication::translate("CANSetting", "\320\243\321\201\320\273\320\276\320\262\320\270\320\265:", nullptr));
        canIDcondition->setItemText(0, QCoreApplication::translate("CANSetting", ">", nullptr));
        canIDcondition->setItemText(1, QCoreApplication::translate("CANSetting", "<", nullptr));
        canIDcondition->setItemText(2, QCoreApplication::translate("CANSetting", "==", nullptr));
        canIDcondition->setItemText(3, QCoreApplication::translate("CANSetting", "=<", nullptr));
        canIDcondition->setItemText(4, QCoreApplication::translate("CANSetting", ">=", nullptr));
        canIDcondition->setItemText(5, QCoreApplication::translate("CANSetting", "!=", nullptr));

        canIDcondition->setCurrentText(QCoreApplication::translate("CANSetting", ">", nullptr));
        label_3->setText(QCoreApplication::translate("CANSetting", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        canIDvalue->setText(QCoreApplication::translate("CANSetting", "0", nullptr));
        label_4->setText(QCoreApplication::translate("CANSetting", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275:", nullptr));

        const bool __sortingEnabled = startByteLength->isSortingEnabled();
        startByteLength->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = startByteLength->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = startByteLength->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = startByteLength->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = startByteLength->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = startByteLength->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = startByteLength->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = startByteLength->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = startByteLength->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("CANSetting", "00", nullptr));
        startByteLength->setSortingEnabled(__sortingEnabled);

        sendConfig->setText(QCoreApplication::translate("CANSetting", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CANSetting: public Ui_CANSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANSETTING_H
