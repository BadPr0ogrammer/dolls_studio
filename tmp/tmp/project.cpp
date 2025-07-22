#include "project.h"

#include <QCoreApplication>
#include <QMetaEnum>
#include <QDir>

#include "applicationsettings.h"
#include "vtkitem.h"

Project::Project()
{
}

bool Project::hasLoaded() const
{
    return m_url.isValid();
}

QUrl Project::url() const
{
    return m_url;
}

void Project::setUrl(const QUrl &url)
{
    if (url == m_url)
        return;

    const bool wasLoaded = hasLoaded();

    m_url = url;

    if (objectName().isEmpty())
       setObjectName(m_url.toString());

    if (wasLoaded != hasLoaded()) {
        emit loadedChanged();
    }

    emit urlChanged();
}

QString Project::displayUrl() const
{
    return m_url.toDisplayString(QUrl::PreferLocalFile);
}

QUrl Project::dirUrl() const
{
    QDir dir(m_url.toLocalFile());
    if (!dir.cdUp())
        return QUrl();

    return QUrl::fromLocalFile(dir.path());
}

QString Project::fileBaseName() const
{
    return QFileInfo(m_url.toLocalFile()).baseName();
}

bool Project::load(const QUrl &url)
{
    bool ret = false;
    //close();

    if (!fname.isEmpty()) {
        ret = m_vtk->openSource(fname);
        if (!ret)
            qDebug() << "Vtk openSource error!";
    }
    else
        qDebug() << "File name is empty!";
    return ret;
}

void Project::play()
{
    m_vtk->m_play = true;
}

void Project::close()
{
    if (!hasLoaded())
        return;

    setUrl(QUrl());
}

void Project::error(const QString &message)
{
    qDebug() << "Emitting errorOccurred with message" << message;
    emit errorOccurred(message);
}

ApplicationSettings *Project::settings() const
{
    return m_settings;
}

void Project::setSettings(ApplicationSettings *settings)
{
    if (settings == m_settings)
        return;

    m_settings = settings;
    emit settingsChanged();
}

