#include "scene.h"
#include "window.h"

#include "engine.h"
#include "scene_impl.h"
#include "window_impl.h"
#include "camera_impl.h"

#include "animationManager.h"
#include "interactor_impl.h"
#include "log.h"
#include "options.h"
#include "factory.h"

#include "vtkF3DGenericImporter.h"
#include "vtkF3DMemoryMesh.h"
#include "vtkF3DMetaImporter.h"
#include "vtkF3DAssimpImporter.h"
#include "vtkF3DRenderer.h"

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


namespace f3d::detail
{
class window_impl::internals
{
public:
    explicit internals(const options& options);
    static context::fptr SymbolLoader(void* userptr, const char* name);
    static vtkSmartPointer<vtkRenderWindow> AutoBackendWindow();

    std::unique_ptr<camera_impl> Camera;
    vtkSmartPointer<vtkRenderWindow> RenWin;
    vtkNew<vtkF3DRenderer> Renderer;
    const options& Options;
    interactor_impl* Interactor = nullptr;
    fs::path CachePath;
    context::function GetProcAddress;
};
}


VtkItem::vtkUserData VtkItem::initializeVTK(vtkRenderWindow* renderWindow)
{    
    vtkNew<Data> vtk;

    f3d::context::function loadFunc = [&](const char* name) {
        QOpenGLContext *ctx = QOpenGLContext::currentContext();
        return ctx->getProcAddress(name);
    };
    vtk->m_f3Engine = new f3d::engine(f3d::engine::createExternal(loadFunc));
    vtk->m_renderer = vtk->m_f3Engine->Internals->Window->Internals->Renderer;

    vtkNew<vtkActor> actor;
    vtk->m_renderer->AddActor(actor);
    vtk->m_renderer->ResetCamera();
    vtk->m_renderer->SetBackground(1,1,1);

    renderWindow->AddRenderer(vtk->m_renderer);

    return vtk;
}

void VtkItem::openSource(QString fname)
{
    m_fileName = fname;

    dispatch_async([this](vtkRenderWindow* renderWindow, vtkUserData userData)
    {            
        Data* vtk = (Data*)userData.GetPointer();
        vtk->m_f3Engine->getScene().clear();
        vtk->m_f3Engine->getScene().add(m_fileName.toStdString());

        auto actorCollection = vtk->m_f3Engine->Internals->Scene->Internals->MetaImporter->GetImportedActors();
        vtkCollectionSimpleIterator ait;
        actorCollection->InitTraversal(ait);
        while (auto* actor = actorCollection->GetNextActor(ait))
            vtk->m_renderer->AddActor(actor);

        vtk->m_renderer->ResetCamera();
        vtk->m_renderer->SetBackground(1,1,1);

        renderWindow->AddRenderer(vtk->m_renderer);
    });
}
