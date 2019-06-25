import QtQuick 2.0
import  QtGraphicalEffects 1.0

Rectangle {
    id: rect
    property alias internalText: valueText
    color: "lightblue"
    border.color: "green"
    border.width: 2
    radius: 5
    Text {
        id: valueText
        text: "1"
        font.bold: true
        font.pointSize: rect.height * 0.33
        anchors.centerIn: rect
    }
}

