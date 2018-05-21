#pragma once

#include <stdio.h>
#include <iostream>
#include <QObject>
#include <QTimerEvent>
#include <QThread>

#include <lcm/lcm-cpp.hpp>

#include "example_t.hpp"

namespace Ui {
class LcmRecv;
}

class LcmRecv : public QObject
{
    Q_OBJECT

public:
    explicit LcmRecv(QObject *parent = 0);
    ~LcmRecv();

    void timerEvent(QTimerEvent *event);

signals:
    void getLcmData(const exlcm::example_t *msg);
    void getLcmChanData(const std::string &chan);

public slots:
    void enableRecv(bool flag);
    void initLcm();

private:
    void recvLcmData();

private:
    lcm::LCM mLcm;

    void handleMessage(const lcm::ReceiveBuffer *rbuf,
                       const std::string &chan,
                       const exlcm::example_t *msg);

    int mRecvTimer = 0;
};
