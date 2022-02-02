import QtQuick 2.0

Item {
    Image {
        id: gradientEnclosedImg
        source: "qrc:/map-gradient-enclosed.png"
        opacity: 1
    }

    Image {
        id: gradientOpenImg
        source: "qrc:/map-gradient.png"
        opacity: 0
    }

    states: [
        State {
            name: "open"

            PropertyChanges {
                target: gradientEnclosedImg
                opacity: 0
            }

            PropertyChanges {
                target: gradientOpenImg
                opacity: 1
            }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation
            {
                properties: "opacity"
                duration: 800
            }
        }
    ]
}
