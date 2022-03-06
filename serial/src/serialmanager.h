#pragma once

#include <QObject>

#include "serialmodule.h"
#include "../share/globals.h"
#include "../share/dbus/dbusmodule.h"
#include "../share/dbus/dbushelper.h"

/*! \brief SerialManager class
 *  Manages the serial module class.
*/
class SerialManager : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor. Initiates the dbus and serial modules.
     *  @param[in] *parent The parent QObject.
     *  @return none
    */
    explicit SerialManager(QObject *parent = nullptr);

    /*! \brief Default destrucotr, deletes pointers.
    */
    ~SerialManager();

private slots:
    /*! \brief This slot is triggered when there is new data from the serial port.
     *  @param[in] msg The message that is received.
     *  @return none
    */
    void dataReceived(QString msg);

private:
    /*! \brief The serial module pointer.
    */
    SerialModule *_serialModule;

    /*! \brief The dbus module pointer.
    */
    DbusModule *_dbusModule;
};
