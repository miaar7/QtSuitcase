import QtQuick 2.0
import QtCharts 2.0


PageBackground {
    property alias axisXstyle: axisXstyle

    ChartView {
        title: "Temperature"
        anchors.fill: parent
        antialiasing: true
        backgroundColor: "transparent"
        titleColor: "white"

        ValueAxis {
            id: axisXstyle
            min: 0
            max: 60
            tickCount: 10
            labelFormat: "%i"
            labelsColor: "white"

          }

        ValueAxis {
            id: axisYstyle
            min: 0
            max: 40
            tickCount: 5
            labelsColor: "white"
        }

        LineSeries {
            name: "LineSeries"
            axisX: axisXstyle
            axisY: axisYstyle

            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 50; y: 33 }
        }


    }

}

