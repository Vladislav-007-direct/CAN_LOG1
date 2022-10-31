/********************************************************************************
** Form generated from reading UI file 'packetRow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKETROW_H
#define UI_PACKETROW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PacketRow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *number;
    QCheckBox *sendIt;
    QLabel *label_21;
    QComboBox *frameType;
    QLabel *label_33;
    QLineEdit *frameID;
    QFrame *line_9;
    QLabel *label_23;
    QComboBox *messageLength;
    QLabel *label_25;
    QLabel *label_31;
    QLineEdit *message;
    QFrame *line;
    QLabel *label_29;
    QLineEdit *delay;
    QLabel *label_27;
    QLineEdit *repeat;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *PacketRow)
    {
        if (PacketRow->objectName().isEmpty())
            PacketRow->setObjectName(QString::fromUtf8("PacketRow"));
        PacketRow->resize(754, 38);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PacketRow->sizePolicy().hasHeightForWidth());
        PacketRow->setSizePolicy(sizePolicy);
        PacketRow->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(PacketRow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        number = new QLabel(PacketRow);
        number->setObjectName(QString::fromUtf8("number"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(number->sizePolicy().hasHeightForWidth());
        number->setSizePolicy(sizePolicy1);
        number->setMinimumSize(QSize(20, 0));

        horizontalLayout->addWidget(number);

        sendIt = new QCheckBox(PacketRow);
        sendIt->setObjectName(QString::fromUtf8("sendIt"));
        sizePolicy1.setHeightForWidth(sendIt->sizePolicy().hasHeightForWidth());
        sendIt->setSizePolicy(sizePolicy1);
        sendIt->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(sendIt);

        label_21 = new QLabel(PacketRow);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(7);
        label_21->setFont(font);
        label_21->setLayoutDirection(Qt::LeftToRight);
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_21);

        frameType = new QComboBox(PacketRow);
        frameType->addItem(QString());
        frameType->addItem(QString());
        frameType->setObjectName(QString::fromUtf8("frameType"));
        frameType->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(frameType);

        label_33 = new QLabel(PacketRow);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMaximumSize(QSize(12, 16777215));

        horizontalLayout->addWidget(label_33);

        frameID = new QLineEdit(PacketRow);
        frameID->setObjectName(QString::fromUtf8("frameID"));
        frameID->setMinimumSize(QSize(63, 0));
        frameID->setMaximumSize(QSize(70, 16777215));
        frameID->setMaxLength(11);

        horizontalLayout->addWidget(frameID);

        line_9 = new QFrame(PacketRow);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_9);

        label_23 = new QLabel(PacketRow);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_23);

        messageLength = new QComboBox(PacketRow);
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->addItem(QString());
        messageLength->setObjectName(QString::fromUtf8("messageLength"));
        messageLength->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(messageLength);

        label_25 = new QLabel(PacketRow);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy1.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy1);
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_25);

        label_31 = new QLabel(PacketRow);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMaximumSize(QSize(12, 16777215));

        horizontalLayout->addWidget(label_31);

        message = new QLineEdit(PacketRow);
        message->setObjectName(QString::fromUtf8("message"));
        message->setMinimumSize(QSize(130, 0));
        message->setMaximumSize(QSize(130, 16777215));
        message->setMaxLength(23);

        horizontalLayout->addWidget(message);

        line = new QFrame(PacketRow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_29 = new QLabel(PacketRow);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_29);

        delay = new QLineEdit(PacketRow);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(delay);

        label_27 = new QLabel(PacketRow);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_27);

        repeat = new QLineEdit(PacketRow);
        repeat->setObjectName(QString::fromUtf8("repeat"));
        repeat->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(repeat);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        retranslateUi(PacketRow);

        frameType->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PacketRow);
    } // setupUi

    void retranslateUi(QWidget *PacketRow)
    {
        PacketRow->setWindowTitle(QCoreApplication::translate("PacketRow", "Form", nullptr));
        number->setText(QCoreApplication::translate("PacketRow", "1", nullptr));
        sendIt->setText(QString());
        label_21->setText(QCoreApplication::translate("PacketRow", "\320\272\320\260\320\264\321\200", nullptr));
        frameType->setItemText(0, QCoreApplication::translate("PacketRow", "SFF", nullptr));
        frameType->setItemText(1, QCoreApplication::translate("PacketRow", "EFF", nullptr));

        label_33->setText(QCoreApplication::translate("PacketRow", "0x", nullptr));
        frameID->setText(QCoreApplication::translate("PacketRow", "00 00 00 00", nullptr));
        label_23->setText(QCoreApplication::translate("PacketRow", "\320\264\320\273\320\270\320\275\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        messageLength->setItemText(0, QCoreApplication::translate("PacketRow", "8", nullptr));
        messageLength->setItemText(1, QCoreApplication::translate("PacketRow", "7", nullptr));
        messageLength->setItemText(2, QCoreApplication::translate("PacketRow", "6", nullptr));
        messageLength->setItemText(3, QCoreApplication::translate("PacketRow", "5", nullptr));
        messageLength->setItemText(4, QCoreApplication::translate("PacketRow", "4", nullptr));
        messageLength->setItemText(5, QCoreApplication::translate("PacketRow", "3", nullptr));
        messageLength->setItemText(6, QCoreApplication::translate("PacketRow", "2", nullptr));
        messageLength->setItemText(7, QCoreApplication::translate("PacketRow", "1", nullptr));

        label_25->setText(QCoreApplication::translate("PacketRow", "\320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_31->setText(QCoreApplication::translate("PacketRow", "0x", nullptr));
        message->setText(QCoreApplication::translate("PacketRow", "00 00 00 00 00 00 00 00", nullptr));
        label_29->setText(QCoreApplication::translate("PacketRow", "\320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\260, \320\274\321\201", nullptr));
        delay->setText(QCoreApplication::translate("PacketRow", "0", nullptr));
        label_27->setText(QCoreApplication::translate("PacketRow", "\320\277\320\276\320\262\321\202\320\276\321\200", nullptr));
        repeat->setText(QCoreApplication::translate("PacketRow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PacketRow: public Ui_PacketRow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKETROW_H
