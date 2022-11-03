#ifndef FILTERINGDIALOG_H
#define FILTERINGDIALOG_H

#include <QDialog>
#include <QObject>
#include <QMap>
#include "structs.h"
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGridLayout>

class FilteringDialog : public QDialog
{
    Q_OBJECT
public:
    FilteringDialog(QList<trblock> blocks,QMap<QString, QList<peripherystruct>*> periphery,QWidget * parent=nullptr);
    param_filter filter();
private:
    enum class State{
        Manual,
        Filter,
        Periphery
    };
    State m_state=State::Manual;
    QSpinBox * startBitSB;
    QSpinBox * lengthSB;
    QDoubleSpinBox * ratioSB;
    QComboBox *filterIDCB;
    QComboBox *peripheryCB;
    QCheckBox * signCB;
    int startBit(){
        return startBitSB->value();
    }
    int length(){
        return lengthSB->value();
    }
    double ratio(){
        return ratioSB->value();
    }
    quint32 filterID(){
        return filterIDCB->currentData().toUInt();
    }
    bool sign(){
        return signCB->isChecked();
    }
    void peripheryActivated();
    void filterActivated();
    void lengthActivated(int value);
    void ratioActivated(double value);
    void stBitActivated(int value);

    void changeState(State state);


};

#endif // FILTERINGDIALOG_H
