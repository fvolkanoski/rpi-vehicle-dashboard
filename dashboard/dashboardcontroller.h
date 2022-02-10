#pragma once

#include <QObject>
#include <QQmlEngine>

#include "messageparser.h"
#include "../share/globals.h"
#include "../share/dbus/dbusmodule.h"
#include "../share/dbus/dbushelper.h"

class DashboardController : public QObject
{
    Q_OBJECT
public:
    explicit DashboardController(QObject *parent = nullptr);
    ~DashboardController();

    void initializeQmlContext(QQmlEngine *engine);

private slots:
    void messageReceived(QString &msg);

private:
    QQmlEngine *_engine;
    DbusModule *_dbusModule;
    MessageParser *_msgParser;
};
