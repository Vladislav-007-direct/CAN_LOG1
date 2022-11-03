#include "graph.h"
#include "ui_graph.h"

#include <QDateTime>
#include <QDateTimeAxis>

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph) {
    ui->setupUi(this);
}

Graph::~Graph() {
}

void Graph::setDataToGraph(const QMap<QString, param_series> &params) {
    QDateTimeAxis *axisX = new QDateTimeAxis;
//    axisX->setTickCount(10 * 1000);
    axisX->setFormat("HH:mm:ss\ndd.MM.yyyy");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);

    quint64 tmin = -1;
    quint64 tmax = 0;
    quint64 vmin = -1;
    quint64 vmax = 0;

    for (auto name: params.keys()) {;

        QLineSeries* series = new QLineSeries();
        series->setName(name);
        series->setObjectName(name);
        auto param = params.value(name);
        auto list = param.list;
        auto it = list.begin();
        while(it != list.end()) {
            auto v = *it;

            series->append(v.timestamp, v.value);
            if (v.timestamp > tmax) tmax = v.timestamp;
            if (v.timestamp < tmin) tmin = v.timestamp;
            if (v.value > vmax) vmax = v.value;
            if (v.value < vmin) vmin = v.value;
            it++;
        }
        chart->addSeries(series);
        seriess.insert(name, series);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

        auto w = new QWidget();
        auto lay = new QHBoxLayout();
        lay->setSpacing(0);
        w->setLayout(lay);
        auto cb = new QCheckBox();
        cb->setText(name);
        cb->setFixedWidth(100);
        auto lbl = new QLabel();
        lbl->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        auto pixmap = QPixmap(22, 22);
        auto m = chart->legend()->markers(series);
        pixmap.fill(m.first()->brush().color());
        lbl->setPixmap(pixmap);
        lay->addWidget(cb);
        lay->addWidget(lbl);
        auto is_visible = params.value(name).is_visible;
        cb->setChecked(is_visible);
        series->setVisible(is_visible);
        connect(cb, &QCheckBox::clicked, this, [=](){
            auto is_visible=seriess.value(name)->isVisible();
            if (!is_visible) addSeries(name);
            else removeSeries(name);
        });
        checkboxesWidget->layout()->addWidget(w);
    }

    axisY->setRange(vmin, vmax);
    axisX->setRange(QDateTime::fromMSecsSinceEpoch(tmin), QDateTime::fromMSecsSinceEpoch(tmax));
    chart->legend()->setVisible(false);
}

void Graph::setupUi() {
    setMinimumWidth(1250);
    setMinimumHeight(800);
    setWindowTitle("График");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    auto layout = new QGridLayout();
    btn_box = new QDialogButtonBox();
    chart = new QChart();
    chartView = new CBIChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::HorizontalRubberBand);
    auto scrollCheckBoxes=new QScrollArea();
    scrollCheckBoxes->setWidgetResizable(true);
    scrollCheckBoxes->setFixedWidth(180);
    checkboxesWidget=new QWidget();
    scrollCheckBoxes->setWidget(checkboxesWidget);
    auto chartandcheckboxes=new QWidget();
    auto hlay=new QHBoxLayout();
    chartandcheckboxes->setLayout(hlay);
    hlay->addWidget(scrollCheckBoxes);
    hlay->addWidget(chartView);
    hlay->setStretch(1,2);
    hlay->setStretch(2,8);
    checkboxesWidget->setLayout(new QVBoxLayout());
    connect(chartView, SIGNAL(signalZoom(int)), this, SLOT(zoomAll(int)));
    layout->addWidget(chartandcheckboxes);
    layout->addWidget(btn_box);
    setLayout(layout);
}

void Graph::addSeries(const QString& name) {
    auto ss = seriess.value(name);
    ss->setVisible(true);
}

void Graph::removeSeries(const QString& name) {
    auto ss = seriess.value(name);
    ss->setVisible(false);
}

void CBIChartView::wheelEvent(QWheelEvent *event) {
    if (event->delta() > 0) emit signalZoom(1);
    else emit signalZoom(2);
}

void Graph::zoomAll(int type) {
    if (type == 1) chart->zoomIn();
    else chart->zoomOut();
}
