#include "vtkitem.h"

#include "vtkF3DAssimpImporter.h"

#include <QQuickWindow>

#include <vtkRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRendererCollection.h>

using namespace DS;

vtkStandardNewMacro(VtkItem::Data)
//vtkStandardNewMacro(VtkItem::TimerCallback)

VtkItem::vtkUserData VtkItem::initializeVTK(vtkRenderWindow* renderWindow)
{    
    vtkNew<Data> vtk;
    vtk->m_vtk = this;

    vtkRenderer* renderer = renderWindow->GetRenderers()->GetFirstRenderer();
    if (renderer == nullptr) {
        renderer = vtkRenderer::New();
        renderWindow->AddRenderer(renderer);
    }

    vtkNew<vtkNamedColors> colors;
    std::array<unsigned char, 4> bkg{{255, 255, 255, 255}};
    colors->SetColor("BkgColor", bkg.data());
    renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());

    //renderer->Register(vtk->m_importer);
    //vtk->m_importer->SetRenderWindow(renderWindow);
    /*
    vtkNew<TimerCallback> tcb;
    tcb->m_vtk = this;

    renderWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, tcb);
    renderWindow->GetInteractor()->CreateRepeatingTimer(10);
    */
    return vtk;
}

void VtkItem::destroyingVTK(vtkRenderWindow* renderWindow, vtkUserData userData)
{
    auto* vtk = Data::SafeDownCast(userData);
    vtk->m_importer->Delete();
}

bool VtkItem::openSource(const QUrl url)
{
    QString fname = url.fileName();
    dispatch_async([&](vtkRenderWindow* renderWindow, vtkUserData userData)
    {            
        Data* vtk = (Data*)userData.GetPointer();
        //m_engine.sceneClear();
        bool ret = false;
        vtk->m_importer->SetFileName(fname.toStdString());
        if (vtk->m_importer->ImportBegin()) {
            vtkRenderer* renderer = renderWindow->GetRenderers()->GetFirstRenderer();
            vtk->m_importer->ImportActors(renderer);

            vtk->m_importer->EnableAnimation(0);
            renderer->ResetCamera();
            ret = true;
        }
        return ret;
    });
    return false;
}
/*
void VtkItem::TimerCallback::Execute(vtkObject* caller, unsigned long, void*data)
{
    if (m_vtk && m_vtk->m_play)
    {
        m_vtk->dispatch_async([this](vtkRenderWindow* renderWindow, vtkUserData userData)
        {
            Data* vtk = (Data*)userData.GetPointer();
            m_vtk->m_timeValue += 1.0 / 30.0;
            vtk->m_importer->UpdateAtTimeValue(m_vtk->m_timeValue);
            renderWindow->Render();
        });
    }
}
*/

/* in async
void f3d_engine::sceneClear()
{
    // Clear the meta importer from all importers
    m_metaImporter->Clear();
    // Clear the window of all actors
    m_renderer->Initialize();
}
*/

//m_renderer->Initialize();
//m_renderer->SetImporter(m_metaImporter);
//m_metaImporter->SetRenderWindow(_renWin);
//m_metaImporter->AddImporter(m_assimpImporter);

//m_renderer->ResetCamera();
//m_renderer->ResetCameraScreenSpace(0.9);

//CreateProgressRepresentationAndCallback();
//m_vtk->setProperty("width", m_vtk->m_parent->width());
//m_vtk->setProperty("height", m_vtk->m_parent->height());

//m_timerCallback->m_vtk = m_vtk;
//m_timerInteractor->SetRenderWindow(renderWindow);
//renderWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, m_timerCallback);
//renderWindow->GetInteractor()->CreateRepeatingTimer(1);
/*
    vtkNew<vtkPlaneSource> planeSource;
    planeSource->SetCenter(0.0, 0.0, 0.0);
    planeSource->SetNormal(0.0, 1.0, 0.0);
    planeSource->Update();
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputData(planeSource->GetOutput());
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    vtkNew<vtkTransform> transform;
    transform->Scale(200, 200, 200);
    actor->SetUserTransform(transform);

    actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
    vtk->m_renderer->AddActor(actor);
    renderWindow->AddRenderer(vtk->m_renderer);
*/
