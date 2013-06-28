import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: mainMenu

    Image {
        id: background
        anchors.fill: parent
        source: "../../img/commons/background_wall_red.png"
    }

    Mascot {

    }

    Logo {

    }

    MenuButton{
        width: 90
        height: 90

        foregroundImage: "../../img/ui/ui_btn_icon_small_help.png"
    }

    Repeater {
        model: 3;
        delegate: MenuButton {
            foregroundImage: "../../img/ui/ui_btn_icon_menu_00" + (index + 1) + ".png"
            backgroundImage: "../../img/ui/ui_btn_circle_big.png"

            anchors.left: parent.left
            anchors.leftMargin: 70 + (index * 200)

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 90

            opacity: 1 - (0.7 * (index < 2))
            enabled: index >= 2
        }
    }
}

