#include <QCoreApplication>

#include "detectorcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DetectorController detectorController;
    detectorController.start("cam1");

    return a.exec();
}
