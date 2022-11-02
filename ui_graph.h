/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(400, 300);
        buttonBox = new QDialogButtonBox(Graph);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Graph);
        QObject::connect(buttonBox, SIGNAL(accepted()), Graph, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Graph, SLOT(reject()));

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QDialog *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
