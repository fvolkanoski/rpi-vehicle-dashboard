#include <QCanBus>
#include <QDebug>
#include <QTime>

#include "canbusmodule.h"

CanBusModule::CanBusModule(QObject *parent)
    : QObject{parent}
{
    if (QCanBus::instance()->plugins().contains(QStringLiteral("virtualcan"))) {
        qDebug() << "Virtualcan is available.";

        _device = QCanBus::instance()->createDevice(
            QStringLiteral("virtualcan"), QStringLiteral("can0"));
        _device->connectDevice();

        connect(_device, &QCanBusDevice::framesReceived, this, &CanBusModule::canBusFrameReceived);
    }
}

CanBusModule::~CanBusModule()
{
    delete _device;
}

void CanBusModule::canBusFrameReceived()
{
    emit frameReceived(_device->readFrame());
}
