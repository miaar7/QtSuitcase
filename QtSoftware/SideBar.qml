import QtQuick 2.4
import QtQuick.Controls 2.0
//import QtQuick.Controls.Material 2.0

SideBarForm {
        id: sideBar
        signal modeChanged(bool mode)
        switchMode {

            onPressed: {
                backend.setMode(!switchMode.checked)
                sideBar.modeChanged(switchMode.checked)
            }
        }
}
