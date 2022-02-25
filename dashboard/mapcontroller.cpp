#include "mapcontroller.h"
#include "../share/globals.h"

MapController::MapController(QObject *parent)
    : QObject{parent}
{
    m_zoomLevel = 17.5;
    m_mapState = MAP_STATE_ENCLOSED;
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
