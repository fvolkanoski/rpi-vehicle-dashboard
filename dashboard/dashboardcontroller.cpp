#include "dashboardcontroller.h"

DashboardController::DashboardController(QObject *parent)
    : QObject{parent}
{

}

DashboardController::~DashboardController()
{
    delete _engine;
}

void DashboardController::initializeQmlContext(QQmlEngine *engine)
{
    if (!engine)
        return;

    _engine = engine;
}
