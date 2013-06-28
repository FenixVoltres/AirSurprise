import QtQuick 2.0
import QtQuick.Layouts 1.0
import "PlaceHolderScript.js" as Script

Rectangle {
    id: levelOne

    property bool levelCompleted

    anchors.fill: parent

    Image {
        id: name
        source: "../../img/commons/background_wall_green.png"
        anchors.fill: parent
        fillMode: Image.Stretch
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

    function isLevelComplete() {
        for (var i=0; i<Script.creatures.length; ++i) {
            console.log(Script.placeHolders[i].creature.source)
        }

        for (var i=0; i<Script.creatures.length; ++i)
            if (Script.placeHolders[i].creature !== Script.creatures[i]) {
                console.log("false")
                return false
            }

        console.log("true")
        return true
    }

    Component.onCompleted: populateCreatures()
}
