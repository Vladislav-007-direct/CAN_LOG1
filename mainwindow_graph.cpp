#include "mainwindow.h"
#include "hexvalidator.h"
#include <QDebug>
#include <QtCharts/QLegend>

void MainWindow::createGraphObject(param_filter filter) {
    if (!graphic) {
        graphic = new Graph(this);
        graphic->setupUi();

        auto params=paramsFromBlocks(this->parsedBlocks,filter);
        graphic->setDataToGraph(params);

        connect(graphic, &QDialog::destroyed, this, [this]() {
            this->graphic=nullptr;
        });
        connect(graphic, &QDialog::finished, this, [this]() {
            this->graphic->deleteLater();
        });
    }
    graphic->open();
}

void MainWindow::setDialogGraph() {
        if (createGraphdlg) {
            return;
        }

        createGraphdlg = new FilteringDialog(this->parsedBlocks,getPeriphery(),this);
        createGraphdlg->setMinimumWidth(250);
        createGraphdlg->setWindowTitle("Graph");
        createGraphdlg->setWindowFlags(createGraphdlg->windowFlags() & ~Qt::WindowContextHelpButtonHint);

        connect(createGraphdlg, &QDialog::destroyed, this, [this]() {
            createGraphdlg=nullptr;
        });
        connect(createGraphdlg,&QDialog::rejected,this,[this](){
            this->createGraphdlg->deleteLater();
        });
        connect(createGraphdlg, &QDialog::accepted, this, [=,this]() {
            auto fil=createGraphdlg->filter();
            createGraphObject(fil);
            this->createGraphdlg->deleteLater();
        });

    createGraphdlg->open();

}

void MainWindow::graphCreate1() {
    if (can1_mdiUI->log->toPlainText().length() == 0) {
        QMessageBox::information(this,"Внимание!","Логи не загружены!");
    }
    else setDialogGraph();
}

void MainWindow::graphCreate2() {
    if (can2_mdiUI->log->toPlainText().length() == 0) {
        QMessageBox::information(this,"Внимание!","Логи не загружены!");
    }
    else setDialogGraph();
}
