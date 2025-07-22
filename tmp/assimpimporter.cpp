/*
#include <vtkObjectFactory.h>

#include <vtkF3DImporter.h>
#include "assimpimporter.h"

vtkStandardNewMacro(DS::AssimpImporter);

using namespace DS;

int AssimpImporter::ImportBegin()
{
    return vtkF3DAssimpImporter::ImportBegin();
}

void AssimpImporter::ImportActors(vtkRenderer* render)
{
    vtkF3DAssimpImporter::ImportActors(render);
}

vtkImporter::UpdateStatusEnum AssimpImporter::GetUpdateStatus()
{
    return vtkF3DAssimpImporter::GetUpdateStatus();
}

bool AssimpImporter::UpdateStatus()
{
    return vtkF3DAssimpImporter::GetUpdateStatus() == vtkImporter::UpdateStatusEnum::SUCCESS;
}

bool AssimpImporter::UpdateAtTimeValue(double timeValue)
{
    return vtkF3DAssimpImporter::UpdateAtTimeValue(timeValue);
}

vtkIdType AssimpImporter::GetNumberOfAnimations()
{
    return vtkF3DAssimpImporter::GetNumberOfAnimations();
}

std::string AssimpImporter::GetAnimationName(vtkIdType animationIndex)
{
    return vtkF3DAssimpImporter::GetAnimationName(animationIndex);
}

void AssimpImporter::EnableAnimation(vtkIdType animationIndex)
{
    vtkF3DAssimpImporter::EnableAnimation(animationIndex);
}
*/
