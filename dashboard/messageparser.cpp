#include "messageparser.h"

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
