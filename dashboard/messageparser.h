#pragma once

#include <QObject>

class MessageParser : public QObject
{
    Q_OBJECT
public:
    explicit MessageParser(QObject *parent = nullptr);
    char parseMessageType(QString &msg);
};
