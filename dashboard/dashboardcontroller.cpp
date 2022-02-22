#include <QQmlContext>

#include "dashboardcontroller.h"

DashboardController::DashboardController(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_DASHBOARD, this)),
      _msgParser(new MessageParser()),
      _mapController(new MapController())
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
    _engine->rootContext()->setContextProperty("mapController", _mapController);
}

void DashboardController::messageReceived(const QString &deviceId, const QString &msg)
{
    Q_UNUSED(deviceId);

    switch(_msgParser->parseMessageID(msg))
    {
        case 'M': // Map Command
        {
            switch(_msgParser->parseCommandID(msg))
            {
                case 1: // Zoom In
                {
                    _mapController->setZoomLevel(_mapController->zoomLevel() + 0.5);
                    break;
                }
                case 2: // Zoom Out
                {
                    _mapController->setZoomLevel(_mapController->zoomLevel() - 0.5);
                    break;
                }

                default:
                {
                    // TODO: Log unknown command received?
                }
            }
            break;
        }

        default:
        {
            // TODO: Log unknown command received?
        }
    }
}
