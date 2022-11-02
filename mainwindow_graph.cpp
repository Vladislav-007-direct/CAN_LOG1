#include "mainwindow.h"
#include "hexvalidator.h"
#include <QDebug>
#include <QtCharts/QLegend>

void MainWindow::createGraphObject(quint32 frmid,int startBit,int length,double ratio) {
    if (!graphic) {
        graphic = new Graph(this);
        graphic->setupUi();

        param_filter f;
        f.frame_id=frmid;
        f.start_bit=startBit;
        f.length=length;
        f.ratio=ratio;

        graphic->setDataToGraph(params,f);

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
        auto ed=new QComboBox(this);
        auto m=std::map<quint32,bool>();
        ed->addItem("",0);
        for(auto const &i:this->params){
           for (auto const &j:(*i->list)){
               if(!m[j.canFrame.frm_id]){
                   m[j.canFrame.frm_id]=true;
                   auto a=j.canFrame.frm_id;
                   QByteArray frameID = QByteArray::fromRawData(reinterpret_cast<char*>(&a),sizeof(can_frm::frm_id));
                   std::reverse(frameID.begin(), frameID.end());
                   ed->addItem("0x"+frameID.toHex().toUpper(),j.canFrame.frm_id);
               }
           }
        }
        auto *ed1=new QSpinBox(this);
        ed1->setValue(0);
        ed1->setMaximum(7);
        ed1->setMinimum(0);
        auto *ed2=new QSpinBox(this);
        ed2->setValue(8);
        ed2->setMaximum(8);
        ed2->setMinimum(1);
        auto *ed3=new QDoubleSpinBox(this);
        ed3->setDecimals(5);
        ed3->setValue(1);
        ed3->setMinimum(0);

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


        connect(createGraphdlg, &QDialog::destroyed, this, [this]() {
            createGraphdlg=nullptr;
        });
        connect(createGraphdlg,&QDialog::rejected,this,[this](){
            this->createGraphdlg->deleteLater();
        });
        connect(createGraphdlg, &QDialog::accepted, this, [=,this]() {
            auto frm_id=ed->currentData().toInt();
            auto startBit=ed1->value();
            auto length=ed2->value();
            auto ratio=ed3->value();
            createGraphObject(frm_id,startBit,length,ratio);
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
