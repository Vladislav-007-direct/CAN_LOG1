#include "read_thread.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "QtDebug"
#include <Crc/ModbusCrc.h>

#include <QTimer>
#include <Crc/ModbusCrc.h>

#include "geostreampacketvirtual.h"

#include <QMutexLocker>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QPlainTextEdit>

#define MINGSPACKETSIZE 18

QList<can_frm> export_data_can1;
QList<can_frm> export_data_can2;

read_thread::read_thread(MainWindow * mw): _mw(mw) {

    connect(this,SIGNAL(plog(QByteArray)),_mw,SLOT(parseLog(QByteArray)));

    connect(this,SIGNAL(istarterror()),_mw,SLOT(_can1_starterror()));
    connect(this,SIGNAL(fwinfo(QByteArray)),_mw,SLOT(fwinfo(QByteArray)));

    connect(&tx1, SIGNAL(timeout()), this, SLOT(tx1_tm()));
    connect(&tx2, SIGNAL(timeout()), this, SLOT(tx2_tm()));

}

void read_thread::start_tx1(QList<Task> taskList,uint bigCycleRepeats) {
    if (taskList.length()>0){
        tx1_current_task = 0;
        tx1_big_cycle_repeat_count = bigCycleRepeats;
        tx1_task_list = taskList;
        tx1_current_task_repeat_count = taskList[0].repeats;
        tx1.setInterval(taskList[0].delay>2?taskList[0].delay:0);

        tx1.start();
    }
}
void read_thread::start_tx2(QList<Task> taskList,uint bigCycleRepeats) {
    if (taskList.length()>0){
        tx2_current_task = 0;
        tx2_big_cycle_repeat_count = bigCycleRepeats;
        tx2_task_list = taskList;
        tx2_current_task_repeat_count = taskList[0].repeats;
        tx2.setInterval(taskList[0].delay>2?taskList[0].delay:0);

        tx2.start();
    }
}
void read_thread::start_tx3(QByteArray data, int ntx3, int delay) {
    tx3_data = data;
    tx3_nrem = ntx3;

    if(delay<=2)
        delay=0;

    tx3.setInterval(delay);
    tx3.start();

}
void read_thread::start_tx4(QByteArray data, int ntx4, int delay) {
    tx4_data = data;
    tx4_nrem = ntx4;

    if(delay<=2)
        delay=0;

    tx4.setInterval(delay);
    tx4.start();


}

void read_thread::stop_tx1() {
    tx1.stop();
    tx1_nrem = 0;

    tx1_big_cycle_repeat_count = 0;
    tx1_current_task = 0;
    tx1_current_task_repeat_count = 0;
}
void read_thread::stop_tx2() {
    tx2.stop();
    tx2_nrem = 0;

    tx2_big_cycle_repeat_count = 0;
    tx2_current_task = 0;
    tx2_current_task_repeat_count = 0;
}
void read_thread::stop_tx3() {
    tx3.stop();
    tx3_nrem = 0;
}
void read_thread::stop_tx4() {
    tx4.stop();
    tx4_nrem = 0;
}

