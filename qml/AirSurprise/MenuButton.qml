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

    NumberAnimation {
        id: fadeOut
        target: mainMenu
        properties: "opacity"
        from: 1.0
        to: 0.0
        duration: 500
        }

    NumberAnimation {
        id: fadeIn
        target: levelOne
        properties: "opacity"
        from: 0.0
        to: 1.0
        duration: 500
        }


    function clickCallback()
    {
//        fadeOut.start();
//        fadeIn.start();
        world.state = "level"
    }
}
