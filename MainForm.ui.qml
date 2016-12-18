import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

Rectangle {
    width: Screen.width / 4
    height: Screen.height / 3

    property alias textArea: notesTextArea

    TextArea {
        id: notesTextArea
        objectName: "notesTextArea"
        anchors {
            fill: parent
            margins: 10
        }
        textFormat: TextEdit.RichText
        font.pixelSize: 15
    }
}