void read_thread::tx1_tm() {
    qDebug() << "tx1_tm()";

    bool proceed = false;

    if (tx1_current_task_repeat_count > 0) proceed = true;
    else if (++tx1_current_task < tx1_task_list.length()) {
        proceed = true;
        tx1_current_task_repeat_count = tx1_task_list[tx1_current_task].repeats;
        tx1.setInterval(tx1_task_list[tx1_current_task].delay>2?tx1_task_list[tx1_current_task].delay:0);
    }
    else if(--tx1_big_cycle_repeat_count > 0) {
        proceed = true;
        tx1_current_task = 0;
        tx1_current_task_repeat_count = tx1_task_list[tx1_current_task].repeats;
        tx1.setInterval(tx1_task_list[tx1_current_task].delay>2?tx1_task_list[tx1_current_task].delay:0);
    }

    if (proceed) {
        QByteArray data = tx1_task_list[tx1_current_task].block;
        tx1_current_task_repeat_count--;

        GeoStreamPacketVirtual g;
        g.makeTxReq(data);
        qDebug() << "Sending data: " << g.getData().toHex(' ');
        virtual_write_data(g.getData());

        can_frm cf;
        cf.frm_id = *(reinterpret_cast<quint32*>(&data.data()[4])); // another way of converting bytes to data
        cf.frm_id &= ~(1<<31);
        cf.data[0] = data[9];
        cf.data[1] = data[10];
        cf.data[2] = data[11];
        cf.data[3] = data[12];
        cf.data[4] = data[13];
        cf.data[5] = data[14];
        cf.data[6] = data[15];
        cf.data[7] = data[16];

        if((export_data_can1.size()%10240)==0 || export_data_can1.size()==0)
            export_data_can1.reserve(export_data_can1.size()+10240);
        export_data_can1.append(cf);

        qDebug() << "tx1_data: " << data.toHex(' ');

        QByteArray frameID;
        frameID.append(reinterpret_cast<char*>(&cf.frm_id), 4);
        std::reverse(frameID.begin(), frameID.end());
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString str = QString("TX ") + MainWindow::create_table_row_string(
                _mw->tx1_count++,
                frameID.toHex().toUpper(),
                (uchar)data[8],
                data.mid(9,8),
                currentDateTime.toSecsSinceEpoch(),
                currentDateTime.date().day(),
                currentDateTime.date().month(),
                currentDateTime.date().year(),
                currentDateTime.time().hour(),
                currentDateTime.time().minute(),
                currentDateTime.time().second(),
                currentDateTime.time().msec());

//        QString str  = QString("tx %1%2%3%15%4%16%5%16%6%16%7%16%8%16%9%16%10%16%11%15%12%13%14")
//              .arg(_mw->tx1_count++,4)
//              .arg(QString("0x")+QString(frameID),12)
//              .arg((uchar)data[8] ,4, 16)
//              .arg((uchar)data[9] ,2, 16, QChar('0'))
//              .arg((uchar)data[10],2, 16, QChar('0'))
//              .arg((uchar)data[11],2, 16, QChar('0'))
//              .arg((uchar)data[12],2, 16, QChar('0'))
//              .arg((uchar)data[13],2, 16, QChar('0'))
//              .arg((uchar)data[14],2, 16, QChar('0'))
//              .arg((uchar)data[15],2, 16, QChar('0'))
//              .arg((uchar)data[16],2, 16, QChar('0'))
//              .arg(QDateTime::currentSecsSinceEpoch(),10)
//              .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy"),11)
//              .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz"),13)
//              .arg(QString(""),5,QChar(' ')) // %15 is 12 char spacer
//              .arg(QString(""),2,QChar(' ')) // %16 is 2 char spacer
//              .toUpper();

        qDebug() << "Window 1";
        _mw->show_can1_mdi_window();
        QTextCharFormat tf = _mw->can1_mdiUI->log->currentCharFormat();
        tf.setForeground(QBrush(Qt::blue));
        _mw->can1_mdiUI->log->setCurrentCharFormat(tf);
        _mw->can1_mdiUI->log->appendPlainText(str);
    }
    else
    {   
        qDebug() << "stop tx1_tm()";
        tx1.stop();
    }
}
void read_thread::tx2_tm() {
    qDebug() << "tx2_tm()";

    bool proceed = false;

    if (tx2_current_task_repeat_count > 0) proceed = true;
    else if (++tx2_current_task < tx2_task_list.length()) {
        proceed = true;
        tx2_current_task_repeat_count = tx2_task_list[tx2_current_task].repeats;
        tx2.setInterval(tx2_task_list[tx2_current_task].delay>2?tx2_task_list[tx2_current_task].delay:0);
    }
    else if (--tx2_big_cycle_repeat_count > 0) {
        proceed = true;
        tx2_current_task = 0;
        tx2_current_task_repeat_count = tx2_task_list[tx2_current_task].repeats;
        tx2.setInterval(tx2_task_list[tx2_current_task].delay>2?tx2_task_list[tx2_current_task].delay:0);
    }

    if (proceed) {
        QByteArray data = tx2_task_list[tx2_current_task].block;
        tx2_current_task_repeat_count--;

        GeoStreamPacketVirtual g;
        g.makeTxReq(data);
        virtual_write_data(g.getData());

        can_frm cf;
        cf.frm_id = (quint32)(* reinterpret_cast<quint32*>(&data.data()[4])); // another way of converting bytes to data
        cf.frm_id &= ~(1<<31);
        cf.data[0] = data[9];
        cf.data[1] = data[10];
        cf.data[2] = data[11];
        cf.data[3] = data[12];
        cf.data[4] = data[13];
        cf.data[5] = data[14];
        cf.data[6] = data[15];
        cf.data[7] = data[16];

        if((export_data_can2.size()%10240)==0 || export_data_can2.size()==0)
            export_data_can2.reserve(export_data_can2.size()+10240);

        export_data_can2.append(cf);

        qDebug() << "tx2_data: " << data.toHex(' ');
        QByteArray frameID;
        frameID.append(reinterpret_cast<char*>(&cf.frm_id), 4);
        std::reverse(frameID.begin(), frameID.end());
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString str = QString("TX ") + MainWindow::create_table_row_string(
                _mw->tx2_count++,
                frameID.toHex().toUpper(),
                (uchar)data[8],
                data.mid(9,8),
                currentDateTime.toSecsSinceEpoch(),
                currentDateTime.date().day(),
                currentDateTime.date().month(),
                currentDateTime.date().year(),
                currentDateTime.time().hour(),
                currentDateTime.time().minute(),
                currentDateTime.time().second(),
                currentDateTime.time().msec());
        _mw->show_can2_mdi_window();
        QTextCharFormat tf = _mw->can2_mdiUI->log->currentCharFormat();
        tf.setForeground(QBrush(Qt::blue));
        _mw->can2_mdiUI->log->setCurrentCharFormat(tf);
        _mw->can2_mdiUI->log->appendPlainText(str);
    }
    else {
        qDebug() << "stop tx2_tm()";
        tx2.stop();
    }
}
void read_thread::tx3_tm() {
    if (tx3_nrem > 0 || tx3_nrem == -1) {
        //virtual_write_data(tx3_data);

        if (tx3_nrem > 0) tx3_nrem--;
    }

}
void read_thread::tx4_tm() {
    if (tx4_nrem > 0 || tx4_nrem == -1) {
        //virtual_write_data(tx4_data);

        if (tx4_nrem > 0) tx4_nrem--;
    }
}

