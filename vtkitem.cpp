#include "scene.h"
#include "window.h"

#include "engine.h"
#include "scene_impl.h"
#include "window_impl.h"

#include "animationManager.h"
#include "interactor_impl.h"
#include "log.h"
#include "options.h"
#include "factory.h"

#include "vtkF3DGenericImporter.h"
#include "vtkF3DMemoryMesh.h"
#include "vtkF3DMetaImporter.h"
#include "vtkF3DAssimpImporter.h"

#include "vtkitem.h"

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

using namespace DollsStudio;

vtkStandardNewMacro(VtkItem::Data)

namespace fs = std::filesystem;

namespace f3d
{
class engine::internals
{
public:
    template<typename F>
    static bool BackendAvailable(F&& func);

    std::unique_ptr<options> Options;
    std::unique_ptr<detail::window_impl> Window;
    std::unique_ptr<detail::scene_impl> Scene;
    std::unique_ptr<detail::interactor_impl> Interactor;
};
}

namespace f3d::detail
{
class scene_impl::internals
{
public:
    internals(options& options, window_impl& window);

    struct ProgressDataStruct
    {
        vtkTimerLog* timer;
        vtkProgressBarWidget* widget;
    };

    static void CreateProgressRepresentationAndCallback(
        ProgressDataStruct* data, vtkImporter* importer, interactor_impl* interactor);

    void Load(const std::vector<vtkSmartPointer<vtkImporter>>& importers);

    static void DisplayImporterDescription(log::VerboseLevel level, vtkImporter* importer);

    static void DisplayAllInfo(vtkImporter* importer, window_impl& window);

    const options& Options;
    window_impl& Window;
    interactor_impl* Interactor = nullptr;
    animationManager AnimationManager;

    vtkNew<vtkF3DMetaImporter> MetaImporter;
};
}

VtkItem::vtkUserData VtkItem::initializeVTK(vtkRenderWindow* renderWindow)
{    
    vtkNew<Data> vtk;

    _f3Engine = new f3d::engine(f3d::engine::createNone());
    _renderer = vtkSmartPointer<vtkRenderer>::New();

    vtkNew<vtkActor> actor;
    _renderer->AddActor(actor);
    _renderer->ResetCamera();
    _renderer->SetBackground(1,1,1);

    renderWindow->AddRenderer(_renderer);

    return vtk;
}

void VtkItem::openSource(QString fname)
{
    fileName = fname;

    dispatch_async(
    [this](vtkRenderWindow* renderWindow, vtkUserData userData)
    {
        _f3Engine->getScene().clear();
        _f3Engine->getScene().add(fileName.toStdString());

        auto actorCollection =_f3Engine->Internals->Scene->Internals->MetaImporter->GetImportedActors();
        vtkCollectionSimpleIterator ait;
        actorCollection->InitTraversal(ait);
        while (auto* actor = actorCollection->GetNextActor(ait))
            _renderer->AddActor(actor);

        _renderer->ResetCamera();
        _renderer->SetBackground(1,1,1);

        renderWindow->AddRenderer(_renderer);
    });
}
