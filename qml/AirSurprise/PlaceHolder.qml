import QtQuick 2.0

Rectangle {
    id: dropRectangle
    width: 120; height: 250

    color: "green"
    opacity: 0.3

    states: [
        State {
            name: "greyed"
            when: mousePointer.isDragging && mousePointer.isInside(dropRectangle)
            PropertyChanges {
                target: dropRectangle
                color: "grey"
            }
        }
    ]

    onStateChanged: {
        if (state === "greyed")
            mousePointer.drop = dropRectangle
    }
}
