#include "manager.h"
#include "settings.h"
#include "vtkitem.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
}

Settings *Manager::applicationSettings() const
{
    return m_settings;
}

void Manager::setApplicationSettings(Settings *settings)
{
    if (settings == m_settings)
        return;

    m_settings = settings;
    emit applicationSettingsChanged();
}

bool Manager::isReady() const
{
    return m_ready;
}

void Manager::setReady(bool ready)
{
    if (ready == m_ready)
        return;
    m_ready = ready;
    emit readyChanged();
}

// Provides a temporary project for client code to use
// while it tries to create/load a new project, so that if
// Project::createNew()/load() fails, the current project
// is not affected.
void Manager::openSource(const QUrl &url)
{
    m_projectCreationFailed = true;
    setReady(false);

    if (m_vtk->openSource(url)) {
        m_projectCreationFailed = false;
        setReady(true);
        emit projectChanged();
    }
}

void Manager::onCreationFailed(const QString &errorMessage)
{
    qDebug() << "Creation of the project failed;" << errorMessage;

    m_projectCreationFailed = true;

    // In case this was a recent file that we were loading, remove it from our list.
    // The function only checks that the file exists (not that e.g. its contents couldn't be loaded),
    // but it will remove any other invalid files at the same time. It's good enough.
    m_settings->removeInvalidRecentFiles();

    emit creationFailed(errorMessage);
}

void Manager::projectUrlChanged()
{
    /*
    if (mProject->hasLoaded() && !mProject->url().isEmpty()) {

    qCDebug(lcProjectManager) << "adding" << mProject->url().toString() << "to recent files list";
        mSettings->addRecentFile(mProject->url().toString());
    }
    */
}

void Manager::playFlag()
{
    m_vtk->m_play = true;
}
