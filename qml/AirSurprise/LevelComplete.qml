import QtQuick 2.0

Rectangle {
    id: levelCompleted

    Image {
        id: background
        anchors.fill: parent
        source: "../../img/commons/background_wall_red.png"
    }

    Mascot {

    }

    Logo {

    }

    Grid {
        anchors.bottom: parent.bottom

        Repeater {
            model: 3
            delegate: Image{
                width:130
                height:130
                source: "../../img/level_complete/icon_star_full.png"
            }
        }
    }
}
