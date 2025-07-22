#include <QDebug>
#include <QGuiApplication>
#include <QApplication>

#include "mainview.h"
#include "engine.h"

int main( int argc, char* argv[] )
{
    QQuickVTKItem::setGraphicsApi();

#if defined(__linux__) || defined(_WIN32)
    QApplication app(argc, argv);
#else
    QGuiApplication app(argc, argv);
#endif

}
