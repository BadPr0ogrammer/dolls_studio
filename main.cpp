/******************************************************************************
 * QSkinny - Copyright (C) The authors
 *           SPDX-License-Identifier: BSD-3-Clause
 *****************************************************************************/

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

    QGuiApplication app(argc, argv);

    MainView mainView;
    QskWindow window;
    window.addItem(&mainView);

    window.resize(800, 600);
    window.show();

    return app.exec();
}
