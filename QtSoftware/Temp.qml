import QtQuick 2.4
import QtQuick.Controls 2.0
//import QtQuick.Controls.Material 2.0

TempForm {
    id: tempForm

    signal dialChange(real value)

            Connections {
                target:applicationWindow

                onTempChange: {
                pBarPV.value = temp
                }
             }
            tempFormLabel: pBarSP.value.toFixed(1) + " °C"
            pvValue: pBarPV.value.toFixed(1) + " °C"

            dial
            {
                onValueChanged:{
                    backend.setSetpoint(dial.value)
                    tempForm.dialChange(dial.value)
                }
                //onPositionChanged:{backend.setSetpoint(dial.value)}

            }


}
