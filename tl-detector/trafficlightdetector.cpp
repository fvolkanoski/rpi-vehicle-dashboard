#include <QtDebug>

#include "trafficlightdetector.h"

#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

TrafficLightDetector::TrafficLightDetector(QObject *parent)
    : QObject{parent},
      lower_red1(std::vector <int>({0,100,100})),
      upper_red1(std::vector <int>({10,255,255})),
      lower_red2(std::vector <int>({160,100,100})),
      upper_red2(std::vector <int>({180,255,255})),
      lower_green(std::vector <int>({40,50,50})),
      upper_green(std::vector <int>({90,255,255})),
      lower_yellow(std::vector <int>({15,150,150})),
      upper_yellow(std::vector <int>({35,255,255}))
{
    qRegisterMetaType<TrafficLightDetector::TrafficLight>("TrafficLightDetector::TrafficLight");
}

void TrafficLightDetector::startDetection(QString &camera)
{
    cv::Mat frame;
    cv::VideoCapture cap;

    cap.set(cv::CAP_PROP_FPS, 5);
    cap.open(camera.toStdString(), cv::CAP_ANY);

    if (!cap.isOpened()) {
        // TODO: Print to log camera cannot be opened
        // TODO: Retry maybe or restart process?
    }

    while(true)
    {
        cap.read(frame);

        if (frame.empty()) {
            // TODO: Maybe write to log that frame capture failed?
        }
        else {
            processFrame(frame);
        }
    }
}

void TrafficLightDetector::processFrame(cv::Mat &frame)
{
    cv::Mat cimg = frame;

    cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
    cv::Mat mask1; cv::inRange(frame, lower_red1, upper_red1, mask1);
    cv::Mat mask2; cv::inRange(frame, lower_red2, upper_red2, mask2);
    cv::Mat maskg; cv::inRange(frame, lower_green, upper_green, maskg);
    cv::Mat maskr; cv::add(mask1, mask2, maskr);

    std::vector<cv::Vec3f> r_circles,
                           g_circles;

    medianBlur(maskg, maskg, 15);

    cv::HoughCircles(maskr, r_circles, cv::HOUGH_GRADIENT, 1, 80, 90, 12, 0, 35);
    cv::HoughCircles(maskg, g_circles, cv::HOUGH_GRADIENT, 1, 50, 100, 15, 0, 35);

    for( size_t i = 0; i < r_circles.size(); i++ )
    {
        cv::Vec3i c = r_circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        int radius = c[2];

        circle(cimg, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);
        circle(cimg, center, radius, cv::Scalar(0,0,255), 3, cv::LINE_AA);

        qDebug() << "Detected red";
        emit detected(TrafficLightDetector::TrafficLight::TL_RED);
    }

    for( size_t i = 0; i < g_circles.size(); i++ )
    {
        cv::Vec3i c = g_circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        int radius = c[2];

        circle(cimg, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);
        circle(cimg, center, radius, cv::Scalar(0,255,0), 3, cv::LINE_AA);

        qDebug() << "Detected green";
        emit detected(TrafficLightDetector::TrafficLight::TL_GREEN);
    }

    // For testing
    // cv::namedWindow("My Image");
    // cv::imshow("My Image", cimg);
}
