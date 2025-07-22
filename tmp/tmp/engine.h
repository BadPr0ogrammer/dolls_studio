#ifndef F3D_ENGINE_H
#define F3D_ENGINE_H

#include <QString>

#include <functional>

#include <vtkNew.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProgressBarWidget.h>
#include <vtkTimerLog.h>
#include <vtkCallbackCommand.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyle.h>

#include <QVTKInteractor.h>


#include "timercallback.h"

class VtkItem;

class f3d_engine
{
public:

    //vtkNew<TimerCallback> m_timerCallback;
};

#endif // F3D_ENGINE_H
