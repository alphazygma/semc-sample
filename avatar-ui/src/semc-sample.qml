import QtQuick 2.7
import QtQuick.Controls 2.0 as QQC2
import "qml"
import "qml/Style"

/**
 * The main component that will initialize the display window.
 * NOTE  : It is mostly based on the wearable QT Tutorial
 * NOTE 2: The Style directory and NaviButton.qml files used are directly used
 *         from the QT tutorial
 *
 * @author Alejandro B. Salazar
 */
QQC2.ApplicationWindow {
    id: window

    visible: true

    width: 512
    height: 512

    title: qsTr("SEMC Sample")

    background: Image {
        source: "images/background.png"
    }

    header: NaviButton {
        id: homeButton

        edge: Qt.TopEdge
        enabled: stackView.depth > 1
        imageSource: "images/home.png"

        onClicked: stackView.pop(null)
    }

    footer: NaviButton {
        id: backButton

        edge: Qt.BottomEdge
        enabled: stackView.depth > 1
        imageSource: "images/back.png"

        onClicked: stackView.pop()
    }

    QQC2.StackView {
        id: stackView

        focus: true
        anchors.fill: parent

        initialItem: LauncherPage {
            onLaunched: stackView.push(page)
        }
    }
}
