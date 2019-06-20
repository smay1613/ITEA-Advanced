import QtQuick 2.0
import GameBoard_uri 1.0

GridView {
    id: root

    cellHeight: height / 4
    cellWidth: width / 4

    model: GameBoard_qml {
    }

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight
        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 5

            internalText.text: display.toString()
        }
    }
}
