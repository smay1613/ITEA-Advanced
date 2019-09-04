import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ContactsModule.Impl 1.0
import StyleModule 1.0
import Contacts 1.0

Window {
    visible: true
    width: 480
    height: 640
    title: qsTr("Address book")

    ContactsView {
        anchors.fill: parent
    }

    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }

    Rectangle {
        id: _add
        color: "lightgreen"
        width: 70
        height: 70
        y: parent.height - width - 10
        x: parent.width - height - 10
        radius: 35
        MouseArea {
            anchors.fill: parent
            onClicked: {
                _popup.visible = true
                _add.visible = false
            }
        }
    }

    Popup {
        visible: false
        width: parent.width
        height: parent.height
        padding:0
        id: _popup

        Rectangle {
            z: -100
            anchors.fill: parent
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
        }

        Rectangle {
            width: parent.width * 2 / 3
            height: parent.width * 2 / 3
            x: parent.width / 2 - width / 2
            y: 30
            color: "lightgreen"
            radius: width/2
        }

        Text {
            y: parent.width * 2 / 3 + 70
            x: _popup.width/10
            text: "Name:"
            font.pixelSize: 22
            color: "white"
        }
        Rectangle {
            y: parent.width * 2 / 3 + 70
            x: _popup.width * 4 / 10
            width: _popup.width / 2
            height: 30
            color: "white"
            TextInput {
                id: _name
                font.pixelSize: 22
                anchors.fill: parent
                color: "grey"
            }
        }

        Text {
            y: parent.width * 2 / 3 + 130
            x: _popup.width/10
            text: "Surname:"
            font.pixelSize: 22
            color: "white"
        }
        Rectangle {
            y: parent.width * 2 / 3 + 130
            x: _popup.width * 4 / 10
            width: _popup.width / 2
            height: 30
            color: "white"
            TextInput {
                id: _surname
                font.pixelSize: 22
                anchors.fill: parent
                color: "grey"
            }
        }

        Text {
            y: parent.width * 2 / 3 + 190
            x: _popup.width/10
            text: "Phone:"
            font.pixelSize: 22
            color: "white"
        }
        Rectangle {
            y: parent.width * 2 / 3 + 190
            x: _popup.width * 4 / 10
            width: _popup.width / 2
            height: 30
            color: "white"
            TextInput {
                id: _phone
                font.pixelSize: 22
                anchors.fill: parent
                color: "grey"
            }
        }

        Button {
            y: parent.height - 60
            x: parent.width/2-15-width
            text: "Ok"
            height: 30
            onClicked: {
                _contactsModel.addContact(_name.getText(),
                                          _surname.getText(),
                                          _phone.getText())
                _add.visible = true
                _popup.visible = false
            }
        }
        Button {
            y: parent.height - 60
            x: parent.width/2+15
            text: "Cancel"
            height: 30
            onClicked: {
                _add.visible = true
                _popup.visible = false
            }
        }

        ContactsModel {
            id: _contactsModel
        }
    }
}
