#include "messageparser.h"

MessageParser::MessageParser(QObject *parent)
    : QObject{parent}
{

}

char MessageParser::parseMessageType(QString &msg)
{
    Q_UNUSED(msg);

    return ' ';
}
