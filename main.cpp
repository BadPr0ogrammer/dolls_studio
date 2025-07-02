#include <SkinnyShapeProvider.h>
#include <SkinnyShortcut.h>

#include <QskAspect.h>
#include <QskGraphicLabel.h>
#include <QskObjectCounter.h>
#include <QskShortcutMap.h>
#include <QskSubWindow.h>
#include <QskSubWindowArea.h>
#include <QskWindow.h>
#include <QskRgbValue.h>

#include <QDebug>
#include <QGuiApplication>
#include <QKeySequence>
#include <QApplication>

#include "vtkitem.h"
#include "mainview.h"

int main( int argc, char* argv[] )
{
    QQuickVTKItem::setGraphicsApi();
    f3d::engine::autoloadPlugins();

#ifdef ITEM_STATISTICS
    QskObjectCounter counter( true );
#endif
    Qsk::addGraphicProvider("shapes", new SkinnyShapeProvider());

#if defined(__linux__) || defined(_WIN32)
    QApplication app(argc, argv);
#else
    QGuiApplication app(argc, argv);
#endif

    DollsStudio::MainView mainView;
    QskWindow window;
    window.addItem(&mainView);

    window.resize(800, 600);
    window.show();

    return app.exec();
}
