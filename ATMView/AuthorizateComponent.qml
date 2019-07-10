import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: root
    color: "#FFFFFF"
    radius: 4

    function open() {
        root.visible =  true;
    }

    function close() {
        root.visible = false;
    }

    Column {
        anchors.centerIn: parent
        spacing: 25
        Image {
            id: image
            width: 64
            height: 64
            source: "Image/user_icon.png"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: label
            width: 260; height: 36
            anchors.horizontalCenter: image.horizontalCenter
            color: "#EEEEEE"
            radius: 4
            border.color: "gray"
            border.width: 1

            Label {
                id: lab
                width: 80
                height: 36
                anchors.left: label.left
                Text {
                    text: qsTr("授权码")
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
            }

            Rectangle {
                id: line
                width: 1
                height: 36
                color: "gray"
                anchors.left: lab.right
            }

            TextEdit {
                id: inputEdit
                width: 180
                height: 36
                anchors.left: line.right
                anchors.right: label.right
                focus: true
                anchors.verticalCenter: label.verticalCenter
                TextField {
                    horizontalAlignment: TextInput.AlignHCenter
                    echoMode: TextInput.Password
                    maximumLength: 8
                    style: TextFieldStyle {
                        textColor: "black"
                        font {
                            family:  "微软雅黑"
                            pixelSize: 14
                        }

                        background: Rectangle {
                            anchors.fill: parent
                            anchors.topMargin: 1
                            anchors.bottomMargin: 1
                            anchors.rightMargin: 2
                            implicitWidth: 178
                            implicitHeight: 34
                            color: "#FFFFFF"
                        }
                    }
                }
            }
        }

        Rectangle {
            width: parent.width
            height: 6
            color: "transparent"
        }

        Row {
            spacing: 60
            Button {
                id: login
                width: 100
                height: 36
                Text {
                    text: qsTr("登录")
                    color: "#FFFFFF"
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
                style: ButtonStyle {
                    background: Rectangle {
                        color: "#00cb00"
                        radius: 4
                    }
                }
            }

            Button {
                id: back
                width: 100
                height: 36
                Text {
                    text: qsTr("返回")
                    color: "#FFFFFF"
                    font.family: "微软雅黑"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
                style: ButtonStyle {
                    background: Rectangle {
                        color: "#00cb00"
                        radius: 4
                    }
                }
            }
        }
    }
}
