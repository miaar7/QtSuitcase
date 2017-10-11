import QtQuick 2.4
import QtQuick.Controls 2.1

PageBackground {
    id: pageBackground
    title: "Temp control"

    Dial {
        id: dial
        x: 152
        y: 99
        width: 150
        height: 150
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ProgressBar {
        id: progressBar
        x: 4
        y: 152
        width: 175
        anchors.verticalCenter: dial.verticalCenter
        anchors.horizontalCenterOffset: -125
        anchors.horizontalCenter: dial.horizontalCenter
        value: dial.position
        rotation: -90
    }

    ProgressBar {
        id: progressBar1
        x: 266
        y: 158
        width: 175
        anchors.verticalCenter: dial.verticalCenter
        anchors.horizontalCenterOffset: 125
        anchors.horizontalCenter: dial.horizontalCenter
        rotation: -90
        value: 0.5
    }

    Label {
        id: label
        x: 86
        y: 32
        text: qsTr("Target")
        anchors.right: progressBar.horizontalCenter
        anchors.rightMargin: 10
        anchors.bottom: progressBar.bottom
        anchors.bottomMargin: 70
    }

    Label {
        id: label1
        y: 32
        text: qsTr("Actual")
        anchors.left: progressBar1.right
        anchors.leftMargin: -80
        anchors.bottom: progressBar1.bottom
        anchors.bottomMargin: 70
    }
}
