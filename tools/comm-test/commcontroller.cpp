#include <QCanBus>
#include <QDebug>

#include "commcontroller.h"
#include "../../share/globals.h"

CommController::CommController(QObject *parent)
    : QObject{parent},
      _dbusModule(new DbusModule(DBUS_TEST))
{
    // TODO: Write to log if dbus can't connect.
    _dbusModule->connect();
    connect(_dbusModule, &DbusModule::frameReceived, this, &CommController::messageReceived);

    _device = QCanBus::instance()->createDevice(QStringLiteral("virtualcan"), QStringLiteral("can0"));
    _device->connectDevice();
    connect(_device, &QCanBusDevice::framesReceived, this, &CommController::canBusFrameReceived);
}

bool CommController::sendMsg(const QString &msg)
{
    switch(commType())
    {
        case 1: // Dbus
            return _dbusModule->sendFrame(DBUS_DASHBOARD, msg);

        case 2: // Serial
            return false;

        case 3: // CANBus
        {
            QCanBusFrame frame = QCanBusFrame(1, QByteArray(msg.toUtf8()).toHex());
            frame.setExtendedFrameFormat(false);
            frame.setFlexibleDataRateFormat(false);
            return _device->writeFrame(frame);
        }

        default:
            qDebug() << "Invalid communication type!";
    }

    return false;
}

bool CommController::sendFixedMsg(int msgType)
{
    qDebug () << commType();
    switch(msgType)
    {
        case 1: // Map Zoom In
        {
            switch(commType())
            {
                case 1: // Dbus
                    return _dbusModule->sendFrame(DBUS_DASHBOARD, "[M100000]");

                case 2: // Serial
                    return false;

                case 3: // CANBus
                {
                    QCanBusFrame frame = QCanBusFrame(1, QByteArray("[M100000]").toHex());
                    frame.setExtendedFrameFormat(false);
                    frame.setFlexibleDataRateFormat(false);
                    return _device->writeFrame(frame);
                }


                default:
                    qDebug() << "Invalid communication type.";
            }
        }

        case 2: // Map Zoom Out
        {
            switch(commType())
            {
                case 1: // Dbus
                    return _dbusModule->sendFrame(DBUS_DASHBOARD, "[M200000]");

                case 2: // Serial
                    return false;

                case 3: // CANBus
                {
                    QCanBusFrame frame = QCanBusFrame(1, QByteArray("[M200000]").toHex());
                    frame.setExtendedFrameFormat(false);
                    frame.setFlexibleDataRateFormat(false);
                    return _device->writeFrame(frame);
                }


                default:
                    qDebug() << "Invalid communication type.";
            }
        }
        case 3: // Gauge Layout Open
        {
            switch(commType())
            {
                case 1: // Dbus
                    return _dbusModule->sendFrame(DBUS_DASHBOARD, "[M300000]");

                case 2: // Serial
                    return false;

                case 3: // CANBus
                {
                    QCanBusFrame frame = QCanBusFrame(1, QByteArray("[M300000]").toHex());
                    frame.setExtendedFrameFormat(false);
                    frame.setFlexibleDataRateFormat(false);
                    return _device->writeFrame(frame);
                }


                default:
                    qDebug() << "Invalid communication type.";
            }
        }

        case 4: // Gauge Layout Enclosed
        {
            switch(commType())
            {
                case 1: // Dbus
                    return _dbusModule->sendFrame(DBUS_DASHBOARD, "[M400000]");

                case 2: // Serial
                    return false;

                case 3: // CANBus
                {
                    QCanBusFrame frame = QCanBusFrame(1, QByteArray("[M400000]").toHex());
                    frame.setExtendedFrameFormat(false);
                    frame.setFlexibleDataRateFormat(false);
                    return _device->writeFrame(frame);
                }


                default:
                    qDebug() << "Invalid communication type.";
            }
        }

        default:
            return false;
    }
}

void CommController::messageReceived(const QString &deviceId, const QString &msg)
{
    // TODO: Display received messages on UI.
    Q_UNUSED(deviceId);
    Q_UNUSED(msg);
}

void CommController::canBusFrameReceived()
{
    // TODO: Process received CANBus messages.
}

int CommController::commType() const
{
    return m_commType;
}

void CommController::setCommType(int newCommType)
{
    if (m_commType == newCommType)
        return;
    m_commType = newCommType;
    emit commTypeChanged();
}
