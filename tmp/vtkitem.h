#pragma once

#include <QQuickVTKItem.h>

#include <QString>

#include <vtkNew.h>
#include <vtkObject.h>
#include <vtkObjectFactory.h>
#include <vtkRenderer.h>
#include <vtkCommand.h>

#include "vtkF3DAssimpImporter.h"

namespace DS {

struct VtkItem : QQuickVTKItem
{
    Q_OBJECT
public:  
    struct Data : vtkObject
    {
        static Data* New();
        vtkTypeMacro(Data, vtkObject);
        vtkNew<vtkF3DAssimpImporter> m_importer;

        struct VtkItem* m_vtk = nullptr;
    };
    /*
    struct TimerCallback : vtkCommand
    {
        static TimerCallback* New();
        vtkTypeMacro(TimerCallback, vtkCommand);
        virtual void Execute(vtkObject* caller, unsigned long evId, void* data) override;

        struct VtkItem* m_vtk = nullptr;
    };
    */
    double m_timeValue = 0;
    bool m_play = false;

    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;
    void destroyingVTK(vtkRenderWindow* renderWindow, vtkUserData userData) override;

    bool openSource(const QUrl url);
    bool UpdateAtTimeValue(double timeValue, vtkF3DAssimpImporter *importer);
};

}

