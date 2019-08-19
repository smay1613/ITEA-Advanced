import QtQuick 2.0
import QtGraphicalEffects 1.0
import Game 1.0

GridView {
    id: roots
    cellHeight: height / model.dimension
    cellWidth: width / model.dimension

    model: GameBoardModel {

    }

    delegate: Item {
        id: _backgroundDelegate
        width: roots.cellWidth
        height: roots.cellHeight

        Tile {
            id: _internalTile
            visible: display != roots.model.boardSize
            displayText: display
            anchors.fill: _backgroundDelegate
            anchors.margins: 1
            radius: 10
        }

        MouseArea {

            hoverEnabled: true
            anchors.fill: _internalTile
            onEntered: {
                _internalTile.color = "#b5b5b5"
            }
            onExited: {
                _internalTile.color = "white"
            }
            onClicked: {
                roots.model.move(index)
            }
        }
    }

    Text {
        id: textstr
        x: root.width / 1.145
        y: root.height / 50
        text: qsTr("MOVES")
        fontSizeMode: Text.FixedSize
        renderType: Text.QtRendering
        font.pixelSize: root.width/40
        color: "white"
    }

    Text {
        id: textScore
        x: root.width / 1.1
        y: root.height / 15
        text: roots.model.numbersOfSteps
        fontSizeMode: Text.FixedSize
        renderType: Text.QtRendering
        font.pixelSize: root.width/30
        color: "white"
    }

    Rectangle {
        id: rec
        x: root.width / 1.12
        y: root.height / 1.2
        width: root.height < root.width?
                   root.height/10 : root.width/10
        height: root.height < root.width?
                    root.height/10 : root.width/10
        radius: 100
        color: "#383838"
        MouseArea {
            id: _mouse
            hoverEnabled: true
            anchors.fill: rec
            onClicked: {
                roots.model.shuffleBoardFunc
            }
        }
        RectangularGlow {
            visible: _mouse.containsMouse
            cornerRadius: parent.radius
            glowRadius: parent.radius/10
            anchors.fill: parent

        }
    }
    Image {
        id: restartImage
        x: root.width / 1.12
        y: root.height / 1.2
        width: root.height < root.width?
                   root.height/10 : root.width/10
        height: root.height < root.width?
                    root.height/10 : root.width/10
        opacity: 1
        source: "restart-icon.png"
        fillMode: Image.PreserveAspectFit
    }

    displaced: Transition {
        NumberAnimation { properties: "x,y"; duration: 800; easing.type: Easing.InOutExpo }
    }
}

