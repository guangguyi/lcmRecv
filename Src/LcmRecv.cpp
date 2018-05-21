#include "LcmRecv.hpp"

#include <QDebug>

LcmRecv::LcmRecv(QObject *parent) : QObject(parent) {}

LcmRecv::~LcmRecv() {}

void LcmRecv::timerEvent(QTimerEvent *event) {
    if (mRecvTimer == event->timerId()) {
        recvLcmData();
    }
}

void LcmRecv::enableRecv(bool flag) {
    if (flag) {
        if (mRecvTimer == 0) {
            mRecvTimer = startTimer(100);
        }
    } else {
        killTimer(mRecvTimer);
        mRecvTimer = 0;
    }
}

void LcmRecv::initLcm() {
    if (!mLcm.good()) {
        qWarning() << "mLcm is not good";
        return;
    }

    mLcm.subscribe("EXAMPLE", &LcmRecv::handleMessage, this);
}

void LcmRecv::handleMessage(const lcm::ReceiveBuffer *rbuf,
                            const std::string &chan,
                            const exlcm::example_t *msg) {
    Q_UNUSED(rbuf);
    emit getLcmChanData(chan);
    emit getLcmData(msg);
}

void LcmRecv::recvLcmData() {
    qDebug() << "LcmRec Thread: " << QThread::currentThread();
    mLcm.handleTimeout(50);
}
