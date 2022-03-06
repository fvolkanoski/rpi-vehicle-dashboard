#pragma once

#include <QObject>
#include <QMap>

class DbusHelper;
class QDBusInterface;

/*! \brief DbusModule class
 *  The dbus module class, initiates dbus connections, sends and receives messages
*/
class DbusModule : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor.
     *  @param[in] parent The parent QObject.
     *  @param[in] deviceId The deviceId for the dbus connection.
     *  @return none
    */
    explicit DbusModule(const QString &deviceId, QObject *parent = nullptr);

    /*! \brief Default destructor, disconnects the dbus connection and deletes pointers.
     *  @return none
    */
    ~DbusModule();

    /*! \brief Getter for m_moduleName.
     *  @return QString Returns m_moduleName.
    */
    QString name() const { return m_moduleName; }

    /*! \brief Getter for m_isConnected.
     *  @return bool Returns m_isConnected.
    */
    bool isConnected() const { return m_isConnected; }

    /*! \brief Connects the dbus module.
     *  @return bool Returns true if connection is successfull.
    */
    bool connect();

    /*! \brief Disconnects the dbus module.
     *  @return bool Returns true if disconnection is successfull.
    */
    bool disconnect();

    /*! \brief Sends a dbus message.
     *  @param[in] destAddress Where to send the dbus message to.
     *  @param[in] frame The message that will be sent.
     *  @return bool Returns true if message is sent successfully.
    */
    bool sendFrame(const QString &destAddress, const QString &frame);

signals:
    /*! \brief This signal is emitted when a new message is received through dbus.
     *  @param[in] deviceId The device id which sent the message.
     *  @param[in] frame The message.
     *  @return none
    */
    void frameReceived(const QString &deviceId, const QString &frame);

private slots:
    /*! \brief This slot is triggered when a new frame is received.
     *  @param[in] deviceId The device id which sent the message.
     *  @param[in] frame The message.
     *  @return none
    */
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
