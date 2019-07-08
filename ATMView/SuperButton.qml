import QtQuick 2.0
import QtQuick.Controls 1.1

Rectangle {
    property alias url: image.source
    property alias text: label.text
    property alias imageWidth: image.width
    property alias imageHight: image.height
    property alias textFont: label.font.pixelSize
    signal idCardRead()

    radius: 4

    Column{
       anchors.centerIn: parent
        spacing: 12

        Image {
            id: image
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: idCardRead()
            }
        }

        Label {
            id: label
            font.family: qsTr("微软雅黑")
            color: "#FFFFFF"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
