#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QObject>

#include "../share/globals.h"

class MapController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)
    Q_PROPERTY(QString mapState READ mapState WRITE setMapState NOTIFY mapStateChanged)

public:
    explicit MapController(QObject *parent = nullptr);

    float zoomLevel() const;
    void setZoomLevel(float newZoomLevel);

    const QString &mapState() const;
    void setMapState(const QString &newMapState);

signals:
    void zoomLevelChanged();
    void mapStateChanged();

private:
    float m_zoomLevel = 17.5;
    QString m_mapState = MAP_STATE_ENCLOSED;
};

#endif // MAPCONTROLLER_H
