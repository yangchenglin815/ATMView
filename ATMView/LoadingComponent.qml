import QtQuick 2.3
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: root
    color: "#FFFFFF"
    radius: 10

    property alias text: label.text

    function open() {
        root.visible =  true;
        busyIndicator.running = true
    }

    function close() {
        root.visible = false;
        busyIndicator.running = false
    }

    Rectangle {
        id: idicator
        width: 96
        height: 96
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        BusyIndicator {
            anchors.fill: parent
            id: busyIndicator
            implicitWidth: 96
            implicitHeight: 96
            style: BusyIndicatorStyle {
                indicator: Rectangle{
                    visible: control.running
                    Rectangle {
                        id: rect
                        width: parent.width
                        height: parent.height
                        color: Qt.rgba(0, 0, 0, 0)
                        radius: width / 2
                        border.width: width / 6
                        visible: false
                    }
                    ConicalGradient {
                        width: rect.width
                        height: rect.height
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "gray" }
                            GradientStop { position: 1.0; color: "white" }
                        }
                        source: rect

                        Rectangle {
                            anchors.top: parent.top
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: rect.border.width
                            height: width
                            radius: width / 2
                            color: "gray"
                        }

                        RotationAnimation on rotation {
                            from: 0
                            to: 360
                            duration: 800
                            loops: Animation.Infinite
                            running: control.running
                        }
                    }
                }
            }
        }
    }

    Label {
        id: label
        font.family: "微软雅黑"
        font.pixelSize: 28
        color: "gray"
        anchors.top: idicator.bottom
        anchors.topMargin: 50
        width: parent.width
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        clip: true
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
    }
}
