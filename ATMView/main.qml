import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Window {
    id: mainWindow
    visible: true
    visibility: Window.FullScreen
    flags: Qt.Window | Qt.FramelessWindowHint

    TitleRect {
        id: title
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 70
        color: "#0090D8"
    }

    ControlRect {
        id: control
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 70
        color: "#FFFFFF"
    }

    StatusRect {
        id: status
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 40
        color: "#0090D8"
    }

    StackView {
        id: stack
        initialItem: mainView
        anchors.top: control.bottom
        anchors.bottom: status.top
        anchors.left: parent.left
        anchors.right: parent.right

        Component {
            id: mainView
            Rectangle {
                anchors.fill: parent
                color: "#EEEEEE"
                Row {
                    anchors.centerIn: parent
                    spacing: 60
                    SuperButton {
                        id: idCardReader
                        width: 300
                        height: 300
                        url: "Image/idCard.png"
                        text: qsTr("身份证")
                    }
                    SuperButton {
                        id: siCardReader
                        width: 300
                        height: 300
                        url: "Image/securityCard.png"
                        text: qsTr("社保卡")
                    }
                }
            }
        }
    }
}
