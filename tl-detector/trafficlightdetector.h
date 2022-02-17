#pragma once

#include <QObject>

#include <vector>

#include <opencv2/core/core.hpp>

class TrafficLightDetector : public QObject
{
    Q_OBJECT

public:
    enum TrafficLight {
        TL_RED,
        TL_GREEN,
        TL_INVALID
    };

    explicit TrafficLightDetector(QObject *parent = nullptr);

signals:
    void detected(const TrafficLightDetector::TrafficLight &trafficLight);

public slots:
    void startDetection(QString &camera);

private:
    void processFrame(cv::Mat &frame);

    std::vector <int> lower_red1;
    std::vector <int> upper_red1;
    std::vector <int> lower_red2;
    std::vector <int> upper_red2;
    std::vector <int> lower_green;
    std::vector <int> upper_green;
    std::vector <int> lower_yellow;
    std::vector <int> upper_yellow;
};

Q_DECLARE_METATYPE(TrafficLightDetector::TrafficLight);
