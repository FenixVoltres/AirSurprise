import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: mainMenu
    width: 100
    height: 62

    Image {
        id: background
        anchors.fill: parent
        source: "../../img/commons/background_wall_red.png"
    }

    Image{
        id: logo
        width: 375
        height: 275

        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.horizontalCenter: parent.horizontalCenter

        source: "../../img/lobby/lobby_logo_crayon_castle.png"
    }

    Image
    {
        id: character
        width: 280
        height: 380

        anchors.top: parent.top
        anchors.topMargin: 175
        anchors.right: parent.right
        anchors.rightMargin: 60

        source: "../../img/commons/lobby_mascot.png"

    }

    Grid {
        columns: 3
        anchors.margins: 5
        anchors.left: parent.left
        anchors.leftMargin: 70
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 80
        spacing: 85

        Repeater {
            model: 3;
            delegate: MenuButton {
                foregroundImage: "../../img/ui/ui_btn_icon_menu_00" + (index + 1) + ".png"
            }
        }
    }


}

