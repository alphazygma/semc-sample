import QtQuick 2.7
import QtQuick.Controls 2.0 as QQC2
import "Style"

/**
 * The initial component that will display some of the heroes in a spin wheel so that once
 * in the center, they can be selected and a few more details are shown.
 * NOTE  : It is mostly based on the wearable QT Tutorial
 * NOTE 2: The Style directory and NaviButton.qml files used are directly used
 *         from the QT tutorial
 *
 * @author Alejandro B. Salazar
 */
PathView {
    id: circularView

    signal launched(string page)

    readonly property int size: Math.min(width - 80, height)
    readonly property int centerX: width / 2
    readonly property int centerY: height / 2
    readonly property int itemSize: size / 4
    readonly property int radius: size / 2 - itemSize / 3

    snapMode: PathView.SnapToItem

    // Creating the Circular elements that show the heroes
    // @TODO: Figure out how to use one AvatarPage.qml instead of separate hero
    //        specific qmls, since the QMLs are virtually identical save one
    //        property used to identify the hero.
    //        Couldn't manage to get the index of this element from within the
    //        <Hero>Page.qml to avoid code duplication.
    model: ListModel {
        ListElement {
            title: qsTr("Alpha")
            icon: "../avatars/alpha.png"
            page: "Avatar/AlphaPage.qml"
        }
        ListElement {
            title: qsTr("Ardan")
            icon: "../avatars/ardan.png"
            page: "Avatar/ArdanPage.qml"
        }
        ListElement {
            title: qsTr("Idris")
            icon: "../avatars/idris.png"
            page: "Avatar/IdrisPage.qml"
        }
        ListElement {
            title: qsTr("Rona")
            icon: "../avatars/rona.png"
            page: "Avatar/RonaPage.qml"
        }
        ListElement {
            title: qsTr("Grace")
            icon: "../avatars/grace.png"
            page: "Avatar/GracePage.qml"
        }
        ListElement {
            title: qsTr("Skaarf")
            icon: "../avatars/skaarf.png"
            page: "Avatar/SkaarfPage.qml"
        }
    }

    delegate: QQC2.AbstractButton {
        width: circularView.itemSize
        height: circularView.itemSize

        text: model.title
        opacity: PathView.itemOpacity
        padding: 3

        contentItem: Image {
            source: model.icon
            fillMode: Image.Stretch
            sourceSize.width: parent.availableWidth
            sourceSize.height: parent.availableHeight
        }

        background: Rectangle {
            radius: width / 2
            border.width: 3
            border.color: parent.PathView.isCurrentItem ? UIStyle.colorQtPrimGreen : UIStyle.colorQtGray4
        }

        onClicked: {
            if (PathView.isCurrentItem) {
                circularView.launched(Qt.resolvedUrl(page))

            } else {
                circularView.currentIndex = index
            }
        }
    }

    path: Path {
        startX: circularView.centerX
        startY: circularView.centerY
        PathAttribute {
            name: "itemOpacity"
            value: 1.0
        }
        PathLine {
            x: circularView.centerX + circularView.radius
            y: circularView.centerY
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.7
        }
        PathArc {
            x: circularView.centerX - circularView.radius
            y: circularView.centerY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.5
        }
        PathArc {
            x: circularView.centerX + circularView.radius
            y: circularView.centerY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.3
        }
    }

    Text {
        id: appTitle

        property Item currentItem: circularView.currentItem

        visible: currentItem ? currentItem.PathView.itemOpacity === 1.0 : 0

        text: currentItem ? currentItem.text : ""
        anchors.centerIn: parent
        anchors.verticalCenterOffset: (circularView.itemSize + height) / 2

        font.bold: true
        font.pixelSize: circularView.itemSize / 3
        font.letterSpacing: 1
        color: UIStyle.colorQtGray1
    }
}
