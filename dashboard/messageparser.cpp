#include "messageparser.h"

#include <QDebug>

MessageParser::MessageParser(QObject *parent)
    : QObject{parent}
{

}

char MessageParser::parseMessageID(const QString &msg)
{
    if(msg.size() < 7)
    {
        return ' ';
    }

    if(msg[0] != '[' || msg.back() != ']')
    {
        return ' ';
    }

    return msg[1].toLatin1();
}

int MessageParser::parseCommandID(const QString &msg)
{
    if(msg.size() < 7)
    {
        return ' ';
    }

    if(msg[0] != '[' || msg.back() != ']')
    {
        return ' ';
    }

    return msg[2].digitValue();
}

DataMessageParser::DataMessageParser(QObject *parent)
    : QObject{parent}
{

}

int DataMessageParser::parseSpeed(const QString &msg)
{
    if(msg.size() < 9)
    {
        return 0;
    }

    if(msg[0] != '[' || msg.back() != ']')
    {
        return 0;
    }

    return msg.midRef(3, 3).toUInt(NULL, 16);
}

int DataMessageParser::parseRPM(const QString &msg)
{
    if(msg.size() < 9)
    {
        return 0;
    }
    if(msg[0] != '[' || msg.back() != ']')
    {
        return 0;
    }

    return msg.midRef(6, 4).toUInt(NULL, 16);
}
