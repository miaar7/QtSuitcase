import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2
import QtSensors 5.8

Item {
    id: page
    width: 480
    height: 272
    property alias button: button
    property alias mouseArea2: mouseArea2
    property alias bottomLeftRect: bottomLeftRect
    property alias mouseArea1: mouseArea1
    property alias middleRightRect: middleRightRect
    property alias mouseArea: mouseArea
    property alias topLeftRect: topLeftRect
    property alias icon: icon
    property alias textInput: textInput

    Image {
        id: icon
        x: 10
        y: 20
        width: 100
        height: 100
        source: "QtIcon.png"
    }

    Rectangle {
        id: topLeftRect
        width: 100
        height: 100
        color: "#00000000"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 10
        border.color: "#808080"

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }

    Rectangle {
        id: middleRightRect
        x: 3
        y: -3
        width: 100
        height: 100
        color: "#00000000"
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        border.color: "#808080"
        MouseArea {
            id: mouseArea1
            anchors.fill: parent
        }
    }

    Rectangle {
        id: bottomLeftRect
        x: 0
        y: 6
        width: 100
        height: 100
        color: "#00000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        border.color: "#808080"
        anchors.left: parent.left
        MouseArea {
            id: mouseArea2
            anchors.fill: parent
        }
        anchors.leftMargin: 10
    }

    TextInput {
        id: textInput
        x: 348
        y: 36
        width: 80
        height: 20
        //text: backend.userName
        font.weight: Font.Light
        font.pixelSize: 12

        //onTextChanged: backend.userName = text
    }

    Button {
        id: button
        x: 196
        y: 50
        text: qsTr("Button")
    }
}
