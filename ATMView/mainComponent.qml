import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
    signal readByIdcard()

    anchors.fill: parent
    color: "#EEEEEE"
    Row {
        anchors.centerIn: parent
        spacing: 60
        SuperButton {
            id: idCardReader
            width: 300; height: 300
            imageWidth: 128; imageHight: 128
            color: "#00cb00"
            textFont: 24
            url: "Image/idCard.png"
            text: qsTr("身份证")
            onIdCardRead: {
                emit: readByIdcard();
            }
        }
        SuperButton {
            id: siCardReader
            width: 300; height: 300
            imageWidth: 128; imageHight: 128
            color: "#00cb00"
            textFont: 24
            url: "Image/securityCard.png"
            text: qsTr("社保卡")
        }
    }
}
