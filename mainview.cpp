#include "mainview.h"
#include "tabview.h"
#include "header.h"
#include "gridlayoutpage.h"
#include "menufilebutton.h"
#include "sysdlgs.h"

#include "vtkitem.h"

using namespace DS;

MainView::MainView(QQuickItem* parent) : QskMainView(parent)
{
    _vtk = new VtkItem;

    _tabView = new TabView(this);
    setBody(_tabView);

    _grid = new GridLayoutPage(this);
    _tabView->addPage("Model", _grid);

    _header = new Header(_tabView->count(), this);
    setHeader(_header);

    connect(_header, &Header::enabledToggled, _tabView, &TabView::setPagesEnabled );
    connect(_tabView, &TabView::currentIndexChanged, _header, &Header::setCurrentTab );
}
