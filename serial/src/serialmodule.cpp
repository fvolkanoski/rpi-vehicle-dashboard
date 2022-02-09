#include <QtSerialPort/QSerialPortInfo>

#include "serialmodule.h"
#include "../share/globals.h"

SerialModule::SerialModule(QObject *parent)
    : QObject(parent)
{
    _serialPort = new QSerialPort(this);

    connect(_serialPort, &QSerialPort::readyRead, this, &SerialModule::receive);
    connect(_serialPort, &QSerialPort::errorOccurred, this, &SerialModule::serialError);
}

bool SerialModule::openPort()
{
    if(!_serialPort->setBaudRate(BAUD_RATE) &&
       !_serialPort->setParity(QSerialPort::Parity::NoParity) &&
       !_serialPort->setStopBits(QSerialPort::StopBits::OneStop) &&
       !_serialPort->setDataBits(QSerialPort::DataBits::Data8))
        return false;

    _serialPort->setPortName(PORT_NAME);

    if(!_serialPort->open(QIODevice::ReadWrite))
        return false;

    return true;
}

void SerialModule::receive()
{
    emit dataReceived(_serialPort->readAll().trimmed());
}

void SerialModule::serialError(QSerialPort::SerialPortError err)
{
    Q_UNUSED(err);
    // TODO: Handle serial error.
}

SerialModule::~SerialModule()
{
    delete _serialPort;
}
