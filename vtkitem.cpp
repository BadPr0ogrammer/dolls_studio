#include "vtkitem.h"
#include "engine.h"

#include <optional>
#include <vector>

#include <vtkCallbackCommand.h>
#include <vtkProgressBarRepresentation.h>
#include <vtkProgressBarWidget.h>
#include <vtkTimerLog.h>
#include <vtkVersion.h>
#include <vtksys/SystemTools.hxx>
#include <vtkRendererCollection.h>
#include <vtkNamedColors.h>
#include <vtkActorCollection.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>

#include <QQuickWindow>
#include <QQuickGraphicsDevice>
#include <QOpenGLContext>
#include <QQuickPaintedItem>
#include <QOpenGLFunctions>

using namespace DollsStudio;

vtkStandardNewMacro(VtkItem::Data)

namespace fs = std::filesystem;


VtkItem::vtkUserData VtkItem::initializeVTK(vtkRenderWindow* renderWindow)
{    
    vtkNew<Data> vtk;

    vtk->m_engine = std::make_unique<f3d_engine>();

    vtkNew<vtkActor> actor;
    vtk->m_engine->Renderer->AddActor(actor);
    vtk->m_engine->Renderer->ResetCamera();
    vtk->m_engine->Renderer->SetBackground(1,1,1);

    renderWindow->AddRenderer(vtk->m_engine->Renderer);

    return vtk;
}

void VtkItem::openSource(QString fname)
{
    m_fname = fname;
    dispatch_async([this](vtkRenderWindow* renderWindow, vtkUserData userData)
    {            
        Data* vtk = (Data*)userData.GetPointer();

        vtk->m_engine->AssimpImporter->SetFileName(m_fname.toStdString());
        vtk->m_engine->AssimpImporter->ImportBegin();
        vtk->m_engine->AssimpImporter->ImportActors(vtk->m_engine->Renderer);

        vtk->m_engine->Renderer->ResetCamera();
        vtk->m_engine->Renderer->SetBackground(1,1,1);

        renderWindow->AddRenderer(vtk->m_engine->Renderer);
    });
}

void VtkItem::startAnim()
{
}
