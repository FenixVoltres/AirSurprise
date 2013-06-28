import QtQuick 2.0
import QtQuick.Layouts 1.0
import "PlaceHolderScript.js" as Script

Rectangle {
    id: levelOne

    property bool levelCompleted
    property int seconds
    property int maxTime: 15

    anchors.fill: parent

    Image {
        id: name
        source: "../../img/commons/background_wall_green.png"
        anchors.fill: parent
        fillMode: Image.Stretch
    }

    BetterText {
        text: "Reorder the creatures tallest right"
        color: "white"
        opacity: 0.7
        font.pointSize: 40
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50
    }

    BetterText {
        id: timerText
        text: displayText()
        opacity: 0.7
        font.pointSize: 70
        anchors {
            bottom: parent.bottom
            right: parent.right
            bottomMargin: 50
            rightMargin: 50
        }
        color: calculateColor()

        Behavior on color { ColorAnimation { duration: 100 } }
    }

    Timer {
        id: timer
        interval: 1000;
        repeat: true;
        running: false
        onTriggered: {
            ++seconds
            pulseAnimation.running = true
        }
    }

    SequentialAnimation {
        id: pulseAnimation
        NumberAnimation { target: timerText; property: "scale"; from: 1.0; to: 1.15; duration: 100 }
        NumberAnimation { target: timerText; property: "scale"; from: 1.15; to: 1.0; duration: 100 }
    }

    Repeater {
        model: 5
        delegate: PlaceHolder {
            id: placeHolder
            itemIndex: index
            anchors {
                bottom: parent.bottom
                bottomMargin: parent.height * 0.25
            }
            x: parent.width*0.17 + index * parent.width* 0.13

            Component.onCompleted: Script.placeHolders.push(placeHolder)
        }
    }

    Repeater {
        model: 5;
        delegate: Creature {
            id: creature
            Component.onCompleted: Script.creatures.push(creature)
        }
    }

    onLevelCompletedChanged: {
        if (levelCompleted)
            stopLevel()
    }

    function reorder(index, fromLeft) {
        if ( fromLeft ) {
            if ( isAnySpaceToRight(index) )
                moveItemsToRight(index)
            else
                moveItemsToLeft(index)
        } else {
            if ( isAnySpaceToLeft(index) )
                moveItemsToLeft(index)
            else
                moveItemsToRight(index)
        }
    }

    function moveItemsToLeft(index) {
        var nextCreature
        for (var i=index; i>=0; --i) {
            var currentHolder       = Script.placeHolders[i]
            var nextHolder          = Script.placeHolders[i-1]
            var currentCreature     = currentHolder.creature

            if (nextCreature) {
                nextCreature.parent     = currentHolder
                currentHolder.creature  = nextCreature
            } else
                currentHolder.creature  = null

            if (!currentCreature || !nextHolder)
                return

            nextCreature            = currentCreature
            nextCreature.parent     = levelOne
        }
    }

    function moveItemsToRight(index) {
        var nextCreature
        for (var i=index; i<Script.placeHolders.length; ++i) {
            var currentHolder       = Script.placeHolders[i]
            var nextHolder          = Script.placeHolders[i+1]
            var currentCreature     = currentHolder.creature

            if (nextCreature) {
                nextCreature.parent     = currentHolder
                currentHolder.creature  = nextCreature
            } else
                currentHolder.creature  = null

            if (!currentCreature || !nextHolder)
                return

            nextCreature            = currentCreature
            nextCreature.parent     = levelOne
        }
    }

    function isAnySpaceToLeft(index) {
        var isAnySpace = false
        for (var i=index-1; i>=0; --i)
            if ( !Script.placeHolders[i].creature )
                return true
        return false
    }

    function isAnySpaceToRight(index) {
        var isAnySpace = false
        for (var i=index+1; i<Script.placeHolders.length; ++i)
            if ( !Script.placeHolders[i].creature )
                return true
        return false
    }

    function populateCreatures() {
        var order = Script.shuffle([0,1,2,3,4])

        for(var i=0; i<Script.creatures.length; ++i) {
            var creature    = Script.creatures[i]
            var holder      = Script.placeHolders[order[i]]
            creature.parent = holder
            holder.creature = creature
        }
    }

    function startLevel() {
        populateCreatures()
        timer.running = true
        seconds = 0;
    }

    function stopLevel() {
        timer.running = false
    }

    function displayText() {
        var onlyMinutes = Math.floor(seconds / 60)
        var onlySeconds = seconds % 60;

        return addZero(onlyMinutes) + ":" + addZero(onlySeconds)
    }

    function addZero(number) {
        return (number < 10 ? "0" : "") + number
    }

    function calculateColor() {
        if (seconds > maxTime)
            return Qt.rgba(1.0, 0.0, 0.0, 1)

        var progress = seconds / maxTime;
        var r = Math.min(progress*2, 1.0);
        var g = Math.min(2*(1-progress), 1.0);
        var b = 0;

        return Qt.rgba(r, g, b, 1)
    }

    function isLevelComplete() {
        for (var i=0; i<Script.creatures.length; ++i)
            if (Script.placeHolders[i].creature !== Script.creatures[i])
                return false
        return true
    }
}
