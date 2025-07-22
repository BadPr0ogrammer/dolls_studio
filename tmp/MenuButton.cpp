#include <QQuickWindow>

#include "MenuButton.h"
#include "vtkitem.h"
#include "sysdlgs.h"
#include "MainView.h"

using namespace  DS;

MenuButton::MenuButton(const QString& text, QQuickItem* parent)
    : QskPushButton(text, parent)
{
    connect(this, &QskPushButton::pressed, this, &MenuButton::openMenu);
    m_fileDlg = new FileDlg();
}

void MenuButton::openMenu()
{
    m_menu = new QskMenu(window()->contentItem());

    populateMenu(m_menu);

    m_menu->setOrigin(geometry().bottomLeft());
    m_menu->open();
}

void MenuButton::populateMenu(QskMenu* menu)
{
    menu->addOption("", "Open");
    menu->addOption("", "Quit");
    connect(menu, &QskMenu::triggered, [this](int index) {
        switch (index) {
        case 0:
            openFile();
            break;
        case 1: qApp->quit();
            break;
        }
    });
}

void MenuButton::openFile()
{
    m_fileDlg->createFileDlg();
}
