import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
//import QtQuick.Controls.Material 2.1

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 480
    height: 272
    title: qsTr("SmartSuitcase")
    //Material.theme: Material.Dark
    //Material.accent: Material.color(Material.Blue)

    SwipeView {
        id: swipeView
        anchors.left: sideBar.right
        anchors.right: parent.right
        anchors.bottom: tabBar.top
        anchors.top: parent.top
        currentIndex: tabBar.currentIndex

        Temp {

        }

        Trend {

        }
        Man {

        }

    }

    TabBar {
        id: tabBar
        height: 40
        anchors.right: parent.right
        anchors.left: sideBar.right
        anchors.bottom: parent.bottom
        currentIndex: swipeView.currentIndex
        TabButton {
            height: 40
            text: qsTr("Temp control")
        }
        TabButton {
            height: 40
            text: qsTr("Trend")
        }
        TabButton {
            height: 40
            text: qsTr("Manual")
        }
    }

    SideBar {
        id: sideBar
    }
}
