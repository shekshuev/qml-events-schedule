import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import ru.afso 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello")

    EventListModel {
        id: eventModel
        onCountChanged: {
            print('new count: ' + eventModel.count)
            print('last entry: ' + eventModel.get(eventModel.count - 1))
        }
    }


    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8

        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            ListView {
                id: view

                anchors.margins: 10
                anchors.fill: parent
                spacing: 10
                model: EventListModel {}
                focus: true

                delegate: Rectangle {
                    width: view.width
                    height: 100
                    color: model.name

                    Text {
                        anchors.centerIn: parent
                        renderType: Text.NativeRendering
                        text: 'hsv(' +
                              Number(model.hue).toFixed(2) + ',' +
                              Number(model.saturation).toFixed() + ',' +
                              Number(model.brightness).toFixed() + ')'
                    }
                }
            }

        }

        RowLayout {
            TextField {
                id: textEntry
            }
            Button {
                onClicked: function() {
                    eventModel.append(textEntry.text);
                }
            }
        }

    }

}