void read_thread::devconnect() {
	qDebug() << "devconnect";

	if (_mw->serialPort && _mw->serialPort->isOpen())
	{
		qDebug() << "port already open";
        emit showStatus(tr("???????? ?????? ????????????"));
		return;

	}
    bool recon = false;
    if (_mw->serialPort) {
        delete _mw->serialPort;
        _mw->serialPort = nullptr;
        recon = true;
    }

	_mw->sPortName = QString();

	QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

	int not_found = 1;
	for (auto port : ports)
	{
		qDebug() << port.manufacturer();
		qDebug() << port.serialNumber();

        if (port.hasVendorIdentifier() && port.hasProductIdentifier() &&
            port.vendorIdentifier() == 0x0484 && port.productIdentifier() == 0x0001
           ) {
			not_found = 0;
			qDebug() << "opening port";
            emit showStatus(tr("?????????????????????? ????????"));
            if (!recon) QApplication::processEvents();
			_mw->sPortName = port.portName();
			if (!_mw->serialPort)
				_mw->serialPort = new QSerialPort(_mw->sPortName, this);
            _mw->serialPort->setSettingsRestoredOnClose(false);
            if (!_mw->serialPort->open(QIODevice::ReadWrite)) {
				qDebug() << "cannot open serial port";
                emit showStatus(tr("???????????????????? ?????????????? ????????"));
                if (!recon) QApplication::processEvents();
				return;
			}
			connect(_mw->serialPort, SIGNAL(readyRead()), this, SLOT(read_data()));
            connect(_mw->serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError )), this, SLOT(error()));
            connect(this, SIGNAL(showStatus(QString)),_mw, SLOT(showStatus(QString)));
            connect(this, SIGNAL(greenStatus()),_mw, SLOT(greenStatus()));
            connect(this, SIGNAL(redStatus()),_mw, SLOT(redStatus()));
            _mw->serialPort->setBaudRate(1000000);
            if(!_mw->serialPort->setDataTerminalReady(true))
                emit showStatus(tr("???????????????????? ?????????????????? DTR"));
            qDebug() << "_mw->serialPort->isDataTerminalReady() " <<
                        _mw->serialPort->isDataTerminalReady();
            emit showStatus(tr("???????? ????????????"));
            if (!recon) QApplication::processEvents();
            emit greenStatus();
            if (!recon) QApplication::processEvents();
			break;
		}
	}

    if (not_found) {
        emit showStatus(tr("???????? ???? ????????????"));
        emit redStatus();
        if (!recon) QApplication::processEvents();
	}
}
void read_thread::devdisconnect() {
	qDebug() << "devdisconnect";

	if (_mw->serialPort)
	{
        _mw->serialPort->clear();
        _mw->serialPort->clearError();
        _mw->serialPort->close();
        emit showStatus(tr("???????? ????????????"));
        emit redStatus();
        QApplication::processEvents();

//        disconnect(_mw->serialPort);
	}
}

