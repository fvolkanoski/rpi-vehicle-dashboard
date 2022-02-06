#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>

#include "serialmodule.h"

class SerialManager : public QObject
{
    Q_OBJECT

public:
    explicit SerialManager(QObject *parent = nullptr);

    ~SerialManager();

private:
    SerialModule *_serialModule;
};

#endif
