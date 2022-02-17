#include <QDebug>

#include "detectorcontroller.h"
#include "../share/globals.h"

DetectorController::DetectorController(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_TLDETECTOR)),
      _tlDetector(new TrafficLightDetector())
{
    // TODO: Write to log if dbus can't connect.
    _dbusModule->connect();

    _tlDetector->moveToThread(&_tlDetectorThread);
    connect(&_tlDetectorThread, &QThread::finished, _tlDetector, &QObject::deleteLater);
    connect(_tlDetector, &TrafficLightDetector::detected, this, &DetectorController::tlDetected);
    connect(this, &DetectorController::startDetection, _tlDetector, &TrafficLightDetector::startDetection);

    _tlDetectorThread.start();
}

DetectorController::~DetectorController()
{
    delete _dbusModule;
    delete _tlDetector;
}

void DetectorController::start(QString camera)
{
    emit startDetection(camera);
}

void DetectorController::tlDetected(const TrafficLightDetector::TrafficLight &trafficLight)
{
    // TODO: Send message to dashboard that a traffic light was detected.

    qDebug() << "Traffic light detected: " << trafficLight;
}
