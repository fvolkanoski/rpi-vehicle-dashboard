#pragma once

#include <QObject>

#include "canbusmodule.h"
#include "../../share/dbus/dbusmodule.h"
#include "../../share/dbus/dbushelper.h"

/*! \brief CanBusManager class.
 *  The CanBusManager class is responsible for managing the CanBus module and
 *  other classes the canbus process may need.
*/
class CanBusManager : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor.
       *  @param[in] *parent The parent QObject.
       *  @return none
      */
    explicit CanBusManager(QObject *parent = nullptr);

    /*! \brief Default destructor.
       *  @param[in] none
       *  @return none
      */
    ~CanBusManager();

private slots:
    /*! \brief This slot is triggered when a message is received through dbus.
     *  @param[in] deviceId The device id which sent the message.
     *  @param[in] msg The message.
     *  @return none
    */
    void messageReceived(const QString &deviceId, const QString &msg);

    /*! \brief This slot is triggered by the frameReceived signal from the
     *         CanBusModule class.
     *  @param[in] frame The CanBus frame which was received.
     *  @return none
    */
    void canFrameReceived(QCanBusFrame frame);

private:
    /*! \brief The dbus module pointer.
      */
    DbusModule *_dbusModule;

    /*! \brief The CanBus module pointer.
      */
    CanBusModule *_canBusModule;
};
