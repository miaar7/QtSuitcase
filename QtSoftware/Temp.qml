import QtQuick 2.4
import QtQuick.Controls 2.0
//import QtQuick.Controls.Material 2.0

TempForm {
            tempFormLabel: pBarSP.value.toFixed(1) + " °C"
            pvValue: pBarPV.value.toFixed(1) + " °C"


}
