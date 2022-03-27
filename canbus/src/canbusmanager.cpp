#include <QDebug>

#include "canbusmanager.h"
#include "../../share/globals.h"

CanBusManager::CanBusManager(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_CANBUS)),
      _canBusModule(new CanBusModule(this))
{
    // TODO: Write to log if dbus can't connect.
    _dbusModule->connect();
    connect(_dbusModule, &DbusModule::frameReceived, this, &CanBusManager::messageReceived);

    connect(_canBusModule, &CanBusModule::frameReceived, this, &CanBusManager::canFrameReceived);
}

CanBusManager::~CanBusManager()
{
    delete _canBusModule;
}

void CanBusManager::messageReceived(const QString &deviceId, const QString &msg)
{
    Q_UNUSED(deviceId);
    Q_UNUSED(msg);
    // TODO: Process received msg from dbus.
}

void CanBusManager::canFrameReceived(QCanBusFrame frame)
{
    qDebug() << "--------- CanBus frame: --------- ";
    qDebug() << ".toString():" << frame.toString();
    qDebug() << "payload(): " << frame.payload();
    qDebug() << "payload().QString" << QByteArray::fromHex(frame.payload());
    qDebug() << "isValid(): " << frame.isValid();
    qDebug() << "hasLocalEcho():" << frame.hasLocalEcho();
    qDebug() << "frameId():" << frame.frameId();
    qDebug() << "error():" << frame.error();
    qDebug() << "frameType():" << frame.frameType();
    qDebug() << "----------------------------------";

    emit _dbusModule->sendFrame(DBUS_DASHBOARD, QByteArray::fromHex(frame.payload()));
}
