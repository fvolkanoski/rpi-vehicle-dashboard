#include <QDebug>

#include "canbusmanager.h"

CanBusManager::CanBusManager(QObject *parent)
    : QObject{parent},
      _canBusModule(new CanBusModule(this))
{
    connect(_canBusModule, &CanBusModule::frameReceived, this, &CanBusManager::canFrameReceived);
}

CanBusManager::~CanBusManager()
{
    delete _canBusModule;
}

void CanBusManager::canFrameReceived(QCanBusFrame frame)
{
    qDebug() << "--------- CanBus frame: --------- ";
    qDebug() << ".toString():" << frame.toString();
    qDebug() << "payload(): " << frame.payload();
    qDebug() << "isValid(): " << frame.isValid();
    qDebug() << "hasLocalEcho():" << frame.hasLocalEcho();
    qDebug() << "frameId():" << frame.frameId();
    qDebug() << "error():" << frame.error();
    qDebug() << "frameType():" << frame.frameType();
    qDebug() << "----------------------------------";
}
