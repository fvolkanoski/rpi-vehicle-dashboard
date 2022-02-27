#include "datacontroller.h"

DataController::DataController(QObject *parent)
    : QObject{parent}
{

}

int DataController::speedKmph() const
{
    return m_speedKmph;
}

void DataController::setSpeedKmph(int newSpeedKmph)
{
    if (m_speedKmph == newSpeedKmph)
        return;
    m_speedKmph = newSpeedKmph;
    emit speedKmphChanged();
}

int DataController::RPM() const
{
    return m_RPM;
}

void DataController::setRPM(int newRPM)
{
    if (m_RPM == newRPM)
        return;
    m_RPM = newRPM;
    emit RPMChanged();
}
