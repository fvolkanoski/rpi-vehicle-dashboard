#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QObject>

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
    float m_zoomLevel;
    QString m_mapState;
};

#endif // MAPCONTROLLER_H
