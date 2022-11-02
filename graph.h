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
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

    QChart*             chart;
    CBIChartView*       chartView;
    QWidget*            checkboxesWidget;
    QDialogButtonBox*   btn_box;

    void setDataToGraph(const QMap<QString, param_series*>& data, const param_filter & paramfilter);
    void setupUi();
    void removeSeries(const QString& name);
    void addSeries(const QString& name);
private:
    Ui::Graph *ui;
    QMap<QString, QLineSeries*> seriess;
public slots:
    void zoomAll(int type);
};

#endif // GRAPH_H
