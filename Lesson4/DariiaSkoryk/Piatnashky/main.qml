import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 640
    height: 640
    title: qsTr("15-puzzle")

    GameBoard {
        width: root.width - _background.border.width*2
        height: root.height - _background.border.width*2
        anchors.verticalCenter: _background.verticalCenter
        anchors.horizontalCenter: _background.horizontalCenter
    }

    Rectangle {
        id: _background
        color: "#202020"
        anchors.fill: parent
        z: -100
        border.width: root.width < root.height? root.width / 50 : root.height / 50
    }
}
