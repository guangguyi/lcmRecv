import QtQuick 2.8
import QtQuick.Controls 2.2

Rectangle {
    id: mainItem
    width: 800
    height: 480
    color: "white"
//    Image {
//        id: backgroud
//        z: 0
//        source: "qrc:/image/image/background.png"
//    }

    Text {
        id: channelName
        x: 55
        y: 35
        font.pixelSize: 25
        text: "Received message on channel = " + LcmDataParse.channelName
    }
    Text {
        id: timestamp
        x: 55
        y: 75
        font.pixelSize: 25
        text: "timestamp = " + LcmDataParse.timestamp
    }
    Text {
        id: position
        x: 55
        y: 115
        font.pixelSize: 25
        text: "position = " + LcmDataParse.position
    }
    Text {
        id: orientation
        x: 55
        y: 155
        font.pixelSize: 25
        text: "orientation = " + LcmDataParse.orientation
    }
    Text {
        id: numRanges
        x: 55
        y: 195
        font.pixelSize: 25
        text: "numRanges = " + LcmDataParse.numRanges
    }
    Text {
        id: nameString
        x: 55
        y: 235
        font.pixelSize: 25
        text: "name string = " + LcmDataParse.names
    }
    Text {
        id: enables
        x: 55
        y: 275
        font.pixelSize: 25
        text: "enables = " + LcmDataParse.enabled
    }
    Rectangle {
        id: one
        x: 55
        y: 35
        width: 550
        height: 400
        color: "white"
        clip: true
        transform: Rotation {
            id: ringDownRotation
            origin.x: 263
            origin.y: 185
            angle: 180
            Behavior on angle { SpringAnimation { spring: 2; damping: 0.3 } }
        }
    }
    SequentialAnimation {
        id: test
        NumberAnimation {
            running: false
            target: one
            property: "width"
            from: 500
            to: 0
            duration: 1000
            easing.type: Easing.InOutQuad
        }
        ScriptAction {
            script: {
                controlBu.opacity = 1
            }
        }
    }

//    Column {
//        anchors.top: mainItem.top
//        anchors.topMargin: 25
//        anchors.left: mainItem.left
//        anchors.leftMargin: 10
//        spacing: 15
//        Text {
//            font.pixelSize: 25
//            text: "Received message on channel = : " + LcmDataParse.channelName
//        }
//        Text {
//            font.pixelSize: 25
//            text: "timestamp = : " + LcmDataParse.timestamp
//        }
//        Text {
//            font.pixelSize: 25
//            text: "position = : " + LcmDataParse.position
//        }
//        Text {
//            font.pixelSize: 25
//            text: "orientation = : " + LcmDataParse.orientation
//        }
//        Text {
//            font.pixelSize: 25
//            text: "numRanges = : " + LcmDataParse.numRanges
//        }
//        Text {
//            font.pixelSize: 25
//            text: "name string = : " + LcmDataParse.names
//        }

//        Text {
//            font.pixelSize: 25
//            text: "enables : " + LcmDataParse.enabled
//        }
//    }

    Button {
        id: controlBu
        opacity: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        text: checked ? "stop" : "start"
        checkable: true
        onCheckedChanged: {
            LcmDataParse.setLcmDataRecvState(checked);
        }
    }
    Component.onCompleted: {
        test.running = true
    }
}
