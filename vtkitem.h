#ifndef VTKITEM_H
#define VTKITEM_H

#include <QQuickVTKItem.h>

#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkObject.h>
#include <vtkBoxWidget.h>
#include <vtkCommand.h>
#include <vtkRenderWindow.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkObjectFactory.h>
#include <vtkCallbackCommand.h>

#include <QString>

#include <engine.h>

namespace DollsStudio
{
class VtkItem : public QQuickVTKItem
{
    Q_OBJECT
public:
    f3d::engine* _f3Engine = nullptr;
    vtkSmartPointer<vtkRenderer> _renderer;

    struct Data : vtkObject
    {
        static Data* New();
        vtkTypeMacro(Data, vtkObject);
    };

    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;
    void openSource(QString fname);
private:
    QString fileName;
};

}

#endif // VTKITEM_H
