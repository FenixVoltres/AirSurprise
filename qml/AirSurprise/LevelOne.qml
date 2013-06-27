import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: levelOne

    gradient: Gradient {
        GradientStop { position: 0.0; color: "white"; }
        GradientStop { position: 1.0; color: "blue";  }
    }

    Grid {
        columns: 5
        anchors.margins: 5
        anchors.centerIn: parent
        spacing: 10

        Repeater {
            model: 5;
            delegate: PlaceHolder {  }
        }
    }

    Creature {
        id: creature1
    }
}
