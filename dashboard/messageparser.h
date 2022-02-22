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
