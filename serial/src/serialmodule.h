#ifndef SERIALMODULE_H
#define SERIALMODULE_H

#include <QObject>

class SerialModule : public QObject
{
    Q_OBJECT

public:
    explicit SerialModule(QObject *parent = nullptr);

    ~SerialModule();
};

#endif
