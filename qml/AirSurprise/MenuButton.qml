import QtQuick 2.0

Rectangle{
    id: startGameButton
    width: 141
    height: 141

//    anchors.bottom: parent.bottom;
//    anchors.bottomMargin: 70;
//    anchors.horizontalCenter: parent.horizontalCenter;
    color: "transparent"

    property alias foregroundImage: foregroundImage.source

    Image {
        id: foregroundImage
        anchors.fill: parent
    }

    Image
    {
        id: circle
        anchors.fill: parent

        source: "../../img/ui/ui_btn_circle_big.png"
    }
}
