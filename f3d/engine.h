#ifndef F3D_ENGINE_H
#define F3D_ENGINE_H

#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>

#include "vtkF3DAssimpImporter.h"
#include "vtkF3DRenderer.h"

namespace DollsStudio
{

class f3d_engine
{
public:
    vtkSmartPointer<vtkRenderWindow> RenWin;
    vtkNew<vtkF3DRenderer> Renderer;
    vtkNew<vtkF3DAssimpImporter> AssimpImporter;

    f3d_engine();
    ~f3d_engine();
};

}
#endif // F3D_ENGINE_H
