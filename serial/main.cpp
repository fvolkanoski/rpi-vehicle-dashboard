#include <QCoreApplication>

#include "src/serialmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SerialManager serialPortManager;

    return a.exec();
}
