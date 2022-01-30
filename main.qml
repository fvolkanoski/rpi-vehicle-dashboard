import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15
import QtPositioning 5.15
import QtLocation 5.15
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
        width: 50
        height: 50
        z: 3
        text: "Gauges"

        onClicked: {
            gaugeOne.state === '' ? gaugeOne.state = 'other' : gaugeOne.state = ''
            gaugeTwo.state === '' ? gaugeTwo.state = 'other' : gaugeTwo.state = ''
            gradientImg.state === '' ? gradientImg.state = 'other' : gradientImg.state = ''
            gradientEnclosedImg.state === '' ? gradientEnclosedImg.state = 'other' : gradientEnclosedImg.state = ''
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "#2d3436"

        Rectangle {
            x: 462
            y: 0
            z: 2
            width: 100
            height: 150
            color: "transparent"

            Image {
                id: dirArrow
                anchors.centerIn: parent
                width: 70
                height: 70
                source: "left-arrow.png"
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

        Map {
            id: mapa
            x: 0
            width: 1024
            y: 0
            height: 600
            plugin: mapboxglPlugin
            center: QtPositioning.coordinate(40.71971, -73.99428)
            zoomLevel: 17.5
            tilt: 90
            minimumZoomLevel: 5
            maximumZoomLevel: 50
            bearing: 16.8
            copyrightsVisible: false

            MapQuickItem {
                id: navigationArrowItem
                z: 2
                coordinate: QtPositioning.coordinate(40.71971, -73.99428)
                anchorPoint.x: navigationArrowImage.width / 2
                anchorPoint.y: navigationArrowImage.height / 2
                sourceItem: Image {
                    id: navigationArrowImage
                    source: "arrow.png"
                    width: 32
                    height: 32
                    mipmap: true
                }
            }
        }

        Image {
            id: gradientEnclosedImg
            x: 0
            y: 0
            z: 1
            source: "map-gradient-enclosed.png"
            opacity: 1

            states: [
                State {
                    name: "other"

                    PropertyChanges {
                        target: gradientEnclosedImg
                        opacity: 0
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

        Image {
            id: gradientImg
            x: 0
            y: 0
            z: 1
            source: "map-gradient.png"

            states: [
                State {
                    name: "other"

                    PropertyChanges {
                        target: gradientImg
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

        Gauge {
            id: gaugeOne
            x: 20
            y: 172
            z: 1
            value: 32
            valueInfo: "KM/H"
            zoomOutX: 10
            zoomOutY: 462
        }

        Gauge {
            id: gaugeTwo
            x: 748
            y: 172
            z: 1
            value: 800
            valueInfo: "RPM"
            zoomOutX: 886
            zoomOutY: 462
        }
    }

    Plugin {
       id: mapboxglPlugin
       name: "mapboxgl"

       PluginParameter {
           name: "mapbox.access_token"
           value: "pk.eyJ1IjoiZmlsaXB2IiwiYSI6ImNreXQzNjc2aTE5bmoyeXB0ZTA1anFjN3kifQ.GtxI-IJkyjJTdzOchmy6Yg"
       }
       PluginParameter {
           name: "mapboxgl.mapping.additional_style_urls"
           value: "mapbox://styles/filipv/ckyw4lmi0005b14pkmh140mi5"
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
