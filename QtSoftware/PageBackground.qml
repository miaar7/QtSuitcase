import QtQuick 2.0
import QtQuick.Controls 2.1
//import QtQuick.Controls.Material 2.1

Rectangle {
    //Material.theme: Material.Dark
    //Material.accent: Material.color(Material.Blue)

    width: 380
    height: 232
    color: "#191919"
    clip: true
    property alias title: label.text

    Label {
        id: label
        x: 8
        y: 18
        text: qsTr("Label")
        renderType: Text.QtRendering
        font.pointSize: 14
    }

    Rectangle {
        id: rectangle
        x: 319
        y: -93
        width: 300
        height: 200
        color: "#3a3a3a"
        clip: false
        rotation: 45
    }
}
