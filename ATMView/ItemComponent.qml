import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    anchors.fill: parent
    color: "#EEEEEE"

    property alias faceText: faceLabel.text
    property alias faceTextColor: faceLabel.color
    property alias faceBtnColor: faceIdentify.color
    property bool faceBtnDisable: faceIdentify.disable

    property alias veinText: veinLabel.text
    property alias veinTextColor: veinLabel.color
    property alias veinBtnColor: veinIdentify.color
    property bool veinBtnDisable: veinIdentify.disable

    property alias fingerText: fingetLabel.text
    property alias fingerTextColor: fingetLabel.color
    property alias fingerBtnColor: fingerIdentify.color
    property bool fingerDisable: fingerIdentify.disable

    Column {
        anchors.centerIn: parent
        spacing: 60

        Row {
            spacing: 60

            Column {
                spacing: 6

                SuperButton {
                    id: faceIdentify
                    width: 120; height: 140
                    imageWidth: 64; imageHight: 64
                    textFont: 14
                    url: "Image/face.png"
                    text: qsTr("人脸认证")
                }

                Label {
                    id: faceLabel
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Column {
                spacing: 6

                SuperButton {
                    id: veinIdentify
                    width: 120; height: 140
                    imageWidth: 64; imageHight: 64
                    textFont: 14
                    url: "Image/vein.png"
                    text: qsTr("指静脉认证")
                }

                Label {
                    id:veinLabel
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Column {
                spacing: 6

                SuperButton {
                    id: fingerIdentify
                    width: 120; height: 140
                    imageWidth: 64; imageHight: 64
                    textFont: 14
                    url: "Image/finger.png"
                    text: qsTr("指纹认证")
                }

                Label {
                    id: fingetLabel
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Rectangle {
            width: 500; height: 35
            color: "#ffffff"
            radius: 15
            Label {
                text: qsTr("请选择需要认证的类型")
                font.family: "微软雅黑"
                font.pixelSize: 16
                color: "gray"
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
