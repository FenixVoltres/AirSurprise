import QtQuick 2.0

Image {
    id: star
    width:130
    height:130
    source: fullStar ? "../../img/level_complete/icon_star_full.png" : "../../img/level_complete/icon_star_empty.png"

    property bool fullStar: 15 -index*5 >= levelOne.seconds

    SequentialAnimation {
        id: pulseAnimation
        running: fullStar
        loops: 8768768
        NumberAnimation { target: star; property: "scale"; from: 1.0; to: 1.5; duration: 500 }
        NumberAnimation { target: star; property: "scale"; from: 1.50; to: 1.0; duration: 500 }
    }
}
