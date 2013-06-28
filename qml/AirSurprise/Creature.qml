import QtQuick 2.0

//        onReleased: parent = tile.Drag.target !== null ? tile.Drag.target : root

Image {
    id: tile
    objectName: "dragable"

    property int lastHolderIndex

    width: 120; height: 250
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter

    source: "../../img/level_001/animal_00"+ (index+1) + ".png"

    states: State {
        name: "dragged"
        when: mouseArea.drag.active
        ParentChange { target: tile; parent: mousePointer }
        AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
    }
}
