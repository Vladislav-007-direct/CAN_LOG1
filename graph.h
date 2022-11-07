#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QtCharts/QtCharts>
#include <QList>
#include <QMap>
#include "structs.h"

namespace Ui {
    class Graph;
}
class CBIChart: public QChart {
    Q_OBJECT

public:
    CBIChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags()): QChart(parent, wFlags) {};

    qreal getTMin() { return tmin; };
    qreal getTMax() { return tmax; };
    qreal getVMin() { return vmin; };
    qreal getVMax() { return vmax; };
    void setTMin(qreal v) { tmin = v; };
    void setTMax(qreal v) { tmax = v; };
    void setVMin(qreal v) { vmin = v; };
    void setVMax(qreal v) { vmax = v; };

private:
    qreal tmin = std::numeric_limits<qreal>::max();
    qreal tmax = std::numeric_limits<qreal>::min();
    qreal vmin = std::numeric_limits<qreal>::max();
    qreal vmax = std::numeric_limits<qreal>::min();
};
class CBIChartView: public QChartView {
    Q_OBJECT

public:

    CBIChartView(QChart* chart): QChartView(chart) {};
signals:
    void signalZoom(int zoom1);
public slots:
    virtual void wheelEvent(QWheelEvent *event);
};

class Graph : public QDialog {
    Q_OBJECT

public:
    struct seriesstruct {
            qreal tmin = std::numeric_limits<qreal>::max();
            qreal tmax = std::numeric_limits<qreal>::min();
            qreal vmin = std::numeric_limits<qreal>::max();
            qreal vmax = std::numeric_limits<qreal>::min();
            QLineSeries* series;
        };
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();


    void setDataToGraph(const QMap<QString, param_series>& data);
    void setupUi();
    void removeSeries(const QString& name);
    void addSeries(const QString& name);
    void checkZoom(const bool& drop = false);
private:
    Ui::Graph*                  ui;
    CBIChart*                   chart;
    CBIChartView*               chartView;
    QWidget*                    checkboxesWidget;
    QDialogButtonBox*           btn_box;
    QMap<QString, seriesstruct> seriess;
public slots:
    void zoomAll(int type);
};

#endif // GRAPH_H
