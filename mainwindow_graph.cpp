#include "mainwindow.h"
#include "hexvalidator.h"
#include <QDebug>
#include <QtCharts/QLegend>

void MainWindow::createGraphObject() {
    graphic=new Graph(this);
    graphic->setMinimumWidth(1250);
    graphic->setMinimumHeight(900);
    graphic->setWindowTitle("График");
    graphic->setWindowFlags(graphic->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QDialogButtonBox *btn_box = new QDialogButtonBox();
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(btn_box, &QDialogButtonBox::accepted, graphic, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, graphic, &QDialog::reject);
    QVBoxLayout *layout = new QVBoxLayout();
    chart = new QChart();
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::HorizontalRubberBand);
    QObject::connect(graphic, SIGNAL(signalZoom(int)), this, SLOT(zoomAll(int)));
    QStringList red=checkCanDialogText(can1_mdiUI->log,can2_mdiUI->log);
//    QVector<QString>datas=parseToGraph(red,"0x18FFD53D");
//    qDebug()<<datas;
//    setDataToGraph(datas);

    auto scrollCheckBoxes=new QScrollArea();
    scrollCheckBoxes->setWidgetResizable(true);

    checkboxesWidget=new QWidget();
    scrollCheckBoxes->setWidget(checkboxesWidget);


    auto chartandcheckboxes=new QWidget();

    auto hlay=new QHBoxLayout();
    chartandcheckboxes->setLayout(hlay);


    chartandcheckboxes->layout()->addWidget(scrollCheckBoxes);

    chartandcheckboxes->layout()->addWidget(chartView);

    hlay->setStretch(1,2);

    hlay->setStretch(2,8);

    checkboxesWidget->setLayout(new QVBoxLayout());





    setDataToGraph();
    chart->createDefaultAxes();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setVisible(true);

    layout->addWidget(chartandcheckboxes);

    layout->addWidget(btn_box);

    graphic->setLayout(layout);
    switch(graphic->exec()) {
       case QDialog::Accepted:
            graphic->deleteLater();
            break;
       case QDialog::Rejected:
            graphic->deleteLater();
            break;
     }
}

void MainWindow::setDialogGraph() {
    createGraphdlg=new QDialog(this);
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

    switch( createGraphdlg->exec()) {
       case QDialog::Accepted:
            createGraphObject();
            createGraphdlg->deleteLater();
           break;
       case QDialog::Rejected:
           createGraphdlg->deleteLater();
           break;
     }
}
//void MainWindow::setDataToGraph(QVector<QString> a){
void MainWindow::setDataToGraph(){
    for (auto name: params.keys()) {;
        QLineSeries* series = new QLineSeries();
        series->setName(name);
        series->setObjectName(name);
        auto list = params.value(name)->list;
        auto it = list.begin();
        while(it != list.end()) {
            auto v = *it;

            series->append(v.timestamp, v.value);

            it++;
        }

        chart->addSeries(series);

        auto w=new QWidget();
        auto lay=new QHBoxLayout();
        lay->setSpacing(0);
        w->setLayout(lay);

        auto cb=new QCheckBox();
        cb->setText(name);
        auto pixmap=QPixmap(22,22);
        cb->setSizePolicy(QSizePolicy::Minimum
                          ,QSizePolicy::Fixed);

        auto m=chart->legend()->markers(series);
        pixmap.fill(m.first()->brush().color());

        auto lbl=new QLabel();
        lbl->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        lbl->setPixmap(pixmap);
        lay->addWidget(cb);
        lay->addWidget(lbl);


        auto is_visible=params.value(name)->is_visible;
        cb->setChecked(is_visible);
        series->setVisible(is_visible);

        connect(cb,&QCheckBox::clicked,this,[=](){
           this->params.value(name)->is_visible=cb->isChecked();
           auto s=chartView->chart()->series();

           for (auto const & ser: s){
                if(ser->name()==name){
                    ser->setVisible(cb->isChecked());
                    break;
                }
           }

        });




        qDebug()<<name<<m.first()->brush().color();
        checkboxesWidget->layout()->addWidget(w);

        chart->legend()->setVisible(true);
        chart->legend()->setBackgroundVisible(true);
        chart->legend()->attachToChart();
        chart->legend()->setAlignment(Qt::AlignLeft);
        chart->legend()->update();
    }
}


void MainWindow::zoomAll(int type) {
    if (type == 1) chart->zoomIn();
    else chart->zoomOut();
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

QVector<QString>MainWindow::parseToGraph(QStringList data, QString ID) {
    QVector<QString> s;
    for (int i = 0; i < data.length(); i++) {
        QVector<QString> vr;
        QStringList s1=data[i].split("     ");
        QStringList s2=s1[0].split(" ");
        QString q;
        for (int j=0;j<s2.length();j++) {
            if (s2[j].startsWith("0x")==true){q=s2[j].trimmed();break;}
        }
        if (q == ID) {
            if (s.contains(s1[1]) != true) {
                s.append(s1[1]);
            }
        }
    }
    return s;
}
