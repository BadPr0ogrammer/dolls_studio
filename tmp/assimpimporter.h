/*
#pragma once

#include <string>
#include <vtkImporter.h>
#include <vtkF3DAssimpImporter.h>

namespace DS
{
class AssimpImporter : public vtkF3DAssimpImporter
{
public:
    static AssimpImporter* New();
    vtkTypeMacro(AssimpImporter, vtkF3DAssimpImporter);

    int ImportBegin() override;
    void ImportActors(vtkRenderer* render) override;
    UpdateStatusEnum GetUpdateStatus();
    bool UpdateStatus();
    bool UpdateAtTimeValue(double timeValue) override;
    vtkIdType GetNumberOfAnimations() override;
    std::string GetAnimationName(vtkIdType animationIndex) override;
    void EnableAnimation(vtkIdType animationIndex) override;
};
}
*/
