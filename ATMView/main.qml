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

    Rectangle {
        id: mainRect
        anchors.fill: parent
        state: "freeState"
        states: [
            State {
                name: "freeState"
                PropertyChanges {
                    target: title

                }
            },
            State {
                name: "workState"
                PropertyChanges {
                    target: title

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
    }

    MessageDialog {
        id: messageDialog
        onAccepted: {
            console.log("And of course you could only agree.")
            Qt.quit()
        }
        visible: false
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
            if (nCode === 0) {
                getLogObj.logInfo("OperatorLogin 请求成功")
                    var interfaceHeadInfo = getModelData.getInterfaceHead();
                    interfaceHeadInfo.sessionId = sessionId
                    getModelData. setInterfaceHead(interfaceHeadInfo)
            }
            else {
                 getLogObj.logInfo("OperatorLogin 请求出现异常 -- 错误码: " + nCode + "，错误信息：" +sMsg)
                messageDialog.title = "警告"
                messageDialog.text = "系统初始化异常--错误码:" + nCode + ", 错误信息:" + sMsg
                messageDialog.icon = StandardIcon.Warning
                messageDialog.open()
            }
        }
        onRespondOnHeartbeat: {
            var heartbeatData = getModelData.getHeartbeatInfo()
              if (nCode === 0) {
                      getLogObj.logInfo("Heartbeat 请求成功")
                      heartbeatData.offlineCount = 0;
              }
              else {
                  getLogObj.logInfo("Heartbeat 请求出现异常 -- 错误码: " + nCode + "，错误信息：" +sMsg)
                  heartbeatData.offlineCount++
              }
               getModelData.setHeartbeatData(heartbeatData)

              if (heartbeatData.offlineCount === 5)
              {
                   getLogObj.logInfo("设备已离线")
              }
        }

    }

    Timer {
        id:"heartBeat"
        interval: 5000
        running: true
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            var heartbeatData = getModelData.getHeartbeatInfo()
            var interfaceHeadInfo = getModelData.getInterfaceHead();
            getHttpAgent.RequestOnHeartbeat(heartbeatData, interfaceHeadInfo)
        }
    }
}
