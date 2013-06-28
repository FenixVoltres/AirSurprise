import QtQuick 2.0

Rectangle {
    id: levelComplete

    Image {
        id: background
        anchors.fill: parent
        source: "../../img/commons/background_wall_red.png"
    }

    Mascot {

    }

    Logo {
        width: 430
        height: 255

        source: "../../img/level_complete/text_level_complete.png"
    }

    Grid {
        id: grid
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 150
        spacing: 30

        anchors.horizontalCenter: parent.horizontalCenter;

        Repeater {
            model: 3
            delegate: Star {}
        }
    }

    MenuButton {
        foregroundImage: "../../img/ui/ui_btn_icon_big_restart.png"
        backgroundImage: "../../img/ui/ui_btn_circle_big.png"

        function clickCallback()
        {
            world.state = "menu"
        }
    }
}
