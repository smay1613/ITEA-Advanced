import QtQuick 2.0

Rectangle {
    id: root

    property alias internalText: _text
    border.color: "black"
    border.width: 2
    radius: height < width ? height/6 : width/6

    Text {
        id: _text
        anchors.centerIn: root
        font.bold: true
        font.pointSize: root.height < root.width? root.height/3 : root.width/3
        text: "1"
    }
}
