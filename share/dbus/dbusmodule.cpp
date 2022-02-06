#include "dbusmodule.h"
#include "dbushelper.h"

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusInterface>

#include <iostream>

static QDBusConnection m_bus = QDBusConnection::sessionBus();

DbusModule::DbusModule(const QString &deviceId, QObject *parent)
    : QObject(parent),
      m_helper(new DbusHelper(this))
{
    std::cout << "Init DBus instance for process: " << deviceId.toStdString() << std::endl;

    m_dbusService = m_serviceName + "." + deviceId;
    m_dbusPath = QString("/") + deviceId;
    m_moduleName = QString("Dbus_") + deviceId;

    QObject::connect(m_helper, &DbusHelper::frameReceived,
                     this, &DbusModule::frameReceivedSlot);

    std::cout << "Constructed DBus Module at: \n"
              << "DBus service: " << m_dbusService.toStdString() << "; \n"
              << "DBus Path: " << m_dbusPath.toStdString() << "; \n"
              << "Module Name: " << m_moduleName.toStdString() << std::endl;
}

DbusModule::~DbusModule()
{
    this->disconnect();
    delete m_helper;
}

bool DbusModule::connect()
{
    if (!m_bus.isConnected())
    {
        std::cerr << "Cannot connect to the D-Bus session bus" << std::endl;
        return false;
    }

    if (!m_bus.registerService(m_dbusService))
    {
        std::cerr << "Failed to register DBus service, service '"
                  << m_dbusService.toStdString() << "' is already in use."
                  << std::endl;

        return false;
    }

    if (!m_bus.registerObject(m_dbusPath, "", m_helper, QDBusConnection::ExportScriptableSlots))
    {
        QDBusError err = m_bus.lastError();
        Q_UNUSED(err);

        std::cerr << "Failed to register DBus Object for receiving direct message calls. Error:"
                  << m_bus.lastError().name().toStdString() << std::endl;

        return false;
    }

    m_isConnected = true;
    return true;
}

bool DbusModule::disconnect()
{
    m_bus.disconnectFromBus(m_dbusService);
    m_bus.unregisterObject(m_dbusPath, QDBusConnection::UnregisterNode);
    m_isConnected = false;

    return true;
}

bool DbusModule::sendFrame(const QString &destAddress, const QString &frame)
{
    auto dbusService = m_serviceName + "." + destAddress;
    auto path = QString("/") + destAddress;

    std::cout << "Dbus send to " << destAddress.toStdString()
              << " via service: " << dbusService.toStdString()
              << std::endl;

    if (!m_iFaces.contains(dbusService))
        m_iFaces[dbusService] = new QDBusInterface(dbusService, path, "", QDBusConnection::sessionBus(), this);

    auto &iface = m_iFaces[dbusService];

    if (iface->isValid())
    {
        QDBusMessage msg = iface->call(QDBus::NoBlock, m_receiveFrameMethodName, m_dbusService, frame);
        Q_UNUSED(msg);
        return true;
    }
    else
    {
        std::cerr << QString("Interface not valid: %1").arg(iface->lastError().message()).toStdString() << std::endl;

        return false;
    }
}

void DbusModule::frameReceivedSlot(const QString &deviceId, const QString &frame)
{
    emit this->frameReceived(deviceId, frame);

    std::cout << m_moduleName.toStdString() << " Received frame from: " << deviceId.toStdString()
              << "\nFrame: " << frame.toStdString() << std::endl;
}
