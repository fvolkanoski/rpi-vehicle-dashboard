#pragma once

#include <QObject>

#include "serialmodule.h"
#include "../share/globals.h"
#include "../share/dbus/dbusmodule.h"
#include "../share/dbus/dbushelper.h"

class SerialManager : public QObject
{
    Q_OBJECT

public:
    explicit SerialManager(QObject *parent = nullptr);

    ~SerialManager();

private slots:
    void dataReceived(QString msg);

private:
    SerialModule *_serialModule;
    DbusModule *_dbusModule;
};
