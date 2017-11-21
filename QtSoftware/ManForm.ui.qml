import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Extras 1.4

PageBackground {

    property alias swLamp1: swLamp1
    property alias swLamp2: swLamp2
    property alias swLamp3: swLamp3
    property alias fanSlider: fanSlider
    property alias pBarPV : pBarPV
    property alias pvValue : pvValue
    property alias fanValue: fanValue

    id: pageBackground
    height: 232
    // property alias tempFormLabel: label.text
    // property alias pBarSP: pBarSP
   // property alias pBarPV: pBarPV
   // property alias pvValue : pvValue.text
   // property alias dial: dial

    ProgressBar {
        id: pBarPV
        x: 266
        y: 158
        width: 100
        height: 10
        to: 60
        from: 10
        rotation: -90
        value: 20
    }

    Label {
        id: labelPV
        y: 32
        text: qsTr("Temperature")
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

    Switch {
        id: swLamp1
        x: 21
        y: 46
        width: 130
        text: qsTr("Lamp 1")
        enabled: true
        padding: 0
        topPadding: 0
    }

    Switch {
        id: swLamp2
        x: 21
        y: 94
        width: 130
        text: qsTr("Lamp 2")
        padding: 0
        anchors.top: swLamp1.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: swLamp1.horizontalCenter
    }

    Switch {
        id: swLamp3
        x: 21
        y: 131
        width: 130
        text: qsTr("Lamp 3")
        padding: 0
        anchors.top: swLamp2.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: swLamp1.horizontalCenter
    }

    Slider {
        id: fanSlider
        x: 133
        y: 122
        width: 150
        height: 32
        padding: 0
        rotation: -90
        value: 0.5
    }

    Label {
        id: fanSpeedlabel
        x: 1
        y: 13
        text: qsTr("Fan speed")
        anchors.horizontalCenterOffset: -108
        anchors.bottom: pBarPV.top
        anchors.horizontalCenter: pBarPV.horizontalCenter
        anchors.bottomMargin: 128
    }

    Label {
        id: fanValue
        x: 190
        y: 30
        text: qsTr("Label")
    }
}
