#pragma once

#include <QObject>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMessage>

class DbusHelper : public QObject
{
    Q_OBJECT

public:
    explicit DbusHelper(QObject *parent = nullptr);

signals:
    void frameReceived(const QString &deviceId, const QString &frame);

public slots:
    Q_SCRIPTABLE void receiveDirectFrame(const QDBusMessage &message);
    void receiveBroadcast(const QDBusMessage &msg);

private:
    bool parseDbusMsg(const QDBusMessage &msg);
};
