#include "engine.h"

#include "vtkF3DGLXRenderWindow.h"
#include "vtkF3DGenericImporter.h"
#include "vtkF3DAssimpImporter.h"
#include "vtkF3DRenderer.h"

using namespace DollsStudio;

f3d_engine::f3d_engine()
{
#ifdef VTK_USE_X
    RenWin = vtkSmartPointer<vtkF3DGLXRenderWindow>::New();
#elif _WIN32
    RenWin = vtkSmartPointer<vtkF3DWGLRenderWindow>::New();
#endif
}

f3d_engine::~f3d_engine()
{
}
