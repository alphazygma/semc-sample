import QtQuick 2.7
import QtQuick.Controls 2.0 as QQ2
import "../Style"
import "avatars.js" as AvatarData

/**
 * Hero Component that will show Two pages through a swipe displaing a banner of the selected
 * hero and few details about it.
 * NOTE: The Style directory files used are directly used from the QT tutorial
 *
 * NOTICE: Need to figure out a way to centralize this Hero specific Page into a generic
 * AvatarPage.qml file, since it virutally is identical to every other hero qml file with
 * the one exception of the property `avatarId`.
 * This is because I couldn't manage to get the index on the LauncherPage for the button that
 * called this instance.
 * Once I can retrieve such index, then all Hero Page.qml files can be reduced to one file and
 * remove duplicated code.
 *
 * @author Alejandro B. Salazar
 */
Item {
    id: avatarView

    // This is the property used to circumvent the issue of getting the caller button's index
    property string avatarId: 'skaarf'

    // This component is what generate the pages with a swipe motion
    QQ2.SwipeView {
        id: vsAvatarContainer

        anchors.fill: parent

        // First element will automatically become the first page
        Item {
            id: avatarPage1

            Row {
                spacing: 15

                Image {
                    source: AvatarData.getImage(avatarView.avatarId)
                }

                Column {
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("Name: ") + AvatarData.getName(avatarView.avatarId)
                        font.italic: true
                        font.pixelSize: UIStyle.fontSizeM
                        color: UIStyle.colorQtGray1
                    }
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("Role: ") + AvatarData.getRole(avatarView.avatarId)
                        font.pixelSize: UIStyle.fontSizeS
                        font.italic: true
                        color: UIStyle.colorQtGray3
                    }
                }

            }
        }

        // Second element will automatically become the second page
        Item {
            id: avatarPage2

            Row {
                spacing: 15

                Image {
                    source: AvatarData.getImage(avatarView.avatarId)
                }

                Column {
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("Offense: ") + AvatarData.getOffense(avatarView.avatarId)
                        font.italic: true
                        font.pixelSize: UIStyle.fontSizeS
                        color: UIStyle.colorQtGray3
                    }
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("Difficulty: ") + AvatarData.getDifficulty(avatarView.avatarId)
                        font.pixelSize: UIStyle.fontSizeS
                        font.italic: true
                        color: UIStyle.colorQtGray3
                    }
                }

            }
        }
    }

    // This component is where the number of pages is displayed and which is active
    QQ2.PageIndicator {
        count: vsAvatarContainer.count
        currentIndex: vsAvatarContainer.currentIndex

        anchors.bottom: vsAvatarContainer.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
