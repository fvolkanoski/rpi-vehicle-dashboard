#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
    : QObject(parent)
{
    _serialModule = new SerialModule(this);
}

SerialManager::~SerialManager()
{
    delete _serialModule;
}
