#pragma once

#include <QObject>

class MessageParser : public QObject
{
    Q_OBJECT

public:
    explicit MessageParser(QObject *parent = nullptr);
    char parseMessageID(const QString &msg);
    int parseCommandID(const QString &msg);
};

class DataMessageParser : public QObject
{
    Q_OBJECT

public:
    explicit DataMessageParser(QObject *parent = nullptr);
    static int parseSpeed(const QString &msg);
    static int parseRPM(const QString &msg);
};
