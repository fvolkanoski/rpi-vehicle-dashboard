#pragma once

#include <QObject>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMessage>

/*! \brief DbusHelper class
 *  Simplifies the dbusmodule by parsing the dbus messages that are received.
*/
class DbusHelper : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor.
       *  @param[in] *parent The parent QObject.
       *  @return none
      */
    explicit DbusHelper(QObject *parent = nullptr);

signals:
    /*! \brief This signal is emitted when a new message is received through dbus.
     *  @param[in] deviceId The device id which sent the message.
     *  @param[in] msg The message.
     *  @return none
    */
    void frameReceived(const QString &deviceId, const QString &frame);

public slots:
    /*! \brief This slot is triggered when the dbus module receives a new message.
     *  @param[in] message The message that is received.
     *  @return none
    */
    Q_SCRIPTABLE void receiveDirectFrame(const QDBusMessage &message);

    /*! \brief This slot is triggered when the dbus module receives a new broadcast message.
     *  @param[in] msg The message that is received.
     *  @return none
    */
    void receiveBroadcast(const QDBusMessage &msg);

private:
    /*! \brief Parses the received dbus message.
     *  @param[in] msg The message that is to be parsed.
     *  @return bool Returns true if message is parsed successfully.
    */
    bool parseDbusMsg(const QDBusMessage &msg);
};
