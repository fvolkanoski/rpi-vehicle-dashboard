import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

Window {
    id: window
    width: 510
    height: 400
    visible: true
    title: qsTr("Dbus & Serial Test")

    RowLayout {
        x: 5
        y: 5
        anchors.horizontalCenter: parent.horizontalCenter

        RadioButton {
            checked: true
            text: qsTr("Dbus")

            onCheckedChanged: {
                if(checked)
                    commController.commType = 1;
            }
        }
        RadioButton {
            text: qsTr("Serial")

            onCheckedChanged: {
                if(checked)
                    commController.commType = 2;
            }
        }
        RadioButton {
            text: qsTr("CANBus")

            onCheckedChanged: {
                if(checked)
                    commController.commType = 3;
            }
        }
    }

    Rectangle {
        x: 5
        y: 55
        height: 30
        width: parent.width - 10

        border {
            width: 1
            color: "black"
        }

        TextInput {
            id: msgInput
            anchors.fill: parent
            padding: 5
            text: ""

            font {
                pointSize: 15
            }
        }
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
        text: "Send"

        onClicked: {
            if(commController.sendMsg(msgInput.text))
                console.log("Message sent to dbus successfully.");
        }
    }

    RowLayout {
        x: 20
        y: 200
        width: parent.width - 10
        ColumnLayout {
            Button {
                text: "Map Zoom In"

                onClicked: {
                    if(commController.sendFixedMsg(1))
                        console.log("Message sent successfully.");
                }
            }
            Button {
                text: "Map Zoom Out"

                onClicked: {
                    if(commController.sendFixedMsg(2))
                        console.log("Message sent successfully.");
                }
            }
            Button {
                text: "Gauge Layout Open"

                onClicked: {
                    if(commController.sendFixedMsg(3))
                        console.log("Message sent successfully.");
                }
            }
            Button {
                text: "Gauge Layout Enclosed"

                onClicked: {
                    if(commController.sendFixedMsg(4))
                        console.log("Message sent successfully.");
                }
            }
        }
    }
}
