/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *devconnect;
    QAction *devdisconnect;
    QAction *fileopen;
    QAction *filesave;
    QAction *quit;
    QAction *time_sync;
    QAction *action_2;
    QAction *firmware_update;
    QAction *action_dec_txt;
    QAction *action_dec_txt_can2;
    QAction *action_dec_txt_can1;
    QAction *action_dec_txt_can2_2;
    QAction *action_CAN_1;
    QAction *action_CAN_2;
    QAction *convertFiles;
    QAction *reboot;
    QAction *action_ASCII;
    QAction *action_Hex;
    QAction *actionASC;
    QAction *actionInf;
    QAction *actionCrane;
    QAction *actionPeriphery;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *can1_startbn;
    QPushButton *can1_stopbn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *can1;
    QPushButton *can2;
    QMdiArea *mdi;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_2;
    QMenu *menu_4;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_6;
    QFrame *line;
    QLabel *label_25;
    QLineEdit *tx_can0_repeat;
    QLabel *label_23;
    QComboBox *tx_can0_len;
    QComboBox *tx_can0_frametype;
    QLabel *label_27;
    QLabel *label_21;
    QLineEdit *tx_can0_delay;
    QLineEdit *tx_can0_data;
    QCheckBox *tx_can0_check;
    QFrame *line_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_29;
    QLabel *label_31;
    QLabel *label_33;
    QLineEdit *tx_can0_frameid;
    QGridLayout *gridLayout;
    QLabel *label_24;
    QComboBox *tx_can1_frametype;
    QLineEdit *tx_can1_repeat;
    QLabel *label_22;
    QLabel *label_28;
    QComboBox *tx_can1_len;
    QLabel *label_26;
    QLineEdit *tx_can1_delay;
    QLineEdit *tx_can1_frameid;
    QLineEdit *tx_can1_data;
    QCheckBox *tx_can1_check;
    QFrame *line_2;
    QLabel *label_30;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_32;
    QLabel *label_34;
    QGridLayout *gridLayout_12;
    QFrame *line_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *transmitbn;
    QPushButton *canceltxbn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(984, 811);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logger.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        devconnect = new QAction(MainWindow);
        devconnect->setObjectName(QString::fromUtf8("devconnect"));
        devdisconnect = new QAction(MainWindow);
        devdisconnect->setObjectName(QString::fromUtf8("devdisconnect"));
        fileopen = new QAction(MainWindow);
        fileopen->setObjectName(QString::fromUtf8("fileopen"));
        filesave = new QAction(MainWindow);
        filesave->setObjectName(QString::fromUtf8("filesave"));
        filesave->setEnabled(false);
        quit = new QAction(MainWindow);
        quit->setObjectName(QString::fromUtf8("quit"));
        time_sync = new QAction(MainWindow);
        time_sync->setObjectName(QString::fromUtf8("time_sync"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        firmware_update = new QAction(MainWindow);
        firmware_update->setObjectName(QString::fromUtf8("firmware_update"));
        action_dec_txt = new QAction(MainWindow);
        action_dec_txt->setObjectName(QString::fromUtf8("action_dec_txt"));
        action_dec_txt_can2 = new QAction(MainWindow);
        action_dec_txt_can2->setObjectName(QString::fromUtf8("action_dec_txt_can2"));
        action_dec_txt_can1 = new QAction(MainWindow);
        action_dec_txt_can1->setObjectName(QString::fromUtf8("action_dec_txt_can1"));
        action_dec_txt_can2_2 = new QAction(MainWindow);
        action_dec_txt_can2_2->setObjectName(QString::fromUtf8("action_dec_txt_can2_2"));
        action_CAN_1 = new QAction(MainWindow);
        action_CAN_1->setObjectName(QString::fromUtf8("action_CAN_1"));
        action_CAN_2 = new QAction(MainWindow);
        action_CAN_2->setObjectName(QString::fromUtf8("action_CAN_2"));
        convertFiles = new QAction(MainWindow);
        convertFiles->setObjectName(QString::fromUtf8("convertFiles"));
        reboot = new QAction(MainWindow);
        reboot->setObjectName(QString::fromUtf8("reboot"));
        action_ASCII = new QAction(MainWindow);
        action_ASCII->setObjectName(QString::fromUtf8("action_ASCII"));
        action_Hex = new QAction(MainWindow);
        action_Hex->setObjectName(QString::fromUtf8("action_Hex"));
        actionASC = new QAction(MainWindow);
        actionASC->setObjectName(QString::fromUtf8("actionASC"));
        actionInf = new QAction(MainWindow);
        actionInf->setObjectName(QString::fromUtf8("actionInf"));
        actionCrane = new QAction(MainWindow);
        actionCrane->setObjectName(QString::fromUtf8("actionCrane"));
        actionPeriphery = new QAction(MainWindow);
        actionPeriphery->setObjectName(QString::fromUtf8("actionPeriphery"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        can1_startbn = new QPushButton(centralWidget);
        can1_startbn->setObjectName(QString::fromUtf8("can1_startbn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(can1_startbn->sizePolicy().hasHeightForWidth());
        can1_startbn->setSizePolicy(sizePolicy);
        can1_startbn->setMaximumSize(QSize(350, 16777215));

        horizontalLayout_3->addWidget(can1_startbn);

        can1_stopbn = new QPushButton(centralWidget);
        can1_stopbn->setObjectName(QString::fromUtf8("can1_stopbn"));
        sizePolicy.setHeightForWidth(can1_stopbn->sizePolicy().hasHeightForWidth());
        can1_stopbn->setSizePolicy(sizePolicy);
        can1_stopbn->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(can1_stopbn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        can1 = new QPushButton(centralWidget);
        can1->setObjectName(QString::fromUtf8("can1"));

        horizontalLayout_3->addWidget(can1);

        can2 = new QPushButton(centralWidget);
        can2->setObjectName(QString::fromUtf8("can2"));

        horizontalLayout_3->addWidget(can2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        mdi = new QMdiArea(centralWidget);
        mdi->setObjectName(QString::fromUtf8("mdi"));
        mdi->setBaseSize(QSize(800, 600));
        mdi->setViewMode(QMdiArea::TabbedView);

        verticalLayout_5->addWidget(mdi);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 984, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        line = new QFrame(dockWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 0, 1, 1, 1);

        label_25 = new QLabel(dockWidgetContents);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        QFont font;
        font.setPointSize(7);
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_25, 0, 9, 1, 1);

        tx_can0_repeat = new QLineEdit(dockWidgetContents);
        tx_can0_repeat->setObjectName(QString::fromUtf8("tx_can0_repeat"));
        tx_can0_repeat->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(tx_can0_repeat, 0, 13, 1, 1);

        label_23 = new QLabel(dockWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_23, 0, 7, 1, 1);

        tx_can0_len = new QComboBox(dockWidgetContents);
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->addItem(QString());
        tx_can0_len->setObjectName(QString::fromUtf8("tx_can0_len"));
        tx_can0_len->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(tx_can0_len, 0, 8, 1, 1);

        tx_can0_frametype = new QComboBox(dockWidgetContents);
        tx_can0_frametype->addItem(QString());
        tx_can0_frametype->addItem(QString());
        tx_can0_frametype->setObjectName(QString::fromUtf8("tx_can0_frametype"));
        tx_can0_frametype->setMaximumSize(QSize(40, 16777215));

        gridLayout_6->addWidget(tx_can0_frametype, 0, 2, 1, 1);

        label_27 = new QLabel(dockWidgetContents);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_27, 0, 12, 1, 1);

        label_21 = new QLabel(dockWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setLayoutDirection(Qt::LeftToRight);
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_21, 0, 3, 1, 1);

        tx_can0_delay = new QLineEdit(dockWidgetContents);
        tx_can0_delay->setObjectName(QString::fromUtf8("tx_can0_delay"));
        tx_can0_delay->setMaximumSize(QSize(40, 16777215));

        gridLayout_6->addWidget(tx_can0_delay, 0, 15, 1, 1);

        tx_can0_data = new QLineEdit(dockWidgetContents);
        tx_can0_data->setObjectName(QString::fromUtf8("tx_can0_data"));
        tx_can0_data->setMaximumSize(QSize(130, 16777215));
        tx_can0_data->setMaxLength(23);

        gridLayout_6->addWidget(tx_can0_data, 0, 11, 1, 1);

        tx_can0_check = new QCheckBox(dockWidgetContents);
        tx_can0_check->setObjectName(QString::fromUtf8("tx_can0_check"));
        tx_can0_check->setMinimumSize(QSize(200, 0));

        gridLayout_6->addWidget(tx_can0_check, 0, 0, 1, 1);

        line_9 = new QFrame(dockWidgetContents);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_9, 0, 16, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 17, 1, 1);

        label_29 = new QLabel(dockWidgetContents);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_29, 0, 14, 1, 1);

        label_31 = new QLabel(dockWidgetContents);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMaximumSize(QSize(12, 16777215));

        gridLayout_6->addWidget(label_31, 0, 4, 1, 1);

        label_33 = new QLabel(dockWidgetContents);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMaximumSize(QSize(12, 16777215));

        gridLayout_6->addWidget(label_33, 0, 10, 1, 1);

        tx_can0_frameid = new QLineEdit(dockWidgetContents);
        tx_can0_frameid->setObjectName(QString::fromUtf8("tx_can0_frameid"));
        tx_can0_frameid->setMaximumSize(QSize(70, 16777215));
        tx_can0_frameid->setMaxLength(11);

        gridLayout_6->addWidget(tx_can0_frameid, 0, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout_6);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_24 = new QLabel(dockWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_24, 0, 6, 1, 1);

        tx_can1_frametype = new QComboBox(dockWidgetContents);
        tx_can1_frametype->addItem(QString());
        tx_can1_frametype->addItem(QString());
        tx_can1_frametype->setObjectName(QString::fromUtf8("tx_can1_frametype"));
        tx_can1_frametype->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(tx_can1_frametype, 0, 2, 1, 1);

        tx_can1_repeat = new QLineEdit(dockWidgetContents);
        tx_can1_repeat->setObjectName(QString::fromUtf8("tx_can1_repeat"));
        tx_can1_repeat->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(tx_can1_repeat, 0, 12, 1, 1);

        label_22 = new QLabel(dockWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_22, 0, 3, 1, 1);

        label_28 = new QLabel(dockWidgetContents);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 0, 11, 1, 1);

        tx_can1_len = new QComboBox(dockWidgetContents);
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->addItem(QString());
        tx_can1_len->setObjectName(QString::fromUtf8("tx_can1_len"));
        tx_can1_len->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(tx_can1_len, 0, 7, 1, 1);

        label_26 = new QLabel(dockWidgetContents);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 0, 8, 1, 1);

        tx_can1_delay = new QLineEdit(dockWidgetContents);
        tx_can1_delay->setObjectName(QString::fromUtf8("tx_can1_delay"));
        tx_can1_delay->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(tx_can1_delay, 0, 14, 1, 1);

        tx_can1_frameid = new QLineEdit(dockWidgetContents);
        tx_can1_frameid->setObjectName(QString::fromUtf8("tx_can1_frameid"));
        tx_can1_frameid->setMaximumSize(QSize(70, 16777215));
        tx_can1_frameid->setMaxLength(11);

        gridLayout->addWidget(tx_can1_frameid, 0, 5, 1, 1);

        tx_can1_data = new QLineEdit(dockWidgetContents);
        tx_can1_data->setObjectName(QString::fromUtf8("tx_can1_data"));
        tx_can1_data->setMaximumSize(QSize(130, 16777215));
        tx_can1_data->setMaxLength(23);

        gridLayout->addWidget(tx_can1_data, 0, 10, 1, 1);

        tx_can1_check = new QCheckBox(dockWidgetContents);
        tx_can1_check->setObjectName(QString::fromUtf8("tx_can1_check"));
        tx_can1_check->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(tx_can1_check, 0, 0, 1, 1);

        line_2 = new QFrame(dockWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 1, 1);

        label_30 = new QLabel(dockWidgetContents);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 0, 13, 1, 1);

        line_8 = new QFrame(dockWidgetContents);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 0, 15, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 16, 1, 1);

        label_32 = new QLabel(dockWidgetContents);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMaximumSize(QSize(12, 16777215));

        gridLayout->addWidget(label_32, 0, 4, 1, 1);

        label_34 = new QLabel(dockWidgetContents);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMaximumSize(QSize(12, 16777215));

        gridLayout->addWidget(label_34, 0, 9, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        line_5 = new QFrame(dockWidgetContents);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_5, 2, 0, 1, 1);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_12->addWidget(pushButton, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer, 1, 4, 1, 1);

        transmitbn = new QPushButton(dockWidgetContents);
        transmitbn->setObjectName(QString::fromUtf8("transmitbn"));

        gridLayout_12->addWidget(transmitbn, 1, 1, 1, 1);

        canceltxbn = new QPushButton(dockWidgetContents);
        canceltxbn->setObjectName(QString::fromUtf8("canceltxbn"));

        gridLayout_12->addWidget(canceltxbn, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_12);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(devconnect);
        menu->addAction(devdisconnect);
        menu->addAction(reboot);
        menu->addSeparator();
        menu->addAction(time_sync);
        menu->addAction(firmware_update);
        menu->addSeparator();
        menu->addAction(actionPeriphery);
        menu->addAction(actionCrane);
        menu->addAction(menu_3->menuAction());
        menu_3->addAction(action_CAN_1);
        menu_3->addAction(action_CAN_2);
        menu_2->addAction(fileopen);
        menu_2->addAction(filesave);
        menu_2->addSeparator();
        menu_2->addAction(action_dec_txt);
        menu_2->addAction(action_dec_txt_can2);
        menu_2->addSeparator();
        menu_2->addAction(action_dec_txt_can1);
        menu_2->addAction(action_dec_txt_can2_2);
        menu_2->addSeparator();
        menu_2->addAction(menu_4->menuAction());
        menu_2->addSeparator();
        menu_2->addAction(quit);
        menu_4->addAction(action_Hex);
        menu_4->addAction(actionASC);

        retranslateUi(MainWindow);
        QObject::connect(transmitbn, SIGNAL(clicked()), MainWindow, SLOT(transmitbn()));
        QObject::connect(canceltxbn, SIGNAL(clicked()), MainWindow, SLOT(canceltxbn()));

        tx_can0_frametype->setCurrentIndex(1);
        tx_can1_frametype->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CBI", nullptr));
        devconnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        devdisconnect->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        fileopen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        filesave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        time_sync->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\321\217 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\261\320\265\320\267\321\200\320\260\320\274\320\276\321\207\320\275\321\213\320\265", nullptr));
        firmware_update->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        action_dec_txt->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 dec txt (can1)", nullptr));
        action_dec_txt_can2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 dec txt (can2)", nullptr));
        action_dec_txt_can1->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \320\262 dec txt (can1)", nullptr));
        action_dec_txt_can2_2->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \320\262 dec txt (can2)", nullptr));
        action_CAN_1->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 CAN 1", nullptr));
        action_CAN_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 CAN 2", nullptr));
        convertFiles->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \320\262 hex", nullptr));
        reboot->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        action_ASCII->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \320\262 asc", nullptr));
        action_Hex->setText(QCoreApplication::translate("MainWindow", "\320\262 HEX", nullptr));
        actionASC->setText(QCoreApplication::translate("MainWindow", "\320\262 ASC", nullptr));
        actionInf->setText(QCoreApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        actionCrane->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\321\200\320\260\320\275\320\265", nullptr));
        actionPeriphery->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\321\204\320\265\321\200\320\270\321\217", nullptr));
        can1_startbn->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        can1_stopbn->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        can1->setText(QCoreApplication::translate("MainWindow", "CAN1", nullptr));
        can2->setText(QCoreApplication::translate("MainWindow", "CAN2", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\276\320\262", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        tx_can0_repeat->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\264\320\273\320\270\320\275\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        tx_can0_len->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        tx_can0_len->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));
        tx_can0_len->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        tx_can0_len->setItemText(3, QCoreApplication::translate("MainWindow", "5", nullptr));
        tx_can0_len->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        tx_can0_len->setItemText(5, QCoreApplication::translate("MainWindow", "3", nullptr));
        tx_can0_len->setItemText(6, QCoreApplication::translate("MainWindow", "2", nullptr));
        tx_can0_len->setItemText(7, QCoreApplication::translate("MainWindow", "1", nullptr));

        tx_can0_frametype->setItemText(0, QCoreApplication::translate("MainWindow", "SFF", nullptr));
        tx_can0_frametype->setItemText(1, QCoreApplication::translate("MainWindow", "EFF", nullptr));

        label_27->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\262\321\202\320\276\321\200", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\264\321\200", nullptr));
        tx_can0_delay->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tx_can0_data->setText(QCoreApplication::translate("MainWindow", "00 00 00 00 00 00 00 00", nullptr));
        tx_can0_check->setText(QCoreApplication::translate("MainWindow", "CAN 1", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\260, \320\274\321\201", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "0x", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "0x", nullptr));
        tx_can0_frameid->setText(QCoreApplication::translate("MainWindow", "00 00 00 00", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\320\264\320\273\320\270\320\275\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        tx_can1_frametype->setItemText(0, QCoreApplication::translate("MainWindow", "SFF", nullptr));
        tx_can1_frametype->setItemText(1, QCoreApplication::translate("MainWindow", "EFF", nullptr));

        tx_can1_repeat->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\264\321\200", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\262\321\202\320\276\321\200", nullptr));
        tx_can1_len->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        tx_can1_len->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));
        tx_can1_len->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        tx_can1_len->setItemText(3, QCoreApplication::translate("MainWindow", "5", nullptr));
        tx_can1_len->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        tx_can1_len->setItemText(5, QCoreApplication::translate("MainWindow", "3", nullptr));
        tx_can1_len->setItemText(6, QCoreApplication::translate("MainWindow", "2", nullptr));
        tx_can1_len->setItemText(7, QCoreApplication::translate("MainWindow", "1", nullptr));

        label_26->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        tx_can1_delay->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tx_can1_frameid->setText(QCoreApplication::translate("MainWindow", "00 00 00 00", nullptr));
        tx_can1_data->setText(QCoreApplication::translate("MainWindow", "00 00 00 00 00 00 00 00", nullptr));
        tx_can1_check->setText(QCoreApplication::translate("MainWindow", "CAN 2", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\260, \320\274\321\201", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "0x", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "0x", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\213\320\262\320\276\320\264", nullptr));
        transmitbn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        canceltxbn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
