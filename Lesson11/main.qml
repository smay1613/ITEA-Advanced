import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Pjatnashki")
    StatusBar {
        id: _statusbar
        anchors.top: parent.window
        anchors.margins: 5
        style: ApplicationWindow.style
        RowLayout {
            Label { text: "Status" }
            Timer {
                interval: 500; running: true; repeat: true
                onTriggered: time.text = Date().toString()
            }
            Text {
                id: time
                ColorAnimation {
                    from: "white"
                    to: "black"
                    duration: 20
                }
            }
        }
    }
    GameBoard {
        id: _gameBoard
        anchors.fill: parent
        anchors.margins: 5
    }
}
