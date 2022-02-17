#pragma once

#include <QObject>
#include <QThread>

#include "trafficlightdetector.h"
#include "../share/dbus/dbushelper.h"
#include "../share/dbus/dbusmodule.h"

class DetectorController : public QObject
{
    Q_OBJECT

public:
    explicit DetectorController(QObject *parent = nullptr);
    ~DetectorController();
    void start(QString camera);

signals:
    void startDetection(QString &camera);

public slots:
    void tlDetected(const TrafficLightDetector::TrafficLight &trafficLight);

private:
    DbusModule *_dbusModule;
    TrafficLightDetector *_tlDetector;
    QThread _tlDetectorThread;
};
