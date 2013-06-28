import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    id: world
    width: 1024
    height: 640
    state: "menu"

    focus: true
    Keys.onEscapePressed: Qt.quit()

    FontLoader {  id: openSansFont; source: "./font/OpenSansCondBold.ttf" }

    LevelComplete {
        id: levelComplete
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

    BetterText {
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

    Audio {
        id: audio
        loops: -1
        autoPlay: true
        source: "../../sounds/theme1.mp3"
    }

    states:[
        State {
            name: "menu"
            PropertyChanges { target: mainMenu; opacity: 1.0 }
            PropertyChanges { target: levelOne; opacity: 0.0 }
            PropertyChanges { target: levelComplete; opacity: 0.0 }
        },
        State {
            name: "level"
            PropertyChanges { target: mainMenu; opacity: 0.0 }
            PropertyChanges { target: levelOne; opacity: 1.0 }
            PropertyChanges { target: levelComplete; opacity: 0.0 }
        },
        State {
            name: "levelComplete"
            when: levelOne.levelCompleted
            PropertyChanges { target: mainMenu; opacity: 0.0 }
            PropertyChanges { target: levelOne; opacity: 0.0 }
            PropertyChanges { target: levelComplete; opacity: 1.0 }
        }

    ]

    transitions: [
            Transition {
                to: "level"
                NumberAnimation { target: mainMenu; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelOne; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelComplete; properties: "opacity"; duration: 800}
            },
            Transition {
                to: "menu"
                NumberAnimation { target: mainMenu; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelOne; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelComplete; properties: "opacity"; duration: 800}
            },

            Transition {
            to: "levelComplete"
                NumberAnimation { target: mainMenu; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelOne; properties: "opacity"; duration: 800}
                NumberAnimation { target: levelComplete; properties: "opacity"; duration: 800}
            }

         ]
}
