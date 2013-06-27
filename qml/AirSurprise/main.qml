import QtQuick 2.0

Rectangle {
    width: 640
    height: 480

    color: "green"

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
