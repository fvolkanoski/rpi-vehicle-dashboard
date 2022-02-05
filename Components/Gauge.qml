import QtQuick 2.15

Item {
    id: root
    width: 256
    height: 256

    property int zoomOutX
    property int zoomOutY
    property int value
    property string valueInfo

    Image {
        source: "qrc:/Images/gauge-outline.png"
        id: container
        anchors.fill: parent

        Text {
            id: speedTxt
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: value
            color: "white"
            font.pixelSize: 72
            font.bold: true

            Behavior on font.pixelSize {

                NumberAnimation {
                    target: speedTxt
                    property: "font.pixelSize"
                    duration: 500
                }
            }
        }

        Text {
            id: speedInfo
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: speedTxt.bottom
            text: valueInfo
            color: "white"
            font.pixelSize: 20

            Behavior on font.pixelSize {

                NumberAnimation {
                    target: speedInfo
                    property: "font.pixelSize"
                    duration: 500
                }
            }
        }
    }
    states: [
        // This adds a second state to the container where the rectangle is farther to the right

        State {
            name: "open"

            PropertyChanges {
                target: root
                x: zoomOutX;
                y: zoomOutY;
                width: 128
                height: 128
            }

            PropertyChanges {
                target: speedTxt
                font.pixelSize: 30
            }

            PropertyChanges {
                target: speedInfo
                font.pixelSize: 10
            }
        }
    ]
    transitions: [
        // This adds a transition that defaults to applying to all state changes
        Transition {
            // This applies a default NumberAnimation to any changes a state change makes to x or y properties
            NumberAnimation
            {
                properties: "x,y,width,height"
                duration: 500
            }
        }
    ]
}
