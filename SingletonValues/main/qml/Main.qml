import QtQuick
import SingletonClass

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Singleton type")

    property var myApi: SingletonClass

    Rectangle {
        id: rectId
        width: 200
        height: 200
        radius: 10
        color: "red"
        Text {
            id: textId
            anchors.centerIn: parent
            font.pointSize: 30
            text: myApi.someProperty
        }
    }

    Rectangle {
        id: rect2Id
        width: 200
        height: 200
        radius: 10
        anchors.left: rectId.right
        anchors.leftMargin: 20
        color: "blue"

        Text {
            id: text2Id
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 30
            text: myApi.someProperty
        }
    }
}
