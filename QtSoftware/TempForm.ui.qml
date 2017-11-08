import QtQuick 2.4
import QtQuick.Controls 2.1

PageBackground {
    id: pageBackground
    property alias tempFormLabel: label.text
    property alias pBarSP: pBarSP
    property alias pBarPV: pBarPV
    property alias pvValue : pvValue.text
    property alias dial: dial

    Dial {
        id: dial
        x: 152
        y: 99
        width: 150
        height: 150
        enabled: true
        to: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ProgressBar {

        id: pBarSP
        x: 4
        y: 152
        width: 100
        height: 10
        to: 60
        value: dial.position * pBarSP.to
        anchors.verticalCenterOffset: 20
        anchors.verticalCenter: dial.verticalCenter
        anchors.horizontalCenterOffset: -125
        anchors.horizontalCenter: dial.horizontalCenter
        rotation: -90
    }

    ProgressBar {
        id: pBarPV
        x: 266
        y: 158
        width: 100
        height: 10
        to: 60
        from: 10
        anchors.verticalCenterOffset: 20
        anchors.verticalCenter: dial.verticalCenter
        anchors.horizontalCenterOffset: 125
        anchors.horizontalCenter: dial.horizontalCenter
        rotation: -90
        value: 20
    }

    Label {
        id: labelSP
        x: 86
        y: 32
        text: "Setpoint"
        anchors.bottom: pBarSP.top
        anchors.bottomMargin: 100
        anchors.horizontalCenter: pBarSP.horizontalCenter
    }

    Label {
        id: labelPV
        y: 32
        text: qsTr("Process value")
        anchors.bottom: pBarPV.top
        anchors.bottomMargin: 100
        anchors.horizontalCenter: pBarPV.horizontalCenter
    }

    Label {
        id: label
        x: 48
        y: 57
        //text: (pBarSP.value).toFixed(1) + "°C"
    }

    Label {
        id: pvValue
        x: 298
        y: 57
        text: qsTr("Label")
    }
}
