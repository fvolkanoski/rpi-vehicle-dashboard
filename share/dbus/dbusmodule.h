#pragma once

#include <QObject>
#include <QMap>

class DbusHelper;
class QDBusInterface;

class DbusModule : public QObject
{
    Q_OBJECT

public:
    explicit DbusModule(const QString &deviceId, QObject *parent = nullptr);
    ~DbusModule();

    QString name() const { return m_moduleName; }
    bool isConnected() const { return m_isConnected; }
    bool connect();
    bool disconnect();
    bool sendFrame(const QString &destAddress, const QString &frame);

signals:
    void frameReceived(const QString &deviceId, const QString &frame);

private slots:
    void frameReceivedSlot(const QString &deviceId, const QString &frame);

private:
    const QString m_serviceName = "org.freedesktop.DBus";
    QString m_iFaceBroadcastName;
    const QString m_broadcastMethodName = "Broadcast";
    const QString m_receiveFrameMethodName = "receiveDirectFrame";

    QString m_dbusService;
    QString m_dbusPath;
    QString m_moduleName;

    bool m_isConnected = false;
    DbusHelper *m_helper { nullptr };
    QMap<QString, QDBusInterface*> m_iFaces;
};
