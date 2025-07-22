#include "engine.h"

#include <QDebug>

#include <vtkPlaneSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkTransform.h>
#include <vtkCommand.h>
#include <vtkNamedColors.h>
#include <vtkProgressBarRepresentation.h>
#include <vtkObjectFactory.h>
#include <vtkProperty.h>

#include "vtkitem.h"

void f3d_engine::setup(vtkRenderWindow* renderWindow)
{
    //m_renderer->Initialize();
    //m_renderer->SetImporter(m_metaImporter);
    //m_metaImporter->SetRenderWindow(_renWin);
    //m_metaImporter->AddImporter(m_assimpImporter);

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
    vtkNew<vtkNamedColors> colors;
    actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

    m_renderer->AddActor(actor);
    m_renderer->SetBackground(colors->GetColor3d("White").GetData());

    //m_renderer->ResetCamera();
    //m_renderer->ResetCameraScreenSpace(0.9);

    //CreateProgressRepresentationAndCallback();
    //m_vtk->setProperty("width", m_vtk->m_parent->width());
    //m_vtk->setProperty("height", m_vtk->m_parent->height());

    //m_timerCallback->m_vtk = m_vtk;
    //m_timerInteractor->SetRenderWindow(renderWindow);
    //renderWindow->GetInteractor()->AddObserver(vtkCommand::TimerEvent, m_timerCallback);
    //renderWindow->GetInteractor()->CreateRepeatingTimer(1);
}

/* in async
void f3d_engine::sceneClear()
{
    // Clear the meta importer from all importers
    m_metaImporter->Clear();
    // Clear the window of all actors
    m_renderer->Initialize();
}
*/
bool f3d_engine::importFile(QString fname)
{
    bool ret = false;
    m_assimpImporter->SetFileName(fname.toStdString());

    if (m_assimpImporter->ImportBegin()) {
        m_assimpImporter->ImportActors(m_renderer);
        ret = true;
    }
    m_renderer->ResetCamera();
    m_renderer->SetBackground(1,1,1);
    return ret;
}

