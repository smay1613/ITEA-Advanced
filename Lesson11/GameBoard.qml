import QtQuick 2.0
import GameBoard_uri 1.0
import Game 1.0
GridView {
    id: root

    cellHeight: height / 4
    cellWidth: width / 4
    interactive: false
    model: GameBoard_qml {
    }

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight
        visible: root.model.hiddenElementValue !== display
        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 5

            internalText.text: display.toString()
        }
    }
    GameController_qml{
        id: _gameController
    }

}
