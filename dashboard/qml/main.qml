import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.5

import "Components"

Window {
    id: window
    width: 1024
    height: 600
    visible: true

    Button {
        x: 0
        y: 0
        width: 25
        height: 25
        z: 3
        text: "ST"

        onClicked: {
            gaugeKMH.state === 'enclosed' ? gaugeKMH.state = 'open' : gaugeKMH.state = 'enclosed'
            gaugeRPM.state === 'enclosed' ? gaugeRPM.state = 'open' : gaugeRPM.state = 'enclosed'
        }
    }

    Button {
        x: 25
        y: 0
        width: 25
        height: 25
        z: 3
        text: "-"

        onClicked: {
            navMap.mapZoom -= 0.5;
        }
    }

    Button {
        x: 50
        y: 0
        width: 25
        height: 25
        z: 3
        text: "+"

        onClicked: {
            navMap.mapZoom += 0.5;
        }
    }

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
        }

        Gauge {
            id: gaugeKMH
            x: 20
            y: 172
            z: 1
            value: 32
            valueInfo: "KM/H"
            zoomOutX: 10
            zoomOutY: 462
            state: "enclosed"
        }

        Gauge {
            id: gaugeRPM
            x: 748
            y: 172
            z: 1
            value: 800
            valueInfo: "RPM"
            zoomOutX: 886
            zoomOutY: 462
            state: "enclosed"
        }
    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
