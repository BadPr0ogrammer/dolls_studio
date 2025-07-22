#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <QUrl>
#include <QtQmlIntegration/qqmlintegration.h>

#include <memory>

#include "vtkitem.h"

class ApplicationSettings;

class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ApplicationSettings *settings READ settings WRITE setSettings NOTIFY settingsChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
    Q_PROPERTY(QUrl dirUrl READ dirUrl NOTIFY urlChanged)
    Q_PROPERTY(QString displayUrl READ displayUrl NOTIFY urlChanged)

    QML_ELEMENT
    QML_UNCREATABLE("")
    Q_MOC_INCLUDE("applicationsettings.h")

public:
    Project();

    bool hasLoaded() const;

    QUrl url() const;
    void setUrl(const QUrl &url);
    QString displayUrl() const;
    QUrl dirUrl() const;
    QString fileBaseName() const;

    ApplicationSettings *settings() const;
    void setSettings(ApplicationSettings *settings);

    void error(const QString &message);
signals:
    void projectLoaded();
    void projectClosed();
    void loadedChanged();

    void urlChanged();
    void settingsChanged();

    void errorOccurred(const QString &errorMessage);
public slots:
    void close();
    void play();
public:
    ApplicationSettings *m_settings = nullptr;
    QUrl m_url;

    VtkItem* m_vtk = nullptr;
};

#endif // PROJECT_H
