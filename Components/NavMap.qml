import QtQuick 2.15
import QtPositioning 5.15
import QtLocation 5.15

Item {
    property string mapStyle: "mapbox://styles/filipv/ckyw4lmi0005b14pkmh140mi5"
    property real mapZoom: 17.5

    Map {
        id: mapa
        x: 0
        width: 1024
        y: 0
        height: 600
        plugin: mapboxglPlugin
        center: QtPositioning.coordinate(40.71971, -73.99428)
        zoomLevel: mapZoom
        tilt: 90
        minimumZoomLevel: 5
        maximumZoomLevel: 50
        bearing: 16.8
        copyrightsVisible: false

        MapQuickItem {
            id: navigationArrowItem
            z: 2
            coordinate: QtPositioning.coordinate(40.71971, -73.99428)
            anchorPoint.x: navigationArrowImage.width / 2
            anchorPoint.y: navigationArrowImage.height / 2
            sourceItem: Image {
                id: navigationArrowImage
                source: "qrc:/Images/arrow.png"
                width: 32
                height: 32
                mipmap: true
            }
        }
    }

    Plugin {
       id: mapboxglPlugin
       name: "mapboxgl"

       PluginParameter {
           name: "mapbox.access_token"
           value: "pk.eyJ1IjoiZmlsaXB2IiwiYSI6ImNreXQzNjc2aTE5bmoyeXB0ZTA1anFjN3kifQ.GtxI-IJkyjJTdzOchmy6Yg"
       }
       PluginParameter {
           name: "mapboxgl.mapping.additional_style_urls"
           value: mapStyle
       }
    }
}
