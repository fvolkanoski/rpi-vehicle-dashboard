#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QObject>

class MapController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float zoomLevel READ zoomLevel WRITE setZoomLevel NOTIFY zoomLevelChanged)

public:
    explicit MapController(QObject *parent = nullptr);

    float zoomLevel() const;
    void setZoomLevel(float newZoomLevel);

signals:
    void zoomLevelChanged();

private:
    float m_zoomLevel;
};

#endif // MAPCONTROLLER_H
