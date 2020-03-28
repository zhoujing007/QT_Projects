import QtQuick 2.6
import QtQuick.Window 2.2

//Item {
//    width: 200
//    height: 200

//    Rectangle {
//        id: rect
//        width: 100
//        color: "blue"
//    }

//    Component.onCompleted: {
//        rect.height = Qt.binding(function() { return this.width * 2 })
//        console.log("rect.height = " + rect.height) // 打印 200, 而非 400
//    }


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }
    MouseArea {
          anchors.fill: parent
          onClicked: {
              Qt.quit();
          }
      }
      Text {
          text: qsTr("Hello World")
          anchors.centerIn: parent
      }
      Image { source: "123" }
}
