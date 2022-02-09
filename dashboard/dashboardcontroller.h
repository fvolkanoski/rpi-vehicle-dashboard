#pragma once

#include <QObject>
#include <QQmlEngine>

class DashboardController : public QObject
{
    Q_OBJECT
public:
    explicit DashboardController(QObject *parent = nullptr);
    ~DashboardController();

    void initializeQmlContext(QQmlEngine *engine);

private:
    QQmlEngine *_engine;
};
