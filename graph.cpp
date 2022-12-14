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
    axisX->setFormat("HH:mm:ss.zzz\ndd.MM.yyyy");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);


    qreal tmin = std::numeric_limits<qreal>::max();
    qreal tmax = std::numeric_limits<qreal>::min();
    qreal vmin = std::numeric_limits<qreal>::max();
    qreal vmax = std::numeric_limits<qreal>::min();


    for (auto name: params.keys()) {;
        auto ss = Graph::seriesstruct();

        ss.series=new QLineSeries;
        ss.series->setName(name);
        ss.series->setObjectName(name);
        auto param = params.value(name);
        auto list = param.list;
        auto it = list.begin();
        while(it != list.end()) {
            auto v = *it;

            ss.series->append(v.timestamp, v.value);
            if (v.timestamp > tmax) tmax = v.timestamp;
            if (v.timestamp < tmin) tmin = v.timestamp;
            if (v.value > vmax) vmax = v.value;
            if (v.value < vmin) vmin = v.value;
            it++;
        }
        ss.tmin -= 1;
        ss.tmax += 1;
        ss.vmin -= 1;
        ss.vmax += 1;
        if (tmin > ss.tmin) tmin = ss.tmin;
        if (tmax < ss.tmax) tmax = ss.tmax;
        if (vmin > ss.vmin) vmin = ss.vmin;
        if (vmax < ss.vmax) vmax = ss.vmax;

        chart->addSeries(ss.series);
        seriess.insert(name, ss);
        ss.series->attachAxis(axisX);
        ss.series->attachAxis(axisY);

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
        auto m = chart->legend()->markers(ss.series);
        pixmap.fill(m.first()->brush().color());
        lbl->setPixmap(pixmap);
        lay->addWidget(cb);
        lay->addWidget(lbl);
        auto is_visible = params.value(name).is_visible;
        cb->setChecked(is_visible);
        ss.series->setVisible(is_visible);
        connect(cb, &QCheckBox::clicked, this, [=](){
            auto is_visible=seriess.value(name).series->isVisible();
            if (!is_visible) addSeries(name);
            else removeSeries(name);
        });
        checkboxesWidget->layout()->addWidget(w);
    }

    axisY->setRange(vmin, vmax);
    axisX->setRange(QDateTime::fromMSecsSinceEpoch(tmin), QDateTime::fromMSecsSinceEpoch(tmax));
    chart->setTMax(tmax);
    chart->setTMin(tmin);
    chart->setVMax(vmax);
    chart->setVMin(vmin);
    chart->legend()->setVisible(false);
}

void Graph::setupUi() {
    setMinimumWidth(1250);
    setMinimumHeight(800);
    setWindowTitle("????????????");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    auto layout = new QGridLayout();
    btn_box = new QDialogButtonBox();
    chart = new CBIChart();
    chartView = new CBIChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
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
    ss.series->setVisible(true);
    if (chart->getTMin() > ss.tmin) chart->setTMin(ss.tmin);
    if (chart->getTMax() < ss.tmax) chart->setTMax(ss.tmax);
    if (chart->getVMin() > ss.vmin) chart->setVMin(ss.vmin);
    if (chart->getVMax() < ss.vmax) chart->setVMax(ss.vmax);
    checkZoom(true);
}

void Graph::removeSeries(const QString& name) {
    auto ss = seriess.value(name);
    ss.series->setVisible(false);
    qreal tmin = std::numeric_limits<qreal>::max();
    qreal tmax = std::numeric_limits<qreal>::min();
    qreal vmin = std::numeric_limits<qreal>::max();
    qreal vmax = std::numeric_limits<qreal>::min();
    for(auto ss:  seriess.values()) {
        if (ss.series->isVisible()) {
            if (tmin > ss.tmin) tmin = ss.tmin;
            if (tmax < ss.tmax) tmax = ss.tmax;
            if (vmin > ss.vmin) vmin = ss.vmin;
            if (vmax < ss.vmax) vmax = ss.vmax;
        }
    }
    chart->setTMax(tmax);
    chart->setTMin(tmin);
    chart->setVMax(vmax);
    chart->setVMin(vmin);
    checkZoom();
}
void CBIChartView::wheelEvent(QWheelEvent *event) {
    if (event->delta() > 0) emit signalZoom(1);
    else emit signalZoom(2);
}
void Graph::checkZoom(const bool& drop) {
    auto axisX = (QDateTimeAxis*)chart->axisX();
    auto axisY = (QValueAxis*)chart->axisY();
    if (drop) {
        axisX->setMax(QDateTime::fromMSecsSinceEpoch(chart->getTMax()));
        axisX->setMin(QDateTime::fromMSecsSinceEpoch(chart->getTMin()));
        axisY->setMax(chart->getVMax());
        axisY->setMin(chart->getVMin());
    }
    else {
        auto tmin = axisX->min().toMSecsSinceEpoch();
        auto tmax = axisX->max().toMSecsSinceEpoch();
        auto vmin = axisY->min();
        auto vmax = axisY->max();
        if (chart->getTMax() < tmax) axisX->setMax(QDateTime::fromMSecsSinceEpoch(chart->getTMax()));
        if (chart->getTMin() > tmin) axisX->setMin(QDateTime::fromMSecsSinceEpoch(chart->getTMin()));
        if (chart->getVMax() < vmax) axisY->setMax(chart->getVMax());
        if (chart->getVMin() > vmin) axisY->setMin(chart->getVMin());

    }
};
void Graph::zoomAll(int type) {
    if (type == 1) chart->zoomIn();
    else chart->zoomOut();
    checkZoom();
}
