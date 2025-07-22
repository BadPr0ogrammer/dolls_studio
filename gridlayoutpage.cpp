#include "gridlayoutpage.h"
#include "listboxpage.h"

#include <QskRgbValue.h>
#include <QskGridBox.h>

#include "vtkitem.h"
#include "mainview.h"

using namespace DS;

GridLayoutPage::GridLayoutPage(QQuickItem* parent)
    : QskControl(parent)
{
    setMargins(10);
    setBackgroundColor(QskRgb::LightGray);

    setAutoLayoutChildren(true);

    _grid = new QskGridBox(this);
    _grid->addItem(new ListBoxPage, 0, 0, 0, 0);

    MainView *mainView = (MainView *) parent;
    mainView->_vtk->setParent(this);
    _grid->addItem(mainView->_vtk, 0, 1, 0, 3);

    //grid->setColumnStretchFactor(1, 2);
}
