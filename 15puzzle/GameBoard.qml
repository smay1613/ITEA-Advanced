import QtQuick 2.2
import QtQuick.Dialogs 1.1
import Game 1.0

GridView {
    id: root
    interactive: false
    cellHeight: height / model.dimension
    cellWidth: width / model.dimension

    model: GameBoardModel {

    }

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        Tile {
            id: _internalTile
            visible: display != 16
            displayText: display
            anchors.fill: _backgroundDelegate
            anchors.margins: 1
        }
        MouseArea {
            anchors.fill: _internalTile
            onClicked: {
                root.model.move(index);
            }
        }
    }

    GameBoardModel {
        id: _gameController
    }

    move: Transition {
            NumberAnimation {
                properties: "x, y"
                duration: 1000
            }
        }

    MessageDialog {
        id: ms_box
        text: "Зіграти ще раз?"
        standardButtons: MessageDialog.Yes | MessageDialog.No
        //visible: true
        //Component.onCompleted: visible = true
        onNo: Qt.quit()
        onYes: {
            root.model.ms_box(0)
        }
    }

}