void read_thread::virtual_write_data(QByteArray data) {
    qDebug() << data.toHex(' ');
    int datalen=data.size();

    if(_mw->serialPort && _mw->serialPort->isOpen())
    {
        QMutexLocker lock(&_mw->serialPortMutex);

        //if(serialPort->flush()) qDebug() << "flush ok";
        //if (_mw->serialPort && _mw->serialPort->error() != QSerialPort::NoError)
        //{
        //    _mw->serialPort->clearError();
        //}


        int len = 0;
        int count=0;
        while(((len+=_mw->serialPort->write(data))!=datalen && _mw->serialPort->waitForBytesWritten(100)==false && count < 100))
        {
            if(len==0)
                break;
            auto bytes = _mw->serialPort->waitForBytesWritten(100);
            qDebug() << "bytes " << bytes;
            if(len>0)
                data.remove(0,len);
            count ++;
        }

        /*
        _mw->serialPort->write(data);
        _mw->serialPort->flush();
        _mw->serialPort->waitForBytesWritten(1000);
        */
    }
    else
    {
        if(data[0] == (char)0xdb && data[1] == (char)0xea && data[2] == (char)0x02){
            QString error = parse_error(data[3]);
            emit interfaceConfigurationFailed(error);
        }
        if(data[0] == (char)0xdb && data[1] == (char)0xea && data[2] == (char)0x10){
            QString error = parse_error(data[3]);
            emit variableConfigurationFailed(error);
        }
        if(data[0] == (char)0x45 && data[1] == (char)0x00 && data[2] == (char)0x60){
            QString error = parse_error(data[3]);
            emit interfaceConfigurationFailed(error);
        }
        if(data[0] == (char)0x40 && data[1] == (char)0x00 && data[2] == (char)0x60){
            QString error = parse_error(data[3]);
            emit interfaceConfigurationFailed(error);
        }
        qDebug() << "port closed";
    }
}
void read_thread::can_startbn() {
	qDebug() << "startbn";

    emit showStatus(tr("??????????"));

	GeoStreamPacketVirtual* gsp0 = new GeoStreamPacketVirtual;
	gsp0->makeStartReq();
    virtual_write_data(gsp0->getData());
	delete gsp0;
}
void read_thread::can_stopbn() {
	qDebug() << "stopbn";

    emit showStatus(tr("??????????????"));

	GeoStreamPacketVirtual* gsp0 = new GeoStreamPacketVirtual;
	gsp0->makeStopReq();
    virtual_write_data(gsp0->getData());
	delete gsp0;
}

void read_thread::get_fw_info() {
    qDebug() << "read_thread::get_fw_info();";

    GeoStreamPacketVirtual g;

    g.makeInfoReq();
    virtual_write_data(g.getData());

}

void read_thread::error() {
    if (_mw->serialPort && _mw->serialPort->isOpen() && _mw->serialPort->error() != QSerialPort::NoError)
    {
        if( _mw->serialPort->error() == QSerialPort::WriteError ||
            _mw->serialPort->error() == QSerialPort::ReadError )
        {

            _mw->serialPort->clearError();
            return;
        }

        _mw->serialPort->clearError();
        emit showStatus(tr("???????????? ???? ??????????. ?????????????? ???????????????????????? ???????????????????? ?? ????????????"));
        emit redStatus();

        _mw->serialPort->close();
        disconnect(_mw->serialPort);
        for (int i=0; i<100; i++) {
            qDebug()<< "trying to reopen port";
            QThread::msleep(1000);
            devconnect();
            QThread::msleep(1000);
            if (_mw->serialPort && _mw->serialPort->isOpen() ) {
                _mw->serialPort->clearError();
                emit showStatus(tr("???????? ????????????"));
                emit greenStatus();
                break;
            }
        }
    }
}
QString read_thread::parse_error(const int& code_error) {
    QString err;
    switch (code_error) {
        case 0x01:  err = "?????????????????????? ????????????"; break;
        case 0x02:  err = "???????????????? CRC ????????????"; break;
        case 0x08:  err = "?????????????? ???????????? ????????????"; break;
        case 0x09:  err = "???????????????? ???????????? ??????????????????"; break;
        case 0x10: err = "?????????????????? ???????????????????????????????????? ???? ????????????????????????????"; break;
        case 0x11: err = "???????????????????????? ????????????????"; break;
        case 0x12: err = "?????????????? ???? ????????????????????????????"; break;
        case 0x17: err = "?????? ?????????? ?????? ?????????????????? ???????????????????????????????????? ?? ?????????????? ???? ????????????????????????????"; break;
    }
    return err;
}

