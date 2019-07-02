import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
     Button {
         id: returnBtn
         width: 44
         height: 44
         anchors.left: parent.left
         anchors.leftMargin: 12
         anchors.verticalCenter: parent.verticalCenter
         iconSource: "Image/return.png"
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
         anchors.top: parent
         anchors.bottom: parent
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
         text: "60"
         color: "#FFFFFF"
         font.family: "微软雅黑"
         font.pixelSize: 20
     }
}
