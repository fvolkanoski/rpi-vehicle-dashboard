#include "mapcontroller.h"

MapController::MapController(QObject *parent)
    : QObject{parent}
{
    m_zoomLevel = 17.5;
}

float MapController::zoomLevel() const
{
    return m_zoomLevel;
}

void MapController::setZoomLevel(float newZoomLevel)
{
    if (qFuzzyCompare(m_zoomLevel, newZoomLevel))
        return;

    m_zoomLevel = newZoomLevel;
    emit zoomLevelChanged();
}
