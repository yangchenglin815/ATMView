import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Window {
    id: mainWindow
    visible: true
    visibility: Window.FullScreen
    flags: Qt.Window | Qt.FramelessWindowHint |  Qt.WindowStaysOnTopHint

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
        onShowAuthorizateWindow: {
            mask.visible = true;
            authorizateDlg.open();
        }
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
            MainComponent {
                id: mainPage
                onReadByIdcard: {
                    console.log("kkkkk")
                    stack.push(itemView)
                }
            }
        }

        Component {
            id: itemView
            ItemComponent {
                id: itemPage
            }
        }
    }

    Rectangle {
        id: mask
        color: Qt.rgba(0, 0, 0, 0.7)
        width: parent.width
        height: parent.height
        anchors.fill: parent
        visible: false

        AuthorizateComponent {
            id: authorizateDlg
            width: 400
            height: 300
            visible:  false
            anchors.centerIn: parent
        }
    }

    //Init
    Component.onCompleted: {
        var operatorInfo = getModelData.getOperatorInfo();

        var interfaceHeadInfo = getModelData.getInterfaceHead();

        getHttpAgent.RequestOnOperatorLogin(operatorInfo, interfaceHeadInfo)
    }

    Connections {
        target: getHttpAgent
        onRespondOnOperatorLogin: {
            console.log(nCode)
            console.log(sMsg)
            console.log(sessionId)
        }
    }
}
