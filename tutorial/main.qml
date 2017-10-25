import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.VirtualKeyboard 2.1

//import io.qt.examples.backend 1.0


ApplicationWindow {
    visible: true
    width: 480
    height: 272
    title: qsTr("Transitions")
    id: root

    //BackEnd {
    //    id: backend
    //}

    function setTextField(text)
    {
        console.log("settextfield: " + text)
    }

        Page1Form{
            anchors.fill: parent
            id: page

            mouseArea {
                onClicked: stateGroup.state = ' '
            }

            mouseArea1 {
                onClicked: stateGroup.state = 'State1'
            }

            mouseArea2 {
                onClicked: stateGroup.state = 'State2'
            }

            button {
                onClicked: {
                    ic.testButtonClick(1)
                }
            }
        }

        StateGroup {
            id: stateGroup
            states: [
                State {
                    name: "State1"

                    PropertyChanges {
                        target: page.icon
                        x: page.middleRightRect.x
                        y: page.middleRightRect.y
                    }
                },
                State {
                    name: "State2"

                    PropertyChanges {
                        target: page.icon
                        x: page.bottomLeftRect.x
                        y: page.bottomLeftRect.y
                    }
                }
            ]
            transitions: [
                Transition {
                    from: "*"
                    to: "State1"
                    NumberAnimation {
                        easing.type: Easing.OutBounce
                        properties: "x,y"
                        duration: 1000
                    }
                },
                Transition {
                    from: "*"
                    to: "State2"
                    NumberAnimation {
                        easing.type: Easing.InOutQuad
                        properties: "x,y"
                        duration: 2000
                    }
                },
                Transition {
                    NumberAnimation {
                        properties: "x,y"
                        duration: 200
                    }
                }
            ]
        }


        InputPanel {
            id: inputPanel
            z: 99
            x: 0
            y: 272
            width: root.width

            states: State {
                name: "visible"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: root.height - inputPanel.height
                }
            }
            transitions: Transition {
                from: ""
                to: "visible"
                reversible: true
                ParallelAnimation {
                    NumberAnimation {
                        properties: "y"
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                }
            }
        }
}

