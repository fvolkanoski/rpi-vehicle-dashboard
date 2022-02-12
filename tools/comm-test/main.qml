import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15

Window {
    id: window
    width: 510
    height: 400
    visible: true
    title: qsTr("Dbus & Serial Test")

    Rectangle {
        x: 5
        y: 5
        height: 30
        width: 500

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
        x: 5
        y: 50
        text: "Send to Dbus"

        onClicked: {
            if(commController.sendMsgToDbus(msgInput.text))
                console.log("Message sent to dbus successfully.");
        }
    }

    Button {
        x: 405
        y: 50
        text: "Send to Serial"

        onClicked: {
            if(commController.sendMsgToSerial(msgInput.text))
                console.log("Message sent to dbus successfully.");
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
