import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2

Window {
    id: mainWindow
    visible: true
    visibility: Window.FullScreen
    flags: Qt.Window | Qt.FramelessWindowHint |  Qt.WindowStaysOnTopHint
    property int clockCounter: 60

    Rectangle {
        id: mainRect
        anchors.fill: parent
        state: "freeState"
        states: [
            State {
                name: "freeState"
                PropertyChanges {
                    target: title
                    clockVisible: true
                    countVisible: true
                }
                PropertyChanges {
                    target: control
                    exitBtnVisible: true
                }
            },
            State {
                name: "workState"
                PropertyChanges {
                    target: title
                    clockVisible: false
                    countVisible: false
                }
                PropertyChanges {
                    target: control
                    exitBtnVisible: false
                }
            }
        ]

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
                        getBusinessAgent.ReadIdCard()
                        mask.visible = true
                        loadingDlg.text = "正在加载，请稍候..."
                        loadingDlg.open()
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

            LoadingComponent {
                id: loadingDlg
                width: 500
                height: 320
                visible:  false
                anchors.centerIn: parent
            }
        }
    }

    MessageDialog {
        id: messageDialog
        onAccepted: close()
        visible: false
    }

    //Init
    Component.onCompleted: getHttpAgent.RequestOnOperatorLogin()

    Connections {
        target: getBusinessAgent
        onSigOnReadCardFailed: {
            mask.visible = false
            loadingDlg.close()

            messageDialog.title = "警告"
            messageDialog.text = errMsg
            messageDialog.icon = StandardIcon.Warning
            messageDialog.open()
        }
        onSigOnReadCardSuccess: {
            mask.visible = false
            loadingDlg.close()

            getHttpAgent.RespondOnGetBaseInfo()
        }
    }

    Connections {
        target: getHttpAgent
        onRespondSigOnNetworkErr: {
            messageDialog.title = nCode
            messageDialog.text = sMsg
            messageDialog.icon = StandardIcon.Warning
            messageDialog.open()
        }
        onRespondSigOnHeartbeat: {
            if (online) {
                status.labelImage = "Image/online.png"
            }
            else {
                status.labelImage = "Image/offline.png"
            }
        }

        onRespondSigOnGetBaseInfo: {
            updateComponentUI()
            getHttpAgent.RespondOnGetIdCardPic()
            stack.push(itemView)
        }
    }

    Timer {
        id:"heartBeat"
        interval: 5000
        running: true
        repeat: true
        triggeredOnStart: true
        onTriggered: getHttpAgent.RequestOnHeartbeat()
    }

    Timer {
        id: "counter"
        interval: 1000
        running: false
        repeat: true
        triggeredOnStart: true
        onTriggered: {
              title.clockNumber = mainWindow.clockCounter--
              if (mainWindow.clockCounter == -1) {
                      mainRect.state = "freeState"
              }
        }
    }

    function updateComponentUI() {
        var modelStatus = getModelData.getModelStatus()
        itemPage.faceBtnDisable = !modelStatus.faceBtnColor
        itemPage.veinBtnDisable = !modelStatus.fveinModelStatus
        itemPage.fingerDisable = !modelStatus.fprintModelStatus

        if (modelStatus.faceModelStatus) {
            itemPage.faceBtnColor = "#0090D8"
            itemPage.faceText = "可认证"
            itemPage.faceTextColor = "#0090D8"
        }
        else {
            itemPage.faceBtnColor = "gray"
            itemPage.faceText = "未建模"
            itemPage.faceTextColor = "gray"
        }

        if (modelStatus.fveinModelStatus) {
            itemPage.veinBtnColor = "#0090D8"
            itemPage.veinText = "可认证"
            itemPage.veinTextColor = "#0090D8"
        }
        else {
            itemPage.veinBtnColor = "gray"
            itemPage.veinText = "未建模"
            itemPage.veinTextColor = "gray"
        }

        if (modelStatus.fprintModelStatus) {
            itemPage.fingerBtnColor = "#0090D8"
            itemPage.fingerText = "可认证"
            itemPage.fingerTextColor = "#0090D8"
        }
        else {
            itemPage.fingerBtnColor = "gray"
            itemPage.fingerText = "未建模"
            itemPage.fingerTextColor = "gray"
        }
    }
}
