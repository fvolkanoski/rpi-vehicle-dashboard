#pragma once

#include <QObject>

class DataController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speedKmph READ speedKmph WRITE setSpeedKmph NOTIFY speedKmphChanged)
    Q_PROPERTY(int RPM READ RPM WRITE setRPM NOTIFY RPMChanged)

public:
    explicit DataController(QObject *parent = nullptr);

    int speedKmph() const;
    void setSpeedKmph(int newSpeedKmph);
    int RPM() const;
    void setRPM(int newRPM);

signals:
    void speedKmphChanged();
    void RPMChanged();

private:
    int m_speedKmph = 0;
    int m_RPM = 0;
};
