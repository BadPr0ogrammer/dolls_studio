#pragma once

#include <QQuickVTKItem.h>

#include <QString>
#include <QTimer>

#include <vtkNew.h>
#include <vtkObject.h>
#include <vtkObjectFactory.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCallbackCommand.h>
#include <vtkRenderTimerLog.h>
#include <vtkProgressBarWidget.h>

#include "vtkF3DMetaImporter.h"
#include "vtkF3DRenderer.h"
#include "vtkF3DAssimpImporter.h"

#include "animationManager.h"
#include "window_impl.h"
#include "scene_impl.h"
#include "options.h"

namespace DS {
struct VtkItem : QQuickVTKItem
{
    Q_OBJECT
public:
    struct Data : vtkObject
    {
        static Data* New();
        vtkTypeMacro(Data, vtkObject);
        struct VtkItem*                     _vtkItem = nullptr;

        f3d::detail::window_impl*           _win = nullptr;
        f3d::detail::scene_impl*            _scene = nullptr;

        vtkSmartPointer<vtkCallbackCommand> _timer1;
    };    
    QString _fname;
    f3d::options _options;    
    QTimer _timer2;
    
    VtkItem();

    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;
    void destroyingVTK(vtkRenderWindow* renderWindow, vtkUserData userData) override;

    bool openSource();
    void close();
    void play();
public slots:
    void timerSlot();
};
}
