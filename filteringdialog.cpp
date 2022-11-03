#include "filteringdialog.h"
FilteringDialog::FilteringDialog(QList<trblock> blocks,QMap<QString, QList<peripherystruct>*> periphery,QWidget * parent):QDialog(parent)
{
    QDialogButtonBox *btn_box = new QDialogButtonBox(this);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(btn_box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, this, &QDialog::reject);
    QLabel *lb=new QLabel("ID");
    QLabel *lb1=new QLabel("Start Bit");
    QLabel *lb2=new QLabel("Length");
    QLabel *lb3=new QLabel("Ratio");
    filterIDCB=new QComboBox(this);
    peripheryCB=new QComboBox(this);


    peripheryCB->addItem("",QVariant::fromValue(param_filter{}));
    for(auto const &list:periphery){
        for(auto const &j:*list){
            auto pf=param_filter{};
            pf.frame_id=0;
            strcpy(pf.param_name,j.name);
            pf.length=j.size;
            pf.ratio=j.ratio;
            pf.start_bit=j.start;
            peripheryCB->addItem(QString("%1").arg(j.name),QVariant::fromValue(pf));
        }
    }

    auto m=std::map<quint32,bool>();
    filterIDCB->addItem("",0);
    for(auto const &i:blocks){
       if(!m[i.canFrame.frm_id]){
           m[i.canFrame.frm_id]=true;
           auto a=i.canFrame.frm_id;
           QByteArray frameID = QByteArray::fromRawData(reinterpret_cast<char*>(&a),sizeof(can_frm::frm_id));
           std::reverse(frameID.begin(), frameID.end());
           filterIDCB->addItem("0x"+frameID.toHex().toUpper(),i.canFrame.frm_id);
       }
    }

    startBitSB=new QSpinBox(this);
    startBitSB->setValue(0);
    startBitSB->setMinimum(0);

    lengthSB=new QSpinBox(this);
    lengthSB->setValue(8);
    lengthSB->setMinimum(1);

    ratioSB=new QDoubleSpinBox(this);
    ratioSB->setDecimals(5);
    ratioSB->setValue(1);
    ratioSB->setMinimum(0.00001);

    signCB=new QCheckBox(this);
    signCB->setChecked(true);
    signCB->setText("Sign");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel("Параметр",this),0,0);
    layout->addWidget(peripheryCB,0,1);
    layout->addWidget(lb,1,0);
    layout->addWidget(filterIDCB,1,1);
    layout->addWidget(lb1,2,0);
    layout->addWidget(startBitSB,2,1);
    layout->addWidget(lb2,3,0);
    layout->addWidget(lengthSB,3,1);
    layout->addWidget(lb3,4,0);
    layout->addWidget(ratioSB,4,1);
    layout->addWidget(btn_box,5,1);
    layout->addWidget(signCB,5,0);
    this->setLayout(layout);

    connect(filterIDCB,QOverload<int>::of(&QComboBox::activated),this,&FilteringDialog::filterActivated);
    connect(peripheryCB,QOverload<int>::of(&QComboBox::activated),this,&FilteringDialog::peripheryActivated);
    connect(lengthSB,QOverload<int>::of(&QSpinBox::valueChanged),this,&FilteringDialog::lengthActivated);
    connect(ratioSB,QOverload<double>::of(&QDoubleSpinBox::valueChanged),this,&FilteringDialog::ratioActivated);
    connect(startBitSB,QOverload<int>::of(&QSpinBox::valueChanged),this,&FilteringDialog::stBitActivated);


}
param_filter FilteringDialog::filter()
{
    auto pf=param_filter{};
    pf.sign=this->sign();
    auto fid=this->filterID();
    if (fid!=0){
        pf.frame_id=fid;
        return pf;
    }
    pf.length=this->length();
    pf.ratio=this->ratio();
    pf.start_bit=this->startBit();
    if (m_state==State::Periphery){
        auto p1=qvariant_cast<param_filter>(peripheryCB->currentData());
        return p1;
    }
    return pf;
}

void FilteringDialog::peripheryActivated()
{
    auto index=peripheryCB->currentIndex();
    if (index!=0){
        auto filter=qvariant_cast<param_filter>(peripheryCB->currentData());
        lengthSB->blockSignals(true);
        lengthSB->setValue(filter.length);
        lengthSB->blockSignals(false);

        startBitSB->blockSignals(true);
        startBitSB->setValue(filter.start_bit);
        startBitSB->blockSignals(false);

        ratioSB->blockSignals(true);
        ratioSB->setValue(filter.ratio);
        ratioSB->blockSignals(false);
        changeState(State::Periphery);
    }else{
        if (m_state==State::Periphery){
            changeState(State::Manual);
        }
    }
}

void FilteringDialog::filterActivated()
{
    auto index=filterIDCB->currentIndex();
    if (index!=0){
        changeState(State::Filter);

    }else{
        if (m_state==State::Filter){
            changeState(State::Manual);
        }
    }
}

void FilteringDialog::lengthActivated(int value)
{
    changeState(State::Manual);
}

void FilteringDialog::ratioActivated(double value)
{
     changeState(State::Manual);
}

void FilteringDialog::stBitActivated(int value)
{
    changeState(State::Manual);
}

void FilteringDialog::changeState(State state)
{
    if(m_state==state){
        return;
    }

    bool isEnabled=false;
    switch(state){

        case State::Manual:
            filterIDCB->setCurrentIndex(0);
            peripheryCB->setCurrentIndex(0);
            filterIDCB->setEnabled(true);
            peripheryCB->setEnabled(true);
            isEnabled=true;
        break;

        case State::Filter:
            peripheryCB->setCurrentIndex(0);
            peripheryCB->setEnabled(false);

            isEnabled=false;
        break;

        case State::Periphery:
            filterIDCB->setCurrentIndex(0);
            filterIDCB->setEnabled(false);
            isEnabled=true;
        break;

    }

    lengthSB->setEnabled(isEnabled);
    startBitSB->setEnabled(isEnabled);
    ratioSB->setEnabled(isEnabled);
    m_state=state;
}
