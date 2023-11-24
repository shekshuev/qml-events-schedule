import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.12
import ru.afso 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello")
    color: Material.background

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

            Layout.fillWidth: true
            anchors {
                top: parent.top
                bottom: bottomPane.top
            }

            ListView {
                id: view
                anchors.margins: 10
                anchors.fill: parent
                spacing: 10
                model: eventModel
                focus: true

                delegate: Pane {
                    width: view.width
                    height: 100
                    Material.elevation: 3

                    ColumnLayout {
                        Text {
                            Layout.fillWidth: true
                            renderType: Text.NativeRendering
                            text: model.title
                        }
                    }


                }
            }

        }

        Pane {
            id: bottomPane
            Layout.fillWidth: true
            height: 100
            anchors {
                bottom: parent.bottom
            }

            ColumnLayout {



                TextField {
                    id: textEntry
                    Layout.fillWidth: true
                    color: Material.primary
                }

                Button {
                    onClicked: function() {
                        view.decrementCurrentIndex()

                        print(textEntry.text)
                        eventModel.append(textEntry.text);
                    }
                }
            }
        }

    }

}
