#pragma once

#include <QObject>

#include "canbusmodule.h"

class CanBusManager : public QObject
{
    Q_OBJECT
public:
    explicit CanBusManager(QObject *parent = nullptr);
    ~CanBusManager();

private slots:
    void canFrameReceived(QCanBusFrame frame);

private:
    CanBusModule *_canBusModule;
};
