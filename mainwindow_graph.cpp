#include "mainwindow.h"
#include "hexvalidator.h"
#include <QDebug>
#include <QtCharts/QLegend>

void MainWindow::createGraphObject() {
    if (graphic) {
        graphic->deleteLater();
        delete graphic;
        graphic = nullptr;
    }
    graphic = new Graph(this);
    graphic->setupUi();
    /**
     * TODO: добавить фильтрацию параметров,
     * по которым строить график
    */
    graphic->setDataToGraph(params);
    graphic->open();
}

void MainWindow::setDialogGraph() {
    createGraphObject();
    return;
    if (!createGraphdlg) {
        createGraphdlg = new QDialog(this);
        createGraphdlg->setMinimumWidth(250);
        createGraphdlg->setWindowTitle("Graph");
        createGraphdlg->setWindowFlags(createGraphdlg->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        QDialogButtonBox *btn_box = new QDialogButtonBox(createGraphdlg);
        btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        connect(btn_box, &QDialogButtonBox::accepted, createGraphdlg, &QDialog::accept);
        connect(btn_box, &QDialogButtonBox::rejected, createGraphdlg, &QDialog::reject);
        QLabel *lb=new QLabel("ID");
        QLabel *lb1=new QLabel("Start Bit");
        QLabel *lb2=new QLabel("Length");
        QLabel *lb3=new QLabel("Ratio");
        QLineEdit *ed=new QLineEdit(this);
        QLineEdit *ed1=new QLineEdit(this);
        QLineEdit *ed2=new QLineEdit(this);
        QLineEdit *ed3=new QLineEdit(this);
        QGridLayout *layout = new QGridLayout();
        layout->addWidget(lb,0,0);
        layout->addWidget(ed,0,1);
        layout->addWidget(lb1,1,0);
        layout->addWidget(ed1,1,1);
        layout->addWidget(lb2,2,0);
        layout->addWidget(ed2,2,1);
        layout->addWidget(lb3,3,0);
        layout->addWidget(ed3,3,1);
        layout->addWidget(btn_box,4,1);
        createGraphdlg->setLayout(layout);
    }
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
