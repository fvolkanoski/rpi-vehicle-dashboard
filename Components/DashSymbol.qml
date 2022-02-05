import QtQuick 2.0

Item {
    id: root

    property string imgSrc: ""
    property bool isBlinking: false

    Image {
        id: symbolImg
        source: imgSrc
    }

    Timer {
        id: blinkTimer
        running: isBlinking
        repeat: true
        interval: 500

        onTriggered: {
            symbolImg.visible = !symbolImg.visible
        }
    }
}
