#pragma once

#include <QQuickItem>

#include <QskMainView.h>

namespace DS
{
class VtkItem;
class TabView;
class GridLayoutPage;
class Header;
class MainView : public QskMainView
{
    Q_OBJECT
public:
    MainView(QQuickItem* parent = nullptr);

    VtkItem*        _vtk = nullptr;
    TabView*        _tabView = nullptr;
    GridLayoutPage* _grid = nullptr;
    Header*         _header = nullptr;
};

}
