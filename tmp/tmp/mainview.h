#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "vtkitem.h"
#include "mainheader.h"

namespace DS
{

class MainView : public QskMainView
{
    Q_OBJECT
public:
    MainView(QQuickItem* parent = nullptr);
    ~MainView();

    VtkItem*    m_vtk = nullptr;
    MainHeader* m_header = nullptr;

public slots:
    void openFile();
    void startAnim();
};

}
#endif
