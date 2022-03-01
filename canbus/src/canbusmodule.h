#pragma once

#include <QObject>
#include <QCanBusDevice>

/*! \brief CanBusModule class.
 *  The CanBusModule class is responsible for the instance of the CanBus connection,
 *  also it is responsible for receiving and sending CanBus frames.
*/
class CanBusModule : public QObject
{
    Q_OBJECT

public:
    /*! \brief Default constructor.
       *  @param[in] *parent The parent QObject.
       *  @return none
      */
    explicit CanBusModule(QObject *parent = nullptr);

    /*! \brief Default destructor.
       *  @param[in] none
       *  @return none
      */
    ~CanBusModule();

signals:
    /*! \brief This signal is emitted to trigger the canFrameReceived slot in
     *         the CanBusManager class.
     *  @param[in] frame The CanBus frame which was received.
     *  @return none
    */
    void frameReceived(QCanBusFrame frame);

private slots:
    /*! \brief This slot is triggered by the framesReceived signal from the
     *         QCanBus class.
     *  @param[in] none
     *  @return none
    */
    void canBusFrameReceived();

private:
    /*! \brief The QCanBusDevice pointer, it holds the instance of the QCanBusDevice.
      */
    QCanBusDevice *_device;
};
