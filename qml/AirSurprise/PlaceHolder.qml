import QtQuick 2.0

DropArea {
    id: dragTarget

    property alias dropProxy: dragTarget

    width: 100
    height: 100

    Rectangle {
        id: dropRectangle

        color: "yellow"
        anchors.fill: parent

        states: [
            State {
                when: dragTarget.containsDrag
                PropertyChanges {
                    target: dropRectangle
                    color: "grey"
                }
            }
        ]
    }

}
