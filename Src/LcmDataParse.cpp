#include "LcmDataParse.hpp"
#include <QDebug>

LcmDataParse::LcmDataParse(QObject *parent) : QObject(parent) {
    mLcmRecv.reset(new LcmRecv);
    mLcmRecvThread.reset(new QThread);
    mLcmRecv->moveToThread(mLcmRecvThread.get());

    connect(mLcmRecv.get(), &LcmRecv::getLcmChanData, this, &LcmDataParse::parseLcmChanData, Qt::DirectConnection);
    connect(mLcmRecv.get(), &LcmRecv::getLcmData, this, &LcmDataParse::parseLcmData, Qt::DirectConnection);
    connect(this, &LcmDataParse::enableLcmRecv, mLcmRecv.get(), &LcmRecv::enableRecv);
    connect(this, &LcmDataParse::initLcm, mLcmRecv.get(), &LcmRecv::initLcm);

    mLcmRecvThread->start();
    qDebug() << "Main threadThread: " << QThread().currentThread();

    emit initLcm();
}

LcmDataParse::~LcmDataParse() {
    mLcmRecvThread->quit();
    mLcmRecvThread->wait();
}

void LcmDataParse::setLcmDataRecvState(bool flag) {
    emit enableLcmRecv(flag);
}

void LcmDataParse::parseLcmChanData(const std::string &chan)
{
        mChannelName = chan.c_str();
        emit channelNameChanged();
}

void LcmDataParse::parseLcmData(const exlcm::example_t *msg) {
    int i;
    mTimestamp = msg->timestamp;
    emit timestampChanged();

    mPosition = msg->position[0];
    emit positionChanged();

    mOrientation = msg->orientation[0];
    emit orientationChanged();

    for(i = 0; i < msg->num_ranges; i++)
        mNumRanges = msg->ranges[i];
        emit numRangesChanged();

    mNames = msg->name.c_str();
    emit namesChanged();

    mEnabled = msg->enabled;
    emit enabledChanged();
}
