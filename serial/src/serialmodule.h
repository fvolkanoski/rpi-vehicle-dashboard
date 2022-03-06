#pragma once

#include <QObject>
#include <QtSerialPort/QSerialPort>

/*! \brief SerialModule class
 *  Initiates and maintains the serial port connection.
*/
class SerialModule : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor. Initiates the serial port module.
     *  @param[in] *parent The parent QObject.
     *  @return none
    */
    explicit SerialModule(QObject *parent = nullptr);

    /*! \brief Default destrucotr, deletes pointers.
    */
    ~SerialModule();

    /*! \brief Opens the serial port connection.
     *  @param[in] none
     *  @return bool Returns true if opening is successfull.
    */
    bool openPort();

signals:
    /*! \brief This signal is emitted when there is new data from the serial port.
     *  @param[in] msg The message that is received.
     *  @return none
    */
    void dataReceived(QString msg);

private slots:
    /*! \brief This slot is triggered when there is new data to receive from the serial port.
     *  @param[in] none
     *  @return none
    */
    void receive();

    /*! \brief This slot is triggered when there is an error on the serial port.
     *  @param[in] err The serial port error.
     *  @return none
    */
    void serialError(QSerialPort::SerialPortError err);

private:
    /*! \brief The serial port pointer.
    */
    QSerialPort *_serialPort;
};
