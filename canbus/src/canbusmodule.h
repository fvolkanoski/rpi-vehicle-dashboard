#pragma once

#include <QObject>
#include <QCanBusDevice>

class CanBusModule : public QObject
{
    Q_OBJECT
public:
    explicit CanBusModule(QObject *parent = nullptr);

signals:
    void frameReceived(QCanBusFrame frame);

private slots:
    void canBusFrameReceived();

private:
    QCanBusDevice *_device;
};
