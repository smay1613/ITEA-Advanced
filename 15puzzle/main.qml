import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    id: root
    visible: true
    width: 640
    height: 480
    color: "#383838"
    title: qsTr("15 puzzle")

    GameBoard {
        id: _gameBoard
        anchors.topMargin: 0
        anchors.rightMargin: width * 0.15
        anchors.fill: parent
        anchors.margins: 5
        boundsBehavior: Flickable.StopAtBounds
    }
}


