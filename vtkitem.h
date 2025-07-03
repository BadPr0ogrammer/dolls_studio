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
#include <vtkObjectFactory.h>
#include <vtkCallbackCommand.h>

#include <QString>

#include "engine.h"

namespace DollsStudio
{
class VtkItem : public QQuickVTKItem
{
    Q_OBJECT
public:
    struct Data : vtkObject
    {
        //std::unique_ptr<f3d::engine> m_engine;
         //vtkSmartPointer<vtkF3DRenderer> m_renderer;
        std::unique_ptr<f3d_engine> m_engine;

        static Data* New();
        vtkTypeMacro(Data, vtkObject);
    };
    QString m_fname;

    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;

    void openSource(QString fname);
    void startAnim();
};

}

#endif // VTKITEM_H
