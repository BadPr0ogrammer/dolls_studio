#include "app.h"

#include <memory>

#include <QQmlContext>
#include <QQuickWindow>
#include <QQuickItem>
#include <QDebug>

#include "settings.h"
#include "manager.h"
#include "vtkitem.h"

App::App(int &argc, char **argv)
{
    m_application = std::make_unique<QGuiApplication>(argc, argv);
    m_qmlEng = std::make_unique<QQmlApplicationEngine>();
    m_settings = std::make_unique<Settings>();
    m_manager = std::make_unique<Manager>();

    registerQmlTypes();

 #if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
    QQmlFileSelector fileSelector(mEngine.data());
    fileSelector.setExtraSelectors(QStringList() << QLatin1String("nativemenubar"));
#endif
    m_qmlEng->rootContext()->setContextProperty("settings", m_settings.get());
    m_qmlEng->setInitialProperties({
        { "projectManager", QVariant::fromValue(m_manager.get()) },
    });
    m_qmlEng->load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (m_qmlEng->rootObjects().isEmpty()) {
        qDebug() << "... failed to load main.qml";
        exit(-1);
    }
    else {
        QObject *root = m_qmlEng->rootObjects().at(0);
        VtkItem* vtk = nullptr;
        if (root)
            vtk = reinterpret_cast<VtkItem*>(root->findChild<QObject*>("vtkItem"));
        if (vtk)
            m_manager->m_vtk = vtk;
        else {
            qDebug() << "... failed to get vtkItem";
            exit(-1);
        }
    }
}

App::~App()
{
    // Context properties should outlive QML.
    // Usually this wouldn't be a problem with a traditional main(),
    // but since we're trying to encapsulate as much as possible into App
    // to be able to reuse it in tests, we run into the problem where
    // the project manager (a context property) is destroyed before the engine.
    // Give the engine a little helping hand and ensure that it's
    // destroyed before the project manager, otherwise we get binding errors.
    m_qmlEng.reset();
}

void App::registerQmlTypes()
{
    qRegisterMetaType<Settings*>();

    qmlRegisterType<Manager>("Dolls.studio", 1, 0, "Manager");
    qmlRegisterType<VtkItem>("Dolls.studio", 1, 0, "VtkItem");

    // For some reason, only when debugging, I get
    // QMetaProperty::read: Unable to handle unregistered datatype 'QUndoStack*' for property 'Project_QML_108::undoStack'
    // if I don't do this.
}
