import QtQuick 2.0

Rectangle{
    id: startGameButton
    width: 141
    height: 141

    color: "transparent"
    objectName: "pressable"

    property alias foregroundImage: foregroundImage.source
    property alias backgroundImage: circle.source

    Image {
        id: foregroundImage
        anchors.centerIn: parent
    }

    Image
    {
        id: circle
        anchors.centerIn: parent
    }

    states: State{
        name: "pressed"
        when: mousePointer.isInside(startGameButton) && startGameButton.enabled
//        PropertyChanges { target: startGameButton; color: "red"; restoreEntryValues: true }
    }

    function clickCallback() {
        world.state = "level"
    }
}
