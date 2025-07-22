#ifndef VTKITEM_H
#define VTKITEM_H

#include <QString>
#include <QQuickVTKItem.h>

#include <vtkNew.h>
#include <vtkObject.h>
#include <vtkObjectFactory.h>

#include "engine.h"

namespace DS
{
class VtkItem : public QQuickVTKItem
{
    Q_OBJECT
public:    
    struct Data : vtkObject
    {
        static Data* New();
        vtkTypeMacro(Data, vtkObject);        
    };
    QString m_fname;
    f3d_engine m_engine;

    VtkItem();
    vtkUserData initializeVTK(vtkRenderWindow* renderWindow) override;

    void openSource(QString fname);
    void startAnim();
};

}

#endif // VTKITEM_H
