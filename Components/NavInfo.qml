import QtQuick 2.15

Item {
    Image {
        id: dirArrow
        anchors.centerIn: parent
        width: 70
        height: 70
        source: "qrc:/left-arrow.png"
        mipmap: true
    }

    Text {
        id: navInfo
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: dirArrow.bottom
        anchors.topMargin: 15
        text: "Delancey Street"
        color: "white"
        font.pixelSize: 15
    }

    Text {
        id: navInfoKM
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: navInfo.bottom
        anchors.topMargin: 2
        text: "500m"
        color: "white"
        font.pixelSize: 12
        font.bold: true
    }
}
