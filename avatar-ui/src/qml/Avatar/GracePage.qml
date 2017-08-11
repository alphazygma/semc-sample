import QtQuick 2.7
import QtQuick.Controls 2.0 as QQ2
import "../Style"
import "avatars.js" as AvatarData

Item {
    id: avatarView
    property string avatarId: 'grace'

    QQ2.SwipeView {
        id: vsAvatarContainer

        anchors.fill: parent

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

    QQ2.PageIndicator {
        count: vsAvatarContainer.count
        currentIndex: vsAvatarContainer.currentIndex

        anchors.bottom: vsAvatarContainer.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
