#include "mainview.h"

MainView::MainView(QQuickItem* parent)
{
    _vtk = new VtkItem();
    //_menu = new QskMenu(this);
    //_btnOpen = new QskPushButton(this);

    //setHeader(_menu);
    QskControl* vtki = reinterpret_cast<QskControl*>(_vtk);
    setBody(vtki);

    //connect(_btnOpen, &QskPushButton::pressed, this, &MainView::openMenu );
}

MainView::~MainView()
{
    delete _vtk;
}

void MainView::openMenu()
{

}
