import QtQuick 2.0

Rectangle {
    width: 1024
    height: 640
    id: world

    focus: true
    Keys.onEscapePressed: Qt.quit()

    LevelComplete {
        id: levelCompleted
        anchors.fill: parent
    }

    LevelOne {
        id: levelOne
        anchors.fill: parent
        opacity: 0.0
    }

    MainMenu {
        id: mainMenu
        anchors.fill: parent
        opacity: 0.0
    }

    states:[
        State {
            name: "menu"
            PropertyChanges { target: mainMenu; opacity: 1.0 }
            PropertyChanges { target: levelOne; opacity: 0.0 }
            PropertyChanges { target: levelCompleted; opacity: 0.0 }
        },
        State {
            name: "level"
            PropertyChanges { target: mainMenu; opacity: 0.0 }
            PropertyChanges { target: levelOne; opacity: 1.0 }
            PropertyChanges { target: levelCompleted; opacity: 0.0 }
        },
        State {
            name: "levelComplete"
            when: levelOne.levelCompleted
            PropertyChanges { target: mainMenu; opacity: 0.0 }
            PropertyChanges { target: levelOne; opacity: 0.0 }
            PropertyChanges { target: levelCompleted; opacity: 1.0 }
        }

    ]

    transitions: [
            Transition {
                to: "level"
                NumberAnimation { target: mainMenu; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelOne; properties: "opacity"; duration: 800}
            },
            Transition {
                to: "menu"
                NumberAnimation { target: mainMenu; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelOne; properties: "opacity"; duration: 800}
            }
         ]

    state: "menu"

    Text {
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }

        text: "(" + Math.floor(_QmlInterface.position.x) + ", " + Math.floor(_QmlInterface.position.y) + ")"
        font.pointSize: 30
        color: "white"

        opacity: 0.4
    }

    MousePointer {
        id: mousePointer
    }
}
