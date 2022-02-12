#pragma once

#include <QObject>

#include "../../share/dbus/dbusmodule.h"
#include "../../share/dbus/dbushelper.h"

class CommController : public QObject
{
    Q_OBJECT
public:
    explicit CommController(QObject *parent = nullptr);

    Q_INVOKABLE bool sendMsgToDbus(const QString &msg);

private slots:
    void messageReceived(const QString &deviceId, const QString &msg);

private:
    DbusModule *_dbusModule;
};
