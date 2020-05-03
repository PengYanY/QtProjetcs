import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import Davis.qml.Controls 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QPainter")
    TextInput{
        id:tranPos
        anchors.left : parent.left
        anchors.top : parent.top
        width:60
        height:20
        anchors.topMargin: 10
        anchors.leftMargin: 10
        color:"black"
        text: "200,200"
        Rectangle{
            anchors.fill:parent
            border.color: "black"
            color:"transparent"
        }
    }

    TextInput{
        id:rote
        anchors.left : parent.left
        anchors.top : tranPos.bottom
        anchors.topMargin: 10
        anchors.leftMargin:10
        width:60
        height:20
        color:"black"
        text: "30"
        Rectangle{
            anchors.fill:parent
            border.color: "black"
            color:"transparent"
        }
    }

    TextInput{
        id:showScale
        anchors.left : parent.left
        anchors.top : rote.bottom
        anchors.topMargin: 10
        anchors.leftMargin:10
        width:60
        height:20
        color:"black"
        text: "1"
        Rectangle{
            anchors.fill:parent
            border.color: "black"
            color:"transparent"
        }
    }

    Rectangle{
        anchors.top:showScale.bottom
        anchors.left : parent.left
        border.color: "black"
        color:"transparent"
        anchors.topMargin: 10
        anchors.leftMargin:20
        Text{
            anchors.centerIn: parent
            text:"确定"
        }
        width:40
        height:20
        MouseArea{
            anchors.fill:parent
            onClicked: {
                myPainter.originCoord = tranPos.text
                myPainter.rote = Number(rote.text)
                myPainter.showScale = Number(showScale.text)
                //console.log("helladafas")
            }
        }
    }

    Rectangle{
        width:460
        height:460
        border.color: "green"
        anchors.centerIn: parent

        MyPainterItem{
            id: myPainter
            //originCoord:Qt.point(parent.width/2,parent.height/2)
            //originCoord:"0,0"
            anchors.fill:parent
        }
    }
}
