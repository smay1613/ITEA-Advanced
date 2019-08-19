import QtQuick 2.0
import QtGraphicalEffects 1.0
import Game 1.0

GridView {
    id: _root

    cellHeight: height / 4
    cellWidth: width / 4

    interactive: false

    delegate: Item {
        id: _backgroundDelegate
        width: _root.cellWidth
        height: _root.cellHeight

        visible: display !== _root.model.hiddenElementValue()

        Tile {
            id: _tile
            color: _mouseArea.containsMouse? "#f8efe3" : "#ece5d7"
            anchors.fill: _backgroundDelegate
            anchors.margins: 5

            internalText.text: display.toString()
            MouseArea {
                id: _mouseArea
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    _root.model.move(index)
                }
                onPressAndHold: {
                    _root.model.shuffleBoard()
                }
            }
            RectangularGlow {
                visible: _mouseArea.containsMouse
                cornerRadius: parent.radius
                glowRadius: parent.radius/2
                anchors.fill: parent
                z: -15
                opacity: 100
            }
        }
    }

    GameController_qml{
        id: _gameController
    }

    Component.onCompleted: {
        _root.model =  _gameController.getModel();
    }

    move: Transition {
        NumberAnimation {
            properties: "x, y"
            duration: 200
            easing.type: Easing.InOutExpo
        }
    }
}
