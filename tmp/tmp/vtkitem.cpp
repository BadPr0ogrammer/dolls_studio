#include "vtkitem.h"

using namespace DS;

vtkStandardNewMacro(VtkItem::Data)

namespace fs = std::filesystem;

VtkItem::VtkItem()
{
}

VtkItem::vtkUserData VtkItem::initializeVTK(vtkRenderWindow* renderWindow)
{    
    vtkNew<Data> vtk;

    m_engine.setup(renderWindow);
    renderWindow->AddRenderer(m_engine.m_renderer);
    return vtk;
}

void VtkItem::openSource(QString fname)
{
    m_fname = fname;
    dispatch_async([this](vtkRenderWindow* renderWindow, vtkUserData userData)
    {            
        Data* vtk = (Data*)userData.GetPointer();

        //m_engine.sceneClear();
        m_engine.importFile(m_fname);
        renderWindow->AddRenderer(m_engine.m_renderer);
    });
}

void VtkItem::startAnim()
{
}
