import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: titleRect
    property alias clockVisible: iconLabel.visible
    property alias countVisible: countLabel.visible
    property alias clockNumber: countLabel.text

    Button {
        id: returnBtn
        visible: false
        width: 44
        height: 44
        anchors.left: parent.left
        anchors.leftMargin: 12
        anchors.verticalCenter: parent.verticalCenter
        Image {
            width: 44
            height: 44
            source: "Image/return.png"
        }
        style: ButtonStyle {
            background: Rectangle {
                anchors.fill: parent
                opacity: 0
            }
        }
    }

    Label {
        id: titleLabel
        color: "#FFFFFF"
        font.family: "微软雅黑"
        font.pixelSize: 30
        anchors.left: returnBtn.right
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("甘肃省生物识别身份认证自助服务终端")
        anchors.centerIn: parent
    }

    Label {
        id: iconLabel
        width: 32
        height: 32
        anchors.right: countLabel.left
        anchors.rightMargin: 6
        anchors.verticalCenter: parent.verticalCenter
        BorderImage {
            id: name
            source: "Image/clock.png"
            width: 32; height: 32
        }
    }

    Label {
        id: countLabel
        anchors.rightMargin: 12
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        color: "#FFFFFF"
        font.family: "微软雅黑"
        font.pixelSize: 20
    }
}
