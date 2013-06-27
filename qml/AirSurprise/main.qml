import QtQuick 2.0

Rectangle {
    width: 640
    height: 480

    focus: true
    Keys.onEscapePressed: Qt.quit()

    LevelOne {
        anchors.fill: parent
    }
}
