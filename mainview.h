#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QskMainView.h>
#include <QskMenu.h>
#include <QskPushButton.h>

#include "vtkitem.h"

class MainView : public QskMainView
{
    Q_OBJECT
public:
    MainView(QQuickItem* parent = nullptr);
    ~MainView();

    void openMenu();

    VtkItem*        _vtk;
    QskMenu*        _menu;
    QskPushButton*  _btnOpen;
};

#endif
