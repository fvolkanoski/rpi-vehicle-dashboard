#include <QCoreApplication>

#include "src/canbusmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CanBusManager canBusManager;
    return a.exec();
}
