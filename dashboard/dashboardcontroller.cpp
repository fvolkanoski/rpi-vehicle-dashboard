#include "dashboardcontroller.h"

DashboardController::DashboardController(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_DASHBOARD, this))
{
    _dbusModule->connect();
    connect(_dbusModule, &DbusModule::frameReceived, this, &DashboardController::messageReceived);
}

DashboardController::~DashboardController()
{
    delete _engine;
    delete _msgParser;
    delete _dbusModule;
}

void DashboardController::initializeQmlContext(QQmlEngine *engine)
{
    if (!engine)
        return;

    _engine = engine;
}

void DashboardController::messageReceived(const QString &deviceId, const QString &msg)
{
    switch(_msgParser->parseMessageType(msg))
    {
        case 'A':
        {
            // Process A.
            break;
        }
    }
}
