#include <QQuickVTKItem.h>

#include <SkinnyShortcut.h>
#include <SkinnyNamespace.h>
#include <SkinnyShapeProvider.h>

#include <QskWindow.h>
#include <QskDialog.h>
#include <QskFocusIndicator.h>

#include "mainview.h"
#include "factory.h"

#include <QApplication>

int main( int argc, char* argv[] )
{
    QQuickVTKItem::setGraphicsApi();

    Qsk::addGraphicProvider("shapes", new SkinnyShapeProvider());
    
    f3d::factory::instance()->autoload();

    QGuiApplication app(argc, argv);

    auto mainView = new DS::MainView();
    QskWindow window;
    window.setTitle("Dolls Studio");
    window.addItem(mainView);
    window.addItem(new QskFocusIndicator());

    window.resize(800, 600);
    window.show();

    return app.exec();
}