void read_thread::read_data() {
    qDebug() << "read_data()";
    if (paused) {
        return;
    }
    if (_mw->serialPort && _mw->serialPort->isOpen()) {
		if (_mw->serialPort->error() == QSerialPort::NoError)
			//if (_mw->serialPort->bytesAvailable() > 0)
			{
				data+= _mw->serialPort->readAll();

				qDebug() << "* " << data.toHex(' ');

				int parseLen = 0;

				quint32 len = 0;
                for (int i = 0; i + MINGSPACKETSIZE <= data.size(); ) {

                    len = *(reinterpret_cast<quint32*>(&data.data()[i + 10]));

					qDebug() << "len=" << len;

                    if (i + len > (uint)data.size() || len < MINGSPACKETSIZE) {
                        break;
					}

					quint16 my_crc16 = CRC16((uint8_t*)(&data.data()[i]), len - 2);
					quint16 _crc16 = *(reinterpret_cast<quint16*>(&data.data()[i + len - 2]));

					qDebug() << QString::number(my_crc16) << " " << QString::number(_crc16);

                    if (my_crc16 != _crc16) {
						i++;
						parseLen++;
						continue;
					}

					qDebug() << "crc16 match";

					parseLen += len;

					QByteArray d;
                    d = data.mid(i + 16, len - MINGSPACKETSIZE); // 16 bytes - head; 2 bytes - crc16

					qDebug() << "d.size()=" << d.size();

                    GeoStreamPacketVirtual gspv;
					gspv.initFromBufferData(data);

                    int haveError = 0;
                    if (gspv.checkCfgPk(haveError) || gspv.checkCfgPrph(haveError) || gspv.checkCraneInfo(haveError) || gspv.checkIDInfo(haveError)) {
                        if (!haveError) {
                            if (time_syncing) time_syncing=0; // there was a time sync request
                            else {
                                qint16 size_block = *(reinterpret_cast<quint16*>(&data.data()[16]));
                                QByteArray block_data = data.mid(18, size_block - 2);
                                emit interfaceConfigurationSuccess(block_data); // it was a interface configuration request
                            }
                        }
                        else {
                            QString error = parse_error(haveError);
                            emit interfaceConfigurationFailed(error);
                        }
                    }

                    haveError = 0;
                    if (gspv.checkCfgIDPk(haveError)) {
                        if (!haveError) {
                            emit variableConfigurationSuccess();
                        }
                        else {
                            QString error = parse_error(haveError);
                            emit variableConfigurationFailed(error);
                        }
                    }

                    if (gspv.checkInfoAk()) {
                        qDebug() << "gspv.checkInfoAk()";
                        QByteArray fw_info = gspv.getDataBlock().mid(10,8);

                        qDebug() << "emit fwinfo(fw_info);";
                        emit fwinfo(fw_info);
                    }

					int error = 0;
					if (gspv.checkStartPk(error) && error != 0)
						emit istarterror();

					emit plog(d);

					i += len;
				}

				data.remove(0, parseLen);
			}
	}
}

void read_thread::devconn() {
    devconnect();
    return; // b1 - ??????, b2 - ????????????????
    for (int i = 0; i < 10; i++) {
        qDebug() << "trying to reopen port";
        emit showStatus(tr("?????????????? ???????????????????????? ???????????????????? ?? ????????????"));
        emit redStatus();
        QApplication::processEvents();
        QThread::msleep(2000);

        devconnect();

//        if (_mw->serialPort->open(QIODevice::ReadWrite) ) {
        if (_mw->serialPort->isOpen() ) {
            emit showStatus(tr("???????? ????????????"));
            emit greenStatus();
            break;
        }
    }
}
void read_thread::devdisconn() {
    devdisconnect();
    return;
    _mw->serialPort->clear();
    _mw->serialPort->close();
}

void read_thread::time_sync() {
    GeoStreamPacketVirtual gsp0;
    gsp0.makeTimeSyncReq();
    virtual_write_data(gsp0.getData());

    time_syncing=1;
}

void read_thread::run() {
	while (1)
		exec();
}
void read_thread::play() {
    paused=false;

    if (_mw->serialPort && _mw->serialPort->isOpen() ) {
        connect(_mw->serialPort, SIGNAL(readyRead()), this, SLOT(read_data()));
    }

    qDebug() << "play;";
}
void read_thread::pause() {

    paused=true;

    if (_mw->serialPort && _mw->serialPort->isOpen() ) {
        disconnect(_mw->serialPort, SIGNAL(readyRead()), this, SLOT(read_data()));
    }

}
void read_thread::reload() {
    GeoStreamPacketVirtual* g = new GeoStreamPacketVirtual;
    g->makeWorkReq();
    virtual_write_data(g->getData());
}
