#pragma once

#include <QObject>
#include <QThread>
#include <memory>
#include <cstdlib>
#include <functional>
#include "LcmRecv.hpp"

class LcmDataParse : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString channelName MEMBER mChannelName NOTIFY channelNameChanged)
    Q_PROPERTY(int timestamp MEMBER mTimestamp NOTIFY timestampChanged)
    Q_PROPERTY(double position MEMBER mPosition NOTIFY positionChanged)
    Q_PROPERTY(double orientation MEMBER mOrientation NOTIFY orientationChanged)
    Q_PROPERTY(int numRanges MEMBER mNumRanges NOTIFY numRangesChanged)
    Q_PROPERTY(int ranges MEMBER mRanges NOTIFY rangesChanged)
    Q_PROPERTY(QString names MEMBER mNames NOTIFY namesChanged)
    Q_PROPERTY(int enabled MEMBER mEnabled NOTIFY enabledChanged)

public:
    explicit LcmDataParse(QObject *parent = nullptr);
    ~LcmDataParse();

    Q_INVOKABLE void setLcmDataRecvState(bool flag);

signals:
    void channelNameChanged();
    void timestampChanged();
    void positionChanged();
    void orientationChanged();
    void numRangesChanged();
    void rangesChanged();
    void namesChanged();
    void enabledChanged();

    void enableLcmRecv(bool flag);
    void initLcm();

public slots:
    void parseLcmData(const exlcm::example_t *msg);
    void parseLcmChanData(const std::string &chan);

private:
    std::unique_ptr<LcmRecv> mLcmRecv = nullptr;
    std::unique_ptr<QThread> mLcmRecvThread = nullptr;

    int mRecvLcmDataTimer = 0;
    bool mEnableLcmDataRecv = false;

    QString mChannelName = "wating...";
    int mTimestamp = 0;
    double mPosition = 0;
    double mOrientation = 0;
    int mNumRanges = 0;
    int mRanges = 0;
    QString mNames = "waiting...";
    int mEnabled = 0;
};
