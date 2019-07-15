import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    property alias nameText: userName.text
    property alias certNoText: idCard.text
    property alias exitBtnVisible: logout.visible

      Label {
          id: userIcon
          width: 64
          height: 64
          anchors.verticalCenter: parent.verticalCenter
          anchors.left: parent.left
          anchors.leftMargin: 20
          Image {
              anchors.fill: parent
              source: "Image/user_icon.png"
          }
      }

      Label {
          id: userName
          anchors.left: userIcon.right
          anchors.verticalCenter: parent.verticalCenter
          anchors.leftMargin: 30
          text: qsTr("****")
          font.family: qsTr("微软雅黑")
          font.pixelSize: 16
          color: "#000000"
      }

      Label {
          id: idCard
          anchors.left: userName.right
          anchors.verticalCenter: parent.verticalCenter
          anchors.leftMargin: 30
          text: "******************"
          font.family: "微软雅黑"
          font.pixelSize: 16
          color: "#000000"
      }

      Button {
          id: logout
          width: 100
          height: 36
          anchors.verticalCenter: parent.verticalCenter
          anchors.right: parent.right
          anchors.rightMargin: 20
          Text {
              text: qsTr("退出")
              font.family: "微软雅黑"
              font.pixelSize: 16
              color: "#FFFFFF"
              anchors.centerIn: parent
          }
          style: ButtonStyle {
              background: Rectangle {
                  anchors.fill: parent
                  color: "#FE5400"
                  radius: 4
              }
          }
      }
}
