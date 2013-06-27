import QtQuick 2.0

Rectangle {
    id: mousePointer
    width: 20
    height: 20

    property variant drag
    property variant drop
    property bool isDragging: false

    x: _QmlInterface.position.x - width/2
    y: _QmlInterface.position.y - height/2

    radius: 10
    color: isDragging ? "yellow" : "black"

    SimpleProgressBar {
        id: progressBar

        x: -width/2 +mousePointer.width/2
        y: -height - 5

        visible: _QmlInterface.holdPercentage > 0.1

        value: _QmlInterface.holdPercentage * 100
    }

    Connections {
        target: _QmlInterface
        onPressedChanged: {
            if (!isDragging)
                isDragging = startDrag()
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
            progressBar.z = drag.z + 2
            return true
        }
        return false
    }

    function stopDrag() {
        isDragging = false
        if ( !drag )
            return

        console.log(drag)

        drag.state = ""
        drag.parent = drop
    }

    function isInside(obj) {
        return _QmlInterface.position.x >= obj.x + obj.parent.x && _QmlInterface.position.x <= obj.x+ obj.parent.x + obj.width &&
                _QmlInterface.position.y >= obj.y+ obj.parent.y && _QmlInterface.position.y <= obj.y + obj.parent.y + obj.height
    }
}
