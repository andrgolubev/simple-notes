import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: Screen.width / 4
    height: Screen.height / 3

    toolBar: ToolBar {
        RowLayout {
            ToolButton {
                objectName: "saveButton"
                text: qsTr("Save")
                signal saveMessage(string message)
                onClicked: saveMessage(mainForm.textArea.text)
            }

            ToolButton {
                text: qsTr("Clear")
                onClicked: mainForm.textArea.text = ""
            }
        }
    }

    MainForm {
        id: mainForm
        anchors.fill: parent
    }

    Connections {
        target: fileWorker
        onLoadMessage: mainForm.textArea.text = message
    }
}

