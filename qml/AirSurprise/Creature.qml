import QtQuick 2.0

//        onReleased: parent = tile.Drag.target !== null ? tile.Drag.target : root

Rectangle {
    id: tile
    objectName: "dragable"

    width: 64; height: 64
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter

    color: "red"

    states: State {
        name: "dragged"
        when: mouseArea.drag.active
        ParentChange { target: tile; parent: mousePointer }
        AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
    }
}
