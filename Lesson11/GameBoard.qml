import QtQuick 2.0

GridView {
    id: root

    cellHeight: height / 4
    cellWidth: width / 4

    model: ListModel {
        ListElement {
            value: 1
        }
        ListElement {
            value: 2
        }
        ListElement {
            value: 3
        }
        ListElement {
            value: 4
        }
    }

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight
        Tile {
            anchors.fill: _backgroundDelegate
            anchors.margins: 5
        }
    }
}
