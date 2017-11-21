import QtQuick 2.4
import QtQuick.Controls 2.1

PageBackground {
    width: 100
    height: 272
    title: "Suitcase"
    property alias switchMode : switchMode

    Switch {
        id: switchMode
        x: 0
        y: 53
        width: 100
        height: 48
        text: ""
        scale: 1
        leftPadding: 8
        rightPadding: 8
        checked: true
    }

    Label {
        id: labelMode
        x: 16
        y: 47
        text: qsTr("Man - Auto")
    }
}
