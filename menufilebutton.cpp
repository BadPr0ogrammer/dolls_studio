#include <QQuickWindow>

#include "menufilebutton.h"
#include "vtkitem.h"
#include "sysdlgs.h"
#include "mainview.h"

using namespace  DS;

MenuFileButton::MenuFileButton(const QString& text, QQuickItem* parent)
    : QskPushButton(text, parent)
{
    connect(this, &QskPushButton::pressed, this, &MenuFileButton::openMenu);
    MainView *mv = (MainView *) parent->parent();
    _fileDlg = new FileDlg(mv->_vtk);
}

void MenuFileButton::openMenu()
{
    _menu = new QskMenu(window()->contentItem());

    populateMenu(_menu);

    _menu->setOrigin(geometry().bottomLeft());
    _menu->open();
}

void MenuFileButton::populateMenu(QskMenu* menu)
{
    menu->addOption("", "Open");
    menu->addOption("", "Close");
    menu->addOption("", "Animate");
    menu->addOption("", "Quit");
    connect(menu, &QskMenu::triggered, [this](int index) {
        switch (index) {
        case 0:
            openFile();
            break;
        case 1:
            closeFile();
            break;
        case 2: animateFile();
            break;
        case 3: qApp->quit();
            break;
        }
    });
}

void MenuFileButton::openFile()
{
    _fileDlg->openFileDlg();
}

void MenuFileButton::closeFile()
{
    MainView *mv = (MainView *) parent()->parent();
    mv->_vtk->close();
}

void MenuFileButton::animateFile()
{
    MainView *mv = (MainView *) parent()->parent();
    mv->_vtk->play();
}
