#include "dbushelper.h"

DbusHelper::DbusHelper(QObject *parent)
    : QObject(parent)
{

}

void DbusHelper::receiveDirectFrame(const QDBusMessage &msg)
{
    parseDbusMsg(msg);
}

void DbusHelper::receiveBroadcast(const QDBusMessage &msg)
{
    parseDbusMsg(msg);
}

bool DbusHelper::parseDbusMsg(const QDBusMessage &msg)
{
    QList<QVariant> args = msg.arguments();

    auto sourceAddress = args.at(0);
    auto frameBuffer = args.at(1);

    if(sourceAddress.isValid() && frameBuffer.isValid()) {
        emit frameReceived(sourceAddress.toString(), frameBuffer.toString());
        return true;
    }

    return false;
}
