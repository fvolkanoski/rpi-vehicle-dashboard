#pragma once

#include <QObject>

#include "../../share/dbus/dbusmodule.h"
#include "../../share/dbus/dbushelper.h"

/*! \brief ComController class
 *  This is the class that is exposed to the QML, it is responsible for sending and receiving
 *  messages through dbus, serial and can.
*/
class CommController : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor.
       *  @param[in] *parent The parent QObject.
       *  @return none
      */
    explicit CommController(QObject *parent = nullptr);

    /*! \brief INVOKABLE sendMsgToDbus Sends a message to dbus.
     *  @param[in] msg The message that is gonna be sent.
     *  @return bool Returns true if the message was sent successfully.
    */
    Q_INVOKABLE bool sendMsgToDbus(const QString &msg);

private slots:
    /*! \brief This slot is triggered when a message is received through dbus.
     *  @param[in] deviceId The device id which sent the message.
     *  @param[in] msg The message.
     *  @return none
    */
    void messageReceived(const QString &deviceId, const QString &msg);

private:
    /*! \brief The dbus module pointer.
      */
    DbusModule *_dbusModule;
};
