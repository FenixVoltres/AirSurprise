import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: levelOne

    Image {
        id: name
        source: "../../img/commons/background_wall_green.png"
    }

    Grid {
        columns: 5
        anchors.margins: 5
        anchors.centerIn: parent
        spacing: 15

        Repeater {
            model: 5;
            delegate: PlaceHolder {  }
        }
    }

    Repeater {
        model: 5;
        delegate: Creature {  }
    }
}
