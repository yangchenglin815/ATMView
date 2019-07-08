import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    signal showAuthorizateWindow()

     Label {
         id: versionNo
         anchors.verticalCenter: parent.verticalCenter
         anchors.left: parent.left
         anchors.leftMargin: 12
         text: qsTr("v1.0.0")
         font.family: qsTr("微软雅黑")
         font.pixelSize: 16
         color: "#FFFFFF"
     }

     Button {
         id: settings
         anchors.right: parent.right
         anchors.rightMargin: 12
         anchors.verticalCenter: parent.verticalCenter
         width: 32
         height: 32
         iconSource: "Image/settings.png"
         style: ButtonStyle {
             background: Rectangle {
                 anchors.fill: parent
                 opacity: 0
             }
         }
         onClicked: showAuthorizateWindow()
     }
}
