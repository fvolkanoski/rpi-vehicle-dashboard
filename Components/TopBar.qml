import QtQuick 2.0

Item {
    id: root

    Image {
        source: "qrc:/Images/top-bar.png"
    }

    DashSymbol {
        x: 40
        y: 5
        imgSrc: "qrc:/Images/DashboardSymbols/turn-left.png"
        isBlinking: true
    }

    DashSymbol {
        x: 690
        y: 5
        imgSrc: "qrc:/Images/DashboardSymbols/turn-right.png"
        isBlinking: true
    }
}
