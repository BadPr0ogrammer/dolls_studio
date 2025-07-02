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
    struct Data : vtkObject
    {
        f3d::engine* m_f3Engine = nullptr;
        vtkSmartPointer<vtkRenderer> m_renderer;

        static Data* New();
        vtkTypeMacro(Data, vtkObject);
    };
    QString m_fileName;

    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;
    void openSource(QString fname);
};

}

#endif // VTKITEM_H
