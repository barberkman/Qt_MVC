import QtQuick
import QtQuick.Window

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: listViewID
        anchors.fill: parent
        model: ListController ? ListController.model : null
        delegate: Text {
            id: textDelegateID
            width: window.width
            height: 20
            text: model.display
        }
    }
}
