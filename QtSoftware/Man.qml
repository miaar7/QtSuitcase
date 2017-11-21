import QtQuick 2.4
import QtQuick.Controls 2.0

ManForm {

    Connections {
        target:sideBar
        onModeChanged: {
            swLamp1.enabled = mode
            swLamp2.enabled = mode
            swLamp3.enabled = mode
            fanSlider.enabled = mode
        }
    }

    Connections {
        target:applicationWindow

        onTempChange: {
        pBarPV.value = temp
        }
     }

    pvValue {
        text: pBarPV.value.toFixed(1) + " °C"
    }

    fanValue {
        text : (fanSlider.position * 100).toFixed(1) + "%"
    }

    swLamp1
    {
        onPressed:
        { backend.setLamp1(!swLamp1.checked)
        }
    }

    swLamp2
    {
        onPressed: backend.setLamp2(!swLamp2.checked)
    }

    swLamp3
    {
        onPressed: backend.setLamp3(!swLamp3.checked)
    }

    fanSlider
    {
        onValueChanged:
        {
            console.log(fanSlider.value)
            backend.setFan(fanSlider.value)
        }

        onPositionChanged:
        {
            if(fanSlider.position > 0)
            {
                fanValue.text = (fanSlider.position*100.0).toFixed(1) + "%"
                fanValue.color = "white"
            } else
            {
                fanValue.text = "OFF"
                fanValue.color = "blue"
            }


        }
    }
}
