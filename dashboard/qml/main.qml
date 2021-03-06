import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.5

import "Components"

Window {
    id: window
    width: 1024
    height: 600
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "#2d3436"

        NavMap {
            id: navMap
            x: 0
            y: 0
            width: 1024
            height: 600
            mapStyle: "mapbox://styles/filipv/ckzadjsxh000l15rsouno6l39"
            mapZoom: mapController.zoomLevel
        }

        Gauge {
            id: gaugeKMH
            x: 20
            y: 172
            z: 1
            value: dataController.speedKmph
            valueInfo: "KM/H"
            zoomOutX: 10
            zoomOutY: 462
            state: mapController.mapState
        }

        Gauge {
            id: gaugeRPM
            x: 748
            y: 172
            z: 1
            value: dataController.RPM
            valueInfo: "RPM"
            zoomOutX: 886
            zoomOutY: 462
            state: mapController.mapState
        }
    }
}
