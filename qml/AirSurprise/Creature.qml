import QtQuick 2.0

Image {
    id: creature
    objectName: "dragable"

    property int lastHolderIndex

    width: 120; height: 250
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter

    source: "../../img/level_001/animal_00"+ (index+1) + ".png"

    states: State {
        name: "dragged"
        ParentChange { target: creature; parent: mousePointer }
        AnchorChanges { target: creature; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
    }

    transitions: Transition {
        to: "dragged"
//        ScriptAction { script: console.log("asdasd")}
        ParentAnimation {
            NumberAnimation { properties: "x,y"; duration: 1000 }
        }
    }
}
