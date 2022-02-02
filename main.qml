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

    // Test button to switch between states
    Button {
        x: 0
        y: 0
        width: 50
        height: 50
        z: 3
        text: "ST"

        onClicked: {
            gaugeKMH.state === 'enclosed' ? gaugeKMH.state = 'open' : gaugeKMH.state = 'enclosed'
            gaugeRPM.state === 'enclosed' ? gaugeRPM.state = 'open' : gaugeRPM.state = 'enclosed'
            mapGradient.state === 'enclosed' ? mapGradient.state = 'open' : mapGradient.state = 'enclosed'
        }
    }

    Button {
        x: 50
        y: 0
        width: 50
        height: 50
        z: 3
        text: "-"

        onClicked: {
            navMap.mapZoom -= 0.5;
        }
    }

    Button {
        x: 100
        y: 0
        width: 50
        height: 50
        z: 3
        text: "+"

        onClicked: {
            navMap.mapZoom += 0.5;
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "#2d3436"

        NavInfo {
            x: 462
            y: 0
            z: 2
            width: 100
            height: 150
        }

        NavMap {
            id: navMap
            x: 0
            y: 0
            width: 1024
            height: 600
            mapStyle: "mapbox://styles/filipv/ckyw4lmi0005b14pkmh140mi5"
        }

        MapGradient {
            id: mapGradient
            x: 0
            y: 0
            z: 1
            state: "enclosed"
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
