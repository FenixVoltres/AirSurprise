import QtQuick 2.0

Rectangle {
    width: 1024
    height: 640

    focus: true
    Keys.onEscapePressed: Qt.quit()

    LevelOne {
        id: levelOne
        anchors.fill: parent
    }

    Text {
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }

        text: "(" + Math.floor(_QmlInterface.position.x) + ", " + Math.floor(_QmlInterface.position.y) + ")"
        font.pointSize: 30
        color: "white"
    }

    MousePointer {
        id: mousePointer
    }
}
