import QtQuick 2.0

Rectangle {
    id: _rectangle

    property string displayText

    color: "white"
    border.color: "black"
    border.width: 2

    Text {
        id: _text
        text: _rectangle.displayText
        anchors.centerIn: _rectangle
        font.bold: true
        font.pointSize: _rectangle.height < _rectangle.width ?
                            _rectangle.height * 0.2
                          : _rectangle.width * 0.2
    }
}
