#include "serialmanager.h"

#include <QDebug>

SerialManager::SerialManager(QObject *parent)
    : QObject(parent),
      _serialModule(new SerialModule(this)),
      _dbusModule(new DbusModule(DBUS_SERIAL, this))
{
    if(!_serialModule->openPort())
        qDebug() << "Failed to open serial port";

    connect(_serialModule, &SerialModule::dataReceived, this, &SerialManager::dataReceived);
}

SerialManager::~SerialManager()
{
    delete _serialModule;
}

void SerialManager::dataReceived(QString msg)
{
    // TODO: Add checks whether it needs to go to dashboard process.
    _dbusModule->sendFrame(DBUS_DASHBOARD, msg);
}
