#pragma once

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialModule : public QObject
{
    Q_OBJECT

public:
    explicit SerialModule(QObject *parent = nullptr);
    ~SerialModule();

    bool openPort();

signals:
    void dataReceived(QString msg);

private slots:
    void receive();
    void serialError(QSerialPort::SerialPortError err);

private:
    QSerialPort *_serialPort;
};
