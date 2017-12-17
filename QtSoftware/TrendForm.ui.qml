import QtQuick 2.0
import QtCharts 2.2
import QtQuick.Controls 2.1


PageBackground {
    id: pageBackground
    //property alias axisXstyle: axisXstyle
    property alias tempSeries: tempSeries
    property alias xAxis: xAxis
    property alias axisYstyle: axisYstyle
    property alias timeSlider: timeSlider
    property alias setSeries: setSeries

    ChartView {
        title: "Temperature °C"
        //anchors.fill: parent
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        antialiasing: true
        backgroundColor: "transparent"
        titleColor: "white"
        legend.visible: false


        ValueAxis {
            id: axisYstyle
            min: 20
            max: 30
            tickCount: 5
            labelFormat: "%i"
            labelsColor: "white"
        }

        DateTimeAxis {
            id: xAxis
            format: "hh:mm"
            tickCount: 2
            labelsColor: "white"
        }

        LineSeries {
            id: tempSeries
            //name: "Temprature"
            axisX: xAxis

            axisY: axisYstyle
        }

        LineSeries {
            id: setSeries
            //name: "Temprature"
            axisX: xAxis
            axisY: axisYstyle
        }

    }

    Slider {
        id: timeSlider
        width: 150
        height: 20
        anchors.bottomMargin: 10
        anchors.horizontalCenterOffset: 0
        padding: 0
        value: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
      }

    Label {
        id: oneMin
        height: 20
        width: 43
        text: qsTr("1 min")
        anchors.right: timeSlider.left
        anchors.rightMargin: 0
        anchors.bottom: timeSlider.bottom
        anchors.bottomMargin: 0

    }

    Label {
        id: oneHour
        height: 20
        width: 46
        text: qsTr("1 hour")
        anchors.left: timeSlider.right
        anchors.leftMargin: 10
        anchors.bottom: timeSlider.bottom
        anchors.bottomMargin: 0

    }

}

