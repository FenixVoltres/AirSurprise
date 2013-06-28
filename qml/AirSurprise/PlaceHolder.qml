import QtQuick 2.0

Rectangle {
    id: dropRectangle
    width: 120; height: 250
    objectName: "holder"

    property variant creature
    property int itemIndex

    color: "#44006400"

    states: [
        State {
            name: "highlighted"
            when: mousePointer.isDragging && mousePointer.isInside(dropRectangle)
            PropertyChanges {
                target: dropRectangle
                color: "#44222222"
            }
        }
    ]

    onStateChanged: {
        if (state === "highlighted") {
            mousePointer.drop = dropRectangle
            if ( creature ) {
                var fromLeft = _QmlInterface.position.x - dropRectangle.x < dropRectangle.width/2
                levelOne.reorder(itemIndex, fromLeft)
            }
        }
    }
}
