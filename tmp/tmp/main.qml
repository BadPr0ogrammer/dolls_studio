import QtQuick
import QtQuick.Controls

import Qt.labs.platform as Platform

import Dolls.studio 1.0

ApplicationWindow
{
    width: 640
    height: 480
    visible: true
    title: "Dolls.studio"

    required property Manager projectManager
    property alias openProjectDialog: openProjectDialog

    // If we set the image URL immediately, it can happen before
    // the error popup is ready.
    Component.onCompleted: {
        contentItem.parent.objectName = "applicationWindowRootItem"
        contentItem.objectName = "applicationWindowContentItem"
        if (settings.loadLastOnStartup && settings.recentFiles.length > 0) {
            loadProject(settings.recentFiles[0])
        }
    }

    StackView {
        anchors.fill: parent
        VtkItem {
            objectName: "vtkItem"
            anchors.fill: parent
        }
    }
    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
                text: qsTr("&Open...")
                onTriggered: openProjectDialog.open()
            }
            MenuSeparator { }
            Action {
                text: qsTr("&Quit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("&Animation")
            Action {
                onTriggered: projectManager.playFlag();
            }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }
    Platform.FileDialog {
        id: openProjectDialog
        objectName: "openProjectDialog"        
        nameFilters: ["FBX files (*.fbx)","All files (*)"]
        onAccepted: projectManager.openSource(file);
    } 
}
