#include "commcontroller.h"
#include "../../share/globals.h"

CommController::CommController(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_TEST))
{
    // TODO: Write to log if dbus can't connect.
    _dbusModule->connect();
    connect(_dbusModule, &DbusModule::frameReceived, this, &CommController::messageReceived);
}

bool CommController::sendMsgToDbus(const QString &msg)
{
    // TODO: Add ComboBox to choose where to send msg.
    return _dbusModule->sendFrame(DBUS_DASHBOARD, msg);
}

void CommController::messageReceived(const QString &deviceId, const QString &msg)
{
    // TODO: Display received messages on UI.
    Q_UNUSED(deviceId);
    Q_UNUSED(msg);
}
