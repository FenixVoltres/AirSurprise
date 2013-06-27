import QtQuick 2.0

Rectangle {
    id: mousePointer
    width: 20
    height: 20

    property variant drag

    x: _QmlInterface.position.x - width/2
    y: _QmlInterface.position.y - height/2

    radius: 10
    color: _QmlInterface.pressed ? "red" : "black"

    Connections {
        target: _QmlInterface
        onPressedChanged: {
            if (_QmlInterface.pressed)
                startDrag()
            else
                stopDrag()
        }
    }

    function startDrag() {
        var object = levelOne.childAt(mousePointer.x, mousePointer.y)

        console.log(object)

        if (object && object.objectName === "dragable") {
            drag = object
            drag.state = "dragged"
        }
    }

    function stopDrag() {
        if ( !drag )
            return

        console.log(drag)

        drag.state = ""
    }
}
