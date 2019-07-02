import QtQuick 2.0
import QtQuick.Controls 1.1

Rectangle {
    property alias url: image.source
    property alias text: label.text

    color: "#00cb00"
    radius: 4

    Column{
       anchors.centerIn: parent
        spacing: 0
        Image {
            id: image
            width: 128; height: 128
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClipChanged: {

                }
            }
        }

        Label {
            id: label
            font.family: qsTr("微软雅黑")
            font.pixelSize: 24
            color: "#FFFFFF"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
