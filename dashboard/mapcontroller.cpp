#include "mapcontroller.h"

MapController::MapController(QObject *parent)
    : QObject{parent}
{
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

const QString &MapController::mapState() const
{
    return m_mapState;
}

void MapController::setMapState(const QString &newMapState)
{
    if (m_mapState == newMapState)
        return;
    m_mapState = newMapState;
    emit mapStateChanged();
}
