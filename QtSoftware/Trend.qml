import QtQuick 2.4
import QtQuick.Controls 2.0
//import QtQuick.Controls.Material 2.0

TrendForm {


    property int i: 0

    property date currentDate
    property date xAxisMin
    property int timeScale: 60000
    property real setPoint: 0


  Connections {
        target:applicationWindow

        onTempChange: {
            if(temp > axisYstyle.max){
                axisYstyle.max = temp+5
            }

            if(temp < axisYstyle.min){
                axisYstyle.min = temp.toFixed(0)
            }
            if(temp != 0){
                currentDate = new Date()
                tempSeries.append(currentDate,temp)
                setSeries.append(currentDate,setPoint)

                xAxis.max = currentDate
                xAxisMin = new Date(toMSec(currentDate)-timeScale)
                xAxis.min = xAxisMin


            }
        }

        onSetpointChange: {

           setPoint = value
        }

    }

    timeSlider {
        onPositionChanged: {
            console.log(timeSlider.position)
            timeScale = (timeSlider.position * (3600000-60000)) + 60000
            xAxisMin = new Date(toMSec(currentDate)-timeScale)
            xAxis.min = xAxisMin


        }
    }


  function toMSec(date){
      var msec = date.getTime()
      return msec
  }
}
